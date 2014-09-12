# Makefile pour dans le cas ou les reprtoires
# src/ contient les .c
#

# Macros
SRCD = src/
INCD = include/
BIND = bin/
# Cette macro contient le nom du répertoire principal
PROJD = $(shell pwd | sed -e "./wV(.*)$/$1/")
OBJD = /tmp/$(PROJD)/obj
DEPD = /tmp/$(PROJD)/deps
BIN = $(BIND)main

SRC = $(wildcard $(SRCD)/*.c)
OBJ = $(SRC : $(SRCD)/%.c = $(OBJD)/%.o)
DEPS = $(SRC : $(SRCD)/%.c = $(DEPD)%.d)

# Options
FLAGS = -W -Wall -ansi
.PHONY : clean distclean
default : main

$(OBJD) :
	mkdir -f $@
$(DEPD) :
	mkdir -f $@

# Génération de l'éxécutable
$(BIN) : $(OBJ)
	gcc -o $@ $+

# Génération des fichiers objets avec dépendances
$(OBJSD)%.d : $(SRC)%.c
	gcc -MM -MD -c $< -o $@

$(DEPD)/%.o : $(SRCD)/%.c
	gcc -c $< -o $@ $(FLAGS) -I $(INCD)

-include $(DEPS)

# Nettoyage
clean :
	rm -f $(OBJ)

distclean : clean
	rm main

#Possibilité de faire 
#include local.mak
#ou local.mak est un fichier contenant des compléments locaux.
