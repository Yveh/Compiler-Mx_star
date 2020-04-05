#pragma once

#include <vector>
#include <string>
#include <iostream>

class SemanticIssue {
private:
    std::vector<std::pair<int, std::string>> errors;
public:
    void issue(int pos, std::string msg);
    int count();
    void print();
};