#include "instruction.hpp"

Instruction::Instruction(string nom){
	this->instruc = nom;
	listeExpression = vector<Expression *>();
}

void Instruction::add(Expression * ex){

	listeExpression.push_back(ex);
}

string Instruction::toString(){

	return "oups... J'ai oublié de developper ça...\n";
}
