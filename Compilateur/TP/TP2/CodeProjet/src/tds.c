#include "tds.hpp"

TDS::TDS(){

	this->contexte = -1;
	this->parent = NULL;
}

TDS::TDS(int c, TDS * pere){

	this->contexte = c;
	this->parent = pere;
}

int TDS::getContexte(){
	return this->contexte;
}

TDS * TDS::getParent(){
	return this->parent;
}

vector<Symbole> TDS::getSymboles(){
	return this->symboles;
}

void TDS::setContexte(int c){
	this->contexte = c;
}

void TDS::setParent(TDS * pere){
	this->parent = pere;
}

void TDS::addSymbole(Symbole s){
	symboles.push_back(s);
}

void TDS::addSymbole(int id, string s){
	symboles.push_back(Symbole(id, s));
}
