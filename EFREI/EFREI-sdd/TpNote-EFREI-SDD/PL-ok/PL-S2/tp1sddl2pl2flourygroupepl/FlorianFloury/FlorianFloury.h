#ifndef TP2_H_INCLUDED
#define TP2_H_INCLUDED
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
typedef struct Elem{
    int numero;
    struct Elem* suivant;
    }Elem;

typedef struct Elem* element;


/////////////FONCTIONS////////////

element creaCellule(int cpt);
element premierElt(element *lst, int cpt);
void construireListe (element *lst ,int nb);
void Afficher(element liste);

#endif // TP2_H_INCLUDED
