#include "RegAllocation.h"

void RegAllocation::run() {
    for (auto func : prog->functions) {
        _func = func;
        stackOffset = 0;
        nodeColor.clear();
        alias.clear();
        nodeStackOffset.clear();
        runForFunction();
        stackOffset += func->paramInStackOffset;
        stackOffset = (stackOffset + 15) / 16 * 16;
        for (auto blk : func->blocks) {
            for (auto _inst : blk->insts) {
                if (std::dynamic_pointer_cast<RVLd>(_inst)) {
                    auto inst = std::dynamic_pointer_cast<RVLd>(_inst);
                    if (inst->offset.is_stack)
                        inst->offset.id += (inst->offset.is_neg ? -1 : 1) * stackOffset;
                }
                else if (std::dynamic_pointer_cast<RVSt>(_inst)) {
                    auto inst = std::dynamic_pointer_cast<RVSt>(_inst);
                    if (inst->offset.is_stack)
                        inst->offset.id += (inst->offset.is_neg ? -1 : 1) * stackOffset;
                }
                else if (std::dynamic_pointer_cast<RVItype>(_inst)) {
                    auto inst = std::dynamic_pointer_cast<RVItype>(_inst);
                    if (inst->imm.is_stack)
                        inst->imm.id += (inst->imm.is_neg ? -1 : 1) * stackOffset;
                }
            }
        }
        for (auto pp : nodeColor)
            for (auto blk : func->blocks) {
                for (auto inst : blk->insts) {
                    if (inst->getDef().count(pp.first) || inst->getUse().count(pp.first))
                        inst->replaceColor(pp.first, pp.second);
                }
            }
    }
}

RegAllocation::RegAllocation(std::shared_ptr<RVProgram> _prog) : prog(_prog) {
    K = 28;
    for (auto x : allocatableReg) {
        preColored.insert(-x);
    }
    LivenessAnalyser = std::make_shared<Liveness>(_prog);
}

void RegAllocation::runForFunction() {
    init();
    LivenessAnalyser->runForFunction(_func);
    build();
    makeWorkList();
//    for (auto x : spillWorkList)
//        printf("%d ", x);
//    puts("");
    do {
        if (!simplifyWorkList.empty())
            simplify();
        else if (!workListMoves.empty())
            coalesce();
        else if (!freezeWorkList.empty())
            freeze();
        else if (!spillWorkList.empty())
            selectSpill();
    } while(!(simplifyWorkList.empty() && workListMoves.empty() && freezeWorkList.empty() && spillWorkList.empty()));
//    for (auto x : coalescedNodes)
//        printf("%d ", x);
//    puts("");
    assignColors();
    if (!spilledNodes.empty()) {
        rewriteProgram();
//        prog->outputIR(std::cout);
        runForFunction();
    }
}

void RegAllocation::build() {
    for (auto blk : _func->blocks) {
        std::set<int> live = blk->liveOut;
        for (auto it = blk->insts.rbegin(); it != blk->insts.rend(); it++) {
            if (std::dynamic_pointer_cast<RVMv>(*it)) {
                auto inst = std::dynamic_pointer_cast<RVMv>(*it);
                std::set<int> tmp = inst->getUse();
                for (auto x : tmp)
                    live.erase(x);
                for (auto x : inst->getDef())
                    tmp.insert(x);
                for (auto x : tmp)
                    moveList[x].insert(inst);
                workListMoves.insert(inst);
            }
            std::set<int> tmp = (*it)->getDef();
            live.insert(0);
            for (auto x : tmp)
                live.insert(x);
            for (auto x : tmp)
                for (auto y : live) {
                    addEdge(x, y);
                }
            for (auto x : tmp)
                live.erase(x);
            tmp = (*it)->getUse();
            for (auto x : tmp)
                live.insert(x);
        }
    }
}

void RegAllocation::addEdge(int u, int v) {
    if (u == 1 && v == 1)
        int ha = 3;
    if (u != v && !adjSet.count(Edge(u, v))) {
        adjSet.insert(Edge(u, v));
        adjSet.insert(Edge(v, u));
        if (!preColored.count(u)) {
            adjList[u].insert(v);
            degree[u] += 1;
        }
        if (!preColored.count(v)) {
            adjList[v].insert(u);
            degree[v] += 1;
        }
    }
}

