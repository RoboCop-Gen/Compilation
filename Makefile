CC = gcc
OPTIONS = -W -Wall -pedantic -std=c11
YFLAGS = -d -v
YACC = bison
CLIBS = -ly -ll
LEX = flex
OUTPUT = toro
GDB = -g

main : yacc lex ./objets/lex.yy.o
	$(CC) $(OPTIONS) bison.tab.c ./objets/lex.yy.o $(CLIBS) -o $(OUTPUT)


yacc : bison.y
	$(YACC) $(YFLAGS) bison.y

lex : flex.l
	$(LEX) flex.l

./objets/lex.yy.o : lex.yy.c
	$(CC) -c lex.yy.c -o ./objets/lex.yy.o

clean :
	rm lex.yy.* bison.tab.* bison.output toro ./objets/*