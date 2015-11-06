#ifndef VARIABLE_HPP
#define VARIABLE_HPP

#include "symbole.hpp"

using namespace std;

class Variable : public Symbole {

	protected :
		Symbole * type;

	public :
		Variable();
		Variable(Symbole *, int);
		Symbole * getType();
		void setType(Symbole *);
};

#endif
