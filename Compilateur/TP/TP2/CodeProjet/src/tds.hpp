#ifndef TDS_HPP
#define TDS_HPP

#include "symbole.hpp"
#include <vector>

class TDS {

	protected :
		int contexte;
		TDS * parent;
		vector<Symbole> symboles;

	public :
		TDS();
		TDS(int, TDS *);
		
		int getContexte();
		TDS * getParent();
		vector<Symbole> getSymboles();
		void setContexte(int);
		void setParent(TDS *);

		void addSymbole(Symbole);
		void addSymbole(int, string);

};

#endif
