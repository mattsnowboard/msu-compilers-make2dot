%{
/*
 * Make2dot Bison
 */

%}

%token WORD COMMAND

%%

DONE: TARGET ":" LIST { cppPrint("DONE -> TARGET : LIST"); }
TARGET: LIST ":" { cppPrint("TARGET -> LIST :"); }
LIST: WORD { cppPrint("LIST -> WORD"); }
LIST: LIST WORD { cppPrint("LIST -> LIST WORD"); }

%%
