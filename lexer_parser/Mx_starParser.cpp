
// Generated from /Users/zhangyuheng/CLionProjects/Comiler-Mx_star/grammar/Mx_star.g4 by ANTLR 4.8


#include "Mx_starListener.h"
#include "Mx_starVisitor.h"

#include "Mx_starParser.h"


using namespace antlrcpp;
using namespace antlr4;

Mx_starParser::Mx_starParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

Mx_starParser::~Mx_starParser() {
  delete _interpreter;
}

std::string Mx_starParser::getGrammarFileName() const {
  return "Mx_star.g4";
}

const std::vector<std::string>& Mx_starParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& Mx_starParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- FileContext ------------------------------------------------------------------

Mx_starParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Mx_starParser::DeclarationlistContext* Mx_starParser::FileContext::declarationlist() {
  return getRuleContext<Mx_starParser::DeclarationlistContext>(0);
}


size_t Mx_starParser::FileContext::getRuleIndex() const {
  return Mx_starParser::RuleFile;
}

void Mx_starParser::FileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFile(this);
}

void Mx_starParser::FileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFile(this);
}


antlrcpp::Any Mx_starParser::FileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitFile(this);
  else
    return visitor->visitChildren(this);
}

Mx_starParser::FileContext* Mx_starParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 0, Mx_starParser::RuleFile);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(102);
    declarationlist(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationlistContext ------------------------------------------------------------------

Mx_starParser::DeclarationlistContext::DeclarationlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Mx_starParser::DeclarationContext* Mx_starParser::DeclarationlistContext::declaration() {
  return getRuleContext<Mx_starParser::DeclarationContext>(0);
}

Mx_starParser::DeclarationlistContext* Mx_starParser::DeclarationlistContext::declarationlist() {
  return getRuleContext<Mx_starParser::DeclarationlistContext>(0);
}


size_t Mx_starParser::DeclarationlistContext::getRuleIndex() const {
  return Mx_starParser::RuleDeclarationlist;
}

void Mx_starParser::DeclarationlistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarationlist(this);
}

void Mx_starParser::DeclarationlistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarationlist(this);
}


antlrcpp::Any Mx_starParser::DeclarationlistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitDeclarationlist(this);
  else
    return visitor->visitChildren(this);
}


Mx_starParser::DeclarationlistContext* Mx_starParser::declarationlist() {
   return declarationlist(0);
}

Mx_starParser::DeclarationlistContext* Mx_starParser::declarationlist(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Mx_starParser::DeclarationlistContext *_localctx = _tracker.createInstance<DeclarationlistContext>(_ctx, parentState);
  Mx_starParser::DeclarationlistContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, Mx_starParser::RuleDeclarationlist, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(105);
    declaration();
    _ctx->stop = _input->LT(-1);
    setState(111);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<DeclarationlistContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleDeclarationlist);
        setState(107);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(108);
        declaration(); 
      }
      setState(113);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

Mx_starParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Mx_starParser::ClassdeclarationContext* Mx_starParser::DeclarationContext::classdeclaration() {
  return getRuleContext<Mx_starParser::ClassdeclarationContext>(0);
}

Mx_starParser::FunctiondeclarationContext* Mx_starParser::DeclarationContext::functiondeclaration() {
  return getRuleContext<Mx_starParser::FunctiondeclarationContext>(0);
}

Mx_starParser::DeclarationstatementContext* Mx_starParser::DeclarationContext::declarationstatement() {
  return getRuleContext<Mx_starParser::DeclarationstatementContext>(0);
}


size_t Mx_starParser::DeclarationContext::getRuleIndex() const {
  return Mx_starParser::RuleDeclaration;
}

void Mx_starParser::DeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration(this);
}

void Mx_starParser::DeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration(this);
}


antlrcpp::Any Mx_starParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

Mx_starParser::DeclarationContext* Mx_starParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 4, Mx_starParser::RuleDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(117);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(114);
      classdeclaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(115);
      functiondeclaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(116);
      declarationstatement();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassdeclarationContext ------------------------------------------------------------------

Mx_starParser::ClassdeclarationContext::ClassdeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Mx_starParser::ClassdeclarationContext::Class() {
  return getToken(Mx_starParser::Class, 0);
}

tree::TerminalNode* Mx_starParser::ClassdeclarationContext::Identifier() {
  return getToken(Mx_starParser::Identifier, 0);
}

Mx_starParser::MemberdeclarationlistContext* Mx_starParser::ClassdeclarationContext::memberdeclarationlist() {
  return getRuleContext<Mx_starParser::MemberdeclarationlistContext>(0);
}


size_t Mx_starParser::ClassdeclarationContext::getRuleIndex() const {
  return Mx_starParser::RuleClassdeclaration;
}

void Mx_starParser::ClassdeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassdeclaration(this);
}

void Mx_starParser::ClassdeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassdeclaration(this);
}


antlrcpp::Any Mx_starParser::ClassdeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitClassdeclaration(this);
  else
    return visitor->visitChildren(this);
}

Mx_starParser::ClassdeclarationContext* Mx_starParser::classdeclaration() {
  ClassdeclarationContext *_localctx = _tracker.createInstance<ClassdeclarationContext>(_ctx, getState());
  enterRule(_localctx, 6, Mx_starParser::RuleClassdeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(119);
    match(Mx_starParser::Class);
    setState(120);
    match(Mx_starParser::Identifier);
    setState(121);
    match(Mx_starParser::T__0);
    setState(123);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << Mx_starParser::Int)
      | (1ULL << Mx_starParser::Bool)
      | (1ULL << Mx_starParser::String)
      | (1ULL << Mx_starParser::Void)
      | (1ULL << Mx_starParser::Identifier))) != 0)) {
      setState(122);
      memberdeclarationlist(0);
    }
    setState(125);
    match(Mx_starParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MemberdeclarationlistContext ------------------------------------------------------------------

Mx_starParser::MemberdeclarationlistContext::MemberdeclarationlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Mx_starParser::MemberdeclarationContext* Mx_starParser::MemberdeclarationlistContext::memberdeclaration() {
  return getRuleContext<Mx_starParser::MemberdeclarationContext>(0);
}

Mx_starParser::MemberdeclarationlistContext* Mx_starParser::MemberdeclarationlistContext::memberdeclarationlist() {
  return getRuleContext<Mx_starParser::MemberdeclarationlistContext>(0);
}


size_t Mx_starParser::MemberdeclarationlistContext::getRuleIndex() const {
  return Mx_starParser::RuleMemberdeclarationlist;
}

void Mx_starParser::MemberdeclarationlistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMemberdeclarationlist(this);
}

void Mx_starParser::MemberdeclarationlistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMemberdeclarationlist(this);
}


antlrcpp::Any Mx_starParser::MemberdeclarationlistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitMemberdeclarationlist(this);
  else
    return visitor->visitChildren(this);
}


Mx_starParser::MemberdeclarationlistContext* Mx_starParser::memberdeclarationlist() {
   return memberdeclarationlist(0);
}

Mx_starParser::MemberdeclarationlistContext* Mx_starParser::memberdeclarationlist(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Mx_starParser::MemberdeclarationlistContext *_localctx = _tracker.createInstance<MemberdeclarationlistContext>(_ctx, parentState);
  Mx_starParser::MemberdeclarationlistContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 8;
  enterRecursionRule(_localctx, 8, Mx_starParser::RuleMemberdeclarationlist, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(128);
    memberdeclaration();
    _ctx->stop = _input->LT(-1);
    setState(134);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<MemberdeclarationlistContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleMemberdeclarationlist);
        setState(130);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(131);
        memberdeclaration(); 
      }
      setState(136);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- MemberdeclarationContext ------------------------------------------------------------------

Mx_starParser::MemberdeclarationContext::MemberdeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Mx_starParser::DeclarationstatementContext* Mx_starParser::MemberdeclarationContext::declarationstatement() {
  return getRuleContext<Mx_starParser::DeclarationstatementContext>(0);
}

Mx_starParser::FunctiondeclarationContext* Mx_starParser::MemberdeclarationContext::functiondeclaration() {
  return getRuleContext<Mx_starParser::FunctiondeclarationContext>(0);
}


size_t Mx_starParser::MemberdeclarationContext::getRuleIndex() const {
  return Mx_starParser::RuleMemberdeclaration;
}

void Mx_starParser::MemberdeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMemberdeclaration(this);
}

void Mx_starParser::MemberdeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMemberdeclaration(this);
}


antlrcpp::Any Mx_starParser::MemberdeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitMemberdeclaration(this);
  else
    return visitor->visitChildren(this);
}

Mx_starParser::MemberdeclarationContext* Mx_starParser::memberdeclaration() {
  MemberdeclarationContext *_localctx = _tracker.createInstance<MemberdeclarationContext>(_ctx, getState());
  enterRule(_localctx, 10, Mx_starParser::RuleMemberdeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(139);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(137);
      declarationstatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(138);
      functiondeclaration();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctiondeclarationContext ------------------------------------------------------------------

Mx_starParser::FunctiondeclarationContext::FunctiondeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Mx_starParser::FunctiondeclarationContext::Identifier() {
  return getToken(Mx_starParser::Identifier, 0);
}

Mx_starParser::BlockContext* Mx_starParser::FunctiondeclarationContext::block() {
  return getRuleContext<Mx_starParser::BlockContext>(0);
}

Mx_starParser::TypespecifierContext* Mx_starParser::FunctiondeclarationContext::typespecifier() {
  return getRuleContext<Mx_starParser::TypespecifierContext>(0);
}

Mx_starParser::ParameterlistContext* Mx_starParser::FunctiondeclarationContext::parameterlist() {
  return getRuleContext<Mx_starParser::ParameterlistContext>(0);
}


size_t Mx_starParser::FunctiondeclarationContext::getRuleIndex() const {
  return Mx_starParser::RuleFunctiondeclaration;
}

void Mx_starParser::FunctiondeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctiondeclaration(this);
}

void Mx_starParser::FunctiondeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctiondeclaration(this);
}


antlrcpp::Any Mx_starParser::FunctiondeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitFunctiondeclaration(this);
  else
    return visitor->visitChildren(this);
}

Mx_starParser::FunctiondeclarationContext* Mx_starParser::functiondeclaration() {
  FunctiondeclarationContext *_localctx = _tracker.createInstance<FunctiondeclarationContext>(_ctx, getState());
  enterRule(_localctx, 12, Mx_starParser::RuleFunctiondeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(142);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      setState(141);
      typespecifier(0);
      break;
    }

    }
    setState(144);
    match(Mx_starParser::Identifier);
    setState(145);
    match(Mx_starParser::T__2);
    setState(147);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << Mx_starParser::Int)
      | (1ULL << Mx_starParser::Bool)
      | (1ULL << Mx_starParser::String)
      | (1ULL << Mx_starParser::Void)
      | (1ULL << Mx_starParser::Identifier))) != 0)) {
      setState(146);
      parameterlist(0);
    }
    setState(149);
    match(Mx_starParser::T__3);
    setState(150);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterlistContext ------------------------------------------------------------------

Mx_starParser::ParameterlistContext::ParameterlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Mx_starParser::ParameterContext* Mx_starParser::ParameterlistContext::parameter() {
  return getRuleContext<Mx_starParser::ParameterContext>(0);
}

Mx_starParser::ParameterlistContext* Mx_starParser::ParameterlistContext::parameterlist() {
  return getRuleContext<Mx_starParser::ParameterlistContext>(0);
}


size_t Mx_starParser::ParameterlistContext::getRuleIndex() const {
  return Mx_starParser::RuleParameterlist;
}

void Mx_starParser::ParameterlistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterlist(this);
}

void Mx_starParser::ParameterlistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterlist(this);
}


antlrcpp::Any Mx_starParser::ParameterlistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitParameterlist(this);
  else
    return visitor->visitChildren(this);
}


Mx_starParser::ParameterlistContext* Mx_starParser::parameterlist() {
   return parameterlist(0);
}

Mx_starParser::ParameterlistContext* Mx_starParser::parameterlist(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Mx_starParser::ParameterlistContext *_localctx = _tracker.createInstance<ParameterlistContext>(_ctx, parentState);
  Mx_starParser::ParameterlistContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 14;
  enterRecursionRule(_localctx, 14, Mx_starParser::RuleParameterlist, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(153);
    parameter();
    _ctx->stop = _input->LT(-1);
    setState(160);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ParameterlistContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleParameterlist);
        setState(155);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(156);
        match(Mx_starParser::T__4);
        setState(157);
        parameter(); 
      }
      setState(162);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ParameterContext ------------------------------------------------------------------

Mx_starParser::ParameterContext::ParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Mx_starParser::TypespecifierContext* Mx_starParser::ParameterContext::typespecifier() {
  return getRuleContext<Mx_starParser::TypespecifierContext>(0);
}

Mx_starParser::InitdeclaratorContext* Mx_starParser::ParameterContext::initdeclarator() {
  return getRuleContext<Mx_starParser::InitdeclaratorContext>(0);
}


size_t Mx_starParser::ParameterContext::getRuleIndex() const {
  return Mx_starParser::RuleParameter;
}

void Mx_starParser::ParameterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter(this);
}

void Mx_starParser::ParameterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter(this);
}


antlrcpp::Any Mx_starParser::ParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitParameter(this);
  else
    return visitor->visitChildren(this);
}

Mx_starParser::ParameterContext* Mx_starParser::parameter() {
  ParameterContext *_localctx = _tracker.createInstance<ParameterContext>(_ctx, getState());
  enterRule(_localctx, 16, Mx_starParser::RuleParameter);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(163);
    typespecifier(0);
    setState(164);
    initdeclarator();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

Mx_starParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Mx_starParser::DeclarationstatementContext* Mx_starParser::StatementContext::declarationstatement() {
  return getRuleContext<Mx_starParser::DeclarationstatementContext>(0);
}

Mx_starParser::IfstatementContext* Mx_starParser::StatementContext::ifstatement() {
  return getRuleContext<Mx_starParser::IfstatementContext>(0);
}

Mx_starParser::IterationstatementContext* Mx_starParser::StatementContext::iterationstatement() {
  return getRuleContext<Mx_starParser::IterationstatementContext>(0);
}

Mx_starParser::JumpstatementContext* Mx_starParser::StatementContext::jumpstatement() {
  return getRuleContext<Mx_starParser::JumpstatementContext>(0);
}

Mx_starParser::ExpressionstatementContext* Mx_starParser::StatementContext::expressionstatement() {
  return getRuleContext<Mx_starParser::ExpressionstatementContext>(0);
}

Mx_starParser::EmptystatementContext* Mx_starParser::StatementContext::emptystatement() {
  return getRuleContext<Mx_starParser::EmptystatementContext>(0);
}

Mx_starParser::BlockContext* Mx_starParser::StatementContext::block() {
  return getRuleContext<Mx_starParser::BlockContext>(0);
}


size_t Mx_starParser::StatementContext::getRuleIndex() const {
  return Mx_starParser::RuleStatement;
}

void Mx_starParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void Mx_starParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


antlrcpp::Any Mx_starParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

Mx_starParser::StatementContext* Mx_starParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 18, Mx_starParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(173);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(166);
      declarationstatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(167);
      ifstatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(168);
      iterationstatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(169);
      jumpstatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(170);
      expressionstatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(171);
      emptystatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(172);
      block();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

Mx_starParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Mx_starParser::StatementlistContext* Mx_starParser::BlockContext::statementlist() {
  return getRuleContext<Mx_starParser::StatementlistContext>(0);
}


size_t Mx_starParser::BlockContext::getRuleIndex() const {
  return Mx_starParser::RuleBlock;
}

void Mx_starParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void Mx_starParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


antlrcpp::Any Mx_starParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

Mx_starParser::BlockContext* Mx_starParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 20, Mx_starParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(175);
    match(Mx_starParser::T__0);
    setState(177);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << Mx_starParser::T__0)
      | (1ULL << Mx_starParser::T__2)
      | (1ULL << Mx_starParser::T__5)
      | (1ULL << Mx_starParser::T__13)
      | (1ULL << Mx_starParser::T__17)
      | (1ULL << Mx_starParser::T__18)
      | (1ULL << Mx_starParser::T__30)
      | (1ULL << Mx_starParser::T__31)
      | (1ULL << Mx_starParser::Stringliteral)
      | (1ULL << Mx_starParser::Integerliteral)
      | (1ULL << Mx_starParser::Int)
      | (1ULL << Mx_starParser::Bool)
      | (1ULL << Mx_starParser::String)
      | (1ULL << Mx_starParser::Null)
      | (1ULL << Mx_starParser::Void)
      | (1ULL << Mx_starParser::True)
      | (1ULL << Mx_starParser::False)
      | (1ULL << Mx_starParser::If)
      | (1ULL << Mx_starParser::For)
      | (1ULL << Mx_starParser::While)
      | (1ULL << Mx_starParser::Break)
      | (1ULL << Mx_starParser::Continue)
      | (1ULL << Mx_starParser::Return)
      | (1ULL << Mx_starParser::New)
      | (1ULL << Mx_starParser::This)
      | (1ULL << Mx_starParser::Identifier))) != 0)) {
      setState(176);
      statementlist(0);
    }
    setState(179);
    match(Mx_starParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementlistContext ------------------------------------------------------------------

Mx_starParser::StatementlistContext::StatementlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Mx_starParser::StatementContext* Mx_starParser::StatementlistContext::statement() {
  return getRuleContext<Mx_starParser::StatementContext>(0);
}

Mx_starParser::StatementlistContext* Mx_starParser::StatementlistContext::statementlist() {
  return getRuleContext<Mx_starParser::StatementlistContext>(0);
}


size_t Mx_starParser::StatementlistContext::getRuleIndex() const {
  return Mx_starParser::RuleStatementlist;
}

void Mx_starParser::StatementlistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatementlist(this);
}

