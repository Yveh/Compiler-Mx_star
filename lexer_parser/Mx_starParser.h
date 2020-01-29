
// Generated from /Users/zhangyuheng/CLionProjects/Comiler-Mx_star/grammar/Mx_star.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  Mx_starParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
    T__26 = 27, T__27 = 28, T__28 = 29, T__29 = 30, T__30 = 31, T__31 = 32, 
    Stringliteral = 33, Integerliteral = 34, Int = 35, Bool = 36, String = 37, 
    Null = 38, Void = 39, True = 40, False = 41, If = 42, Else = 43, For = 44, 
    While = 45, Break = 46, Continue = 47, Return = 48, New = 49, Class = 50, 
    This = 51, Identifier = 52, Whitespace = 53, Newline = 54, BlockComment = 55, 
    LineComment = 56
  };

  enum {
    RuleFile = 0, RuleDeclarationlist = 1, RuleDeclaration = 2, RuleClassdeclaration = 3, 
    RuleMemberdeclarationlist = 4, RuleMemberdeclaration = 5, RuleFunctiondeclaration = 6, 
    RuleParameterlist = 7, RuleParameter = 8, RuleStatement = 9, RuleBlock = 10, 
    RuleStatementlist = 11, RuleDeclarationstatement = 12, RuleInitdeclaratorlist = 13, 
    RuleInitdeclarator = 14, RuleDeclarator = 15, RuleInitializer = 16, 
    RuleIfstatement = 17, RuleIterationstatement = 18, RuleJumpstatement = 19, 
    RuleExpressionstatement = 20, RuleEmptystatement = 21, RuleExpressionlist = 22, 
    RuleExpression = 23, RuleAssignmentexpression = 24, RuleLogicalorexpression = 25, 
    RuleLogicalandexpression = 26, RuleOrexpression = 27, RuleXorexpression = 28, 
    RuleAndexpression = 29, RuleEqualityexpression = 30, RuleRelationalexpression = 31, 
    RuleShiftexpression = 32, RuleAdditiveexpression = 33, RuleMultiplicativeexpression = 34, 
    RuleUnaryexpression = 35, RuleNewexpression = 36, RuleNewinitializer = 37, 
    RuleNewtypespecifier = 38, RuleNewdeclarator = 39, RulePointerspecifier = 40, 
    RulePostfixexpression = 41, RulePrimaryexpression = 42, RuleEqualityoperator = 43, 
    RuleRelationoperator = 44, RuleShiftoperator = 45, RuleUnaryoperator = 46, 
    RuleTypespecifier = 47, RuleSimpletypespecifier = 48, RuleLiteral = 49, 
    RuleBooleanliteral = 50
  };

  Mx_starParser(antlr4::TokenStream *input);
  ~Mx_starParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class FileContext;
  class DeclarationlistContext;
  class DeclarationContext;
  class ClassdeclarationContext;
  class MemberdeclarationlistContext;
  class MemberdeclarationContext;
  class FunctiondeclarationContext;
  class ParameterlistContext;
  class ParameterContext;
  class StatementContext;
  class BlockContext;
  class StatementlistContext;
  class DeclarationstatementContext;
  class InitdeclaratorlistContext;
  class InitdeclaratorContext;
  class DeclaratorContext;
  class InitializerContext;
  class IfstatementContext;
  class IterationstatementContext;
  class JumpstatementContext;
  class ExpressionstatementContext;
  class EmptystatementContext;
  class ExpressionlistContext;
  class ExpressionContext;
  class AssignmentexpressionContext;
  class LogicalorexpressionContext;
  class LogicalandexpressionContext;
  class OrexpressionContext;
  class XorexpressionContext;
  class AndexpressionContext;
  class EqualityexpressionContext;
  class RelationalexpressionContext;
  class ShiftexpressionContext;
  class AdditiveexpressionContext;
  class MultiplicativeexpressionContext;
  class UnaryexpressionContext;
  class NewexpressionContext;
  class NewinitializerContext;
  class NewtypespecifierContext;
  class NewdeclaratorContext;
  class PointerspecifierContext;
  class PostfixexpressionContext;
  class PrimaryexpressionContext;
  class EqualityoperatorContext;
  class RelationoperatorContext;
  class ShiftoperatorContext;
  class UnaryoperatorContext;
  class TypespecifierContext;
  class SimpletypespecifierContext;
  class LiteralContext;
  class BooleanliteralContext; 

  class  FileContext : public antlr4::ParserRuleContext {
  public:
    FileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclarationlistContext *declarationlist();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FileContext* file();

  class  DeclarationlistContext : public antlr4::ParserRuleContext {
  public:
    DeclarationlistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclarationContext *declaration();
    DeclarationlistContext *declarationlist();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclarationlistContext* declarationlist();
  DeclarationlistContext* declarationlist(int precedence);
  class  DeclarationContext : public antlr4::ParserRuleContext {
  public:
    DeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ClassdeclarationContext *classdeclaration();
    FunctiondeclarationContext *functiondeclaration();
    DeclarationstatementContext *declarationstatement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclarationContext* declaration();

  class  ClassdeclarationContext : public antlr4::ParserRuleContext {
  public:
    ClassdeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Class();
    antlr4::tree::TerminalNode *Identifier();
    MemberdeclarationlistContext *memberdeclarationlist();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassdeclarationContext* classdeclaration();

  class  MemberdeclarationlistContext : public antlr4::ParserRuleContext {
  public:
    MemberdeclarationlistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MemberdeclarationContext *memberdeclaration();
    MemberdeclarationlistContext *memberdeclarationlist();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MemberdeclarationlistContext* memberdeclarationlist();
  MemberdeclarationlistContext* memberdeclarationlist(int precedence);
  class  MemberdeclarationContext : public antlr4::ParserRuleContext {
  public:
    MemberdeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclarationstatementContext *declarationstatement();
    FunctiondeclarationContext *functiondeclaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MemberdeclarationContext* memberdeclaration();

  class  FunctiondeclarationContext : public antlr4::ParserRuleContext {
  public:
    FunctiondeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    BlockContext *block();
    TypespecifierContext *typespecifier();
    ParameterlistContext *parameterlist();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctiondeclarationContext* functiondeclaration();

  class  ParameterlistContext : public antlr4::ParserRuleContext {
  public:
    ParameterlistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ParameterContext *parameter();
    ParameterlistContext *parameterlist();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParameterlistContext* parameterlist();
  ParameterlistContext* parameterlist(int precedence);
  class  ParameterContext : public antlr4::ParserRuleContext {
  public:
    ParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypespecifierContext *typespecifier();
    InitdeclaratorContext *initdeclarator();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParameterContext* parameter();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclarationstatementContext *declarationstatement();
    IfstatementContext *ifstatement();
    IterationstatementContext *iterationstatement();
    JumpstatementContext *jumpstatement();
    ExpressionstatementContext *expressionstatement();
    EmptystatementContext *emptystatement();
    BlockContext *block();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementlistContext *statementlist();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();

  class  StatementlistContext : public antlr4::ParserRuleContext {
  public:
    StatementlistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementContext *statement();
    StatementlistContext *statementlist();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementlistContext* statementlist();
  StatementlistContext* statementlist(int precedence);
  class  DeclarationstatementContext : public antlr4::ParserRuleContext {
  public:
    DeclarationstatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypespecifierContext *typespecifier();
    InitdeclaratorlistContext *initdeclaratorlist();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclarationstatementContext* declarationstatement();

  class  InitdeclaratorlistContext : public antlr4::ParserRuleContext {
  public:
    InitdeclaratorlistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    InitdeclaratorContext *initdeclarator();
    InitdeclaratorlistContext *initdeclaratorlist();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InitdeclaratorlistContext* initdeclaratorlist();
  InitdeclaratorlistContext* initdeclaratorlist(int precedence);
  class  InitdeclaratorContext : public antlr4::ParserRuleContext {
  public:
    InitdeclaratorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclaratorContext *declarator();
    InitializerContext *initializer();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InitdeclaratorContext* initdeclarator();

  class  DeclaratorContext : public antlr4::ParserRuleContext {
  public:
    DeclaratorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclaratorContext* declarator();

  class  InitializerContext : public antlr4::ParserRuleContext {
  public:
    InitializerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InitializerContext* initializer();

  class  IfstatementContext : public antlr4::ParserRuleContext {
  public:
    IfstatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *If();
    ExpressionContext *expression();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    antlr4::tree::TerminalNode *Else();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfstatementContext* ifstatement();

  class  IterationstatementContext : public antlr4::ParserRuleContext {
  public:
    IterationstatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *While();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    StatementContext *statement();
    antlr4::tree::TerminalNode *For();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IterationstatementContext* iterationstatement();

  class  JumpstatementContext : public antlr4::ParserRuleContext {
  public:
    JumpstatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Break();
    antlr4::tree::TerminalNode *Continue();
    antlr4::tree::TerminalNode *Return();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  JumpstatementContext* jumpstatement();

  class  ExpressionstatementContext : public antlr4::ParserRuleContext {
  public:
    ExpressionstatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionstatementContext* expressionstatement();

  class  EmptystatementContext : public antlr4::ParserRuleContext {
  public:
    EmptystatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EmptystatementContext* emptystatement();

  class  ExpressionlistContext : public antlr4::ParserRuleContext {
  public:
    ExpressionlistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    ExpressionlistContext *expressionlist();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionlistContext* expressionlist();
  ExpressionlistContext* expressionlist(int precedence);
  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AssignmentexpressionContext *assignmentexpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionContext* expression();

  class  AssignmentexpressionContext : public antlr4::ParserRuleContext {
  public:
    AssignmentexpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LogicalorexpressionContext *logicalorexpression();
    AssignmentexpressionContext *assignmentexpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignmentexpressionContext* assignmentexpression();

  class  LogicalorexpressionContext : public antlr4::ParserRuleContext {
  public:
    LogicalorexpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LogicalandexpressionContext *logicalandexpression();
    LogicalorexpressionContext *logicalorexpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LogicalorexpressionContext* logicalorexpression();
  LogicalorexpressionContext* logicalorexpression(int precedence);
  class  LogicalandexpressionContext : public antlr4::ParserRuleContext {
  public:
    LogicalandexpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OrexpressionContext *orexpression();
    LogicalandexpressionContext *logicalandexpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LogicalandexpressionContext* logicalandexpression();
  LogicalandexpressionContext* logicalandexpression(int precedence);
  class  OrexpressionContext : public antlr4::ParserRuleContext {
  public:
    OrexpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    XorexpressionContext *xorexpression();
    OrexpressionContext *orexpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OrexpressionContext* orexpression();
  OrexpressionContext* orexpression(int precedence);
  class  XorexpressionContext : public antlr4::ParserRuleContext {
  public:
    XorexpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AndexpressionContext *andexpression();
    XorexpressionContext *xorexpression();
    EqualityexpressionContext *equalityexpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  XorexpressionContext* xorexpression();
  XorexpressionContext* xorexpression(int precedence);
  class  AndexpressionContext : public antlr4::ParserRuleContext {
  public:
    AndexpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EqualityexpressionContext *equalityexpression();
    AndexpressionContext *andexpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AndexpressionContext* andexpression();
  AndexpressionContext* andexpression(int precedence);
  class  EqualityexpressionContext : public antlr4::ParserRuleContext {
  public:
    EqualityexpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RelationalexpressionContext *relationalexpression();
    EqualityexpressionContext *equalityexpression();
    EqualityoperatorContext *equalityoperator();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EqualityexpressionContext* equalityexpression();
  EqualityexpressionContext* equalityexpression(int precedence);
  class  RelationalexpressionContext : public antlr4::ParserRuleContext {
  public:
    RelationalexpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ShiftexpressionContext *shiftexpression();
    RelationalexpressionContext *relationalexpression();
    RelationoperatorContext *relationoperator();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RelationalexpressionContext* relationalexpression();
  RelationalexpressionContext* relationalexpression(int precedence);
  class  ShiftexpressionContext : public antlr4::ParserRuleContext {
  public:
    ShiftexpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AdditiveexpressionContext *additiveexpression();
    ShiftexpressionContext *shiftexpression();
    ShiftoperatorContext *shiftoperator();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ShiftexpressionContext* shiftexpression();
  ShiftexpressionContext* shiftexpression(int precedence);
  class  AdditiveexpressionContext : public antlr4::ParserRuleContext {
  public:
    AdditiveexpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MultiplicativeexpressionContext *multiplicativeexpression();
    AdditiveexpressionContext *additiveexpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AdditiveexpressionContext* additiveexpression();
  AdditiveexpressionContext* additiveexpression(int precedence);
  class  MultiplicativeexpressionContext : public antlr4::ParserRuleContext {
  public:
    MultiplicativeexpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnaryexpressionContext *unaryexpression();
    MultiplicativeexpressionContext *multiplicativeexpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MultiplicativeexpressionContext* multiplicativeexpression();
  MultiplicativeexpressionContext* multiplicativeexpression(int precedence);
  class  UnaryexpressionContext : public antlr4::ParserRuleContext {
  public:
    UnaryexpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PostfixexpressionContext *postfixexpression();
    UnaryexpressionContext *unaryexpression();
    UnaryoperatorContext *unaryoperator();
    NewexpressionContext *newexpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnaryexpressionContext* unaryexpression();

  class  NewexpressionContext : public antlr4::ParserRuleContext {
  public:
    NewexpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *New();
    NewtypespecifierContext *newtypespecifier();
    NewinitializerContext *newinitializer();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NewexpressionContext* newexpression();

  class  NewinitializerContext : public antlr4::ParserRuleContext {
  public:
    NewinitializerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NewinitializerContext* newinitializer();

  class  NewtypespecifierContext : public antlr4::ParserRuleContext {
  public:
    NewtypespecifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SimpletypespecifierContext *simpletypespecifier();
    NewdeclaratorContext *newdeclarator();
    PointerspecifierContext *pointerspecifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NewtypespecifierContext* newtypespecifier();

  class  NewdeclaratorContext : public antlr4::ParserRuleContext {
  public:
    NewdeclaratorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    NewdeclaratorContext *newdeclarator();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NewdeclaratorContext* newdeclarator();
  NewdeclaratorContext* newdeclarator(int precedence);
  class  PointerspecifierContext : public antlr4::ParserRuleContext {
  public:
    PointerspecifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PointerspecifierContext *pointerspecifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PointerspecifierContext* pointerspecifier();
  PointerspecifierContext* pointerspecifier(int precedence);
  class  PostfixexpressionContext : public antlr4::ParserRuleContext {
  public:
    PostfixexpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PrimaryexpressionContext *primaryexpression();
    PostfixexpressionContext *postfixexpression();
    ExpressionContext *expression();
    ExpressionlistContext *expressionlist();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PostfixexpressionContext* postfixexpression();
  PostfixexpressionContext* postfixexpression(int precedence);
  class  PrimaryexpressionContext : public antlr4::ParserRuleContext {
  public:
    PrimaryexpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LiteralContext *literal();
    antlr4::tree::TerminalNode *This();
    antlr4::tree::TerminalNode *Identifier();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrimaryexpressionContext* primaryexpression();

  class  EqualityoperatorContext : public antlr4::ParserRuleContext {
  public:
    EqualityoperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EqualityoperatorContext* equalityoperator();

  class  RelationoperatorContext : public antlr4::ParserRuleContext {
  public:
    RelationoperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RelationoperatorContext* relationoperator();

  class  ShiftoperatorContext : public antlr4::ParserRuleContext {
  public:
    ShiftoperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ShiftoperatorContext* shiftoperator();

  class  UnaryoperatorContext : public antlr4::ParserRuleContext {
  public:
    UnaryoperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnaryoperatorContext* unaryoperator();

  class  TypespecifierContext : public antlr4::ParserRuleContext {
  public:
    TypespecifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SimpletypespecifierContext *simpletypespecifier();
    TypespecifierContext *typespecifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypespecifierContext* typespecifier();
  TypespecifierContext* typespecifier(int precedence);
  class  SimpletypespecifierContext : public antlr4::ParserRuleContext {
  public:
    SimpletypespecifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Bool();
    antlr4::tree::TerminalNode *Int();
    antlr4::tree::TerminalNode *Void();
    antlr4::tree::TerminalNode *String();
    antlr4::tree::TerminalNode *Identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SimpletypespecifierContext* simpletypespecifier();

  class  LiteralContext : public antlr4::ParserRuleContext {
  public:
    LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BooleanliteralContext *booleanliteral();
    antlr4::tree::TerminalNode *Integerliteral();
    antlr4::tree::TerminalNode *Stringliteral();
    antlr4::tree::TerminalNode *Null();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LiteralContext* literal();

  class  BooleanliteralContext : public antlr4::ParserRuleContext {
  public:
    BooleanliteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *True();
    antlr4::tree::TerminalNode *False();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BooleanliteralContext* booleanliteral();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool declarationlistSempred(DeclarationlistContext *_localctx, size_t predicateIndex);
  bool memberdeclarationlistSempred(MemberdeclarationlistContext *_localctx, size_t predicateIndex);
  bool parameterlistSempred(ParameterlistContext *_localctx, size_t predicateIndex);
  bool statementlistSempred(StatementlistContext *_localctx, size_t predicateIndex);
  bool initdeclaratorlistSempred(InitdeclaratorlistContext *_localctx, size_t predicateIndex);
  bool expressionlistSempred(ExpressionlistContext *_localctx, size_t predicateIndex);
  bool logicalorexpressionSempred(LogicalorexpressionContext *_localctx, size_t predicateIndex);
  bool logicalandexpressionSempred(LogicalandexpressionContext *_localctx, size_t predicateIndex);
  bool orexpressionSempred(OrexpressionContext *_localctx, size_t predicateIndex);
  bool xorexpressionSempred(XorexpressionContext *_localctx, size_t predicateIndex);
  bool andexpressionSempred(AndexpressionContext *_localctx, size_t predicateIndex);
  bool equalityexpressionSempred(EqualityexpressionContext *_localctx, size_t predicateIndex);
  bool relationalexpressionSempred(RelationalexpressionContext *_localctx, size_t predicateIndex);
  bool shiftexpressionSempred(ShiftexpressionContext *_localctx, size_t predicateIndex);
  bool additiveexpressionSempred(AdditiveexpressionContext *_localctx, size_t predicateIndex);
  bool multiplicativeexpressionSempred(MultiplicativeexpressionContext *_localctx, size_t predicateIndex);
  bool newdeclaratorSempred(NewdeclaratorContext *_localctx, size_t predicateIndex);
  bool pointerspecifierSempred(PointerspecifierContext *_localctx, size_t predicateIndex);
  bool postfixexpressionSempred(PostfixexpressionContext *_localctx, size_t predicateIndex);
  bool typespecifierSempred(TypespecifierContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

