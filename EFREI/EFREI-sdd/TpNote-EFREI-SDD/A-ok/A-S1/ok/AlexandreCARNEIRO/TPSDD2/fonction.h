#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
// liste chainée pour les nombres
typedef struct maillon
{
    int data;
    struct maillon *suivant;

} maillon;

typedef struct maillon *LSCc;

LSCc premierElt(LSCc *lst);
void construireliste(LSCc *lst,int n);
LSCc creationCellule(int n);

//fonction pour les arbres
typedef struct abrenoeud {
    unsigned data;
    struct abrenoeud *sag, *sad;
} abrenoeud;

typedef abrenoeud *arbre;

arbre nouveau_singleton(unsigned data);

#endif // FONCTION_H_INCLUDED
