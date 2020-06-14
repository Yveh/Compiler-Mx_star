#pragma once

#include "IR.h"
#include "IRProgram.h"

class SSADestructor {
public:
    std::shared_ptr<IRProgram> prog;
    void runForFunction(std::shared_ptr<IRFunction> func);
    void run(std::shared_ptr<IRProgram> _prog);
};