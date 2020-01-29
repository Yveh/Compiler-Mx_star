#include <iostream>
#include "antlr4-runtime.h"
#include "Mx_starLexer.h"
#include "Mx_starParser.h"
#include "EvalVisitor.h"

int main(){
    const std::string filepath;
    std::ifstream ifs;
    ifs.open(filepath);
    if (!ifs.good()) {
        std::cout<<"bad";
    }
    antlr4::ANTLRInputStream input(ifs);
    Mx_starLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    tokens.fill();
    Mx_starParser parser(&tokens);
    antlr4::tree::ParseTree* tree = parser.file();
    EvalVisitor visitor;
    visitor.visit(tree);

    ifs.close();
    return 0;
}