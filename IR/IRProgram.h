#pragma once

#include <vector>
#include <map>
#include "IR.h"

class IRProgram {
public:
    int id_n;
    std::map<std::string, int> ref_func, ref_class;
    std::map<int, IROperand> ref_var;
    int newLabel() {return ++id_n;}

    std::vector<IROperand> globalVar;
    std::vector<std::string> constString;
    std::vector<std::shared_ptr<IRFunction>> func;
    std::vector<std::shared_ptr<IRClass>> object;

    bool hasFunc(std::string name);
    bool hasVar(int x);
    std::shared_ptr<IRFunction> getFunc(std::string name);
    std::shared_ptr<IRClass> getClass(std::string name);
    IROperand getVar(int x);

    void getAllBlocks();
    void outputBlock(std::shared_ptr<IRBlock> _blk, std::ostream &ofs);
    void outputIR(std::ostream &ofs);
};
