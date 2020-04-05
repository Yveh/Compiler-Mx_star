#include "SemanticIssue.h"

void SemanticIssue::issue(int pos, std::string msg) {
    errors.push_back(std::make_pair(pos, msg));
}

int SemanticIssue::count() {
    return errors.size();
}

void SemanticIssue::print() {
    for (auto error : errors) {
        std::cerr << "[" << error.first << "] : " << error.second << std::endl;
    }
}