#include "InstSelector.h"

InstSelector::InstSelector(std::shared_ptr<IRProgram> _old, std::shared_ptr<RVProgram> _new) : IRprog(_old), RVprog(_new) {
    id_n = 1;
}

RVReg InstSelector::RegTrans(IROperand operand) {
    if (operand.type == IROperand::constID) {
        return RVSReg(operand.id, 4);
    }
    else if (operand.type == IROperand::Imm8) {
        if (operand.id) {
            RVReg reg(newLabel(), 1);
            _block->insts.push_back(std::make_shared<RVLi>(reg, RVImm(operand.id)));
            return reg;
        }
        else {
            return RVReg_zero();
        }
    }
    else if (operand.type == IROperand::Imm32) {
        if (operand.id) {
            RVReg reg(newLabel(), 4);
            _block->insts.push_back(std::make_shared<RVLi>(reg, RVImm(operand.id)));
            return reg;
        }
        else {
            return RVReg_zero();
        }
    }
    else if (RVprog->checkGlobal(operand.id)) {
        return RVprog->getGlobal(operand.id);
    }
    else if (RVprog->hasVar(operand.id)) {
        return RVprog->getVar(operand.id);
    }
    else {
        RVReg reg = RVReg(newLabel(), operand.size());
        RVprog->ref_reg[operand.id] = reg;
        return reg;
    }
}

int InstSelector::newLabel() {
    return id_n++;
}

