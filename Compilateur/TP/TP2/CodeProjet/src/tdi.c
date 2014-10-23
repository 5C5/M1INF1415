/* Fichier contenant la description de la table des identificateurs*/
#define TAILLE 256

//Définition des variables et types
int numeroUnique = 1;

typedef struct identificateur{

	char nom[TAILLE];
	int id_unique;
	identifcateur * suivant;

} s_identifcateur;

s_identificateur * TI = null;;

/* Fonctions liés à la table des identificateurs*/

//Ajout d'un identificateur dans la table, renvoyant son numéro unique. Si l'identificateur est déjà dans la table des symboles, on renvoie juste son numéro unique
unsigned int ajouterIdentificateur (const char* s){

	int index = 0;
	s_identificateur *courant;
	
	if(TI == null){
		
		*TI = malloc(sizeof(s_identifcateur));
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
		courant->suivant = malloc(sizeof(s_identificateur));
		strcpy(courant->suivant->nom, s);
		courant->suivant->id_unique = numeroUnique++;
		return courant->suivant->id_unique;
	}

}

// recupere le nom associé à un numéro unique
const char* getNom(const unsigned int num) {

	if(num == 0){
		
		printf("Erreur : l'entier passé en paramètre doit être strictement supérieur à zéro\n");
		exit(0);
	}
	else {
	}
}

//
void afficherTableIndent(){
}

//
void sauvegarderTableIdent(cont char* nom){

	FILE* ficher = null;
	if((fichier = fopen(nom, 'w')) == null){
		printf("Erreur lors de l'ouverture de %s\n", nom);
		exit(0);
	}
	else {
	}
}
