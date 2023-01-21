/* MERT GURSIMSIR                               */
/* 1901042646                                   */
/* CSE 341 - PROGRAMMING LANGUAGES FALL 2022    */

%{
    /* definitions */
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    #include "gpp_interpreter.h"
    int flag = 0;
%}

/* rules */
%%
    /*KEYWORDS*/
progn {return KW_PROGN;}
gt {return KW_GT;}
and {return KW_AND;}
or {return KW_OR;}
not {return KW_NOT;}
equal {return KW_EQUAL;}
less {return KW_LESS;}
nil {return KW_NIL;}
list {return KW_LIST;}
append {return KW_APPEND;}
concat {return KW_CONCAT;}
set {return KW_SET;}
deffun {return KW_DEFFUN;}
defvar {return DEFV;}
for {return KW_FOR;}
while {return KW_WHILE;}
if {return KW_IF;}
load {return KW_LOAD;}
disp {return KW_DISP;}
true {yylval.boolean = true; return KW_TRUE;}
false {yylval.boolean = false; return KW_FALSE;}
exit {return KW_EXIT;}

    /*OPERATORS*/
[+] {return OP_PLUS;}
[-] {return OP_MINUS;}
[/] {return OP_DIV;}
[*] {return OP_MULT;}
[(] {return OP_OP;}
[)] {return OP_CP;}
[*]{2} {return OP_DBLMULT;}
["] {
        if (flag == 1) { flag = 0; return OP_CC;}
        else { flag = 1; return OP_OC;}
    }
[,] {return OP_COMMA;}

    /*OTHERS*/
[;]{2}.* {return COMMENT;}
[0][0-9]+ {printf("LEXICAL ERROR --> Leading 0\n"); exit(EXIT_FAILURE);}
[0] {return VALUEI;}
[1-9][0-9]* {return VALUEI;}
[0-9]+f[0]{2}[0]* {printf("LEXICAL ERROR --> Invalid fraction\n"); exit(EXIT_FAILURE);}
[0]{2}[0]*+f[0-9]* {printf("LEXICAL ERROR --> Invalid fraction\n"); exit(EXIT_FAILURE);}
[0-9]+f[0-9]+ {yylval.value = atof(yytext)/atof(strchr(yytext, 'f')+1); return VALUEF;}
[0-9]+[a-zA-Z_.]+[0-9]* {printf("LEXICAL ERROR --> Invalid identifier\n"); exit(EXIT_FAILURE);}
[a-zA-Z_][a-zA-Z0-9_]* {strcpy(yylval.ID, yytext); return IDENTIFIER;}


[ ]  {;}
[\t] {;}
[\n] {;}
[[:space:]]+ {;}

. {printf("ERROR ---> Invalid input\n"); exit(EXIT_FAILURE);}

%%

int yywrap() {}