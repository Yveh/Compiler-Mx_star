#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>

#include "Types.h"

class IROperand {
public:
    enum type_t {
        Void, Reg32, Reg8, Imm32, Imm8, constID
    };
    type_t type;
    bool pointer;
    int id;
    bool is_reg();
    bool is_imm();
    bool is_void();
    std::string to_string();
    std::string get_id() const;
    int size() const;
    IROperand(type_t _type = Void, int _id = 0, bool _pointer = 0);
    bool operator < (const IROperand &rhs) const;
    bool operator == (const IROperand &rhs) const;
};

IROperand IROPerandVoid();
IROperand IROperandReg32(int _id = 0, bool _pointer= 0);
IROperand IROperandReg8(int _id = 0, bool _pointer = 0);
IROperand IROperandImm32(int _id = 0, bool _pointer = 0);
IROperand IROperandImm8(int _id = 0, bool _pointer = 0);
IROperand IROperandConst(int _id = 0);

class IRInst {
public:
    std::string comment;
    virtual std::string to_string() = 0;
};

class IRBlock {
public:
    std::list<std::shared_ptr<IRInst>> insts;
    std::vector<std::shared_ptr<IRBlock>> next, pre;
    std::shared_ptr<IRBlock> idom;
    std::set<std::shared_ptr<IRBlock>> domFrontier;
    int label;
    IRBlock(int _label);
};

class IRFunction {
public:
    std::string name;
    std::vector<std::shared_ptr<IRBlock>> blocks;
    std::shared_ptr<IRBlock> inBlock, outBlock;
    std::vector<IROperand> paras;
    IROperand retType;
    std::set<int> vis;
    bool isBuiltin;
    void getAllBlocks(std::shared_ptr<IRBlock> cur);
    IRFunction(std::string _name);
};

class IRClass {
public:
    std::string name;
    int size;
    std::vector<IROperand> member;
    std::vector<int> offset;
    std::map<std::string, int> ref;
    int getOffset(std::string varName);
    IRClass(std::string _name);
};

class IRAlloca : public IRInst {
public:
    IROperand dst;
    std::string to_string() override;
    IRAlloca(IROperand _dst);
};

class IRMalloc : public IRInst {
public:
    IROperand dst, size;
    std::string to_string() override;
    IRMalloc(IROperand _dst, IROperand _size);
};

class IRBinary : public IRInst {
public:
    enum op_t {
        And, Or, Xor, Eq, Ne, Slt, Sle, Sgt, Sge, Shl, Ashr, Add, Sub, Mul, Sdiv, Srem
    };
    op_t op;
    IROperand dst, src1, src2;
    std::string to_string() override;
    IRBinary(op_t _op, IROperand _dst, IROperand _src1, IROperand _src2);
};

class IRBr : public IRInst {
public:
    std::shared_ptr<IRBlock> thenBlock, elseBlock;
    IROperand cond;
    std::string to_string() override;
    IRBr(IROperand _cond, std::shared_ptr<IRBlock> _tb, std::shared_ptr<IRBlock> _eb);
};

class IRCall : public IRInst {
public:
    std::shared_ptr<IRFunction> func;
    IROperand dst;
    std::vector<IROperand> paras;
    std::string to_string() override;
    IRCall(std::shared_ptr<IRFunction> _func, std::vector<IROperand> _paras, IROperand dst = IROperand());
};

class IRJump : public IRInst {
public:
    std::shared_ptr<IRBlock> block;
    std::string to_string() override;
    IRJump(std::shared_ptr<IRBlock> _blk);
};

class IRMove : public IRInst {
public:
    IROperand dst, src;
    std::string to_string() override;
    IRMove(IROperand _dst, IROperand _src);
};

class IRLoad : public IRInst {
public:
    IROperand dst, addr;
    std::string to_string() override;
    IRLoad(IROperand _dst, IROperand _addr);
};

class IRStore : public IRInst {
public:
    IROperand addr, value;
    std::string to_string() override;
    IRStore(IROperand _addr, IROperand _value);
};

class IRReturn : public IRInst {
public:
    IROperand value;
    std::string to_string() override;
    IRReturn(IROperand _value = IROperand());
};

class IRPhi : public IRInst {
public:
    IROperand dst;
    std::vector<std::shared_ptr<IRBlock>> blocks;
    std::vector<IROperand> values;
    std::string to_string() override;
    IRPhi(IROperand _dst);
};