
simple: simple.o y.tab.o lex.yy.o
	g++ simple.o y.tab.o lex.yy.o -o simple

lex.yy.c: simple.l y.tab.h
	flex simple.l

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

y.tab.c y.tab.h: simple.y
	bison --yacc --defines simple.y

y.tab.o: y.tab.c y.tab.h
	gcc -c y.tab.c

simple.o: simple.cc y.tab.h
	g++ -c simple.cc
