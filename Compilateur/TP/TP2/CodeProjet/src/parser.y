%{

#include <cstddef>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <stack>
#include "type.hpp"
#include "symbole.hpp"
#include "programme.hpp"
#include "tds.hpp"
#include "tdi.hpp"
#include "variable.hpp"
#include "procedure.hpp"
#include "fonction.hpp"
#include "expression.hpp"
#include "instruction.hpp"

extern int yyerror ( char* );
extern int yylex ();

extern void yyfinir(char *);

//Table des identificateurs
extern TDI * tdi;

//Table des Symboles courante
TDS * courant;
// Liste des tables des symbole
vector<TDS *> listeTDS;
//Liste des identificateurs lors des déclarations groupées
vector<int> listeVar;
//Arités des fonctions et procédures;
int arite = 0;
//Numéro du contexte
int contexte = 0;
//Numero de la variable temporaire pour le code 3ad
int numTp = 0;
//Liste des instructions
vector<Instruction *> listeInstruction;
//pile d'instruction temporaires
stack<Instruction *> * listeCourante;

//Etiquettes
stack<pair<string, int> >  * etiquette;

//Numero d'etiquette
int numEti = 0;

%}

%union{
	int ident;
	int intval;
	int boolval;
	float realval;
	char charval;
	char * stringval;
	Symbole * sval;
	Expression * eval;
}

%token KW_PROGRAM
%token KW_CONST
%token KW_TYPE
%token KW_VAR
%token KW_ARRAY
%token KW_OF
%token KW_RECORD
%token KW_BEGIN
%token KW_END
%token KW_DIV
%token KW_MOD
%token KW_AND
%token KW_OR
%token KW_XOR
%token KW_NOT
%token KW_IF
%token KW_THEN
%token KW_ELSE
%token KW_WHILE
%token KW_DO
%token KW_REPEAT
%token KW_UNTIL
%token KW_FOR
%token KW_TO
%token KW_DOWNTO
%token KW_PROC
%token KW_FUNC
%token KW_INTEGER
%token KW_REAL
%token KW_BOOLEAN
%token KW_CHAR
%token KW_STRING

%token KW_WRITE
%token KW_WRITELN
%token KW_READ

%token SEP_SCOL
%token SEP_DOT
%token SEP_DOTS
%token SEP_DOTDOT
%token SEP_COMMA
%token SEP_CO
%token SEP_CF
%token SEP_PO
%token SEP_PF

%token OP_EQ
%token OP_NEQ
%token OP_LT
%token OP_LTE
%token OP_GT
%token OP_GTE
%token OP_ADD
%token OP_SUB
%token OP_MUL
%token OP_SLASH
%token OP_EXP
%token OP_AFFECT

%token <ident> TOK_IDENT
%token <intval> TOK_INTEGER
%token <realval> TOK_REAL
%token <boolval> TOK_BOOLEAN
%token <charval> TOK_CHAR
%token <stringval> TOK_STRING

%type <ident> ProgramHeader
%type <sval> SimpleType
%type <ident> ProcIdent
%type <ident> FuncIdent
%type <sval> FuncResult
%type <sval> BaseType
%type <sval> UserType
%type <sval> Type
%type <eval> Expression
%type <eval> AtomExpr
%type <eval> MathExpr
%type <eval> BoolExpr
%type <eval> VarExpr
%type <eval> CompExpr

%start Program

%nonassoc OP_EQ OP_NEQ OP_GT OP_LT OP_GTE OP_LTE
%left OP_ADD OP_SUB KW_OR KW_XOR
%left OP_MUL OP_SLASH KW_AND KW_DIV KW_MOD
%right KW_NOT OP_NEG OP_POS
%left OP_EXP
%nonassoc OP_PTR
%nonassoc OP_DOT
%left SEP_CO

%nonassoc KW_IFX
%nonassoc KW_ELSE

%%
	
Program				:	ProgramHeader SEP_SCOL Block SEP_DOT
					;

