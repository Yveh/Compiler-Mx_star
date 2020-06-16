#include "SSAConstructor.h"

void SSAConstructor::run(std::shared_ptr<IRProgram> _prog) {
    prog = _prog;
    for (auto func : prog->func) {
        if (!func->isBuiltin)
            runForFunction(func);
    }
}

void SSAConstructor::runForFunction(std::shared_ptr<IRFunction> func) {
    std::set<IROperand> AllocaVars;
    std::map<std::shared_ptr<IRBlock>, std::map<IROperand, IROperand>> AllocaStores;
    std::map<std::shared_ptr<IRBlock>, std::set<std::shared_ptr<IRLoad>>> AllocaLoads;
    std::map<std::shared_ptr<IRBlock>, std::map<IROperand, std::shared_ptr<IRPhi>>> AllocaPhis;
    std::set<std::shared_ptr<IRBlock>> definitionBlocks;
    std::map<IROperand, IROperand> fa;
    for (auto block : func->blocks) {
        for (auto _inst : block->insts) {
            if (std::dynamic_pointer_cast<IRAlloca>(_inst)) {
                auto inst = std::dynamic_pointer_cast<IRAlloca>(_inst);
                AllocaVars.insert(inst->dst);
            }
        }
    }
//    for (auto var : AllocaVars) {
//        std::cerr << var.get_id() << std::endl;
//    }
    for (auto block : func->blocks) {
        std::vector<std::list<std::shared_ptr<IRInst>>::iterator> LazyDelete;
        for (auto it = block->insts.begin(); it != block->insts.end(); it++) {
            if (std::dynamic_pointer_cast<IRLoad>(*it)) {
                auto inst = std::dynamic_pointer_cast<IRLoad>(*it);
                if (inst->addr.is_reg() && AllocaVars.count(inst->addr)) {
                    if (AllocaStores[block].count(inst->addr)) {
                        fa[inst->dst] = AllocaStores[block][inst->addr];
                    }
                    else {
                        AllocaLoads[block].insert(inst);
                    }
                    LazyDelete.push_back(it);
                }
            }
            else if (std::dynamic_pointer_cast<IRStore>(*it)) {
                auto inst = std::dynamic_pointer_cast<IRStore>(*it);
                if (inst->addr.is_reg() && AllocaVars.count(inst->addr)) {
                    definitionBlocks.insert(block);
                    AllocaStores[block][inst->addr] = inst->value;
                    LazyDelete.push_back(it);
                }
            }
        }
        for (auto it : LazyDelete)
            block->insts.erase(it);
    }

    while (!definitionBlocks.empty()) {
        auto DBlocks = definitionBlocks;
        definitionBlocks.clear();
        for (auto blk : DBlocks) {
            for (auto domFrontier : blk->domFrontier) {
                for (auto st : AllocaStores[blk]) {
                    if (!AllocaPhis[domFrontier].count(st.first)) {
                        IROperand dst;
                        if (st.second.size() == 1)
                            dst = IROperandReg8(prog->newLabel());
                        else
                            dst = IROperandReg32(prog->newLabel());
                        auto phi = std::make_shared<IRPhi>(dst);
                        domFrontier->insts.push_front(phi);
                        if (!AllocaStores[domFrontier].count(st.first)) {
                            AllocaStores[domFrontier][st.first] = dst;
                            definitionBlocks.insert(domFrontier);
                        }
                        AllocaPhis[domFrontier][st.first] = phi;
                    }
                }
            }
        }
    }

    for (auto blk : func->blocks) {
        for (auto inst : AllocaPhis[blk]) {
            for (auto pre : blk->pre) {
                std::shared_ptr<IRBlock> tmp = pre;
                while (tmp != tmp->idom && !AllocaStores[tmp].count(inst.first)) {
                    tmp = tmp->idom;
                }
                if (AllocaStores[tmp].count(inst.first)) {
                    inst.second->blocks.push_back(pre);
                    inst.second->values.push_back(AllocaStores[tmp][inst.first]);
                }
                else {
                    inst.second->blocks.push_back(pre);
                    if (inst.first.size() == 1)
                        inst.second->values.push_back(IROperandImm8(0));
                    else
                        inst.second->values.push_back(IROperandImm32(0));
                }
            }
        }
        for (auto inst : AllocaLoads[blk]) {
            IROperand dst;
            if (AllocaPhis[blk].count(inst->addr)) {
                dst = AllocaPhis[blk][inst->addr]->dst;
            }
            else {
                std::shared_ptr<IRBlock> tmp = blk->idom;
                while (!AllocaStores[tmp].count(inst->addr)) {
                    tmp = tmp->idom;
                }
                dst = AllocaStores[tmp][inst->addr];
            }
            fa[inst->dst] = dst;
        }
    }
    for (auto blk : func->blocks) {
        std::vector<std::list<std::shared_ptr<IRInst>>::iterator> LazyDelete;
        for (auto it = blk->insts.begin(); it != blk->insts.end(); it++) {
            if (std::dynamic_pointer_cast<IRAlloca>(*it)) {
                LazyDelete.push_back(it);
            }
        }
        for (auto it : LazyDelete)
            blk->insts.erase(it);
    }
    for (auto pp : fa) {
        IROperand dst = getfa(fa, pp.first);
//        std::cerr << pp.first.get_id() << " " << dst.get_id() << std::endl;
        for (auto blk : func->blocks) {
            for (auto _inst : blk->insts) {
                if (std::dynamic_pointer_cast<IRMalloc>(_inst)) {
                    auto inst = std::dynamic_pointer_cast<IRMalloc>(_inst);
//                    if (inst->dst == pp.first)
//                        inst->dst = dst;
                    if (inst->size == pp.first)
                        inst->size = dst;
                }
                if (std::dynamic_pointer_cast<IRBinary>(_inst)) {
                    auto inst = std::dynamic_pointer_cast<IRBinary>(_inst);
//                    if (inst->dst == pp.first)
//                        inst->dst = dst;
                    if (inst->src1 == pp.first)
                        inst->src1 = dst;
                    if (inst->src2 == pp.first)
                        inst->src2 = dst;
                }
                else if (std::dynamic_pointer_cast<IRBr>(_inst)) {
                    auto inst = std::dynamic_pointer_cast<IRBr>(_inst);
                    if (inst->cond == pp.first)
                        inst->cond = dst;
                }
                else if (std::dynamic_pointer_cast<IRCall>(_inst)) {
                    auto inst = std::dynamic_pointer_cast<IRCall>(_inst);
//                    if (inst->dst == pp.first)
//                        inst->dst = dst;
                    for (auto &para : inst->paras) {
                        if (para == pp.first)
                            para = dst;
                    }
                }
                else if (std::dynamic_pointer_cast<IRLoad>(_inst)) {
                    auto inst = std::dynamic_pointer_cast<IRLoad>(_inst);
//                    if (inst->dst == pp.first)
//                        inst->dst = dst;
                    if (inst->addr == pp.first)
                        inst->addr = dst;
                }
                else if (std::dynamic_pointer_cast<IRStore>(_inst)) {
                    auto inst = std::dynamic_pointer_cast<IRStore>(_inst);
                    if (inst->value == pp.first)
                        inst->value = dst;
                    if (inst->addr == pp.first)
                        inst->addr = dst;
                }
                else if (std::dynamic_pointer_cast<IRReturn>(_inst)) {
                    auto inst = std::dynamic_pointer_cast<IRReturn>(_inst);
                    if (inst->value == pp.first)
                        inst->value = dst;
                }
                else if (std::dynamic_pointer_cast<IRPhi>(_inst)) {
                    auto inst = std::dynamic_pointer_cast<IRPhi>(_inst);
                    for (auto &value : inst->values) {
                        if (value == pp.first)
                            value = dst;
                    }
                }

            }
        }
    }
}

IROperand SSAConstructor::getfa(std::map<IROperand, IROperand> &map, IROperand key) {
    if (map.count(key)) {
        IROperand ret = map[key];
        map[key] = getfa(map, ret);;
        return map[key];
    }
    return key;
}