void InstSelector::runForBlock(std::shared_ptr<IRBlock> blk) {
    _block = RVprog->ref_block[blk];
    for (auto _inst : blk->insts) {
        if (std::dynamic_pointer_cast<IRMalloc>(_inst)) {
            auto inst = std::dynamic_pointer_cast<IRMalloc>(_inst);
            _block->insts.push_back(std::make_shared<RVMv>(RVReg_a(0), RegTrans(inst->size)));
            _block->insts.push_back(std::make_shared<RVCall>(RVprog->builtin_functions[0]));
            _block->insts.push_back(std::make_shared<RVMv>(RegTrans(inst->dst), RVReg_a(0)));
        }
        else if (std::dynamic_pointer_cast<IRMove>(_inst)) {
            auto inst = std::dynamic_pointer_cast<IRMove>(_inst);
            if (inst->src.is_imm()) {
                _block->insts.push_back(std::make_shared<RVLi>(RegTrans(inst->dst), RVImm(inst->src.id)));
            }
            else {
                _block->insts.push_back(std::make_shared<RVMv>(RegTrans(inst->dst), RegTrans(inst->src)));
            }
        }
        else if (std::dynamic_pointer_cast<IRBinary>(_inst)) {
            auto inst = std::dynamic_pointer_cast<IRBinary>(_inst);
            if (inst->src1.is_imm() && inst->src2.is_imm()) {
                int value;
                switch (inst->op) {
                    case IRBinary::And: value = inst->src1.id & inst->src2.id; break;
                    case IRBinary::Or: value = inst->src1.id | inst->src2.id; break;
                    case IRBinary::Xor: value = inst->src1.id ^ inst->src2.id; break;
                    case IRBinary::Add: value = inst->src1.id + inst->src2.id; break;
                    case IRBinary::Sub: value = inst->src1.id - inst->src2.id; break;
                    case IRBinary::Mul: value = inst->src1.id * inst->src2.id; break;
                    case IRBinary::Sdiv: value = inst->src1.id / inst->src2.id; break;
                    case IRBinary::Srem: value = inst->src1.id % inst->src2.id; break;
                    case IRBinary::Shl: value = inst->src1.id << inst->src2.id; break;
                    case IRBinary::Ashr: value = inst->src1.id >> inst->src2.id; break;
                    case IRBinary::Eq: value = inst->src1.id == inst->src2.id; break;
                    case IRBinary::Ne: value = inst->src1.id != inst->src2.id; break;
                    case IRBinary::Slt: value = inst->src1.id < inst->src2.id; break;
                    case IRBinary::Sle: value = inst->src1.id <= inst->src2.id; break;
                    case IRBinary::Sgt: value = inst->src1.id > inst->src2.id; break;
                    case IRBinary::Sge: value = inst->src1.id >= inst->src2.id; break;
                }
                _block->insts.push_back(std::make_shared<RVLi>(RegTrans(inst->dst), RVImm(value)));
            }
            else {
                Sop sop;
                bool is_cmp = false;
                switch (inst->op) {
                    case IRBinary::And: sop = Sop::And; break;
                    case IRBinary::Or: sop = Sop::Or; break;
                    case IRBinary::Xor: sop = Sop::Xor; break;
                    case IRBinary::Add: sop = Sop::Add; break;
                    case IRBinary::Sub: sop = Sop::Sub; break;
                    case IRBinary::Mul: sop = Sop::Mul; break;
                    case IRBinary::Sdiv: sop = Sop::Div; break;
                    case IRBinary::Srem: sop = Sop::Rem; break;
                    case IRBinary::Shl: sop = Sop::Sll; break;
                    case IRBinary::Ashr: sop = Sop::Sra; break;
                    default:
                        is_cmp = true;
                }
                if (is_cmp) {
                    makeCmp(inst->src1, inst->src2, inst->op, RegTrans(inst->dst));
                }
                else {
                    makeBinary(inst->src1, inst->src2, sop, RegTrans(inst->dst));
                }
            }
        }
        else if (std::dynamic_pointer_cast<IRBr>(_inst)) {
            auto inst = std::dynamic_pointer_cast<IRBr>(_inst);
            _block->insts.push_back(std::make_shared<RVBr>(RegTrans(inst->cond), RVReg_zero(), Bop::Ne, RVprog->ref_block[inst->thenBlock]));
            _block->insts.push_back(std::make_shared<RVJump>(RVprog->ref_block[inst->elseBlock]));
        }
        else if (std::dynamic_pointer_cast<IRCall>(_inst)) {
            auto inst = std::dynamic_pointer_cast<IRCall>(_inst);
            for (int i = 0; i < std::min(8, int(inst->paras.size())); ++i) {
                RVReg addr = RegTrans(inst->paras[i]);
                if (addr.is_constString) {
                    _block->insts.push_back(std::make_shared<RVLa>(RVReg_a(i), addr));
                }
                else if (addr.is_global) {
                    RVReg dst = RegTrans(inst->dst);
                    RVReg ptr(newLabel(), 4);
                    _block->insts.push_back(std::make_shared<RVLui>(ptr, RVImm(addr.id, Rop::Hi)));
                    _block->insts.push_back(std::make_shared<RVLd>(RVReg_a(i), ptr, RVImm(addr.id, Rop::Lo), inst->dst.size()));
                }
                else {
                    _block->insts.push_back(std::make_shared<RVMv>(RVReg_a(i), addr));
                }
            }
            int offset = 0;
            for (int i = 8; i < inst->paras.size(); ++i) {
                RVReg addr = RegTrans(inst->paras[i]);
                if (addr.is_global) {
                    RVReg value = RegTrans(inst->paras[i]);
                    RVReg ptr(newLabel(), 4);
                    _block->insts.push_back(std::make_shared<RVLui>(ptr, RVImm(addr.id, Rop::Hi)));
                    _block->insts.push_back(std::make_shared<RVSt>(value, ptr, RVImm(addr.id, Rop::Lo), inst->paras[i].size()));
                }
                else {
                    _block->insts.push_back(std::make_shared<RVSt>(RegTrans(inst->paras[i]), RVReg_sp(), RVImm(offset), inst->paras[i].size()));
                }
                offset += 4;
            }
            _func->paramInStackOffset = std::max(_func->paramInStackOffset, offset);
            _block->insts.push_back(std::make_shared<RVCall>(RVprog->ref_function[inst->func]));
            if (!inst->dst.is_void()) {
                _block->insts.push_back(std::make_shared<RVMv>(RegTrans(inst->dst), RVReg_a(0)));
            }
        }
        else if (std::dynamic_pointer_cast<IRJump>(_inst)) {
            auto inst = std::dynamic_pointer_cast<IRJump>(_inst);
            _block->insts.push_back(std::make_shared<RVJump>(RVprog->ref_block[inst->block]));
        }
        else if (std::dynamic_pointer_cast<IRLoad>(_inst)) {
            auto inst = std::dynamic_pointer_cast<IRLoad>(_inst);
            RVReg addr = RegTrans(inst->addr);
            if (addr.is_global) {
                RVReg dst = RegTrans(inst->dst);
                RVReg ptr(newLabel(), 4);
                _block->insts.push_back(std::make_shared<RVLui>(ptr, RVImm(addr.id, Rop::Hi)));
                _block->insts.push_back(std::make_shared<RVLd>(dst, ptr, RVImm(addr.id, Rop::Lo), inst->dst.size()));
            }
            else {
                _block->insts.push_back(std::make_shared<RVLd>(RegTrans(inst->dst), RegTrans(inst->addr), RVImm(0), inst->dst.size()));
            }
        }
        else if (std::dynamic_pointer_cast<IRStore>(_inst)) {
            auto inst = std::dynamic_pointer_cast<IRStore>(_inst);
            RVReg addr = RegTrans(inst->addr);
            if (addr.is_global) {
                RVReg value = RegTrans(inst->value);
                RVReg ptr(newLabel(), 4);
                _block->insts.push_back(std::make_shared<RVLui>(ptr, RVImm(addr.id, Rop::Hi)));
                _block->insts.push_back(std::make_shared<RVSt>(value, ptr, RVImm(addr.id, Rop::Lo), inst->value.size()));
            }
            else {
                _block->insts.push_back(std::make_shared<RVSt>(RegTrans(inst->value), addr, RVImm(0), inst->value.size()));
            }
        }
        else if (std::dynamic_pointer_cast<IRReturn>(_inst)) {
            auto inst = std::dynamic_pointer_cast<IRReturn>(_inst);
            if (!inst->value.is_void()) {
                if (inst->value.type == IROperand::Imm8 || inst->value.type == IROperand::Imm32) {
                    if (inst->value.id) {
                        _block->insts.push_back(std::make_shared<RVLi>(RVReg_a(0), inst->value.id));
                    }
                    else {
                        _block->insts.push_back(std::make_shared<RVMv>(RVReg_a(0), RVReg_zero()));
                    }
                }
                else {
                    _block->insts.push_back(std::make_shared<RVMv>(RVReg_a(0), RegTrans(inst->value)));
                }
            }
        }
    }
}

