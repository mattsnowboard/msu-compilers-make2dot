
#include "List.h"

#include "DotFile.h"

#include <stdexcept>

/**
 * Check if a string is a variable (syntax is $(VAR) )
 * @param s String to check
 * @return true if it's a variable
 */
inline bool isVar(const std::string &s)
{
    if (s[0] == '$' && s[1] == '('  && s[s.size() - 1] == ')')
    {
        return true;
    }
    return false;
}

void List::Expand(const DotFile & dot)
{
    ListT newList;
    for (ListT::iterator it = _list.begin(); it != _list.end(); ++it)
    {
        if (isVar(*it))
        {
            try
            {
                const List &vars = dot.GetVariableList(
                    (*it).substr(2, (*it).size() - 3));
                _list.insert(it, vars._list.begin(), vars._list.end());
                it = _list.erase(it);
                --it;
            }
            catch (std::invalid_argument&)
            {
            }
        }
    }
}
