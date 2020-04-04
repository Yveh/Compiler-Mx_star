#include "Builtin.h"

std::set<std::string> Builtin::reservedWord;

void Builtin::init() {
    reservedWord.insert("int");
    reservedWord.insert("bool");
    reservedWord.insert("string");
    reservedWord.insert("null");
    reservedWord.insert("void");
    reservedWord.insert("true");
    reservedWord.insert("false");
    reservedWord.insert("if");
    reservedWord.insert("else");
    reservedWord.insert("for");
    reservedWord.insert("while");
    reservedWord.insert("break");
    reservedWord.insert("continue");
    reservedWord.insert("return");
    reservedWord.insert("new");
    reservedWord.insert("class");
    reservedWord.insert("this");
}

bool Builtin::checkVarName(std::string key) {
    return reservedWord.count(key) == 0;
}
