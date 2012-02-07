%{
/*
 * Make2dot Bison
 */

%}

%union {
    char *s;
}

%token <s> WORD COMMAND

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
}
/*SET: RULE {
    cppPrint("SET -> RULE");
    // store Rule object in SET
    }*/
RULE: TARGET LIST {
    cppPrint("RULE -> TARGET LIST");
    // create a Rule object and add the TARGET and LIST lists to it
}
RULE: TARGET {
    cppPrint("RULE -> TARGET");
    // create a Rule object and add the TARGET list to it
}
TARGET: LIST ':' {
    cppPrint("TARGET -> LIST :");
    // no action?
}
LIST: WORD {
    cppPrint("LIST -> WORD");
    cppPrint($1);
    // add WORD to a new list? (a list<string>)
}
LIST: LIST WORD {
    cppPrint("LIST -> LIST WORD");
    // add WORD to LIST (a list<string>)
}
COMMANDS: COMMAND {
    cppPrint("COMMANDS -> COMMAND");
    // add COMMAND to a new list (list<string>)
}
COMMANDS: COMMANDS COMMAND {
    cppPrint("COMMANDS -> COMMANDS COMMAND");
    // add COMMAND to COMMANDS list<string>
}

%%
