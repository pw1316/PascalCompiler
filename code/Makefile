objects = main.o scan.o parse.o util.o sematic.o code.o

all:	pascal

pascal:	$(objects)
	gcc $(objects) -o pascal -ll

main.o: main.c pascal.tab.h
	gcc -c main.c -o main.o

scan.o:	scan.c scan.h
	gcc -c scan.c -o scan.o

scan.c: pascal.l pascal.tab.h
	flex -o scan.c pascal.l

parse.o: pascal.tab.c parse.h
	gcc -c pascal.tab.c -o parse.o 

pascal.tab.c pascal.tab.h: pascal.y
	yacc -d -b pascal -v pascal.y

sematic.o: sematic.c sematic.h
	gcc -c sematic.c -o sematic.o

code.o: code.c code.h
	gcc -c code.c -o code.o

util.o: util.c util.h
	gcc -c util.c -o util.o

clean:
	rm *.o
