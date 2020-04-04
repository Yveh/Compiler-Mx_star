#pragma once

#include <string>
#include <set>

class Builtin {
public:
    static std::set<std::string> reservedWord;
    static void init();
    static bool checkVarName(std::string key);
};