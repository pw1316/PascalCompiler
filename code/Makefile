objects = main.o scan.o parse.o util.o

all:	pascal

pascal:	$(objects)
	gcc $(objects) -o pascal -ll
	rm *.o
	rm *.tab.*
	rm scan.c

main.o: main.c
	gcc -c main.c -o main.o

scan.o:	scan.c
	gcc -c scan.c -o scan.o

scan.c: pascal.l pascal.tab.h
	flex -o scan.c pascal.l

parse.o: pascal.tab.c
	gcc -c pascal.tab.c -o parse.o 

pascal.tab.c pascal.tab.h: pascal.y
	yacc -d -b pascal -v pascal.y

util.o: util.c
	gcc -c util.c -o util.o