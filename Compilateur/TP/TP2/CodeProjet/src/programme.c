#include "programme.hpp"

Programme::Programme(){
	this->signification = "programme";
	this->nom = "";
}

Programme::Programme(string n, int i){
	this->signification = "programme";
	this->nom = n;
	this->identifiant = i;
}

string Programme::getNom(){
	return this->nom;
}

void Programme::setNom(string n){
	this->nom = n;
}
