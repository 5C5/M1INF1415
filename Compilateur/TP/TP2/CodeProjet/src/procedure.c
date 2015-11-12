#include "procedure.hpp"

Procedure::Procedure(){

	this->signification = "procedure";
	this->identifiant = -1;
	this->arite = 0;
}

Procedure::Procedure(int a, int id){

	this->signification = "procedure";
	this->arite = a;
	this->identifiant = id;
}

int Procedure::getArite(){

	return this->arite;
}

void Procedure::setArite(int a){

	this->arite = a;
}

string Procedure::toString(){

	char c;
	sprintf(&c, "%d", this->arite);
	return Symbole::toString() + "d' arite " + string(&c);
}

void Procedure::afficher(){
	Symbole::afficher();
	cout << " d'arite " << this->arite;
}
