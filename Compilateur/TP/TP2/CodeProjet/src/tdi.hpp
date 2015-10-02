#ifndef TDI_HPP
#define TDI_HPP

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;


/*
 * Classe d'identificateur
 */
class Identificateur {

	protected :
		static unsigned int num;
		unsigned int ident;
		string name;

	public :
		Identificateur(const char * n);
		unsigned int getIdent();
		const char* getNom();

};

/*
 * Déclaration de la table d'identificateur (variable globale)
 */
extern vector<Identificateur> tdi;


extern unsigned int ajouterIdentificateur(const char *);
extern void sauvegarderTable(const char *);
extern void afficherTableIdent(void);
extern char * getNom(const unsigned int);
#endif