void Mx_starParser::StatementlistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatementlist(this);
}


antlrcpp::Any Mx_starParser::StatementlistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitStatementlist(this);
  else
    return visitor->visitChildren(this);
}


Mx_starParser::StatementlistContext* Mx_starParser::statementlist() {
   return statementlist(0);
}

Mx_starParser::StatementlistContext* Mx_starParser::statementlist(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Mx_starParser::StatementlistContext *_localctx = _tracker.createInstance<StatementlistContext>(_ctx, parentState);
  Mx_starParser::StatementlistContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, Mx_starParser::RuleStatementlist, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(182);
    statement();
    _ctx->stop = _input->LT(-1);
    setState(188);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<StatementlistContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleStatementlist);
        setState(184);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(185);
        statement(); 
      }
      setState(190);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- DeclarationstatementContext ------------------------------------------------------------------

Mx_starParser::DeclarationstatementContext::DeclarationstatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Mx_starParser::TypespecifierContext* Mx_starParser::DeclarationstatementContext::typespecifier() {
  return getRuleContext<Mx_starParser::TypespecifierContext>(0);
}

Mx_starParser::InitdeclaratorlistContext* Mx_starParser::DeclarationstatementContext::initdeclaratorlist() {
  return getRuleContext<Mx_starParser::InitdeclaratorlistContext>(0);
}


size_t Mx_starParser::DeclarationstatementContext::getRuleIndex() const {
  return Mx_starParser::RuleDeclarationstatement;
}

void Mx_starParser::DeclarationstatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarationstatement(this);
}

void Mx_starParser::DeclarationstatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarationstatement(this);
}


antlrcpp::Any Mx_starParser::DeclarationstatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitDeclarationstatement(this);
  else
    return visitor->visitChildren(this);
}

Mx_starParser::DeclarationstatementContext* Mx_starParser::declarationstatement() {
  DeclarationstatementContext *_localctx = _tracker.createInstance<DeclarationstatementContext>(_ctx, getState());
  enterRule(_localctx, 24, Mx_starParser::RuleDeclarationstatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(191);
    typespecifier(0);
    setState(192);
    initdeclaratorlist(0);
    setState(193);
    match(Mx_starParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitdeclaratorlistContext ------------------------------------------------------------------

Mx_starParser::InitdeclaratorlistContext::InitdeclaratorlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Mx_starParser::InitdeclaratorContext* Mx_starParser::InitdeclaratorlistContext::initdeclarator() {
  return getRuleContext<Mx_starParser::InitdeclaratorContext>(0);
}

Mx_starParser::InitdeclaratorlistContext* Mx_starParser::InitdeclaratorlistContext::initdeclaratorlist() {
  return getRuleContext<Mx_starParser::InitdeclaratorlistContext>(0);
}


size_t Mx_starParser::InitdeclaratorlistContext::getRuleIndex() const {
  return Mx_starParser::RuleInitdeclaratorlist;
}

void Mx_starParser::InitdeclaratorlistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitdeclaratorlist(this);
}

void Mx_starParser::InitdeclaratorlistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitdeclaratorlist(this);
}


antlrcpp::Any Mx_starParser::InitdeclaratorlistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitInitdeclaratorlist(this);
  else
    return visitor->visitChildren(this);
}


Mx_starParser::InitdeclaratorlistContext* Mx_starParser::initdeclaratorlist() {
   return initdeclaratorlist(0);
}

Mx_starParser::InitdeclaratorlistContext* Mx_starParser::initdeclaratorlist(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Mx_starParser::InitdeclaratorlistContext *_localctx = _tracker.createInstance<InitdeclaratorlistContext>(_ctx, parentState);
  Mx_starParser::InitdeclaratorlistContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 26;
  enterRecursionRule(_localctx, 26, Mx_starParser::RuleInitdeclaratorlist, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(196);
    initdeclarator();
    _ctx->stop = _input->LT(-1);
    setState(203);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<InitdeclaratorlistContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleInitdeclaratorlist);
        setState(198);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(199);
        match(Mx_starParser::T__4);
        setState(200);
        initdeclarator(); 
      }
      setState(205);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- InitdeclaratorContext ------------------------------------------------------------------

Mx_starParser::InitdeclaratorContext::InitdeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Mx_starParser::DeclaratorContext* Mx_starParser::InitdeclaratorContext::declarator() {
  return getRuleContext<Mx_starParser::DeclaratorContext>(0);
}

Mx_starParser::InitializerContext* Mx_starParser::InitdeclaratorContext::initializer() {
  return getRuleContext<Mx_starParser::InitializerContext>(0);
}


size_t Mx_starParser::InitdeclaratorContext::getRuleIndex() const {
  return Mx_starParser::RuleInitdeclarator;
}

void Mx_starParser::InitdeclaratorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitdeclarator(this);
}

void Mx_starParser::InitdeclaratorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitdeclarator(this);
}


antlrcpp::Any Mx_starParser::InitdeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitInitdeclarator(this);
  else
    return visitor->visitChildren(this);
}

Mx_starParser::InitdeclaratorContext* Mx_starParser::initdeclarator() {
  InitdeclaratorContext *_localctx = _tracker.createInstance<InitdeclaratorContext>(_ctx, getState());
  enterRule(_localctx, 28, Mx_starParser::RuleInitdeclarator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(206);
    declarator();
    setState(208);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      setState(207);
      initializer();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclaratorContext ------------------------------------------------------------------

Mx_starParser::DeclaratorContext::DeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Mx_starParser::DeclaratorContext::Identifier() {
  return getToken(Mx_starParser::Identifier, 0);
}


size_t Mx_starParser::DeclaratorContext::getRuleIndex() const {
  return Mx_starParser::RuleDeclarator;
}

void Mx_starParser::DeclaratorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarator(this);
}

void Mx_starParser::DeclaratorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarator(this);
}


antlrcpp::Any Mx_starParser::DeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitDeclarator(this);
  else
    return visitor->visitChildren(this);
}

Mx_starParser::DeclaratorContext* Mx_starParser::declarator() {
  DeclaratorContext *_localctx = _tracker.createInstance<DeclaratorContext>(_ctx, getState());
  enterRule(_localctx, 30, Mx_starParser::RuleDeclarator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(210);
    match(Mx_starParser::Identifier);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitializerContext ------------------------------------------------------------------

Mx_starParser::InitializerContext::InitializerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Mx_starParser::ExpressionContext* Mx_starParser::InitializerContext::expression() {
  return getRuleContext<Mx_starParser::ExpressionContext>(0);
}


size_t Mx_starParser::InitializerContext::getRuleIndex() const {
  return Mx_starParser::RuleInitializer;
}

void Mx_starParser::InitializerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitializer(this);
}

void Mx_starParser::InitializerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitializer(this);
}


antlrcpp::Any Mx_starParser::InitializerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitInitializer(this);
  else
    return visitor->visitChildren(this);
}

Mx_starParser::InitializerContext* Mx_starParser::initializer() {
  InitializerContext *_localctx = _tracker.createInstance<InitializerContext>(_ctx, getState());
  enterRule(_localctx, 32, Mx_starParser::RuleInitializer);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(212);
    match(Mx_starParser::T__6);
    setState(213);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfstatementContext ------------------------------------------------------------------

Mx_starParser::IfstatementContext::IfstatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Mx_starParser::IfstatementContext::If() {
  return getToken(Mx_starParser::If, 0);
}

Mx_starParser::ExpressionContext* Mx_starParser::IfstatementContext::expression() {
  return getRuleContext<Mx_starParser::ExpressionContext>(0);
}

std::vector<Mx_starParser::StatementContext *> Mx_starParser::IfstatementContext::statement() {
  return getRuleContexts<Mx_starParser::StatementContext>();
}

Mx_starParser::StatementContext* Mx_starParser::IfstatementContext::statement(size_t i) {
  return getRuleContext<Mx_starParser::StatementContext>(i);
}

tree::TerminalNode* Mx_starParser::IfstatementContext::Else() {
  return getToken(Mx_starParser::Else, 0);
}


size_t Mx_starParser::IfstatementContext::getRuleIndex() const {
  return Mx_starParser::RuleIfstatement;
}

void Mx_starParser::IfstatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfstatement(this);
}

void Mx_starParser::IfstatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfstatement(this);
}


antlrcpp::Any Mx_starParser::IfstatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitIfstatement(this);
  else
    return visitor->visitChildren(this);
}

Mx_starParser::IfstatementContext* Mx_starParser::ifstatement() {
  IfstatementContext *_localctx = _tracker.createInstance<IfstatementContext>(_ctx, getState());
  enterRule(_localctx, 34, Mx_starParser::RuleIfstatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(229);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(215);
      match(Mx_starParser::If);
      setState(216);
      match(Mx_starParser::T__2);
      setState(217);
      expression();
      setState(218);
      match(Mx_starParser::T__3);
      setState(219);
      statement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(221);
      match(Mx_starParser::If);
      setState(222);
      match(Mx_starParser::T__2);
      setState(223);
      expression();
      setState(224);
      match(Mx_starParser::T__3);
      setState(225);
      statement();
      setState(226);
      match(Mx_starParser::Else);
      setState(227);
      statement();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IterationstatementContext ------------------------------------------------------------------

Mx_starParser::IterationstatementContext::IterationstatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Mx_starParser::IterationstatementContext::While() {
  return getToken(Mx_starParser::While, 0);
}

std::vector<Mx_starParser::ExpressionContext *> Mx_starParser::IterationstatementContext::expression() {
  return getRuleContexts<Mx_starParser::ExpressionContext>();
}

Mx_starParser::ExpressionContext* Mx_starParser::IterationstatementContext::expression(size_t i) {
  return getRuleContext<Mx_starParser::ExpressionContext>(i);
}

Mx_starParser::StatementContext* Mx_starParser::IterationstatementContext::statement() {
  return getRuleContext<Mx_starParser::StatementContext>(0);
}

tree::TerminalNode* Mx_starParser::IterationstatementContext::For() {
  return getToken(Mx_starParser::For, 0);
}


size_t Mx_starParser::IterationstatementContext::getRuleIndex() const {
  return Mx_starParser::RuleIterationstatement;
}

void Mx_starParser::IterationstatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIterationstatement(this);
}

void Mx_starParser::IterationstatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIterationstatement(this);
}


antlrcpp::Any Mx_starParser::IterationstatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitIterationstatement(this);
  else
    return visitor->visitChildren(this);
}

Mx_starParser::IterationstatementContext* Mx_starParser::iterationstatement() {
  IterationstatementContext *_localctx = _tracker.createInstance<IterationstatementContext>(_ctx, getState());
  enterRule(_localctx, 36, Mx_starParser::RuleIterationstatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(252);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Mx_starParser::While: {
        enterOuterAlt(_localctx, 1);
        setState(231);
        match(Mx_starParser::While);
        setState(232);
        match(Mx_starParser::T__2);
        setState(233);
        expression();
        setState(234);
        match(Mx_starParser::T__3);
        setState(235);
        statement();
        break;
      }

      case Mx_starParser::For: {
        enterOuterAlt(_localctx, 2);
        setState(237);
        match(Mx_starParser::For);
        setState(238);
        match(Mx_starParser::T__2);
        setState(240);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << Mx_starParser::T__2)
          | (1ULL << Mx_starParser::T__13)
          | (1ULL << Mx_starParser::T__17)
          | (1ULL << Mx_starParser::T__18)
          | (1ULL << Mx_starParser::T__30)
          | (1ULL << Mx_starParser::T__31)
          | (1ULL << Mx_starParser::Stringliteral)
          | (1ULL << Mx_starParser::Integerliteral)
          | (1ULL << Mx_starParser::Null)
          | (1ULL << Mx_starParser::True)
          | (1ULL << Mx_starParser::False)
          | (1ULL << Mx_starParser::New)
          | (1ULL << Mx_starParser::This)
          | (1ULL << Mx_starParser::Identifier))) != 0)) {
          setState(239);
          expression();
        }
        setState(242);
        match(Mx_starParser::T__5);
        setState(244);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << Mx_starParser::T__2)
          | (1ULL << Mx_starParser::T__13)
          | (1ULL << Mx_starParser::T__17)
          | (1ULL << Mx_starParser::T__18)
          | (1ULL << Mx_starParser::T__30)
          | (1ULL << Mx_starParser::T__31)
          | (1ULL << Mx_starParser::Stringliteral)
          | (1ULL << Mx_starParser::Integerliteral)
          | (1ULL << Mx_starParser::Null)
          | (1ULL << Mx_starParser::True)
          | (1ULL << Mx_starParser::False)
          | (1ULL << Mx_starParser::New)
          | (1ULL << Mx_starParser::This)
          | (1ULL << Mx_starParser::Identifier))) != 0)) {
          setState(243);
          expression();
        }
        setState(246);
        match(Mx_starParser::T__5);
        setState(248);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << Mx_starParser::T__2)
          | (1ULL << Mx_starParser::T__13)
          | (1ULL << Mx_starParser::T__17)
          | (1ULL << Mx_starParser::T__18)
          | (1ULL << Mx_starParser::T__30)
          | (1ULL << Mx_starParser::T__31)
          | (1ULL << Mx_starParser::Stringliteral)
          | (1ULL << Mx_starParser::Integerliteral)
          | (1ULL << Mx_starParser::Null)
          | (1ULL << Mx_starParser::True)
          | (1ULL << Mx_starParser::False)
          | (1ULL << Mx_starParser::New)
          | (1ULL << Mx_starParser::This)
          | (1ULL << Mx_starParser::Identifier))) != 0)) {
          setState(247);
          expression();
        }
        setState(250);
        match(Mx_starParser::T__3);
        setState(251);
        statement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- JumpstatementContext ------------------------------------------------------------------

Mx_starParser::JumpstatementContext::JumpstatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Mx_starParser::JumpstatementContext::Break() {
  return getToken(Mx_starParser::Break, 0);
}

tree::TerminalNode* Mx_starParser::JumpstatementContext::Continue() {
  return getToken(Mx_starParser::Continue, 0);
}

tree::TerminalNode* Mx_starParser::JumpstatementContext::Return() {
  return getToken(Mx_starParser::Return, 0);
}

Mx_starParser::ExpressionContext* Mx_starParser::JumpstatementContext::expression() {
  return getRuleContext<Mx_starParser::ExpressionContext>(0);
}


size_t Mx_starParser::JumpstatementContext::getRuleIndex() const {
  return Mx_starParser::RuleJumpstatement;
}

void Mx_starParser::JumpstatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterJumpstatement(this);
}

void Mx_starParser::JumpstatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitJumpstatement(this);
}


antlrcpp::Any Mx_starParser::JumpstatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitJumpstatement(this);
  else
    return visitor->visitChildren(this);
}

