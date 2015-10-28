#ifndef TYPE_H
#define TYPE_H

#include <string>

using namespace std;

class Type {

	protected :
		string type;

	public :
		Type();
		Type(string);
		string getType();
		void setType(string);
		string toString();
};

#endif
