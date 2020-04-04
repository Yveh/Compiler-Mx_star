#pragma once

#include <memory>

#include "Mx_starBaseVisitor.h"
#include "ASTNode.h"
#include "Types.h"

class ASTBuilder : public Mx_starBaseVisitor {
private:
    std::shared_ptr<ASTNode> _node;
    type_t _type;

    virtual antlrcpp::Any visitProg(Mx_starParser::ProgContext *ctx) override;
    virtual antlrcpp::Any visitClassdeclaration(Mx_starParser::ClassdeclarationContext *ctx) override;
    virtual antlrcpp::Any visitFunctiondeclaration(Mx_starParser::FunctiondeclarationContext *ctx) override;
    virtual antlrcpp::Any visitParameter(Mx_starParser::ParameterContext *ctx) override;
    virtual antlrcpp::Any visitStatement(Mx_starParser::StatementContext *ctx) override;
    virtual antlrcpp::Any visitBlock(Mx_starParser::BlockContext *ctx) override;
    virtual antlrcpp::Any visitVardeclaration(Mx_starParser::VardeclarationContext *ctx) override;
    virtual antlrcpp::Any visitIfstatement(Mx_starParser::IfstatementContext *ctx) override;
    virtual antlrcpp::Any visitIterationstatement(Mx_starParser::IterationstatementContext *ctx) override;
    virtual antlrcpp::Any visitForinit(Mx_starParser::ForinitContext *ctx) override;
    virtual antlrcpp::Any visitForcond(Mx_starParser::ForcondContext *ctx) override;
    virtual antlrcpp::Any visitForincr(Mx_starParser::ForincrContext *ctx) override;
    virtual antlrcpp::Any visitJumpstatement(Mx_starParser::JumpstatementContext *ctx) override;
    virtual antlrcpp::Any visitExpressionstatement(Mx_starParser::ExpressionstatementContext *ctx) override;
    virtual antlrcpp::Any visitEmptystatement(Mx_starParser::EmptystatementContext *ctx) override;
    virtual antlrcpp::Any visitExpression(Mx_starParser::ExpressionContext *ctx) override;
    virtual antlrcpp::Any visitLogicalorexpression(Mx_starParser::LogicalorexpressionContext *ctx) override;
    virtual antlrcpp::Any visitLogicalandexpression(Mx_starParser::LogicalandexpressionContext *ctx) override;
    virtual antlrcpp::Any visitOrexpression(Mx_starParser::OrexpressionContext *ctx) override;
    virtual antlrcpp::Any visitXorexpression(Mx_starParser::XorexpressionContext *ctx) override;
    virtual antlrcpp::Any visitAndexpression(Mx_starParser::AndexpressionContext *ctx) override;
    virtual antlrcpp::Any visitEqualityexpression(Mx_starParser::EqualityexpressionContext *ctx) override;
    virtual antlrcpp::Any visitRelationalexpression(Mx_starParser::RelationalexpressionContext *ctx) override;
    virtual antlrcpp::Any visitShiftexpression(Mx_starParser::ShiftexpressionContext *ctx) override;
    virtual antlrcpp::Any visitAdditiveexpression(Mx_starParser::AdditiveexpressionContext *ctx) override;
    virtual antlrcpp::Any visitMultiplicativeexpression(Mx_starParser::MultiplicativeexpressionContext *ctx) override;
    virtual antlrcpp::Any visitUnaryexpression(Mx_starParser::UnaryexpressionContext *ctx) override;
    virtual antlrcpp::Any visitNewexpression(Mx_starParser::NewexpressionContext *ctx) override;
    virtual antlrcpp::Any visitPostfixexpression(Mx_starParser::PostfixexpressionContext *ctx) override;
    virtual antlrcpp::Any visitPrimaryexpression(Mx_starParser::PrimaryexpressionContext *ctx) override;
    virtual antlrcpp::Any visitTypespecifier(Mx_starParser::TypespecifierContext *ctx) override;
    virtual antlrcpp::Any visitSimpletypespecifier(Mx_starParser::SimpletypespecifierContext *ctx) override;
    virtual antlrcpp::Any visitLiteral(Mx_starParser::LiteralContext *ctx) override;
    virtual antlrcpp::Any visitBooleanliteral(Mx_starParser::BooleanliteralContext *ctx) override;
public:
    std::shared_ptr<ASTRoot> build(antlr4::tree::ParseTree* tree);
};
