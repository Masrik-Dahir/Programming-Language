/*
----------------------------------------------------
Masrik Dahir
Date: 04/15/2022

---------------------------------------------------
Usage Guide
(1) gcc Parser.c -o Parser
(2) ./Parser

----------------------------------------------------
*/


# include "Parser.h"

int index = 0;

/*
verification: expression --> term {BINOP term} | LEFT_PARENTHESIS expression RIGHT_PARENTHESIS 
*/
_Bool _expression(struct lexics *someLexics, int numberOfLexics){

    // Setting result to False
    _Bool result = FALSE;

    // IF the current someLexics token is IDENTIFIER or NUMBER
    if(someLexics[index].token==IDENTIFIER || someLexics[index].token==NUMBER){

        // IF the _term(someLexics, numberOfLexics) function is true
        if (_term (someLexics, numberOfLexics)){
            
            // IF the current someLexics token is BINOP
            if(someLexics[index].token==BINOP){
                index++;

                // IF the _term(someLexics, numberOfLexics) function is true
                if( _term(someLexics, numberOfLexics)){
                    result = TRUE;
                }

                else{
                    result = FALSE;
                }
            }
            result = TRUE;
        }
        else{
            result = FALSE;
        }
        
    }

    // IF the current someLexics token is LEFT_PARENTHESIS
    else if(someLexics[index].token==LEFT_PARENTHESIS){

        // IF the current someLexics token is LEFT_PARENTHESIS
        if(someLexics[index].token==LEFT_PARENTHESIS){
            index++;

            // IF if(_expression(someLexics, numberOfLexics) function is true
            if(_expression(someLexics, numberOfLexics)){

                // IF the current someLexics token is RIGHT_PARENTHESIS
                if (someLexics[index].token==RIGHT_PARENTHESIS){
                    index++;

                    result = TRUE;

                }
                else{
                    result = FALSE;
                }
            }

        }
    }
    return result;
    
}

/*
verification: term --> IDENTIFIER | NUMBER  
*/
_Bool _term (struct lexics *someLexics, int numberOfLexics){

    // Setting result to False
    _Bool result = FALSE;

    // IF the current someLexics token is IDENTIFIER
    if(someLexics[index].token==IDENTIFIER){
        index++;

        result = TRUE;
    }

    // ELSE IF the current someLexics token is NUMBER
    else if(someLexics[index].token==NUMBER){
        index++;

        result = TRUE;
    }
    return result;
}

/*
verification: assignment --> IDENTIFIER EQUAL expression EOL
*/
_Bool _assignment(struct lexics *someLexics, int numberOfLexics){
    
    // Setting result to False
    _Bool result = FALSE;

    // IF the current someLexics token is IDENTIFIER
    if(someLexics[index].token==IDENTIFIER){
        index++;

        // IF the current someLexics token is EQUAL
        if(someLexics[index].token==EQUAL){
            index++;

            // IF _expression(someLexics, numberOfLexics) function is true
            if(_expression(someLexics, numberOfLexics)){
                
                // IF the current someLexics token is EOL
                if(someLexics[index].token==EOL){
                    index++;

                    result = TRUE;
                }
            }
        }
    }
    return result;
}

/*
verification: return --> RETURN_KEYWORD expression EOL
*/
_Bool _return(struct lexics *someLexics, int numberOfLexics){
    
    // Setting result to False
    _Bool result = FALSE;

    // IF the current someLexics token is RETURN_KEYWORD
    if(someLexics[index].token==RETURN_KEYWORD){
        index++;

        // IF _expression(someLexics, numberOfLexics) function is true
        if(_expression(someLexics, numberOfLexics)){

            // IF the current someLexics token is EOL
            if(someLexics[index].token==EOL){
                index++;

                result = TRUE;
            }
            else{
                result = FALSE;
            }
        }
    }
    return result;

}

