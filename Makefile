CC = gcc
OPTIONS = -W -Wall -pedantic -std=c11
YFLAGS = -d -v
YACC = yacc
CLIBS = -ly -ll
LEX = flex
OUTPUT = compi
GDB = -g

main : yacc lex lex.yy.o
	$(CC) $(OPTIONS) -o $(OUTPUT) y.tab.c lex.yy.o $(CLIBS)


yacc : bison.y
	$(YACC) $(YFLAGS) bison.y

lex : flex.l
	$(LEX) flex.l

lex.yy.o : lex.yy.c
	$(CC) -c lex.yy.c

clean :
	rm -rf lex.yy.* y.tab.* *.o *.output bison.output compi 
