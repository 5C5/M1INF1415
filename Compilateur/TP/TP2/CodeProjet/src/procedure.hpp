#ifndef PROCEDURE_HPP
#define PROCEDURE_HPP

#include "symbole.hpp"

class Procedure : public Symbole {

	protected :
		int arite;

	public :
		Procedure();
		Procedure(int, int);
		int getArite();
		void setArite(int);
		string toString();
		void afficher();
};

#endif
