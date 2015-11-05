#ifndef PROGRAMME_HPP
#define PROGRAMME_HPP

#include "symbole.hpp"

using namespace std;

class Programme : public Symbole {

	protected :
		string nom;

	public :
		Programme();
		Programme(string, int);
		string getNom();
		void setNom(string);
};
#endif
