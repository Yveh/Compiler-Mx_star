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

class ASTVisitor : public std::enable_shared_from_this<ASTVisitor> {
public:
    virtual void visit(std::shared_ptr<ASTNode> node);
    virtual void visit(std::shared_ptr<ASTRoot> node);
    virtual void visit(std::shared_ptr<ASTStmt> node);
    virtual void visit(std::shared_ptr<ASTStmtBreak> node);
    virtual void visit(std::shared_ptr<ASTStmtContinue> node);
    virtual void visit(std::shared_ptr<ASTStmtReturn> node);
    virtual void visit(std::shared_ptr<ASTStmtFor> node);
    virtual void visit(std::shared_ptr<ASTStmtWhile> node);
    virtual void visit(std::shared_ptr<ASTStmtIf> node);
    virtual void visit(std::shared_ptr<ASTStmtExpr> node);
    virtual void visit(std::shared_ptr<ASTClassDecl> node);
    virtual void visit(std::shared_ptr<ASTBlock> node);
    virtual void visit(std::shared_ptr<ASTFuncDecl> node);
    virtual void visit(std::shared_ptr<ASTVarDecl> node);
    virtual void visit(std::shared_ptr<ASTExpr> node);
    virtual void visit(std::shared_ptr<ASTExprNew> node);
    virtual void visit(std::shared_ptr<ASTExprAssign> node);
    virtual void visit(std::shared_ptr<ASTExprBinary> node);
    virtual void visit(std::shared_ptr<ASTExprUnary> node);
    virtual void visit(std::shared_ptr<ASTExprSubscript> node);
    virtual void visit(std::shared_ptr<ASTExprFuncCall> node);
    virtual void visit(std::shared_ptr<ASTExprMemberAccess> node);
    virtual void visit(std::shared_ptr<ASTExprVar> node);
    virtual void visit(std::shared_ptr<ASTExprLiteral> node);
};