ProgramHeader		:	KW_PROGRAM TOK_IDENT	{
			   				TDS *ts = new TDS(contexte++, NULL, string(tdi->getNomFromId($2)));
			   				courant = ts;
							listeTDS.push_back(ts);
							Programme *p = new Programme(string(tdi->getNomFromId($2)), $2);
							courant->addSymbole(p);
							Instruction * i = new Instruction(string(tdi->getNomFromId($2)));
							//listeInstruction.push_back(i);
							//listeCourante->push(i);
			   			}
					;

Block				:	BlockDeclConst BlockDeclType BlockDeclVar BlockDeclFunc BlockCode
					;

BlockSimple			:	BlockDeclConst BlockDeclType BlockDeclVar BlockCode
					;

BlockDeclConst		:	KW_CONST ListDeclConst	
			 		|
			 		;

ListDeclConst		:	ListDeclConst DeclConst
			 		|	DeclConst
			 		;

DeclConst			:	TOK_IDENT OP_EQ Expression SEP_SCOL
					|	TOK_IDENT SEP_DOTS BaseType OP_EQ Expression SEP_SCOL	{
							}
			 		;

BlockDeclType		:	KW_TYPE ListDeclType
			 		|
			 		;

ListDeclType		:	ListDeclType DeclType
			 		|	DeclType
			 		;

DeclType			:	TOK_IDENT OP_EQ Type SEP_SCOL	{
		   					$3->setIdentifiant($1);
		   					courant->addSymbole($3);
							}
			 		;

Type				:	UserType	{$$ = $1;}
					|	SimpleType	{$$ = $1;}	
			 		;

UserType			:	EnumType	{
							$$ = new Type("Enumeration");
							}
			 		|	InterType	{
							printf("Intervalle n'a pas encore été géré\n");
							$$ = new Type("Intervalle");		
							}
			 		|	ArrayType	{
							printf("Tableau n'a pas encore été géré\n");
							$$ = new Type("Tableau");
							}
			 		|	RecordType	{
							printf("Record n'a pas encore été géré\n");
							$$ = new Type("Record");
							}
			 		;

SimpleType			:	BaseType	{$$ = $1;}
					|	TOK_IDENT	{
							/*
							* Type utilisateurs pas encore gérés
							*/
							$$ = NULL;
							}
					;

BaseType			:	KW_INTEGER	{$$ = new Type("Entier");}
		   			|	KW_REAL		{$$ = new Type("Reel");}
					|	KW_BOOLEAN	{$$ = new Type("Booleen");}
					|	KW_CHAR		{$$ = new Type("Caractere");}
					|	KW_STRING	{$$ = new Type("Chaine");}
					;

EnumType			:	SEP_PO ListEnumValue SEP_PF
			 		;

ListEnumValue		:	ListEnumValue SEP_COMMA TOK_IDENT
			 		|	TOK_IDENT
			 		;

InterType			:	InterBase SEP_DOTDOT InterBase
			 		;

InterBase			:	TOK_IDENT
			 		|	TOK_INTEGER
					|	TOK_CHAR
			 		;

ArrayType			:	KW_ARRAY SEP_CO ArrayIndex SEP_CF KW_OF SimpleType
			 		;

ArrayIndex			:	TOK_IDENT
			 		|	InterType
			 		;
RecordType			:	KW_RECORD RecordFields KW_END
			 		;

RecordFields		:	RecordFields SEP_SCOL RecordField
			 		|	RecordField
			 		;

RecordField			:	ListIdent SEP_DOTS SimpleType
			 		;

BlockDeclVar		:	KW_VAR ListDeclVar
			 		|
			 		;

ListDeclVar			:	ListDeclVar DeclVar
			 		|	DeclVar
			 		;

DeclVar				:	ListIdent SEP_DOTS SimpleType SEP_SCOL	{
		   					
							for(unsigned int i = 0;
								i < listeVar.size();
								i++){
									Variable * v = new Variable($3, listeVar[i]);
									courant->addSymbole(v);
							}
							listeVar.clear();
						}
			 		;

