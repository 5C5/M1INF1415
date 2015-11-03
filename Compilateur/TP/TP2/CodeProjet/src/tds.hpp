#ifndef TDS_HPP
#define TDS_HPP

#include "symbole.hpp"
#include <vector>

class TDS {

	protected :
		int contexte;
		string id;
		TDS * parent;
		vector<Symbole> symboles;

	public :
		TDS();
		TDS(int, TDS *, string);
		
		int getContexte();
		TDS * getParent();
		vector<Symbole> getSymboles();
		string getId();
		void setContexte(int);
		void setParent(TDS *);
		void setId(string);

		void addSymbole(Symbole);
		void addSymbole(int, string);

};

#endif