/*
verification: while-loop --> WHILE_KEYWORD LEFT_PARENTHESIS expression RIGHT_PARENTHESIS statement
*/ 
_Bool _while_loop(struct lexics *someLexics, int numberOfLexics){
   
   // Setting result to False
    _Bool result = FALSE;

    // IF the current someLexics token is WHILE_KEYWORD
    if(someLexics[index].token==WHILE_KEYWORD){
        index++;

        // IF the current someLexics token is LEFT_PARENTHESIS
        if (someLexics[index].token==LEFT_PARENTHESIS){
            index++;

            // IF _expression(someLexics, numberOfLexics) function is true
            if(_expression(someLexics, numberOfLexics)){
                
                // IF the current someLexics token is RIGHT_PARENTHESIS
                if(someLexics[index].token==RIGHT_PARENTHESIS){
                    index++;

                    // IF _statement(someLexics, numberOfLexics) function is true
                    if(_statement(someLexics, numberOfLexics)){
                        result = TRUE;
                    }
                }
            }
        }
    }
    return result;


}

/*
verification: statement --> while-loop | return | assignment | body 
*/
_Bool _statement(struct lexics *someLexics, int numberOfLexics){
    
    // Setting result to False
    _Bool result = FALSE;

    // IF the current someLexics token is WHILE_KEYWORD
    if (someLexics[index].token==WHILE_KEYWORD){

        // IF _while_loop(someLexics, numberOfLexics) function is true
        if(_while_loop(someLexics, numberOfLexics)){
            result = TRUE;
        }
        else{
            result = FALSE;
        }
    }

    // IF the current someLexics token is RETURN_KEYWORD
    else if (someLexics[index].token==RETURN_KEYWORD){

        // IF if(_return(someLexics, numberOfLexics) function is true
        if(_return(someLexics, numberOfLexics)){
            result = TRUE;
        }
        else{
            result = FALSE;
        }
    }
    
    // IF the current someLexics token is IDENTIFIER
    else if (someLexics[index].token==IDENTIFIER){

        // IF if(_assignment(someLexics, numberOfLexics) function is true
        if(_assignment(someLexics, numberOfLexics)){
            result = TRUE;
        }
        else{
            result = FALSE;
        }
    }

    // IF the current someLexics token is LEFT_BRACKET
    else if (someLexics[index].token==LEFT_BRACKET){

        // IF if(_body(someLexics, numberOfLexics) function is true
        if (result = _body(someLexics, numberOfLexics)){
            result = TRUE;
        }
    }

    // IF the current someLexics token is RIGHT_BRACKET
    else if (someLexics[index].token==RIGHT_BRACKET){
        result = TRUE;
    }
    return result;
}

/*
verification: statement-list --> statement {statement} 
*/ 
_Bool _statement_list(struct lexics *someLexics, int numberOfLexics){
   
   // Setting result to False
    _Bool result = FALSE;
    
    // IF the current someLexics token is WHILE_KEYWORD or RETURN_KEYWORD or IDENTIFIER or LEFT_BRACKET
    if(someLexics[index].token==WHILE_KEYWORD || someLexics[index].token==RETURN_KEYWORD 
    || someLexics[index].token==IDENTIFIER || someLexics[index].token==LEFT_BRACKET){
        
        // while the current someLexics token is WHILE_KEYWORD or RETURN_KEYWORD or IDENTIFIER or LEFT_BRACKET
        while (someLexics[index].token==WHILE_KEYWORD || someLexics[index].token==RETURN_KEYWORD 
        || someLexics[index].token==IDENTIFIER || someLexics[index].token==LEFT_BRACKET){
            
            // IF _statement(someLexics, numberOfLexics) function is true
            if (_statement(someLexics, numberOfLexics)){
                result = TRUE;
            }
            else{
                result = FALSE;
                break;
            }
        }
    }
    else{
        result = TRUE;
    }
    return result;
}

