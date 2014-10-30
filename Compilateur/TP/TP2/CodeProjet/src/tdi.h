#ifndef _TDI_H_
#define _TDI_H_

#define TAILLE 256

typedef struct identificateur{

	char nom[TAILLE];
	int id_unique;
	identificateur * suivant;

} s_identificateur;

extern s_identificateur * TI;
extern int numeroUnique;

unsigned int ajouterIdentificateur (const char *);
const char* getNom(const unsigned int);
void afficherTableIndent();
void sauvegarderTableIdent(const char *);
void nettoyerIdent(s_identificateur*);
int nettoyerTableIdent(void);

#endif
