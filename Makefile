CC = gcc
OPTIONS = -W -Wall -pedantic -std=c11
YFLAGS = -d -v
YACC = bison
CLIBS = -ly -ll
LEX = flex
OUTPUT = toro
GDB = -g

main : yacc lex ./objets/lex.yy.o ./objets/pile.o ./objets/tableLexicographique.o
	$(CC) $(OPTIONS) bison.tab.c ./objets/lex.yy.o ./objets/pile.o ./objets/tableLexicographique.o $(CLIBS) -o $(OUTPUT)

table_lexico: tableLexicographique.h tableLexicographique.c	
	$(CC) -c $(OPTIONS) tableLexicographique.c

pile: pile.h pile.c
	$(CC) -c $(OPTIONS) pile.c

yacc : bison.y
	$(YACC) $(YFLAGS) bison.y

lex : flex.l
	$(LEX) flex.l

./objets/lex.yy.o : lex.yy.c
	$(CC) -c lex.yy.c -o ./objets/lex.yy.o

./objets/pile.o : pile.c
	$(CC) -c pile.c -o ./objets/pile.o

./objets/tableLexicographique.o : tableLexicographique.c
	$(CC) -c tableLexicographique.c -o ./objets/tableLexicographique.o	

clean :
	rm lex.yy.* bison.tab.* bison.output toro ./objets/*