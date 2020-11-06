#ifndef ARBRE
#define ARBRE

#include<stdlib.h>
#include<stdio.h>
#include<string>

// il reste à ajouter les définitions de tous les tokens.

union element{
    int t_int;
    int t_bool;
    float t_float;
    char t_char;
    char *t_string;
};

typedef struct noeud{
    int code;
    int num_lex;
    int num_declaration;
    union elem e;
    struct noeud *fils;
    struct noeud *frere;
}noeud;

typedef noud *arbre;

#endif