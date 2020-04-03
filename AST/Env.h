#pragma once

#include "SymbolTable.h"
#include "types.h"

class funcInfo {
public:
    type_t funcType, retType;
    std::vector<type_t> parasType;
};

class varInfo {
public:
    type_t varType;
};

class classInfo {
public:
    type_t classType;
    SymbolTable<funcInfo> memberFunc;
    SymbolTable<varInfo> memberVar;
};

class Env {
public:
    SymbolTable<funcInfo> funcTable;
    SymbolTable<classInfo> classTable;
    SymbolTable<varInfo> varTable;
};