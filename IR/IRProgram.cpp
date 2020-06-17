#include "IRProgram.h"

void IRProgram::outputIR(std::ostream &ofs) {
    for (auto obj : object) {
        ofs << "%" << obj->name << " [";
        bool first = true;
        for (auto member : obj->member) {
            if (!first)
                ofs << ", ";
            ofs << member.to_string();
            first = false;
        }
        ofs << "]" << std::endl;
    }
    for (auto operand : globalVar) {
        ofs << operand.to_string() << " " << operand.get_id() << std::endl;
    }
    for (int i = 0; i < constString.size(); ++i) {
        ofs << "str." << i << " = \"" << constString[i] << "\"" << std::endl;
    }
    for (auto function : func) {
        if (function->isBuiltin)
            continue;
        ofs << "def @" << function->name << "(";
        bool first = true;
        for (auto para : function->paras) {
            if (!first)
                ofs << ", ";
            ofs << para.to_string() << " " << para.get_id();
            first = false;
        }
        ofs << ") {" << std::endl;
        for (auto blk : function->blocks)
            outputBlock(blk, ofs);
        ofs << "}" << std::endl;
    }
}

std::shared_ptr<IRFunction> IRProgram::getFunc(std::string name) {
    return func[ref_func[name]];
}

bool IRProgram::hasFunc(std::string name) {
    return ref_func.count(name);
}

std::shared_ptr<IRClass> IRProgram::getClass(std::string name) {
    return object[ref_class[name]];
}

void IRProgram::outputBlock(std::shared_ptr<IRBlock> blk, std::ostream &ofs) {
    ofs << "LAB " << blk->label << ":" << std::endl;
    for (auto inst : blk->insts) {
        ofs << "\t" << inst->to_string() << ";" << std::endl;
    }
}

bool IRProgram::hasVar(int x) {
    return ref_var.count(x);
}

IROperand IRProgram::getVar(int x) {
    return ref_var[x];
}

void IRProgram::getAllBlocks() {
    for (auto function : func) {
        if (function->isBuiltin)
            continue;
        function->vis.clear();
        function->getAllBlocks(function->inBlock);
    }
}

void IRProgram::optimize() {
    for (auto f : func) {
        for (auto blk : f->blocks) {
            for (auto it = blk->insts.begin(); it != blk->insts.end();it++) {
                std::map<IROperand, IROperand> mmm;
                if (std::dynamic_pointer_cast<IRStore>(*it)) {
                    auto inst = std::dynamic_pointer_cast<IRStore>(*it);
                    mmm[inst->addr] = mmm[inst->value];
                }
                if (std::dynamic_pointer_cast<IRLoad>(*it)) {
                    auto inst = std::dynamic_pointer_cast<IRLoad>(*it);
                    if (mmm.count(inst->addr)) {
                        *it = std::make_shared<IRMove>(inst->dst, mmm[inst->addr]);
                    }
                }
            }
        }
    }
}

