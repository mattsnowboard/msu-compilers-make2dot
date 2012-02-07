
#include "DotFile.h"

std::shared_ptr<List> DotFile::CreateList()
{
    std::shared_ptr<List> l(new List);
    _lists.push_back(l);
    return l;
}

std::shared_ptr<Files> DotFile::CreateFilesList()
{
    std::shared_ptr<Files> f(new Files);
    _files.push_back(f);
    return f;
}

std::shared_ptr<Rule> DotFile::CreateRule()
{
    std::shared_ptr<Rule> r(new Rule);
    _rules.push_back(r);
    return r;
}
