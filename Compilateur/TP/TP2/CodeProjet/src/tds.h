#ifndef _TDS_H_
#define _TDS_H_

#include "type.h"

extern int tableContexte[TAILLE];

typedef struct {
	int ident;
	signification s;
} symbole;


extern symbole TS[];


void ajouterSymbole(int, int, char*);

void ajouterContexte(int, int);

#endif
