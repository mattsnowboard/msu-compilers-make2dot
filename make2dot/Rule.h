
#ifndef _RULE_H
#define _RULE_H

#ifdef __cplusplus
#include <string>
#endif

#include "List.h"

#ifdef __cplusplus
/**
 * Stores a make rule (targets, sources, commands)
 */
class Rule
{
public:

    Rule() : _targets(NULL), _sources(NULL), _commands(NULL)
    {}

    void SetTarget(const List &t)
    {
        _targets = &t;
    }

    void SetSources(const List &s)
    {
        _sources = &s;
    }

    void SetCommands(const List &c)
    {
        _commands = &c;
    }

    std::string GetStrings();

    ~Rule()
    {}

private:

    const List* _targets;
    const List* _sources;
    const List* _commands;
    
};

#else
typedef struct Rule Rule;
#endif

#endif
