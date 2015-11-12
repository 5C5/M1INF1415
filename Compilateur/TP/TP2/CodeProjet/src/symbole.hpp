#ifndef SYMBOLE_HPP
#define SYMBOLE_HPP

#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

class Symbole {

	protected :
		int identifiant;
		string signification;

	public :
		Symbole();
		Symbole(int, string);
		int getIdentifiant();
		string getSignification();
		void setIdentifiant(int);
		void setSignification(string);
		string toString();
		void afficher();
};

#endif