ListIdent			:	ListIdent SEP_COMMA TOK_IDENT	{
							listeVar.push_back($3);
						}
			 		|	TOK_IDENT	{
							listeVar.push_back($1);
						}
			 		;

BlockDeclFunc		:	ListDeclFunc SEP_SCOL
			 		|
			 		;

ListDeclFunc		:	ListDeclFunc SEP_SCOL DeclFunc {
			  				courant = courant->getParent();
						}
			 		|	DeclFunc {
							courant = courant->getParent();
						}
			 		;

DeclFunc			:	ProcDecl
			 		|	FuncDecl
			 		;

ProcDecl			:	ProcHeader SEP_SCOL BlockSimple
			 		;

ProcHeader			:	ProcIdent	{
			 				Procedure * proc = new Procedure($1, arite);
							arite = 0;
							courant->addSymbole(proc);
							TDS * t = new TDS(contexte++, courant, tdi->getNomFromId($1));
							courant = t;
							listeTDS.push_back(t);
						}
			 		|	ProcIdent FormalArgs {
							Procedure * proc = new Procedure($1, arite);
							arite = 0;
							courant->addSymbole(proc);
							TDS * t = new TDS(contexte++, courant, tdi->getNomFromId($1));
							courant = t;
							listeTDS.push_back(t);
							}
			 		;

ProcIdent			:	KW_PROC TOK_IDENT {
							$$ = $2;
						}
			 		;

FormalArgs			:	SEP_PO ListFormalArgs SEP_PF
			 		;

ListFormalArgs		:	ListFormalArgs SEP_SCOL FormalArg
			 		|	FormalArg
			 		;

FormalArg			:	ValFormalArg
			 		|	VarFormalArg
			 		;

ValFormalArg		:	ListIdent SEP_DOTS SimpleType {
			  				for(unsigned int i = 0; i < listeVar.size();i++){
								arite++;
							}
							listeVar.clear();
			  				}
				 	;

VarFormalArg		:	KW_VAR ListIdent SEP_DOTS SimpleType
				 	;

FuncDecl			:	FuncHeader SEP_SCOL BlockSimple
			 		;

FuncHeader			:	FuncIdent FuncResult {
			 				Fonction * f = new Fonction(arite, $1, $2);
							courant->addSymbole(f);
							arite = 0;

							TDS * t = new TDS(contexte++, courant, tdi->getNomFromId($1));
							courant = t;
							listeTDS.push_back(t);
			 			}
			 		|	FuncIdent FormalArgs FuncResult {
							Fonction * f = new Fonction(arite, $1, $3);
							courant->addSymbole(f);
							arite = 0;
							TDS * t = new TDS(contexte++, courant, tdi->getNomFromId($1));
							courant = t;
							listeTDS.push_back(t);
						}
			 		;

FuncIdent			:	KW_FUNC TOK_IDENT {
							$$ = $2;
						}
			 		;

FuncResult			:	SEP_DOTS SimpleType {$$ = $2;}
			 		;

BlockCode			:	KW_BEGIN ListInstr KW_END
					|	KW_BEGIN ListInstr SEP_SCOL KW_END
					|	KW_BEGIN KW_END
			 		;

ListInstr			:	ListInstr SEP_SCOL Instr
			 		|	Instr
			 		;

Instr				:	KW_WHILE Expression KW_DO Instr	{
		 					
		 				}
			 		|	KW_REPEAT ListInstr KW_UNTIL Expression
			 		|	KW_FOR TOK_IDENT OP_AFFECT Expression ForDirection Expression KW_DO Instr
			 		|	KW_IF Expression KW_THEN Instr %prec KW_IFX
			 		|	KW_IF Expression KW_THEN Instr KW_ELSE Instr
			 		|	VarExpr OP_AFFECT Expression
			 		|	TOK_IDENT SEP_PO ListeExpr SEP_PF
			 		|	TOK_IDENT
			 		|	KW_WRITE SEP_PO ListeExpr SEP_PF
			 		|	KW_WRITELN SEP_PO ListeExpr SEP_PF
			 		|	KW_READ SEP_PO VarExpr SEP_PF
			 		|	BlockCode
			 		;

