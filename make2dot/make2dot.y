%{
/*
 * Make2dot Bison
 */

%}

%token WORD COMMAND

%%

DONE: SETS { cppPrint("DONE -> SETS"); }
SETS: SET { cppPrint("SETS -> SET"); }
SETS: SETS SET { cppPrint("SETS -> SETS SET"); }
SET: RULE COMMANDS { cppPrint("SET -> RULE COMMANDS"); }
RULE: TARGET LIST { cppPrint("RULE -> TARGET LIST"); }
TARGET: LIST ':' { cppPrint("TARGET -> LIST :"); }
LIST: WORD { cppPrint("LIST -> WORD"); }
LIST: LIST WORD { cppPrint("LIST -> LIST WORD"); }
COMMANDS: COMMAND { cppPrint("COMMANDS -> COMMAND"); }
COMMANDS: COMMANDS COMMAND { cppPrint("COMMANDS -> COMMANDS COMMAND"); }

%%
