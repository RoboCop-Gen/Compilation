#ifndef PILE_H
#define PILE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct pile{
    int elem;
    struct pile *suivant;

}pile;
/*empile element*/
pile *empile(pile *p, int elem);

/*depile element*/
pile *depile(pile *p);

/*dernier element de la pile*/
int h_pile(pile *p);

/*n-ième element de la pile*/
int n_pile(pile *p, int n);

/*premier element de la pile*/
int s_pile(pile *p);

/*existence de la valeur*/
int exist_p(pile *p, int val);

/*affichage de la pile*/
void affiche_p(pile *p);

#endif