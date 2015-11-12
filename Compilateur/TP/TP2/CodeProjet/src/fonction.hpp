#ifndef FONCTION_HPP
#define FONCTION_HPP

#include "type.hpp"

class Fonction : public Symbole {

	protected :
		int arite;
		Symbole * retour;

	public :
		Fonction();
		Fonction(int, int, Symbole *);
		Fonction(int, int);
		int getArite();
		void setArite(int);
		Symbole * getType();
		void setType(Symbole *);
		string toString();
		void afficher();
};

#endif
