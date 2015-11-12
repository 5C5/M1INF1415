#include "symbole.hpp"

Symbole::Symbole(){
	this->identifiant = -1;
	this->signification = "";
}

Symbole::Symbole(int id, string s){
	
	this->identifiant = id;
	this->signification = s;
}

int Symbole::getIdentifiant(){
	return this->identifiant;
}

string Symbole::getSignification(){
	return this->signification;
}

void Symbole::setIdentifiant(int id){
	this->identifiant = id;
}

void Symbole::setSignification(string s){
	this->signification = s;
}

string Symbole::toString(){
	char c;
	sprintf(&c, "%d", this->identifiant);
	return "Identifiant n°" + string(&c) + " correspond à un(e) " + this->signification;
}

void Symbole::afficher(){

	cout << "Identifiant n° " << this->identifiant << " correspondant à un(e) " + this->signification;
}
