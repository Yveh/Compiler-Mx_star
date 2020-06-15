#pragma once

#include <string>
#include <memory>
#include <vector>
#include <set>

#include "RegInfo.h"

enum Rop {Imm, Hi, Lo};

enum Sop {Add, Sub, Slt, Xor, Or, And, Sll, Sra, Mul, Div, Rem};

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
RVReg RVPReg(int _id);
RVReg RVReg_zero();
RVReg RVReg_ra();
RVReg RVReg_a(int _id);
RVReg RVReg_sp();

class RVImm {
public:
    Rop op;
    int id;
    bool is_stack, is_neg;
    std::string to_string();
    RVImm(int _id = 0, Rop _op = Rop::Imm, bool is_stack = false, bool _is_neg = true);
};

class RVInst {
public:
    virtual std::string to_string() = 0;
    virtual std::set<int> getUse() = 0;
    virtual std::set<int> getDef() = 0;
    virtual void replaceUse(int a, int b) = 0;
    virtual void replaceDef(int a, int b) = 0;
    virtual void replaceColor(int a, int b) = 0;
};

class RVBlock {
public:
    std::string funcName;
    int label;
    std::vector<std::shared_ptr<RVInst>> insts;
    std::vector<std::shared_ptr<RVBlock>> pre, succ;
    std::set<int> liveIn, liveOut;
    std::string to_string();
    RVBlock(int _label);
};

class RVFunction {
public:
    int regcnt, paramInStackOffset;
    std::string name;
    std::vector<RVReg> paras;
    std::vector<std::shared_ptr<RVBlock>> blocks;
    std::shared_ptr<RVBlock> inBlock, outBlock;
    std::string to_string();
    RVFunction(std::string _name);
};

class RVBr : public RVInst {
public:
    RVReg rs1, rs2;
    std::shared_ptr<RVBlock> offset;
    Bop op;
    std::string to_string() override;
    std::set<int> getUse() override;
    std::set<int> getDef() override;
    void replaceUse(int a, int b) override;
    void replaceDef(int a, int b) override;
    void replaceColor(int a, int b) override;
    RVBr(RVReg _rs1, RVReg _rs2, Bop _op, std::shared_ptr<RVBlock> _offset);
};

class RVJump : public RVInst {
public:
    std::shared_ptr<RVBlock> offset;
    std::string to_string() override;
    std::set<int> getUse() override;
    std::set<int> getDef() override;
    void replaceUse(int a, int b) override;
    void replaceDef(int a, int b) override;
    void replaceColor(int a, int b) override;
    RVJump(std::shared_ptr<RVBlock> _offset);
};

class RVCall : public RVInst {
public:
    std::shared_ptr<RVFunction> func;
    std::string to_string() override;
    std::set<int> getUse() override;
    std::set<int> getDef() override;
    void replaceUse(int a, int b) override;
    void replaceDef(int a, int b) override;
    void replaceColor(int a, int b) override;
    RVCall(std::shared_ptr<RVFunction> _func);
};

class RVLd : public RVInst {
public:
    RVReg rd, addr;
    RVImm offset;
    int width;
    std::string to_string() override;
    std::set<int> getUse() override;
    std::set<int> getDef() override;
    void replaceUse(int a, int b) override;
    void replaceDef(int a, int b) override;
    void replaceColor(int a, int b) override;
    RVLd(RVReg _rd, RVReg _addr, RVImm _offset, int _width);
};

class RVLi : public RVInst {
public:
    RVReg rd;
    RVImm value;
    std::string to_string() override;
    std::set<int> getUse() override;
    std::set<int> getDef() override;
    void replaceUse(int a, int b) override;
    void replaceDef(int a, int b) override;
    void replaceColor(int a, int b) override;
    RVLi(RVReg _rd, RVImm _value);
};

class RVLui : public RVInst {
public:
    RVReg rd;
    RVImm value;
    std::string to_string() override;
    std::set<int> getUse() override;
    std::set<int> getDef() override;
    void replaceUse(int a, int b) override;
    void replaceDef(int a, int b) override;
    void replaceColor(int a, int b) override;
    RVLui(RVReg _rd, RVImm _value);
};

class RVMv : public RVInst {
public:
    RVReg rd, rs;
    std::string to_string() override;
    std::set<int> getUse() override;
    std::set<int> getDef() override;
    void replaceUse(int a, int b) override;
    void replaceDef(int a, int b) override;
    void replaceColor(int a, int b) override;
    RVMv(RVReg _rd, RVReg _rs);
};

class RVRet : public RVInst {
public:
    std::string to_string() override;
    std::set<int> getUse() override;
    std::set<int> getDef() override;
    void replaceUse(int a, int b) override;
    void replaceDef(int a, int b) override;
    void replaceColor(int a, int b) override;
    RVRet();
};

class RVSt : public RVInst {
public:
    RVReg addr, value;
    RVImm offset;
    int width;
    std::string to_string() override;
    std::set<int> getUse() override;
    std::set<int> getDef() override;
    void replaceUse(int a, int b) override;
    void replaceDef(int a, int b) override;
    void replaceColor(int a, int b) override;
    RVSt(RVReg _value, RVReg _addr, RVImm _offset, int _width);
};

class RVSz : public RVInst {
public:
    RVReg rs, rd;
    Szop op;
    std::string to_string() override;
    std::set<int> getUse() override;
    std::set<int> getDef() override;
    void replaceUse(int a, int b) override;
    void replaceDef(int a, int b) override;
    void replaceColor(int a, int b) override;
    RVSz(RVReg _rd, RVReg _rs, Szop _op);
};

class RVItype : public RVInst {
public:
    RVReg rs, rd;
    RVImm imm;
    Sop op;
    std::string to_string() override;
    std::set<int> getUse() override;
    std::set<int> getDef() override;
    void replaceUse(int a, int b) override;
    void replaceDef(int a, int b) override;
    void replaceColor(int a, int b) override;
    RVItype(RVReg _rd, RVReg _rs, RVImm _imm, Sop _op);
};

class RVRtype : public RVInst {
public:
    RVReg rs1, rs2, rd;
    Sop op;
    std::string to_string() override;
    std::set<int> getUse() override;
    std::set<int> getDef() override;
    void replaceUse(int a, int b) override;
    void replaceDef(int a, int b) override;
    void replaceColor(int a, int b) override;
    RVRtype(RVReg _rd, RVReg _rs1, RVReg _rs2, Sop _op);
};