Mx_starParser::JumpstatementContext* Mx_starParser::jumpstatement() {
  JumpstatementContext *_localctx = _tracker.createInstance<JumpstatementContext>(_ctx, getState());
  enterRule(_localctx, 38, Mx_starParser::RuleJumpstatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(263);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Mx_starParser::Break: {
        enterOuterAlt(_localctx, 1);
        setState(254);
        match(Mx_starParser::Break);
        setState(255);
        match(Mx_starParser::T__5);
        break;
      }

      case Mx_starParser::Continue: {
        enterOuterAlt(_localctx, 2);
        setState(256);
        match(Mx_starParser::Continue);
        setState(257);
        match(Mx_starParser::T__5);
        break;
      }

      case Mx_starParser::Return: {
        enterOuterAlt(_localctx, 3);
        setState(258);
        match(Mx_starParser::Return);
        setState(260);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << Mx_starParser::T__2)
          | (1ULL << Mx_starParser::T__13)
          | (1ULL << Mx_starParser::T__17)
          | (1ULL << Mx_starParser::T__18)
          | (1ULL << Mx_starParser::T__30)
          | (1ULL << Mx_starParser::T__31)
          | (1ULL << Mx_starParser::Stringliteral)
          | (1ULL << Mx_starParser::Integerliteral)
          | (1ULL << Mx_starParser::Null)
          | (1ULL << Mx_starParser::True)
          | (1ULL << Mx_starParser::False)
          | (1ULL << Mx_starParser::New)
          | (1ULL << Mx_starParser::This)
          | (1ULL << Mx_starParser::Identifier))) != 0)) {
          setState(259);
          expression();
        }
        setState(262);
        match(Mx_starParser::T__5);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionstatementContext ------------------------------------------------------------------

Mx_starParser::ExpressionstatementContext::ExpressionstatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Mx_starParser::ExpressionContext* Mx_starParser::ExpressionstatementContext::expression() {
  return getRuleContext<Mx_starParser::ExpressionContext>(0);
}


size_t Mx_starParser::ExpressionstatementContext::getRuleIndex() const {
  return Mx_starParser::RuleExpressionstatement;
}

void Mx_starParser::ExpressionstatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionstatement(this);
}

void Mx_starParser::ExpressionstatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionstatement(this);
}


antlrcpp::Any Mx_starParser::ExpressionstatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitExpressionstatement(this);
  else
    return visitor->visitChildren(this);
}

Mx_starParser::ExpressionstatementContext* Mx_starParser::expressionstatement() {
  ExpressionstatementContext *_localctx = _tracker.createInstance<ExpressionstatementContext>(_ctx, getState());
  enterRule(_localctx, 40, Mx_starParser::RuleExpressionstatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(265);
    expression();
    setState(266);
    match(Mx_starParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EmptystatementContext ------------------------------------------------------------------

Mx_starParser::EmptystatementContext::EmptystatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t Mx_starParser::EmptystatementContext::getRuleIndex() const {
  return Mx_starParser::RuleEmptystatement;
}

void Mx_starParser::EmptystatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEmptystatement(this);
}

void Mx_starParser::EmptystatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEmptystatement(this);
}


antlrcpp::Any Mx_starParser::EmptystatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitEmptystatement(this);
  else
    return visitor->visitChildren(this);
}

Mx_starParser::EmptystatementContext* Mx_starParser::emptystatement() {
  EmptystatementContext *_localctx = _tracker.createInstance<EmptystatementContext>(_ctx, getState());
  enterRule(_localctx, 42, Mx_starParser::RuleEmptystatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(268);
    match(Mx_starParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionlistContext ------------------------------------------------------------------

Mx_starParser::ExpressionlistContext::ExpressionlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Mx_starParser::ExpressionContext* Mx_starParser::ExpressionlistContext::expression() {
  return getRuleContext<Mx_starParser::ExpressionContext>(0);
}

Mx_starParser::ExpressionlistContext* Mx_starParser::ExpressionlistContext::expressionlist() {
  return getRuleContext<Mx_starParser::ExpressionlistContext>(0);
}


size_t Mx_starParser::ExpressionlistContext::getRuleIndex() const {
  return Mx_starParser::RuleExpressionlist;
}

void Mx_starParser::ExpressionlistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionlist(this);
}

void Mx_starParser::ExpressionlistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionlist(this);
}


antlrcpp::Any Mx_starParser::ExpressionlistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitExpressionlist(this);
  else
    return visitor->visitChildren(this);
}


Mx_starParser::ExpressionlistContext* Mx_starParser::expressionlist() {
   return expressionlist(0);
}

Mx_starParser::ExpressionlistContext* Mx_starParser::expressionlist(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Mx_starParser::ExpressionlistContext *_localctx = _tracker.createInstance<ExpressionlistContext>(_ctx, parentState);
  Mx_starParser::ExpressionlistContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 44;
  enterRecursionRule(_localctx, 44, Mx_starParser::RuleExpressionlist, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(271);
    expression();
    _ctx->stop = _input->LT(-1);
    setState(278);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExpressionlistContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpressionlist);
        setState(273);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(274);
        match(Mx_starParser::T__4);
        setState(275);
        expression(); 
      }
      setState(280);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

Mx_starParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Mx_starParser::AssignmentexpressionContext* Mx_starParser::ExpressionContext::assignmentexpression() {
  return getRuleContext<Mx_starParser::AssignmentexpressionContext>(0);
}


size_t Mx_starParser::ExpressionContext::getRuleIndex() const {
  return Mx_starParser::RuleExpression;
}

void Mx_starParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void Mx_starParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


antlrcpp::Any Mx_starParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

Mx_starParser::ExpressionContext* Mx_starParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 46, Mx_starParser::RuleExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(281);
    assignmentexpression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentexpressionContext ------------------------------------------------------------------

Mx_starParser::AssignmentexpressionContext::AssignmentexpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Mx_starParser::LogicalorexpressionContext* Mx_starParser::AssignmentexpressionContext::logicalorexpression() {
  return getRuleContext<Mx_starParser::LogicalorexpressionContext>(0);
}

Mx_starParser::AssignmentexpressionContext* Mx_starParser::AssignmentexpressionContext::assignmentexpression() {
  return getRuleContext<Mx_starParser::AssignmentexpressionContext>(0);
}


size_t Mx_starParser::AssignmentexpressionContext::getRuleIndex() const {
  return Mx_starParser::RuleAssignmentexpression;
}

void Mx_starParser::AssignmentexpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentexpression(this);
}

void Mx_starParser::AssignmentexpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentexpression(this);
}


antlrcpp::Any Mx_starParser::AssignmentexpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitAssignmentexpression(this);
  else
    return visitor->visitChildren(this);
}

Mx_starParser::AssignmentexpressionContext* Mx_starParser::assignmentexpression() {
  AssignmentexpressionContext *_localctx = _tracker.createInstance<AssignmentexpressionContext>(_ctx, getState());
  enterRule(_localctx, 48, Mx_starParser::RuleAssignmentexpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(288);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(283);
      logicalorexpression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(284);
      logicalorexpression(0);
      setState(285);
      match(Mx_starParser::T__6);
      setState(286);
      assignmentexpression();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicalorexpressionContext ------------------------------------------------------------------

Mx_starParser::LogicalorexpressionContext::LogicalorexpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Mx_starParser::LogicalandexpressionContext* Mx_starParser::LogicalorexpressionContext::logicalandexpression() {
  return getRuleContext<Mx_starParser::LogicalandexpressionContext>(0);
}

Mx_starParser::LogicalorexpressionContext* Mx_starParser::LogicalorexpressionContext::logicalorexpression() {
  return getRuleContext<Mx_starParser::LogicalorexpressionContext>(0);
}


size_t Mx_starParser::LogicalorexpressionContext::getRuleIndex() const {
  return Mx_starParser::RuleLogicalorexpression;
}

void Mx_starParser::LogicalorexpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalorexpression(this);
}

void Mx_starParser::LogicalorexpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalorexpression(this);
}


antlrcpp::Any Mx_starParser::LogicalorexpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitLogicalorexpression(this);
  else
    return visitor->visitChildren(this);
}


Mx_starParser::LogicalorexpressionContext* Mx_starParser::logicalorexpression() {
   return logicalorexpression(0);
}

Mx_starParser::LogicalorexpressionContext* Mx_starParser::logicalorexpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Mx_starParser::LogicalorexpressionContext *_localctx = _tracker.createInstance<LogicalorexpressionContext>(_ctx, parentState);
  Mx_starParser::LogicalorexpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 50;
  enterRecursionRule(_localctx, 50, Mx_starParser::RuleLogicalorexpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(291);
    logicalandexpression(0);
    _ctx->stop = _input->LT(-1);
    setState(298);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<LogicalorexpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLogicalorexpression);
        setState(293);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(294);
        match(Mx_starParser::T__7);
        setState(295);
        logicalandexpression(0); 
      }
      setState(300);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LogicalandexpressionContext ------------------------------------------------------------------

Mx_starParser::LogicalandexpressionContext::LogicalandexpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Mx_starParser::OrexpressionContext* Mx_starParser::LogicalandexpressionContext::orexpression() {
  return getRuleContext<Mx_starParser::OrexpressionContext>(0);
}

Mx_starParser::LogicalandexpressionContext* Mx_starParser::LogicalandexpressionContext::logicalandexpression() {
  return getRuleContext<Mx_starParser::LogicalandexpressionContext>(0);
}


size_t Mx_starParser::LogicalandexpressionContext::getRuleIndex() const {
  return Mx_starParser::RuleLogicalandexpression;
}

void Mx_starParser::LogicalandexpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalandexpression(this);
}

void Mx_starParser::LogicalandexpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalandexpression(this);
}


antlrcpp::Any Mx_starParser::LogicalandexpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitLogicalandexpression(this);
  else
    return visitor->visitChildren(this);
}


Mx_starParser::LogicalandexpressionContext* Mx_starParser::logicalandexpression() {
   return logicalandexpression(0);
}

Mx_starParser::LogicalandexpressionContext* Mx_starParser::logicalandexpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Mx_starParser::LogicalandexpressionContext *_localctx = _tracker.createInstance<LogicalandexpressionContext>(_ctx, parentState);
  Mx_starParser::LogicalandexpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 52;
  enterRecursionRule(_localctx, 52, Mx_starParser::RuleLogicalandexpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(302);
    orexpression(0);
    _ctx->stop = _input->LT(-1);
    setState(309);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<LogicalandexpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLogicalandexpression);
        setState(304);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(305);
        match(Mx_starParser::T__8);
        setState(306);
        orexpression(0); 
      }
      setState(311);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- OrexpressionContext ------------------------------------------------------------------

Mx_starParser::OrexpressionContext::OrexpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Mx_starParser::XorexpressionContext* Mx_starParser::OrexpressionContext::xorexpression() {
  return getRuleContext<Mx_starParser::XorexpressionContext>(0);
}

Mx_starParser::OrexpressionContext* Mx_starParser::OrexpressionContext::orexpression() {
  return getRuleContext<Mx_starParser::OrexpressionContext>(0);
}


size_t Mx_starParser::OrexpressionContext::getRuleIndex() const {
  return Mx_starParser::RuleOrexpression;
}

void Mx_starParser::OrexpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOrexpression(this);
}

void Mx_starParser::OrexpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOrexpression(this);
}


antlrcpp::Any Mx_starParser::OrexpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitOrexpression(this);
  else
    return visitor->visitChildren(this);
}


Mx_starParser::OrexpressionContext* Mx_starParser::orexpression() {
   return orexpression(0);
}

Mx_starParser::OrexpressionContext* Mx_starParser::orexpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Mx_starParser::OrexpressionContext *_localctx = _tracker.createInstance<OrexpressionContext>(_ctx, parentState);
  Mx_starParser::OrexpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 54;
  enterRecursionRule(_localctx, 54, Mx_starParser::RuleOrexpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(313);
    xorexpression(0);
    _ctx->stop = _input->LT(-1);
    setState(320);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<OrexpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleOrexpression);
        setState(315);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(316);
        match(Mx_starParser::T__9);
        setState(317);
        xorexpression(0); 
      }
      setState(322);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- XorexpressionContext ------------------------------------------------------------------

Mx_starParser::XorexpressionContext::XorexpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Mx_starParser::AndexpressionContext* Mx_starParser::XorexpressionContext::andexpression() {
  return getRuleContext<Mx_starParser::AndexpressionContext>(0);
}

Mx_starParser::XorexpressionContext* Mx_starParser::XorexpressionContext::xorexpression() {
  return getRuleContext<Mx_starParser::XorexpressionContext>(0);
}

Mx_starParser::EqualityexpressionContext* Mx_starParser::XorexpressionContext::equalityexpression() {
  return getRuleContext<Mx_starParser::EqualityexpressionContext>(0);
}


size_t Mx_starParser::XorexpressionContext::getRuleIndex() const {
  return Mx_starParser::RuleXorexpression;
}

void Mx_starParser::XorexpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterXorexpression(this);
}

void Mx_starParser::XorexpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitXorexpression(this);
}


antlrcpp::Any Mx_starParser::XorexpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitXorexpression(this);
  else
    return visitor->visitChildren(this);
}


Mx_starParser::XorexpressionContext* Mx_starParser::xorexpression() {
   return xorexpression(0);
}

Mx_starParser::XorexpressionContext* Mx_starParser::xorexpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Mx_starParser::XorexpressionContext *_localctx = _tracker.createInstance<XorexpressionContext>(_ctx, parentState);
  Mx_starParser::XorexpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 56;
  enterRecursionRule(_localctx, 56, Mx_starParser::RuleXorexpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(324);
    andexpression(0);
    _ctx->stop = _input->LT(-1);
    setState(331);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<XorexpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleXorexpression);
        setState(326);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(327);
        match(Mx_starParser::T__10);
        setState(328);
        equalityexpression(0); 
      }
      setState(333);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AndexpressionContext ------------------------------------------------------------------

Mx_starParser::AndexpressionContext::AndexpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Mx_starParser::EqualityexpressionContext* Mx_starParser::AndexpressionContext::equalityexpression() {
  return getRuleContext<Mx_starParser::EqualityexpressionContext>(0);
}

Mx_starParser::AndexpressionContext* Mx_starParser::AndexpressionContext::andexpression() {
  return getRuleContext<Mx_starParser::AndexpressionContext>(0);
}


size_t Mx_starParser::AndexpressionContext::getRuleIndex() const {
  return Mx_starParser::RuleAndexpression;
}

void Mx_starParser::AndexpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAndexpression(this);
}

void Mx_starParser::AndexpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAndexpression(this);
}


antlrcpp::Any Mx_starParser::AndexpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitAndexpression(this);
  else
    return visitor->visitChildren(this);
}


Mx_starParser::AndexpressionContext* Mx_starParser::andexpression() {
   return andexpression(0);
}

Mx_starParser::AndexpressionContext* Mx_starParser::andexpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Mx_starParser::AndexpressionContext *_localctx = _tracker.createInstance<AndexpressionContext>(_ctx, parentState);
  Mx_starParser::AndexpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 58;
  enterRecursionRule(_localctx, 58, Mx_starParser::RuleAndexpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(335);
    equalityexpression(0);
    _ctx->stop = _input->LT(-1);
    setState(342);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<AndexpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleAndexpression);
        setState(337);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(338);
        match(Mx_starParser::T__11);
        setState(339);
        equalityexpression(0); 
      }
      setState(344);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- EqualityexpressionContext ------------------------------------------------------------------

Mx_starParser::EqualityexpressionContext::EqualityexpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Mx_starParser::RelationalexpressionContext* Mx_starParser::EqualityexpressionContext::relationalexpression() {
  return getRuleContext<Mx_starParser::RelationalexpressionContext>(0);
}

Mx_starParser::EqualityexpressionContext* Mx_starParser::EqualityexpressionContext::equalityexpression() {
  return getRuleContext<Mx_starParser::EqualityexpressionContext>(0);
}

Mx_starParser::EqualityoperatorContext* Mx_starParser::EqualityexpressionContext::equalityoperator() {
  return getRuleContext<Mx_starParser::EqualityoperatorContext>(0);
}


size_t Mx_starParser::EqualityexpressionContext::getRuleIndex() const {
  return Mx_starParser::RuleEqualityexpression;
}

void Mx_starParser::EqualityexpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqualityexpression(this);
}

void Mx_starParser::EqualityexpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqualityexpression(this);
}


antlrcpp::Any Mx_starParser::EqualityexpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitEqualityexpression(this);
  else
    return visitor->visitChildren(this);
}


Mx_starParser::EqualityexpressionContext* Mx_starParser::equalityexpression() {
   return equalityexpression(0);
}

Mx_starParser::EqualityexpressionContext* Mx_starParser::equalityexpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Mx_starParser::EqualityexpressionContext *_localctx = _tracker.createInstance<EqualityexpressionContext>(_ctx, parentState);
  Mx_starParser::EqualityexpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 60;
  enterRecursionRule(_localctx, 60, Mx_starParser::RuleEqualityexpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(346);
    relationalexpression(0);
    _ctx->stop = _input->LT(-1);
    setState(354);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<EqualityexpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleEqualityexpression);
        setState(348);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(349);
        equalityoperator();
        setState(350);
        relationalexpression(0); 
      }
      setState(356);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- RelationalexpressionContext ------------------------------------------------------------------

