#include "ASTVisitor.h"
#include "ASTNode.h"

void ASTVisitor::visit(std::shared_ptr<ASTNode> node) {
    node->accept(shared_from_this());
}

void ASTVisitor::visit(std::shared_ptr<ASTRoot> node) {
    node->accept(shared_from_this());
}

void ASTVisitor::visit(std::shared_ptr<ASTStmt> node) {
    node->ASTStmt::accept(shared_from_this());
}

void ASTVisitor::visit(std::shared_ptr<ASTStmtBreak> node) {
    node->accept(shared_from_this());
}

void ASTVisitor::visit(std::shared_ptr<ASTStmtContinue> node) {
    node->accept(shared_from_this());
}

void ASTVisitor::visit(std::shared_ptr<ASTStmtReturn> node) {
    node->accept(shared_from_this());
}

void ASTVisitor::visit(std::shared_ptr<ASTStmtFor> node) {
    node->accept(shared_from_this());
}

void ASTVisitor::visit(std::shared_ptr<ASTStmtWhile> node) {
    node->accept(shared_from_this());
}

void ASTVisitor::visit(std::shared_ptr<ASTStmtIf> node) {
    node->accept(shared_from_this());
}

void ASTVisitor::visit(std::shared_ptr<ASTStmtExpr> node) {
    node->accept(shared_from_this());
}

void ASTVisitor::visit(std::shared_ptr<ASTClassDecl> node) {
    node->accept(shared_from_this());
}

void ASTVisitor::visit(std::shared_ptr<ASTBlock> node) {
    node->accept(shared_from_this());
}

void ASTVisitor::visit(std::shared_ptr<ASTFuncDecl> node) {
    node->accept(shared_from_this());
}

void ASTVisitor::visit(std::shared_ptr<ASTVarDecl> node) {
    node->accept(shared_from_this());
}

void ASTVisitor::visit(std::shared_ptr<ASTExpr> node) {
    node->ASTExpr::accept(shared_from_this());
}

void ASTVisitor::visit(std::shared_ptr<ASTExprNew> node) {
    node->accept(shared_from_this());
}

void ASTVisitor::visit(std::shared_ptr<ASTExprAssign> node) {
    node->accept(shared_from_this());
}

void ASTVisitor::visit(std::shared_ptr<ASTExprBinary> node) {
    node->accept(shared_from_this());
}

void ASTVisitor::visit(std::shared_ptr<ASTExprUnary> node) {
    node->accept(shared_from_this());
}

void ASTVisitor::visit(std::shared_ptr<ASTExprSubscript> node) {
    node->accept(shared_from_this());
}

void ASTVisitor::visit(std::shared_ptr<ASTExprFuncCall> node) {
    node->accept(shared_from_this());
}

void ASTVisitor::visit(std::shared_ptr<ASTExprMemberAccess> node) {
    node->accept(shared_from_this());
}

void ASTVisitor::visit(std::shared_ptr<ASTExprVar> node) {
    node->accept(shared_from_this());
}

void ASTVisitor::visit(std::shared_ptr<ASTExprLiteral> node) {
    node->accept(shared_from_this());
}