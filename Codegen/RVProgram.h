#pragma once

#include <vector>
#include <string>
#include <memory>
#include <map>

#include "RVInst.h"
#include "IR.h"

class RVProgram {
public:
    std::map<int, RVReg> ref_reg;
    std::map<int, RVReg> ref_global;
    std::map<std::shared_ptr<IRBlock>, std::shared_ptr<RVBlock>> ref_block;
    std::map<std::shared_ptr<IRFunction>, std::shared_ptr<RVFunction>> ref_function;
    std::vector<std::shared_ptr<RVFunction>> functions;
    std::vector<std::shared_ptr<RVFunction>> builtin_functions;
    std::vector<std::string> constString;

    std::string StringTrans(std::string s);

    bool hasVar(int _id);
    RVReg getVar(int _id);
    bool checkGlobal(int _id);
    RVReg getGlobal(int _id);
    void outputBlock(std::shared_ptr<RVBlock> blk, std::ostream &ofs);
    void outputIR(std::ostream &ofs);
};