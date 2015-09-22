all: exo1

exo1: exo1.o 
		gcc -o exo1 exo1.o -lfl

exo1.o:  exo1.l
		flex -o exo1.c exo1.l
		gcc -c exo1.c
clean:
		rm -f exo1 *.o *~ *.c *.h
