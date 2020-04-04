#pragma once

#include "SymbolTable.h"
#include "Types.h"

class varInfo {
public:
    type_t varType;
};

class funcInfo {
public:
    type_t retType;
    std::vector<type_t> parasType;
};

class classInfo {
public:
    SymbolTable<funcInfo> memberFunc;
    SymbolTable<varInfo> memberVar;
};

class Env {
public:
    SymbolTable<funcInfo> funcTable;
    SymbolTable<classInfo> classTable;
    SymbolTable<varInfo> varTable;
    int inClass = 0, inLoop = 0, inFunc = 0;
    bool hasReturn = 0;
    std::string className, funcName;
};