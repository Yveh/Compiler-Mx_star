#include "ASTNode.h"

void ASTRoot::accept(ASTVisitor *visitor) {
    for (auto child : children) {
        if (dynamic_cast<ASTVarDecl*>(child.get()))
            visitor->visit(dynamic_cast<ASTVarDecl*>(child.get()));
        else if (dynamic_cast<ASTFuncDecl*>(child.get()))
            visitor->visit(dynamic_cast<ASTFuncDecl*>(child.get()));
        else
            visitor->visit(dynamic_cast<ASTClassDecl*>(child.get()));
    }
}

void ASTStmt::accept(ASTVisitor *visitor) {
    if (dynamic_cast<ASTVarDecl*>(this))
        visitor->visit(dynamic_cast<ASTVarDecl*>(this));
    else if (dynamic_cast<ASTStmtIf*>(this))
        visitor->visit(dynamic_cast<ASTStmtIf*>(this));
    else if (dynamic_cast<ASTStmtFor*>(this))
        visitor->visit(dynamic_cast<ASTStmtFor*>(this));
    else if (dynamic_cast<ASTStmtWhile*>(this))
        visitor->visit(dynamic_cast<ASTStmtWhile*>(this));
    else if (dynamic_cast<ASTStmtBreak*>(this))
        visitor->visit(dynamic_cast<ASTStmtBreak*>(this));
    else if (dynamic_cast<ASTStmtContinue*>(this))
        visitor->visit(dynamic_cast<ASTStmtContinue*>(this));
    else if (dynamic_cast<ASTStmtReturn*>(this))
        visitor->visit(dynamic_cast<ASTStmtReturn*>(this));
    else if (dynamic_cast<ASTStmtExpr*>(this))
        visitor->visit(dynamic_cast<ASTStmtExpr*>(this));
    else
        visitor->visit(dynamic_cast<ASTBlock*>(this));
}

void ASTStmtBreak::accept(ASTVisitor *visitor) {}

void ASTStmtContinue::accept(ASTVisitor *visitor) {}

void ASTStmtReturn::accept(ASTVisitor *visitor) {
    if (retValue)
        visitor->visit(dynamic_cast<ASTExpr*>(retValue.get()));
}

void ASTStmtFor::accept(ASTVisitor *visitor) {
    if (init)
        visitor->visit(dynamic_cast<ASTExpr*>(init.get()));
    if (cond)
        visitor->visit(dynamic_cast<ASTExpr*>(cond.get()));
    if (incr)
        visitor->visit(dynamic_cast<ASTExpr*>(incr.get()));
    if (stmt)
        visitor->visit(dynamic_cast<ASTStmt*>(stmt.get()));
}

void ASTStmtWhile::accept(ASTVisitor *visitor) {
    visitor->visit(dynamic_cast<ASTExpr*>(cond.get()));
    if (stmt)
        visitor->visit(dynamic_cast<ASTStmt*>(stmt.get()));
}

void ASTStmtIf::accept(ASTVisitor *visitor) {
    visitor->visit(dynamic_cast<ASTExpr*>(cond.get()));
    if (thenStmt)
        visitor->visit(dynamic_cast<ASTStmt*>(thenStmt.get()));
    if (elseStmt)
        visitor->visit(dynamic_cast<ASTStmt*>(elseStmt.get()));
}

void ASTStmtExpr::accept(ASTVisitor *visitor) {
    visitor->visit(dynamic_cast<ASTExpr*>(expr.get()));
}

void ASTClassDecl::accept(ASTVisitor *visitor) {
    for (auto child : varList) {
        visitor->visit(dynamic_cast<ASTVarDecl*>(child.get()));
    }
    for (auto child : funcList) {
        visitor->visit(dynamic_cast<ASTFuncDecl*>(child.get()));
    }
}

void ASTBlock::accept(ASTVisitor *visitor) {
    for (auto child : stmts)
        visitor->visit(dynamic_cast<ASTStmt*>(child.get()));
}

void ASTFuncDecl::accept(ASTVisitor *visitor) {
    for (auto child : paras) {
        visitor->visit(dynamic_cast<ASTVarDecl*>(child.get()));
    }
    ASTBlock::accept(visitor);
}

void ASTVarDecl::accept(ASTVisitor *visitor) {
    for (int idx = 0; idx < name.size(); idx++)
        if (initValue[idx])
            visitor->visit(dynamic_cast<ASTExpr*>(initValue[idx].get()));
}

void ASTExpr::accept(ASTVisitor *visitor) {
    if (dynamic_cast<ASTExprNew*>(this))
        visitor->visit(dynamic_cast<ASTExprNew*>(this));
    else if (dynamic_cast<ASTExprAssign*>(this))
        visitor->visit(dynamic_cast<ASTExprAssign*>(this));
    else if (dynamic_cast<ASTExprBinary*>(this))
        visitor->visit(dynamic_cast<ASTExprBinary*>(this));
    else if (dynamic_cast<ASTExprUnary*>(this))
        visitor->visit(dynamic_cast<ASTExprUnary*>(this));
    else if (dynamic_cast<ASTExprSubscript*>(this))
        visitor->visit(dynamic_cast<ASTExprSubscript*>(this));
    else if (dynamic_cast<ASTExprFuncCall*>(this))
        visitor->visit(dynamic_cast<ASTExprFuncCall*>(this));
    else if (dynamic_cast<ASTExprMemberAccess*>(this))
        visitor->visit(dynamic_cast<ASTExprMemberAccess*>(this));
    else if (dynamic_cast<ASTExprVar*>(this))
        visitor->visit(dynamic_cast<ASTExprVar*>(this));
    else
        visitor->visit(dynamic_cast<ASTExprLiteral*>(this));
}

void ASTExprNew::accept(ASTVisitor *visitor) {
    for (auto child : paras) {
        if (child)
            visitor->visit(dynamic_cast<ASTExpr*>(child.get()));
    }
}

void ASTExprAssign::accept(ASTVisitor *visitor) {
    visitor->visit(dynamic_cast<ASTExpr*>((operandL.get())));
    visitor->visit(dynamic_cast<ASTExpr*>((operandR.get())));
}

void ASTExprBinary::accept(ASTVisitor *visitor) {
    visitor->visit(dynamic_cast<ASTExpr*>((operandL.get())));
    visitor->visit(dynamic_cast<ASTExpr*>((operandR.get())));
}

void ASTExprUnary::accept(ASTVisitor *visitor) {
    visitor->visit(dynamic_cast<ASTExpr*>((operand.get())));
}

void ASTExprSubscript::accept(ASTVisitor *visitor) {
    visitor->visit(dynamic_cast<ASTExpr*>((array.get())));
    visitor->visit(dynamic_cast<ASTExpr*>((subscript.get())));
}

void ASTExprFuncCall::accept(ASTVisitor *visitor) {
    for (auto child : paras)
        visitor->visit(dynamic_cast<ASTExpr*>((child.get())));
}

void ASTExprMemberAccess::accept(ASTVisitor *visitor) {
    visitor->visit(dynamic_cast<ASTExpr*>((object.get())));
    if (memberFunc)
        visitor->visit(dynamic_cast<ASTExpr*>((memberFunc.get())));
}

void ASTExprVar::accept(ASTVisitor *visitor) {}

void ASTExprLiteral::accept(ASTVisitor *visitor) {}
