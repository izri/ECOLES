#include <stdio.h>
#include <stdlib.h>


// Déclaration de la structure de la liste
typedef struct listeLSC {
    int valeur;
    struct listeLSC *suivant;
}listeLSC;


// Initialisation de la liste
void init_liste(listeLSC *liste, int dernier_int)
{
    int i=0;
    listeLSC *chainon;
    chainon->valeur = 2;
    for(i=0;i<dernier_int;i++)
    {
        ajouter_int(liste, chainon);
    }
}


// Ajout des entiers à la liste
void ajouter_int(listeLSC *liste, listeLSC *chainon)
{
    int valeur;
    valeur++;
    chainon=(listeLSC*) malloc(sizeof(listeLSC));
    chainon->valeur = valeur;
    chainon->suivant = liste;
    liste = chainon;
}


// Affichage de la liste des entiers
void afficher_liste(listeLSC *liste, int dernier_int)
{
    int i=0;
    for(i=0;i<dernier_int;i++)
    {
        printf("Entier de la liste: %d",liste->valeur);
    }
}


int main()
{
    // Initialisation
    int dernier_int=0;
    int i=0;
    printf("Choisissez un entier, svp : ");
    scanf("%d", &dernier_int); // Choix de la variable N
    listeLSC *liste;

    // Initialiser la file jusqu'à dernier_int (N)
   init_liste(&liste, dernier_int);
    // Afficher la liste
     afficher_liste(&liste, dernier_int);
    return 0;
}
