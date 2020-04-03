#include "ASTVisitor.h"
#include "ASTNode.h"

void ASTVisitor::visit(std::shared_ptr<ASTNode> node) {
    node->accept(this);
}

void ASTVisitor::visit(std::shared_ptr<ASTRoot> node) {
    node->accept(this);
}

void ASTVisitor::visit(std::shared_ptr<ASTStmt> node) {
    node->accept(this);
}

void ASTVisitor::visit(std::shared_ptr<ASTStmtBreak> node) {
    node->accept(this);
}

void ASTVisitor::visit(std::shared_ptr<ASTStmtContinue> node) {
    node->accept(this);
}

void ASTVisitor::visit(std::shared_ptr<ASTStmtReturn> node) {
    node->accept(this);
}

void ASTVisitor::visit(std::shared_ptr<ASTStmtFor> node) {
    node->accept(this);
}

void ASTVisitor::visit(std::shared_ptr<ASTStmtWhile> node) {
    node->accept(this);
}

void ASTVisitor::visit(std::shared_ptr<ASTStmtIf> node) {
    node->accept(this);
}

void ASTVisitor::visit(std::shared_ptr<ASTStmtExpr> node) {
    node->accept(this);
}

void ASTVisitor::visit(std::shared_ptr<ASTClassDecl> node) {
    node->accept(this);
}

void ASTVisitor::visit(std::shared_ptr<ASTBlock> node) {
    node->accept(this);
}

void ASTVisitor::visit(std::shared_ptr<ASTFuncDecl> node) {
    node->accept(this);
}

void ASTVisitor::visit(std::shared_ptr<ASTVarDecl> node) {
    node->accept(this);
}

void ASTVisitor::visit(std::shared_ptr<ASTExpr> node) {
    node->accept(this);
}

void ASTVisitor::visit(std::shared_ptr<ASTExprNew> node) {
    node->accept(this);
}

void ASTVisitor::visit(std::shared_ptr<ASTExprAssign> node) {
    node->accept(this);
}

void ASTVisitor::visit(std::shared_ptr<ASTExprBinary> node) {
    node->accept(this);
}

void ASTVisitor::visit(std::shared_ptr<ASTExprUnary> node) {
    node->accept(this);
}

void ASTVisitor::visit(std::shared_ptr<ASTExprSubscript> node) {
    node->accept(this);
}

void ASTVisitor::visit(std::shared_ptr<ASTExprFuncCall> node) {
    node->accept(this);
}

void ASTVisitor::visit(std::shared_ptr<ASTExprMemberAccess> node) {
    node->accept(this);
}

void ASTVisitor::visit(std::shared_ptr<ASTExprVar> node) {
    node->accept(this);
}

void ASTVisitor::visit(std::shared_ptr<ASTExprLiteral> node) {
    node->accept(this);
}