void RegAllocation::init() {
    initial.clear();
    for (auto blk : _func->blocks) {
        for (auto inst : blk->insts) {
            std::set<int> tmp = inst->getDef();
            for (auto x : tmp)
                if (x > 0)
                    initial.insert(x);
            tmp = inst->getUse();
            for (auto x : tmp)
                if (x > 0)
                    initial.insert(x);
        }
    }
    for (auto x : preColored)
        nodeColor[x] = -x;
    moveList.clear();
    simplifyWorkList.clear();
    freezeWorkList.clear();
    spillWorkList.clear();

    spilledNodes.clear();
    coalescedNodes.clear();
    coloredNodes.clear();
    selectStack.clear();

    coalescedMoves.clear();
    constrainedMoves.clear();
    frozenMoves.clear();
    activeMoves.clear();
    workListMoves.clear();

    adjList.clear();
    adjSet.clear();
    degree.clear();
}

void RegAllocation::makeWorkList() {
    for (auto x : initial) {
        if (degree[x] >= K)
            spillWorkList.insert(x);
        else if (moveRelated(x))
            freezeWorkList.insert(x);
        else
            simplifyWorkList.insert(x);
    }
}

bool RegAllocation::moveRelated(int x) {
    return !nodeMoves(x).empty();
}

std::set<std::shared_ptr<RVMv>> RegAllocation::nodeMoves(int x) {
    std::set<std::shared_ptr<RVMv>> ret;
    for (auto mv : moveList[x])
        if (activeMoves.count(mv) || workListMoves.count(mv))
            ret.insert(mv);
    return ret;
}

void RegAllocation::simplify() {
    int x = *simplifyWorkList.begin();
    simplifyWorkList.erase(simplifyWorkList.begin());
    selectStack.push_back(x);
    for (auto y : adjacent(x)) {
        decrementDegree(y);
    }
}

std::set<int> RegAllocation::adjacent(int x) {
    std::set<int> ret;
    for (auto y : adjList[x])
        if (!coalescedNodes.count(y))
            ret.insert(y);
    for (auto y : selectStack)
        ret.erase(y);
    return ret;
}

void RegAllocation::decrementDegree(int x) {
    int d = degree[x];
    degree[x] = d - 1;
    if (d == K) {
        std::set<int> tmp = adjacent(x);
        tmp.insert(x);
        enableMoves(tmp);
        spillWorkList.erase(x);
        if (moveRelated(x))
            freezeWorkList.insert(x);
        else
            simplifyWorkList.insert(x);
    }
}

void RegAllocation::enableMoves(std::set<int> nodes) {
    for (auto x : nodes) {
        for (auto y : nodeMoves(x)) {
            activeMoves.erase(y);
            workListMoves.insert(y);
        }
    }
}

void RegAllocation::coalesce() {
    std::shared_ptr<RVMv> move = *workListMoves.begin();
    int x = getAlias(move->rd.is_special ? -move->rd.id : move->rd.id);
    int y = getAlias(move->rs.is_special ? -move->rs.id : move->rs.id);
    int u, v;
    if (preColored.count(y)) {
        u = y, v = x;
    }
    else {
        u = x, v = y;
    }
    workListMoves.erase(workListMoves.begin());
    if (u == v) {
        coalescedMoves.insert(move);
        addWorkList(u);
    }
    else if (preColored.count(v) || adjSet.count(Edge(u, v))) {
        constrainedMoves.insert(move);
        addWorkList(u);
        addWorkList(v);
    }
    else if ((preColored.count(u) && forAllOK(u, v)) || (!preColored.count(u) && conservative(adjacent(u, v)))) {
        coalescedMoves.insert(move);
        combine(u, v);
        addWorkList(u);
    }
    else {
        activeMoves.insert(move);
    }
}

int RegAllocation::getAlias(int x) {
    if (coalescedNodes.count(x)) {
        alias[x] = getAlias(alias[x]);
        return alias[x];
    }
    return x;
}

void RegAllocation::addWorkList(int x) {
    if (!preColored.count(x) && !moveRelated(x) && degree[x] < K) {
        freezeWorkList.erase(x);
        simplifyWorkList.insert(x);
    }
}

bool RegAllocation::OK(int t, int r) {
    return degree[t] < K || preColored.count(t) || adjSet.count(Edge(t, r));
}

bool RegAllocation::forAllOK(int u, int v) {
    for (auto w : adjacent(v))
        if (!OK(w, u))
            return false;
    return true;
}

