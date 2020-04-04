#include "ASTVisitor.h"
#include "ASTNode.h"

void ASTVisitor::visit(ASTNode* node) {
    node->accept(this);
}

void ASTVisitor::visit(ASTRoot* node) {
    node->accept(this);
}

void ASTVisitor::visit(ASTStmt* node) {
    node->ASTStmt::accept(this);
}

void ASTVisitor::visit(ASTStmtBreak* node) {
    node->accept(this);
}

void ASTVisitor::visit(ASTStmtContinue* node) {
    node->accept(this);
}

void ASTVisitor::visit(ASTStmtReturn* node) {
    node->accept(this);
}

void ASTVisitor::visit(ASTStmtFor* node) {
    node->accept(this);
}

void ASTVisitor::visit(ASTStmtWhile* node) {
    node->accept(this);
}

void ASTVisitor::visit(ASTStmtIf* node) {
    node->accept(this);
}

void ASTVisitor::visit(ASTStmtExpr* node) {
    node->accept(this);
}

void ASTVisitor::visit(ASTClassDecl* node) {
    node->accept(this);
}

void ASTVisitor::visit(ASTBlock* node) {
    node->accept(this);
}

void ASTVisitor::visit(ASTFuncDecl* node) {
    node->accept(this);
}

void ASTVisitor::visit(ASTVarDecl* node) {
    node->accept(this);
}

void ASTVisitor::visit(ASTExpr* node) {
    node->ASTExpr::accept(this);
}

void ASTVisitor::visit(ASTExprNew* node) {
    node->accept(this);
}

void ASTVisitor::visit(ASTExprAssign* node) {
    node->accept(this);
}

void ASTVisitor::visit(ASTExprBinary* node) {
    node->accept(this);
}

void ASTVisitor::visit(ASTExprUnary* node) {
    node->accept(this);
}

void ASTVisitor::visit(ASTExprSubscript* node) {
    node->accept(this);
}

void ASTVisitor::visit(ASTExprFuncCall* node) {
    node->accept(this);
}

void ASTVisitor::visit(ASTExprMemberAccess* node) {
    node->accept(this);
}

void ASTVisitor::visit(ASTExprVar* node) {
    node->accept(this);
}

void ASTVisitor::visit(ASTExprLiteral* node) {
    node->accept(this);
}