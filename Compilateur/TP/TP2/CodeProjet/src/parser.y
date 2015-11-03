%{

#include <cstddef>
#include <stdlib.h>
#include <stdio.h>
#include "type.hpp"
#include "symbole.hpp"
#include "tds.hpp"
#include "tdi.hpp"

extern int yyerror ( char* );
extern int yylex ();

TDS * courant;
vector<TDS> listeTDS;

%}

%union{
	int ident;
	int intval;
	int boolval;
	float realval;
	char charval;
	char * stringval;
	Type * typeval;
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
%type <typeval> SimpleType
%type <typeval> BaseType
%type <typeval> UserType
%type <typeval> Type

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
			   				TDS p = TDS(0, NULL, string(getNomFromIdent($2)));
			   				courant = &p;
							listeTDS.push_back(p);
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
							printf("Declaration de constante de type : %s\n",
							$3->toString().c_str());
							}
			 		;

BlockDeclType		:	KW_TYPE ListDeclType
			 		|
			 		;

ListDeclType		:	ListDeclType DeclType
			 		|	DeclType
			 		;

DeclType			:	TOK_IDENT OP_EQ Type SEP_SCOL	{
		   					printf("Type declaré : %s\n", 
							$3->toString().c_str());
							}
			 		;

Type				:	UserType	{$$ = $1;}
					|	SimpleType	{$$ = $1;}	
			 		;

UserType			:	EnumType	{
		   					printf("Enum n'a pas encore été géré\n"); 
							$$ = new Type("Enum");
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
					|	TOK_IDENT	{$$ = new Type("Identificateur");}
					;

BaseType			:	KW_INTEGER	{$$ = new Type("entier");}
		   			|	KW_REAL		{$$ = new Type("reel");}
					|	KW_BOOLEAN	{$$ = new Type("booleen");}
					|	KW_CHAR		{$$ = new Type("caractère");}
					|	KW_STRING	{$$ = new Type("chaine de caractere");}
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

DeclVar				:	ListIdent SEP_DOTS BaseType SEP_SCOL	{
		   					printf("Déclaration d'une variable de type : %s\n",
							$3->toString().c_str());
							}
			 		;

ListIdent			:	ListIdent SEP_COMMA TOK_IDENT
			 		|	TOK_IDENT
			 		;

BlockDeclFunc		:	ListDeclFunc SEP_SCOL
			 		|
			 		;

ListDeclFunc		:	ListDeclFunc SEP_SCOL DeclFunc
			 		|	DeclFunc
			 		;

DeclFunc			:	ProcDecl
			 		|	FuncDecl
			 		;

ProcDecl			:	ProcHeader SEP_SCOL BlockSimple
			 		;

ProcHeader			:	ProcIdent
			 		|	ProcIdent FormalArgs
			 		;

ProcIdent			:	KW_PROC TOK_IDENT
			 		;

FormalArgs			:	SEP_PO ListFormalArgs SEP_PF
			 		;

ListFormalArgs		:	ListFormalArgs SEP_SCOL FormalArg
			 		|	FormalArg
			 		;

FormalArg			:	ValFormalArg
			 		|	VarFormalArg
			 		;

ValFormalArg		:	ListIdent SEP_DOTS SimpleType
				 	;

VarFormalArg		:	KW_VAR ListIdent SEP_DOTS SimpleType
				 	;

FuncDecl			:	FuncHeader SEP_SCOL BlockSimple
			 		;

FuncHeader			:	FuncIdent FuncResult
			 		|	FuncIdent FormalArgs FuncResult
			 		;

FuncIdent			:	KW_FUNC TOK_IDENT
			 		;

FuncResult			:	SEP_DOTS SimpleType
			 		;

BlockCode			:	KW_BEGIN ListInstr KW_END
					|	KW_BEGIN ListInstr SEP_SCOL KW_END
					|	KW_BEGIN KW_END
			 		;

ListInstr			:	ListInstr SEP_SCOL Instr
			 		|	Instr
			 		;

Instr				:	KW_WHILE Expression KW_DO Instr
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

Expression			:	MathExpr
			 		|	CompExpr
			 		|	BoolExpr
			 		|	AtomExpr
			 		|	VarExpr
					|	TOK_IDENT SEP_PO ListeExpr SEP_PF
			 		;

MathExpr			:	Expression OP_ADD Expression
			 		|	Expression OP_SUB Expression
			 		|	Expression OP_MUL Expression
			 		|	Expression OP_SLASH Expression
			 		|	Expression KW_DIV Expression
			 		|	Expression KW_MOD Expression
			 		|	Expression OP_EXP Expression
			 		|	OP_SUB Expression %prec OP_NEG
			 		|	OP_ADD Expression %prec OP_POS
			 		;

CompExpr			:	Expression OP_EQ Expression
				 	|	Expression OP_NEQ Expression
				 	|	Expression OP_LT Expression
				 	|	Expression OP_LTE Expression
				 	|	Expression OP_GT Expression
			 		|	Expression OP_GTE Expression
			 		;

BoolExpr			:	Expression KW_AND Expression
			 		|	Expression KW_OR Expression
			 		|	Expression KW_XOR Expression
			 		|	KW_NOT Expression
			 		;

AtomExpr			:	SEP_PO Expression SEP_PF
			 		|	TOK_INTEGER
			 		|	TOK_REAL
					|	TOK_BOOLEAN
			 		|	TOK_CHAR
			 		|	TOK_STRING 

			 		;

VarExpr				:	TOK_IDENT
					|	VarExpr SEP_CO Expression SEP_CF
					|	VarExpr SEP_DOT TOK_IDENT %prec OP_DOT
					;

ListeExpr			:	ListeExpr SEP_COMMA Expression
					|	Expression
					;

%%
