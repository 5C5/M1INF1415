#include "tdi.h"
/* Fichier contenant la description de la table des identificateurs*/

//Définition des variables et types
int numeroUnique = 1;

s_identificateur * TI = null;

/* Fonctions liés à la table des identificateurs*/

//Ajout d'un identificateur dans la table, renvoyant son numéro unique. Si l'identificateur est déjà dans la table des symboles, on renvoie juste son numéro unique
unsigned int ajouterIdentificateur (const char* s){

	int index = 0;
	s_identificateur *courant;
	
	if(TI == null){
		
		TI = (s_identificateur *) malloc(sizeof(s_identifcateur));
		TI->nom = (char *) malloc(strlen(s));
		strcpy(TI->nom, s);
		TI->id_unique = numeroUnique++;
		TI->suivant = null;
		return TI->id_unique;
	}
	else {

		courant = TI;
		while(courant->suivant !=null){
			
			if(strcmp(courant->nom, s) == 0)
				return courant->id_unique;
			else
				courant = courant->suivant;
		}
		courant->suivant = (s_identificateur *) malloc(sizeof(s_identificateur));
		courant = suivant;
		courant->nom = (char *) malloc(strlen(s));
		strcpy(courant->nom, s);
		courant->id_unique = numeroUnique++;
		return courant->id_unique;
	}

}

// recupere le nom associé à un numéro unique
const char* getNom(const unsigned int num) {

	if(num == 0){
		
		printf("Erreur : l'entier passé en paramètre doit être strictement supérieur à zéro\n");
		exit(0);
	}
	else {
		if(num > numeroUnique){
			printf("Erreur : le numéro que vous avez demandé n'est pas attribué\n");
			exit(0);
		}
		else {
			
			int i = 1;
			s_identificateur * courant = TI;
			
			for(; i < num + 1; i++){
				if(num == courant->id_unique)
					return courant->nom;
				else
					courant = courant->suivant;
			}
			printf("Erreur : le numero n'a pas pu être trouvé\n");
			exit(0);
		}
	}
}

//Fonction affichant la table des identificateurs dans la sortie standard
void afficherTableIndent(){
	s_identificateur * courant = TI;
	
	if(courant != null){	
		
		while(courant->suivant != null){
			
			printf("\tidentificateur : %s \tidentifiant unique : %i\n", courant->nom, courant->id);
			courant = courant->suivant;
		}
		printf("\tidentificateur : %s \tidentifiant unique : %i\n", courant->nom, courant->id);

	}
}

//Sauvegarde de la table des identificateurs dans un fichier dont le nom est passé en paramètre
void sauvegarderTableIdent(const char* nom){

	FILE* ficher = null;
	if((fichier = fopen(nom, "w+")) == null){
		printf("Erreur lors de l'ouverture de %s\n", nom);
		exit(0);
	}
	else {

		s_identificateur *courant = TI;
		
		if(courant != null){
			
			while(courant->suivant != null){

				fprintf("%i;%s\n", courant->id_unique, courant->nom);
				courant = courant->suivant;
			}
			
			fprintf("%i;%s\n", courant->id_unique, courant->nom);
		}
		fclose(fichier);
	}
}

// Nettoyage de la table des identificateurs pour libération mémoire
// Fonction nettoyant un noeud
void nettoyerIdent(s_identificateur* s){
	
	if(s->suivant != null){
		nettoyerIdent(s->suivant);
	}
	free(s->nom)
	free(s->suivant);
	s->suivant = null;
}

int nettoyerTableIdent(void){
	
	if(TI != null){
		
		nettoyerIdent(TI);
	}
	free(TI);
}
