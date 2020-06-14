#pragma once

#include <memory>
#include <utility>
#include <stack>

#include "ASTVisitor.h"
#include "ASTNode.h"
#include "Builtin.h"
#include "IR.h"
#include "IRProgram.h"

class IRBuilder : public ASTVisitor {
public:
    std::shared_ptr<IRProgram> prog;

    std::shared_ptr<IRBlock> _block;
    IROperand _opr, _obj;
    bool _inClass;
    std::shared_ptr<IRClass> _objPointer;
    std::string _className;
    bool hasReturn, hasContinue , hasBreak;
    std::stack<std::shared_ptr<IRBlock>> continueTo, breakTo;

    IROperand::type_t RegFromMx(type_t type);
    IROperand::type_t ImmFromMx(type_t type);
    void createArray(std::shared_ptr<ASTExprNew> node, int deep);
    IROperand loadOperand(IROperand x);

    void createIR(std::shared_ptr<ASTRoot> node);

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

    IRBuilder(std::shared_ptr<IRProgram> _prog);
};