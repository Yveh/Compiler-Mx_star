
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

  virtual antlrcpp::Any visitProg(Mx_starParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassdeclaration(Mx_starParser::ClassdeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctiondeclaration(Mx_starParser::FunctiondeclarationContext *ctx) override {
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

  virtual antlrcpp::Any visitVardeclaration(Mx_starParser::VardeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfstatement(Mx_starParser::IfstatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIterationstatement(Mx_starParser::IterationstatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForinit(Mx_starParser::ForinitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForcond(Mx_starParser::ForcondContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForincr(Mx_starParser::ForincrContext *ctx) override {
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

  virtual antlrcpp::Any visitExpression(Mx_starParser::ExpressionContext *ctx) override {
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

  virtual antlrcpp::Any visitPostfixexpression(Mx_starParser::PostfixexpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrimaryexpression(Mx_starParser::PrimaryexpressionContext *ctx) override {
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

