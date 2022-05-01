%{
#include<stdio.h>
#include<stdlib.h>
int yyerror(char *s);
int yylex();
%}
%token ZERO ONE TWO THREE FOUR
%%
N: L {printf("\n%d\n",$$);}
L: L B {$$=$1*5+$2;}
| B {$$=$1;}
B:ZERO {$$=$1;}
|ONE {$$=$1;}
|TWO {$$=$1;}
|THREE {$$=$1;}
|FOUR {$$=$1;};
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