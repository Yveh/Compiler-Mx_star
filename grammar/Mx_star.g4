grammar Mx_star;

statement
    : declarationstatement
    ;

declarationstatement
    : typespecifier initdeclarator
    ;

initdeclarator
    : declarator initializer
    ;

declarator
    : Identifier
    | declarator '[]'
    ;

initializer
    : '=' expression
    ;

//expression
expression
    : assignmentexpression
    ;

assignmentexpression
    : logicalandexpression
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
    | '++' postfixexpression
    | '--' postfixexpression
    | unaryoperator postfixexpression
    | newexpression
    ;

newexpression
    : New typespecifier newdeclarator?
    ;

newdeclarator
    : '[' expression ']'
    | newdeclarator '[' expression ']'
    ;

postfixexpression
    : primaryexpression
    | postfixexpression '++'
    | postfixexpression '--'
    | postfixexpression '[' expression ']'
    | postfixexpression '.' Identifier
    ;

primaryexpression
    : literal
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
