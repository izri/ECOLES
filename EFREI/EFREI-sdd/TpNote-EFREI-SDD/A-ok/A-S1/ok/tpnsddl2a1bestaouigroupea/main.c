#include <stdio.h>
#include <stdlib.h>

/** Exercice 1 **/

 typedef struct maillon
{
    int nombre;
    struct maillon *suivant;

} maillon;

void creationListe (maillon **liste, int n);
void listeNombrePremier (maillon **liste);
int determinationPremier (maillon **liste);


int main()
{
    maillon *liste=NULL, *l;

    creationListe(&liste, 150);
    listeNombrePremier (&liste);
    l = liste;

    printf("Nombres premiers:\n");

    while( l != NULL ) // Tant que la liste n'a pas été parcouru jusqu'à son dernier maillon
    {
        printf( "%d\n", l->nombre );
        l = l -> suivant;
    }

    return 0;
}


void creationListe(maillon **liste, int n)
{
    int cpt;
    maillon *l = NULL; // initialisation

    *liste = (maillon*)malloc(sizeof(maillon));
    l = *liste;
    l -> nombre = 2; // car liste chainée commenceant à 2 selon l'énoncé

    for(cpt=3; cpt<=n; cpt++)
    {
        l-> suivant = (maillon*) malloc (sizeof(maillon)); // allcoation des maillons de la liste
        l = l-> suivant;
        l -> nombre = cpt;
    }
    l -> suivant = NULL;
}

int determinationPremier (maillon **liste)
{
  maillon *l = NULL;
  int cpt, temp;
  temp = 0;

  for (cpt = 2; cpt < (l->nombre) ; cpt++) // à la rechcerhce des diviseurs
  {
        if (l->nombre % cpt == 0)
        {
            temp = 1;
        }
  if (!temp) return 1; // premier

  else return 0; // non premier
  }
}

void listeNombrePremier(maillon **liste)
{
    int test;
    maillon *l = NULL; // creation + initialisation
    maillon *temp = NULL; // idem

    l = *liste;

    if(l==NULL || l -> nombre !=2) // si le maillon est vide ou que la case ne contient pas un 2 (qui est representatif du debut de la liste)
    {
        printf("Liste qui commence par 2 !!!");
    }else

    {

        while(l != NULL) //on parcourt toute la liste
        {
            test = (determinationPremier(&l)); /// PROBLEME :(

            if (test = 0) //le nombre n'est pas premier, donc suppresion du maillon le contenant
            {
                temp -> suivant = l -> suivant;
            }
            temp = l;
            l = temp->suivant;

        }
    }
}

 /** Exercice 2 **/

 typedef struct noeud
{
    int nombre;
    struct noeud *sad;
    struct noeud *sag;
} noeud;



