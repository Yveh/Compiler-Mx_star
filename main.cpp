#include <iostream>

#include "antlr4-runtime.h"
#include "Mx_starLexer.h"
#include "Mx_starParser.h"
#include "ASTNode.h"
#include "ASTBuilder.h"

int main(){
    const std::string filepath("../testcase/sema/if-package/if-2.mx");
    std::ifstream ifs;
    ifs.open(filepath);
    if (!ifs.good()) {
        std::cout << "bad";
    }
    antlr4::ANTLRInputStream input(ifs);
    Mx_starLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    tokens.fill();
    Mx_starParser parser(&tokens);
    antlr4::tree::ParseTree* tree = parser.prog();
    if (lexer.getNumberOfSyntaxErrors() + parser.getRuleNames() > 0)
        return 2;
    ASTBuilder builder;
    auto node = builder.build(tree);
    std::cout << node->pos << std::endl;
    ifs.close();
    return 0;
}