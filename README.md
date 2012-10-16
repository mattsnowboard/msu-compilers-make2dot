Make2Dot
========

A project for CSE450 Compilers

This assignment is to make a program that can produce dot files from simple makefiles to show a dependency graph.

Dependencies
------------

Flex and Bison

Dot (to generate png images of the dotfiles)

About
-----

Run make to build the project and create the test .pngs (6)

My make2dot supports:
 - one or more targets, a colon, and zero or more sources makes a "Rule"
 - zero or more commands, prefixed by a TAB character can be associated with
   a rule
 - strips comments (# preceded by any whitespace)
     - Does not handle comments at the end of a valid line
 - most invalid characters are ignored (as the example did)
 - The last command or rule must have a new line at the end
HONOR's OPTION
 - Different shapes depending on the file extension (case insensitive)
     - .c, .cc, .cpp, .cxx: rect
     - .h, .hh, .hpp, .hxx: trapezium
     - .l, .y: parallelogram
     - (see: makefile4)
 - All commands that form a connection on the graph are labeled
     - multiple commands separated by ;
 - simple variables in the form VARIABLE = <LIST> where later sources can use
   $(VARIABLE) anywhere in the list and all of the items in <LIST> will be
   inserted (see: makefile5)
     - Nested variables are supported (see: makefile6)
