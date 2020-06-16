#include "RVInst.h"

RVFunction::RVFunction(std::string _name) : name(_name) {
    regcnt = 0;
    paramInStackOffset = 0;
}

std::string RVFunction::to_string() {
    return name;
}

RVBlock::RVBlock(int _label) : label(_label) {}

std::string RVBlock::to_string() {
    return "." + funcName + "_.bb" + std::to_string(label);
}

RVReg::RVReg(int _id, int _size, bool _is_global, bool _is_constString, bool _is_special) : id(_id), size(_size), is_global(_is_global), is_constString(_is_constString), is_special(_is_special) {}

std::string RVReg::to_string() {
    if (is_special)
        return regNames[id];
    else if (is_constString)
        return ".str." + std::to_string(id);
    else if (is_global)
        return "g" + std::to_string(id);
    else
        return "%" + std::to_string(id);
}

RVReg RVGReg(int _id, int _size) {return RVReg(_id, _size, 1, 0);}
RVReg RVSReg(int _id, int _size) {return RVReg(_id, _size, 1, 1);}
RVReg RVPReg(int _id) {return RVReg(_id, 0, 0, 0, 1);}
RVReg RVReg_zero() {return RVReg(0, 0, 0, 0, 1);}
RVReg RVReg_ra() {return RVReg(1, 0, 0, 0, 1);};
RVReg RVReg_a(int _id) {return RVReg(10 + _id, 0, 0, 0, 1);}
RVReg RVReg_sp() {return RVReg(2, 0, 0, 0, 1);}

RVImm::RVImm(int _id, Rop _op, bool _is_stack, bool _is_neg) : id(_id), op(_op), is_stack(_is_stack), is_neg(_is_neg) {}

std::string RVImm::to_string() {
    if (op == Imm)
        return std::to_string(id);
    else if (op == Hi)
        return "%hi(g" + std::to_string(id) + ")";
    else
        return "%lo(g" + std::to_string(id) + ")";
}

RVLi::RVLi(RVReg _rd, RVImm _value) : rd(_rd), value(_value) {}

RVSt::RVSt(RVReg _value, RVReg _addr, RVImm _offset, int _width) : value(_value), addr(_addr), offset(_offset), width(_width) {}

RVLui::RVLui(RVReg _rd, RVImm _value) : rd(_rd), value(_value) {}

RVMv::RVMv(RVReg _rd, RVReg _rs) : rd(_rd), rs(_rs) {}

RVLd::RVLd(RVReg _rd, RVReg _addr, RVImm _offset, int _width) : rd(_rd), addr(_addr), offset(_offset), width(_width) {}

RVJump::RVJump(std::shared_ptr<RVBlock> _offset) : offset(_offset) {}

RVBr::RVBr(RVReg _rs1, RVReg _rs2, Bop _op, std::shared_ptr<RVBlock> _offset) : rs1(_rs1), rs2(_rs2), op(_op), offset(_offset) {}

RVItype::RVItype(RVReg _rd, RVReg _rs, RVImm _imm, Sop _op) : rd(_rd), rs(_rs), imm(_imm), op(_op) {}

RVRtype::RVRtype(RVReg _rd, RVReg _rs1, RVReg _rs2, Sop _op) : rd(_rd), rs1(_rs1), rs2(_rs2), op(_op) {}

RVSz::RVSz(RVReg _rd, RVReg _rs, Szop _op) : rd(_rd), rs(_rs), op(_op) {}

RVCall::RVCall(std::shared_ptr<RVFunction> _func) : func(_func) {}


std::string RVBr::to_string() {
    std::string ret = "b";
    switch (op) {
        case Bop::Eq : ret += "eq"; break;
        case Bop::Ne : ret += "ne"; break;
        case Bop::Ge : ret += "ge"; break;
        case Bop::Gt : ret += "gt"; break;
        case Bop::Le : ret += "le"; break;
        case Bop::Lt : ret += "lt"; break;
    }
    ret += " " + rs1.to_string() + ", " + rs2.to_string() + ", " + offset->to_string();
    return ret;
}

