
#ifndef _DOTFILE_H
#define _DOTFILE_H

#include <memory>
#include <vector>
#include <string>

class Rule;
class List;
class Variable;

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
     * @return List, owned by DotFile
     */
    List& CreateList();

    /**
     * Create a Rule and return the pointer so the callee can add
     * items to it
     *
     * @return Rule, owned by DotFile
     */
    Rule& CreateRule();
    
    /**
     * Create a Variable and return the pointer so the callee can
     * set its name and add to its list
     *
     * @return Variable, owned by DotFile
     */
    Variable& CreateVariable();

    /**
     * Lookup a Variable by name and return its list
     *
     * @param s The variable name
     * @return The List of strings it expands to
     */
    const List& GetVariableList(const std::string &s) const;

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
    typedef std::vector<std::shared_ptr<Variable> > VarVec;
    RulesVec _rules;
    // just hold these objects
    ListVec _lists;
    VarVec _vars;

    /// The filename to output
    std::string _filename;
};

#endif
