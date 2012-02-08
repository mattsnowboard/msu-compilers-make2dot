
#include "DotFile.h"

#include <sstream>
#include <stdexcept>

#include "List.h"
#include "Rule.h"
#include "Variable.h"

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

Variable& DotFile::CreateVariable()
{
    std::shared_ptr<Variable> v(new Variable);
    _vars.push_back(v);
    return *v;
}

std::string DotFile::MakeFile()
{
    // expand all variables first
    for (ListVec::iterator it = _lists.begin(); it != _lists.end(); ++it)
    {
        (*it)->Expand(*this);
    }

    std::ostringstream s;
    s << "digraph " << _filename << " {" << std::endl;
    for (RulesVec::iterator it = _rules.begin(); it != _rules.end(); ++it)
    {
        s << (*it)->GetStrings();
    }
    s << "}";
    return s.str();
}

const List& DotFile::GetVariableList(const std::string &s) const
{
    for (VarVec::const_iterator var = _vars.begin();
         var != _vars.end();
         ++var)
    {
        if ((*var)->GetName() == s)
        {
            return (*var)->GetList();
        }
    }
    throw std::invalid_argument("The variable does not exist");
}
