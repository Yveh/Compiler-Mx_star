#include "ASTNode.h"

void ASTRoot::accept(ASTVisitor *visitor) {
    for (auto child : varList)
        visitor->visit(std::dynamic_pointer_cast<ASTVarDecl>(child));
    for (auto child : funcList)
        visitor->visit(std::dynamic_pointer_cast<ASTFuncDecl>(child));
    for (auto child : classList)
        visitor->visit(std::dynamic_pointer_cast<ASTClassDecl>(child));
}

void ASTStmtBreak::accept(ASTVisitor *visitor) {}

void ASTStmtContinue::accept(ASTVisitor *visitor) {}

void ASTStmtReturn::accept(ASTVisitor *visitor) {
//    if (retValue)
//        visitor->visit(std::dynamic_pointer_cast<ASTExpr>(retValue));
}

void ASTStmtFor::accept(ASTVisitor *visitor) {
//    if (init)
//        visitor->visit(std::dynamic_pointer_cast<ASTExpr>(init));
//    if (cond)
//        visitor->visit(std::dynamic_pointer_cast<ASTExpr>(cond));
//    if (incr)
//        visitor->visit(std::dynamic_pointer_cast<ASTExpr>(incr));
//    visitor->visit(stmt);
}

void ASTStmtWhile::accept(ASTVisitor *visitor) {
//    visitor->visit(cond);
//    visitor->visit(stmt);
}

void ASTStmtIf::accept(ASTVisitor *visitor) {
//    visitor->visit(cond);
//    visitor->visit(thenStmt);
//    if (elseStmt)
//        visitor->visit(elseStmt);
}

void ASTStmtExpr::accept(ASTVisitor *visitor) {

}

void ASTClassDecl::accept(ASTVisitor *visitor) {
//    for (auto child : varList) {
//        visitor->visit(child);
//    }
//    for (auto child : funcList) {
//        visitor->visit(child);
//    }

}

void ASTBlock::accept(ASTVisitor *visitor) {
//    for (auto child : stmts) {
//        visitor->visit(child);
//    }
}

void ASTFuncDecl::accept(ASTVisitor *visitor) {
//    for (auto child : paras) {
//        visitor->visit(child);
//    }
//    ASTBlock::accept(visitor);
}

void ASTVarDecl::accept(ASTVisitor *visitor) {
//    if (initValue)
//        visitor->visit(initValue);
}

void ASTExpr::accept(ASTVisitor *visitor) {}

void ASTExprNew::accept(ASTVisitor *visitor) {
//    for (auto child : paras) {
//        visitor->visit(child);
//    }
}

void ASTExprAssign::accept(ASTVisitor *visitor) {
//    ASTExpr::accept(visitor);
}

void ASTExprBinary::accept(ASTVisitor *visitor) {
//    visitor->visit(operandL);
//    visitor->visit(operandR);
}

void ASTExprUnary::accept(ASTVisitor *visitor) {
//    visitor->visit(operand);
}

void ASTExprSubscript::accept(ASTVisitor *visitor) {
//    ASTExpr::accept(visitor);
}

void ASTExprFuncCall::accept(ASTVisitor *visitor) {
//    ASTExpr::accept(visitor);
}

void ASTExprMemberAccess::accept(ASTVisitor *visitor) {
//    ASTExpr::accept(visitor);
}

void ASTExprVar::accept(ASTVisitor *visitor) {
//    ASTExpr::accept(visitor);
}

void ASTExprLiteral::accept(ASTVisitor *visitor) {
//    ASTExpr::accept(visitor);
}


