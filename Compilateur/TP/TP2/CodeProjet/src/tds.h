#ifndef _TDS_H_
#define _TDS_H_

extern int tableContexte[TAILLE];

typedef struct {
	int ident;
	signification ;
} symbole;


extern symbole TS[];


void ajouterSymbole(int, int, char*);

void ajouterContexte(int, int);

#endif
