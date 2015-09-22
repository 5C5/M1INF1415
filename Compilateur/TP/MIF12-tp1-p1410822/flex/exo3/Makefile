all: exo3

exo3: exo3.o 
		gcc -o exo3 exo3.o -lfl

exo3.o:  exo3.l
		flex -o exo3.c exo3.l
		gcc -c exo3.c
clean:
		rm -f exo3 *.o *~ *.c *.h
