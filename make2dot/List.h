
#ifndef _LIST_H
#define _LIST_H

#include <string>
#include <list>

/**
 * List
 *
 * Holds a list of strings
 */
class List
{
public:

    List()
    {}

    void Add(const std::string &s)
    {
        _list.push_back(s);
    }

    virtual ~List() {}

private:

    /// List of strings
    std::list<std::string> _list;
};

#endif
