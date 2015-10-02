#ifndef TDI_HPP
#define TDI_HPP

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;



class Identificateur {

	protected :
		static unsigned int num;
		unsigned int ident;
		string name;

	public :
		Identificateur(char * n);
		unsigned int getIdent();
		char* getNom();

};

vector<Identificateur> tdi;
unsigned int ajouterIdentificateur(const char *);
void sauvegardeTable(const char *);
void afficherTableIdent(void);

#endif