void InstSelector::runForFunction(std::shared_ptr<IRFunction> func) {
    auto rFunc = RVprog->ref_function[func];
    _func = rFunc;
    id_n = 1;
    RVprog->ref_reg.clear();
    _block = RVprog->ref_block[func->inBlock];

    _block->insts.push_back(std::make_shared<RVItype>(RVReg_sp(), RVReg_sp(), RVImm(0, Rop::Imm, true), Sop::Add));
    calleeRegs.clear();
    for (auto id : calleeSavedRegNames) {
        RVReg tmp(newLabel());
        _block->insts.push_back(std::make_shared<RVMv>(tmp, RVPReg(id)));
        calleeRegs[id] = tmp;
    }
    RVReg Vra(newLabel());
    _block->insts.push_back(std::make_shared<RVMv>(Vra, RVReg_ra()));



    for (int i = 0; i < std::min(8, int(func->paras.size())); ++i) {
        RVReg reg = RVReg(newLabel(), func->paras[i].size());
        RVprog->ref_reg[func->paras[i].id] = reg;
        _block->insts.push_back(std::make_shared<RVMv>(reg, RVReg_a(i)));
    }
    int offset = 0;
    for (int i = 8; i < func->paras.size(); ++i) {
        RVReg reg = RVReg(newLabel(), func->paras[i].size());
        RVprog->ref_reg[func->paras[i].id] = reg;
        _block->insts.push_back(std::make_shared<RVLd>(reg, RVReg_sp(), RVImm(offset, Rop::Imm, true, false), func->paras[i].size()));
        offset += 4;
    }
    for (auto blk : func->blocks)
        runForBlock(blk);

    _block = RVprog->ref_block[func->outBlock];
    for (auto id : calleeSavedRegNames) {
        _block->insts.push_back(std::make_shared<RVMv>(RVPReg(id), calleeRegs[id]));
    }
    _block->insts.push_back(std::make_shared<RVMv>(RVReg_ra(), Vra));
    _block->insts.push_back(std::make_shared<RVItype>(RVReg_sp(), RVReg_sp(), RVImm(0, Rop::Imm, true,false), Sop::Add));
    _block->insts.push_back(std::make_shared<RVRet>());
    rFunc->regcnt = id_n;
}

