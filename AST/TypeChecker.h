#pragma once

#include <memory>

#include "ASTVisitor.h"
#include "ASTNode.h"
#include "Env.h"
#include "SematicIssue.h"
#include "Builtin.h"

class TypeChecker : public ASTVisitor {
public:
    std::shared_ptr<Env> env;

    void createEnv(std::shared_ptr<ASTRoot> node, SematicIssue *issue);

//    void visit(std::shared_ptr<ASTNode> node) override = 0;
//    void visit(std::shared_ptr<ASTRoot> node);
//    void visit(std::shared_ptr<ASTStmt> node);
//    void visit(std::shared_ptr<ASTStmtBreak> node);
//    void visit(std::shared_ptr<ASTStmtContinue> node);
//    void visit(std::shared_ptr<ASTStmtReturn> node);
//    void visit(std::shared_ptr<ASTStmtFor> node);
//    void visit(std::shared_ptr<ASTStmtWhile> node);
//    void visit(std::shared_ptr<ASTStmtIf> node);
//    void visit(std::shared_ptr<ASTStmtExpr> node);
//    void visit(std::shared_ptr<ASTClassDecl> node);
//    void visit(std::shared_ptr<ASTBlock> node);
//    void visit(std::shared_ptr<ASTFuncDecl> node);
//    void visit(std::shared_ptr<ASTVarDecl> node);
//    void visit(std::shared_ptr<ASTExpr> node);
//    void visit(std::shared_ptr<ASTExprNew> node);
//    void visit(std::shared_ptr<ASTExprAssign> node);
//    void visit(std::shared_ptr<ASTExprBinary> node);
//    void visit(std::shared_ptr<ASTExprUnary> node);
//    void visit(std::shared_ptr<ASTExprSubscript> node);
//    void visit(std::shared_ptr<ASTExprFuncCall> node);
//    void visit(std::shared_ptr<ASTExprMemberAccess> node);
//    void visit(std::shared_ptr<ASTExprVar> node);
//    void visit(std::shared_ptr<ASTExprLiteral> node);

    TypeChecker() {
        env = std::make_shared<Env>();
    }
};