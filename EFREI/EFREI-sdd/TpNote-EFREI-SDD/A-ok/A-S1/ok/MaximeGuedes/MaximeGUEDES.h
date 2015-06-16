#ifndef MAXIMEGUEDES_H_INCLUDED
#define MAXIMEGUEDES_H_INCLUDED

//EXERCICE 1
typedef struct liste
{
    int nombre;
    struct liste* succ;
} Liste_chainee;


//Crée une liste chainée avec les nombres de 2 au nombre spécifié en paramètre
Liste_chainee* LSC_RemplissageListe (int);

//élimine tous les maillons d'une chaine qui ne sont pas des nombre premiers
Liste_chainee* LSC_NombrePremier (Liste_chainee*);

//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

//EXERCICE 2

typedef struct arbre_binaire
{
    int nombre;
    struct arbre_binaire* sag;
    struct arbre_binaire* sad;
}Arbre;

//crée l'arbre parfait contenant la liste des éléments rentrée en paramètre
Arbre* ABR_CreationArbre (int*);

#endif // MAXIMEGUEDES_H_INCLUDED
