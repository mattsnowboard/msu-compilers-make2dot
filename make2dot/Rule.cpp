
#include "Rule.h"

#include <sstream>

std::string Rule::GetStrings()
{
    std::ostringstream s;
    for (List::ListT::const_iterator src = _sources->GetList().begin();
         src != _sources->GetList().end();
         ++src)
    {
        for (List::ListT::const_iterator tar = _targets->GetList().begin();
             tar != _targets->GetList().end();
             ++tar)
        {
            s << "\t\"" << *src << "\"->\"" << *tar << "\"" << std::endl;
        }
    }

    return s.str();
}
