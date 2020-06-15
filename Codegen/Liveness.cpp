#include "Liveness.h"

Liveness::Liveness(std::shared_ptr<RVProgram> _prog) : prog(_prog) {}

void Liveness::runForFunction(std::shared_ptr<RVFunction> func) {
    visit.clear();
    BUse.clear();
    BDef.clear();
    for (auto blk : func->blocks)
        runForBlock(blk);
    runForLive(func->outBlock);
}


void Liveness::runForBlock(std::shared_ptr<RVBlock> blk) {
    for (auto inst : blk->insts) {
        std::set<int> Iuse;
        for (auto x : Iuse) {
            BUse[blk].insert(x);
        }
        std::set<int> Idef;
        for (auto x : Idef) {
            BDef[blk].insert(x);
        }
    }
    blk->liveIn.clear();
    blk->liveOut.clear();
}

void Liveness::runForLive(std::shared_ptr<RVBlock> blk) {
    if (visit.count(blk))
        return;
    visit.insert(blk);
    std::set<int> liveOut;
    for (auto succ : blk->succ)
        for (auto x : succ->liveIn)
            liveOut.insert(x);
    std::set<int> liveIn = liveOut;
    for (auto x : BDef[blk])
        liveIn.erase(x);
    for (auto x : BUse[blk])
        liveIn.insert(x);
    for (auto x : liveOut)
        blk->liveOut.insert(x);
    for (auto x : blk->liveIn)
        liveIn.erase(x);
    if (!liveIn.empty()) {
        for (auto x : liveIn)
            blk->liveIn.insert(x);
        for (auto x : blk->pre)
            visit.erase(x);
    }
    for (auto x : blk->pre)
        runForLive(x);
}
