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
5 {yylval=5;return FIVE;}
6 {yylval=6;return SIX;}
7 {yylval=7;return SEVEN;}
8 {yylval=8;return EIGHT;}
9 {yylval=9;return NINE;}
a {yylval=10;return A;}
b {yylval=11;return B;}
c {yylval=12;return C;}
d {yylval=13;return D;}
e {yylval=14;return E;}
f {yylval=15;return F;}
[ \t] {;}
\n return 0;
. return yytext[0];
%%