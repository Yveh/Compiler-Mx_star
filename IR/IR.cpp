#include "IR.h"

IROperand IROPerandVoid() {return IROperand(IROperand::Void);}
IROperand IROperandReg32(int _id, bool _pointer) {return IROperand(IROperand::Reg32, _id, _pointer);}
IROperand IROperandReg8(int _id, bool _pointer) {return IROperand(IROperand::Reg8, _id, _pointer);}
IROperand IROperandImm32(int _id, bool _pointer) {return IROperand(IROperand::Imm32, _id, _pointer);}
IROperand IROperandImm8(int _id, bool _pointer) {return IROperand(IROperand::Imm8, _id, _pointer);}
IROperand IROperandConst(int _id) {return IROperand(IROperand::constID, _id);}

std::string IROperand::to_string() {
    std::string ret;
    if (type == type_t::Void)
        ret = "void";
    else if (type == type_t::Reg32 || type == type_t::Imm32)
        ret = "i32";
    else
        ret = "i8";
    if (pointer)
        ret += "*";
    return ret;
}

std::string IROperand::get_id() const {
    if (type == Reg32 || type == Reg8)
        return "%" + std::to_string(id);
    else if (type == constID)
        return "str." + std::to_string(id);
    else
        return std::to_string(id);
}

bool IROperand::is_void() {
    return type == type_t::Void;
}

IROperand::IROperand(IROperand::type_t _type, int _id, bool _pointer) : type(_type), id(_id), pointer(_pointer) {}

int IROperand::size() const {
    if (type == Void)
        return 0;
    else if (type == Reg32 || type == Imm32)
        return 4;
    else if (type == Reg8 || type == Imm8)
        return 1;
    else
        return 0;
}

bool IROperand::is_reg() {
    return type == Reg32 || type == Reg8;
}

bool IROperand::operator<(const IROperand &rhs) const {
    return type < rhs.type || (type == rhs.type && id < rhs.id);
}

bool IROperand::operator==(const IROperand &rhs) const {
    return type == rhs.type && id == rhs.id;
}

bool IROperand::is_imm() {
    return type == Imm8 || type == Imm32;
}

std::string IRAlloca::to_string() {
    return dst.get_id() + " = alloca " + dst.to_string();
}

IRAlloca::IRAlloca(IROperand _dst) : dst(_dst) {}

std::string IRMalloc::to_string() {
    return dst.get_id() + " = malloc(" + size.get_id() + ")";
}

IRMalloc::IRMalloc(IROperand _dst, IROperand _size) : dst(_dst), size(_size) {}

std::string IRBinary::to_string() {
    std::string ret;
    switch (op) {
        case op_t::And : ret = "&"; break;
        case op_t::Or : ret = "|"; break;
        case op_t::Xor : ret = "^"; break;
        case op_t::Eq : ret = "=="; break;
        case op_t::Ne : ret = "!="; break;
        case op_t::Slt : ret = "<"; break;
        case op_t::Sle : ret = "<="; break;
        case op_t::Sgt : ret = ">"; break;
        case op_t::Sge : ret = ">="; break;
        case op_t::Shl : ret = "<<"; break;
        case op_t::Ashr : ret = ">>"; break;
        case op_t::Add : ret = "+"; break;
        case op_t::Sub : ret = "-"; break;
        case op_t::Mul : ret = "*"; break;
        case op_t::Sdiv : ret = "/"; break;
        case op_t::Srem : ret = "%"; break;
    }
    return dst.get_id() + " = " + src1.get_id() + " " + ret + " " + src2.get_id();
}

IRBinary::IRBinary(IRBinary::op_t _op, IROperand _dst, IROperand _src1, IROperand _src2) : op(_op), dst(_dst), src1(_src1), src2(_src2) {}

std::string IRBr::to_string() {
    return "br " + cond.get_id() + " lab" + std::to_string(thenBlock->label) + " lab" + std::to_string(elseBlock->label);
}

