/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_SRC_PARSER_H_INCLUDED
# define YY_YY_SRC_PARSER_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     KW_PROGRAM = 258,
     KW_CONST = 259,
     KW_TYPE = 260,
     KW_VAR = 261,
     KW_ARRAY = 262,
     KW_OF = 263,
     KW_RECORD = 264,
     KW_BEGIN = 265,
     KW_END = 266,
     KW_DIV = 267,
     KW_MOD = 268,
     KW_AND = 269,
     KW_OR = 270,
     KW_XOR = 271,
     KW_NOT = 272,
     KW_IF = 273,
     KW_THEN = 274,
     KW_ELSE = 275,
     KW_WHILE = 276,
     KW_DO = 277,
     KW_REPEAT = 278,
     KW_UNTIL = 279,
     KW_FOR = 280,
     KW_TO = 281,
     KW_DOWNTO = 282,
     KW_PROC = 283,
     KW_FUNC = 284,
     KW_INTEGER = 285,
     KW_REAL = 286,
     KW_BOOLEAN = 287,
     KW_CHAR = 288,
     KW_STRING = 289,
     KW_WRITE = 290,
     KW_WRITELN = 291,
     KW_READ = 292,
     SEP_SCOL = 293,
     SEP_DOT = 294,
     SEP_DOTS = 295,
     SEP_DOTDOT = 296,
     SEP_COMMA = 297,
     SEP_CO = 298,
     SEP_CF = 299,
     SEP_PO = 300,
     SEP_PF = 301,
     OP_EQ = 302,
     OP_NEQ = 303,
     OP_LT = 304,
     OP_LTE = 305,
     OP_GT = 306,
     OP_GTE = 307,
     OP_ADD = 308,
     OP_SUB = 309,
     OP_MUL = 310,
     OP_SLASH = 311,
     OP_EXP = 312,
     OP_AFFECT = 313,
     TOK_IDENT = 314,
     TOK_INTEGER = 315,
     TOK_REAL = 316,
     TOK_BOOLEAN = 317,
     TOK_CHAR = 318,
     TOK_STRING = 319,
     OP_POS = 320,
     OP_NEG = 321,
     OP_PTR = 322,
     OP_DOT = 323,
     KW_IFX = 324
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 14 "src/parser.y"

	int ident;		/* Numéro de l'identificateur*/
	int valentier;
	double valreel;
	int valbooleen;
	char valcar;
	char* valchaine;
	int nb_arg;		/* Nombre d'argument d'une fonction*/
	char* type;		// chaine de caractère pour faire remonter les types lors de l'analyse


/* Line 2058 of yacc.c  */
#line 138 "src/parser.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_SRC_PARSER_H_INCLUDED  */