ForDirection		:	KW_TO
			 		|	KW_DOWNTO
			 		;

Expression			:	MathExpr	{$$ = $1;}
			 		|	CompExpr	{$$ = $1;}
			 		|	BoolExpr	{$$ = $1;}
			 		|	AtomExpr	{$$ = $1;}
			 		|	VarExpr		{$$ = $1;}
					|	TOK_IDENT SEP_PO ListeExpr SEP_PF	{
							Symbole * s = courant->getSymbole($1);
							if(s->getSignification() == "fonction"){
								//Appel à la fonction
								Expression * e = new Expression(numTp++, "", new Type(((Type *)((Fonction *)s)->getType())->getType()), string(tdi->getNomFromId($1)), "", OPE_CLL);
								listeCourante->top()->add(e);
								//Sortie du résultat de la fonction
								e = new Expression(-1, "", new Type(((Type *)((Fonction *)s)->getType())->getType()), e->newTmp(numTp++), "", OPE_POP);
								$$ = e;
							}
							else if(s->getSignification() == "procedure"){
								Expression * e = new Expression(-1, "", new Type(((Type *)((Fonction *)s)->getType())->getType()), string(tdi->getNomFromId($1)), string(""), OPE_CLL);
								listeCourante->top()->add(e);
								$$ = NULL;
							}
						}
			 		;

MathExpr			:	Expression OP_ADD Expression	{
		   					printf("J'ai raison\n");
		   					string t = $1->isMathCompatible($3, false);
							if(t!= ""){
								listeCourante->top()->add($1);
								listeCourante->top()->add($3);
								Expression * e = new Expression(numTp++, "", new Type(t), $1->getResultat(), $3->getResultat(), OPE_ADD);
								//listeCourante->top()->add(e);
								$$ = e;
							}
							else {
								yyerror("Aille! Types incompatibles!\n");
								$$ = NULL;
							}
		   				}
			 		|	Expression OP_SUB Expression	{
		   					string t = $1->isMathCompatible($3, false);
							if(t!= ""){
								listeCourante->top()->add($1);
								listeCourante->top()->add($3);
								Expression * e = new Expression(numTp++, "", new Type(t), $1->getResultat(), $3->getResultat(), OPE_SUB);
								//listeCourante->top()->add(e);
								$$ = e;
							}
							else {
								yyerror("Aille! Types incompatibles!\n");
								$$ = NULL;
							}
						}
			 		|	Expression OP_MUL Expression	{
							string t = $1->isMathCompatible($3, false);
							if(t!= ""){
								listeCourante->top()->add($1);
								listeCourante->top()->add($3);
								Expression * e = new Expression(numTp++, "", new Type(t), $1->getResultat(), $3->getResultat(), OPE_MUL);
								//listeCourante->top()->add(e);
								$$ = e;
							}
							else {
								yyerror("Aille! Types incompatibles!\n");
								$$ = NULL;
							}	
						}
			 		|	Expression OP_SLASH Expression	{
							string t = $1->isMathCompatible($3, false);
							if(t!= ""){
								listeCourante->top()->add($1);
								listeCourante->top()->add($3);
								Expression * e = new Expression(numTp++, "", new Type(t), $1->getResultat(), $3->getResultat(), OPE_DIV);
								//listeCourante->top()->add(e);
								$$ = e;
							}
							else {
								yyerror("Aille! Types incompatibles!\n");
								$$ = NULL;
							}
						}
			 		|	Expression KW_DIV Expression	{
		 					string t = $1->isMathCompatible($3, false);
							if(t!= ""){
								listeCourante->top()->add($1);
								listeCourante->top()->add($3);
								Expression * e = new Expression(numTp++, "", new Type(t), $1->getResultat(), $3->getResultat(), OPE_DIV);
								//listeCourante->top()->add(e);
								$$ = e;
							}
							else {
								yyerror("Aille! Types incompatibles!\n");
								$$ = NULL;
							}
						}
			 		|	Expression KW_MOD Expression	{
							printf("Oups... J'ai pas réussi. Faut gérer comment le modulo?\n");
							$$ = NULL;	
						}
			 		|	Expression OP_EXP Expression	{
							$$ = NULL;
							yyerror("Je vois pas à quoi ça correspond\n");
						}
			 		|	OP_SUB Expression %prec OP_NEG	{}
			 		|	OP_ADD Expression %prec OP_POS	{}
			 		;

