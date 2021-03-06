%{
#include<stdio.h>
#include<stdlib.h>
int yyerror(char *s);
int yylex();
%}
%token ZERO ONE TWO THREE FOUR FIVE SIX SEVEN EIGHT NINE A B C D E F
%%
N: L {printf("\n%d\n",$$);}
L: L S {$$=$1*16+$2;}
| S {$$=$1;}
S:ZERO {$$=$1;}
|ONE {$$=$1;}
|TWO {$$=$1;}
|THREE {$$=$1;}
|FOUR {$$=$1;}
|FIVE {$$=$1;}
|SIX {$$=$1;}
|SEVEN {$$=$1;}
|EIGHT {$$=$1;}
|NINE {$$=$1;}
|A {$$=$1;}
|B {$$=$1;}
|C {$$=$1;}
|D {$$=$1;}
|E {$$=$1;}
|F {$$=$1;};
%%
int main()
{
    while(yyparse());
}
int yyerror(char *s)
{
    fprintf(stdout,"\n%s",s);
    return 1;
}