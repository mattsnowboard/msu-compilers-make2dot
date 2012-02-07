#include <cstdio>
#include <iostream>
#include <list>

#include "DotFile.h"
#include "List.h"
#include "Rule.h"

using namespace std;

extern "C" {
#include "y.tab.h"
    extern FILE *yyin;
    extern int yylex();
    extern int yyparse();
    extern char *yytext();
}

// Global variable so we can get it in the parser
DotFile dot;

int main(int argc, char **argv)
{
    FILE *file;

    if (argc < 2)
    {
        fprintf(stderr, "Using Standard input: Use ^D to exit.\n");
        file = stdin;
        dot.SetFileName("stdin");
    }
    else
    {
        file = fopen(argv[1], "r");
        dot.SetFileName(argv[1]);
    }

    if (!file)
    {
        fprintf(stderr, "Unable to open file %s", argv[1]);
        return 1;
    }

    cout << "Make2Dot!" << endl;

    yyin = file;

    do
    {
        yyparse();
    } while (!feof(yyin));

    cout << dot.MakeFile() << endl;
    
    return 0;
}

extern "C" void yyerror(char *s)
{
    cout << s << endl;
}

extern "C" void cppPrint(char *s)
{
    cout << s << endl;
}

extern "C" Rule* makeRule()
{
    return &dot.CreateRule();
}

extern "C" void addTarget(Rule *r, List *l)
{
    r->SetTarget(*l);
}

extern "C" void addSources(Rule *r, List *l)
{
    r->SetSources(*l);
}

extern "C" void addCommands(Rule *r, List *l)
{
    r->SetCommands(*l);
}

extern "C" List* makeList(char *c)
{
    List& l = dot.CreateList();
    l.Add(c);
    return &l;
}

extern "C" List* addToList(List *l, char *c)
{
    l->Add(c);
    return l;
}
