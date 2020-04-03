
// Generated from /Users/zhangyuheng/CLionProjects/Comiler-Mx_star/grammar/Mx_star.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  Mx_starLexer : public antlr4::Lexer {
public:
  enum {
    Stringliteral = 1, Integerliteral = 2, Assign = 3, Logic_or = 4, Logic_and = 5, 
    Bitwise_or = 6, Bitwise_xor = 7, Bitwise_and = 8, Equal = 9, NotEqual = 10, 
    Less = 11, Lesseq = 12, Greater = 13, Greatereq = 14, Leftshift = 15, 
    Rightshift = 16, Plus = 17, Minus = 18, Mul = 19, Div = 20, Mod = 21, 
    Inc = 22, Dec = 23, Logic_not = 24, Bitwise_not = 25, Dot = 26, Openpar = 27, 
    Closepar = 28, Openbra = 29, Closebra = 30, Opencur = 31, Closecur = 32, 
    Comma = 33, Semicolon = 34, Int = 35, Bool = 36, String = 37, Null = 38, 
    Void = 39, True = 40, False = 41, If = 42, Else = 43, For = 44, While = 45, 
    Break = 46, Continue = 47, Return = 48, New = 49, Class = 50, This = 51, 
    Identifier = 52, Whitespace = 53, Newline = 54, BlockComment = 55, LineComment = 56
  };

  Mx_starLexer(antlr4::CharStream *input);
  ~Mx_starLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

