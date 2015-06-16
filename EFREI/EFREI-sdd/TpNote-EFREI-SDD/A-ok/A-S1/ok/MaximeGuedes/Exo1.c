#include <stdio.h>
#include <stdlib.h>


#include "MaximeGUEDES.h"

Liste_chainee* LSC_RemplissageListe (int nombre)
{
    //variable compteur
    int i;
    //variable contenant le tableau d'étude
    Liste_chainee* liste;
    //variable de navigation dans le tableau
    Liste_chainee* courant;

    //initialisation des variables

    liste = (Liste_chainee*)malloc(sizeof(Liste_chainee));
    liste->nombre = 2;
    liste->succ = NULL;
    courant = liste;

    //creation de la liste chainée avec les nombres de 2 à nombre
    for (i=3; i<=nombre; i++)
    {
        courant->succ = (Liste_chainee*) malloc(sizeof (Liste_chainee));
        courant = courant->succ;
        courant->nombre = i;
        courant->succ = NULL;
    }

    //remise de courant en tête de liste
    courant = liste;

    //affichage de la liste
    printf ("Liste avant:\n");
    while (courant != NULL)
    {
        printf("nombre %d\n", courant->nombre);
        courant = courant->succ;
    }

    //suppression des nombre non-premiers de la liste
    liste = LSC_NombrePremier (liste);

    //remise de courant en tête de liste
    courant = liste;

    //affichagede la liste ne contenant désormais que des nombres premmiers
    printf ("Liste apres:\n");
     while (courant != NULL)
    {
        printf("nombre %d\n", courant->nombre);
        courant = courant->succ;
    }
    while (courant != NULL)
    {
        printf("nombre %d\n", courant->nombre);
        courant = courant->succ;
    }

    //passage de la liste chainée ainsi triée
    return liste;
}

Liste_chainee* LSC_NombrePremier (Liste_chainee* liste)
{
    Liste_chainee* courant;
    Liste_chainee* precedant;
    Liste_chainee* suppression;
    int parcours;
    int compteur;

    courant = liste;
    precedant = liste;

    //parcours de la liste jusqu'à la fin
    while (courant != NULL)
    {
        compteur = 0;

        //test de la divisibilité de tous les nombres de 1 à courant->nombre
        for (parcours=1; parcours<=courant->nombre; parcours++)
        {
            if (courant->nombre % parcours == 0)
            {
                compteur++;
            }
        }

        //si le nombre de diviseur est différent de 2, le nombre n'est pas premier et on le supprime
        if (compteur !=2)
        {
            suppression = courant;
            courant = courant->succ;
            precedant->succ = suppression->succ;
            free(suppression);
        }
        //par contre, si le nombre est premier, on passe au maillon suivant
        else if (compteur == 2)
        {
            precedant = courant;
            courant = courant->succ;
        }
    }

    //on retourne la liste triée
    return liste;
}

