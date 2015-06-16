#ifndef LISTE_CHAINE_H_INCLUDED
#define LISTE_CHAINE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>


typedef struct maillon
{

    int valeur;
    struct maillon* precedent;
    struct maillon* suivant;

}maillon;

typedef struct liste
{
    maillon* tete;
    maillon* queu;
}liste;





//exercice 1
liste* liste_nombre_premier1(int n);
liste* liste_nombre_premier2(int n);//bugger mais la fonction liste_nombre_premier1 marche est est plus performente
liste* ajouter_un_maillon(liste* chaine,int valeur);
liste* supprimer_un_maillon(liste* chaine,maillon* maillon);
int test_premier(liste *,int);
liste* creation_liste();

//exercice 2





#endif // LISTE_CHAINE_H_INCLUDED
