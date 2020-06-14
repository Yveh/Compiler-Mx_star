#include "ASTNode.h"

void ASTRoot::accept(std::shared_ptr<ASTVisitor> visitor) {
    for (auto child : children) {
        if (std::dynamic_pointer_cast<ASTVarDecl>(child))
            visitor->visit(std::dynamic_pointer_cast<ASTVarDecl>(child));
        else if (std::dynamic_pointer_cast<ASTFuncDecl>(child))
            visitor->visit(std::dynamic_pointer_cast<ASTFuncDecl>(child));
        else
            visitor->visit(std::dynamic_pointer_cast<ASTClassDecl>(child));
    }
}

void ASTStmt::accept(std::shared_ptr<ASTVisitor> visitor) {
    if (std::dynamic_pointer_cast<ASTVarDecl>(shared_from_this()))
        visitor->visit(std::dynamic_pointer_cast<ASTVarDecl>(shared_from_this()));
    else if (std::dynamic_pointer_cast<ASTStmtIf>(shared_from_this()))
        visitor->visit(std::dynamic_pointer_cast<ASTStmtIf>(shared_from_this()));
    else if (std::dynamic_pointer_cast<ASTStmtFor>(shared_from_this()))
        visitor->visit(std::dynamic_pointer_cast<ASTStmtFor>(shared_from_this()));
    else if (std::dynamic_pointer_cast<ASTStmtWhile>(shared_from_this()))
        visitor->visit(std::dynamic_pointer_cast<ASTStmtWhile>(shared_from_this()));
    else if (std::dynamic_pointer_cast<ASTStmtBreak>(shared_from_this()))
        visitor->visit(std::dynamic_pointer_cast<ASTStmtBreak>(shared_from_this()));
    else if (std::dynamic_pointer_cast<ASTStmtContinue>(shared_from_this()))
        visitor->visit(std::dynamic_pointer_cast<ASTStmtContinue>(shared_from_this()));
    else if (std::dynamic_pointer_cast<ASTStmtReturn>(shared_from_this()))
        visitor->visit(std::dynamic_pointer_cast<ASTStmtReturn>(shared_from_this()));
    else if (std::dynamic_pointer_cast<ASTStmtExpr>(shared_from_this()))
        visitor->visit(std::dynamic_pointer_cast<ASTStmtExpr>(shared_from_this()));
    else
        visitor->visit(std::dynamic_pointer_cast<ASTBlock>(shared_from_this()));
}

void ASTStmtBreak::accept(std::shared_ptr<ASTVisitor> visitor) {}

void ASTStmtContinue::accept(std::shared_ptr<ASTVisitor> visitor) {}

void ASTStmtReturn::accept(std::shared_ptr<ASTVisitor> visitor) {
    if (retValue)
        visitor->visit(std::dynamic_pointer_cast<ASTExpr>(retValue));
}

void ASTStmtFor::accept(std::shared_ptr<ASTVisitor> visitor) {
    if (init)
        visitor->visit(std::dynamic_pointer_cast<ASTExpr>(init));
    if (cond)
        visitor->visit(std::dynamic_pointer_cast<ASTExpr>(cond));
    if (incr)
        visitor->visit(std::dynamic_pointer_cast<ASTExpr>(incr));
    if (stmt)
        visitor->visit(std::dynamic_pointer_cast<ASTStmt>(stmt));
}

void ASTStmtWhile::accept(std::shared_ptr<ASTVisitor> visitor) {
    visitor->visit(std::dynamic_pointer_cast<ASTExpr>(cond));
    if (stmt)
        visitor->visit(std::dynamic_pointer_cast<ASTStmt>(stmt));
}

void ASTStmtIf::accept(std::shared_ptr<ASTVisitor> visitor) {
    visitor->visit(std::dynamic_pointer_cast<ASTExpr>(cond));
    if (thenStmt)
        visitor->visit(std::dynamic_pointer_cast<ASTStmt>(thenStmt));
    if (elseStmt)
        visitor->visit(std::dynamic_pointer_cast<ASTStmt>(elseStmt));
}

void ASTStmtExpr::accept(std::shared_ptr<ASTVisitor> visitor) {
    visitor->visit(std::dynamic_pointer_cast<ASTExpr>(expr));
}

void ASTClassDecl::accept(std::shared_ptr<ASTVisitor> visitor) {
    for (auto child : varList) {
        visitor->visit(std::dynamic_pointer_cast<ASTVarDecl>(child));
    }
    for (auto child : funcList) {
        visitor->visit(std::dynamic_pointer_cast<ASTFuncDecl>(child));
    }
}

