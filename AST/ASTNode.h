#pragma once

#include <string>
#include <vector>
#include <memory>

#include "types.h"
#include "ASTVisitor.h"

class ASTNode {
public:
    virtual void accept(ASTVisitor *visitor) = 0;
    int pos;
};

class ASTRoot : public ASTNode {
public:
    virtual void accept(ASTVisitor *visitor) override;
    std::vector<std::shared_ptr<ASTNode>> classList, funcList, varList;
};

class ASTStmt : public ASTNode {
public:
    virtual void accept(ASTVisitor *visitor) override = 0;
};

class ASTStmtBreak : public ASTStmt {
public:
    virtual void accept(ASTVisitor *visitor) override;
};

class ASTStmtContinue : public ASTStmt {
public:
    virtual void accept(ASTVisitor *visitor) override;
};

class ASTStmtReturn : public ASTStmt {
public:
    virtual void accept(ASTVisitor *visitor) override;
    std::shared_ptr<ASTNode> retValue;
};

class ASTStmtFor : public ASTStmt {
public:
    void accept(ASTVisitor *visitor) override;
    std::shared_ptr<ASTNode> init, cond, incr, stmt;
};

class ASTStmtWhile : public ASTStmt {
public:
    virtual void accept(ASTVisitor *visitor) override;
    std::shared_ptr<ASTNode> cond, stmt;
};

class ASTStmtIf : public ASTStmt {
public:
    virtual void accept(ASTVisitor *visitor);
    std::shared_ptr<ASTNode> cond, thenStmt, elseStmt;
};

class ASTStmtExpr : public ASTStmt {
public:
    virtual void accept(ASTVisitor *visitor);
    std::shared_ptr<ASTNode> expr;
};

class ASTClassDecl : public ASTNode {
public:
    virtual void accept(ASTVisitor *visitor);
    std::string name;
    std::vector<std::shared_ptr<ASTNode>> funcList, varList;
};

class ASTBlock : public ASTNode {
public:
    virtual void accept(ASTVisitor *visitor);
    std::vector<std::shared_ptr<ASTNode>> stmts;
};

class ASTFuncDecl : public ASTBlock {
public:
    virtual void accept(ASTVisitor *visitor);
    std::string name;
    type_t retType;
    std::vector<std::shared_ptr<ASTNode>> paras;
};

class ASTVarDecl : public ASTNode {
public:
    virtual void accept(ASTVisitor *visitor);
    std::string name;
    type_t varType;
    std::shared_ptr<ASTNode> initValue;
};

class ASTExpr : public ASTNode {
public:
    virtual void accept(ASTVisitor *visitor);
    type_t exprType;
};

class ASTExprNew : public ASTExpr {
public:
    virtual void accept(ASTVisitor *visitor);
    std::vector<std::shared_ptr<ASTNode>> paras;
};

class ASTExprBinary : public ASTExpr {
public:
    virtual void accept(ASTVisitor *visitor);
    enum op_t {logic_or, logic_and, bitwise_or, bitwise_xor, bitwise_and, equal, not_equal, less, greater, lesseq, greatereq,
        leftshift, rightshift, plus, minus, mul, div, mod};
    op_t op;
    std::shared_ptr<ASTNode> operandL, operandR;
};

class ASTExprAssign : public ASTExpr {
public:
    virtual void accept(ASTVisitor *visitor);
    std::shared_ptr<ASTNode> operandL, operandR;
};

class ASTExprUnary : public ASTExpr {
public:
    virtual void accept(ASTVisitor *visitor);
    enum op_t {inc_postfix, dec_postfix, inc_prefix, dec_prefix, positive, negative, logic_not, bitwise_not, op_new};
    op_t op;
    std::shared_ptr<ASTNode> operand;
};

class ASTExprSubscript : public ASTExpr {
public:
    virtual void accept(ASTVisitor *visitor);
    std::shared_ptr<ASTNode> array, subscript;
};

class ASTExprFuncCall : public ASTExpr {
public:
    virtual void accept(ASTVisitor *visitor);
    std::shared_ptr<ASTNode> func;
    std::vector<std::shared_ptr<ASTNode>> paras;
};

class ASTExprMemberAccess : public ASTExpr {
public:
    virtual void accept(ASTVisitor *visitor);
    std::shared_ptr<ASTNode> object;
    std::string member;
};

class ASTExprVar : public ASTExpr {
public:
    virtual void accept(ASTVisitor *visitor);
    bool isThis;
    std::string name;
};

class ASTExprLiteral : public ASTExpr {
public:
    virtual void accept(ASTVisitor *visitor);
    int ivalue;
    bool bvalue;
    std::string svalue;

};