Mx_starParser::RelationalexpressionContext::RelationalexpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Mx_starParser::ShiftexpressionContext* Mx_starParser::RelationalexpressionContext::shiftexpression() {
  return getRuleContext<Mx_starParser::ShiftexpressionContext>(0);
}

Mx_starParser::RelationalexpressionContext* Mx_starParser::RelationalexpressionContext::relationalexpression() {
  return getRuleContext<Mx_starParser::RelationalexpressionContext>(0);
}

Mx_starParser::RelationoperatorContext* Mx_starParser::RelationalexpressionContext::relationoperator() {
  return getRuleContext<Mx_starParser::RelationoperatorContext>(0);
}


size_t Mx_starParser::RelationalexpressionContext::getRuleIndex() const {
  return Mx_starParser::RuleRelationalexpression;
}

void Mx_starParser::RelationalexpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelationalexpression(this);
}

void Mx_starParser::RelationalexpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelationalexpression(this);
}


antlrcpp::Any Mx_starParser::RelationalexpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitRelationalexpression(this);
  else
    return visitor->visitChildren(this);
}


Mx_starParser::RelationalexpressionContext* Mx_starParser::relationalexpression() {
   return relationalexpression(0);
}

Mx_starParser::RelationalexpressionContext* Mx_starParser::relationalexpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Mx_starParser::RelationalexpressionContext *_localctx = _tracker.createInstance<RelationalexpressionContext>(_ctx, parentState);
  Mx_starParser::RelationalexpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 62;
  enterRecursionRule(_localctx, 62, Mx_starParser::RuleRelationalexpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(358);
    shiftexpression(0);
    _ctx->stop = _input->LT(-1);
    setState(366);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<RelationalexpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleRelationalexpression);
        setState(360);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(361);
        relationoperator();
        setState(362);
        shiftexpression(0); 
      }
      setState(368);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ShiftexpressionContext ------------------------------------------------------------------

Mx_starParser::ShiftexpressionContext::ShiftexpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Mx_starParser::AdditiveexpressionContext* Mx_starParser::ShiftexpressionContext::additiveexpression() {
  return getRuleContext<Mx_starParser::AdditiveexpressionContext>(0);
}

Mx_starParser::ShiftexpressionContext* Mx_starParser::ShiftexpressionContext::shiftexpression() {
  return getRuleContext<Mx_starParser::ShiftexpressionContext>(0);
}

Mx_starParser::ShiftoperatorContext* Mx_starParser::ShiftexpressionContext::shiftoperator() {
  return getRuleContext<Mx_starParser::ShiftoperatorContext>(0);
}


size_t Mx_starParser::ShiftexpressionContext::getRuleIndex() const {
  return Mx_starParser::RuleShiftexpression;
}

void Mx_starParser::ShiftexpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShiftexpression(this);
}

void Mx_starParser::ShiftexpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShiftexpression(this);
}


antlrcpp::Any Mx_starParser::ShiftexpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitShiftexpression(this);
  else
    return visitor->visitChildren(this);
}


Mx_starParser::ShiftexpressionContext* Mx_starParser::shiftexpression() {
   return shiftexpression(0);
}

Mx_starParser::ShiftexpressionContext* Mx_starParser::shiftexpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Mx_starParser::ShiftexpressionContext *_localctx = _tracker.createInstance<ShiftexpressionContext>(_ctx, parentState);
  Mx_starParser::ShiftexpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 64;
  enterRecursionRule(_localctx, 64, Mx_starParser::RuleShiftexpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(370);
    additiveexpression(0);
    _ctx->stop = _input->LT(-1);
    setState(378);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ShiftexpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleShiftexpression);
        setState(372);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(373);
        shiftoperator();
        setState(374);
        additiveexpression(0); 
      }
      setState(380);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AdditiveexpressionContext ------------------------------------------------------------------

Mx_starParser::AdditiveexpressionContext::AdditiveexpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Mx_starParser::MultiplicativeexpressionContext* Mx_starParser::AdditiveexpressionContext::multiplicativeexpression() {
  return getRuleContext<Mx_starParser::MultiplicativeexpressionContext>(0);
}

Mx_starParser::AdditiveexpressionContext* Mx_starParser::AdditiveexpressionContext::additiveexpression() {
  return getRuleContext<Mx_starParser::AdditiveexpressionContext>(0);
}


size_t Mx_starParser::AdditiveexpressionContext::getRuleIndex() const {
  return Mx_starParser::RuleAdditiveexpression;
}

void Mx_starParser::AdditiveexpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAdditiveexpression(this);
}

void Mx_starParser::AdditiveexpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAdditiveexpression(this);
}


antlrcpp::Any Mx_starParser::AdditiveexpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitAdditiveexpression(this);
  else
    return visitor->visitChildren(this);
}


Mx_starParser::AdditiveexpressionContext* Mx_starParser::additiveexpression() {
   return additiveexpression(0);
}

Mx_starParser::AdditiveexpressionContext* Mx_starParser::additiveexpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Mx_starParser::AdditiveexpressionContext *_localctx = _tracker.createInstance<AdditiveexpressionContext>(_ctx, parentState);
  Mx_starParser::AdditiveexpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 66;
  enterRecursionRule(_localctx, 66, Mx_starParser::RuleAdditiveexpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(382);
    multiplicativeexpression(0);
    _ctx->stop = _input->LT(-1);
    setState(392);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(390);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<AdditiveexpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleAdditiveexpression);
          setState(384);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(385);
          match(Mx_starParser::T__12);
          setState(386);
          multiplicativeexpression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<AdditiveexpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleAdditiveexpression);
          setState(387);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(388);
          match(Mx_starParser::T__13);
          setState(389);
          multiplicativeexpression(0);
          break;
        }

        } 
      }
      setState(394);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- MultiplicativeexpressionContext ------------------------------------------------------------------

Mx_starParser::MultiplicativeexpressionContext::MultiplicativeexpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Mx_starParser::UnaryexpressionContext* Mx_starParser::MultiplicativeexpressionContext::unaryexpression() {
  return getRuleContext<Mx_starParser::UnaryexpressionContext>(0);
}

Mx_starParser::MultiplicativeexpressionContext* Mx_starParser::MultiplicativeexpressionContext::multiplicativeexpression() {
  return getRuleContext<Mx_starParser::MultiplicativeexpressionContext>(0);
}


size_t Mx_starParser::MultiplicativeexpressionContext::getRuleIndex() const {
  return Mx_starParser::RuleMultiplicativeexpression;
}

void Mx_starParser::MultiplicativeexpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiplicativeexpression(this);
}

void Mx_starParser::MultiplicativeexpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiplicativeexpression(this);
}


antlrcpp::Any Mx_starParser::MultiplicativeexpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitMultiplicativeexpression(this);
  else
    return visitor->visitChildren(this);
}


Mx_starParser::MultiplicativeexpressionContext* Mx_starParser::multiplicativeexpression() {
   return multiplicativeexpression(0);
}

Mx_starParser::MultiplicativeexpressionContext* Mx_starParser::multiplicativeexpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Mx_starParser::MultiplicativeexpressionContext *_localctx = _tracker.createInstance<MultiplicativeexpressionContext>(_ctx, parentState);
  Mx_starParser::MultiplicativeexpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 68;
  enterRecursionRule(_localctx, 68, Mx_starParser::RuleMultiplicativeexpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(396);
    unaryexpression();
    _ctx->stop = _input->LT(-1);
    setState(409);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(407);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<MultiplicativeexpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleMultiplicativeexpression);
          setState(398);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(399);
          match(Mx_starParser::T__14);
          setState(400);
          unaryexpression();
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<MultiplicativeexpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleMultiplicativeexpression);
          setState(401);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(402);
          match(Mx_starParser::T__15);
          setState(403);
          unaryexpression();
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<MultiplicativeexpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleMultiplicativeexpression);
          setState(404);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(405);
          match(Mx_starParser::T__16);
          setState(406);
          unaryexpression();
          break;
        }

        } 
      }
      setState(411);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- UnaryexpressionContext ------------------------------------------------------------------

Mx_starParser::UnaryexpressionContext::UnaryexpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Mx_starParser::PostfixexpressionContext* Mx_starParser::UnaryexpressionContext::postfixexpression() {
  return getRuleContext<Mx_starParser::PostfixexpressionContext>(0);
}

Mx_starParser::UnaryexpressionContext* Mx_starParser::UnaryexpressionContext::unaryexpression() {
  return getRuleContext<Mx_starParser::UnaryexpressionContext>(0);
}

Mx_starParser::UnaryoperatorContext* Mx_starParser::UnaryexpressionContext::unaryoperator() {
  return getRuleContext<Mx_starParser::UnaryoperatorContext>(0);
}

Mx_starParser::NewexpressionContext* Mx_starParser::UnaryexpressionContext::newexpression() {
  return getRuleContext<Mx_starParser::NewexpressionContext>(0);
}


size_t Mx_starParser::UnaryexpressionContext::getRuleIndex() const {
  return Mx_starParser::RuleUnaryexpression;
}

void Mx_starParser::UnaryexpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryexpression(this);
}

void Mx_starParser::UnaryexpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryexpression(this);
}


antlrcpp::Any Mx_starParser::UnaryexpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitUnaryexpression(this);
  else
    return visitor->visitChildren(this);
}

Mx_starParser::UnaryexpressionContext* Mx_starParser::unaryexpression() {
  UnaryexpressionContext *_localctx = _tracker.createInstance<UnaryexpressionContext>(_ctx, getState());
  enterRule(_localctx, 70, Mx_starParser::RuleUnaryexpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(421);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Mx_starParser::T__2:
      case Mx_starParser::Stringliteral:
      case Mx_starParser::Integerliteral:
      case Mx_starParser::Null:
      case Mx_starParser::True:
      case Mx_starParser::False:
      case Mx_starParser::This:
      case Mx_starParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(412);
        postfixexpression(0);
        break;
      }

      case Mx_starParser::T__17: {
        enterOuterAlt(_localctx, 2);
        setState(413);
        match(Mx_starParser::T__17);
        setState(414);
        unaryexpression();
        break;
      }

      case Mx_starParser::T__18: {
        enterOuterAlt(_localctx, 3);
        setState(415);
        match(Mx_starParser::T__18);
        setState(416);
        unaryexpression();
        break;
      }

      case Mx_starParser::T__13:
      case Mx_starParser::T__30:
      case Mx_starParser::T__31: {
        enterOuterAlt(_localctx, 4);
        setState(417);
        unaryoperator();
        setState(418);
        unaryexpression();
        break;
      }

      case Mx_starParser::New: {
        enterOuterAlt(_localctx, 5);
        setState(420);
        newexpression();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NewexpressionContext ------------------------------------------------------------------

Mx_starParser::NewexpressionContext::NewexpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Mx_starParser::NewexpressionContext::New() {
  return getToken(Mx_starParser::New, 0);
}

Mx_starParser::NewtypespecifierContext* Mx_starParser::NewexpressionContext::newtypespecifier() {
  return getRuleContext<Mx_starParser::NewtypespecifierContext>(0);
}

Mx_starParser::NewinitializerContext* Mx_starParser::NewexpressionContext::newinitializer() {
  return getRuleContext<Mx_starParser::NewinitializerContext>(0);
}


size_t Mx_starParser::NewexpressionContext::getRuleIndex() const {
  return Mx_starParser::RuleNewexpression;
}

void Mx_starParser::NewexpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNewexpression(this);
}

void Mx_starParser::NewexpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNewexpression(this);
}


antlrcpp::Any Mx_starParser::NewexpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitNewexpression(this);
  else
    return visitor->visitChildren(this);
}

Mx_starParser::NewexpressionContext* Mx_starParser::newexpression() {
  NewexpressionContext *_localctx = _tracker.createInstance<NewexpressionContext>(_ctx, getState());
  enterRule(_localctx, 72, Mx_starParser::RuleNewexpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(423);
    match(Mx_starParser::New);
    setState(424);
    newtypespecifier();
    setState(426);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx)) {
    case 1: {
      setState(425);
      newinitializer();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NewinitializerContext ------------------------------------------------------------------

Mx_starParser::NewinitializerContext::NewinitializerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Mx_starParser::ExpressionContext* Mx_starParser::NewinitializerContext::expression() {
  return getRuleContext<Mx_starParser::ExpressionContext>(0);
}


size_t Mx_starParser::NewinitializerContext::getRuleIndex() const {
  return Mx_starParser::RuleNewinitializer;
}

void Mx_starParser::NewinitializerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNewinitializer(this);
}

void Mx_starParser::NewinitializerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNewinitializer(this);
}


antlrcpp::Any Mx_starParser::NewinitializerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitNewinitializer(this);
  else
    return visitor->visitChildren(this);
}

Mx_starParser::NewinitializerContext* Mx_starParser::newinitializer() {
  NewinitializerContext *_localctx = _tracker.createInstance<NewinitializerContext>(_ctx, getState());
  enterRule(_localctx, 74, Mx_starParser::RuleNewinitializer);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(428);
    match(Mx_starParser::T__2);
    setState(430);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << Mx_starParser::T__2)
      | (1ULL << Mx_starParser::T__13)
      | (1ULL << Mx_starParser::T__17)
      | (1ULL << Mx_starParser::T__18)
      | (1ULL << Mx_starParser::T__30)
      | (1ULL << Mx_starParser::T__31)
      | (1ULL << Mx_starParser::Stringliteral)
      | (1ULL << Mx_starParser::Integerliteral)
      | (1ULL << Mx_starParser::Null)
      | (1ULL << Mx_starParser::True)
      | (1ULL << Mx_starParser::False)
      | (1ULL << Mx_starParser::New)
      | (1ULL << Mx_starParser::This)
      | (1ULL << Mx_starParser::Identifier))) != 0)) {
      setState(429);
      expression();
    }
    setState(432);
    match(Mx_starParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NewtypespecifierContext ------------------------------------------------------------------

Mx_starParser::NewtypespecifierContext::NewtypespecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Mx_starParser::SimpletypespecifierContext* Mx_starParser::NewtypespecifierContext::simpletypespecifier() {
  return getRuleContext<Mx_starParser::SimpletypespecifierContext>(0);
}

Mx_starParser::NewdeclaratorContext* Mx_starParser::NewtypespecifierContext::newdeclarator() {
  return getRuleContext<Mx_starParser::NewdeclaratorContext>(0);
}

Mx_starParser::PointerspecifierContext* Mx_starParser::NewtypespecifierContext::pointerspecifier() {
  return getRuleContext<Mx_starParser::PointerspecifierContext>(0);
}


size_t Mx_starParser::NewtypespecifierContext::getRuleIndex() const {
  return Mx_starParser::RuleNewtypespecifier;
}

void Mx_starParser::NewtypespecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNewtypespecifier(this);
}

void Mx_starParser::NewtypespecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNewtypespecifier(this);
}


antlrcpp::Any Mx_starParser::NewtypespecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitNewtypespecifier(this);
  else
    return visitor->visitChildren(this);
}

Mx_starParser::NewtypespecifierContext* Mx_starParser::newtypespecifier() {
  NewtypespecifierContext *_localctx = _tracker.createInstance<NewtypespecifierContext>(_ctx, getState());
  enterRule(_localctx, 76, Mx_starParser::RuleNewtypespecifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(434);
    simpletypespecifier();
    setState(436);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx)) {
    case 1: {
      setState(435);
      newdeclarator(0);
      break;
    }

    }
    setState(439);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx)) {
    case 1: {
      setState(438);
      pointerspecifier(0);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NewdeclaratorContext ------------------------------------------------------------------

Mx_starParser::NewdeclaratorContext::NewdeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Mx_starParser::ExpressionContext* Mx_starParser::NewdeclaratorContext::expression() {
  return getRuleContext<Mx_starParser::ExpressionContext>(0);
}

Mx_starParser::NewdeclaratorContext* Mx_starParser::NewdeclaratorContext::newdeclarator() {
  return getRuleContext<Mx_starParser::NewdeclaratorContext>(0);
}


size_t Mx_starParser::NewdeclaratorContext::getRuleIndex() const {
  return Mx_starParser::RuleNewdeclarator;
}

void Mx_starParser::NewdeclaratorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNewdeclarator(this);
}

void Mx_starParser::NewdeclaratorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNewdeclarator(this);
}


antlrcpp::Any Mx_starParser::NewdeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitNewdeclarator(this);
  else
    return visitor->visitChildren(this);
}


Mx_starParser::NewdeclaratorContext* Mx_starParser::newdeclarator() {
   return newdeclarator(0);
}

