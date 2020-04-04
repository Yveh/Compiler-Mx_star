
// Generated from /Users/zhangyuheng/CLionProjects/Comiler-Mx_star/grammar/Mx_star.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "Mx_starParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by Mx_starParser.
 */
class  Mx_starVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by Mx_starParser.
   */
    virtual antlrcpp::Any visitProg(Mx_starParser::ProgContext *context) = 0;

    virtual antlrcpp::Any visitClassdeclaration(Mx_starParser::ClassdeclarationContext *context) = 0;

    virtual antlrcpp::Any visitFunctiondeclaration(Mx_starParser::FunctiondeclarationContext *context) = 0;

    virtual antlrcpp::Any visitParameter(Mx_starParser::ParameterContext *context) = 0;

    virtual antlrcpp::Any visitStatement(Mx_starParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitBlock(Mx_starParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitVardeclaration(Mx_starParser::VardeclarationContext *context) = 0;

    virtual antlrcpp::Any visitVardecl(Mx_starParser::VardeclContext *context) = 0;

    virtual antlrcpp::Any visitIfstatement(Mx_starParser::IfstatementContext *context) = 0;

    virtual antlrcpp::Any visitIterationstatement(Mx_starParser::IterationstatementContext *context) = 0;

    virtual antlrcpp::Any visitForinit(Mx_starParser::ForinitContext *context) = 0;

    virtual antlrcpp::Any visitForcond(Mx_starParser::ForcondContext *context) = 0;

    virtual antlrcpp::Any visitForincr(Mx_starParser::ForincrContext *context) = 0;

    virtual antlrcpp::Any visitJumpstatement(Mx_starParser::JumpstatementContext *context) = 0;

    virtual antlrcpp::Any visitExpressionstatement(Mx_starParser::ExpressionstatementContext *context) = 0;

    virtual antlrcpp::Any visitEmptystatement(Mx_starParser::EmptystatementContext *context) = 0;

    virtual antlrcpp::Any visitExpression(Mx_starParser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitLogicalorexpression(Mx_starParser::LogicalorexpressionContext *context) = 0;

    virtual antlrcpp::Any visitLogicalandexpression(Mx_starParser::LogicalandexpressionContext *context) = 0;

    virtual antlrcpp::Any visitOrexpression(Mx_starParser::OrexpressionContext *context) = 0;

    virtual antlrcpp::Any visitXorexpression(Mx_starParser::XorexpressionContext *context) = 0;

    virtual antlrcpp::Any visitAndexpression(Mx_starParser::AndexpressionContext *context) = 0;

    virtual antlrcpp::Any visitEqualityexpression(Mx_starParser::EqualityexpressionContext *context) = 0;

    virtual antlrcpp::Any visitRelationalexpression(Mx_starParser::RelationalexpressionContext *context) = 0;

    virtual antlrcpp::Any visitShiftexpression(Mx_starParser::ShiftexpressionContext *context) = 0;

    virtual antlrcpp::Any visitAdditiveexpression(Mx_starParser::AdditiveexpressionContext *context) = 0;

    virtual antlrcpp::Any visitMultiplicativeexpression(Mx_starParser::MultiplicativeexpressionContext *context) = 0;

    virtual antlrcpp::Any visitUnaryexpression(Mx_starParser::UnaryexpressionContext *context) = 0;

    virtual antlrcpp::Any visitNewexpression(Mx_starParser::NewexpressionContext *context) = 0;

    virtual antlrcpp::Any visitPostfixexpression(Mx_starParser::PostfixexpressionContext *context) = 0;

    virtual antlrcpp::Any visitFunctioncall(Mx_starParser::FunctioncallContext *context) = 0;

    virtual antlrcpp::Any visitPrimaryexpression(Mx_starParser::PrimaryexpressionContext *context) = 0;

    virtual antlrcpp::Any visitTypespecifier(Mx_starParser::TypespecifierContext *context) = 0;

    virtual antlrcpp::Any visitSimpletypespecifier(Mx_starParser::SimpletypespecifierContext *context) = 0;

    virtual antlrcpp::Any visitLiteral(Mx_starParser::LiteralContext *context) = 0;

    virtual antlrcpp::Any visitBooleanliteral(Mx_starParser::BooleanliteralContext *context) = 0;


};

