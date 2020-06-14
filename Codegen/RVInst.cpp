#include "RVInst.h"

RVFunction::RVFunction(std::string _name) : name(_name) {}

RVBlock::RVBlock(int _label) : label(_label) {}

RVReg::RVReg(int _id, int _size, bool _is_global, bool _is_constString, bool _is_special) : id(_id), size(_size), is_global(_is_global), is_constString(_is_constString), is_special(_is_special) {}

RVReg RVGReg(int _id, int _size) {return RVReg(_id, _size, 1, 0);}
RVReg RVSReg(int _id, int _size) {return RVReg(_id, _size, 1, 1);}
RVReg RVReg_zero() {return RVReg(0, 0, 0, 0, 1);}
RVReg RVReg_a(int _id) {return RVReg(10 + _id, 0, 0, 0, 1);}
RVReg RVReg_sp() {return RVReg(2, 0, 0, 0, 1);}

RVImm::RVImm(int _id, Rop _op) : id(_id), op(_op) {}

RVLi::RVLi(RVReg _rd, RVImm _value) : rd(_rd), value(_value) {}

RVSt::RVSt(RVReg _value, RVReg _addr, RVImm _offset, int _width) : value(_value), addr(_addr), offset(_offset), width(_width) {}

RVLui::RVLui(RVReg _rd, RVImm _value) : rd(_rd), value(_value) {}

RVMv::RVMv(RVReg _rd, RVReg _rs) : rd(_rd), rs(_rs) {}

RVLd::RVLd(RVReg _rd, RVReg _addr, RVImm _offset, int _width) : rd(_rd), addr(_addr), offset(_offset), width(_width) {}

RVJump::RVJump(std::shared_ptr<RVBlock> _blk) : block(_blk) {}

RVBr::RVBr(RVReg _rs1, RVReg _rs2, Bop _op, std::shared_ptr<RVBlock> _offset) : rs1(_rs1), rs2(_rs2), op(_op), offset(_offset) {}

RVItype::RVItype(RVReg _rd, RVReg _rs, RVImm _imm, Sop _op) : rd(_rd), rs(_rs), imm(_imm), op(_op) {}

RVRtype::RVRtype(RVReg _rd, RVReg _rs1, RVReg _rs2, Sop _op) : rd(_rd), rs1(_rs1), rs2(_rs2), op(_op) {}

RVSz::RVSz(RVReg _rd, RVReg _rs, Szop _op) : rd(_rd), rs(_rs), op(_op) {}

RVCall::RVCall(std::shared_ptr<RVFunction> _func) : func(_func) {}


std::string RVBr::to_string() {
    return std::string();
}

std::string RVJump::to_string() {
    return std::string();
}

std::string RVLd::to_string() {
    return std::string();
}

std::string RVLui::to_string() {
    return std::string();
}

std::string RVLi::to_string() {
    return std::string();
}

std::string RVSt::to_string() {
    return std::string();
}

std::string RVSz::to_string() {
    return std::string();
}

std::string RVMv::to_string() {
    return std::string();
}

std::string RVItype::to_string() {
    return std::string();
}

std::string RVRtype::to_string() {
    return std::string();
}

std::string RVCall::to_string() {
    return std::string();
}