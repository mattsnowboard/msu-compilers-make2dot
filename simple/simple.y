%{
/*
 * My first Bison Program
 */
#include "stdio.h"
%}

%token A B C

%%
E: '(' E ')' { cppPrint("E->LPAREN E RPAREN\n"); }
E: F { cppPrint("E -> F\n"); }
F: F B { cppPrint("F -> F B\n"); }
F: F A { cppPrint("F -> F A\n"); }
F: C { cppPrint("F -> C\n"); }
%%