Mx_starParser::NewdeclaratorContext* Mx_starParser::newdeclarator(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Mx_starParser::NewdeclaratorContext *_localctx = _tracker.createInstance<NewdeclaratorContext>(_ctx, parentState);
  Mx_starParser::NewdeclaratorContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 78;
  enterRecursionRule(_localctx, 78, Mx_starParser::RuleNewdeclarator, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(442);
    match(Mx_starParser::T__19);
    setState(443);
    expression();
    setState(444);
    match(Mx_starParser::T__20);
    _ctx->stop = _input->LT(-1);
    setState(453);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<NewdeclaratorContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleNewdeclarator);
        setState(446);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(447);
        match(Mx_starParser::T__19);
        setState(448);
        expression();
        setState(449);
        match(Mx_starParser::T__20); 
      }
      setState(455);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- PointerspecifierContext ------------------------------------------------------------------

Mx_starParser::PointerspecifierContext::PointerspecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Mx_starParser::PointerspecifierContext* Mx_starParser::PointerspecifierContext::pointerspecifier() {
  return getRuleContext<Mx_starParser::PointerspecifierContext>(0);
}


size_t Mx_starParser::PointerspecifierContext::getRuleIndex() const {
  return Mx_starParser::RulePointerspecifier;
}

void Mx_starParser::PointerspecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPointerspecifier(this);
}

void Mx_starParser::PointerspecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPointerspecifier(this);
}


antlrcpp::Any Mx_starParser::PointerspecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitPointerspecifier(this);
  else
    return visitor->visitChildren(this);
}


Mx_starParser::PointerspecifierContext* Mx_starParser::pointerspecifier() {
   return pointerspecifier(0);
}

Mx_starParser::PointerspecifierContext* Mx_starParser::pointerspecifier(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Mx_starParser::PointerspecifierContext *_localctx = _tracker.createInstance<PointerspecifierContext>(_ctx, parentState);
  Mx_starParser::PointerspecifierContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 80;
  enterRecursionRule(_localctx, 80, Mx_starParser::RulePointerspecifier, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(457);
    match(Mx_starParser::T__19);
    setState(458);
    match(Mx_starParser::T__20);
    _ctx->stop = _input->LT(-1);
    setState(465);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<PointerspecifierContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RulePointerspecifier);
        setState(460);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(461);
        match(Mx_starParser::T__19);
        setState(462);
        match(Mx_starParser::T__20); 
      }
      setState(467);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- PostfixexpressionContext ------------------------------------------------------------------

Mx_starParser::PostfixexpressionContext::PostfixexpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Mx_starParser::PrimaryexpressionContext* Mx_starParser::PostfixexpressionContext::primaryexpression() {
  return getRuleContext<Mx_starParser::PrimaryexpressionContext>(0);
}

Mx_starParser::PostfixexpressionContext* Mx_starParser::PostfixexpressionContext::postfixexpression() {
  return getRuleContext<Mx_starParser::PostfixexpressionContext>(0);
}

Mx_starParser::ExpressionContext* Mx_starParser::PostfixexpressionContext::expression() {
  return getRuleContext<Mx_starParser::ExpressionContext>(0);
}

Mx_starParser::ExpressionlistContext* Mx_starParser::PostfixexpressionContext::expressionlist() {
  return getRuleContext<Mx_starParser::ExpressionlistContext>(0);
}


size_t Mx_starParser::PostfixexpressionContext::getRuleIndex() const {
  return Mx_starParser::RulePostfixexpression;
}

void Mx_starParser::PostfixexpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPostfixexpression(this);
}

void Mx_starParser::PostfixexpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPostfixexpression(this);
}


antlrcpp::Any Mx_starParser::PostfixexpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitPostfixexpression(this);
  else
    return visitor->visitChildren(this);
}


Mx_starParser::PostfixexpressionContext* Mx_starParser::postfixexpression() {
   return postfixexpression(0);
}

Mx_starParser::PostfixexpressionContext* Mx_starParser::postfixexpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Mx_starParser::PostfixexpressionContext *_localctx = _tracker.createInstance<PostfixexpressionContext>(_ctx, parentState);
  Mx_starParser::PostfixexpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 82;
  enterRecursionRule(_localctx, 82, Mx_starParser::RulePostfixexpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(469);
    primaryexpression();
    _ctx->stop = _input->LT(-1);
    setState(491);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(489);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<PostfixexpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixexpression);
          setState(471);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(472);
          match(Mx_starParser::T__17);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<PostfixexpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixexpression);
          setState(473);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(474);
          match(Mx_starParser::T__18);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<PostfixexpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixexpression);
          setState(475);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(476);
          match(Mx_starParser::T__19);
          setState(477);
          expression();
          setState(478);
          match(Mx_starParser::T__20);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<PostfixexpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixexpression);
          setState(480);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(481);
          match(Mx_starParser::T__2);
          setState(483);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << Mx_starParser::T__2)
            | (1ULL << Mx_starParser::T__13)
            | (1ULL << Mx_starParser::T__17)
            | (1ULL << Mx_starParser::T__18)
            | (1ULL << Mx_starParser::T__30)
            | (1ULL << Mx_starParser::T__31)
            | (1ULL << Mx_starParser::Stringliteral)
            | (1ULL << Mx_starParser::Integerliteral)
            | (1ULL << Mx_starParser::Null)
            | (1ULL << Mx_starParser::True)
            | (1ULL << Mx_starParser::False)
            | (1ULL << Mx_starParser::New)
            | (1ULL << Mx_starParser::This)
            | (1ULL << Mx_starParser::Identifier))) != 0)) {
            setState(482);
            expressionlist(0);
          }
          setState(485);
          match(Mx_starParser::T__3);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<PostfixexpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixexpression);
          setState(486);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(487);
          match(Mx_starParser::T__21);
          setState(488);
          expression();
          break;
        }

        } 
      }
      setState(493);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- PrimaryexpressionContext ------------------------------------------------------------------

Mx_starParser::PrimaryexpressionContext::PrimaryexpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Mx_starParser::LiteralContext* Mx_starParser::PrimaryexpressionContext::literal() {
  return getRuleContext<Mx_starParser::LiteralContext>(0);
}

tree::TerminalNode* Mx_starParser::PrimaryexpressionContext::This() {
  return getToken(Mx_starParser::This, 0);
}

tree::TerminalNode* Mx_starParser::PrimaryexpressionContext::Identifier() {
  return getToken(Mx_starParser::Identifier, 0);
}

Mx_starParser::ExpressionContext* Mx_starParser::PrimaryexpressionContext::expression() {
  return getRuleContext<Mx_starParser::ExpressionContext>(0);
}


size_t Mx_starParser::PrimaryexpressionContext::getRuleIndex() const {
  return Mx_starParser::RulePrimaryexpression;
}

void Mx_starParser::PrimaryexpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimaryexpression(this);
}

void Mx_starParser::PrimaryexpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimaryexpression(this);
}


antlrcpp::Any Mx_starParser::PrimaryexpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitPrimaryexpression(this);
  else
    return visitor->visitChildren(this);
}

Mx_starParser::PrimaryexpressionContext* Mx_starParser::primaryexpression() {
  PrimaryexpressionContext *_localctx = _tracker.createInstance<PrimaryexpressionContext>(_ctx, getState());
  enterRule(_localctx, 84, Mx_starParser::RulePrimaryexpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(501);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Mx_starParser::Stringliteral:
      case Mx_starParser::Integerliteral:
      case Mx_starParser::Null:
      case Mx_starParser::True:
      case Mx_starParser::False: {
        enterOuterAlt(_localctx, 1);
        setState(494);
        literal();
        break;
      }

      case Mx_starParser::This: {
        enterOuterAlt(_localctx, 2);
        setState(495);
        match(Mx_starParser::This);
        break;
      }

      case Mx_starParser::Identifier: {
        enterOuterAlt(_localctx, 3);
        setState(496);
        match(Mx_starParser::Identifier);
        break;
      }

      case Mx_starParser::T__2: {
        enterOuterAlt(_localctx, 4);
        setState(497);
        match(Mx_starParser::T__2);
        setState(498);
        expression();
        setState(499);
        match(Mx_starParser::T__3);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EqualityoperatorContext ------------------------------------------------------------------

Mx_starParser::EqualityoperatorContext::EqualityoperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t Mx_starParser::EqualityoperatorContext::getRuleIndex() const {
  return Mx_starParser::RuleEqualityoperator;
}

void Mx_starParser::EqualityoperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqualityoperator(this);
}

void Mx_starParser::EqualityoperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqualityoperator(this);
}


antlrcpp::Any Mx_starParser::EqualityoperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitEqualityoperator(this);
  else
    return visitor->visitChildren(this);
}

Mx_starParser::EqualityoperatorContext* Mx_starParser::equalityoperator() {
  EqualityoperatorContext *_localctx = _tracker.createInstance<EqualityoperatorContext>(_ctx, getState());
  enterRule(_localctx, 86, Mx_starParser::RuleEqualityoperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(503);
    _la = _input->LA(1);
    if (!(_la == Mx_starParser::T__22

    || _la == Mx_starParser::T__23)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelationoperatorContext ------------------------------------------------------------------

Mx_starParser::RelationoperatorContext::RelationoperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t Mx_starParser::RelationoperatorContext::getRuleIndex() const {
  return Mx_starParser::RuleRelationoperator;
}

void Mx_starParser::RelationoperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelationoperator(this);
}

void Mx_starParser::RelationoperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelationoperator(this);
}


antlrcpp::Any Mx_starParser::RelationoperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitRelationoperator(this);
  else
    return visitor->visitChildren(this);
}

Mx_starParser::RelationoperatorContext* Mx_starParser::relationoperator() {
  RelationoperatorContext *_localctx = _tracker.createInstance<RelationoperatorContext>(_ctx, getState());
  enterRule(_localctx, 88, Mx_starParser::RuleRelationoperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(505);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << Mx_starParser::T__24)
      | (1ULL << Mx_starParser::T__25)
      | (1ULL << Mx_starParser::T__26)
      | (1ULL << Mx_starParser::T__27))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ShiftoperatorContext ------------------------------------------------------------------

Mx_starParser::ShiftoperatorContext::ShiftoperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t Mx_starParser::ShiftoperatorContext::getRuleIndex() const {
  return Mx_starParser::RuleShiftoperator;
}

void Mx_starParser::ShiftoperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShiftoperator(this);
}

void Mx_starParser::ShiftoperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShiftoperator(this);
}


antlrcpp::Any Mx_starParser::ShiftoperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitShiftoperator(this);
  else
    return visitor->visitChildren(this);
}

Mx_starParser::ShiftoperatorContext* Mx_starParser::shiftoperator() {
  ShiftoperatorContext *_localctx = _tracker.createInstance<ShiftoperatorContext>(_ctx, getState());
  enterRule(_localctx, 90, Mx_starParser::RuleShiftoperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(507);
    _la = _input->LA(1);
    if (!(_la == Mx_starParser::T__28

    || _la == Mx_starParser::T__29)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryoperatorContext ------------------------------------------------------------------

Mx_starParser::UnaryoperatorContext::UnaryoperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t Mx_starParser::UnaryoperatorContext::getRuleIndex() const {
  return Mx_starParser::RuleUnaryoperator;
}

void Mx_starParser::UnaryoperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryoperator(this);
}

void Mx_starParser::UnaryoperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryoperator(this);
}


antlrcpp::Any Mx_starParser::UnaryoperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitUnaryoperator(this);
  else
    return visitor->visitChildren(this);
}

Mx_starParser::UnaryoperatorContext* Mx_starParser::unaryoperator() {
  UnaryoperatorContext *_localctx = _tracker.createInstance<UnaryoperatorContext>(_ctx, getState());
  enterRule(_localctx, 92, Mx_starParser::RuleUnaryoperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(509);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << Mx_starParser::T__13)
      | (1ULL << Mx_starParser::T__30)
      | (1ULL << Mx_starParser::T__31))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypespecifierContext ------------------------------------------------------------------

Mx_starParser::TypespecifierContext::TypespecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Mx_starParser::SimpletypespecifierContext* Mx_starParser::TypespecifierContext::simpletypespecifier() {
  return getRuleContext<Mx_starParser::SimpletypespecifierContext>(0);
}

Mx_starParser::TypespecifierContext* Mx_starParser::TypespecifierContext::typespecifier() {
  return getRuleContext<Mx_starParser::TypespecifierContext>(0);
}


size_t Mx_starParser::TypespecifierContext::getRuleIndex() const {
  return Mx_starParser::RuleTypespecifier;
}

void Mx_starParser::TypespecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypespecifier(this);
}

void Mx_starParser::TypespecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypespecifier(this);
}


antlrcpp::Any Mx_starParser::TypespecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitTypespecifier(this);
  else
    return visitor->visitChildren(this);
}


Mx_starParser::TypespecifierContext* Mx_starParser::typespecifier() {
   return typespecifier(0);
}

Mx_starParser::TypespecifierContext* Mx_starParser::typespecifier(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Mx_starParser::TypespecifierContext *_localctx = _tracker.createInstance<TypespecifierContext>(_ctx, parentState);
  Mx_starParser::TypespecifierContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 94;
  enterRecursionRule(_localctx, 94, Mx_starParser::RuleTypespecifier, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(512);
    simpletypespecifier();
    _ctx->stop = _input->LT(-1);
    setState(519);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TypespecifierContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleTypespecifier);
        setState(514);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(515);
        match(Mx_starParser::T__19);
        setState(516);
        match(Mx_starParser::T__20); 
      }
      setState(521);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- SimpletypespecifierContext ------------------------------------------------------------------

Mx_starParser::SimpletypespecifierContext::SimpletypespecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Mx_starParser::SimpletypespecifierContext::Bool() {
  return getToken(Mx_starParser::Bool, 0);
}

tree::TerminalNode* Mx_starParser::SimpletypespecifierContext::Int() {
  return getToken(Mx_starParser::Int, 0);
}

tree::TerminalNode* Mx_starParser::SimpletypespecifierContext::Void() {
  return getToken(Mx_starParser::Void, 0);
}

tree::TerminalNode* Mx_starParser::SimpletypespecifierContext::String() {
  return getToken(Mx_starParser::String, 0);
}

tree::TerminalNode* Mx_starParser::SimpletypespecifierContext::Identifier() {
  return getToken(Mx_starParser::Identifier, 0);
}


size_t Mx_starParser::SimpletypespecifierContext::getRuleIndex() const {
  return Mx_starParser::RuleSimpletypespecifier;
}

void Mx_starParser::SimpletypespecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimpletypespecifier(this);
}

void Mx_starParser::SimpletypespecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimpletypespecifier(this);
}


antlrcpp::Any Mx_starParser::SimpletypespecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitSimpletypespecifier(this);
  else
    return visitor->visitChildren(this);
}

Mx_starParser::SimpletypespecifierContext* Mx_starParser::simpletypespecifier() {
  SimpletypespecifierContext *_localctx = _tracker.createInstance<SimpletypespecifierContext>(_ctx, getState());
  enterRule(_localctx, 96, Mx_starParser::RuleSimpletypespecifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(522);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << Mx_starParser::Int)
      | (1ULL << Mx_starParser::Bool)
      | (1ULL << Mx_starParser::String)
      | (1ULL << Mx_starParser::Void)
      | (1ULL << Mx_starParser::Identifier))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

Mx_starParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Mx_starParser::BooleanliteralContext* Mx_starParser::LiteralContext::booleanliteral() {
  return getRuleContext<Mx_starParser::BooleanliteralContext>(0);
}

tree::TerminalNode* Mx_starParser::LiteralContext::Integerliteral() {
  return getToken(Mx_starParser::Integerliteral, 0);
}

tree::TerminalNode* Mx_starParser::LiteralContext::Stringliteral() {
  return getToken(Mx_starParser::Stringliteral, 0);
}

tree::TerminalNode* Mx_starParser::LiteralContext::Null() {
  return getToken(Mx_starParser::Null, 0);
}


size_t Mx_starParser::LiteralContext::getRuleIndex() const {
  return Mx_starParser::RuleLiteral;
}

void Mx_starParser::LiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral(this);
}

void Mx_starParser::LiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral(this);
}


antlrcpp::Any Mx_starParser::LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitLiteral(this);
  else
    return visitor->visitChildren(this);
}

