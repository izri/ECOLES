#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct maillon
{    int nombre;
   struct maillon *succ;
}maillon;

typedef struct maillon* liste;/// on initialise la liste

liste creation_cellule_et_liste(int);/// on construit la liste et ses maillons (il y aura le nombre de maillons demandés par l'utilisateur)

liste premier_elt();/// si la liste est vide on l'initialise

void affiche_liste(liste);/// affichage de la liste

void fonction_compare_result(int);///resultat attendu








#endif // FONCTIONS_H_INCLUDED

