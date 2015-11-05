#include "tdi.hpp"

TDI::TDI(){}

unsigned int TDI::ajouterIdentificateur(const char *n){

	for(vector<Identificateur>::iterator it = this->table.begin(); 
			it < this->table.end(); 
			it++){
		if(strcmp(it->getNom(), n) == 0)
			return it->getIdent();
	}
	table.push_back(Identificateur(n));
	return table.back().getIdent();
}

unsigned int TDI::ajouterIdentificateur(Identificateur i){

	this->table.push_back(i);
	return i.getIdent();
}

void TDI::sauvegarderTableIdent(const char * name){

	FILE * fichier = NULL;

	if((fichier = fopen(name, "w"))!= NULL){
		for(vector<Identificateur>::iterator it = this->table.begin(); 
				it!= this->table.end(); 
				it++){
			fprintf(fichier, "nom : %s; numero : %d\n", it->getNom(), it->getIdent());
		}
	}
}

void TDI::afficherTableIdent(void){
	
	for(vector<Identificateur>::iterator it = this->table.begin(); it!= this->table.end(); it++){
			printf("Identificateur : %s; numero : %d\n", it->getNom(), it->getIdent());
		}
}

const char * TDI::getNomFromId(unsigned int id){
	for(vector<Identificateur>::iterator it = this->table.begin();
			it!= this->table.end();
			it++){
		if(it->getIdent() == id)
			return it->getNom();
	}
	return "";
}
