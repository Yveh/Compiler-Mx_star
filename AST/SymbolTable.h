#pragma once

#include <string>
#include <vector>
#include <map>

template<typename T>
class SymbolTable {
private:
    int ord = 0;
    int mark = 0;
    std::map<std::string, int> hash;
    std::vector<T> vec;
    std::vector<std::string> ref;
    std::vector<std::pair<int, int>> stack;
public:
    bool insert(std::string key, T value);
    bool count(std::string s);
    T find(std::string s);
    void beginScope();
    void endScope();
};