#pragma once

#include <memory>
#include <string>
#include <set>

#include "Env.h"

class Builtin {
public:
    static std::set<std::string> reservedWord;
    static void init(std::shared_ptr<Env> env);
    static bool checkVarName(std::string key);
};