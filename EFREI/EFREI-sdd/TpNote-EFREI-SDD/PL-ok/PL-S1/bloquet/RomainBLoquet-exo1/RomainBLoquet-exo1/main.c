#include <stdio.h>
#include <stdlib.h>
#include "lsc.h"
int main()
{
      /*  Lsc liste;
        //creaLsc(&liste);
        creaLsc(&liste,19); //creation de la liste de la taille et des valeurs voulues pas l'utilisateur
        affichLsc(liste);
        printf ("\n");
        affichePremier(liste);*/

        Lsc liste2;
        creaLsc2(&liste2,15); // creation de la liste d'entier de 2 a N;
        affichLsc(liste2);
        printf ("\n");
        affichePremier(liste2);// afficher les nombres premiers

}
