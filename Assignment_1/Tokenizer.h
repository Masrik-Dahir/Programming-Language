#include <string.h>
#include "Givens.h"
#include "stdio.h"

/* 
Check if the current character is part of number set
*/
_Bool is_excepted_number(int current);

/* 
Check if the current character is part of the alphabet set
*/
_Bool is_excepted_string(int current);

/* 
Check if the current character is part of syntax set
*/
_Bool is_excepted_syntax(int current);

/* 
Check if the current character is part of aritmatic sign set
*/
_Bool is_excepted_arithmatic(int current);

/* 
Return the fisrt character of the string
*/
char get_first_charater(FILE* inf,char first[]);

/* 
Return the next character of the current character 
*/
char get_next_charater(FILE* inf);

/* 
Return NUMBER token type after tokenizing 
*/
int get_nonterminal_number (FILE* inf, char current, char* string,int *numLex);

/* 
Return reserved strings type (i.e., WHILE_KEYWORD, RETURN_KEYWORD, and
 VARTYPE) token after tokenizing 
*/
int get_nonterminal_reserved_string(char* string);

/* 
Return nonreserved strings type (i.e., variable names) token after tokenizing 
*/
int get_nonterminal_string(FILE *inf, char current, char* string,struct lexics *aLex,int *numLex);

/* 
Return syxtan type (i.e., LEFT_PARENTHESIS, RIGHT_PARENTHESIS
LEFT_BRACKET, RIGHT_BRACKET, WHILE_KEYWORD, RETURN_KEYWORD,
EQUAL, COMMA, and EOL) and "==" and "!=" token after tokenizing 
*/
int get_nonterminal_syntax(FILE* inf, char current, char* string,struct lexics *aLex,int *numLex);

/* 
Return arithmatic type (i.e., BINOP) token after tokenizing 
*/
int get_nonterminal_arithmatic(FILE* inf, char current, char* string,struct lexics *aLex,int *numLex);

/* 
Read characters from the given FILE parameter and
create lexemes and the associated tokens
*/
_Bool tokenizer(struct lexics *aLex, int *numLex, FILE *inf);