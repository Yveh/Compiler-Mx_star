
// Generated from /Users/zhangyuheng/CLionProjects/Comiler-Mx_star/grammar/Mx_star.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "Mx_starVisitor.h"


/**
 * This class provides an empty implementation of Mx_starVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  Mx_starBaseVisitor : public Mx_starVisitor {
public:

  virtual antlrcpp::Any visitFile(Mx_starParser::FileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclarationlist(Mx_starParser::DeclarationlistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclaration(Mx_starParser::DeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassdeclaration(Mx_starParser::ClassdeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMemberdeclarationlist(Mx_starParser::MemberdeclarationlistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMemberdeclaration(Mx_starParser::MemberdeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctiondeclaration(Mx_starParser::FunctiondeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameterlist(Mx_starParser::ParameterlistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameter(Mx_starParser::ParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(Mx_starParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock(Mx_starParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatementlist(Mx_starParser::StatementlistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclarationstatement(Mx_starParser::DeclarationstatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInitdeclaratorlist(Mx_starParser::InitdeclaratorlistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInitdeclarator(Mx_starParser::InitdeclaratorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclarator(Mx_starParser::DeclaratorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInitializer(Mx_starParser::InitializerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfstatement(Mx_starParser::IfstatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIterationstatement(Mx_starParser::IterationstatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitJumpstatement(Mx_starParser::JumpstatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpressionstatement(Mx_starParser::ExpressionstatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEmptystatement(Mx_starParser::EmptystatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpressionlist(Mx_starParser::ExpressionlistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression(Mx_starParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignmentexpression(Mx_starParser::AssignmentexpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogicalorexpression(Mx_starParser::LogicalorexpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogicalandexpression(Mx_starParser::LogicalandexpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOrexpression(Mx_starParser::OrexpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitXorexpression(Mx_starParser::XorexpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAndexpression(Mx_starParser::AndexpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEqualityexpression(Mx_starParser::EqualityexpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelationalexpression(Mx_starParser::RelationalexpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShiftexpression(Mx_starParser::ShiftexpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAdditiveexpression(Mx_starParser::AdditiveexpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMultiplicativeexpression(Mx_starParser::MultiplicativeexpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryexpression(Mx_starParser::UnaryexpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNewexpression(Mx_starParser::NewexpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNewinitializer(Mx_starParser::NewinitializerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNewtypespecifier(Mx_starParser::NewtypespecifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNewdeclarator(Mx_starParser::NewdeclaratorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPointerspecifier(Mx_starParser::PointerspecifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPostfixexpression(Mx_starParser::PostfixexpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrimaryexpression(Mx_starParser::PrimaryexpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEqualityoperator(Mx_starParser::EqualityoperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelationoperator(Mx_starParser::RelationoperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShiftoperator(Mx_starParser::ShiftoperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryoperator(Mx_starParser::UnaryoperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypespecifier(Mx_starParser::TypespecifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimpletypespecifier(Mx_starParser::SimpletypespecifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteral(Mx_starParser::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBooleanliteral(Mx_starParser::BooleanliteralContext *ctx) override {
    return visitChildren(ctx);
  }


};

