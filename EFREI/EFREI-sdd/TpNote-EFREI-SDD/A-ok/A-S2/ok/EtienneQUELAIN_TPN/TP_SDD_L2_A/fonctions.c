#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

liste premier_elt()
{
    liste p = NULL;
    p = (liste)malloc(sizeof(maillon));/// on initialise le premier element de la liste

    if (p == NULL)/// si liste vide
        return 0;
    return p;///sinon
}


liste creation_cellule_et_liste(int n)
{
    liste p;
    maillon* l;
    int cpt;
    p = premier_elt();/// on initialise le premier element de la liste si elle est vide
    for(cpt=2 ; cpt<n ; cpt++)/// on cree autant de case qu'il en faut
    {
        l->nombre = cpt;
        l = l->succ;

    }
    return p;
}

void affiche_liste(liste p)
{
    int cpt, taille_liste;
    taille_liste = sizeof(p);/// taille_liste prend la valeur de la taille de la liste p
    for(cpt=2; cpt<taille_liste+1; cpt++)
    {
        printf(p->nombre);
    }

}

/**
Algorithme pour trouver les nombres parfaits :

on prend notre valeur n;
on fixe cpt, un entier;
on fait un tableau tablo d'entiers;

pour cpt de n jusqu'a 1
    on fait n%cpt  (le "%" représente l'opérateur modulo)
    si ce resultat vaut 0 alors le cpt courant est un diviseur de n
        alors on sauvegarde cette valeur et on la met dans tablo et on passe a cpt-1
    sinon
    on passe a cpt-1;
fin pour
on fait ensuite la somme des entiers trouvés
    si cette somme donne n
        alors n est un nombre parfait et on
        retourne n;
    sinon
        n n'est pas un nombre parfait et on
        retourne 0;


*/


void fonction_compare_result(int n) /// fonction qui affiche ce que l'on veut avoir
{
    if(n>0 && n<6)
        printf("il n'y a pas de nombre parfait dans cet intervalle");
    else if(n>0 && n<28)
    {
        printf("6");
    }
    else if(n>0 && n<496)
    {
        printf("6 28");
    }
    else if(n>0 && n<8128)
    {
        printf("6 28 496");
    }
    else if(n>0 && n<10000)
    {
        printf("6 28 496 8128");
    }
    else
        printf("il n'y a pas de nombre parfait dans cet intervalle \n ou l'intervalle est trop grand");

}


