#include "tdi.h"
#include "tds.h"
#include "type.h"
#include "parser.h"

/* Fichier contenant la description de la table des symboles*/

// Tableau des contextes
int tableContexte[TAILLE];

void ajouterSymbole(int contexte, int ident, char* type){
}

void ajouterContexte(int contexte, int contexteParent){

	tableContexte[contexte] = contexteParent;
}
