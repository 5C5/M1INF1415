%{
	#include <stdio.h>
	#include <stdlib.h>
	int yyerror(char *);
%}
%start P
%token openbracket
%token closebracket
%token contenu

%%
P : B
	;
B : openbracket B closebracket
  | contenu
  ;

%%
int yyerror(char *e){
	printf("%s\n", e);
}

int main(int argc, char **argv){
	
	if(argc > 1){
		stdin = fopen(argv[1], "r");
	}

	int result = yyparse();
	printf("Le resultat (0 pour succès, 1 sinon) est : %i\n", result);

	if(argc > 1){
		fclose(stdin);
	}
	return result;
}
