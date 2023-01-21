/* MERT GURSIMSIR                               */
/* 1901042646                                   */
/* CSE 341 - PROGRAMMING LANGUAGES FALL 2022    */

/* First you should write these two in order: "flex gpp_lexer.l" AND "gcc lex.yy.c"    */
/* You can run the REPL by --> ./a.out                     <---------------------- */
/* You can read the file by -> ./a.out test.txt            <---------------------- */

%{
    /* definitions */
    int flag = 0;
%}

/* rules */
%%
    /*KEYWORDS*/
and {printf("and: KW_AND\n");}
or {printf("or: KW_OR\n");}
not {printf("not: KW_NOT\n");}
equal {printf("equal: KW_EQUAL\n");}
less {printf("less: KW_LESS\n");}
nil {printf("nil: KW_NIL\n");}
list {printf("list: KW_LIST\n");}
append {printf("append: KW_APPEND\n");}
concat {printf("concat: KW_CONCAT\n");}
set {printf("set: KW_SET\n");}
deffun {printf("deffun: KW_DEFFUN\n");}
for {printf("for: KW_FOR\n");}
if {printf("if: KW_IF\n");}
load {printf("load: KW_LOAD\n");}
disp {printf("disp: KW_DISP\n");}
true {printf("true: KW_TRUE\n");}
false {printf("false: KW_FALSE\n");}
exit {printf("exit: KW_EXIT\n");}
!exit {printf("Have a wonderful day!\n"); return 0;}

    /*OPERATORS*/
[+] {printf("+: OP_PLUS\n");}
[-] {printf("-: OP_MINUS\n");}
[/] {printf("/: OP_DIV\n");}
[*] {printf("*: OP_MULT\n");}
[(] {printf("(: OP_OP\n");}
[)] {printf("): OP_CP\n");}
[*]{2} {printf("**: OP_DBLMULT\n");}
["] {printf("\": OP");
        if (flag == 1) { printf("_CC\n"); flag = 0; }
        else { printf("_OC\n"); flag = 1;}
    }
["].+["] {printf("\": OP_OC\n%s: VALUESTR\n\": OP_CC\n", yytext);}
[,] {printf(",: OP_COMMA");}

    /*OTHERS*/
[;]{2}.* {printf("%s: COMMENT\n", yytext);}
[0][0-9]+ {printf("LEXICAL ERROR --> %s\n", yytext);}
[0] {printf("%s: VALUEI\n", yytext);}
[1-9][0-9]* {printf("%s: VALUEI\n", yytext);}
[0-9]+f[0]{2}[0]* {printf("LEXICAL ERROR: %s\n", yytext);}
[0]{2}[0]*+f[0-9]* {printf("LEXICAL ERROR: %s\n", yytext);}
[0-9]+f[0-9]+ {printf("%s: VALUEF\n", yytext);}
[0-9]+[a-zA-Z_.]+[0-9]* {printf("LEXICAL ERROR --> %s\n", yytext);}
[a-zA-Z_][a-zA-Z0-9_]* {printf("%s: IDENTIFIER\n", yytext);}


[ ]  {;}
[\t] {;}
[\n] {;}
[[:space:]]+ {;}

. {printf("ERROR: %s\n", yytext);}

%%

int yywrap() {}

int main(int argc, char** argv){

    if (argc == 1) printf("WELCOME! You can enter your inputs below - Print \"!exit\" to exit.\n");
    else if (argc == 2){
        FILE *filepointer;
        filepointer = fopen(argv[1], "r");
        yyin = filepointer;
    }
    else{
        printf("Invalid arguments, exiting...\n");
        return -1;
    }
    
    yylex();    //take input, do the rule matching
    return 0;
}