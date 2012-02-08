%{
/*
* Lex file for make2dot.l
*/

#include "y.tab.h"

%}
%%

":" {
    //cppPrint(yytext);
    return yytext[0];
}
[a-zA-Z0-9._-]+ {
    //cppPrint("WORD");
    yylval.s = yytext;
    return WORD;
}
[ \t]*"#".*"\n" {
    //cppPrint("COMMENT");
}
^"\t".+ {
    //cppPrint("COMMAND");
    yylval.s = yytext;
    return COMMAND;
}
^"\n" {
    //cppPrint("Lone NEWLINE");
}
"\n" {
    //cppPrint("NEWLINE");
    return yytext[0];
}
. {}


%%

int yywrap()
{
    return 1;
}
