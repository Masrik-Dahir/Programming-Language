# include "Givens.h"

/*
verification: body --> LEFT_BRACKET [statement-list] RIGHT_BRACKET 
*/
_Bool _body (struct lexics *someLexics, int numberOfLexics);

/*
verification: statement --> while-loop | return | assignment | body 
*/
_Bool _statement (struct lexics *someLexics, int numberOfLexics);

/*
verification: function --> header body
*/
_Bool _function (struct lexics *someLexics, int numberOfLexics);

/*
verification: header --> VARTYPE IDENTIFIER LEFT_PARENTHESIS [arg-decl] RIGHT_PARENTHESIS 
*/
_Bool _header (struct lexics *someLexics, int numberOfLexics);

/*
verification: arg-decl --> VARTYPE IDENTIFIER {COMMA VARTYPE IDENTIFIER} 
*/
_Bool _arg_decl (struct lexics *someLexics, int numberOfLexics);

/*
verification: statement-list --> statement {statement} 
*/
_Bool _statement_list (struct lexics *someLexics, int numberOfLexics);

/*
verification: while-loop --> WHILE_KEYWORD LEFT_PARENTHESIS expression RIGHT_PARENTHESIS statement
*/ 
_Bool _while_loop (struct lexics *someLexics, int numberOfLexics);

/*
verification: return --> RETURN_KEYWORD expression EOL
*/
_Bool _return (struct lexics *someLexics, int numberOfLexics);

/*
verification: assignment --> IDENTIFIER EQUAL expression EOL
*/
_Bool _assignment  (struct lexics *someLexics, int numberOfLexics);

/*
verification: expression --> term {BINOP term} | LEFT_PARENTHESIS expression RIGHT_PARENTHESIS 
*/
_Bool _expression (struct lexics *someLexics, int numberOfLexics);

/*
verification: term --> IDENTIFIER | NUMBER  
*/
_Bool _term  (struct lexics *someLexics, int numberOfLexics);

/*
akes an array of type lexics and an int pointer representing 
the number of tokens in the given lexics array. 
*/
_Bool parser (struct lexics *someLexics, int numberOfLexics);