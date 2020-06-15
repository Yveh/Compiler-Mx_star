#pragma once

#include <memory>

#include "RVInst.h"
#include "RVProgram.h"

class Liveness {
public:
    std::shared_ptr<RVProgram> prog;

    std::map<std::shared_ptr<RVBlock>, std::set<int>> BUse, BDef;
    std::set<std::shared_ptr<RVBlock>> visit;

    Liveness(std::shared_ptr<RVProgram> _prog);
    void runForFunction(std::shared_ptr<RVFunction> func);
    void runForBlock(std::shared_ptr<RVBlock> blk);
    void runForLive(std::shared_ptr<RVBlock> blk);
};