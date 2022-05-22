/*
----------------------------------------------------
Masrik Dahir
Date: 04/15/2022

---------------------------------------------------
Usage Guide
(1) gcc Tokenizer.c -o Tokenizer
(2) ./Tokenizer

----------------------------------------------------
*/

#include "Tokenizer.h"

/* 
Check if the current character is part of number set
*/
_Bool is_excepted_number(int current){
    if (current >= '0' && current <= '9'){
        return TRUE;
    }
    return FALSE;
}

/* 
Check if the current character is part of the alphabet set
*/
_Bool is_excepted_string(int current){
    if ((current >= 'a' && current <= 'z') || (current >= 'A' && current <= 'Z') ){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

/* 
Check if the current character is part of syntax set
*/
_Bool is_excepted_syntax(int current){
    if (current == '(' || current == ')' || current == '{' || current == '}' || current == ','|| current == ';'|| current == '='|| current == '!'){
        return TRUE;
    }
    return FALSE;
}

/* 
Check if the current character is part of aritmatic sign set
*/
_Bool is_excepted_arithmatic(int current){
    if (current == '+' || current == '*' || current == '%'){
        return TRUE;
    }
    return FALSE;
}

/* 
Return the fisrt character of the string
*/
char get_first_charater(FILE* inf,char first[]) {
    fpos_t pos;

    // Retrieves the current position in FILE* inf
    fgetpos(inf, &pos);

    // Reads characters from FILE* inf
    fgets(first,MY_CHAR_MAX, inf);

    // Restores the current position in the FILE* inf to &pos
    fsetpos(inf, &pos);
    return first[0];
}

/* 
Return the next character of the current character 
*/
char get_next_charater(FILE* inf) {
    fpos_t pos;
    char current; 

    // Retrieves the current position in FILE* inf
    fgetpos(inf, &pos);

    // Reads characters from FILE* inf and set it to current
    current = fgetc(inf);

    // Restores the current position in the FILE* inf to &pos
    fsetpos(inf, &pos);
    return current;
}

/* 
Return NUMBER token type after tokenizing 
*/
int get_nonterminal_number (FILE* inf, char current, char* string,int *numLex) {
    // Settin default size for char* string
    int size = 1;

    // the first character of char* string is set to current
    string[0] = current;

    // while the next character is a number, we assign next value of 
    // string as the next value of current.
    // Then, increase the size by 1
    while (is_excepted_number(get_next_charater(inf))) {
        (current = fgetc(inf));
        string[size] = current;
        size++;
    }

    // Close the String by setting the last value as '\0'
    string[size] = '\0';
    return NUMBER;
}

/* 
Return reserved strings type (i.e., WHILE_KEYWORD, RETURN_KEYWORD, and
 VARTYPE) token after tokenizing 
*/
int get_nonterminal_reserved_string(char* string) {
    
    // If the string is equal to "while" return WHILE_KEYWORD
    if (strcmp(string, "while") == 0) {
        return WHILE_KEYWORD;
    } 
    // If the string is equal to "!=" return BINOP
    else if (strcmp(string, "!=") == 0) {
        return BINOP;
    } 
    // If the string is equal to "==" return BINOP
    else if (strcmp(string, "==") == 0) {
        return BINOP;
    } 
    // If the string is equal to "return" return RETURN_KEYWORD
    else if (strcmp(string, "return") == 0) {
        return RETURN_KEYWORD;
    } 
    // If the string is equal to "int" or "void" return VARTYPE
    else if (strcmp(string, "int") == 0 || strcmp(string, "void") == 0) {
        return VARTYPE;
    }
    // return -1 to identify that string is not a reserved string
    else{
        return -1;
    }
}

/* 
Return nonreserved strings type (i.e., variable names) token after tokenizing 
*/
int get_nonterminal_string(FILE *inf, char current, char* string,struct lexics *aLex,int *numLex) {
    // Settin default size for char* string
    int size = 1;
    
    // the first character of char* string is set to current
    string[0] = current;

    // while the next character is a number, we assign next value of 
    // string as the next value of current.
    // Then, increase the size by 1
    while (( is_excepted_string(get_next_charater(inf)) || is_excepted_number(get_next_charater(inf)) )) {
        current = fgetc(inf);
        string[size] = current;
        size++;
    }
    
    // Close the String by setting the last value as '\0'
    string[size] = '\0';

    // get the reserved string result from get_nonterminal_reserved_string(char* string) function
    enum token result = get_nonterminal_reserved_string(string);

    // if the result equals -1 we return IDENTIFIER else the reserved varaibel token type
    if (result == -1) {
        return IDENTIFIER ;
    }
    return result;
    
}

/* 
Return syxtan type (i.e., LEFT_PARENTHESIS, RIGHT_PARENTHESIS
LEFT_BRACKET, RIGHT_BRACKET, WHILE_KEYWORD, RETURN_KEYWORD,
EQUAL, COMMA, and EOL) and "==" and "!=" token after tokenizing 
*/
int get_nonterminal_syntax(FILE* inf, char current, char* string,struct lexics *aLex,int *numLex) {
    // Settin default size for char* string
    int size = 1;

    // the first character of char* string is set to current
    string[0] = current;

    // If the next character is "=" and current character is "!",
    // we tokenize the combined string of "!="
    if ( current == '!' && get_next_charater(inf) == '='  ) {
        (current = fgetc(inf));
        string[size] = current;
        size++;
    }
    // If the next character is "=" and current character is "=",
    // we tokenize the combined string of "=="
    else if ( current == '=' && get_next_charater(inf) == '='  ) {
        (current = fgetc(inf));
        string[size] = current;
        size++;
    }

    // Close the String by setting the last value as '\0'
    string[size] = '\0';

    // If the string is equal to "(" return LEFT_PARENTHESIS
    if (strcmp(string, "(") == 0) {
        return LEFT_PARENTHESIS;
    } 
    // If the string is equal to "==" return BINOP
    else if (strcmp(string, "==") == 0) {
        return BINOP ;
    } 
    // If the string is equal to "!=" return BINOP
    else if (strcmp(string, "!=") == 0) {
        return BINOP;
    } 
    // If the string is equal to ")" return RIGHT_PARENTHESIS
    else if (strcmp(string, ")") == 0) {
        return RIGHT_PARENTHESIS;
    } 
    // If the string is equal to "{" return LEFT_BRACKET
    else if (strcmp(string, "{") == 0) {
        return LEFT_BRACKET;
    } 
    // If the string is equal to "}" return RIGHT_BRACKET
    else if (strcmp(string, "}") == 0) {
        return RIGHT_BRACKET;
    } 
    // If the string is equal to "=" return EQUAL
    else if (strcmp(string, "=") == 0) {
        return EQUAL;
    } 
    // If the string is equal to "," return COMMA
    else if (strcmp(string, ",") == 0) {
        return COMMA;
    } 
    // If the string is equal to ";" return EOL
    else if (strcmp(string, ";") == 0) {
        return EOL;
    } 
    // ELSE return BINOP
    else {
        return BINOP;
    }
}

/* 
Return arithmatic type (i.e., BINOP) token after tokenizing 
*/
int get_nonterminal_arithmatic(FILE* inf, char current, char* string,struct lexics *aLex,int *numLex) {
    // Settin default size for char* string
    int size = 1;

    // the first character of char* string is set to current
    string[0] = current;

    // Close the String by setting the last value as '\0'
    string[size] = '\0';

    // return BINOP
    return BINOP;
    
}

/* 
Read characters from the given FILE parameter and
create lexemes and the associated tokens
*/
_Bool tokenizer(struct lexics *aLex, int *numLex, FILE *inf){
    char first[MY_CHAR_MAX];
    char last[MY_CHAR_MAX];
    char current;

    // Get the first character of the input to pass it into the while loop
    get_first_charater(inf,first);

    // Set current variable to character currently pointed by the internal file position indicator of the inf
    current = fgetc(inf);

    // WHILE the end-of-File indicator associated with stream is set, we run the loop
    while(feof(inf)<1){
        while (current == ' ' || current == '\t' || current == '\n' 
        || current == '\r' || current == '\v' || current == '\f') {
            // Set current variable to character currently pointed by the internal file position indicator of the inf
            current = fgetc(inf);   
        }

        // IF current variable is a number, we pass the parameters to get_nonterminal_number() function
        if(is_excepted_number(current)){
            aLex[*numLex].token = get_nonterminal_number(inf,current,last,numLex);
            strcpy(aLex[*numLex].lexeme,last);
        }

        // IF current variable is a string, we pass the parameters to get_nonterminal_string() function
        else if(is_excepted_string(current)){
            aLex[*numLex].token = get_nonterminal_string(inf,current,last,aLex,numLex);
            strcpy(aLex[*numLex].lexeme,last);
        }

        // IF current variable is a syntax, we pass the parameters to is_excepted_syntax() function
        else if(is_excepted_syntax(current)){
            aLex[*numLex].token = get_nonterminal_syntax(inf,current,last,aLex,numLex);
            strcpy(aLex[*numLex].lexeme,last);
        }

        // IF current variable is a arithmatic, we pass the parameters to get_nonterminal_arithmatic() function
        else if(is_excepted_arithmatic(current)){
            aLex[*numLex].token = get_nonterminal_arithmatic(inf,current,last,aLex,numLex);
            strcpy(aLex[*numLex].lexeme,last);
        }
        
        // Increment numLex
        *numLex = *numLex + 1;

        // Set current variable to character currently pointed by the internal file position indicator of the inf
        current = fgetc(inf);
    }

    return TRUE;
}

int main(void)
{
    printf("Hello world!\n");
    return 0;
}