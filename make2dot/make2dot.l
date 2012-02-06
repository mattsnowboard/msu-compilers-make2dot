%{
/*
* Lex file for make2dot.l
*/

#include "y.tab.h"

%}
%%

":" { return yytext[0]; }
[a-zA-Z.]+ { return WORD; }
^"\t".+ { return COMMAND; }
[\n.] {}


%%

int yywrap()
{
    return 1;
}
