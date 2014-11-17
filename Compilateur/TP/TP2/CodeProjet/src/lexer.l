%{
/*
 * pascal.l
 *
 * lex input file for pascal scanner
 *
 */
 
#include <cstdio>
#include <cmath>
#include "parser.h"
#include "tdi.h"
#include "type.h"

extern int row, column;

extern int yyerror ( char* m );

extern int yylex ();

extern void commenteof ();

%}

A [aA]
B [bB]
C [cC]
D [dD]
E [eE]
F [fF]
G [gG]
H [hH]
I [iI]
J [jJ]
K [kK]
L [lL]
M [mM]
N [nN]
O [oO]
P [pP]
Q [qQ]
R [rR]
S [sS]
T [tT]
U [uU]
V [vV]
W [wW]
X [xX]
Y [yY]
Z [zZ]
NQUOTE [^']
CHIFFRES [0-9]+

%%

{A}{N}{D}						column += yyleng; return KW_AND;
{A}{R}{R}{A}{Y}					column += yyleng; return KW_ARRAY;
{C}{O}{N}{S}{T}					column += yyleng; return KW_CONST;
{D}{I}{V}						column += yyleng; return KW_DIV;
{D}{O}							column += yyleng; return KW_DO;
{D}{O}{W}{N}{T}{O}				column += yyleng; return KW_DOWNTO;
{E}{L}{S}{E}					column += yyleng; return KW_ELSE;
{E}{N}{D}						column += yyleng; return KW_END;
{F}{O}{R}						column += yyleng; return KW_FOR;
{F}{U}{N}{C}{T}{I}{O}{N}		column += yyleng; return KW_FUNC;
{I}{F}							column += yyleng; return KW_IF;
{M}{O}{D}						column += yyleng; return KW_MOD;
{N}{O}{T}						column += yyleng; return KW_NOT;
{O}{F}							column += yyleng; return KW_OF;
{O}{R}							column += yyleng; return KW_OR;
{B}{E}{G}{I}{N}					column += yyleng; return KW_BEGIN;
{P}{R}{O}{C}{E}{D}{U}{R}{E}		column += yyleng; return KW_PROC;
{P}{R}{O}{G}{R}{A}{M}			column += yyleng; return KW_PROGRAM;
{R}{E}{C}{O}{R}{D}				column += yyleng; return KW_RECORD;
{R}{E}{P}{E}{A}{T}				column += yyleng; return KW_REPEAT;
{T}{H}{E}{N}					column += yyleng; return KW_THEN;
{T}{O}							column += yyleng; return KW_TO;
{T}{Y}{P}{E}					column += yyleng; return KW_TYPE;
{U}{N}{T}{I}{L}					column += yyleng; return KW_UNTIL;
{V}{A}{R}						column += yyleng; return KW_VAR;
{W}{H}{I}{L}{E}					column += yyleng; return KW_WHILE;
{X}{O}{R}						column += yyleng; return KW_XOR;
{I}{N}{T}{E}{G}{E}{R}			column += yyleng; return KW_INTEGER;
{R}{E}{A}{L}					column += yyleng; return KW_REAL;
{B}{O}{O}{L}{E}{A}{N}			column += yyleng; return KW_BOOLEAN;
{C}{H}{A}{R}					column += yyleng; return KW_CHAR;
{S}{T}{R}{I}{N}{G}				column += yyleng; return KW_STRING;
{W}{R}{I}{T}{E}					column += yyleng; return KW_WRITE;
{W}{R}{I}{T}{E}{L}{N}			column += yyleng; return KW_WRITELN;
{R}{E}{A}{D}					column += yyleng; return KW_READ;

":="							column += yyleng; return OP_AFFECT;
"="								column += yyleng; return OP_EQ;
">="							column += yyleng; return OP_GTE;
">"								column += yyleng; return OP_GT;
"<="							column += yyleng; return OP_LTE;
"<"								column += yyleng; return OP_LT;
"-"								column += yyleng; return OP_SUB;
"<>"							column += yyleng; return OP_NEQ;
"+"								column += yyleng; return OP_ADD;
"/"								column += yyleng; return OP_SLASH;
"*"								column += yyleng; return OP_MUL;
"**"							column += yyleng; return OP_EXP;

{T}{R}{U}{E}					column += yyleng; yylval.valbooleen = TRUE; return TOK_BOOLEAN;
{F}{A}{L}{S}{E}					column += yyleng; yylval.valbooleen = FALSE; return TOK_BOOLEAN;
[a-zA-Z]([a-zA-Z0-9])*			column += yyleng; yylval.ident = ajouterIdentificateur(yytext); return TOK_IDENT;
'({NQUOTE}|'')+'				column += yyleng; if ( yyleng == 1 ){yylval.valcar = yytext[0]; return TOK_CHAR;} else{ yylval.valchaine = (char *)malloc(yyleng); strcpy(yylval.valchaine, yytext); return TOK_STRING;}
-?{CHIFFRES}					column += yyleng; yylval.valentier = atoi(yytext); return TOK_INTEGER;
-?{CHIFFRES}"."{CHIFFRES}		column += yyleng; yylval.valreel = atoi(yytext); return TOK_REAL;

":"								column += yyleng; return SEP_DOTS;
";"								column += yyleng; return SEP_SCOL;
","								column += yyleng; return SEP_COMMA;
"."								column += yyleng; return SEP_DOT;
".."							column += yyleng; return SEP_DOTDOT;
"["								column += yyleng; return SEP_CO;
"]"								column += yyleng; return SEP_CF;
"("								column += yyleng; return SEP_PO;
")"								column += yyleng; return SEP_PF;

"(*"   |
"{"								{
									register int c;
									while ((c = yyinput()))
									{
										column ++;
										if (c == '}')
											break;
										else if (c == '*')
										{
											if ((c = yyinput()) == ')')
											break;
											else
											unput (c);
										}
										else if (c == '\n')
										{
											row ++;
											column = 1;
										}
										else if (c == 0)
											commenteof ();
									}
								}

[ \t\f]							column ++;

[ \n\r]							row++; column = 1;

.								{
									fprintf (stderr, "'%c' (0%o): illegal charcter at line %d, column %d\n", yytext[0], yytext[0], row, column );
								}

%%

int row = 1, column = 1;

int
yyerror ( char* m )
{
	fprintf ( stderr, "Erreur (%d,%d) [%s] : %s\n", row, column, yytext, m );
	return 1;
}

void
commenteof ()
{
	fprintf (stderr, "unexpected EOF inside comment at line %d, column %d\n", row, column );
	exit (1);
}
