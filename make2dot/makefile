
make2dot: make2dot.o y.tab.o lex.yy.o
	g++ make2dot.o y.tab.o lex.yy.o -o make2dot

lex.yy.c: make2dot.l y.tab.h
	flex make2dot.l

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

y.tab.c y.tab.h: make2dot.y
	bison --yacc --defines make2dot.y

y.tab.o: y.tab.c y.tab.h
	gcc -c y.tab.c

make2dot.o: make2dot.cc y.tab.h
	g++ -c make2dot.cc
