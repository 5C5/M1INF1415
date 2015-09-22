all: exo1

exo1: exo1b.o exo1_l.o
	gcc -o exo1 exo1b.o exo1_l.o -lfl

exo1_l.o: exo1.y lexem.l
	flex -o exo1_l.c lexem.l
	gcc -c exo1_l.c 

exo1b.o: exo1.y
	bison -d -o exo1b.c exo1.y
	gcc -c exo1b.c 

clean:
	rm -f exo1 *.o *~ *.c *.h
