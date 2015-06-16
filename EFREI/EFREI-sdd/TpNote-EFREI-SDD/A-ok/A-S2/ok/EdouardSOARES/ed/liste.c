
#include <stdio.h>
#include <stdlib.h>

#include "liste.h"

Liste *initialiser() {

    Liste *nouveau = malloc(sizeof(*nouveau));

    nouveau->premier = NULL;
    nouveau->dernier = NULL;

    return nouveau;

}

void insererElement(Liste *liste, int nombre, int testParfait) {



    if (testParfait == 1) { // On teste si on veut afficher les nombres parfaits ou non

            int a;
            a = testNombreParfait(nombre);

            if (a == 1) {

                Element *compteur = liste->premier;
                Element *nouveau = malloc(sizeof(*nouveau));  // On alloue la mémoire au nouvel element

                nouveau->nombre = nombre;


                if (compteur == NULL) { // si la liste est vide on insere l'element au debut

                    nouveau->suivant = NULL;
                    liste->premier = nouveau;
                    liste->dernier = nouveau;
                }

                else {   //si la liste n'est pas vide on l'insere à la fin

                    compteur = liste->dernier;
                    compteur->suivant = nouveau;
                    nouveau->suivant = NULL;
                    liste->dernier = nouveau;
                }
            }

    }

    else {

            Element *compteur = liste->premier;
            Element *nouveau = malloc(sizeof(*nouveau));

            nouveau->nombre = nombre;


            if (compteur == NULL) { // si la liste est vide on insere l'element au debut

                nouveau->suivant = NULL;
                liste->premier = nouveau;
                liste->dernier = nouveau;
            }

            else {   //si la liste n'est pas vide on l'insere à la fin

                compteur = liste->dernier;
                compteur->suivant = nouveau;
                nouveau->suivant = NULL;
                liste->dernier = nouveau;
            }
    }
}

void afficherListe(Liste *liste) {



        Element *actuel = liste->premier;

        while (actuel != NULL) {

            printf("%d\n", actuel->nombre);

            actuel = actuel->suivant;
        }


}

int testNombreParfait(int nombre) {

    int a = 0;
    int i;
    int z = 0;
    int tab[100];



         for (i = nombre-1 ; i>0 ; i--) {

            a = nombre % i;

            if (a == 0) {
                tab[z] = i;
                z++;
            }
        }
        a = 0;
        for (i = 0 ; i < z ; i++) {

            a += tab[i];
        }

        if (a == nombre) {
            return 1;
        }

        else {
            return 0;
        }


}
