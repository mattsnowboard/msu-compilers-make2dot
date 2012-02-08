%{
/*
* Lex file for make2dot.l
*/

#include "y.tab.h"

#include <string.h> // strdup

%}
%%

":"|"=" {
    //cppPrint(yytext);
    return yytext[0];
}
[a-zA-Z0-9._-]+ {
    //cppPrint("WORD");
    yylval.s = strdup(yytext);
    return WORD;
}
"$("[a-zA-Z][a-zA-Z0-9]*")" {
    //cppPrint("VARIABLE");
    yylval.s = strdup(yytext);
    return VARIABLE;
}
[ \t]*"#".*"\n" {
    //cppPrint("COMMENT");
}
^"\t".+ {
    //cppPrint("COMMAND");
    yylval.s = strdup(yytext);
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
