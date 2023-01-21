/* MERT GURSIMSIR                               */
/* 1901042646                                   */
/* CSE 341 - PROGRAMMING LANGUAGES FALL 2022    */

/*
TO RUN THE PROGRAM YOU CAN TYPE FOLLOWING COMMAND: "gcc -g gpp_lexer.c gpp_interpreter.c -o gpp_interpreter.out"

Then run the executable by:
    "./gpp_interpreter.out"
*/

/*
Example function definition:
    (deffun mert () (progn (+ 1f1 2f1)))
Example function call:
    (mert)
Example explist:
    (progn (+ 1f1 2f1))
    (progn (+ 1f1 2f1) (* 1f1 2f1))
*/

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    #include "gpp_interpreter.h"

    int yylex(void);
    void yyerror(char *);

    float setID(char*, float);
    float defineID(char*, float, bool);
    float getIDValue(char*);
    void functionProcess(char*, int, float);
    float functionCall(char*, int);

    //Map simulation for variables to hold id's values (ID, value)
    typedef struct variable{
        char ID[256];
        float value; 
    }variable;

    typedef struct variableContainer{
        int size;
        variable* variables;
    }variableContainer;

    //Properties of Functions:
    /*
        Number of parameters
        Values of parameters
        Names of parameters
        Name of the function
        Return value
    */
    typedef struct function{
        int parameter_number;
        float parameter_values[3];
        char parameter_names[3][256];
        char name[16];
        float return_value;
    }function;

    typedef struct functionContainer{
        int size;
        function* functions;
    }functionContainer;

    float parameterVals[3];
    char parameterNames[3][256];
%}

%union {
    float value;
    bool boolean;
    char ID[256];
}

%start INPUT

%token KW_PROGN KW_GT KW_AND KW_OR KW_NOT KW_EQUAL KW_LESS KW_NIL KW_LIST KW_APPEND KW_CONCAT KW_SET KW_DEFFUN KW_FOR KW_IF KW_EXIT KW_LOAD KW_DISP KW_TRUE KW_FALSE KW_WHILE DEFV
%token OP_PLUS OP_MINUS OP_DIV OP_MULT OP_OP OP_CP OP_DBLMULT OP_OC OP_CC OP_COMMA
%token COMMENT
%token <ID> IDENTIFIER
%token <value> VALUEF VALUEI

%type <value> INPUT EXP EXPLIST EXPLISTHELP FUNCTION FCALL PARAMETERS ARGUMENTS ASG
%type <boolean> EXPB

%%

INPUT: 
    COMMENT {;}
    |
    OP_OP KW_EXIT OP_CP {printf("Have a wonderful day!\n"); exit(1);}
    |
    EXP {printf("Syntax OK.\nResult: %f\n\n> ", $1);}
    |
    EXPB {printf("Syntax OK.\nResult: "); if($1) printf("True\n\n> "); else printf("False\n\n> ");}
    | 
    EXPLIST {printf("Syntax OK.\nResult: %f\n\n> ", $1);}
    |
    FUNCTION {printf("Syntax OK.\nResult: %f\n\n> ", $1);}
    |
    INPUT COMMENT {printf("Syntax OK.\nComment.\n\n> ");}
    |
    INPUT EXP {printf("Syntax OK.\nResult: %f\n\n> ", $2);}
    |
    INPUT EXPB {printf("Syntax OK.\nResult: "); if($2) printf("True\n\n> "); else printf("False\n\n> ");}
    |
    INPUT EXPLIST {printf("Syntax OK.\nResult: %f\n\n> ", $2);}
    |
    INPUT FUNCTION {printf("Syntax OK.\nFunction definition.\nResult: %f\n\n> ", $2);}
    ;

EXP:
    OP_OP OP_PLUS EXP EXP OP_CP {$$ = $3 + $4;}
    |
    OP_OP OP_MINUS EXP EXP OP_CP {$$ = $3 - $4;}
    |
    OP_OP OP_MULT EXP EXP OP_CP {$$ = $3 * $4;}
    |
    OP_OP OP_DIV EXP EXP OP_CP {$$ = $3 / $4;}
    |
    IDENTIFIER {$$ = getIDValue($1);}
    |
    VALUEF {$$ = $1;}
    |
    OP_OP KW_IF EXPB EXPLIST EXPLIST OP_CP {if ($3) $$ = $4; else $$ = $5;}
    |
    FCALL {$$ = $1;}
    |
    OP_OP KW_WHILE EXPB EXPLIST OP_CP   {if ($3) $$ = $4; else $$ = 0.0;}
    |
    OP_OP DEFV IDENTIFIER EXP OP_CP {$$ = defineID($3, $4, false);}
    |
    ASG {$$ = $1;}
    ;

ASG:
    OP_OP KW_SET IDENTIFIER EXP OP_CP {$$ = setID($3, $4);}
    ;

EXPB:
    OP_OP KW_EQUAL EXP EXP OP_CP {$$ = ($3 == $4);}
    |
    OP_OP KW_GT EXP EXP OP_CP {$$ = ($3 > $4);}
    |
    KW_TRUE {$$ = true;}
    |
    KW_FALSE {$$ = false;}
    |
    OP_OP KW_AND EXPB EXPB OP_CP {$$ = $3 && $4;}
    |
    OP_OP KW_OR EXPB EXPB OP_CP {$$ = $3 || $4;}
    |
    OP_OP KW_NOT EXPB OP_CP {$$ = !$3;}
    ;

EXPLIST:
    OP_OP KW_PROGN EXPLISTHELP EXP OP_CP {$$ = $4;}
    ;