std::set<int> RVBr::getUse() {
    return std::set<int>{rs1.is_special ? -rs1.id : rs1.id, rs2.is_special ? -rs2.id : rs2.id};
}

std::set<int> RVBr::getDef() {
    return std::set<int>();
}

void RVBr::replaceUse(int a, int b) {
    if (!rs1.is_special && rs1.id == a)
        rs1.id = b;
    if (!rs2.is_special && rs2.id == a)
        rs2.id = b;
}

void RVBr::replaceDef(int a, int b) {}

void RVBr::replaceColor(int a, int b) {
    if (!rs1.is_special && rs1.id == a) {
        rs1.id = b;
        rs1.is_special = 1;
    }
    if (!rs2.is_special && rs2.id == a) {
        rs2.id = b;
        rs2.is_special = 1;
    }
}

std::string RVJump::to_string() {
    return "j " + offset->to_string();
}

std::set<int> RVJump::getUse() {
    return std::set<int>();
}

std::set<int> RVJump::getDef() {
    return std::set<int>();
}

void RVJump::replaceUse(int a, int b) {}

void RVJump::replaceDef(int a, int b) {}

void RVJump::replaceColor(int a, int b) {}

std::string RVLd::to_string() {
    if (width == 1) {
        return "lb " + rd.to_string() + ", " + offset.to_string() + "(" + addr.to_string() + ")";
    }
    else {
        return "lw " + rd.to_string() + ", " + offset.to_string() + "(" + addr.to_string() + ")";
    }
}

std::set<int> RVLd::getUse() {
    return std::set<int>{addr.is_special ? -addr.id : addr.id};
}

std::set<int> RVLd::getDef() {
    return std::set<int>{rd.is_special ? -rd.id : rd.id};
}

void RVLd::replaceUse(int a, int b) {
    if (!addr.is_special && addr.id == a)
        addr.id = b;
}

void RVLd::replaceDef(int a, int b) {
    if (!rd.is_special && rd.id == a)
        rd.id = b;
}

void RVLd::replaceColor(int a, int b) {
    if (!rd.is_special && rd.id == a) {
        rd.id = b;
        rd.is_special = 1;
    }
    if (!addr.is_special && addr.id == a) {
        addr.id = b;
        addr.is_special = 1;
    }
}

std::string RVLui::to_string() {
    return "lui " + rd.to_string() + ", " + value.to_string();
}

std::set<int> RVLui::getUse() {
    return std::set<int>();
}

std::set<int> RVLui::getDef() {
    return std::set<int>{rd.is_special ? -rd.id : rd.id};
}

void RVLui::replaceUse(int a, int b) {}

void RVLui::replaceDef(int a, int b) {
    if (!rd.is_special && rd.id == a)
        rd.id = b;
}

void RVLui::replaceColor(int a, int b) {
    if (!rd.is_special && rd.id == a) {
        rd.id = b;
        rd.is_special = 1;
    }
}

std::string RVLi::to_string() {
    return "li " + rd.to_string() + ", " + value.to_string();
}

std::set<int> RVLi::getUse() {
    return std::set<int>{};
}

std::set<int> RVLi::getDef() {
    return std::set<int>{rd.is_special ? -rd.id : rd.id};
}

void RVLi::replaceUse(int a, int b) {}

void RVLi::replaceDef(int a, int b) {
    if (!rd.is_special && rd.id == a)
        rd.id = b;
}

void RVLi::replaceColor(int a, int b) {
    if (!rd.is_special && rd.id == a) {
        rd.id = b;
        rd.is_special = 1;
    }
}

