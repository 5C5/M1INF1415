#include "type.hpp"

/*
 * Constructeur
 */
Type::Type(){
	this->type="indéfini";
	this->signification = "type";
	this->identifiant = -1;
}

/*
 * Constructeurs avec argument
 */
Type::Type(string t){
	this->type = t;
	this->signification = "type";
	this->identifiant = -1;
}

Type::Type(string t, int id){
	this->type = t;
	this->signification = "type";
	this->identifiant = id;
}

/*
 * Accesseurs
 */
string Type::getType(){
	return type;
}

void Type::setType(string t){
	type = t;
}

string Type::toString(){
	if(identifiant == -1)
		return " de type " + type;
	else
		return Symbole::toString() + " de type " + type + " ";
}

void Type::afficher(){
	if(this->identifiant ==-1)
		cout << " de type " << type;
	else{
		Symbole::afficher();
		cout << " de type " + type + " ";
	}
}
