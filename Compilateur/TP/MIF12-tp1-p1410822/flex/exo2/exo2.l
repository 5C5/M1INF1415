%{
	/*
	* Fichier pour compter le nombre de caractère, de mots et de ligne 
	* second exercice du TP1 de compilation
	* Colas PICARD p1410822
	*/
	#include <stdio.h>
	#include <stdlib.h>

	int nb_char = 0;
	int nb_lne = 0;
	int nb_word = 0;
%}

%%
\n	{nb_lne ++; nb_char ++;}
.	{nb_char ++;}
[a-zA-Z0-9][\t\n<<EOF>> ] {nb_word ++;}

%%

int main(int argc, char** argv){


	if(argc > 1){

		yyin = fopen(argv[1], "r");
	}
	else{
		printf("Erreur : use exo1 <Fichier>\n");
		return EXIT_FAILURE;
	}
	yylex();
	printf("Le nombre de lignes dans %s est de %i, le nombre de caractères est de %i, le nombre de mot est de %i\n", argv[1], nb_lne, nb_char, nb_word);

	fclose(yyin);
}
