#pragma once

#include <string>
#include <memory>
#include <vector>

enum Rop {Imm, Hi, Lo};

enum Sop {Add, Sub, Slt, Xor, Or, And, Shl, Ashr, Sra, Mul, Div, Rem};

enum Bop {Eq, Ne, Le, Ge, Lt, Gt};

enum Szop {Seqz, Snez};

class RVReg {
public:
    int id, size;
    bool is_global, is_constString, is_special;
    std::string to_string();
    RVReg(int _id = 0, int _size = 0, bool _is_global = 0, bool _is_constString = 0, bool _is_special = 0);
};

RVReg RVGReg(int _id, int _size);
RVReg RVSReg(int _id, int _size);
RVReg RVReg_zero();
RVReg RVReg_a(int _id);
RVReg RVReg_sp();

class RVImm {
public:
    Rop op;
    int id;
    RVImm(int _id = 0, Rop _op = Rop::Imm);
};

class RVInst {
public:
    virtual std::string to_string() = 0;
};

class RVBlock {
public:
    int label;
    std::vector<std::shared_ptr<RVInst>> insts;
    RVBlock(int _label);
};

class RVFunction {
public:
    std::string name;
    std::vector<RVReg> paras;
    std::vector<std::shared_ptr<RVBlock>> blocks;
    RVFunction(std::string _name);
};

class RVBr : public RVInst {
public:
    RVReg rs1, rs2;
    std::shared_ptr<RVBlock> offset;
    Bop op;
    std::string to_string() override;
    RVBr(RVReg _rs1, RVReg _rs2, Bop _op, std::shared_ptr<RVBlock> _offset);
};

class RVJump : public RVInst {
public:
    std::shared_ptr<RVBlock> block;
    std::string to_string() override;
    RVJump(std::shared_ptr<RVBlock> _blk);
};

class RVCall : public RVInst {
public:
    std::shared_ptr<RVFunction> func;
    std::string to_string() override;
    RVCall(std::shared_ptr<RVFunction> _func);
};

class RVLa : public RVInst {
public:
    RVReg rd, src;
};

class RVLd : public RVInst {
public:
    RVReg rd, addr;
    RVImm offset;
    int width;
    std::string to_string() override;
    RVLd(RVReg _rd, RVReg _addr, RVImm _offset, int _width);
};

class RVLi : public RVInst {
public:
    RVReg rd;
    RVImm value;
    std::string to_string() override;
    RVLi(RVReg _rd, RVImm _value);
};

class RVLui : public RVInst {
public:
    RVReg rd;
    RVImm value;
    std::string to_string() override;
    RVLui(RVReg _rd, RVImm _value);
};

class RVMv : public RVInst {
public:
    RVReg rd, rs;
    std::string to_string() override;
    RVMv(RVReg _rd, RVReg _rs);
};

class RVRet : public RVInst {

};

class RVSt : public RVInst {
public:
    RVReg addr, value;
    RVImm offset;
    int width;
    std::string to_string() override;
    RVSt(RVReg _value, RVReg _addr, RVImm _offset, int _width);
};

class RVSz : public RVInst {
public:
    RVReg rs, rd;
    Szop op;
    std::string to_string() override;
    RVSz(RVReg _rd, RVReg _rs, Szop _op);
};

class RVItype : public RVInst {
public:
    RVReg rs, rd;
    RVImm imm;
    Sop op;
    std::string to_string() override;
    RVItype(RVReg _rd, RVReg _rs, RVImm _imm, Sop _op);
};

class RVRtype : public RVInst {
public:
    RVReg rs1, rs2, rd;
    Sop op;
    std::string to_string() override;
    RVRtype(RVReg _rd, RVReg _rs1, RVReg _rs2, Sop _op);
};