void InstSelector::run() {
    RVprog->constString = IRprog->constString;
    for (auto var : IRprog->globalVar) {
        RVReg reg = RVGReg(newLabel(), var.size());
        RVprog->ref_global[var.id] = reg;
    }

    for (auto func : IRprog->func) {
        if (func->isBuiltin) {
            std::shared_ptr<RVFunction> rFunc = std::make_shared<RVFunction>(func->name);
            RVprog->ref_function[func] = rFunc;
            RVprog->builtin_functions.push_back(rFunc);
        }
    }

    for (auto func : IRprog->func) {
        if (!func->isBuiltin) {
            std::shared_ptr<RVFunction> rFunc = std::make_shared<RVFunction>(func->name);
            RVprog->ref_function[func] = rFunc;
            RVprog->functions.push_back(rFunc);
            int tmp = 0;
            for (auto blk : func->blocks) {
                std::shared_ptr<RVBlock> rBlock = std::make_shared<RVBlock>(tmp++);
                rBlock->funcName = func->name;
                RVprog->ref_block[blk] = rBlock;
                rFunc->blocks.push_back(rBlock);
                rFunc->inBlock = RVprog->ref_block[func->inBlock];
                rFunc->outBlock = RVprog->ref_block[func->outBlock];
            }
            for (auto blk : func->blocks) {
                auto rBlock = RVprog->ref_block[blk];
                for (auto x : blk->pre)
                    rBlock->pre.push_back(RVprog->ref_block[x]);
                for (auto x : blk->next)
                    rBlock->succ.push_back(RVprog->ref_block[x]);
            }
        }
    }

    for (auto func : IRprog->func)
        if (!func->isBuiltin)
            runForFunction(func);
}

void InstSelector::makeCmp(IROperand src1, IROperand src2, IRBinary::op_t op, RVReg dst) {
    switch (op) {
        case IRBinary::Eq: {
            RVReg tmp(newLabel());
            makeBinary(src1, src2, Sop::Xor, tmp);
            _block->insts.push_back(std::make_shared<RVSz>(dst, tmp, Szop::Seqz));
            break;
        }
        case IRBinary::Ne: {
            RVReg tmp(newLabel());
            makeBinary(src1, src2, Sop::Xor, tmp);
            _block->insts.push_back(std::make_shared<RVSz>(dst, tmp, Szop::Snez));
            break;
        }
        case IRBinary::Slt: {
            if (src2.is_imm()) {
                _block->insts.push_back(std::make_shared<RVItype>(dst, RegTrans(src1), RVImm(src2.id), Sop::Slt));
            } else {
                _block->insts.push_back(std::make_shared<RVRtype>(dst, RegTrans(src1), RegTrans(src2), Sop::Slt));
            }
            break;
        }
        case IRBinary::Sle: {
            RVReg tmp(newLabel());
            if (src1.is_imm()) {
                _block->insts.push_back(std::make_shared<RVItype>(tmp, RegTrans(src2), RVImm(src1.id), Sop::Slt));
            } else {
                _block->insts.push_back(std::make_shared<RVRtype>(tmp, RegTrans(src2), RegTrans(src1), Sop::Slt));
            }
            _block->insts.push_back(std::make_shared<RVItype>(dst, tmp, RVImm(1), Sop::Xor));
            break;
        }
        case IRBinary::Sgt: {
            if (src1.is_imm()) {
                _block->insts.push_back(std::make_shared<RVItype>(dst, RegTrans(src2), RVImm(src1.id), Sop::Slt));
            } else {
                _block->insts.push_back(std::make_shared<RVRtype>(dst, RegTrans(src2), RegTrans(src1), Sop::Slt));
            }
            break;
        }
        case IRBinary::Sge: {
            RVReg tmp(newLabel());
            if (src2.is_imm()) {
                _block->insts.push_back(std::make_shared<RVItype>(tmp, RegTrans(src1), RVImm(src2.id), Sop::Slt));
            } else {
                _block->insts.push_back(std::make_shared<RVRtype>(tmp, RegTrans(src1), RegTrans(src2), Sop::Slt));
            }
            _block->insts.push_back(std::make_shared<RVItype>(dst, tmp, RVImm(1), Sop::Xor));
            break;
        }
    }
}

void InstSelector::makeBinary(IROperand src1, IROperand src2, Sop op, RVReg dst) {
    if (op == Mul || op == Div || op == Rem)
        _block->insts.push_back(std::make_shared<RVRtype>(dst, RegTrans(src1), RegTrans(src2), op));
    else if (op == Sub) {
        if (src2.is_imm()) {
            _block->insts.push_back(std::make_shared<RVItype>(dst, RegTrans(src1), RVImm(-src2.id), Sop::Add));
        }
        else {
            _block->insts.push_back(std::make_shared<RVRtype>(dst, RegTrans(src1), RegTrans(src2), op));
        }
    }
    else if (src1.is_imm()) {
        _block->insts.push_back(std::make_shared<RVItype>(dst, RegTrans(src2), RVImm(src1.id), op));
    }
    else if (src2.is_imm()) {
        _block->insts.push_back(std::make_shared<RVItype>(dst, RegTrans(src1), RVImm(src2.id), op));
    }
    else {
        _block->insts.push_back(std::make_shared<RVRtype>(dst, RegTrans(src1), RegTrans(src2), op));
    }
}
