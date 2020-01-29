
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
    virtual antlrcpp::Any visitFile(Mx_starParser::FileContext *context) = 0;

    virtual antlrcpp::Any visitDeclarationlist(Mx_starParser::DeclarationlistContext *context) = 0;

    virtual antlrcpp::Any visitDeclaration(Mx_starParser::DeclarationContext *context) = 0;

    virtual antlrcpp::Any visitClassdeclaration(Mx_starParser::ClassdeclarationContext *context) = 0;

    virtual antlrcpp::Any visitMemberdeclarationlist(Mx_starParser::MemberdeclarationlistContext *context) = 0;

    virtual antlrcpp::Any visitMemberdeclaration(Mx_starParser::MemberdeclarationContext *context) = 0;

    virtual antlrcpp::Any visitFunctiondeclaration(Mx_starParser::FunctiondeclarationContext *context) = 0;

    virtual antlrcpp::Any visitParameterlist(Mx_starParser::ParameterlistContext *context) = 0;

    virtual antlrcpp::Any visitParameter(Mx_starParser::ParameterContext *context) = 0;

    virtual antlrcpp::Any visitStatement(Mx_starParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitBlock(Mx_starParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitStatementlist(Mx_starParser::StatementlistContext *context) = 0;

    virtual antlrcpp::Any visitDeclarationstatement(Mx_starParser::DeclarationstatementContext *context) = 0;

    virtual antlrcpp::Any visitInitdeclaratorlist(Mx_starParser::InitdeclaratorlistContext *context) = 0;

    virtual antlrcpp::Any visitInitdeclarator(Mx_starParser::InitdeclaratorContext *context) = 0;

    virtual antlrcpp::Any visitDeclarator(Mx_starParser::DeclaratorContext *context) = 0;

    virtual antlrcpp::Any visitInitializer(Mx_starParser::InitializerContext *context) = 0;

    virtual antlrcpp::Any visitIfstatement(Mx_starParser::IfstatementContext *context) = 0;

    virtual antlrcpp::Any visitIterationstatement(Mx_starParser::IterationstatementContext *context) = 0;

    virtual antlrcpp::Any visitJumpstatement(Mx_starParser::JumpstatementContext *context) = 0;

    virtual antlrcpp::Any visitExpressionstatement(Mx_starParser::ExpressionstatementContext *context) = 0;

    virtual antlrcpp::Any visitEmptystatement(Mx_starParser::EmptystatementContext *context) = 0;

    virtual antlrcpp::Any visitExpressionlist(Mx_starParser::ExpressionlistContext *context) = 0;

    virtual antlrcpp::Any visitExpression(Mx_starParser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitAssignmentexpression(Mx_starParser::AssignmentexpressionContext *context) = 0;

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

    virtual antlrcpp::Any visitNewinitializer(Mx_starParser::NewinitializerContext *context) = 0;

    virtual antlrcpp::Any visitNewtypespecifier(Mx_starParser::NewtypespecifierContext *context) = 0;

    virtual antlrcpp::Any visitNewdeclarator(Mx_starParser::NewdeclaratorContext *context) = 0;

    virtual antlrcpp::Any visitPointerspecifier(Mx_starParser::PointerspecifierContext *context) = 0;

    virtual antlrcpp::Any visitPostfixexpression(Mx_starParser::PostfixexpressionContext *context) = 0;

    virtual antlrcpp::Any visitPrimaryexpression(Mx_starParser::PrimaryexpressionContext *context) = 0;

    virtual antlrcpp::Any visitEqualityoperator(Mx_starParser::EqualityoperatorContext *context) = 0;

    virtual antlrcpp::Any visitRelationoperator(Mx_starParser::RelationoperatorContext *context) = 0;

    virtual antlrcpp::Any visitShiftoperator(Mx_starParser::ShiftoperatorContext *context) = 0;

    virtual antlrcpp::Any visitUnaryoperator(Mx_starParser::UnaryoperatorContext *context) = 0;

    virtual antlrcpp::Any visitTypespecifier(Mx_starParser::TypespecifierContext *context) = 0;

    virtual antlrcpp::Any visitSimpletypespecifier(Mx_starParser::SimpletypespecifierContext *context) = 0;

    virtual antlrcpp::Any visitLiteral(Mx_starParser::LiteralContext *context) = 0;

    virtual antlrcpp::Any visitBooleanliteral(Mx_starParser::BooleanliteralContext *context) = 0;


};

