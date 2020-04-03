
// Generated from /Users/zhangyuheng/CLionProjects/Comiler-Mx_star/grammar/Mx_star.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "Mx_starListener.h"


/**
 * This class provides an empty implementation of Mx_starListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  Mx_starBaseListener : public Mx_starListener {
public:

  virtual void enterProg(Mx_starParser::ProgContext * /*ctx*/) override { }
  virtual void exitProg(Mx_starParser::ProgContext * /*ctx*/) override { }

  virtual void enterClassdeclaration(Mx_starParser::ClassdeclarationContext * /*ctx*/) override { }
  virtual void exitClassdeclaration(Mx_starParser::ClassdeclarationContext * /*ctx*/) override { }

  virtual void enterFunctiondeclaration(Mx_starParser::FunctiondeclarationContext * /*ctx*/) override { }
  virtual void exitFunctiondeclaration(Mx_starParser::FunctiondeclarationContext * /*ctx*/) override { }

  virtual void enterParameter(Mx_starParser::ParameterContext * /*ctx*/) override { }
  virtual void exitParameter(Mx_starParser::ParameterContext * /*ctx*/) override { }

  virtual void enterStatement(Mx_starParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(Mx_starParser::StatementContext * /*ctx*/) override { }

  virtual void enterBlock(Mx_starParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(Mx_starParser::BlockContext * /*ctx*/) override { }

  virtual void enterVardeclaration(Mx_starParser::VardeclarationContext * /*ctx*/) override { }
  virtual void exitVardeclaration(Mx_starParser::VardeclarationContext * /*ctx*/) override { }

  virtual void enterIfstatement(Mx_starParser::IfstatementContext * /*ctx*/) override { }
  virtual void exitIfstatement(Mx_starParser::IfstatementContext * /*ctx*/) override { }

  virtual void enterIterationstatement(Mx_starParser::IterationstatementContext * /*ctx*/) override { }
  virtual void exitIterationstatement(Mx_starParser::IterationstatementContext * /*ctx*/) override { }

  virtual void enterForinit(Mx_starParser::ForinitContext * /*ctx*/) override { }
  virtual void exitForinit(Mx_starParser::ForinitContext * /*ctx*/) override { }

  virtual void enterForcond(Mx_starParser::ForcondContext * /*ctx*/) override { }
  virtual void exitForcond(Mx_starParser::ForcondContext * /*ctx*/) override { }

  virtual void enterForincr(Mx_starParser::ForincrContext * /*ctx*/) override { }
  virtual void exitForincr(Mx_starParser::ForincrContext * /*ctx*/) override { }

  virtual void enterJumpstatement(Mx_starParser::JumpstatementContext * /*ctx*/) override { }
  virtual void exitJumpstatement(Mx_starParser::JumpstatementContext * /*ctx*/) override { }

  virtual void enterExpressionstatement(Mx_starParser::ExpressionstatementContext * /*ctx*/) override { }
  virtual void exitExpressionstatement(Mx_starParser::ExpressionstatementContext * /*ctx*/) override { }

  virtual void enterEmptystatement(Mx_starParser::EmptystatementContext * /*ctx*/) override { }
  virtual void exitEmptystatement(Mx_starParser::EmptystatementContext * /*ctx*/) override { }

  virtual void enterExpression(Mx_starParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(Mx_starParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterLogicalorexpression(Mx_starParser::LogicalorexpressionContext * /*ctx*/) override { }
  virtual void exitLogicalorexpression(Mx_starParser::LogicalorexpressionContext * /*ctx*/) override { }

  virtual void enterLogicalandexpression(Mx_starParser::LogicalandexpressionContext * /*ctx*/) override { }
  virtual void exitLogicalandexpression(Mx_starParser::LogicalandexpressionContext * /*ctx*/) override { }

  virtual void enterOrexpression(Mx_starParser::OrexpressionContext * /*ctx*/) override { }
  virtual void exitOrexpression(Mx_starParser::OrexpressionContext * /*ctx*/) override { }

  virtual void enterXorexpression(Mx_starParser::XorexpressionContext * /*ctx*/) override { }
  virtual void exitXorexpression(Mx_starParser::XorexpressionContext * /*ctx*/) override { }

  virtual void enterAndexpression(Mx_starParser::AndexpressionContext * /*ctx*/) override { }
  virtual void exitAndexpression(Mx_starParser::AndexpressionContext * /*ctx*/) override { }

  virtual void enterEqualityexpression(Mx_starParser::EqualityexpressionContext * /*ctx*/) override { }
  virtual void exitEqualityexpression(Mx_starParser::EqualityexpressionContext * /*ctx*/) override { }

  virtual void enterRelationalexpression(Mx_starParser::RelationalexpressionContext * /*ctx*/) override { }
  virtual void exitRelationalexpression(Mx_starParser::RelationalexpressionContext * /*ctx*/) override { }

  virtual void enterShiftexpression(Mx_starParser::ShiftexpressionContext * /*ctx*/) override { }
  virtual void exitShiftexpression(Mx_starParser::ShiftexpressionContext * /*ctx*/) override { }

  virtual void enterAdditiveexpression(Mx_starParser::AdditiveexpressionContext * /*ctx*/) override { }
  virtual void exitAdditiveexpression(Mx_starParser::AdditiveexpressionContext * /*ctx*/) override { }

  virtual void enterMultiplicativeexpression(Mx_starParser::MultiplicativeexpressionContext * /*ctx*/) override { }
  virtual void exitMultiplicativeexpression(Mx_starParser::MultiplicativeexpressionContext * /*ctx*/) override { }

  virtual void enterUnaryexpression(Mx_starParser::UnaryexpressionContext * /*ctx*/) override { }
  virtual void exitUnaryexpression(Mx_starParser::UnaryexpressionContext * /*ctx*/) override { }

  virtual void enterNewexpression(Mx_starParser::NewexpressionContext * /*ctx*/) override { }
  virtual void exitNewexpression(Mx_starParser::NewexpressionContext * /*ctx*/) override { }

  virtual void enterPostfixexpression(Mx_starParser::PostfixexpressionContext * /*ctx*/) override { }
  virtual void exitPostfixexpression(Mx_starParser::PostfixexpressionContext * /*ctx*/) override { }

  virtual void enterPrimaryexpression(Mx_starParser::PrimaryexpressionContext * /*ctx*/) override { }
  virtual void exitPrimaryexpression(Mx_starParser::PrimaryexpressionContext * /*ctx*/) override { }

  virtual void enterTypespecifier(Mx_starParser::TypespecifierContext * /*ctx*/) override { }
  virtual void exitTypespecifier(Mx_starParser::TypespecifierContext * /*ctx*/) override { }

  virtual void enterSimpletypespecifier(Mx_starParser::SimpletypespecifierContext * /*ctx*/) override { }
  virtual void exitSimpletypespecifier(Mx_starParser::SimpletypespecifierContext * /*ctx*/) override { }

  virtual void enterLiteral(Mx_starParser::LiteralContext * /*ctx*/) override { }
  virtual void exitLiteral(Mx_starParser::LiteralContext * /*ctx*/) override { }

  virtual void enterBooleanliteral(Mx_starParser::BooleanliteralContext * /*ctx*/) override { }
  virtual void exitBooleanliteral(Mx_starParser::BooleanliteralContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

