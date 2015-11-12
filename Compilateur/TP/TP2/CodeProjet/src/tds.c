#include "tds.hpp"

TDS::TDS(){

	this->contexte = -1;
	this->parent = NULL;
	this->id = "";
}

TDS::TDS(int c, TDS * pere, string s){

	this->contexte = c;
	this->parent = pere;
	this->id = s;
}

int TDS::getContexte(){
	return this->contexte;
}

TDS * TDS::getParent(){
	return this->parent;
}

string TDS::getId(){
	return this->id;
}

vector<Symbole *>TDS::getSymboles(){
	return this->symboles;
}

void TDS::setContexte(int c){
	this->contexte = c;
}

void TDS::setParent(TDS * pere){
	this->parent = pere;
}

void TDS::setId(string s){
	this->id = s;
}

void TDS::addSymbole(Symbole *s){
	symboles.push_back(s);
}

void TDS::addSymbole(int id, string s){
	symboles.push_back(new Symbole(id, s));
}

string TDS::getSignification(int id){

	for(vector<Symbole *>::iterator it = symboles.begin();
			it != symboles.end();
			it++){
		if((*it)->getIdentifiant() == id)
			return (*it)->getSignification();
	}
	return "";
}

void TDS::afficherTDS(){

	printf("\nAffichage de la table des Symboles du contexte %d\n", this->contexte);
	for(vector<Symbole *>::iterator it = this->symboles.begin();
			it != this->symboles.end();
			it++){
		(*it)->afficher();
		printf("\n");
	}
}

void TDS::sauvegarderTDS(const char *name){

	FILE * fichier = NULL;

	if((fichier = fopen(name, "w")) != NULL){
		for(vector<Symbole *>::iterator it = this->symboles.begin();
			it != this->symboles.end();
			it++){

			fprintf(fichier, "Id : %d signification : %s\n", (*it)->getIdentifiant(), (*it)->getSignification().c_str());
		}
	}
}
