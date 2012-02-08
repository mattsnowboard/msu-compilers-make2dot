
#ifndef _LIST_H
#define _LIST_H

#ifdef __cplusplus

#include <string>
#include <list>

#endif

#ifdef __cplusplus

class DotFile;

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

    const ListT& GetList() const
    {
        return _list;
    }

    /**
     * Handle variable expansion
     * Will iterator over the list and remove items which are variables
     * and substitute them with the strings
     *
     * @param dot The DotFile holds all Variable defintions
     * @post the List holds expanded variables
     */
    void Expand(const DotFile &dot);

    virtual ~List() {}

private:

    /// List of strings
    ListT _list;
};

#else
typedef struct List List;
#endif

#endif
