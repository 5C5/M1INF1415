#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

#ifndef TDI_HPP
#define TDI_HPP

class Identificateur {

	protected :
		static unsigned int num = 1;
		unsigned int ident;
		string name;

	public :
		Identificateur(char * n);
		unsigned int getIdent();
		char* getNom();

}
#endif TDI_HPP

vector <Identificateur> tdi;
unsigned int ajoutIdentificateur(const char *);
void sauvegardeTable(const char *);
void afficherTable(void);
