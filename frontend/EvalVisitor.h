#pragma once

#include "Mx_starBaseVisitor.h"

class EvalVisitor : public Mx_starBaseVisitor {public:

    antlrcpp::Any visitFile(Mx_starParser::FileContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitDeclarationlist(Mx_starParser::DeclarationlistContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitDeclaration(Mx_starParser::DeclarationContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitClassdeclaration(Mx_starParser::ClassdeclarationContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitMemberdeclarationlist(Mx_starParser::MemberdeclarationlistContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitMemberdeclaration(Mx_starParser::MemberdeclarationContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitFunctiondeclaration(Mx_starParser::FunctiondeclarationContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitParameterlist(Mx_starParser::ParameterlistContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitParameter(Mx_starParser::ParameterContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitStatement(Mx_starParser::StatementContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitBlock(Mx_starParser::BlockContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitStatementlist(Mx_starParser::StatementlistContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitDeclarationstatement(Mx_starParser::DeclarationstatementContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitInitdeclaratorlist(Mx_starParser::InitdeclaratorlistContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitInitdeclarator(Mx_starParser::InitdeclaratorContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitDeclarator(Mx_starParser::DeclaratorContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitInitializer(Mx_starParser::InitializerContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitIfstatement(Mx_starParser::IfstatementContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitIterationstatement(Mx_starParser::IterationstatementContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitJumpstatement(Mx_starParser::JumpstatementContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitExpressionstatement(Mx_starParser::ExpressionstatementContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitEmptystatement(Mx_starParser::EmptystatementContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitExpressionlist(Mx_starParser::ExpressionlistContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitExpression(Mx_starParser::ExpressionContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitAssignmentexpression(Mx_starParser::AssignmentexpressionContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitLogicalorexpression(Mx_starParser::LogicalorexpressionContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitLogicalandexpression(Mx_starParser::LogicalandexpressionContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitOrexpression(Mx_starParser::OrexpressionContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitXorexpression(Mx_starParser::XorexpressionContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitAndexpression(Mx_starParser::AndexpressionContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitEqualityexpression(Mx_starParser::EqualityexpressionContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitRelationalexpression(Mx_starParser::RelationalexpressionContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitShiftexpression(Mx_starParser::ShiftexpressionContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitAdditiveexpression(Mx_starParser::AdditiveexpressionContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitMultiplicativeexpression(Mx_starParser::MultiplicativeexpressionContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitUnaryexpression(Mx_starParser::UnaryexpressionContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitNewexpression(Mx_starParser::NewexpressionContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitNewinitializer(Mx_starParser::NewinitializerContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitNewtypespecifier(Mx_starParser::NewtypespecifierContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitNewdeclarator(Mx_starParser::NewdeclaratorContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitPointerspecifier(Mx_starParser::PointerspecifierContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitPostfixexpression(Mx_starParser::PostfixexpressionContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitPrimaryexpression(Mx_starParser::PrimaryexpressionContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitEqualityoperator(Mx_starParser::EqualityoperatorContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitRelationoperator(Mx_starParser::RelationoperatorContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitShiftoperator(Mx_starParser::ShiftoperatorContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitUnaryoperator(Mx_starParser::UnaryoperatorContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitTypespecifier(Mx_starParser::TypespecifierContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitSimpletypespecifier(Mx_starParser::SimpletypespecifierContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitLiteral(Mx_starParser::LiteralContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitBooleanliteral(Mx_starParser::BooleanliteralContext *ctx) override {
        return visitChildren(ctx);
    }

};