std::string RVSt::to_string() {
    if (width == 1) {
        return "sb " + value.to_string() + ", " + offset.to_string() + "(" + addr.to_string() + ")";
    }
    else {
        return "sw " + value.to_string() + ", " + offset.to_string() + "(" + addr.to_string() + ")";
    }
}

std::set<int> RVSt::getUse() {
    return std::set<int>{addr.is_special ? -addr.id : addr.id, value.is_special ? -value.id : value.id};
}

std::set<int> RVSt::getDef() {
    return std::set<int>();
}

void RVSt::replaceUse(int a, int b) {
    if (!addr.is_special && addr.id == a)
        addr.id = b;
    if (!value.is_special && value.id == a)
        value.id = b;
}

void RVSt::replaceDef(int a, int b) {}

void RVSt::replaceColor(int a, int b) {
    if (!addr.is_special && addr.id == a) {
        addr.id = b;
        addr.is_special = 1;
    }
    if (!value.is_special && value.id == a) {
        value.id = b;
        value.is_special = 1;
    }
}

std::string RVSz::to_string() {
    if (op == Seqz) {
        return "seqz " + rd.to_string() + ", " + rs.to_string();
    }
    else {
        return "snez " + rd.to_string() + ", " + rs.to_string();
    }
}

std::set<int> RVSz::getUse() {
    return std::set<int>{rs.is_special ? -rs.id : rs.id};
}

std::set<int> RVSz::getDef() {
    return std::set<int>{rd.is_special ? -rd.id : rd.id};
}

void RVSz::replaceUse(int a, int b) {
    if (!rs.is_special && rs.id == a)
        rs.id = b;
}

void RVSz::replaceDef(int a, int b) {
    if (!rd.is_special && rd.id == a)
        rd.id = b;
}

void RVSz::replaceColor(int a, int b) {
    if (!rd.is_special && rd.id == a) {
        rd.id = b;
        rd.is_special = 1;
    }
    if (!rs.is_special && rs.id == a) {
        rs.id = b;
        rs.is_special = 1;
    }
}

std::string RVMv::to_string() {
    return "mv " + rd.to_string() + ", " + rs.to_string();
}

std::set<int> RVMv::getUse() {
    return std::set<int>{rs.is_special ? -rs.id : rs.id};
}

std::set<int> RVMv::getDef() {
    return std::set<int>{rd.is_special ? -rd.id : rd.id};
}

void RVMv::replaceUse(int a, int b) {
    if (!rs.is_special && rs.id == a)
        rs.id = b;
}

void RVMv::replaceDef(int a, int b) {
    if (!rd.is_special && rd.id == a)
        rd.id = b;
}

void RVMv::replaceColor(int a, int b) {
    if (!rd.is_special && rd.id == a) {
        rd.id = b;
        rd.is_special = 1;
    }
    if (!rs.is_special && rs.id == a) {
        rs.id = b;
        rs.is_special = 1;
    }
}

std::string RVItype::to_string() {
    std::string ret;
    switch (op) {
        case Sop::And: ret = "andi "; break;
        case Sop::Or: ret = "ori "; break;
        case Sop::Xor: ret = "xori "; break;
        case Sop::Add: ret = "addi "; break;
        case Sop::Sll: ret = "slli "; break;
        case Sop::Sra: ret = "slri "; break;
        case Sop::Slt: ret = "slti "; break;
    }
    ret += rd.to_string() + ", " + rs.to_string() + ", " + imm.to_string();
    return ret;
}

std::set<int> RVItype::getUse() {
    return std::set<int>{rs.is_special ? -rs.id : rs.id};
}

std::set<int> RVItype::getDef() {
    return std::set<int>{rd.is_special ? -rd.id : rd.id};
}

void RVItype::replaceUse(int a, int b) {
    if (!rs.is_special && rs.id == a)
        rs.id = b;
}

void RVItype::replaceDef(int a, int b) {
    if (!rd.is_special && rd.id == a)
        rd.id = b;
}