void ASTBlock::accept(std::shared_ptr<ASTVisitor> visitor) {
    for (auto child : stmts)
        visitor->visit(std::dynamic_pointer_cast<ASTStmt>(child));
}

void ASTFuncDecl::accept(std::shared_ptr<ASTVisitor> visitor) {
    for (auto child : paras) {
        visitor->visit(std::dynamic_pointer_cast<ASTVarDecl>(child));
    }
    ASTBlock::accept(visitor);
}

void ASTVarDecl::accept(std::shared_ptr<ASTVisitor> visitor) {
    for (int idx = 0; idx < name.size(); idx++)
        if (initValue[idx])
            visitor->visit(std::dynamic_pointer_cast<ASTExpr>(initValue[idx]));
}

void ASTExpr::accept(std::shared_ptr<ASTVisitor> visitor) {
    if (std::dynamic_pointer_cast<ASTExprNew>(shared_from_this()))
        visitor->visit(std::dynamic_pointer_cast<ASTExprNew>(shared_from_this()));
    else if (std::dynamic_pointer_cast<ASTExprAssign>(shared_from_this()))
        visitor->visit(std::dynamic_pointer_cast<ASTExprAssign>(shared_from_this()));
    else if (std::dynamic_pointer_cast<ASTExprBinary>(shared_from_this()))
        visitor->visit(std::dynamic_pointer_cast<ASTExprBinary>(shared_from_this()));
    else if (std::dynamic_pointer_cast<ASTExprUnary>(shared_from_this()))
        visitor->visit(std::dynamic_pointer_cast<ASTExprUnary>(shared_from_this()));
    else if (std::dynamic_pointer_cast<ASTExprSubscript>(shared_from_this()))
        visitor->visit(std::dynamic_pointer_cast<ASTExprSubscript>(shared_from_this()));
    else if (std::dynamic_pointer_cast<ASTExprFuncCall>(shared_from_this()))
        visitor->visit(std::dynamic_pointer_cast<ASTExprFuncCall>(shared_from_this()));
    else if (std::dynamic_pointer_cast<ASTExprMemberAccess>(shared_from_this()))
        visitor->visit(std::dynamic_pointer_cast<ASTExprMemberAccess>(shared_from_this()));
    else if (std::dynamic_pointer_cast<ASTExprVar>(shared_from_this()))
        visitor->visit(std::dynamic_pointer_cast<ASTExprVar>(shared_from_this()));
    else
        visitor->visit(std::dynamic_pointer_cast<ASTExprLiteral>(shared_from_this()));
}

void ASTExprNew::accept(std::shared_ptr<ASTVisitor> visitor) {
    for (auto child : paras) {
        if (child)
            visitor->visit(std::dynamic_pointer_cast<ASTExpr>(child));
    }
}

void ASTExprAssign::accept(std::shared_ptr<ASTVisitor> visitor) {
    visitor->visit(std::dynamic_pointer_cast<ASTExpr>((operandL)));
    visitor->visit(std::dynamic_pointer_cast<ASTExpr>((operandR)));
}

void ASTExprBinary::accept(std::shared_ptr<ASTVisitor> visitor) {
    visitor->visit(std::dynamic_pointer_cast<ASTExpr>((operandL)));
    visitor->visit(std::dynamic_pointer_cast<ASTExpr>((operandR)));
}

void ASTExprUnary::accept(std::shared_ptr<ASTVisitor> visitor) {
    visitor->visit(std::dynamic_pointer_cast<ASTExpr>((operand)));
}

void ASTExprSubscript::accept(std::shared_ptr<ASTVisitor> visitor) {
    visitor->visit(std::dynamic_pointer_cast<ASTExpr>((array)));
    visitor->visit(std::dynamic_pointer_cast<ASTExpr>((subscript)));
}

void ASTExprFuncCall::accept(std::shared_ptr<ASTVisitor> visitor) {
    for (auto child : paras)
        visitor->visit(std::dynamic_pointer_cast<ASTExpr>((child)));
}

void ASTExprMemberAccess::accept(std::shared_ptr<ASTVisitor> visitor) {
    visitor->visit(std::dynamic_pointer_cast<ASTExpr>((object)));
    if (memberFunc)
        visitor->visit(std::dynamic_pointer_cast<ASTExpr>((memberFunc)));
}

void ASTExprVar::accept(std::shared_ptr<ASTVisitor> visitor) {}

void ASTExprLiteral::accept(std::shared_ptr<ASTVisitor> visitor) {}
