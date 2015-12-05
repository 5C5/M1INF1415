#include "expression.hpp"
#include <vector>

using namespace std;

class Instruction {

	protected :
		string instruc;
		vector<Expression*> listeExpression;

	public :
		Instruction(string);
		void add(Expression *);
		string toString();
};