Mx_starParser::LiteralContext* Mx_starParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 98, Mx_starParser::RuleLiteral);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(528);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Mx_starParser::True:
      case Mx_starParser::False: {
        enterOuterAlt(_localctx, 1);
        setState(524);
        booleanliteral();
        break;
      }

      case Mx_starParser::Integerliteral: {
        enterOuterAlt(_localctx, 2);
        setState(525);
        match(Mx_starParser::Integerliteral);
        break;
      }

      case Mx_starParser::Stringliteral: {
        enterOuterAlt(_localctx, 3);
        setState(526);
        match(Mx_starParser::Stringliteral);
        break;
      }

      case Mx_starParser::Null: {
        enterOuterAlt(_localctx, 4);
        setState(527);
        match(Mx_starParser::Null);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BooleanliteralContext ------------------------------------------------------------------

Mx_starParser::BooleanliteralContext::BooleanliteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Mx_starParser::BooleanliteralContext::True() {
  return getToken(Mx_starParser::True, 0);
}

tree::TerminalNode* Mx_starParser::BooleanliteralContext::False() {
  return getToken(Mx_starParser::False, 0);
}


size_t Mx_starParser::BooleanliteralContext::getRuleIndex() const {
  return Mx_starParser::RuleBooleanliteral;
}

void Mx_starParser::BooleanliteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBooleanliteral(this);
}

void Mx_starParser::BooleanliteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Mx_starListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBooleanliteral(this);
}


antlrcpp::Any Mx_starParser::BooleanliteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Mx_starVisitor*>(visitor))
    return parserVisitor->visitBooleanliteral(this);
  else
    return visitor->visitChildren(this);
}

