#pragma once

#include "SymbolTable.h"
#include "Types.h"

class varInfo {
public:
    type_t varType;
};

class funcInfo {
public:
    type_t funcType, retType;
    SymbolTable<varInfo> paras;
    std::vector<type_t> parasType;
    std::vector<std::string> parasName;
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