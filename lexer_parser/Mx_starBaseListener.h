
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

  virtual void enterFile(Mx_starParser::FileContext * /*ctx*/) override { }
  virtual void exitFile(Mx_starParser::FileContext * /*ctx*/) override { }

  virtual void enterDeclarationlist(Mx_starParser::DeclarationlistContext * /*ctx*/) override { }
  virtual void exitDeclarationlist(Mx_starParser::DeclarationlistContext * /*ctx*/) override { }

  virtual void enterDeclaration(Mx_starParser::DeclarationContext * /*ctx*/) override { }
  virtual void exitDeclaration(Mx_starParser::DeclarationContext * /*ctx*/) override { }

  virtual void enterClassdeclaration(Mx_starParser::ClassdeclarationContext * /*ctx*/) override { }
  virtual void exitClassdeclaration(Mx_starParser::ClassdeclarationContext * /*ctx*/) override { }

  virtual void enterMemberdeclarationlist(Mx_starParser::MemberdeclarationlistContext * /*ctx*/) override { }
  virtual void exitMemberdeclarationlist(Mx_starParser::MemberdeclarationlistContext * /*ctx*/) override { }

  virtual void enterMemberdeclaration(Mx_starParser::MemberdeclarationContext * /*ctx*/) override { }
  virtual void exitMemberdeclaration(Mx_starParser::MemberdeclarationContext * /*ctx*/) override { }

  virtual void enterFunctiondeclaration(Mx_starParser::FunctiondeclarationContext * /*ctx*/) override { }
  virtual void exitFunctiondeclaration(Mx_starParser::FunctiondeclarationContext * /*ctx*/) override { }

  virtual void enterParameterlist(Mx_starParser::ParameterlistContext * /*ctx*/) override { }
  virtual void exitParameterlist(Mx_starParser::ParameterlistContext * /*ctx*/) override { }

  virtual void enterParameter(Mx_starParser::ParameterContext * /*ctx*/) override { }
  virtual void exitParameter(Mx_starParser::ParameterContext * /*ctx*/) override { }

  virtual void enterStatement(Mx_starParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(Mx_starParser::StatementContext * /*ctx*/) override { }

  virtual void enterBlock(Mx_starParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(Mx_starParser::BlockContext * /*ctx*/) override { }

  virtual void enterStatementlist(Mx_starParser::StatementlistContext * /*ctx*/) override { }
  virtual void exitStatementlist(Mx_starParser::StatementlistContext * /*ctx*/) override { }

  virtual void enterDeclarationstatement(Mx_starParser::DeclarationstatementContext * /*ctx*/) override { }
  virtual void exitDeclarationstatement(Mx_starParser::DeclarationstatementContext * /*ctx*/) override { }

  virtual void enterInitdeclaratorlist(Mx_starParser::InitdeclaratorlistContext * /*ctx*/) override { }
  virtual void exitInitdeclaratorlist(Mx_starParser::InitdeclaratorlistContext * /*ctx*/) override { }

  virtual void enterInitdeclarator(Mx_starParser::InitdeclaratorContext * /*ctx*/) override { }
  virtual void exitInitdeclarator(Mx_starParser::InitdeclaratorContext * /*ctx*/) override { }

  virtual void enterDeclarator(Mx_starParser::DeclaratorContext * /*ctx*/) override { }
  virtual void exitDeclarator(Mx_starParser::DeclaratorContext * /*ctx*/) override { }

  virtual void enterInitializer(Mx_starParser::InitializerContext * /*ctx*/) override { }
  virtual void exitInitializer(Mx_starParser::InitializerContext * /*ctx*/) override { }

  virtual void enterIfstatement(Mx_starParser::IfstatementContext * /*ctx*/) override { }
  virtual void exitIfstatement(Mx_starParser::IfstatementContext * /*ctx*/) override { }

  virtual void enterIterationstatement(Mx_starParser::IterationstatementContext * /*ctx*/) override { }
  virtual void exitIterationstatement(Mx_starParser::IterationstatementContext * /*ctx*/) override { }

  virtual void enterJumpstatement(Mx_starParser::JumpstatementContext * /*ctx*/) override { }
  virtual void exitJumpstatement(Mx_starParser::JumpstatementContext * /*ctx*/) override { }

  virtual void enterExpressionstatement(Mx_starParser::ExpressionstatementContext * /*ctx*/) override { }
  virtual void exitExpressionstatement(Mx_starParser::ExpressionstatementContext * /*ctx*/) override { }

  virtual void enterEmptystatement(Mx_starParser::EmptystatementContext * /*ctx*/) override { }
  virtual void exitEmptystatement(Mx_starParser::EmptystatementContext * /*ctx*/) override { }

  virtual void enterExpressionlist(Mx_starParser::ExpressionlistContext * /*ctx*/) override { }
  virtual void exitExpressionlist(Mx_starParser::ExpressionlistContext * /*ctx*/) override { }

  virtual void enterExpression(Mx_starParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(Mx_starParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterAssignmentexpression(Mx_starParser::AssignmentexpressionContext * /*ctx*/) override { }
  virtual void exitAssignmentexpression(Mx_starParser::AssignmentexpressionContext * /*ctx*/) override { }

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

  virtual void enterNewinitializer(Mx_starParser::NewinitializerContext * /*ctx*/) override { }
  virtual void exitNewinitializer(Mx_starParser::NewinitializerContext * /*ctx*/) override { }

  virtual void enterNewtypespecifier(Mx_starParser::NewtypespecifierContext * /*ctx*/) override { }
  virtual void exitNewtypespecifier(Mx_starParser::NewtypespecifierContext * /*ctx*/) override { }

  virtual void enterNewdeclarator(Mx_starParser::NewdeclaratorContext * /*ctx*/) override { }
  virtual void exitNewdeclarator(Mx_starParser::NewdeclaratorContext * /*ctx*/) override { }

  virtual void enterPointerspecifier(Mx_starParser::PointerspecifierContext * /*ctx*/) override { }
  virtual void exitPointerspecifier(Mx_starParser::PointerspecifierContext * /*ctx*/) override { }

  virtual void enterPostfixexpression(Mx_starParser::PostfixexpressionContext * /*ctx*/) override { }
  virtual void exitPostfixexpression(Mx_starParser::PostfixexpressionContext * /*ctx*/) override { }

  virtual void enterPrimaryexpression(Mx_starParser::PrimaryexpressionContext * /*ctx*/) override { }
  virtual void exitPrimaryexpression(Mx_starParser::PrimaryexpressionContext * /*ctx*/) override { }

  virtual void enterEqualityoperator(Mx_starParser::EqualityoperatorContext * /*ctx*/) override { }
  virtual void exitEqualityoperator(Mx_starParser::EqualityoperatorContext * /*ctx*/) override { }

  virtual void enterRelationoperator(Mx_starParser::RelationoperatorContext * /*ctx*/) override { }
  virtual void exitRelationoperator(Mx_starParser::RelationoperatorContext * /*ctx*/) override { }

  virtual void enterShiftoperator(Mx_starParser::ShiftoperatorContext * /*ctx*/) override { }
  virtual void exitShiftoperator(Mx_starParser::ShiftoperatorContext * /*ctx*/) override { }

  virtual void enterUnaryoperator(Mx_starParser::UnaryoperatorContext * /*ctx*/) override { }
  virtual void exitUnaryoperator(Mx_starParser::UnaryoperatorContext * /*ctx*/) override { }

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

