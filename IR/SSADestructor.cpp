#include "SSADestructor.h"

void SSADestructor::run(std::shared_ptr<IRProgram> _prog) {
    prog = _prog;
    for (auto func : prog->func) {
        if (!func->isBuiltin)
            runForFunction(func);
    }
}

void SSADestructor::runForFunction(std::shared_ptr<IRFunction> func) {
    std::vector<std::shared_ptr<IRBlock>> edgeu, edgev;
    for (auto blku : func->blocks)
        if (blku->next.size() > 1) {
            for (auto blkv : blku->next)
                if (blkv->pre.size() > 1) {
                    edgeu.push_back(blku);
                    edgev.push_back(blkv);
                }
        }
    for (int idx = 0; idx < edgeu.size(); ++idx) {
        std::shared_ptr<IRBlock> trans = std::make_shared<IRBlock>(prog->newLabel());
        func->blocks.push_back(trans);
        auto blku = edgeu[idx], blkv = edgev[idx];

        for (auto _inst : blkv->insts) {
            if (std::dynamic_pointer_cast<IRPhi>(_inst)) {
                auto inst = std::dynamic_pointer_cast<IRPhi>(_inst);
                for (auto &it : inst->blocks) {
                    if (it == blku)
                        it = trans;
                }
            }
        }
        trans->insts.push_back(std::make_shared<IRJump>(blkv));
        trans->pre.push_back(blku);
        trans->next.push_back(blkv);

        for (auto &it : blkv->pre)
            if (it == blku) {
                it = trans;
            }

        if (std::dynamic_pointer_cast<IRJump>(blku->insts.back())) {
            auto inst = std::dynamic_pointer_cast<IRJump>(blku->insts.back());
            inst->block = trans;
        }
        else if (std::dynamic_pointer_cast<IRBr>(blku->insts.back())) {
            auto inst = std::dynamic_pointer_cast<IRBr>(blku->insts.back());
            if (inst->thenBlock == blkv)
                inst->thenBlock = trans;
            else
                inst->elseBlock = trans;
        }
        for (auto &it : blku->next)
            if (it == blkv)
                it = trans;
    }

    for (auto blk : func->blocks) {
        std::vector<std::list<std::shared_ptr<IRInst>>::iterator> LazyDelete;
        for (auto it = blk->insts.begin(); it != blk->insts.end(); ++it) {
            if (std::dynamic_pointer_cast<IRPhi>(*it)) {
                auto inst = std::dynamic_pointer_cast<IRPhi>(*it);
                for (int i = 0; i < inst->values.size(); ++i) {
                    inst->blocks[i]->insts.insert(--inst->blocks[i]->insts.end(), std::make_shared<IRMove>(inst->dst, inst->values[i]));
                }
                LazyDelete.push_back(it);
            }
        }
        for (auto it : LazyDelete)
            blk->insts.erase(it);
    }
}
