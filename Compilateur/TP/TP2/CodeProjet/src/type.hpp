#ifndef TYPE_H
#define TYPE_H

#include <string>
#include "symbole.hpp"

using namespace std;

class Type : public Symbole {

	protected :
		string type;

	public :
		Type();
		Type(string);
		Type(string, int);
		string getType();
		void setType(string);
		string toString();
		void afficher();
};

#endif
