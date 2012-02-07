
SRCS := DotFile.cpp
OBJS := $(SRCS:%.cpp=%.o)

CXXFLAGS = -Wall -std=c++0x

DEPDIR = .deps
df = $(DEPDIR)/$(@F)

MAKEDEPEND = $(CXX) $(CPPFLAGS) -MM -o $(df).d $<

make2dot : $(OBJS) make2dot.o y.tab.o lex.yy.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o make2dot $^

# basics for flex/bison
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

# dependency stuff
.D_TARGET:
	mkdir -p $(DEPDIR)
	touch $@

.PRECIOUS: .D_TARGET

# my other sources

%.o : %.cpp .D_TARGET
	$(MAKEDEPEND);
	@cp $(df).d $(df).P;
	@rm -f $(df).d
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ -c $<

-include $(SRCS:%.cpp=$(DEPDIR)/%.o.P)

# clean

clean: 
	$(RM) $(OBJS) .D_TARGET make2dot.o make2dot lex.yy.c lex.yy.o \
		y.tab.h y.tab.c y.tab.o
	rm -rf $(DEPDIR)