#pragma once

#include <memory>

#include "IRProgram.h"
#include "RVProgram.h"
#include "RVInst.h"
#include "IR.h"

class InstSelector {
public:
    std::shared_ptr<IRProgram> IRprog;
    std::shared_ptr<RVProgram> RVprog;

    std::shared_ptr<RVBlock> _block;
    std::shared_ptr<RVFunction> _func;

    std::map<int, RVReg> calleeRegs;

    int id_n;
    int newLabel();
    RVReg RegTrans(IROperand operand);
    void makeCmp(IROperand src1, IROperand src2, IRBinary::op_t op, RVReg dst);
    void makeBinary(IROperand src1, IROperand src2, Sop op, RVReg dst);
    InstSelector(std::shared_ptr<IRProgram> _old, std::shared_ptr<RVProgram> _new);
    void runForBlock(std::shared_ptr<IRBlock> blk);
    void runForFunction(std::shared_ptr<IRFunction> func);
    void run();
};
