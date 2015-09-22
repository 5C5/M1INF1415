all: exo2

exo2: exo2.o 
		gcc -o exo2 exo2.o -lfl

exo2.o:  exo2.l
		flex -o exo2.c exo2.l
		gcc -c exo2.c
clean:
		rm -f exo2 *.o *~ *.c *.h
