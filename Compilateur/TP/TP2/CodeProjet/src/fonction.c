#include "fonction.hpp"

Fonction::Fonction(){
	this->identifiant = -1;
	this->signification = "fonction";
	this->arite = 0;
	this->retour = NULL;
}

Fonction::Fonction(int a, int id, Symbole * t){

	this->identifiant = id;
	this->signification = "fonction";
	this->arite = a;
	this->retour = t;
}

Fonction::Fonction(int a, int id){
	this->identifiant = id;
	this->signification = "fonction";
	this->arite = a;
	this->retour = NULL;
}

int Fonction::getArite(){
	return this->arite;
}

void Fonction::setArite(int a){
	this->arite = a;
}

Symbole * Fonction::getType(){
	return this->retour;
}
void Fonction::setType(Symbole * t){
	this->retour = t;
}

string Fonction::toString(){

	char c;
	sprintf(&c, "%d", this->arite);
	return Symbole::toString() + string(" d'arite ") + string(&c) + ((Type *)this->retour)->toString();
}
