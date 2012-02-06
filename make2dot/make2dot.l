%{
/*
* Lex file for make2dot.l
*/

#include "y.tab.h"

%}
%%

":" { cppPrint(yytext); return yytext[0]; }
[a-zA-Z._-]+ { cppPrint("WORD"); return WORD; }
[ \t\n]*"#".+ { cppPrint("COMMENT"); }
^"\t".+ { cppPrint("COMMAND"); return COMMAND; }
. {}


%%

int yywrap()
{
    return 1;
}
