#pragma once

#include <memory>

class ASTNode;
class ASTRoot;
class ASTStmt;
class ASTStmtBreak;
class ASTStmtContinue;
class ASTStmtReturn;
class ASTStmtFor;
class ASTStmtWhile;
class ASTStmtIf;
class ASTStmtExpr;
class ASTClassDecl;
class ASTBlock;
class ASTFuncDecl;
class ASTVarDecl;
class ASTExpr;
class ASTExprNew;
class ASTExprAssign;
class ASTExprBinary;
class ASTExprUnary;
class ASTExprSubscript;
class ASTExprFuncCall;
class ASTExprMemberAccess;
class ASTExprVar;
class ASTExprLiteral;

class ASTVisitor {
public:
    virtual void visit(ASTNode* node);
    virtual void visit(ASTRoot* node);
    virtual void visit(ASTStmt* node);
    virtual void visit(ASTStmtBreak* node);
    virtual void visit(ASTStmtContinue* node);
    virtual void visit(ASTStmtReturn* node);
    virtual void visit(ASTStmtFor* node);
    virtual void visit(ASTStmtWhile* node);
    virtual void visit(ASTStmtIf* node);
    virtual void visit(ASTStmtExpr* node);
    virtual void visit(ASTClassDecl* node);
    virtual void visit(ASTBlock* node);
    virtual void visit(ASTFuncDecl* node);
    virtual void visit(ASTVarDecl* node);
    virtual void visit(ASTExpr* node);
    virtual void visit(ASTExprNew* node);
    virtual void visit(ASTExprAssign* node);
    virtual void visit(ASTExprBinary* node);
    virtual void visit(ASTExprUnary* node);
    virtual void visit(ASTExprSubscript* node);
    virtual void visit(ASTExprFuncCall* node);
    virtual void visit(ASTExprMemberAccess* node);
    virtual void visit(ASTExprVar* node);
    virtual void visit(ASTExprLiteral* node);
};