void RVItype::replaceColor(int a, int b) {
    if (!rs.is_special && rs.id == a) {
        rs.id = b;
        rs.is_special = 1;
    }
    if (!rd.is_special && rd.id == a) {
        rd.id = b;
        rd.is_special = 1;
    }
}

std::string RVRtype::to_string() {
    std::string ret;
    switch (op) {
        case Sop::And: ret = "and "; break;
        case Sop::Or: ret = "or "; break;
        case Sop::Xor: ret = "xor "; break;
        case Sop::Add: ret = "add "; break;
        case Sop::Sub: ret = "sub "; break;
        case Sop::Sll: ret = "sll "; break;
        case Sop::Sra: ret = "slr "; break;
        case Sop::Mul: ret = "mul "; break;
        case Sop::Div: ret = "div "; break;
        case Sop::Rem: ret = "rem "; break;
        case Sop::Slt: ret = "slt "; break;
    }
    ret += rd.to_string() + ", " + rs1.to_string() + ", " + rs2.to_string();
    return ret;
}

std::set<int> RVRtype::getUse() {
    return std::set<int>{rs1.is_special ? -rs1.id : rs1.id, rs2.is_special ? -rs2.id : rs2.id};
}

std::set<int> RVRtype::getDef() {
    return std::set<int>{rd.is_special ? -rd.id : rd.id};
}

void RVRtype::replaceUse(int a, int b) {
    if (!rs1.is_special && rs1.id == a)
        rs1.id = b;
    if (!rs2.is_special && rs2.id == a)
        rs2.id = b;
}

void RVRtype::replaceDef(int a, int b) {
    if (!rd.is_special && rd.id == a)
        rd.id = b;
}

void RVRtype::replaceColor(int a, int b) {
    if (!rs1.is_special && rs1.id == a) {
        rs1.id = b;
        rs1.is_special = 1;
    }
    if (!rs2.is_special && rs2.id == a) {
        rs2.id = b;
        rs2.is_special = 1;
    }
    if (!rd.is_special && rd.id == a) {
        rd.id = b;
        rd.is_special = 1;
    }
}

std::string RVCall::to_string() {
    return "call " + func->to_string();
}

std::set<int> RVCall::getUse() {
    std::set<int> ret;
    for (int i = 0; i < std::min(8, int(func->paras.size())); ++i) {
        ret.insert(-10 - i);
    }
    return ret;
}

std::set<int> RVCall::getDef() {
    return std::set<int>{-1, -5, -6, -7, -10, -11, -12, -13, -14, -15, -16, -17, -28, -29, -30, -31};
}

void RVCall::replaceUse(int a, int b) {}

void RVCall::replaceDef(int a, int b) {}

void RVCall::replaceColor(int a, int b) {}

RVRet::RVRet() {}

std::string RVRet::to_string() {
    return std::string("ret");
}

std::set<int> RVRet::getUse() {
    return std::set<int>{-1};
}

std::set<int> RVRet::getDef() {
    return std::set<int>();
}

void RVRet::replaceUse(int a, int b) {}

void RVRet::replaceDef(int a, int b) {}

void RVRet::replaceColor(int a, int b) {}

RVLa::RVLa(RVReg _rd, RVReg _rs) : rd(_rd), rs(_rs) {}

std::string RVLa::to_string() {
    return "la " + rd.to_string() + ", " + rs.to_string();
}
std::set<int> RVLa::getUse() {
    return std::set<int>();
}

std::set<int> RVLa::getDef() {
    return std::set<int>{rd.is_special ? -rd.id : rd.id};
}

void RVLa::replaceUse(int a, int b) {}

void RVLa::replaceDef(int a, int b) {
    if (!rd.is_special && rd.id == a)
        rd.id = b;
}
void RVLa::replaceColor(int a, int b) {
    if (!rd.is_special && rd.id == a) {
        rd.id = b;
        rd.is_special = 1;
    }
}