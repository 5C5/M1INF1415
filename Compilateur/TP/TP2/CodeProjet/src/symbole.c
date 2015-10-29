#include "symbole.hpp"

Symbole::Symbole(){
	this->identifiant = -1;
	this->signification = "";
}

Symbole::Symbole(int id, string sign){
	
	this->identifiant = id;
	this->signification = sign;
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
