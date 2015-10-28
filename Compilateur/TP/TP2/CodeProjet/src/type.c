#include "type.hpp"

Type::Type(){
	type="indéfini";
}

Type::Type(string t){
	type = t;
}

string Type::getType(){
	return type;
}

void Type::setType(string t){
	type = t;
}

string Type::toString(){
	return type;
}