IRBr::IRBr(IROperand _cond, std::shared_ptr<IRBlock> _tb, std::shared_ptr<IRBlock> _eb) : cond(_cond), thenBlock(_tb), elseBlock(_eb) {}

std::string IRCall::to_string() {
    std::string ret;
    if (func->retType.is_void())
        ret =  func->retType.to_string() + " @" + func->name + "(";
    else
        ret = dst.get_id() + " = " + func->retType.to_string() + "@" + func->name + "(";
    bool first = true;
    for (auto child : paras) {
        if (!first)
            ret += ",";
        first = false;
        ret += child.to_string() + " " + child.get_id();
    }
    ret += ")";
    return ret;
}

IRCall::IRCall(std::shared_ptr<IRFunction> _func, std::vector<IROperand> _paras, IROperand _dst) : func(_func), paras(_paras), dst(_dst) {}

std::string IRJump::to_string() {
    return "br lab" + std::to_string(block->label);
}

IRJump::IRJump(std::shared_ptr<IRBlock> _blk) : block(_blk) {}

std::string IRLoad::to_string() {
    return dst.get_id() + " = load " + dst.to_string() + " " + addr.get_id();
}

IRLoad::IRLoad(IROperand _dst, IROperand _addr) : dst(_dst), addr(_addr) {}

std::string IRStore::to_string() {
    return "store " + value.to_string() + " " + addr.get_id() + " " + value.get_id();
}

IRStore::IRStore(IROperand _addr, IROperand _value) : addr(_addr), value(_value) {}

std::string IRReturn::to_string() {
    return "ret " + value.to_string() + " " + value.get_id();
}

IRReturn::IRReturn(IROperand _value) : value(_value) {}

IRFunction::IRFunction(std::string _name) : name(_name) {
    inBlock = std::make_shared<IRBlock>(0);
    isBuiltin = 0;
}

void IRFunction::getAllBlocks(std::shared_ptr<IRBlock> cur) {
    if (vis.count(cur->label))
        return;
    vis.insert(cur->label);
    blocks.push_back(cur);
    std::vector<std::shared_ptr<IRBlock>> nxt;
    for (auto inst : cur->insts) {
        if (std::dynamic_pointer_cast<IRBr>(inst)) {
            auto tmp = std::dynamic_pointer_cast<IRBr>(inst);
            nxt.push_back(tmp->thenBlock);
            nxt.push_back(tmp->elseBlock);
            cur->next.push_back(tmp->thenBlock);
            cur->next.push_back(tmp->elseBlock);
            tmp->thenBlock->pre.push_back(cur);
            tmp->elseBlock->pre.push_back(cur);
        }
        if (std::dynamic_pointer_cast<IRJump>(inst)) {
            auto tmp = std::dynamic_pointer_cast<IRJump>(inst);
            nxt.push_back(tmp->block);
            cur->next.push_back(tmp->block);
            tmp->block->pre.push_back(cur);
        }
    }
    for (auto child : nxt) {
        getAllBlocks(child);
    }

}

IRBlock::IRBlock(int _label) : label(_label) {}


IRClass::IRClass(std::string _name) : name(_name) {}

int IRClass::getOffset(std::string name) {
    return offset[ref[name]];
}

IRPhi::IRPhi(IROperand _dst) : dst(_dst) {}

std::string IRPhi::to_string() {
    std::string ret = dst.get_id() + " = phi ";
    for (int i = 0; i < values.size(); ++i) {
        if (i)
            ret += ", ";
        ret += "[" + values[i].get_id() + ", LAB" + std::to_string(blocks[i]->label) + "]";
    }
    return ret;
}

IRMove::IRMove(IROperand _dst, IROperand _src) : dst(_dst), src(_src) {}

std::string IRMove::to_string() {
    return dst.get_id() + " = " + src.get_id();
}
