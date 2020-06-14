#pragma once

#include <string>
#include <vector>
#include <memory>

#include "Types.h"
#include "ASTVisitor.h"

class ASTNode {
public:
    virtual void accept(std::shared_ptr<ASTVisitor> visitor) = 0;
    int pos;
};

class ASTRoot : public ASTNode {
public:
    virtual void accept(std::shared_ptr<ASTVisitor> visitor) override;
    std::vector<std::shared_ptr<ASTNode>> classList, funcList, varList, children;
};

class ASTStmt : public ASTNode , public std::enable_shared_from_this<ASTStmt> {
public:
    virtual void accept(std::shared_ptr<ASTVisitor> visitor) override;
};

class ASTStmtBreak : public ASTStmt {
public:
    virtual void accept(std::shared_ptr<ASTVisitor> visitor) override;
};

class ASTStmtContinue : public ASTStmt {
public:
    virtual void accept(std::shared_ptr<ASTVisitor> visitor) override;
};

class ASTStmtReturn : public ASTStmt {
public:
    virtual void accept(std::shared_ptr<ASTVisitor> visitor) override;
    std::shared_ptr<ASTNode> retValue;
    type_t retType;
};

class ASTStmtFor : public ASTStmt {
public:
    virtual void accept(std::shared_ptr<ASTVisitor> visitor) override;
    std::shared_ptr<ASTNode> init, cond, incr, stmt;
};

class ASTStmtWhile : public ASTStmt {
public:
    virtual void accept(std::shared_ptr<ASTVisitor> visitor) override;
    std::shared_ptr<ASTNode> cond, stmt;
};

class ASTStmtIf : public ASTStmt {
public:
    virtual void accept(std::shared_ptr<ASTVisitor> visitor) override;
    std::shared_ptr<ASTNode> cond, thenStmt, elseStmt;
};

class ASTStmtExpr : public ASTStmt {
public:
    virtual void accept(std::shared_ptr<ASTVisitor> visitor) override;
    std::shared_ptr<ASTNode> expr;
};

class ASTClassDecl : public ASTNode {
public:
    virtual void accept(std::shared_ptr<ASTVisitor> visitor) override;
    std::string name;
    std::vector<std::shared_ptr<ASTNode>> funcList, varList;
};

class ASTBlock : public ASTStmt {
public:
    virtual void accept(std::shared_ptr<ASTVisitor> visitor) override;
    std::vector<std::shared_ptr<ASTNode>> stmts;
};

class ASTFuncDecl : public ASTBlock {
public:
    virtual void accept(std::shared_ptr<ASTVisitor> visitor) override;
    std::string name;
    type_t retType;
    std::vector<std::shared_ptr<ASTNode>> paras;
};

class ASTVarDecl : public ASTStmt {
public:
    virtual void accept(std::shared_ptr<ASTVisitor> visitor) override;
    std::vector<std::string> name;
    std::vector<int> id;
    type_t varType;
    std::vector<std::shared_ptr<ASTNode>> initValue;
};

class ASTExpr : public ASTNode , public std::enable_shared_from_this<ASTExpr> {
public:
    virtual void accept(std::shared_ptr<ASTVisitor> visitor) override;
    type_t exprType;
    value_t valueType;
};

class ASTExprNew : public ASTExpr {
public:
    virtual void accept(std::shared_ptr<ASTVisitor> visitor) override;
    std::vector<std::shared_ptr<ASTNode>> paras;
};

class ASTExprBinary : public ASTExpr {
public:
    virtual void accept(std::shared_ptr<ASTVisitor> visitor) override;
    enum op_t {logic_or, logic_and, bitwise_or, bitwise_xor, bitwise_and, equal, not_equal, less, greater, lesseq, greatereq,
        leftshift, rightshift, plus, minus, mul, div, mod};
    op_t op;
    std::shared_ptr<ASTNode> operandL, operandR;
};

class ASTExprAssign : public ASTExpr {
public:
    virtual void accept(std::shared_ptr<ASTVisitor> visitor) override;
    std::shared_ptr<ASTNode> operandL, operandR;
};

class ASTExprUnary : public ASTExpr {
public:
    virtual void accept(std::shared_ptr<ASTVisitor> visitor) override;
    enum op_t {inc_postfix, dec_postfix, inc_prefix, dec_prefix, positive, negative, logic_not, bitwise_not};
    op_t op;
    std::shared_ptr<ASTNode> operand;
};

class ASTExprSubscript : public ASTExpr {
public:
    virtual void accept(std::shared_ptr<ASTVisitor> visitor) override;
    std::shared_ptr<ASTNode> array, subscript;
};

class ASTExprFuncCall : public ASTExpr {
public:
    virtual void accept(std::shared_ptr<ASTVisitor> visitor) override;
    std::string name;
    std::vector<std::shared_ptr<ASTNode>> paras;
};

class ASTExprMemberAccess : public ASTExpr {
public:
    virtual void accept(std::shared_ptr<ASTVisitor> visitor) override;
    std::shared_ptr<ASTNode> object, memberFunc;
    std::string memberVar;
    int id;
};

class ASTExprVar : public ASTExpr {
public:
    virtual void accept(std::shared_ptr<ASTVisitor> visitor) override;
    bool isThis;
    std::string name;
    int id;
};

class ASTExprLiteral : public ASTExpr {
public:
    virtual void accept(std::shared_ptr<ASTVisitor> visitor) override;
    int ivalue;
    bool bvalue;
    std::string svalue;
};