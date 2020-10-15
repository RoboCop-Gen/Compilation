%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
int yyerror();
%}

%token PROG
%token PLUS MOINS MULT DIV MOD
%token SUP SUP_EGL INF INF_EGL EGAL DIFF OPAFF NOT
%token VIRGULE POINT POINT_VIRGULE DEUX_POINTS
%token PARENTHESE_OUVRANTE PARENTHESE_FERMANTE CROCHET_OUVRANT CROCHET_FERMANT
%token AND OR
%token DE EST
%token TYPE
%token VARIABLE TABLEAU STRUCT FSTRUCT
%token IDF ENTIER REEL CARACTERE BOOLEEN CSTE_ENTIERE
%token CSTE_REELE
%token CSTE_CARACTERE CSTE_CHAINE
%token TRUE FALSE VIDE
%token DEBUT FIN
%token PROCEDURE FONCTION RETOURNE
%token SI ALORS SINON TANT_QUE FAIRE

%%
programme : PROG corps;

corps : liste_declarations liste_instructions
      ;

liste_declarations : declaration POINT_VIRGULE liste_declarations
                   |
                   ;

liste_instructions : DEBUT suite_liste_inst FIN;

suite_liste_inst : instruction POINT_VIRGULE suite_liste_inst
                 |
                 ;

declaration : declaration_type
            | declaration_variable
            | declaration_procedure
            | declaration_fonction
            ;

declaration_type : TYPE IDF DEUX_POINTS EST suite_declaration_type;

suite_declaration_type : STRUCT liste_champs FSTRUCT
                       | TABLEAU dimension DE nom_type
                       ;

dimension : dimension une_dimension
          | une_dimension
          ;

une_dimension : CROCHET_OUVRANT CSTE_ENTIERE POINT POINT CSTE_ENTIERE CROCHET_FERMANT;

liste_champs : un_champ POINT_VIRGULE liste_champs
             | un_champ POINT_VIRGULE
             ;

un_champ :  IDF DEUX_POINTS nom_type;

nom_type : type_simple
         | IDF
         ;

type_simple : ENTIER
            | REEL
            | BOOLEEN
            | CARACTERE
            ;

declaration_variable : VARIABLE IDF DEUX_POINTS nom_type

declaration_procedure : PROCEDURE IDF liste_parametres EST corps;

declaration_fonction : FONCTION IDF liste_parametres RETOURNE type_simple corps

liste_parametres : PARENTHESE_OUVRANTE liste_param PARENTHESE_FERMANTE
                 | PARENTHESE_OUVRANTE PARENTHESE_FERMANTE
                 ;

liste_param : un_param POINT_VIRGULE liste_param
            | un_param
            ;

un_param : IDF DEUX_POINTS type_simple;

instruction : affectation
            | condition
            | tant_que
            | appel
            | VIDE
            | RETOURNE PARENTHESE_OUVRANTE resultat_retourne PARENTHESE_FERMANTE
            ;

resultat_retourne : expression
                  |
                  ;

appel : IDF liste_arguments ;

liste_arguments : PARENTHESE_OUVRANTE liste_args PARENTHESE_FERMANTE
                |
                ;

liste_args : liste_args VIRGULE un_arg
           | un_arg
           ;

un_arg : expression;

condition : SI expression_bool
            ALORS suite_liste_inst
            SINON suite_liste_inst;

tant_que : TANT_QUE expression_bool FAIRE liste_instructions;

affectation : variable OPAFF expression;

variable : IDF
         | IDF CROCHET_OUVRANT dimention_variable CROCHET_FERMANT
         | IDF POINT structure_variable
         ;

dimention_variable : dimention_variable VIRGULE expression_arithm
                   | expression_arithm
                   ;

structure_variable : structure_variable POINT IDF
                   |IDF
                   ;

expression : expression_bool
           | expression_arithm
           ;

expression_bool : expression_bool OR expression_bool1
                | expression_bool1
                ;

expression_bool1 : expression_bool1 AND expression_bool2
                 | expression_bool2
                 ;

expression_bool2 : NOT expression_bool3
                 | expression_bool3
                 ;

expression_bool3 : PARENTHESE_OUVRANTE expression_bool PARENTHESE_FERMANTE
                 | expression_comp
                 | TRUE
                 | FALSE
                 ;

expression_comp : expression_arithm SUP expression_arithm
                | expression_arithm SUP_EGL expression_arithm
                | expression_arithm INF expression_arithm
                | expression_arithm INF_EGL expression_arithm
                | expression_arithm EGAL expression_arithm
                | expression_arithm DIFF expression_arithm
                | expression_arithm EGAL TRUE
                | expression_arithm DIFF FALSE
                | TRUE EGAL expression_arithm
                | FALSE DIFF expression_arithm

                ;

expression_arithm : expression_arithm PLUS expression_arithm1
                  | expression_arithm MOINS expression_arithm1
                  | expression_arithm1
                  ;

expression_arithm1 : expression_arithm1 MULT expression_arithm2
                   | expression_arithm1 DIV expression_arithm2
                   | expression_arithm1 MOD expression_arithm2
                   | expression_arithm2
                   ;

expression_arithm2 : PARENTHESE_OUVRANTE expression_arithm PARENTHESE_FERMANTE
                   | variable
                   | CSTE_ENTIERE
                   | CSTE_REELE
                   | CSTE_CARACTERE
                   | CSTE_CHAINE
                   ;
%%