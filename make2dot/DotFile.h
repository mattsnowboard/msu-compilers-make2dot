
#ifndef _DOTFILE_H
#define _DOTFILE_H

#include <memory>
#include <vector>
#include <string>

class Rule;
class List;

class DotFile
{
public:
    /**
     * Constructor
     */
    DotFile() {}

    void SetFileName(const std::string &f)
    {
        _filename = f;
    }
    
    /**
     * Create a List and return the pointer so the callee can add
     * items to it
     *
     * @return *List, owned by DotFile
     */
    List& CreateList();

    /**
     * Create a Rule and return the pointer so the callee can add
     * items to it
     *
     * @return *Rule, owned by DotFile
     */
    Rule& CreateRule();

    /**
     * Make the Dot file as a string
     *
     * @return string containing the dot file
     */
    std::string MakeFile();

    ~DotFile() {}

private:

    // DotFile OWNS all of this, so it holds smart pointers
    // which will be deleted when DotFile goes out of scope
    // Callers get raw pointers since we know DotFile will outlive them
    typedef std::vector<std::shared_ptr<Rule> > RulesVec;
    typedef std::vector<std::shared_ptr<List> > ListVec;
    RulesVec _rules;
    // just hold these objects
    ListVec _lists;

    /// The filename to output
    std::string _filename;
};

#endif
