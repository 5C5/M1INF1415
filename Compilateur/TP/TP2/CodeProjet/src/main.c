#include <cstdlib>
#include <cstddef>
#include <cstdio>
#include <getopt.h>
#include "tdi.hpp"

extern int yyparse ();
extern FILE* yyin;
extern void yyfinir(char *);

int main ( int argc, char** argv ){

	/*
	 * Variables du programme
	 */
	int optim = 0;
	int gene = 0;
	int debug = 0;

	/* Gestion de la ligne de commande */
	
	if(argc < 3 || argc > 6){
		
		cout << "Erreur dans les arguments" 
			<< endl << "Utilisation : ppc -c <filename> [-0] [-a]" 
			<< endl << " -O -> active les optimisation" 
			<< endl <<" -a -> active la génération de code assembleur"
			<<endl <<" -d -> active le debuggage" << endl;
		return EXIT_FAILURE;

	}else {

		int c;
		while ((c = getopt (argc, argv, "c:Oad")) != -1){

			switch (c){

				case 'a':
					gene = 1;
					break;

				case 'O':
					optim = 1;
					break;

				case 'd':
					debug = 1;
					break;

				case 'c':
					yyin = NULL;
					if((yyin = fopen(optarg, "r")) == NULL){
						fprintf(stderr, "nom de fichier incorrect\n");
						return EXIT_FAILURE;
					}
					break;

				case '?':
					if (optopt == 'c')
						fprintf (stderr, 
								"L'option -%c nécessite un argument \n", optopt);
					else if (isprint (optopt))
						fprintf (stderr, "Option inconnue `-%c'.\n", optopt);
					else 
						fprintf (stderr,
						"Caractère d'option inconnu `\\x%x'.\n", optopt);
					return EXIT_FAILURE;

				default:
					abort ();
			}

		}
		if(debug) {
			printf("Les options activées sont :\n");
			printf("-le debugage\n");
			if(gene)
				printf("-la génération du code assembleur \n");
			if(optim)
				printf("-l'optimisation du code\n");
		}
	}
	
	/* Initialisation des données du compilateur */
	/* phases d'analyse */
    yyparse ();
	/* traitements post analyse */
	/* sauvegarde des resultats */
	yyfinir(argv[2]);
}
