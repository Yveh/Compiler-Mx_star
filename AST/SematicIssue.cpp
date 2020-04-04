#include "SematicIssue.h"

void SematicIssue::issue(int pos, std::string msg) {
    errors.push_back(std::make_pair(pos, msg));
}

int SematicIssue::count() {
    return errors.size();
}

void SematicIssue::print() {
    for (auto error : errors) {
        std::cerr << "[" << error.first << "] : " << error.second << std::endl;
    }
}