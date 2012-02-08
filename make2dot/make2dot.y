%{
/*
 * Make2dot Bison
 */

%}

%union {
    char *s;
    void *rule;
    void *list;
    void *var;
}

%token <s> WORD COMMAND VARIABLE

%type <s> PHRASE

%type <rule> SET RULE

%type <list> TARGET LIST COMMANDS

%type <var> DECLARATION

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
    //cppPrint("\tSET -> RULE \\n COMMANDS");
    // add COMMANDS to the Rule object in RULE, store in SET
    addCommands($1, $3);
    $$ = $1;
}
SET: RULE '\n' {
    //cppPrint("\tSET -> RULE \\n");
    // store Rule object in SET
    $$ = $1;
}
SET: DECLARATION '\n' {
    //cppPrint("\tSET -> DECLARATION \\n");
    // store the declaration in the var name
}
DECLARATION: WORD '=' LIST {
    //cppPrint("\tDECLARATION -> WORD = LIST \\n");
    // associate the list with the word
    $$ = makeVariable($1, $3);
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
LIST: PHRASE {
    //cppPrint("\tLIST -> PHRASE");
    // add WORD to a new list? (a list<string>)
    $$ = makeList($1);
}
LIST: LIST PHRASE {
    //cppPrint("\tLIST -> LIST PHRASE");
    // add WORD to LIST (a list<string>)
    $$ = addToList($1, $2);
}
PHRASE: WORD {
    //cppPrint("\tPHRASE -> WORD");
    // store word in phrase
    $$ = $1;
}
PHRASE: VARIABLE {
    //cppPrint("\tPHRASE -> VARIABLE");
    // store variable text in phrase
    $$ = $1;
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
