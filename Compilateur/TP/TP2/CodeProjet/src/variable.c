#include "variable.hpp"

/*
 * Constructeur par défaut
 */
Variable::Variable(){
	this->type = NULL;
	this->signification = "";
	this->identifiant = -1;
}

/*
 * Constructeur avec argumments
 */
Variable::Variable(Symbole * t, int id){

	this->type = t;
	this->identifiant = id;
	this->signification = "variable";
}

/*
 * Accesseurs
 */

Symbole * Variable::getType(){
	return this->type;
}
void Variable::setType(Symbole * t){
	this->type = t;
}
