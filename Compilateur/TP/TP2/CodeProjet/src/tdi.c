#include "tdi.hpp"

unsigned int Identificateur::num = 1 ;
vector<Identificateur> tdi;

Identificateur::Identificateur(const char * n){
	
	if(!this->num > 0){
		this->num = 1;
	}
	this->name = string(n);
	this->ident = num++;
}

unsigned int Identificateur::getIdent(){

	return this->ident;
}

const char * Identificateur::getNom(){

	return this->name.c_str();
}

unsigned ajouterIdentificateur(const char *n){

	tdi.push_back(Identificateur(n));
	return tdi.back().getIdent();
}

void sauvegardeTable(const char * name){

	FILE * fichier = NULL;

	if((fichier = fopen(name, "w"))!= NULL){
		for(vector<Identificateur>::iterator it = tdi.begin(); it!= tdi.end(); it++){
			fprintf(fichier, "nom : %s; numero : %d\n", it->getNom(), it->getIdent());
		}
	}
}

void afficherTable(void){
	
	for(vector<Identificateur>::iterator it = tdi.begin(); it!= tdi.end(); it++){
			printf("nom : %s; numero : %d\n", it->getNom(), it->getIdent());
		}
}

