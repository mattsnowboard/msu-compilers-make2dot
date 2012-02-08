
#ifndef _VARIABLE_H
#define _VARIABLE_H

#ifdef __cplusplus
#include <string>
#endif

#include "List.h"

#ifdef __cplusplus
/**
 * Stores a variable declaration (a name associated with a list)
 */
class Variable
{
public:

    Variable() : _vars(NULL)
    {}

    void SetName(const std::string &s)
    {
        _name = s;
    }

    const std::string& GetName() const
    {
        return _name;
    }

    void SetList(const List &s)
    {
        _vars = &s;
    }

    /**
     * Expand the variable to a List
     */
    const List& GetList() const
    {
        return *_vars;
    }

    ~Variable()
    {}

private:
    /// The name of the variable
    std::string _name;
    /// The list that the variable references
    const List* _vars;
};

#else
typedef struct Rule Rule;
#endif

#endif
