#include <stdio.h>
#include <stdlib.h>
///-------------------------------------------------------------------------Debut exo 1
///PROTOTYPES

typedef struct cellule {
    int info;
    struct cellule *suivant;
} cellule;

void affichage(cellule *);
cellule * creationListe(int);
int estPremier(int);
void garderPremiers(cellule *);

///FONCTIONS LST

void garderPremiers(cellule *lst)
{
    cellule *tmp = NULL;

    while(lst->suivant != NULL)
    {///On ne verifie pas le premier element car il sera forcement 2 et donc premier !
        if(estPremier(lst->suivant->info) == 0)  ///Nombre non premier : on supprime
        {
           tmp = lst->suivant;
           lst->suivant = tmp->suivant;
           tmp->suivant = NULL;
           free(tmp);
        }
        else    lst = lst->suivant;
    }
}

int estPremier(int x)
{
    int diviseur;

    for(diviseur = 2; diviseur < x; diviseur++)     ///Si le nombre est divisble par un nombre qui lui est inferieur (hormis 1)
    {                                               ///Il n'est pas premier
        if(x%diviseur == 0) return 0;
    }
    return 1;
}

cellule * creationListe(int N)
{
    int cpt;
    cellule *lst = NULL, *tmp = NULL;

    lst = (cellule*)malloc(sizeof(cellule));        ///Premier element
    lst->info = 2;
    lst->suivant = NULL;

    tmp = lst;                                      ///Autres elements
    for(cpt = 3; cpt <= N; cpt++)
    {
        tmp->suivant = (cellule*)malloc(sizeof(cellule));
        tmp = tmp->suivant;
        tmp->info = cpt;
    }
    tmp->suivant = NULL;
    return lst;
}

void affichage(cellule *lst)
{
        while(lst != NULL) {            ///On parcourt la liste
        printf("%d ", lst->info);
        lst = lst->suivant;
    }
}

///------------------------------------------------------------------------- Fin exo 1







///-------------------------------------------------------------------------Debut exo 2

///PROROTYPES
typedef struct noeud
{
    int info;
    struct noeud *sag, *sad;
}noeud;

typedef struct file
{
    cellule *tete, *queue;
}file;

cellule * garderParfaits(cellule *);
int estParfait(int);
///FONCTIONS
int estParfait(int x)
{
    int diviseur, total = 0;

    for(diviseur = 1; diviseur < x; diviseur++)
    {
        if(x%diviseur == 0)         ///Si le nombre est un diviseur de x
        {
            total = total + diviseur;
        }
    }
    if(total == x)   return 1;
    return 0;
}


cellule * garderParfaits(cellule *lst)
{
    cellule *tmp = NULL, *debut = NULL;

    while(estParfait(lst->info) == 0)          ///Premier cas
    {
        tmp = lst;
        lst = tmp->suivant;
        free(tmp);
    }
    debut = lst;
    lst = debut;

    while(lst->suivant != NULL)
    {
        if(estParfait(lst->suivant->info) == 0) ///Non parfait , on supprime
        {
            tmp = lst->suivant;
            lst->suivant = tmp->suivant;
            tmp->suivant = NULL;
            free(tmp);
        }
        else lst = lst->suivant;
    }
    return debut;
}


///-------------------------------------------------------------------------Fin exo 2



///MAIN

int main()
{
    cellule *lst = NULL;
    file f;

    lst = creationListe(150);
    printf("Exercice 1\n\n\nListe : ");
    affichage(lst);
    printf("\n-------------------------------------------------------------");
    garderPremiers(lst);
    printf("\nListe des nombres premiers : ");
    affichage(lst);
    printf("\n\n\nEXERCICE 2\n\n\n");
    f.tete = creationListe(150);              ///Creation de la liste
    f.tete = garderParfaits(f.tete);         ///La liste est parfaite
    f.queue = f.tete;
    while(f.queue->suivant != NULL)    {     ///On positione la fin de liste
        f.queue = f.queue->suivant;
    }
    printf("Liste des nombres parfaits : ");
    affichage(f.tete);
    printf("\n\n\nJe n'ai pas eu le temps de creer les fonctionnalités pour transferer la liste dans l'arbre");

    return 0;
}

