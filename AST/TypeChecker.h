#pragma once

#include <memory>
#include <utility>

#include "ASTVisitor.h"
#include "ASTNode.h"
#include "Env.h"
#include "SemanticIssue.h"
#include "Builtin.h"

class TypeChecker : public ASTVisitor {
public:
    std::shared_ptr<Env> env;
    std::shared_ptr<SemanticIssue> issue;
    void createEnv(std::shared_ptr<ASTRoot> node);
    void typeCheck(std::shared_ptr<ASTRoot> node);

    virtual void visit(std::shared_ptr<ASTNode> node) override;
    virtual void visit(std::shared_ptr<ASTRoot> node) override;
    virtual void visit(std::shared_ptr<ASTStmt> node) override;
    virtual void visit(std::shared_ptr<ASTStmtBreak> node) override;
    virtual void visit(std::shared_ptr<ASTStmtContinue> node) override;
    virtual void visit(std::shared_ptr<ASTStmtReturn> node) override;
    virtual void visit(std::shared_ptr<ASTStmtFor> node) override;
    virtual void visit(std::shared_ptr<ASTStmtWhile> node) override;
    virtual void visit(std::shared_ptr<ASTStmtIf> node) override;
    virtual void visit(std::shared_ptr<ASTStmtExpr> node) override;
    virtual void visit(std::shared_ptr<ASTClassDecl> node) override;
    virtual void visit(std::shared_ptr<ASTBlock> node) override;
    virtual void visit(std::shared_ptr<ASTFuncDecl> node) override;
    virtual void visit(std::shared_ptr<ASTVarDecl> node) override;
    virtual void visit(std::shared_ptr<ASTExpr> node) override;
    virtual void visit(std::shared_ptr<ASTExprNew> node) override;
    virtual void visit(std::shared_ptr<ASTExprAssign> node) override;
    virtual void visit(std::shared_ptr<ASTExprBinary> node) override;
    virtual void visit(std::shared_ptr<ASTExprUnary> node) override;
    virtual void visit(std::shared_ptr<ASTExprSubscript> node) override;
    virtual void visit(std::shared_ptr<ASTExprFuncCall> node) override;
    virtual void visit(std::shared_ptr<ASTExprMemberAccess> node) override;
    virtual void visit(std::shared_ptr<ASTExprVar> node) override;
    virtual void visit(std::shared_ptr<ASTExprLiteral> node) override;

    TypeChecker(std::shared_ptr<SemanticIssue> _issue) {
        env = std::make_shared<Env>();
        issue = std::move(_issue);
    }
};