
#ifndef _DOTFILE_H
#define _DOTFILE_H

#include <memory>
#include <vector>

#include "List.h"
#include "Files.h"
#include "Rule.h"

class DotFile
{
public:
    /**
     * Constructor
     */
    DotFile() {}

    /**
     * Create a List and return the pointer so the callee can add
     * items to it
     *
     * @return *List, owned by DotFile
     */
    std::shared_ptr<List> CreateList();

    /**
     * Create a Files List and return the pointer so the callee can add
     * items to it
     *
     * @return *Files, owned by DotFile
     */
    std::shared_ptr<Files> CreateFilesList();

    /**
     * Create a Rule and return the pointer so the callee can add
     * items to it
     *
     * @return *Rule, owned by DotFile
     */
    std::shared_ptr<Rule> CreateRule();

    ~DotFile() {}

private:

    typedef std::vector<std::shared_ptr<Rule>> RulesVec;
    typedef std::vector<std::shared_ptr<List>> ListVec;
    typedef std::vector<std::shared_ptr<Files>> FilesVec;
    RulesVec _rules;
    // just hold these objects
    ListVec _lists;
    FilesVec _files;
};

#endif
