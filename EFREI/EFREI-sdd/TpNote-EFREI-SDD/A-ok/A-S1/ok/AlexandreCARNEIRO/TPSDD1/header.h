#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct maillon
{
    int data;
    struct maillon *suivant;

} maillon;

typedef struct maillon *LSCc;

LSCc premierElt(LSCc *lst);
void construireliste(LSCc *lst,int n);
LSCc creationCellule(int n);
void afficher(LSCc lst);
void estpremier(LSCc lst);

#endif // HEADER_H_INCLUDED
