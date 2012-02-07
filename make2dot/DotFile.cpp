
#include "DotFile.h"

#include <sstream>

#include "List.h"
#include "Rule.h"

List& DotFile::CreateList()
{
    std::shared_ptr<List> l(new List);
    _lists.push_back(l);
    return *l;
}

Rule& DotFile::CreateRule()
{
    std::shared_ptr<Rule> r(new Rule);
    _rules.push_back(r);
    return *r;
}

std::string DotFile::MakeFile()
{
    std::ostringstream s;
    s << "digraph " << _filename << " {" << std::endl;
    for (RulesVec::iterator it = _rules.begin(); it != _rules.end(); ++it)
    {
        s << (*it)->GetStrings();
    }
    s << "}";
    return s.str();
}
