#include "Builtin.h"

std::set<std::string> Builtin::reservedWord;

void Builtin::init(std::shared_ptr<Env> env) {
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

    classInfo stringinfo;
    funcInfo funcinfo;
    // int string.length()
    funcinfo.retType = typeInt;
    stringinfo.memberFunc.insert("length", funcinfo);
    // int string.parseInt()
    stringinfo.memberFunc.insert("parseInt", funcinfo);
    // int string.ord(int pos)
    funcinfo.parasType.push_back(typeInt);
    stringinfo.memberFunc.insert("ord", funcinfo);
    // string string.substring(int left, int right)
    funcinfo.retType = typeString;
    funcinfo.parasType.push_back(typeInt);
    stringinfo.memberFunc.insert("substring", funcinfo);
    // stringinfo
    env->classTable.insert("string", stringinfo);

    // array.size()
    classInfo arrayinfo;
    funcinfo.retType = typeInt;
    funcinfo.parasType.clear();
    arrayinfo.memberFunc.insert("size", funcinfo);
    env->classTable.insert("", arrayinfo);

    // void print(string str)
    funcinfo.retType = typeVoid;
    funcinfo.parasType.push_back(typeString);
    env->funcTable.insert("print", funcinfo);
    // void print(string str)
    env->funcTable.insert("println", funcinfo);
    // void print(int n)
    funcinfo.parasType.clear();
    funcinfo.parasType.push_back(typeInt);
    env->funcTable.insert("printInt", funcinfo);
    // void print(string str)
    env->funcTable.insert("printlnInt", funcinfo);
    // string toString(int i)
    funcinfo.retType = typeString;
    env->funcTable.insert("toString", funcinfo);
    // string getString()
    funcinfo.parasType.clear();
    env->funcTable.insert("getString", funcinfo);
    // int getInt()
    funcinfo.retType = typeInt;
    env->funcTable.insert("getInt", funcinfo);
}

bool Builtin::checkVarName(std::string key) {
    return reservedWord.count(key) == 0;
}
