
#ifndef _RULE_H
#define _RULE_H

/**
 * Stores a make rule (targets, sources, commands)
 */
class Rule
{
public:

    Rule()
    {}

    void SetTarget(const std::shared_ptr<Files> &t)
    {
        _targets.reset(t.get());
    }

    void SetSources(const std::shared_ptr<Files> &s)
    {
        _sources.reset(s.get());
    }

    void SetCommands(const std::shared_ptr<List> &c)
    {
        _commands.reset(c.get());
    }

    ~Rule()
    {}

private:

    std::shared_ptr<Files> _targets;
    std::shared_ptr<Files> _sources;
    std::shared_ptr<List> _commands;
    
};

#endif
