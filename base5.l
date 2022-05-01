/*
 __             ___    ___       ___     __     __       ___  ___ 
/__`  /\  \  / |__      |  |__| |__     |__) | |__)  /\   |  |__  
.__/ /~~\  \/  |___     |  |  | |___    |    | |  \ /~~\  |  |___ 
                                                                  
*/
%{
#include<stdio.h>
#include<stdlib.h>
#include"y.tab.h"
extern int yylval;
%}
%%
0 {yylval=0;return ZERO;}
1 {yylval=1;return ONE;}
2 {yylval=2;return TWO;}
3 {yylval=3;return THREE;}
4 {yylval=4;return FOUR;}
[ \t] {;}
\n return 0;
. return yytext[0];
%%