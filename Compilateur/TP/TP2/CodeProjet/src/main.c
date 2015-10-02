#include <cstdlib>
#include <cstddef>
#include <cstdio>

extern int yyparse ();
extern FILE* yyin;

int main ( int argc, char** argv )
{
	/* Gestion de la ligne de commande */
	/* Initialisation des données du compilateur */
	/* phases d'analyse */
    yyparse ();
	/* traitements post analyse */
	/* sauvegarde des resultats */
}
