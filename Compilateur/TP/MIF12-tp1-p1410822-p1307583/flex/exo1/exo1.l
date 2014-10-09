%{
	#include <stdio.h>
	#include <stdlib.h>

	int nb_char = 0;
	int nb_lne = 0;
%}
%%
\n	{nb_lne ++; nb_char ++; printf("nbre ligne = %i\n", nb_lne);}
.	{printf("caractère lu\n"); nb_char ++;}

%%

int main(int argc, char** argv){

	printf("Entrée dans le main\n");

	if(argc > 1){

		yyin = fopen(argv[1], "r");
		printf("Fichier ouvert : %s\n", argv[1]);
	}
	else{
		printf("Erreur : use exo1 <Fichier>\n");
		return EXIT_FAILURE;
	}
	yylex();
	printf("Le nombre de lignes dans %s est de %i, et le nombre de caractères est de %i\n", argv[1], nb_lne, nb_char);

	fclose(yyin);
}
