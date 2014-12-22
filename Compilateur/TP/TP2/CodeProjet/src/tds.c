#include "tdi.h"
#include "tds.h"
#include "type.h"
#include "parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Fichier contenant la description de la table des symboles*/

// Initialisation de la table des symboles

s_tableSymb * TDS = NULL;
int nbreContexte = 1;
void ajouterSymbole(int contexte, int ident, char* type){
}

void ajouterTS(int * context, char * nom){
	
	if(TDS == NULL){

		TDS = (s_tableSymb *)malloc(sizeof(s_tableSymb));
		TDS[*context].context = *context;
		TDS[*context].parent = NULL;
		strcpy(TDS[*context].nom, nom);
		TDS[*context].symbole = NULL;
	}
	else {
		s_tableSymb *temp = (s_tableSymb *)realloc(TDS,sizeof(s_tableSymb)* (++nbreContexte));
		if(temp == NULL){
			printf("Erreur allocation mémoire lors de l'ajout d'une table des symbole\n");
			exit(0);
		}
		else {
			int contextParent = *context++;
			TDS = temp;
			TDS[*context].context = (nbreContexte-1);
			TDS[*context].parent = &TDS[contextParent];
			strcpy(TDS[*context].nom, nom);
			TDS[*context].symbole = NULL;
		}
	}
}

void nettoyerTableSymbole(){
}
