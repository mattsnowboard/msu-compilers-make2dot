%{
/*
 * Make2dot Bison
 */
#include "Rule.h"

%}

%union {
    char *s;
    void *r;
    void *l;
}

%token <s> WORD COMMAND

%type <r> SET RULE

%type <l> TARGET LIST COMMANDS

%%

DONE: SETS { cppPrint("DONE -> SETS"); }
SETS: SET {
    cppPrint("SETS -> SET");
    // add the Rule object to the collection of Rules
}
SETS: SETS SET {
    cppPrint("SETS -> SETS SET");
    // add the Rule object to the collection of Rules
}
SET: RULE COMMANDS {
    cppPrint("SET -> RULE COMMANDS");
    // add COMMANDS to the Rule object in RULE, store in SET
    addCommands($1, $2);
    $$ = $1;
}
/*SET: RULE {
    cppPrint("SET -> RULE");
    // store Rule object in SET
    $$ = $1;
    }*/
RULE: TARGET LIST {
    cppPrint("RULE -> TARGET LIST");
    // create a Rule object and add the TARGET and LIST lists to it
    $$ = makeRule();
    addTarget($$, $1);
    addSources($$, $2);
}
RULE: TARGET {
    cppPrint("RULE -> TARGET");
    // create a Rule object and add the TARGET list to it
    $$ = makeRule();
    addTarget($$, $1);
}
TARGET: LIST ':' {
    cppPrint("TARGET -> LIST :");
    // no action?
    $$ = $1;
}
LIST: WORD {
    cppPrint("LIST -> WORD");
    // add WORD to a new list? (a list<string>)
    $$ = makeList($1);
}
LIST: LIST WORD {
    cppPrint("LIST -> LIST WORD");
    // add WORD to LIST (a list<string>)
    $$ = addToList($1, $2);
}
COMMANDS: COMMAND {
    cppPrint("COMMANDS -> COMMAND");
    // add COMMAND to a new list (list<string>)
    $$ = makeList($1);
}
COMMANDS: COMMANDS COMMAND {
    cppPrint("COMMANDS -> COMMANDS COMMAND");
    // add COMMAND to COMMANDS list<string>
    $$ = addToList($1, $2);
}

%%
