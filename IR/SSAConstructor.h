#pragma once

#include "IRProgram.h"

class SSAConstructor {
public:
    std::shared_ptr<IRProgram> prog;
    IROperand getfa(std::map<IROperand, IROperand> &map, IROperand key);
    void runForFunction(std::shared_ptr<IRFunction> func);
    void run(std::shared_ptr<IRProgram> _prog);
};