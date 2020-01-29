
// Generated from /Users/zhangyuheng/CLionProjects/Comiler-Mx_star/grammar/Mx_star.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "Mx_starParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by Mx_starParser.
 */
class  Mx_starListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterFile(Mx_starParser::FileContext *ctx) = 0;
  virtual void exitFile(Mx_starParser::FileContext *ctx) = 0;

  virtual void enterDeclarationlist(Mx_starParser::DeclarationlistContext *ctx) = 0;
  virtual void exitDeclarationlist(Mx_starParser::DeclarationlistContext *ctx) = 0;

  virtual void enterDeclaration(Mx_starParser::DeclarationContext *ctx) = 0;
  virtual void exitDeclaration(Mx_starParser::DeclarationContext *ctx) = 0;

  virtual void enterClassdeclaration(Mx_starParser::ClassdeclarationContext *ctx) = 0;
  virtual void exitClassdeclaration(Mx_starParser::ClassdeclarationContext *ctx) = 0;

  virtual void enterMemberdeclarationlist(Mx_starParser::MemberdeclarationlistContext *ctx) = 0;
  virtual void exitMemberdeclarationlist(Mx_starParser::MemberdeclarationlistContext *ctx) = 0;

  virtual void enterMemberdeclaration(Mx_starParser::MemberdeclarationContext *ctx) = 0;
  virtual void exitMemberdeclaration(Mx_starParser::MemberdeclarationContext *ctx) = 0;

  virtual void enterFunctiondeclaration(Mx_starParser::FunctiondeclarationContext *ctx) = 0;
  virtual void exitFunctiondeclaration(Mx_starParser::FunctiondeclarationContext *ctx) = 0;

  virtual void enterParameterlist(Mx_starParser::ParameterlistContext *ctx) = 0;
  virtual void exitParameterlist(Mx_starParser::ParameterlistContext *ctx) = 0;

  virtual void enterParameter(Mx_starParser::ParameterContext *ctx) = 0;
  virtual void exitParameter(Mx_starParser::ParameterContext *ctx) = 0;

  virtual void enterStatement(Mx_starParser::StatementContext *ctx) = 0;
  virtual void exitStatement(Mx_starParser::StatementContext *ctx) = 0;

  virtual void enterBlock(Mx_starParser::BlockContext *ctx) = 0;
  virtual void exitBlock(Mx_starParser::BlockContext *ctx) = 0;

  virtual void enterStatementlist(Mx_starParser::StatementlistContext *ctx) = 0;
  virtual void exitStatementlist(Mx_starParser::StatementlistContext *ctx) = 0;

  virtual void enterDeclarationstatement(Mx_starParser::DeclarationstatementContext *ctx) = 0;
  virtual void exitDeclarationstatement(Mx_starParser::DeclarationstatementContext *ctx) = 0;

  virtual void enterInitdeclaratorlist(Mx_starParser::InitdeclaratorlistContext *ctx) = 0;
  virtual void exitInitdeclaratorlist(Mx_starParser::InitdeclaratorlistContext *ctx) = 0;

  virtual void enterInitdeclarator(Mx_starParser::InitdeclaratorContext *ctx) = 0;
  virtual void exitInitdeclarator(Mx_starParser::InitdeclaratorContext *ctx) = 0;

  virtual void enterDeclarator(Mx_starParser::DeclaratorContext *ctx) = 0;
  virtual void exitDeclarator(Mx_starParser::DeclaratorContext *ctx) = 0;

  virtual void enterInitializer(Mx_starParser::InitializerContext *ctx) = 0;
  virtual void exitInitializer(Mx_starParser::InitializerContext *ctx) = 0;

  virtual void enterIfstatement(Mx_starParser::IfstatementContext *ctx) = 0;
  virtual void exitIfstatement(Mx_starParser::IfstatementContext *ctx) = 0;

  virtual void enterIterationstatement(Mx_starParser::IterationstatementContext *ctx) = 0;
  virtual void exitIterationstatement(Mx_starParser::IterationstatementContext *ctx) = 0;

  virtual void enterJumpstatement(Mx_starParser::JumpstatementContext *ctx) = 0;
  virtual void exitJumpstatement(Mx_starParser::JumpstatementContext *ctx) = 0;

  virtual void enterExpressionstatement(Mx_starParser::ExpressionstatementContext *ctx) = 0;
  virtual void exitExpressionstatement(Mx_starParser::ExpressionstatementContext *ctx) = 0;

  virtual void enterEmptystatement(Mx_starParser::EmptystatementContext *ctx) = 0;
  virtual void exitEmptystatement(Mx_starParser::EmptystatementContext *ctx) = 0;

  virtual void enterExpressionlist(Mx_starParser::ExpressionlistContext *ctx) = 0;
  virtual void exitExpressionlist(Mx_starParser::ExpressionlistContext *ctx) = 0;

  virtual void enterExpression(Mx_starParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(Mx_starParser::ExpressionContext *ctx) = 0;

  virtual void enterAssignmentexpression(Mx_starParser::AssignmentexpressionContext *ctx) = 0;
  virtual void exitAssignmentexpression(Mx_starParser::AssignmentexpressionContext *ctx) = 0;

  virtual void enterLogicalorexpression(Mx_starParser::LogicalorexpressionContext *ctx) = 0;
  virtual void exitLogicalorexpression(Mx_starParser::LogicalorexpressionContext *ctx) = 0;

  virtual void enterLogicalandexpression(Mx_starParser::LogicalandexpressionContext *ctx) = 0;
  virtual void exitLogicalandexpression(Mx_starParser::LogicalandexpressionContext *ctx) = 0;

  virtual void enterOrexpression(Mx_starParser::OrexpressionContext *ctx) = 0;
  virtual void exitOrexpression(Mx_starParser::OrexpressionContext *ctx) = 0;

  virtual void enterXorexpression(Mx_starParser::XorexpressionContext *ctx) = 0;
  virtual void exitXorexpression(Mx_starParser::XorexpressionContext *ctx) = 0;

  virtual void enterAndexpression(Mx_starParser::AndexpressionContext *ctx) = 0;
  virtual void exitAndexpression(Mx_starParser::AndexpressionContext *ctx) = 0;

  virtual void enterEqualityexpression(Mx_starParser::EqualityexpressionContext *ctx) = 0;
  virtual void exitEqualityexpression(Mx_starParser::EqualityexpressionContext *ctx) = 0;

  virtual void enterRelationalexpression(Mx_starParser::RelationalexpressionContext *ctx) = 0;
  virtual void exitRelationalexpression(Mx_starParser::RelationalexpressionContext *ctx) = 0;

  virtual void enterShiftexpression(Mx_starParser::ShiftexpressionContext *ctx) = 0;
  virtual void exitShiftexpression(Mx_starParser::ShiftexpressionContext *ctx) = 0;

  virtual void enterAdditiveexpression(Mx_starParser::AdditiveexpressionContext *ctx) = 0;
  virtual void exitAdditiveexpression(Mx_starParser::AdditiveexpressionContext *ctx) = 0;

  virtual void enterMultiplicativeexpression(Mx_starParser::MultiplicativeexpressionContext *ctx) = 0;
  virtual void exitMultiplicativeexpression(Mx_starParser::MultiplicativeexpressionContext *ctx) = 0;

  virtual void enterUnaryexpression(Mx_starParser::UnaryexpressionContext *ctx) = 0;
  virtual void exitUnaryexpression(Mx_starParser::UnaryexpressionContext *ctx) = 0;

  virtual void enterNewexpression(Mx_starParser::NewexpressionContext *ctx) = 0;
  virtual void exitNewexpression(Mx_starParser::NewexpressionContext *ctx) = 0;

  virtual void enterNewinitializer(Mx_starParser::NewinitializerContext *ctx) = 0;
  virtual void exitNewinitializer(Mx_starParser::NewinitializerContext *ctx) = 0;

  virtual void enterNewtypespecifier(Mx_starParser::NewtypespecifierContext *ctx) = 0;
  virtual void exitNewtypespecifier(Mx_starParser::NewtypespecifierContext *ctx) = 0;

  virtual void enterNewdeclarator(Mx_starParser::NewdeclaratorContext *ctx) = 0;
  virtual void exitNewdeclarator(Mx_starParser::NewdeclaratorContext *ctx) = 0;

  virtual void enterPointerspecifier(Mx_starParser::PointerspecifierContext *ctx) = 0;
  virtual void exitPointerspecifier(Mx_starParser::PointerspecifierContext *ctx) = 0;

  virtual void enterPostfixexpression(Mx_starParser::PostfixexpressionContext *ctx) = 0;
  virtual void exitPostfixexpression(Mx_starParser::PostfixexpressionContext *ctx) = 0;

  virtual void enterPrimaryexpression(Mx_starParser::PrimaryexpressionContext *ctx) = 0;
  virtual void exitPrimaryexpression(Mx_starParser::PrimaryexpressionContext *ctx) = 0;

  virtual void enterEqualityoperator(Mx_starParser::EqualityoperatorContext *ctx) = 0;
  virtual void exitEqualityoperator(Mx_starParser::EqualityoperatorContext *ctx) = 0;

  virtual void enterRelationoperator(Mx_starParser::RelationoperatorContext *ctx) = 0;
  virtual void exitRelationoperator(Mx_starParser::RelationoperatorContext *ctx) = 0;

  virtual void enterShiftoperator(Mx_starParser::ShiftoperatorContext *ctx) = 0;
  virtual void exitShiftoperator(Mx_starParser::ShiftoperatorContext *ctx) = 0;

  virtual void enterUnaryoperator(Mx_starParser::UnaryoperatorContext *ctx) = 0;
  virtual void exitUnaryoperator(Mx_starParser::UnaryoperatorContext *ctx) = 0;

  virtual void enterTypespecifier(Mx_starParser::TypespecifierContext *ctx) = 0;
  virtual void exitTypespecifier(Mx_starParser::TypespecifierContext *ctx) = 0;

  virtual void enterSimpletypespecifier(Mx_starParser::SimpletypespecifierContext *ctx) = 0;
  virtual void exitSimpletypespecifier(Mx_starParser::SimpletypespecifierContext *ctx) = 0;

  virtual void enterLiteral(Mx_starParser::LiteralContext *ctx) = 0;
  virtual void exitLiteral(Mx_starParser::LiteralContext *ctx) = 0;

  virtual void enterBooleanliteral(Mx_starParser::BooleanliteralContext *ctx) = 0;
  virtual void exitBooleanliteral(Mx_starParser::BooleanliteralContext *ctx) = 0;


};

