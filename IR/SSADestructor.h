#pragma once

#include "IR.h"
#include "IRProgram.h"

class SSADestructor {
public:
    class PCopy_t {
    public:
        std::vector<std::shared_ptr<IRMove>> copies;
        std::map<IROperand, int> use_cnt;
        void add(std::shared_ptr<IRMove> inst);
        bool check();
    };

    std::shared_ptr<IRProgram> prog;
    std::map<std::shared_ptr<IRBlock>, std::shared_ptr<PCopy_t>> pc;
    void runForBlock(std::shared_ptr<IRBlock> blk);
    void runForFunction(std::shared_ptr<IRFunction> func);
    void run(std::shared_ptr<IRProgram> _prog);
};