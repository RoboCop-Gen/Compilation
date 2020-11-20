/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_BISON_TAB_H_INCLUDED
# define YY_YY_BISON_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PROG = 258,
    PLUS = 259,
    MOINS = 260,
    MULT = 261,
    DIV = 262,
    MOD = 263,
    SUP = 264,
    SUP_EGL = 265,
    INF = 266,
    INF_EGL = 267,
    EGAL = 268,
    DIFF = 269,
    OPAFF = 270,
    NOT = 271,
    VIRGULE = 272,
    POINT = 273,
    POINT_VIRGULE = 274,
    DEUX_POINTS = 275,
    PARENTHESE_OUVRANTE = 276,
    PARENTHESE_FERMANTE = 277,
    CROCHET_OUVRANT = 278,
    CROCHET_FERMANT = 279,
    AND = 280,
    OR = 281,
    DE = 282,
    EST = 283,
    TYPE = 284,
    VARIABLE = 285,
    TABLEAU = 286,
    STRUCT = 287,
    FSTRUCT = 288,
    IDF = 289,
    ENTIER = 290,
    REEL = 291,
    CARACTERE = 292,
    BOOLEEN = 293,
    CSTE_ENTIERE = 294,
    CSTE_REELE = 295,
    CSTE_CARACTERE = 296,
    CSTE_CHAINE = 297,
    TRUE = 298,
    FALSE = 299,
    VIDE = 300,
    DEBUT = 301,
    FIN = 302,
    PROCEDURE = 303,
    FONCTION = 304,
    RETOURNE = 305,
    SI = 306,
    ALORS = 307,
    SINON = 308,
    TANT_QUE = 309,
    FAIRE = 310,
    FINSI = 311
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BISON_TAB_H_INCLUDED  */
