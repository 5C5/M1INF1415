%{
	#include <stdio.h>
	#include <stdlib.h>

	int nb= 0;
%}

%%
[{] {nb ++;} 
[}] {nb --;}
. {}
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
	if(nb == 0){
		printf("L'imbrication des accolades est bonne!\n");
	}
	else{
		printf("Il existe un problème dans l'imbrication des accolades\n");
	}

	fclose(yyin);
}