void RegAllocation::combine(int u, int v) {
    if (freezeWorkList.count(v))
        freezeWorkList.erase(v);
    else
        spillWorkList.erase(v);
    coalescedNodes.insert(v);
    alias[v] = u;
    for (auto move : moveList[v])
        moveList[u].insert(move);
    enableMoves({v});
    for (auto t : adjacent(v)) {
        addEdge(t, u);
        decrementDegree(t);
    }
    if (degree[u] >= K && freezeWorkList.count(u)) {
        freezeWorkList.erase(u);
        spillWorkList.insert(u);
    }
}

std::set<int> RegAllocation::adjacent(int x, int y) {
    std::set<int> ret = adjacent(x), tmp = adjacent(y);
    for (auto t : tmp)
        ret.insert(t);
    return ret;
}

bool RegAllocation::conservative(std::set<int> nodes) {
    int cnt = 0;
    for (auto x : nodes)
        if (degree[x] >= K)
            ++cnt;
    return cnt < K;
}

void RegAllocation::freeze() {
    int x = *freezeWorkList.begin();
    freezeWorkList.erase(x);
    simplifyWorkList.insert(x);
    freezeMoves(x);
}

void RegAllocation::freezeMoves(int u) {
    for (auto move : nodeMoves(u)) {
        int x = move->rd.is_special ? -move->rd.id : move->rd.id;
        int y = move->rs.is_special ? -move->rs.id : move->rs.id;
        int v;
        if (getAlias(u) == getAlias(y)) {
            v = getAlias(x);
        }
        else {
            v = getAlias(y);
        }
        activeMoves.erase(move);
        frozenMoves.insert(move);
        if (degree[v] < K && nodeMoves(v).empty()) {
            freezeWorkList.erase(v);
            simplifyWorkList.insert(v);
        }
    }
}

void RegAllocation::selectSpill() {
    //TODO: Can be better
    int m = *spillWorkList.begin();
    spillWorkList.erase(spillWorkList.begin());
    simplifyWorkList.insert(m);
    freezeMoves(m);
}

void RegAllocation::assignColors() {
    while (!selectStack.empty()) {
        int n = selectStack.back();
        selectStack.pop_back();
        std::set<int> okColors;
        for (auto x : allocatableReg)
            okColors.insert(x);
        std::set<int> colored = coloredNodes;
        for (auto x : preColored)
            colored.insert(x);
        for (auto w : adjList[n]) {
            if (colored.count(getAlias(w))) {
                okColors.erase(nodeColor[getAlias(w)]);
            }
        }
        if (okColors.empty()) {
            spilledNodes.insert(n);
        }
        else {
            coloredNodes.insert(n);
            nodeColor[n] = *okColors.begin();
        }
    }
    for (auto n : coalescedNodes)
        nodeColor[n] = nodeColor[getAlias(n)];
}

void RegAllocation::rewriteProgram() {
    std::set<int> newTemps;
    //TODO: spilledCount
    for (auto x : spilledNodes) {
        nodeStackOffset[x] = -stackOffset - 4;
        stackOffset += 4;
    }
    for (auto blk : _func->blocks) {
        for (auto inst : blk->insts) {
            if (inst->getDef().size() == 1) {
                getAlias(*(inst->getDef().begin()));
            }
        }
    }
    for (auto blk : _func->blocks) {
        for (auto it = blk->insts.begin(); it != blk->insts.end(); ++it) {
            auto inst = *it;
            for (auto x : inst->getUse())
                if (spilledNodes.count(x)) {
                    RVReg tmp(_func->regcnt++);
                    blk->insts.insert(it, std::make_shared<RVLd>(tmp, RVReg_sp(), RVImm(nodeStackOffset[x], Rop::Imm, true,false), tmp.size));
                    inst->replaceUse(x, tmp.id);
                    newTemps.insert(tmp.id);
                }
            for (auto x : inst->getDef())
                if (spilledNodes.count(x)) {
                    RVReg tmp(_func->regcnt++);
                    blk->insts.insert(++it, std::make_shared<RVSt>(tmp, RVReg_sp(), RVImm(nodeStackOffset[x], Rop::Imm, true, false), tmp.size));
                    it--;
                    inst->replaceDef(x, tmp.id);
                    newTemps.insert(tmp.id);
                }
        }
    }
    for (auto x : newTemps)
        initial.insert(x);
    for (auto x : coloredNodes)
        initial.insert(x);
    for (auto x : coalescedNodes)
        initial.insert(x);
}

RegAllocation::Edge::Edge(int _x, int _y) : x(_x), y(_y) {}

bool RegAllocation::Edge::operator<(const RegAllocation::Edge &rhs) const {
    return x < rhs.x || (x == rhs.x && y < rhs.y);
}
