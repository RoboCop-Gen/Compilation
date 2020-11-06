#include "pile.h"

pile *empile(pile *p, int elem){
    pile *n_p = NULL;
    n_p = (pile *)malloc(sizeof(pile));
    if(n_p == NULL){
        fprintf(stderr, "Erreur d'allocation mémoire pour la pile\n");
        exit(-1);
    }
    n_p->elem = elem;
    n_p->suivant = p;
    return(n_p);
}// fin empile

pile *depile(pile *p){
    pile *tmp = p;
    if(p == NULL){
        fprintf(stderr, "La pile est déjà vide\n");
        exit(-1);
    }
    p = p->suivant;
    // déallocation de la memoire
    free(tmp);
    return(p);
}// fin depile

int h_pile(pile *p){
    if(p == NULL){
        fprintf(stderr, "La pile est vide, on ne peut pas depiler\n");
        exit(-1);
    }
    // si non vide
    return(p->elem);
}// fin h_pile

int nieme_p(pile *p, int n){
    int i;
    pile *tmp = p;
    for(i=1; i<n; i++){
        // on cherche le n-ième element
        if(tmp->suivant == NULL && i<n){
            fprintf(stderr, "l'element %d de la pile n'existe pas\n", n);
        }
        tmp = tmp->suivant;
    }
    // si on trouve l'element
    return(tmp->elem);
}// fin nieme_p

int s_pile(pile *p){
    int size = 0;
    pile *tmp = p;
    while(tmp != NULL){
        size++;
        tmp = tmp->suivant;
    }// fin while
    return (size);
}// fin s_pile

int exist_p(pile *p, int val){
    pile *tmp = p;
    while(tmp != NULL){
        if(tmp->elem == val)
        return val;
    }// fin while
    return 0;
}// fin exist_p

void affiche_p(pile *p){
    pile *tmp = p;
    while(tmp != NULL){
        fprintf(stdout, "%d ->", tmp->elem);
        tmp = tmp->suivant;
    }// fin while
    // et si NULL
    fprintf(stdout, "PILE VIDE\n");
}