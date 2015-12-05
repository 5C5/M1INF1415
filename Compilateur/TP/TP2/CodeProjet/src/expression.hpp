#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "type.hpp"


using namespace std;


typedef enum {
	OPE_NONE,
	OPE_ADD,
	OPE_SUB,
	OPE_MUL,
	OPE_DIV ,     /* division */
	OPE_NEG ,     /*  moins unaire */
	OPE_AND ,     /*  ET logique */
	OPE_OR  ,     /*  OU logique */
	OPE_NOT ,     /*  NEGATION logique  */
	OPE_CPY ,     /*  copie */
	OPE_LT ,      /*  comparaison inférieur */
	OPE_GT ,      /*  comapraison supérieur */
	OPE_LE ,      /*  comparaison inférieur ou egal*/
	OPE_GE ,      /*  comparaison supérieur ou egal*/
	OPE_EQ ,      /*  comparaison egalite*/
	OPE_NEQ ,     /*  compraison difference*/
	OPE_JMP ,     /*  go to */
	OPE_JMPC ,    /*  go to si */
	OPE_ART ,     /*  acces a un element d'un tableau (droite) */
	OPE_ALT ,     /*  acces a un élement d'un tableau (gauche) */
	OPE_PTR ,     /*  adresse */
	OPE_RRT ,     /*  acces au contenu d'un pointeur (droite) */
	OPE_RLT ,     /*  acces au contenu d'un pointeur (gauche) */
	OPE_PSH ,     /*  empiler */
	OPE_PSA ,     /*   */
	OPE_PSP ,     /*  empiler une adresse */
	OPE_PSR ,     /*  empiler le contenu d'un pointeur */
	OPE_POP ,     /*  dépiler*/
	OPE_PPA ,     /*  */
	OPE_PPR ,     /*  dépiler le contenu d'un pointeur */
	OPE_CLL ,     /*  appeler un sous programme*/
	OPE_RET ,     /*  retour d'un sous programme*/
	OPE_RETV ,    /*  retourner un valeur d'un sous programme*/
	OPE_END       /*  termine l'éxécution du programme*/

}operateur;

class Expression{

	protected :
		Type * type;
		string a;
		string b;
		string tmp;
		string etiquette;
		operateur op;


	public:
		Expression(int, string, Type *, string, string, operateur);
		string getA();
		string getB();
		Type * getType();
		operateur getOp();
		string getTmp();

		void setA(string);
		void setB(string);
		void setType(Type *);
		void setOp(operateur);
		void setTmp(string);
		string getResultat();
		string isMathCompatible(Expression *, bool);
		string isTypeComparable(Expression *);
		string newTmp(int);


};

#endif
