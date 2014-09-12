#Makefile marchant dans tous les cas où les sources .c et .h sont dans le répertoire courant

#Macros
SRC = $(wildcard *.c)
OBJ = $(SRC : %.c = %.o)
DEPS = $(SRC : %.c = %.d)

#Options
FLAGS = -W -Wall -ansi
.PHONY : clean distclean
default : main

#Génération de l'éxécutable
main : $(OBJ)
	gcc -o $@ $+

#Génération des fichiers objets avec dépendances
%.d : %.c
	gcc -MM -MD -c $< -o $@

%.o : %.c 
	gcc -c $< -o $@ $(FLAGS)

-include $(DEPS)

#Nettoyage
clean :
	rm -f $(OBJ)

distclean : clean
	rm main

#Possibilité de faire 
#include local.mak
#ou local.mak est un fichier contenant des compléments locaux.
