#ifndef _TDS_H_
#define _TDS_H_

#include "type.h"
#define TRUE 1
#define FALSE 0


typedef struct symb {

	int numeroIdentifiant;
	signification value;
	symb *suivant;
}s_symb;

typedef struct tableSymb {

	char nom[TAILLE];
	int context;
	tableSymb * parent;
	s_symb *symbole;
}s_tableSymb;

extern s_tableSymb * TDS;
extern int nbreContexte;
extern int context;

void ajouterSymbole(int, int, char*);

void ajouterTS(int);

void nettoyerTableSymbole();

#endif
