#ifndef ARBRE
#define ARBRE

#include<stdlib.h>
#include<stdio.h>
#include<string>

// les cste, comme dans le cours
#define A_CSTE_E 1
#define A_CSTE_R 2
#define A_CSTE_C 3
#define A_CSTE_CC 4
#define A_BOOL 5

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