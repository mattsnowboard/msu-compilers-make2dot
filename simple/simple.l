%{
/*
* Lex file for simple.y
*/

#include "y.tab.h"

%}
%%

a { return A; }
b { return B; }
c { return C; }
\n {}
. { return yytext[0]; }

%%

int yywrap()
{
    return 1;
}
