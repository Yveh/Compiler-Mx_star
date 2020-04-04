
// Generated from /Users/zhangyuheng/CLionProjects/Comiler-Mx_star/grammar/Mx_star.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "Mx_starParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by Mx_starParser.
 */
class  Mx_starListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProg(Mx_starParser::ProgContext *ctx) = 0;
  virtual void exitProg(Mx_starParser::ProgContext *ctx) = 0;

  virtual void enterClassdeclaration(Mx_starParser::ClassdeclarationContext *ctx) = 0;
  virtual void exitClassdeclaration(Mx_starParser::ClassdeclarationContext *ctx) = 0;

  virtual void enterFunctiondeclaration(Mx_starParser::FunctiondeclarationContext *ctx) = 0;
  virtual void exitFunctiondeclaration(Mx_starParser::FunctiondeclarationContext *ctx) = 0;

  virtual void enterParameter(Mx_starParser::ParameterContext *ctx) = 0;
  virtual void exitParameter(Mx_starParser::ParameterContext *ctx) = 0;

  virtual void enterStatement(Mx_starParser::StatementContext *ctx) = 0;
  virtual void exitStatement(Mx_starParser::StatementContext *ctx) = 0;

  virtual void enterBlock(Mx_starParser::BlockContext *ctx) = 0;
  virtual void exitBlock(Mx_starParser::BlockContext *ctx) = 0;

  virtual void enterVardeclaration(Mx_starParser::VardeclarationContext *ctx) = 0;
  virtual void exitVardeclaration(Mx_starParser::VardeclarationContext *ctx) = 0;

  virtual void enterVardecl(Mx_starParser::VardeclContext *ctx) = 0;
  virtual void exitVardecl(Mx_starParser::VardeclContext *ctx) = 0;

  virtual void enterIfstatement(Mx_starParser::IfstatementContext *ctx) = 0;
  virtual void exitIfstatement(Mx_starParser::IfstatementContext *ctx) = 0;

  virtual void enterIterationstatement(Mx_starParser::IterationstatementContext *ctx) = 0;
  virtual void exitIterationstatement(Mx_starParser::IterationstatementContext *ctx) = 0;

  virtual void enterForinit(Mx_starParser::ForinitContext *ctx) = 0;
  virtual void exitForinit(Mx_starParser::ForinitContext *ctx) = 0;

  virtual void enterForcond(Mx_starParser::ForcondContext *ctx) = 0;
  virtual void exitForcond(Mx_starParser::ForcondContext *ctx) = 0;

  virtual void enterForincr(Mx_starParser::ForincrContext *ctx) = 0;
  virtual void exitForincr(Mx_starParser::ForincrContext *ctx) = 0;

  virtual void enterJumpstatement(Mx_starParser::JumpstatementContext *ctx) = 0;
  virtual void exitJumpstatement(Mx_starParser::JumpstatementContext *ctx) = 0;

  virtual void enterExpressionstatement(Mx_starParser::ExpressionstatementContext *ctx) = 0;
  virtual void exitExpressionstatement(Mx_starParser::ExpressionstatementContext *ctx) = 0;

  virtual void enterEmptystatement(Mx_starParser::EmptystatementContext *ctx) = 0;
  virtual void exitEmptystatement(Mx_starParser::EmptystatementContext *ctx) = 0;

  virtual void enterExpression(Mx_starParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(Mx_starParser::ExpressionContext *ctx) = 0;

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

  virtual void enterPostfixexpression(Mx_starParser::PostfixexpressionContext *ctx) = 0;
  virtual void exitPostfixexpression(Mx_starParser::PostfixexpressionContext *ctx) = 0;

  virtual void enterFunctioncall(Mx_starParser::FunctioncallContext *ctx) = 0;
  virtual void exitFunctioncall(Mx_starParser::FunctioncallContext *ctx) = 0;

  virtual void enterPrimaryexpression(Mx_starParser::PrimaryexpressionContext *ctx) = 0;
  virtual void exitPrimaryexpression(Mx_starParser::PrimaryexpressionContext *ctx) = 0;

  virtual void enterTypespecifier(Mx_starParser::TypespecifierContext *ctx) = 0;
  virtual void exitTypespecifier(Mx_starParser::TypespecifierContext *ctx) = 0;

  virtual void enterSimpletypespecifier(Mx_starParser::SimpletypespecifierContext *ctx) = 0;
  virtual void exitSimpletypespecifier(Mx_starParser::SimpletypespecifierContext *ctx) = 0;

  virtual void enterLiteral(Mx_starParser::LiteralContext *ctx) = 0;
  virtual void exitLiteral(Mx_starParser::LiteralContext *ctx) = 0;

  virtual void enterBooleanliteral(Mx_starParser::BooleanliteralContext *ctx) = 0;
  virtual void exitBooleanliteral(Mx_starParser::BooleanliteralContext *ctx) = 0;


};