CompExpr			:	Expression OP_EQ Expression		{
		   					string t = $1->isTypeComparable($3);
							if(t != ""){
								listeCourante->top()->add($1);
								listeCourante->top()->add($3);
								Expression * e = new Expression(numTp++, "", new Type(t),$1->getResultat(),$3->getResultat(), OPE_EQ);
								$$ = e;
							}else{
								yyerror("Erreur! types incomparables!\n");
								$$ = NULL;
							}
		   				}
				 	|	Expression OP_NEQ Expression	{
							string t = $1->isTypeComparable($3);
							if(t != ""){
								listeCourante->top()->add($1);
								listeCourante->top()->add($3);
								Expression * e = new Expression(numTp++, "", new Type(t),$1->getResultat(),$3->getResultat(), OPE_NEQ);
								$$ = e;
							}else{
								yyerror("Erreur! types incomparables!\n");
								$$ = NULL;
							}
						}
				 	|	Expression OP_LT Expression		{
							string t = $1->isTypeComparable($3);
							if(t != ""){
								listeCourante->top()->add($1);
								listeCourante->top()->add($3);
								Expression * e = new Expression(numTp++, "", new Type(t),$1->getResultat(),$3->getResultat(), OPE_LT);
								$$ = e;
							}else{
								yyerror("Erreur! types incomparables!\n");
								$$ = NULL;
							}
						}
				 	|	Expression OP_LTE Expression	{
							string t = $1->isTypeComparable($3);
							if(t != ""){
								listeCourante->top()->add($1);
								listeCourante->top()->add($3);
								Expression * e = new Expression(numTp++, "", new Type(t),$1->getResultat(),$3->getResultat(), OPE_LE);
								$$ = e;
							}else{
								yyerror("Erreur! types incomparables!\n");
								$$ = NULL;
							}
						}
				 	|	Expression OP_GT Expression		{
							string t = $1->isTypeComparable($3);
							if(t != ""){
								listeCourante->top()->add($1);
								listeCourante->top()->add($3);
								Expression * e = new Expression(numTp++, "", new Type(t),$1->getResultat(),$3->getResultat(), OPE_GT);
								$$ = e;
							}else{
								yyerror("Erreur! types incomparables!\n");
								$$ = NULL;
							}
						}
			 		|	Expression OP_GTE Expression	{
							string t = $1->isTypeComparable($3);
							if(t != ""){
								listeCourante->top()->add($1);
								listeCourante->top()->add($3);
								Expression * e = new Expression(numTp++, "", new Type(t),$1->getResultat(),$3->getResultat(), OPE_GE);
								$$ = e;
							}else{
								yyerror("Erreur! types incomparables!\n");
								$$ = NULL;
							}
						}
			 		;

