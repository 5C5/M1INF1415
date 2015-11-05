#ifndef IDENT_HPP
#define IDENT_HPP

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
#endif
