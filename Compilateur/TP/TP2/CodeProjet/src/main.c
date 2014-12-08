#include <cstdlib>
#include <cstddef>
#include <cstdio>
#include <string.h>
#include "tdi.h"

extern int yyparse ();
extern FILE* yyin;

void usage(char * s){
	
	printf("Erreur : %s usage :\n\t ppc -c <FILENAME> [OPTIONS] \n Options : \n -O \t activer les optimisations \n -a \t activer la génération du code assembleur.\n", s);
}

int main ( int argc, char** argv ){

	/* Gestion de la ligne de commande */
	switch(argc){

		case 3 :
			if(strcmp(argv[1], "-c") != 0)
				usage(argv[0]);
			break;
		case 4 :
			if((strcmp(argv[1], "-c") != 0) || (strcmp(argv[3], "-O") != 0))
				usage(argv[0]);
			break;
		case 5 :
			if((strcmp(argv[1], "-c") != 0) || (strcmp(argv[3], "-O") != 0) || (strcmp(argv[4], "-a") != 0))
				usage(argv[1]);
			break;
		default :
			usage(argv[0]);
			break;
	}
	/* Initialisation des données du compilateur */
	yyin = fopen(argv[2], "r");
	/* phases d'analyse */
    yyparse ();
	/* traitements post analyse */
	afficherTableIndent();
	nettoyerTableIdent();
	/* sauvegarde des resultats */
}