BoolExpr			:	Expression KW_AND Expression	{
		   					if($1->getType()->getType() == "Booleen" && $3->getType()->getType() == "Booleen"){
								listeCourante->top()->add($1);
								listeCourante->top()->add($3);
								Expression * e = new Expression(numTp++, "", new Type("Booleen"), $1->getResultat(), $3->getResultat(), OPE_AND);
								$$ = e;
							}
							else{
								yyerror("Oups... Types non booleen\n");
								$$ = NULL;
							}
		   				}
			 		|	Expression KW_OR Expression {
							if($1->getType()->getType() == "Booleen" && $3->getType()->getType() == "Booleen"){
								listeCourante->top()->add($1);
								listeCourante->top()->add($3);
								Expression * e = new Expression(numTp++, "", new Type("Booleen"), $1->getResultat(), $3->getResultat(), OPE_OR);
								$$ = e;
							}
							else{
								yyerror("Oups... Types non booleen\n");
								$$ = NULL;
							}

						}
			 		|	Expression KW_XOR Expression {
							yyerror("Ici, j'imagine qu'il faudrait vérifier que les deux expressions soient différentes\n");
							$$ = NULL;

						}
			 		|	KW_NOT Expression {
							if($2->getType()->getType() == "Booleen"){
								listeCourante->top()->add($2);
								Expression * e = new Expression(numTp++, "", new Type("Booleen"), $2->getResultat(), "", OPE_NOT);
								$$ = e;
							}
							else{
								yyerror("Aille! Ce n'est pas un booleen\n");
								$$ = NULL;
							}
						}
			 		;

AtomExpr			:	SEP_PO Expression SEP_PF	{$$ = $2;}
			 		|	TOK_INTEGER		{
							char t[10];
							sprintf(t, "%d", $1);
							$$ = new Expression(numTp++, "", new Type("Entier"), string(t), "", OPE_CPY);
						}
			 		|	TOK_REAL		{
							char t[10];
							sprintf(t, "%f", $1);
							$$ = new Expression(numTp++, "", new Type("Reel"), string(t), "", OPE_CPY);
						}
					|	TOK_BOOLEAN		{
							char t[1];
							sprintf(t, "%d", $1);
							$$ = new Expression(numTp++, "", new Type("Booleen"), string(t), "", OPE_CPY);
						}
			 		|	TOK_CHAR		{
							$$ = new Expression(numTp++, "", new Type("Caractere"), "", "", OPE_CPY);
						}
			 		|	TOK_STRING 		{
							$$ = new Expression(numTp, "", new Type("Chaine"), $1, "", OPE_CPY);
						}

			 		;

VarExpr				:	TOK_IDENT	{
							Symbole * s = courant->getSymbole($1);
							if(s->getSignification() == "variable"){
								printf("ici\n");
								Expression * e = new Expression(numTp++, "", new Type(((Type *)((Variable *)s)->getType())->getType()), string(tdi->getNomFromId($1)), "", OPE_CPY);
								$$ = e;
							}
							else{
								yyerror("Pas eu le temps de gérer les autres cas\n");
								$$ = NULL;
							}
		   				}
					|	VarExpr SEP_CO Expression SEP_CF
					|	VarExpr SEP_DOT TOK_IDENT %prec OP_DOT
					;

ListeExpr			:	ListeExpr SEP_COMMA Expression
					|	Expression
					;

%%

void yyfinir(char * file){

	string nom(file);
	size_t pos1 = nom.find("/");
	size_t pos2 = nom.find(".");
	string prefixe = nom.substr(pos1 + 1, pos2 - pos1 - 1);
	prefixe = "intermediaire/" + prefixe;
	nom = prefixe;
	char * ti = (char *)malloc(sizeof(prefixe) + 3);
	strcpy(ti, prefixe.c_str());
	strcat(ti, ".ti");
	free(ti);
	
	
	tdi->sauvegarderTableIdent(ti);
	tdi->afficherTableIdent();
	
	for(vector<TDS *>::iterator it = listeTDS.begin();
		it != listeTDS.end();
		it++){
		char * ts = (char *)malloc(sizeof(prefixe) + 6);
		prefixe += ".";
		char tmp[4];
		sprintf(tmp, "%d", (*it)->getContexte());
		prefixe.append(tmp);
		prefixe += ".ts";
		strcpy(ts, prefixe.c_str());
		(*it)->sauvegarderTDS(ts);
		(*it)->afficherTDS();
		prefixe = nom;
		free(ts);
				
	}

}
