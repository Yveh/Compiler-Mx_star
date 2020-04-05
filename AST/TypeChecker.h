#pragma once

#include <memory>

#include "ASTVisitor.h"
#include "ASTNode.h"
#include "Env.h"
#include "SemanticIssue.h"
#include "Builtin.h"

class TypeChecker : public ASTVisitor {
public:
    std::shared_ptr<Env> env;
    SemanticIssue* issue;
    void createEnv(ASTRoot* node, SemanticIssue* _issue);
    void typeCheck(ASTRoot* node);

    virtual void visit(ASTNode* node) override;
    virtual void visit(ASTRoot* node) override;
    virtual void visit(ASTStmt* node) override;
    virtual void visit(ASTStmtBreak* node) override;
    virtual void visit(ASTStmtContinue* node) override;
    virtual void visit(ASTStmtReturn* node) override;
    virtual void visit(ASTStmtFor* node) override;
    virtual void visit(ASTStmtWhile* node) override;
    virtual void visit(ASTStmtIf* node) override;
    virtual void visit(ASTStmtExpr* node) override;
    virtual void visit(ASTClassDecl* node) override;
    virtual void visit(ASTBlock* node) override;
    virtual void visit(ASTFuncDecl* node) override;
    virtual void visit(ASTVarDecl* node) override;
    virtual void visit(ASTExpr* node) override;
    virtual void visit(ASTExprNew* node) override;
    virtual void visit(ASTExprAssign* node) override;
    virtual void visit(ASTExprBinary* node) override;
    virtual void visit(ASTExprUnary* node) override;
    virtual void visit(ASTExprSubscript* node) override;
    virtual void visit(ASTExprFuncCall* node) override;
    virtual void visit(ASTExprMemberAccess* node) override;
    virtual void visit(ASTExprVar* node) override;
    virtual void visit(ASTExprLiteral* node) override;

    TypeChecker() {
        env = std::make_shared<Env>();
    }
};