a.out: main.o lex.yy.o trre.tab.o
		gcc main.o lex.yy.o trre.tab.o -ll

main.o: main.c trre.tab.c
		gcc -c main.c
	
lex.yy.o: lex.yy.c	
			gcc -c lex.yy.c

trre.tab.o: trre.tab.c
					gcc -c trre.tab.c

lex.yy.c: trre.l trre.tab.c
			flex trre.l

trre.tab.c:trre.y
					bison -d trre.y

clean:
		rm -f a.out main.o trre.tab.* lex.yy.*

run: a.out	
		./a.out