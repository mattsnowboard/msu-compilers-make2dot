
#include "Rule.h"

#include <sstream>
#include <cctype>

/**
 * Case-insensitive string comparison
 *
 * @param s1 First string
 * @param s2 Second String
 * @return true if strings equal (case-insensitive)
 */
inline bool strieq(const std::string &s1, const std::string &s2)
{
    if (s1.size() != s2.size())
    {
        return false;
    }

    for (std::string::const_iterator it1 = s1.begin(), it2 = s2.begin();
         it1 != s1.end();
         ++it1, ++it2)
    {
        if (tolower(*it1) != tolower(*it2))
        {
            return false;
        }
    }

    return true;
}

/**
 * Given a filename, change the Dot shape depending on the extension
 * 
 * @param s The filename
 * @return a string to set the shape based on the extension (if present)
 */
inline std::string getShape(const std::string &s)
{
    size_t dot = s.find_last_of('.');
    std::string ext;
    if (dot != std::string::npos)
    {
        ext = s.substr(dot + 1);
    }
    if (strieq(ext, "c") || strieq(ext, "cc") || strieq(ext, "cpp")
        || strieq(ext, "cxx"))
    {
        return "rect";
    }
    if (strieq(ext, "h") || strieq(ext, "hh") || strieq(ext, "hpp")
        || strieq(ext, "hxx"))
    {
        return "trapezium";
    }
    if (strieq(ext, "l") || strieq(ext, "y"))
    {
        return "parallelogram";
    }
    return "ellipse";
    
}

/**
 * Trim whitespace from string
 *
 * @param s input string
 * @return string with no leading or trailing whitespace
 */
inline std::string trim(const std::string &s)
{
    std::string::const_iterator start = s.begin();
    while (start != s.end() &&
           ((*start) == '\n' || (*start) == '\t' || (*start) == ' '))
    {
        ++start;
    }
    std::string::const_iterator end = s.end();
    while (end != s.begin() &&
           ((*end) == '\n' || (*end) == '\t' || (*end) == ' '
            || (*end) == '\0'))
    {
        --end;
    }
    return std::string(start, end + 1);
}

/**
* implode a list to a string (name stolen from PHP)
*
* @param l The List
* @return a string with all list items concatenated with newlines separating
*/
inline std::string implode(const List &l)
{
    std::ostringstream s;
    for (List::ListT::const_iterator it = l.GetList().begin();
         it != l.GetList().end();
         ++it)
    {
        s << trim(*it) << ";";
    }
    return s.str();
}

std::string Rule::GetStrings()
{
    std::ostringstream s;
    if (_sources && _targets)
    {
        for (List::ListT::const_iterator src = _sources->GetList().begin();
             src != _sources->GetList().end();
             ++src)
        {
            // print out the shape of the source
            s << "\t\"" << *src << "\" [shape=" << getShape(*src)
              << "];" << std::endl;
            for (List::ListT::const_iterator tar = _targets->GetList().begin();
                 tar != _targets->GetList().end();
                 ++tar)
            {
                // print the shape of the target then the connection
                s << "\t\"" << *tar << "\" [shape=" << getShape(*tar)
                  << "];" << std::endl
                  << "\t\"" << *src << "\"->\"" << *tar << "\"";
                if (_commands)
                {
                    // add a label with the command used
                    s << " [label=\"" << implode(*_commands) << "\"];";
                }
                s << std::endl;
            }
        }
    }
    else if (_targets)
    {
        for (List::ListT::const_iterator tar = _targets->GetList().begin();
             tar != _targets->GetList().end();
             ++tar)
        {
            // print out the target by itself and its shape
            s << "\t\"" << *tar << "\" [shape=" << getShape(*tar);
            if (_commands)
            {
                // add a label with the command used
                s << " label=\"" << implode(*_commands) << "\"";
            }
            s << "];" << std::endl;
        }
    }

    return s.str();
}