EXPLISTHELP:
    /* empty */ {$$ = 0.0;}
    |
    EXPLISTHELP EXP {$$ = $2;}
    ;

FUNCTION:
    OP_OP KW_DEFFUN IDENTIFIER OP_OP PARAMETERS OP_CP EXPLIST OP_CP {functionProcess($3, $5, $7); $$ = 0.0;}
    ;

PARAMETERS:
    /* empty */ {$$ = 0.0;}
    |
    IDENTIFIER {defineID($1, 0.0, true); strcpy(parameterNames[0], $1); $$ = 1.0;}
    |
    IDENTIFIER IDENTIFIER {defineID($1, 0.0, true); defineID($2, 0.0, true); strcpy(parameterNames[0], $1); strcpy(parameterNames[1], $2); $$ = 2.0;}
    |
    IDENTIFIER IDENTIFIER IDENTIFIER {defineID($1, 0.0, true); defineID($2, 0.0, true); defineID($3, 0.0, true); strcpy(parameterNames[0], $1); strcpy(parameterNames[1], $2); strcpy(parameterNames[2], $3); $$ = 3.0;}
    ;

FCALL:
    OP_OP IDENTIFIER ARGUMENTS OP_CP {$$ = functionCall($2, $3);}
    ;

ARGUMENTS:
    /* empty */ {$$ = 0.0;}
    |
    EXP {parameterVals[0] = $1; $$ = 1.0;}
    |
    EXP EXP {parameterVals[0] = $1; parameterVals[1] = $2; $$ = 2.0;}
    |
    EXP EXP EXP {parameterVals[0] = $1; parameterVals[1] = $2; parameterVals[2] = $3; $$ = 3.0;}
    ;

%%

variableContainer array;
functionContainer functionArray;

float functionCall(char* str, int parameters){
    for (int i = 0; i < functionArray.size; ++i){
        if (strcmp(functionArray.functions[i].name, str) == 0){
            if (functionArray.functions[i].parameter_number != parameters){
                printf("Unmatched parameter number.\n");
                exit(EXIT_FAILURE);
            }
            else{
                for (int j = 0; j < parameters; ++j){
                    functionArray.functions[i].parameter_values[j] = parameterVals[j];
                }
                
                return functionArray.functions[i].return_value;
            }
        }
    }

    printf("There is no function named %s.\n", str);
    exit(EXIT_FAILURE);
}

void functionProcess(char* str, int parameters, float returnVal){
    //ERROR
    for (int i = 0; i < functionArray.size; ++i){
        if (strcmp(functionArray.functions[i].name, str) == 0){
            printf("Function %s is already defined.\n", str);
            exit(EXIT_FAILURE);
        }
    }

    //Add new function name to functions array.
    if (functionArray.size != 0){
        functionArray.functions = (function*)realloc(functionArray.functions, sizeof(function)*(functionArray.size + 1));
    }
    else{
        functionArray.functions = (function*)calloc(1, sizeof(function));
    }

    //Assigning parameter names
    for (int i = 0; i < parameters; ++i){
        strcpy(functionArray.functions[functionArray.size].parameter_names[i], parameterNames[i]);
    }
    functionArray.functions[functionArray.size].parameter_number = parameters;
    functionArray.functions[functionArray.size].return_value = returnVal;
    strcpy(functionArray.functions[functionArray.size].name, str);
    functionArray.size = functionArray.size + 1;

    array.size = array.size - parameters;
}

float defineID(char* str, float val, bool functionFlag){
    //Control if function is already defined
    if (!functionFlag){
        for (int i = 0; i < array.size; ++i){
                if (strcmp(array.variables[i].ID, str) == 0){
                    printf("Variable %s is already defined.\n", str);
                    exit(EXIT_FAILURE);
                }
            }
    }
    
    //Reallocate array of variables
    if (array.size != 0){
        array.variables = (variable*)realloc(array.variables, sizeof(variable)*(array.size + 1));
    }
    else{
        array.variables = (variable*)calloc(1, sizeof(variable));
    }
    //Assign value and increment size by one
    array.variables[array.size].value = val;
    strcpy(array.variables[array.size].ID, str);
    array.size = array.size+1;

    return val;
}

float setID(char* str, float val){
    //Find and change value of a variable
    for (int i = 0; i < array.size; ++i){
        if (strcmp(array.variables[i].ID, str) == 0){
            array.variables[i].value = val;
            return val;
        }
    }
    //ERROR
    printf("Variable %s is never defined before.\n", str);
    exit(EXIT_FAILURE);
}

float getIDValue(char* str){
    //Find the variable
    for (int i = array.size-1; i >= 0; --i){
        if (strcmp(array.variables[i].ID, str) == 0) return array.variables[i].value;
    }
    //ERROR
    printf("Variable %s is never defined before.\n", str);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv){
    array.size = 0;
    array.variables = NULL;
    functionArray.size = 0;
    functionArray.functions = NULL;
    printf("WELCOME TO G++ LANGUAGE SYNTAX ANALYZER. ENTER YOUR INPUTS ONE BY ONE.\n");
    printf("Note: new progn keyword is added for explist. Examples:\n(progn (+ 1f1 2f1))\n(progn (+ 1f1 2f1) (* 1f1 2f1))\n");
    printf("----------------------------------------------------------------------\n");
    while(true){
        printf("\n> ");
        yyparse();
    }
    return 0;
}

void yyerror (char *s) {printf("SYNTAX_ERROR Expression not recognized\n"); exit(EXIT_FAILURE);}