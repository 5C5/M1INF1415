#ifndef TYPE_H
#define TYPE_H

/* Structures de descriptions des types*/
#define TRUE 1
#define FALSE 0

/* Liste des différents types existants :
 * programme; fonction, procedure, type, constante, variable, argument, champ, , valenum, temporaire, etiquette, chaine*/

// Structure d'une variable
typedef struct {
	//Nom du type
	char* type;
} s_variable;

// Structure d'un type
typedef struct {
	//Nom du type
	char* type;
} s_type;

// Structure d'un programme
typedef struct {
	// Pas de type pour les programmes
	char* type = null;
} s_programme;

// Structure d'une fonction 
typedef struct {
	// Type de retour
	char* type;
	// Nombre d'argumments
	int arite;
} s_fonction

typedef union{
	s_variable* variable;
	s_type* type;
	s_programme* programme;
	s_fonction* fonction;
} signification;

#endif
