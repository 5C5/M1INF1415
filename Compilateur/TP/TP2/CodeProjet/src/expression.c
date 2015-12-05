#include "expression.hpp"
#include <stdlib.h>
#include <stdio.h>

Expression::Expression(int n, string e, Type *t, string a, string b, operateur o){
	this->type = t;
	t->toString();
	this->etiquette = e;
	this->a = a;
	this->b = b;
	this->op = o;
	this->tmp = newTmp(n);
}

string Expression::getA(){
	return this->a;
}

string Expression::getB(){
	return this->b;
}

Type * Expression::getType(){
	return this->type;
}

operateur Expression::getOp(){
	return this->op;
}

string Expression::getTmp(){
	return this->tmp;
}

void Expression::setA(string s){
	this->a = s;
}

void Expression::setB(string s){
	this->b = s;
}

void Expression::setType(Type * t){
	this->type = t;
}
void Expression::setOp(operateur o){
	this->op = o;
}

string Expression::getResultat(){
	if(tmp != ""){
		return tmp;
	}else{
		return this->a;
	}
}

string Expression::newTmp(int n){

	string r = "__temp";
	char tmp[3];
	sprintf(tmp, "%d", n);
	string m = string(tmp);
	if (n <= -1)
		return "";
	else if(n < 10) 
		r = r + "00" + m;
	else if(n < 100) 
		r = r + "0" + m;
	else
		r = r + m;

	return r;
}

string Expression::isMathCompatible(Expression * e, bool assignation){
	
	if(this->type->getType() == "Entier" && this->type == e->getType()){

		return "Entier";
	}
	else if(this->type->getType() == "Reel" && this->type == e->getType() || this->type->getType() == "Entier" && e->getType()->getType() == "Reel" || this->type->getType() == "Reel" && e->getType()->getType() == "Entier"){
		return "Reel";
	}
	if(assignation && ((this->type->getType() == "Entier" && e->getType()->getType() == "Reel") || (this->type->getType() == "Reel" && e->getType()->getType() == "Entier"))){
		return this->type->getType();
	}
	else{
		return "";
	}
}

string Expression::isTypeComparable(Expression * e){

	if(e->getType() == this->type)
		return "Booleen";
	else if((e->getType()->getType() == "Entier" && this->getType()->getType() == "Reel") || (e->getType()->getType() == "Entier" && this->getType()->getType() == "Reel")){
		return "Booleen";
	}
	else{
		return "";
	}
}
