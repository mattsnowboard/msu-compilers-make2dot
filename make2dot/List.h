
#ifndef _LIST_H
#define _LIST_H

#ifdef __cplusplus

#include <string>
#include <list>

#endif

#ifdef __cplusplus
/**
 * List
 *
 * Holds a list of strings
 */
class List
{
public:

    typedef std::list<std::string> ListT;

    List()
    {}

    void Add(const std::string &s)
    {
        _list.push_back(s);
    }

    const ListT& GetList() const;

    virtual ~List() {}

private:

    /// List of strings
    ListT _list;
};

#else
typedef struct List List;
#endif

#endif
