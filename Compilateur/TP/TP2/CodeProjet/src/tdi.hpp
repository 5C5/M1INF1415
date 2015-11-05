#ifndef TDI_HPP
#define TDI_HPP

#include "ident.hpp"
#include <cstring>

using namespace std;

class TDI {

	protected :
		vector<Identificateur> table;

	public :
		TDI();
		unsigned int ajouterIdentificateur(const char *);
		unsigned int ajouterIdentificateur(Identificateur);
		const char * getNomFromId(unsigned int);

		void afficherTableIdent();

		void sauvegarderTableIdent(const char *);
};

#endif
