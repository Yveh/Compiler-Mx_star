grammar Mx_star;

prog
    : (classdeclaration | functiondeclaration | vardeclaration)*
    ;

//class
classdeclaration
    : Class Identifier Opencur (functiondeclaration | vardeclaration)* Closecur Semicolon
    ;

//function
functiondeclaration
    : typespecifier? Identifier Openpar (parameter (Comma parameter)*)? Closepar block
    ;

parameter
    : typespecifier (Openbra Closebra)* Identifier
    ;

//statement
statement
    : vardeclaration
    | ifstatement
    | iterationstatement
    | jumpstatement
    | expressionstatement
    | emptystatement
    | block
    ;

block
    : Opencur (statement)* Closecur
    ;

vardeclaration
    : typespecifier vardecl (Comma vardecl)* Semicolon
    ;

vardecl
    : Identifier (Assign expression)?
    ;

ifstatement
    : If Openpar expression Closepar statement
    | If Openpar expression Closepar statement Else statement
    ;

iterationstatement
    : While Openpar expression Closepar statement
    | For Openpar forinit? Semicolon forcond? Semicolon forincr? Closepar statement
    ;

forinit
    : expression
    ;

forcond
    : expression
    ;

forincr
    : expression
    ;

jumpstatement
    : Break Semicolon
    | Continue Semicolon
    | Return expression? Semicolon
    ;

expressionstatement
    : expression Semicolon
    ;

emptystatement
    : Semicolon
    ;

//expression
expression
    : logicalorexpression
    | logicalorexpression Assign expression
    ;

logicalorexpression
    : logicalandexpression
    | logicalorexpression Logic_or logicalandexpression
    ;

logicalandexpression
    : orexpression
    | logicalandexpression Logic_and orexpression
    ;

orexpression
    : xorexpression
    | orexpression Bitwise_or xorexpression
    ;

xorexpression
    : andexpression
    | xorexpression Bitwise_xor andexpression
    ;

andexpression
    : equalityexpression
    | andexpression Bitwise_and equalityexpression
    ;

equalityexpression
    : relationalexpression
    | equalityexpression Equal relationalexpression
    | equalityexpression NotEqual relationalexpression
    ;

relationalexpression
    : shiftexpression
    | relationalexpression Less shiftexpression
    | relationalexpression Lesseq shiftexpression
    | relationalexpression Greater shiftexpression
    | relationalexpression Greatereq shiftexpression
    ;

shiftexpression
    : additiveexpression
    | shiftexpression Leftshift additiveexpression
    | shiftexpression Rightshift additiveexpression
    ;

additiveexpression
    : multiplicativeexpression
    | additiveexpression Plus multiplicativeexpression
    | additiveexpression Minus multiplicativeexpression
    ;

multiplicativeexpression
    : unaryexpression
    | multiplicativeexpression Mul unaryexpression
    | multiplicativeexpression Div unaryexpression
    | multiplicativeexpression Mod unaryexpression
    ;

unaryexpression
    : postfixexpression
    | Inc unaryexpression
    | Dec unaryexpression
    | Bitwise_not unaryexpression
    | Logic_not unaryexpression
    | Plus unaryexpression
    | Minus unaryexpression
    | newexpression
    ;

newexpression
    : New simpletypespecifier ((Openpar (expression (Comma expression)*)? Closepar) | ((Openbra expression Closebra)* (Openbra Closebra)*))
    ;

postfixexpression
    : primaryexpression
    | postfixexpression Inc
    | postfixexpression Dec
    | postfixexpression Openbra expression Closebra
    | postfixexpression Dot (Identifier | functioncall)
    ;

functioncall
    : Identifier Openpar (expression (Comma expression)*)? Closepar
    ;

primaryexpression
    : literal
    | This
    | Identifier
    | Openpar expression Closepar
    | functioncall
    ;

typespecifier
    : simpletypespecifier (Openbra Closebra)*
    ;

simpletypespecifier
    : Bool
    | Int
    | Void
    | String
    | Identifier
    ;

literal
    : booleanliteral
    | Integerliteral
    | Stringliteral
    | Null
    ;

booleanliteral
    : True
    | False
    ;

//fragment

Stringliteral
    : '"' Char* '"'
    ;

Integerliteral
    : DIGIT+
    ;

Assign
    : '='
    ;

Logic_or
    : '||'
    ;

Logic_and
    : '&&'
    ;

Bitwise_or
    : '|'
    ;

Bitwise_xor
    : '^'
    ;

Bitwise_and
    : '&'
    ;

Equal
    : '=='
    ;

NotEqual
    : '!='
    ;

Less
    : '<'
    ;

Lesseq
    : '<='
    ;

Greater
    : '>'
    ;

Greatereq
    : '>='
    ;

Leftshift
    : '<<'
    ;

Rightshift
    : '>>'
    ;

Plus
    : '+'
    ;

Minus
    : '-'
    ;

Mul
    : '*'
    ;

Div
    : '/'
    ;

Mod
    : '%'
    ;

Inc
    : '++'
    ;

Dec
    : '--'
    ;

Logic_not
    : '!'
    ;

Bitwise_not
    : '~'
    ;

Dot
    : '.'
    ;

Openpar
    : '('
    ;

Closepar
    : ')'
    ;

Openbra
    : '['
    ;

Closebra
    : ']'
    ;

Opencur
    : '{'
    ;

Closecur
    : '}'
    ;

Comma
    : ','
    ;

Semicolon
    : ';'
    ;

Int
    : 'int'
    ;
Bool
    : 'bool'
    ;
String
    : 'string'
    ;
Null
    : 'null'
    ;
Void
    : 'void'
    ;
True
    : 'true'
    ;
False
    : 'false'
    ;
If
    : 'if'
    ;
Else
    : 'else'
    ;
For
    : 'for'
    ;
While
    : 'while'
    ;
Break
    : 'break'
    ;
Continue
    : 'continue'
    ;
Return
    : 'return'
    ;
New
    : 'new'
    ;
Class
    : 'class'
    ;
This
    : 'this'
    ;

Identifier
    : ALPHABET (DIGIT | ALPHABET | '_')*
    ;

fragment Char
    : ~["\\\r\n]
    | '\\\\'
    | '\\n'
    | '\\"'
    ;
fragment DIGIT
    : [0-9]
    ;
fragment ALPHABET
    : [a-zA-Z]
    ;

Whitespace
    : [ \t]+ -> skip
    ;
Newline
    : ('\r' '\n'? | '\n') -> skip
    ;
BlockComment
    : '/*' .*? '*/' -> skip
    ;
LineComment
    : '//' ~ [^\r\n]* -> skip
    ;