/*
verification: arg-decl --> VARTYPE IDENTIFIER {COMMA VARTYPE IDENTIFIER} 
*/
_Bool _arg_decl(struct lexics *someLexics, int numberOfLexics){
    
    // Setting result to False
    _Bool result = FALSE;

    // IF the current someLexics token is VARTYPE
    if(someLexics[index].token==VARTYPE){
        index++;

        // IF the current someLexics token is IDENTIFIER
        if(someLexics[index].token==IDENTIFIER){
            index ++;

            // IF the current someLexics token is COMMA
            if (someLexics[index].token==COMMA){
                index ++;
                
                // IF _arg_decl(someLexics, numberOfLexics) function is true
                if(_arg_decl(someLexics, numberOfLexics)){
                    result = TRUE;
                }
                else{
                    result = FALSE;
                }
            }
            result = TRUE;
        }
        else{
            result = FALSE;
        }
    }
    return result;
}

/*
verification: header --> VARTYPE IDENTIFIER LEFT_PARENTHESIS [arg-decl] RIGHT_PARENTHESIS 
*/ 
_Bool _header(struct lexics *someLexics, int numberOfLexics){
    
    // Setting result to False
    _Bool result = FALSE;

    // IF the current someLexics token is VARTYPE
    if(someLexics[index].token==VARTYPE){
        index ++;

        // IF the current someLexics token is IDENTIFIER
        if(someLexics[index].token==IDENTIFIER){
            index ++;

            // IF the current someLexics token is LEFT_PARENTHESIS
            if(someLexics[index].token==LEFT_PARENTHESIS){
                index ++;

                // IF _arg_decl(someLexics, numberOfLexics) function is true
                if( _arg_decl(someLexics, numberOfLexics)){

                    // IF the current someLexics token is RIGHT_PARENTHESIS
                    if(someLexics[index].token==RIGHT_PARENTHESIS){
                        index ++;

                        result = TRUE;
                    }
                }
                else{
                    
                    // IF the current someLexics token is RIGHT_PARENTHESIS
                    if(someLexics[index].token==RIGHT_PARENTHESIS){
                        index ++;

                        result = TRUE;
                    }
                }
            }
        }
    }
    return result;
}

/*
verification: body --> LEFT_BRACKET [statement-list] RIGHT_BRACKET 
*/
_Bool _body(struct lexics *someLexics, int numberOfLexics){
    
    // Setting result to False
    _Bool result = FALSE;
    
    // IF the current someLexics token is LEFT_BRACKET
    if(someLexics[index].token==LEFT_BRACKET){
        index ++;

        // IF _statement_list(someLexics, numberOfLexics) function is true
        if(_statement_list(someLexics, numberOfLexics)){

            // IF the current someLexics token is RIGHT_BRACKET
            if(someLexics[index].token==RIGHT_BRACKET){
                index ++;

                result = TRUE;
            }
            else{

                // IF the current someLexics token is RIGHT_BRACKET
                if(someLexics[index].token==RIGHT_BRACKET){
                    index ++;

                    result = TRUE;
                }
                else{
                    result = FALSE;
                }
            }
        }
    }
    return result;
}

/*
verification: function --> header body
*/
_Bool _function (struct lexics *someLexics, int numberOfLexics){
    
    // Setting result to False
    _Bool result = FALSE;

    // While the current someLexics token is not '\0'
    while (someLexics[index].token != '\0'){

        // IF _header(someLexics, numberOfLexics) and _body(someLexics, numberOfLexics) function is true
        if(_header(someLexics, numberOfLexics) && _body(someLexics, numberOfLexics)){
            result = TRUE;
        }
        else{
            result = FALSE;
            break;

        }
    }
    return result;
}

/*
akes an array of type lexics and an int pointer representing 
the number of tokens in the given lexics array. 
*/
_Bool parser(struct lexics *someLexics, int numberOfLexics){
    
    // Setting result to False
    _Bool result = FALSE;

    // IF _function(someLexics, numberOfLexics) function is True
    if(_function(someLexics,numberOfLexics)){
        result = TRUE;
    }

    return result;
}

int main(void)
{
    printf("Hello world!\n");
    return 0;
}