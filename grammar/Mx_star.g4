grammar Mx_star;

file
    : declarationlist
    ;

declarationlist
    : declaration
    | declarationlist declaration
    ;

declaration
    : classdeclaration
    | functiondeclaration
    | declarationstatement
    ;
//class
classdeclaration
    : Class Identifier '{' memberdeclarationlist? '}'
    ;

memberdeclarationlist
    : memberdeclaration
    | memberdeclarationlist memberdeclaration
    ;

memberdeclaration
    : declarationstatement
    | functiondeclaration
    ;
//function
functiondeclaration
    : typespecifier? Identifier '(' parameterlist? ')' block
    ;

parameterlist
    : parameter
    | parameterlist ',' parameter
    ;

parameter
    : typespecifier initdeclarator
    ;

//statement
statement
    : declarationstatement
    | ifstatement
    | iterationstatement
    | jumpstatement
    | expressionstatement
    | emptystatement
    | block
    ;

block
    : '{' statementlist? '}'
    ;

statementlist
    : statement
    | statementlist statement
    ;

declarationstatement
    : typespecifier initdeclaratorlist ';'
    ;

initdeclaratorlist
    : initdeclarator
    | initdeclaratorlist ',' initdeclarator
    ;

initdeclarator
    : declarator initializer?
    ;

declarator
    : Identifier
    ;

initializer
    : '=' expression
    ;

ifstatement
    : If '(' expression ')' statement
    | If '(' expression ')' statement Else statement
    ;

iterationstatement
    : While '(' expression ')' statement
    | For '(' expression? ';' expression? ';' expression? ')' statement
    ;

jumpstatement
    : Break ';'
    | Continue ';'
    | Return expression? ';'
    ;

expressionstatement
    : expression ';'
    ;

emptystatement
    : ';'
    ;

//expression
expressionlist
    : expression
    | expressionlist ',' expression
    ;

expression
    : assignmentexpression
    ;

assignmentexpression
    : logicalorexpression
    | logicalorexpression '=' assignmentexpression
    ;

logicalorexpression
    : logicalandexpression
    | logicalorexpression '||' logicalandexpression
    ;

logicalandexpression
    : orexpression
    | logicalandexpression '&&' orexpression
    ;

orexpression
    : xorexpression
    | orexpression '|' xorexpression
    ;

xorexpression
    : andexpression
    | xorexpression '^' equalityexpression
    ;

andexpression
    : equalityexpression
    | andexpression '&' equalityexpression
    ;

equalityexpression
    : relationalexpression
    | equalityexpression equalityoperator relationalexpression
    ;

relationalexpression
    : shiftexpression
    | relationalexpression relationoperator shiftexpression
    ;

shiftexpression
    : additiveexpression
    | shiftexpression shiftoperator additiveexpression
    ;

additiveexpression
    : multiplicativeexpression
    | additiveexpression '+' multiplicativeexpression
    | additiveexpression '-' multiplicativeexpression
    ;

multiplicativeexpression
    : unaryexpression
    | multiplicativeexpression '*' unaryexpression
    | multiplicativeexpression '/' unaryexpression
    | multiplicativeexpression '%' unaryexpression
    ;

unaryexpression
    : postfixexpression
    | '++' unaryexpression
    | '--' unaryexpression
    | unaryoperator unaryexpression
    | newexpression
    ;

newexpression
    : New newtypespecifier newinitializer?
    ;

newinitializer
    : '(' expression? ')'
    ;

newtypespecifier
    : simpletypespecifier newdeclarator?
    ;

newdeclarator
    : '[' expression? ']'
    | newdeclarator '[' expression? ']'
    ;

postfixexpression
    : primaryexpression
    | postfixexpression '++'
    | postfixexpression '--'
    | postfixexpression '[' expression ']'
    | postfixexpression '(' expressionlist? ')'
    | postfixexpression '.' expression
    ;

primaryexpression
    : literal
    | This
    | Identifier
    | '(' expression ')'
    ;

//fragment

equalityoperator
    : '=='
    | '!='
    ;

relationoperator
    : '<'
    | '<='
    | '>'
    | '>='
    ;

shiftoperator
    : '<<'
    | '>>'
    ;

unaryoperator
    : '~'
    | '-'
    | '!'
    ;

typespecifier
    : simpletypespecifier
    | typespecifier '[' ']'
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
Stringliteral
    : '"' Char* '"'
    ;
booleanliteral
    : True
    | False
    ;

Integerliteral
    : DIGIT+
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