void IRProgram::constantPropagation() {
    for (auto f : func) {
        std::map<IROperand, IROperand> map;
        size_t tmpsize = -1;
        while (map.size() != tmpsize) {
            tmpsize = map.size();
            for (auto blk : f->blocks) {
                for (auto it = blk->insts.begin(); it != blk->insts.end(); ) {
                    if (std::dynamic_pointer_cast<IRBinary>(*it)) {
                        auto inst = std::dynamic_pointer_cast<IRBinary>(*it);
                        if (map.count(inst->src1))
                            inst->src1 = map[inst->src1];
                        if (map.count(inst->src2))
                            inst->src2 = map[inst->src2];
                        IROperand imm;
                        if (inst->dst.size() == 4)
                            imm = IROperandImm32(newLabel());
                        else
                            imm = IROperandImm8(newLabel());
                        if (inst->src1.is_imm() && inst->src2.is_imm()) {
                            switch (inst->op) {
                                case IRBinary::And : imm.id = inst->src1.id & inst->src2.id; break;
                                case IRBinary::Or : imm.id = inst->src1.id | inst->src2.id; break;
                                case IRBinary::Xor : imm.id = inst->src1.id ^ inst->src2.id; break;
                                case IRBinary::Eq : imm.id = inst->src1.id == inst->src2.id; break;
                                case IRBinary::Ne : imm.id = inst->src1.id != inst->src2.id; break;
                                case IRBinary::Slt : imm.id = inst->src1.id < inst->src2.id; break;
                                case IRBinary::Sle : imm.id = inst->src1.id <= inst->src2.id; break;
                                case IRBinary::Sgt : imm.id = inst->src1.id > inst->src2.id; break;
                                case IRBinary::Sge : imm.id = inst->src1.id >= inst->src2.id; break;
                                case IRBinary::Shl : imm.id = inst->src1.id << inst->src2.id; break;
                                case IRBinary::Ashr : imm.id = inst->src1.id >> inst->src2.id; break;
                                case IRBinary::Add : imm.id = inst->src1.id + inst->src2.id; break;
                                case IRBinary::Sub : imm.id = inst->src1.id - inst->src2.id; break;
                                case IRBinary::Mul : imm.id = inst->src1.id * inst->src2.id; break;
                                case IRBinary::Sdiv : imm.id = inst->src1.id / inst->src2.id; break;
                                case IRBinary::Srem : imm.id = inst->src1.id % inst->src2.id; break;
                            }
                            map[inst->dst] = imm;
                            it = blk->insts.erase(it);
                        }
                        else if (inst->src1.is_imm()) {
                            if (inst->op == IRBinary::Mul && inst->src1.id == 0) {
                                map[inst->dst] = IROperandImm32(0);
                                it = blk->insts.erase(it);
                            }
                            else if(inst->op == IRBinary::And && inst->src1.id == 0) {
                                map[inst->dst] = IROperandImm8(0);
                                it = blk->insts.erase(it);
                            }
                            else
                                it++;
                        }
                        else if (inst->src2.is_imm()) {
                            if (inst->op == IRBinary::Mul && inst->src2.id == 0) {
                                map[inst->dst] = IROperandImm32(0);
                                it = blk->insts.erase(it);
                            }
                            else if(inst->op == IRBinary::And && inst->src2.id == 0) {
                                map[inst->dst] = IROperandImm8(0);
                                it = blk->insts.erase(it);
                            }
                            else
                                it++;
                        }
                        else if (inst->src1 == inst->src2) {
                            if (inst->op == IRBinary::Eq || inst->op == IRBinary::Sle || inst->op == IRBinary::Sge) {
                                map[inst->dst] = IROperandImm8(1);
                                it = blk->insts.erase(it);
                            }
                            else if (inst->op == IRBinary::Xor) {
                                if (inst->dst.size() == 4)
                                    map[inst->dst] = IROperandImm32(0);
                                else
                                    map[inst->dst] = IROperandImm8(0);
                                it = blk->insts.erase(it);
                            }
                            else if (inst->op == IRBinary::Sub) {
                                map[inst->dst] = IROperandImm32(0);
                                it = blk->insts.erase(it);
                            }
                            else if (inst->op == IRBinary::Sdiv) {
                                map[inst->dst] = IROperandImm32(1);
                                it = blk->insts.erase(it);
                            }
                            else
                                it++;
                        }
                        else {
                            it++;
                        }
                    }
                    else if (std::dynamic_pointer_cast<IRMove>(*it)) {
                        auto inst = std::dynamic_pointer_cast<IRMove>(*it);
                        if (map.count(inst->src)) {
                            map[inst->dst] = map[inst->src];
                            it = blk->insts.erase(it);
                        }
                        else
                            it++;
                    }
                    else if (std::dynamic_pointer_cast<IRMalloc>(*it)) {
                        auto inst = std::dynamic_pointer_cast<IRMalloc>(*it);
                        if (map.count(inst->size))
                            inst->size = map[inst->size];
                        it++;
                    }
                    else if (std::dynamic_pointer_cast<IRBr>(*it)) {
                        auto inst = std::dynamic_pointer_cast<IRBr>(*it);
                        if (map.count(inst->cond)) {
                            if (!(map[inst->cond].id))
                                *it = std::make_shared<IRJump>(inst->thenBlock);
                            else
                                *it = std::make_shared<IRJump>(inst->elseBlock);
                        }
                        it++;
                    }
                    else if (std::dynamic_pointer_cast<IRCall>(*it)) {
                        auto inst = std::dynamic_pointer_cast<IRCall>(*it);
                        for (auto &para : inst->paras)
                            if (map.count(para))
                                para = map[para];
                        it++;
                    }
                    else if (std::dynamic_pointer_cast<IRLoad>(*it)) {
                        auto inst = std::dynamic_pointer_cast<IRLoad>(*it);
                        if (map.count(inst->addr))
                            inst->addr = map[inst->addr];
                        it++;
                    }
                    else if (std::dynamic_pointer_cast<IRStore>(*it)) {
                        auto inst = std::dynamic_pointer_cast<IRStore>(*it);
                        if (map.count(inst->addr))
                            inst->addr = map[inst->addr];
                        if (map.count(inst->value))
                            inst->value = map[inst->value];
                        it++;
                    }
                    else if (std::dynamic_pointer_cast<IRReturn>(*it)) {
                        auto inst = std::dynamic_pointer_cast<IRReturn>(*it);
                        if (map.count(inst->value))
                            inst->value = map[inst->value];
                        it++;
                    }
                    else if (std::dynamic_pointer_cast<IRPhi>(*it)) {
                        auto inst = std::dynamic_pointer_cast<IRPhi>(*it);
                        for (auto &v : inst->values)
                            if (map.count(v))
                                v = map[v];
                        it++;
                    }
                    else {
                        it++;
                    }
                }
            }
        }
    }
}

void IRProgram::jumpErase() {
    for (auto f : func) {
        for (auto blk : f->blocks) {
            jumpEraseforBlock(blk);
        }
        f->blocks.clear();
    }
    getAllBlocks();
}

void IRProgram::jumpEraseforBlock(std::shared_ptr<IRBlock> blk) {
    if (blk->pre.size() == 1) {
        if (blk->pre[0]->next.size() == 1)
            jumpEraseforBlock(blk->pre[0]);
    }
    auto cur = blk->pre[0];
    cur->insts.pop_back();
    for (auto it = cur->insts.rbegin(); it != cur->insts.rend(); it++)
        blk->insts.push_front(*it);
    for (auto ppre : cur->pre) {
        if (std::dynamic_pointer_cast<IRJump>(ppre->insts.back())) {
            auto inst = std::dynamic_pointer_cast<IRJump>(ppre->insts.back());
            if (inst->block == cur)
                inst->block = blk;
        }
        else if (std::dynamic_pointer_cast<IRBr>(ppre->insts.back())) {
            auto inst = std::dynamic_pointer_cast<IRBr>(ppre->insts.back());
            if (inst->thenBlock == cur)
                inst->thenBlock = blk;
            if (inst->elseBlock == cur)
                inst->elseBlock = blk;
        }
        //TODO: change func->inBlock but I have no time
    }
}
