#include <iostream>

#include "antlr4-runtime.h"
#include "Mx_starLexer.h"
#include "Mx_starParser.h"
#include "ASTBuilder.h"
#include "TypeChecker.h"
#include "SemanticIssue.h"
#include "Builtin.h"

int main(int argc, char *argv[]){
    /* If Debug */
//    const std::string filepath("../local-judge/testcase/sema/misc-package/misc-19.mx");
//    std::ifstream ifs;
//    ifs.open(filepath);
//    if (!ifs.good()) {
//        std::cout << "bad";
//    }
//    antlr4::ANTLRInputStream input(ifs);
    /* If OnlineJudge */
    antlr4::ANTLRInputStream input(std::cin);
    /* ************** */
    Mx_starLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    tokens.fill();
    Mx_starParser parser(&tokens);
    antlr4::tree::ParseTree* tree = parser.prog();
    if (lexer.getNumberOfSyntaxErrors() + parser.getNumberOfSyntaxErrors() > 0)
        return -1;
    ASTBuilder builder;
    auto node = builder.build(tree);
    std::shared_ptr<SemanticIssue> issues = std::make_shared<SemanticIssue>();
    TypeChecker checker(issues);
    Builtin::init(checker.env);
    checker.createEnv(node.get());
    if (issues->count() > 0) {
        issues->print();
        return -1;
    }
    checker.typeCheck(node.get());
    if (issues->count() > 0) {
        issues->print();
        return -1;
    }
    return 0;
}