Mx_starParser::BooleanliteralContext* Mx_starParser::booleanliteral() {
  BooleanliteralContext *_localctx = _tracker.createInstance<BooleanliteralContext>(_ctx, getState());
  enterRule(_localctx, 100, Mx_starParser::RuleBooleanliteral);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(530);
    _la = _input->LA(1);
    if (!(_la == Mx_starParser::True

    || _la == Mx_starParser::False)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool Mx_starParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return declarationlistSempred(dynamic_cast<DeclarationlistContext *>(context), predicateIndex);
    case 4: return memberdeclarationlistSempred(dynamic_cast<MemberdeclarationlistContext *>(context), predicateIndex);
    case 7: return parameterlistSempred(dynamic_cast<ParameterlistContext *>(context), predicateIndex);
    case 11: return statementlistSempred(dynamic_cast<StatementlistContext *>(context), predicateIndex);
    case 13: return initdeclaratorlistSempred(dynamic_cast<InitdeclaratorlistContext *>(context), predicateIndex);
    case 22: return expressionlistSempred(dynamic_cast<ExpressionlistContext *>(context), predicateIndex);
    case 25: return logicalorexpressionSempred(dynamic_cast<LogicalorexpressionContext *>(context), predicateIndex);
    case 26: return logicalandexpressionSempred(dynamic_cast<LogicalandexpressionContext *>(context), predicateIndex);
    case 27: return orexpressionSempred(dynamic_cast<OrexpressionContext *>(context), predicateIndex);
    case 28: return xorexpressionSempred(dynamic_cast<XorexpressionContext *>(context), predicateIndex);
    case 29: return andexpressionSempred(dynamic_cast<AndexpressionContext *>(context), predicateIndex);
    case 30: return equalityexpressionSempred(dynamic_cast<EqualityexpressionContext *>(context), predicateIndex);
    case 31: return relationalexpressionSempred(dynamic_cast<RelationalexpressionContext *>(context), predicateIndex);
    case 32: return shiftexpressionSempred(dynamic_cast<ShiftexpressionContext *>(context), predicateIndex);
    case 33: return additiveexpressionSempred(dynamic_cast<AdditiveexpressionContext *>(context), predicateIndex);
    case 34: return multiplicativeexpressionSempred(dynamic_cast<MultiplicativeexpressionContext *>(context), predicateIndex);
    case 39: return newdeclaratorSempred(dynamic_cast<NewdeclaratorContext *>(context), predicateIndex);
    case 40: return pointerspecifierSempred(dynamic_cast<PointerspecifierContext *>(context), predicateIndex);
    case 41: return postfixexpressionSempred(dynamic_cast<PostfixexpressionContext *>(context), predicateIndex);
    case 47: return typespecifierSempred(dynamic_cast<TypespecifierContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool Mx_starParser::declarationlistSempred(DeclarationlistContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Mx_starParser::memberdeclarationlistSempred(MemberdeclarationlistContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Mx_starParser::parameterlistSempred(ParameterlistContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Mx_starParser::statementlistSempred(StatementlistContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Mx_starParser::initdeclaratorlistSempred(InitdeclaratorlistContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Mx_starParser::expressionlistSempred(ExpressionlistContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Mx_starParser::logicalorexpressionSempred(LogicalorexpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 6: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Mx_starParser::logicalandexpressionSempred(LogicalandexpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 7: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Mx_starParser::orexpressionSempred(OrexpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 8: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Mx_starParser::xorexpressionSempred(XorexpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 9: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Mx_starParser::andexpressionSempred(AndexpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 10: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Mx_starParser::equalityexpressionSempred(EqualityexpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 11: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Mx_starParser::relationalexpressionSempred(RelationalexpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 12: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Mx_starParser::shiftexpressionSempred(ShiftexpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 13: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Mx_starParser::additiveexpressionSempred(AdditiveexpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 14: return precpred(_ctx, 2);
    case 15: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Mx_starParser::multiplicativeexpressionSempred(MultiplicativeexpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 16: return precpred(_ctx, 3);
    case 17: return precpred(_ctx, 2);
    case 18: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Mx_starParser::newdeclaratorSempred(NewdeclaratorContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 19: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Mx_starParser::pointerspecifierSempred(PointerspecifierContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 20: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Mx_starParser::postfixexpressionSempred(PostfixexpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 21: return precpred(_ctx, 5);
    case 22: return precpred(_ctx, 4);
    case 23: return precpred(_ctx, 3);
    case 24: return precpred(_ctx, 2);
    case 25: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Mx_starParser::typespecifierSempred(TypespecifierContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 26: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> Mx_starParser::_decisionToDFA;
atn::PredictionContextCache Mx_starParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN Mx_starParser::_atn;
std::vector<uint16_t> Mx_starParser::_serializedATN;

std::vector<std::string> Mx_starParser::_ruleNames = {
  "file", "declarationlist", "declaration", "classdeclaration", "memberdeclarationlist", 
  "memberdeclaration", "functiondeclaration", "parameterlist", "parameter", 
  "statement", "block", "statementlist", "declarationstatement", "initdeclaratorlist", 
  "initdeclarator", "declarator", "initializer", "ifstatement", "iterationstatement", 
  "jumpstatement", "expressionstatement", "emptystatement", "expressionlist", 
  "expression", "assignmentexpression", "logicalorexpression", "logicalandexpression", 
  "orexpression", "xorexpression", "andexpression", "equalityexpression", 
  "relationalexpression", "shiftexpression", "additiveexpression", "multiplicativeexpression", 
  "unaryexpression", "newexpression", "newinitializer", "newtypespecifier", 
  "newdeclarator", "pointerspecifier", "postfixexpression", "primaryexpression", 
  "equalityoperator", "relationoperator", "shiftoperator", "unaryoperator", 
  "typespecifier", "simpletypespecifier", "literal", "booleanliteral"
};

std::vector<std::string> Mx_starParser::_literalNames = {
  "", "'{'", "'}'", "'('", "')'", "','", "';'", "'='", "'||'", "'&&'", "'|'", 
  "'^'", "'&'", "'+'", "'-'", "'*'", "'/'", "'%'", "'++'", "'--'", "'['", 
  "']'", "'.'", "'=='", "'!='", "'<'", "'<='", "'>'", "'>='", "'<<'", "'>>'", 
  "'~'", "'!'", "", "", "'int'", "'bool'", "'string'", "'null'", "'void'", 
  "'true'", "'false'", "'if'", "'else'", "'for'", "'while'", "'break'", 
  "'continue'", "'return'", "'new'", "'class'", "'this'"
};

std::vector<std::string> Mx_starParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "Stringliteral", 
  "Integerliteral", "Int", "Bool", "String", "Null", "Void", "True", "False", 
  "If", "Else", "For", "While", "Break", "Continue", "Return", "New", "Class", 
  "This", "Identifier", "Whitespace", "Newline", "BlockComment", "LineComment"
};

dfa::Vocabulary Mx_starParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> Mx_starParser::_tokenNames;

Mx_starParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x3a, 0x217, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 0x9, 
    0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x70, 0xa, 
    0x3, 0xc, 0x3, 0xe, 0x3, 0x73, 0xb, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x5, 0x4, 0x78, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 
    0x5, 0x7e, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x87, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x8a, 
    0xb, 0x6, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x8e, 0xa, 0x7, 0x3, 0x8, 0x5, 
    0x8, 0x91, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x96, 0xa, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0xa1, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 
    0xa4, 0xb, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xb0, 0xa, 0xb, 
    0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xb4, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0xbd, 0xa, 0xd, 
    0xc, 0xd, 0xe, 0xd, 0xc0, 0xb, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 
    0xf, 0xcc, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0xcf, 0xb, 0xf, 0x3, 0x10, 
    0x3, 0x10, 0x5, 0x10, 0xd3, 0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0xe8, 0xa, 0x13, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x5, 0x14, 0xf3, 0xa, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 
    0x14, 0xf7, 0xa, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0xfb, 0xa, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0xff, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0x107, 0xa, 0x15, 
    0x3, 0x15, 0x5, 0x15, 0x10a, 0xa, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 
    0x18, 0x3, 0x18, 0x7, 0x18, 0x117, 0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 
    0x11a, 0xb, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
    0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x123, 0xa, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x7, 0x1b, 0x12b, 0xa, 0x1b, 
    0xc, 0x1b, 0xe, 0x1b, 0x12e, 0xb, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x7, 0x1c, 0x136, 0xa, 0x1c, 0xc, 0x1c, 
    0xe, 0x1c, 0x139, 0xb, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1d, 0x3, 0x1d, 0x7, 0x1d, 0x141, 0xa, 0x1d, 0xc, 0x1d, 0xe, 0x1d, 
    0x144, 0xb, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1e, 0x7, 0x1e, 0x14c, 0xa, 0x1e, 0xc, 0x1e, 0xe, 0x1e, 0x14f, 
    0xb, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 
    0x1f, 0x7, 0x1f, 0x157, 0xa, 0x1f, 0xc, 0x1f, 0xe, 0x1f, 0x15a, 0xb, 
    0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
    0x3, 0x20, 0x7, 0x20, 0x163, 0xa, 0x20, 0xc, 0x20, 0xe, 0x20, 0x166, 
    0xb, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 
    0x21, 0x3, 0x21, 0x7, 0x21, 0x16f, 0xa, 0x21, 0xc, 0x21, 0xe, 0x21, 
    0x172, 0xb, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 
    0x3, 0x22, 0x3, 0x22, 0x7, 0x22, 0x17b, 0xa, 0x22, 0xc, 0x22, 0xe, 0x22, 
    0x17e, 0xb, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 
    0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x7, 0x23, 0x189, 0xa, 0x23, 
    0xc, 0x23, 0xe, 0x23, 0x18c, 0xb, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 
    0x24, 0x3, 0x24, 0x3, 0x24, 0x7, 0x24, 0x19a, 0xa, 0x24, 0xc, 0x24, 
    0xe, 0x24, 0x19d, 0xb, 0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 
    0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x1a8, 
    0xa, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x5, 0x26, 0x1ad, 0xa, 0x26, 
    0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x1b1, 0xa, 0x27, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 0x1b7, 0xa, 0x28, 0x3, 0x28, 0x5, 0x28, 
    0x1ba, 0xa, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 
    0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x7, 0x29, 0x1c6, 
    0xa, 0x29, 0xc, 0x29, 0xe, 0x29, 0x1c9, 0xb, 0x29, 0x3, 0x2a, 0x3, 0x2a, 
    0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x7, 0x2a, 0x1d2, 
    0xa, 0x2a, 0xc, 0x2a, 0xe, 0x2a, 0x1d5, 0xb, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 
    0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 
    0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 
    0x5, 0x2b, 0x1e6, 0xa, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 
    0x7, 0x2b, 0x1ec, 0xa, 0x2b, 0xc, 0x2b, 0xe, 0x2b, 0x1ef, 0xb, 0x2b, 
    0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 
    0x2c, 0x5, 0x2c, 0x1f8, 0xa, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2e, 
    0x3, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x3, 0x31, 0x3, 
    0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x7, 0x31, 0x208, 
    0xa, 0x31, 0xc, 0x31, 0xe, 0x31, 0x20b, 0xb, 0x31, 0x3, 0x32, 0x3, 0x32, 
    0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x213, 0xa, 0x33, 
    0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x2, 0x16, 0x4, 0xa, 0x10, 0x18, 0x1c, 
    0x2e, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x50, 
    0x52, 0x54, 0x60, 0x35, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 
    0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 
    0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 
    0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 
    0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x2, 0x8, 0x3, 0x2, 0x19, 0x1a, 
    0x3, 0x2, 0x1b, 0x1e, 0x3, 0x2, 0x1f, 0x20, 0x4, 0x2, 0x10, 0x10, 0x21, 
    0x22, 0x5, 0x2, 0x25, 0x27, 0x29, 0x29, 0x36, 0x36, 0x3, 0x2, 0x2a, 
    0x2b, 0x2, 0x224, 0x2, 0x68, 0x3, 0x2, 0x2, 0x2, 0x4, 0x6a, 0x3, 0x2, 
    0x2, 0x2, 0x6, 0x77, 0x3, 0x2, 0x2, 0x2, 0x8, 0x79, 0x3, 0x2, 0x2, 0x2, 
    0xa, 0x81, 0x3, 0x2, 0x2, 0x2, 0xc, 0x8d, 0x3, 0x2, 0x2, 0x2, 0xe, 0x90, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x12, 0xa5, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0xaf, 0x3, 0x2, 0x2, 0x2, 0x16, 0xb1, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0xb7, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xc1, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0xc5, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xd0, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0xd4, 0x3, 0x2, 0x2, 0x2, 0x22, 0xd6, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0xe7, 0x3, 0x2, 0x2, 0x2, 0x26, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x28, 0x109, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x10e, 0x3, 
    0x2, 0x2, 0x2, 0x2e, 0x110, 0x3, 0x2, 0x2, 0x2, 0x30, 0x11b, 0x3, 0x2, 
    0x2, 0x2, 0x32, 0x122, 0x3, 0x2, 0x2, 0x2, 0x34, 0x124, 0x3, 0x2, 0x2, 
    0x2, 0x36, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x38, 0x13a, 0x3, 0x2, 0x2, 0x2, 
    0x3a, 0x145, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x150, 0x3, 0x2, 0x2, 0x2, 0x3e, 
    0x15b, 0x3, 0x2, 0x2, 0x2, 0x40, 0x167, 0x3, 0x2, 0x2, 0x2, 0x42, 0x173, 
    0x3, 0x2, 0x2, 0x2, 0x44, 0x17f, 0x3, 0x2, 0x2, 0x2, 0x46, 0x18d, 0x3, 
    0x2, 0x2, 0x2, 0x48, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x1a9, 0x3, 0x2, 
    0x2, 0x2, 0x4c, 0x1ae, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x1b4, 0x3, 0x2, 0x2, 
    0x2, 0x50, 0x1bb, 0x3, 0x2, 0x2, 0x2, 0x52, 0x1ca, 0x3, 0x2, 0x2, 0x2, 
    0x54, 0x1d6, 0x3, 0x2, 0x2, 0x2, 0x56, 0x1f7, 0x3, 0x2, 0x2, 0x2, 0x58, 
    0x1f9, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x1fb, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x1fd, 
    0x3, 0x2, 0x2, 0x2, 0x5e, 0x1ff, 0x3, 0x2, 0x2, 0x2, 0x60, 0x201, 0x3, 
    0x2, 0x2, 0x2, 0x62, 0x20c, 0x3, 0x2, 0x2, 0x2, 0x64, 0x212, 0x3, 0x2, 
    0x2, 0x2, 0x66, 0x214, 0x3, 0x2, 0x2, 0x2, 0x68, 0x69, 0x5, 0x4, 0x3, 
    0x2, 0x69, 0x3, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 0x8, 0x3, 0x1, 0x2, 
    0x6b, 0x6c, 0x5, 0x6, 0x4, 0x2, 0x6c, 0x71, 0x3, 0x2, 0x2, 0x2, 0x6d, 
    0x6e, 0xc, 0x3, 0x2, 0x2, 0x6e, 0x70, 0x5, 0x6, 0x4, 0x2, 0x6f, 0x6d, 
    0x3, 0x2, 0x2, 0x2, 0x70, 0x73, 0x3, 0x2, 0x2, 0x2, 0x71, 0x6f, 0x3, 
    0x2, 0x2, 0x2, 0x71, 0x72, 0x3, 0x2, 0x2, 0x2, 0x72, 0x5, 0x3, 0x2, 
    0x2, 0x2, 0x73, 0x71, 0x3, 0x2, 0x2, 0x2, 0x74, 0x78, 0x5, 0x8, 0x5, 
    0x2, 0x75, 0x78, 0x5, 0xe, 0x8, 0x2, 0x76, 0x78, 0x5, 0x1a, 0xe, 0x2, 
    0x77, 0x74, 0x3, 0x2, 0x2, 0x2, 0x77, 0x75, 0x3, 0x2, 0x2, 0x2, 0x77, 
    0x76, 0x3, 0x2, 0x2, 0x2, 0x78, 0x7, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7a, 
    0x7, 0x34, 0x2, 0x2, 0x7a, 0x7b, 0x7, 0x36, 0x2, 0x2, 0x7b, 0x7d, 0x7, 
    0x3, 0x2, 0x2, 0x7c, 0x7e, 0x5, 0xa, 0x6, 0x2, 0x7d, 0x7c, 0x3, 0x2, 
    0x2, 0x2, 0x7d, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7f, 0x3, 0x2, 0x2, 
    0x2, 0x7f, 0x80, 0x7, 0x4, 0x2, 0x2, 0x80, 0x9, 0x3, 0x2, 0x2, 0x2, 
    0x81, 0x82, 0x8, 0x6, 0x1, 0x2, 0x82, 0x83, 0x5, 0xc, 0x7, 0x2, 0x83, 
    0x88, 0x3, 0x2, 0x2, 0x2, 0x84, 0x85, 0xc, 0x3, 0x2, 0x2, 0x85, 0x87, 
    0x5, 0xc, 0x7, 0x2, 0x86, 0x84, 0x3, 0x2, 0x2, 0x2, 0x87, 0x8a, 0x3, 
    0x2, 0x2, 0x2, 0x88, 0x86, 0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 0x3, 0x2, 
    0x2, 0x2, 0x89, 0xb, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x88, 0x3, 0x2, 0x2, 
    0x2, 0x8b, 0x8e, 0x5, 0x1a, 0xe, 0x2, 0x8c, 0x8e, 0x5, 0xe, 0x8, 0x2, 
    0x8d, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8e, 
    0xd, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x91, 0x5, 0x60, 0x31, 0x2, 0x90, 0x8f, 
    0x3, 0x2, 0x2, 0x2, 0x90, 0x91, 0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 0x3, 
    0x2, 0x2, 0x2, 0x92, 0x93, 0x7, 0x36, 0x2, 0x2, 0x93, 0x95, 0x7, 0x5, 
    0x2, 0x2, 0x94, 0x96, 0x5, 0x10, 0x9, 0x2, 0x95, 0x94, 0x3, 0x2, 0x2, 
    0x2, 0x95, 0x96, 0x3, 0x2, 0x2, 0x2, 0x96, 0x97, 0x3, 0x2, 0x2, 0x2, 
    0x97, 0x98, 0x7, 0x6, 0x2, 0x2, 0x98, 0x99, 0x5, 0x16, 0xc, 0x2, 0x99, 
    0xf, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9b, 0x8, 0x9, 0x1, 0x2, 0x9b, 0x9c, 
    0x5, 0x12, 0xa, 0x2, 0x9c, 0xa2, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9e, 0xc, 
    0x3, 0x2, 0x2, 0x9e, 0x9f, 0x7, 0x7, 0x2, 0x2, 0x9f, 0xa1, 0x5, 0x12, 
    0xa, 0x2, 0xa0, 0x9d, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa4, 0x3, 0x2, 0x2, 
    0x2, 0xa2, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa3, 0x3, 0x2, 0x2, 0x2, 
    0xa3, 0x11, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa5, 
    0xa6, 0x5, 0x60, 0x31, 0x2, 0xa6, 0xa7, 0x5, 0x1e, 0x10, 0x2, 0xa7, 
    0x13, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xb0, 0x5, 0x1a, 0xe, 0x2, 0xa9, 0xb0, 
    0x5, 0x24, 0x13, 0x2, 0xaa, 0xb0, 0x5, 0x26, 0x14, 0x2, 0xab, 0xb0, 
    0x5, 0x28, 0x15, 0x2, 0xac, 0xb0, 0x5, 0x2a, 0x16, 0x2, 0xad, 0xb0, 
    0x5, 0x2c, 0x17, 0x2, 0xae, 0xb0, 0x5, 0x16, 0xc, 0x2, 0xaf, 0xa8, 0x3, 
    0x2, 0x2, 0x2, 0xaf, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xaa, 0x3, 0x2, 
    0x2, 0x2, 0xaf, 0xab, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xac, 0x3, 0x2, 0x2, 
    0x2, 0xaf, 0xad, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xae, 0x3, 0x2, 0x2, 0x2, 
    0xb0, 0x15, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb3, 0x7, 0x3, 0x2, 0x2, 0xb2, 
    0xb4, 0x5, 0x18, 0xd, 0x2, 0xb3, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb4, 
    0x3, 0x2, 0x2, 0x2, 0xb4, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb6, 0x7, 
    0x4, 0x2, 0x2, 0xb6, 0x17, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb8, 0x8, 0xd, 
    0x1, 0x2, 0xb8, 0xb9, 0x5, 0x14, 0xb, 0x2, 0xb9, 0xbe, 0x3, 0x2, 0x2, 
    0x2, 0xba, 0xbb, 0xc, 0x3, 0x2, 0x2, 0xbb, 0xbd, 0x5, 0x14, 0xb, 0x2, 
    0xbc, 0xba, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xbe, 
    0xbc, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xbf, 0x19, 
    0x3, 0x2, 0x2, 0x2, 0xc0, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 0x5, 
    0x60, 0x31, 0x2, 0xc2, 0xc3, 0x5, 0x1c, 0xf, 0x2, 0xc3, 0xc4, 0x7, 0x8, 
    0x2, 0x2, 0xc4, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc6, 0x8, 0xf, 0x1, 
    0x2, 0xc6, 0xc7, 0x5, 0x1e, 0x10, 0x2, 0xc7, 0xcd, 0x3, 0x2, 0x2, 0x2, 
    0xc8, 0xc9, 0xc, 0x3, 0x2, 0x2, 0xc9, 0xca, 0x7, 0x7, 0x2, 0x2, 0xca, 
    0xcc, 0x5, 0x1e, 0x10, 0x2, 0xcb, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xcf, 
    0x3, 0x2, 0x2, 0x2, 0xcd, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xce, 0x3, 
    0x2, 0x2, 0x2, 0xce, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xcd, 0x3, 0x2, 
    0x2, 0x2, 0xd0, 0xd2, 0x5, 0x20, 0x11, 0x2, 0xd1, 0xd3, 0x5, 0x22, 0x12, 
    0x2, 0xd2, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd3, 0x3, 0x2, 0x2, 0x2, 
    0xd3, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd5, 0x7, 0x36, 0x2, 0x2, 0xd5, 
    0x21, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd7, 0x7, 0x9, 0x2, 0x2, 0xd7, 0xd8, 
    0x5, 0x30, 0x19, 0x2, 0xd8, 0x23, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xda, 0x7, 
    0x2c, 0x2, 0x2, 0xda, 0xdb, 0x7, 0x5, 0x2, 0x2, 0xdb, 0xdc, 0x5, 0x30, 
    0x19, 0x2, 0xdc, 0xdd, 0x7, 0x6, 0x2, 0x2, 0xdd, 0xde, 0x5, 0x14, 0xb, 
    0x2, 0xde, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xe0, 0x7, 0x2c, 0x2, 0x2, 
    0xe0, 0xe1, 0x7, 0x5, 0x2, 0x2, 0xe1, 0xe2, 0x5, 0x30, 0x19, 0x2, 0xe2, 
    0xe3, 0x7, 0x6, 0x2, 0x2, 0xe3, 0xe4, 0x5, 0x14, 0xb, 0x2, 0xe4, 0xe5, 
    0x7, 0x2d, 0x2, 0x2, 0xe5, 0xe6, 0x5, 0x14, 0xb, 0x2, 0xe6, 0xe8, 0x3, 
    0x2, 0x2, 0x2, 0xe7, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xdf, 0x3, 0x2, 
    0x2, 0x2, 0xe8, 0x25, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xea, 0x7, 0x2f, 0x2, 
    0x2, 0xea, 0xeb, 0x7, 0x5, 0x2, 0x2, 0xeb, 0xec, 0x5, 0x30, 0x19, 0x2, 
    0xec, 0xed, 0x7, 0x6, 0x2, 0x2, 0xed, 0xee, 0x5, 0x14, 0xb, 0x2, 0xee, 
    0xff, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf0, 0x7, 0x2e, 0x2, 0x2, 0xf0, 0xf2, 
    0x7, 0x5, 0x2, 0x2, 0xf1, 0xf3, 0x5, 0x30, 0x19, 0x2, 0xf2, 0xf1, 0x3, 
    0x2, 0x2, 0x2, 0xf2, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf4, 0x3, 0x2, 
    0x2, 0x2, 0xf4, 0xf6, 0x7, 0x8, 0x2, 0x2, 0xf5, 0xf7, 0x5, 0x30, 0x19, 
    0x2, 0xf6, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf7, 0x3, 0x2, 0x2, 0x2, 
    0xf7, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xfa, 0x7, 0x8, 0x2, 0x2, 0xf9, 
    0xfb, 0x5, 0x30, 0x19, 0x2, 0xfa, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xfb, 
    0x3, 0x2, 0x2, 0x2, 0xfb, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfd, 0x7, 
    0x6, 0x2, 0x2, 0xfd, 0xff, 0x5, 0x14, 0xb, 0x2, 0xfe, 0xe9, 0x3, 0x2, 
    0x2, 0x2, 0xfe, 0xef, 0x3, 0x2, 0x2, 0x2, 0xff, 0x27, 0x3, 0x2, 0x2, 
    0x2, 0x100, 0x101, 0x7, 0x30, 0x2, 0x2, 0x101, 0x10a, 0x7, 0x8, 0x2, 
    0x2, 0x102, 0x103, 0x7, 0x31, 0x2, 0x2, 0x103, 0x10a, 0x7, 0x8, 0x2, 
    0x2, 0x104, 0x106, 0x7, 0x32, 0x2, 0x2, 0x105, 0x107, 0x5, 0x30, 0x19, 
    0x2, 0x106, 0x105, 0x3, 0x2, 0x2, 0x2, 0x106, 0x107, 0x3, 0x2, 0x2, 
    0x2, 0x107, 0x108, 0x3, 0x2, 0x2, 0x2, 0x108, 0x10a, 0x7, 0x8, 0x2, 
    0x2, 0x109, 0x100, 0x3, 0x2, 0x2, 0x2, 0x109, 0x102, 0x3, 0x2, 0x2, 
    0x2, 0x109, 0x104, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x29, 0x3, 0x2, 0x2, 0x2, 
    0x10b, 0x10c, 0x5, 0x30, 0x19, 0x2, 0x10c, 0x10d, 0x7, 0x8, 0x2, 0x2, 
    0x10d, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x10f, 0x7, 0x8, 0x2, 0x2, 0x10f, 
    0x2d, 0x3, 0x2, 0x2, 0x2, 0x110, 0x111, 0x8, 0x18, 0x1, 0x2, 0x111, 
    0x112, 0x5, 0x30, 0x19, 0x2, 0x112, 0x118, 0x3, 0x2, 0x2, 0x2, 0x113, 
    0x114, 0xc, 0x3, 0x2, 0x2, 0x114, 0x115, 0x7, 0x7, 0x2, 0x2, 0x115, 
    0x117, 0x5, 0x30, 0x19, 0x2, 0x116, 0x113, 0x3, 0x2, 0x2, 0x2, 0x117, 
    0x11a, 0x3, 0x2, 0x2, 0x2, 0x118, 0x116, 0x3, 0x2, 0x2, 0x2, 0x118, 
    0x119, 0x3, 0x2, 0x2, 0x2, 0x119, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x118, 
    0x3, 0x2, 0x2, 0x2, 0x11b, 0x11c, 0x5, 0x32, 0x1a, 0x2, 0x11c, 0x31, 
    0x3, 0x2, 0x2, 0x2, 0x11d, 0x123, 0x5, 0x34, 0x1b, 0x2, 0x11e, 0x11f, 
    0x5, 0x34, 0x1b, 0x2, 0x11f, 0x120, 0x7, 0x9, 0x2, 0x2, 0x120, 0x121, 
    0x5, 0x32, 0x1a, 0x2, 0x121, 0x123, 0x3, 0x2, 0x2, 0x2, 0x122, 0x11d, 
    0x3, 0x2, 0x2, 0x2, 0x122, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x123, 0x33, 0x3, 
    0x2, 0x2, 0x2, 0x124, 0x125, 0x8, 0x1b, 0x1, 0x2, 0x125, 0x126, 0x5, 
    0x36, 0x1c, 0x2, 0x126, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x127, 0x128, 0xc, 
    0x3, 0x2, 0x2, 0x128, 0x129, 0x7, 0xa, 0x2, 0x2, 0x129, 0x12b, 0x5, 
    0x36, 0x1c, 0x2, 0x12a, 0x127, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12e, 0x3, 
    0x2, 0x2, 0x2, 0x12c, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12d, 0x3, 
    0x2, 0x2, 0x2, 0x12d, 0x35, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x12c, 0x3, 0x2, 
    0x2, 0x2, 0x12f, 0x130, 0x8, 0x1c, 0x1, 0x2, 0x130, 0x131, 0x5, 0x38, 
    0x1d, 0x2, 0x131, 0x137, 0x3, 0x2, 0x2, 0x2, 0x132, 0x133, 0xc, 0x3, 
    0x2, 0x2, 0x133, 0x134, 0x7, 0xb, 0x2, 0x2, 0x134, 0x136, 0x5, 0x38, 
    0x1d, 0x2, 0x135, 0x132, 0x3, 0x2, 0x2, 0x2, 0x136, 0x139, 0x3, 0x2, 
    0x2, 0x2, 0x137, 0x135, 0x3, 0x2, 0x2, 0x2, 0x137, 0x138, 0x3, 0x2, 
    0x2, 0x2, 0x138, 0x37, 0x3, 0x2, 0x2, 0x2, 0x139, 0x137, 0x3, 0x2, 0x2, 
    0x2, 0x13a, 0x13b, 0x8, 0x1d, 0x1, 0x2, 0x13b, 0x13c, 0x5, 0x3a, 0x1e, 
    0x2, 0x13c, 0x142, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13e, 0xc, 0x3, 0x2, 
    0x2, 0x13e, 0x13f, 0x7, 0xc, 0x2, 0x2, 0x13f, 0x141, 0x5, 0x3a, 0x1e, 
    0x2, 0x140, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x141, 0x144, 0x3, 0x2, 0x2, 
    0x2, 0x142, 0x140, 0x3, 0x2, 0x2, 0x2, 0x142, 0x143, 0x3, 0x2, 0x2, 
    0x2, 0x143, 0x39, 0x3, 0x2, 0x2, 0x2, 0x144, 0x142, 0x3, 0x2, 0x2, 0x2, 
    0x145, 0x146, 0x8, 0x1e, 0x1, 0x2, 0x146, 0x147, 0x5, 0x3c, 0x1f, 0x2, 
    0x147, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x148, 0x149, 0xc, 0x3, 0x2, 0x2, 
    0x149, 0x14a, 0x7, 0xd, 0x2, 0x2, 0x14a, 0x14c, 0x5, 0x3e, 0x20, 0x2, 
    0x14b, 0x148, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x14f, 0x3, 0x2, 0x2, 0x2, 
    0x14d, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x14e, 0x3, 0x2, 0x2, 0x2, 
    0x14e, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x150, 
    0x151, 0x8, 0x1f, 0x1, 0x2, 0x151, 0x152, 0x5, 0x3e, 0x20, 0x2, 0x152, 
    0x158, 0x3, 0x2, 0x2, 0x2, 0x153, 0x154, 0xc, 0x3, 0x2, 0x2, 0x154, 
    0x155, 0x7, 0xe, 0x2, 0x2, 0x155, 0x157, 0x5, 0x3e, 0x20, 0x2, 0x156, 
    0x153, 0x3, 0x2, 0x2, 0x2, 0x157, 0x15a, 0x3, 0x2, 0x2, 0x2, 0x158, 
    0x156, 0x3, 0x2, 0x2, 0x2, 0x158, 0x159, 0x3, 0x2, 0x2, 0x2, 0x159, 
    0x3d, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x158, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x15c, 
    0x8, 0x20, 0x1, 0x2, 0x15c, 0x15d, 0x5, 0x40, 0x21, 0x2, 0x15d, 0x164, 
    0x3, 0x2, 0x2, 0x2, 0x15e, 0x15f, 0xc, 0x3, 0x2, 0x2, 0x15f, 0x160, 
    0x5, 0x58, 0x2d, 0x2, 0x160, 0x161, 0x5, 0x40, 0x21, 0x2, 0x161, 0x163, 
    0x3, 0x2, 0x2, 0x2, 0x162, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x163, 0x166, 
    0x3, 0x2, 0x2, 0x2, 0x164, 0x162, 0x3, 0x2, 0x2, 0x2, 0x164, 0x165, 
    0x3, 0x2, 0x2, 0x2, 0x165, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x166, 0x164, 0x3, 
    0x2, 0x2, 0x2, 0x167, 0x168, 0x8, 0x21, 0x1, 0x2, 0x168, 0x169, 0x5, 
    0x42, 0x22, 0x2, 0x169, 0x170, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x16b, 0xc, 
    0x3, 0x2, 0x2, 0x16b, 0x16c, 0x5, 0x5a, 0x2e, 0x2, 0x16c, 0x16d, 0x5, 
    0x42, 0x22, 0x2, 0x16d, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x16a, 0x3, 
    0x2, 0x2, 0x2, 0x16f, 0x172, 0x3, 0x2, 0x2, 0x2, 0x170, 0x16e, 0x3, 
    0x2, 0x2, 0x2, 0x170, 0x171, 0x3, 0x2, 0x2, 0x2, 0x171, 0x41, 0x3, 0x2, 
    0x2, 0x2, 0x172, 0x170, 0x3, 0x2, 0x2, 0x2, 0x173, 0x174, 0x8, 0x22, 
    0x1, 0x2, 0x174, 0x175, 0x5, 0x44, 0x23, 0x2, 0x175, 0x17c, 0x3, 0x2, 
    0x2, 0x2, 0x176, 0x177, 0xc, 0x3, 0x2, 0x2, 0x177, 0x178, 0x5, 0x5c, 
    0x2f, 0x2, 0x178, 0x179, 0x5, 0x44, 0x23, 0x2, 0x179, 0x17b, 0x3, 0x2, 
    0x2, 0x2, 0x17a, 0x176, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x17e, 0x3, 0x2, 
    0x2, 0x2, 0x17c, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x17d, 0x3, 0x2, 
    0x2, 0x2, 0x17d, 0x43, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x17c, 0x3, 0x2, 0x2, 
    0x2, 0x17f, 0x180, 0x8, 0x23, 0x1, 0x2, 0x180, 0x181, 0x5, 0x46, 0x24, 
    0x2, 0x181, 0x18a, 0x3, 0x2, 0x2, 0x2, 0x182, 0x183, 0xc, 0x4, 0x2, 
    0x2, 0x183, 0x184, 0x7, 0xf, 0x2, 0x2, 0x184, 0x189, 0x5, 0x46, 0x24, 
    0x2, 0x185, 0x186, 0xc, 0x3, 0x2, 0x2, 0x186, 0x187, 0x7, 0x10, 0x2, 
    0x2, 0x187, 0x189, 0x5, 0x46, 0x24, 0x2, 0x188, 0x182, 0x3, 0x2, 0x2, 
    0x2, 0x188, 0x185, 0x3, 0x2, 0x2, 0x2, 0x189, 0x18c, 0x3, 0x2, 0x2, 
    0x2, 0x18a, 0x188, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x18b, 0x3, 0x2, 0x2, 
    0x2, 0x18b, 0x45, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x18a, 0x3, 0x2, 0x2, 0x2, 
    0x18d, 0x18e, 0x8, 0x24, 0x1, 0x2, 0x18e, 0x18f, 0x5, 0x48, 0x25, 0x2, 
    0x18f, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x190, 0x191, 0xc, 0x5, 0x2, 0x2, 
    0x191, 0x192, 0x7, 0x11, 0x2, 0x2, 0x192, 0x19a, 0x5, 0x48, 0x25, 0x2, 
    0x193, 0x194, 0xc, 0x4, 0x2, 0x2, 0x194, 0x195, 0x7, 0x12, 0x2, 0x2, 
    0x195, 0x19a, 0x5, 0x48, 0x25, 0x2, 0x196, 0x197, 0xc, 0x3, 0x2, 0x2, 
    0x197, 0x198, 0x7, 0x13, 0x2, 0x2, 0x198, 0x19a, 0x5, 0x48, 0x25, 0x2, 
    0x199, 0x190, 0x3, 0x2, 0x2, 0x2, 0x199, 0x193, 0x3, 0x2, 0x2, 0x2, 
    0x199, 0x196, 0x3, 0x2, 0x2, 0x2, 0x19a, 0x19d, 0x3, 0x2, 0x2, 0x2, 
    0x19b, 0x199, 0x3, 0x2, 0x2, 0x2, 0x19b, 0x19c, 0x3, 0x2, 0x2, 0x2, 
    0x19c, 0x47, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x19e, 
    0x1a8, 0x5, 0x54, 0x2b, 0x2, 0x19f, 0x1a0, 0x7, 0x14, 0x2, 0x2, 0x1a0, 
    0x1a8, 0x5, 0x48, 0x25, 0x2, 0x1a1, 0x1a2, 0x7, 0x15, 0x2, 0x2, 0x1a2, 
    0x1a8, 0x5, 0x48, 0x25, 0x2, 0x1a3, 0x1a4, 0x5, 0x5e, 0x30, 0x2, 0x1a4, 
    0x1a5, 0x5, 0x48, 0x25, 0x2, 0x1a5, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1a6, 
    0x1a8, 0x5, 0x4a, 0x26, 0x2, 0x1a7, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x1a7, 
    0x19f, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1a1, 0x3, 0x2, 0x2, 0x2, 0x1a7, 
    0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1a6, 0x3, 0x2, 0x2, 0x2, 0x1a8, 
    0x49, 0x3, 0x2, 0x2, 0x2, 0x1a9, 0x1aa, 0x7, 0x33, 0x2, 0x2, 0x1aa, 
    0x1ac, 0x5, 0x4e, 0x28, 0x2, 0x1ab, 0x1ad, 0x5, 0x4c, 0x27, 0x2, 0x1ac, 
    0x1ab, 0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1ad, 0x3, 0x2, 0x2, 0x2, 0x1ad, 
    0x4b, 0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1b0, 0x7, 0x5, 0x2, 0x2, 0x1af, 0x1b1, 
    0x5, 0x30, 0x19, 0x2, 0x1b0, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1b1, 
    0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1b2, 0x3, 0x2, 0x2, 0x2, 0x1b2, 0x1b3, 
    0x7, 0x6, 0x2, 0x2, 0x1b3, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x1b4, 0x1b6, 0x5, 
    0x62, 0x32, 0x2, 0x1b5, 0x1b7, 0x5, 0x50, 0x29, 0x2, 0x1b6, 0x1b5, 0x3, 
    0x2, 0x2, 0x2, 0x1b6, 0x1b7, 0x3, 0x2, 0x2, 0x2, 0x1b7, 0x1b9, 0x3, 
    0x2, 0x2, 0x2, 0x1b8, 0x1ba, 0x5, 0x52, 0x2a, 0x2, 0x1b9, 0x1b8, 0x3, 
    0x2, 0x2, 0x2, 0x1b9, 0x1ba, 0x3, 0x2, 0x2, 0x2, 0x1ba, 0x4f, 0x3, 0x2, 
    0x2, 0x2, 0x1bb, 0x1bc, 0x8, 0x29, 0x1, 0x2, 0x1bc, 0x1bd, 0x7, 0x16, 
    0x2, 0x2, 0x1bd, 0x1be, 0x5, 0x30, 0x19, 0x2, 0x1be, 0x1bf, 0x7, 0x17, 
    0x2, 0x2, 0x1bf, 0x1c7, 0x3, 0x2, 0x2, 0x2, 0x1c0, 0x1c1, 0xc, 0x3, 
    0x2, 0x2, 0x1c1, 0x1c2, 0x7, 0x16, 0x2, 0x2, 0x1c2, 0x1c3, 0x5, 0x30, 
    0x19, 0x2, 0x1c3, 0x1c4, 0x7, 0x17, 0x2, 0x2, 0x1c4, 0x1c6, 0x3, 0x2, 
    0x2, 0x2, 0x1c5, 0x1c0, 0x3, 0x2, 0x2, 0x2, 0x1c6, 0x1c9, 0x3, 0x2, 
    0x2, 0x2, 0x1c7, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x1c7, 0x1c8, 0x3, 0x2, 
    0x2, 0x2, 0x1c8, 0x51, 0x3, 0x2, 0x2, 0x2, 0x1c9, 0x1c7, 0x3, 0x2, 0x2, 
    0x2, 0x1ca, 0x1cb, 0x8, 0x2a, 0x1, 0x2, 0x1cb, 0x1cc, 0x7, 0x16, 0x2, 
    0x2, 0x1cc, 0x1cd, 0x7, 0x17, 0x2, 0x2, 0x1cd, 0x1d3, 0x3, 0x2, 0x2, 
    0x2, 0x1ce, 0x1cf, 0xc, 0x3, 0x2, 0x2, 0x1cf, 0x1d0, 0x7, 0x16, 0x2, 
    0x2, 0x1d0, 0x1d2, 0x7, 0x17, 0x2, 0x2, 0x1d1, 0x1ce, 0x3, 0x2, 0x2, 
    0x2, 0x1d2, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1d3, 0x1d1, 0x3, 0x2, 0x2, 
    0x2, 0x1d3, 0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1d4, 0x53, 0x3, 0x2, 0x2, 0x2, 
    0x1d5, 0x1d3, 0x3, 0x2, 0x2, 0x2, 0x1d6, 0x1d7, 0x8, 0x2b, 0x1, 0x2, 
    0x1d7, 0x1d8, 0x5, 0x56, 0x2c, 0x2, 0x1d8, 0x1ed, 0x3, 0x2, 0x2, 0x2, 
    0x1d9, 0x1da, 0xc, 0x7, 0x2, 0x2, 0x1da, 0x1ec, 0x7, 0x14, 0x2, 0x2, 
    0x1db, 0x1dc, 0xc, 0x6, 0x2, 0x2, 0x1dc, 0x1ec, 0x7, 0x15, 0x2, 0x2, 
    0x1dd, 0x1de, 0xc, 0x5, 0x2, 0x2, 0x1de, 0x1df, 0x7, 0x16, 0x2, 0x2, 
    0x1df, 0x1e0, 0x5, 0x30, 0x19, 0x2, 0x1e0, 0x1e1, 0x7, 0x17, 0x2, 0x2, 
    0x1e1, 0x1ec, 0x3, 0x2, 0x2, 0x2, 0x1e2, 0x1e3, 0xc, 0x4, 0x2, 0x2, 
    0x1e3, 0x1e5, 0x7, 0x5, 0x2, 0x2, 0x1e4, 0x1e6, 0x5, 0x2e, 0x18, 0x2, 
    0x1e5, 0x1e4, 0x3, 0x2, 0x2, 0x2, 0x1e5, 0x1e6, 0x3, 0x2, 0x2, 0x2, 
    0x1e6, 0x1e7, 0x3, 0x2, 0x2, 0x2, 0x1e7, 0x1ec, 0x7, 0x6, 0x2, 0x2, 
    0x1e8, 0x1e9, 0xc, 0x3, 0x2, 0x2, 0x1e9, 0x1ea, 0x7, 0x18, 0x2, 0x2, 
    0x1ea, 0x1ec, 0x5, 0x30, 0x19, 0x2, 0x1eb, 0x1d9, 0x3, 0x2, 0x2, 0x2, 
    0x1eb, 0x1db, 0x3, 0x2, 0x2, 0x2, 0x1eb, 0x1dd, 0x3, 0x2, 0x2, 0x2, 
    0x1eb, 0x1e2, 0x3, 0x2, 0x2, 0x2, 0x1eb, 0x1e8, 0x3, 0x2, 0x2, 0x2, 
    0x1ec, 0x1ef, 0x3, 0x2, 0x2, 0x2, 0x1ed, 0x1eb, 0x3, 0x2, 0x2, 0x2, 
    0x1ed, 0x1ee, 0x3, 0x2, 0x2, 0x2, 0x1ee, 0x55, 0x3, 0x2, 0x2, 0x2, 0x1ef, 
    0x1ed, 0x3, 0x2, 0x2, 0x2, 0x1f0, 0x1f8, 0x5, 0x64, 0x33, 0x2, 0x1f1, 
    0x1f8, 0x7, 0x35, 0x2, 0x2, 0x1f2, 0x1f8, 0x7, 0x36, 0x2, 0x2, 0x1f3, 
    0x1f4, 0x7, 0x5, 0x2, 0x2, 0x1f4, 0x1f5, 0x5, 0x30, 0x19, 0x2, 0x1f5, 
    0x1f6, 0x7, 0x6, 0x2, 0x2, 0x1f6, 0x1f8, 0x3, 0x2, 0x2, 0x2, 0x1f7, 
    0x1f0, 0x3, 0x2, 0x2, 0x2, 0x1f7, 0x1f1, 0x3, 0x2, 0x2, 0x2, 0x1f7, 
    0x1f2, 0x3, 0x2, 0x2, 0x2, 0x1f7, 0x1f3, 0x3, 0x2, 0x2, 0x2, 0x1f8, 
    0x57, 0x3, 0x2, 0x2, 0x2, 0x1f9, 0x1fa, 0x9, 0x2, 0x2, 0x2, 0x1fa, 0x59, 
    0x3, 0x2, 0x2, 0x2, 0x1fb, 0x1fc, 0x9, 0x3, 0x2, 0x2, 0x1fc, 0x5b, 0x3, 
    0x2, 0x2, 0x2, 0x1fd, 0x1fe, 0x9, 0x4, 0x2, 0x2, 0x1fe, 0x5d, 0x3, 0x2, 
    0x2, 0x2, 0x1ff, 0x200, 0x9, 0x5, 0x2, 0x2, 0x200, 0x5f, 0x3, 0x2, 0x2, 
    0x2, 0x201, 0x202, 0x8, 0x31, 0x1, 0x2, 0x202, 0x203, 0x5, 0x62, 0x32, 
    0x2, 0x203, 0x209, 0x3, 0x2, 0x2, 0x2, 0x204, 0x205, 0xc, 0x3, 0x2, 
    0x2, 0x205, 0x206, 0x7, 0x16, 0x2, 0x2, 0x206, 0x208, 0x7, 0x17, 0x2, 
    0x2, 0x207, 0x204, 0x3, 0x2, 0x2, 0x2, 0x208, 0x20b, 0x3, 0x2, 0x2, 
    0x2, 0x209, 0x207, 0x3, 0x2, 0x2, 0x2, 0x209, 0x20a, 0x3, 0x2, 0x2, 
    0x2, 0x20a, 0x61, 0x3, 0x2, 0x2, 0x2, 0x20b, 0x209, 0x3, 0x2, 0x2, 0x2, 
    0x20c, 0x20d, 0x9, 0x6, 0x2, 0x2, 0x20d, 0x63, 0x3, 0x2, 0x2, 0x2, 0x20e, 
    0x213, 0x5, 0x66, 0x34, 0x2, 0x20f, 0x213, 0x7, 0x24, 0x2, 0x2, 0x210, 
    0x213, 0x7, 0x23, 0x2, 0x2, 0x211, 0x213, 0x7, 0x28, 0x2, 0x2, 0x212, 
    0x20e, 0x3, 0x2, 0x2, 0x2, 0x212, 0x20f, 0x3, 0x2, 0x2, 0x2, 0x212, 
    0x210, 0x3, 0x2, 0x2, 0x2, 0x212, 0x211, 0x3, 0x2, 0x2, 0x2, 0x213, 
    0x65, 0x3, 0x2, 0x2, 0x2, 0x214, 0x215, 0x9, 0x7, 0x2, 0x2, 0x215, 0x67, 
    0x3, 0x2, 0x2, 0x2, 0x31, 0x71, 0x77, 0x7d, 0x88, 0x8d, 0x90, 0x95, 
    0xa2, 0xaf, 0xb3, 0xbe, 0xcd, 0xd2, 0xe7, 0xf2, 0xf6, 0xfa, 0xfe, 0x106, 
    0x109, 0x118, 0x122, 0x12c, 0x137, 0x142, 0x14d, 0x158, 0x164, 0x170, 
    0x17c, 0x188, 0x18a, 0x199, 0x19b, 0x1a7, 0x1ac, 0x1b0, 0x1b6, 0x1b9, 
    0x1c7, 0x1d3, 0x1e5, 0x1eb, 0x1ed, 0x1f7, 0x209, 0x212, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

Mx_starParser::Initializer Mx_starParser::_init;
