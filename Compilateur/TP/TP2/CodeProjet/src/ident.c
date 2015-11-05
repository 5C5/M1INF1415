#include "ident.hpp"
#include <string.h>
unsigned int Identificateur::num = 1 ;

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


