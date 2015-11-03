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

vector<Symbole> TDS::getSymboles(){
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

void TDS::addSymbole(Symbole s){
	symboles.push_back(s);
}

void TDS::addSymbole(int id, string s){
	symboles.push_back(Symbole(id, s));
}
