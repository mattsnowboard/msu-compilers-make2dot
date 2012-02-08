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

DONE: SETS {
    //cppPrint("\tDONE -> SETS");
}
SETS: SET {
    //cppPrint("\tSETS -> SET");
    // add the Rule object to the collection of Rules
}
SETS: SETS SET {
    //cppPrint("\tSETS -> SETS SET");
    // add the Rule object to the collection of Rules
}
SET: RULE '\n' COMMANDS {
    //cppPrint("\tSET -> RULE COMMANDS \\n");
    // add COMMANDS to the Rule object in RULE, store in SET
    addCommands($1, $3);
    $$ = $1;
}
SET: RULE '\n' {
    //cppPrint("\tSET -> RULE \\n");
    // store Rule object in SET
    $$ = $1;
    }
RULE: TARGET LIST {
    //cppPrint("\tRULE -> TARGET LIST");
    // create a Rule object and add the TARGET and LIST lists to it
    $$ = makeRule();
    addTarget($$, $1);
    addSources($$, $2);
}
RULE: TARGET {
    //cppPrint("\tRULE -> TARGET");
    // create a Rule object and add the TARGET list to it
    $$ = makeRule();
    addTarget($$, $1);
}
TARGET: LIST ':' {
    //cppPrint("\tTARGET -> LIST :");
    // no action?
    $$ = $1;
}
LIST: WORD {
    //cppPrint("\tLIST -> WORD");
    // add WORD to a new list? (a list<string>)
    $$ = makeList($1);
}
LIST: LIST WORD {
    //cppPrint("\tLIST -> LIST WORD");
    // add WORD to LIST (a list<string>)
    $$ = addToList($1, $2);
}
COMMANDS: COMMAND '\n' {
    //cppPrint("\tCOMMANDS -> COMMAND \\n");
    // add COMMAND to a new list (list<string>)
    $$ = makeList($1);
}
COMMANDS: COMMANDS COMMAND '\n' {
    //cppPrint("\tCOMMANDS -> COMMANDS COMMAND \\n");
    // add COMMAND to COMMANDS list<string>
    $$ = addToList($1, $2);
}


%%
