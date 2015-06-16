#include<stdio.h>
#include<stdlib.h>

/* On définit la structure */

typedef struct Element {
    int info;
    struct Element* next;
} Element;

typedef Element* Liste;

/*
 * Fonction initialisation
 * Initialise la liste est créer des éléments de 2 jusqu'a n en entree du programme
 */
Liste initialisation(int n) {

    Liste liste = malloc(sizeof(*liste));

    liste->next = liste;
    liste->info = 2;

    Liste element = liste;
    Liste temp = NULL;

    int i;

    for(i=3;i<=n;i++) {
        temp = malloc(sizeof(*temp));

        temp-> next = liste;
        temp -> info = i;

        element->next = temp;
        element = temp;
    }

    return liste;
}

/*
 * Fonction affiche
 * Affiche tous les éléments de la liste
 */
void affiche(Liste l) {
    if(l!=NULL) {

        Liste mem = l;

        printf("La liste : \n");

        do {
            printf("%d -> ", l->info);
            l = l->next;
        } while(l != mem);

        printf("\n");
    }
}

/*
 * Fonction affichePetit
 * Affiche les elements de la liste qui sont inférieurs ou egaux a 150.
 */
void affichePetit(Liste l) {
    if(l!=NULL) {

        Liste mem = l;

        printf("La liste au cube plus petit que 150 : \n");

        do {
            printf("%d -> ", l->info);
            l = l->next;
        } while(l != mem && l->info <= 150);

        printf("\n");
    }
}

/*
 * Fonction cube
 * Change tous les elements de la liste avec sa valeur au cube
 */
void cube(Liste *l) {
    if(l!=NULL) {
        Liste element = *l;

        do {
            element->info = (element->info)*(element->info)*(element->info); // On met la valeur au cube
            element = element->next;
        } while(element != *l);
    }
}

/* Programme principal */

int main() {

    int entree;

    do {
        printf("Entrez un entier >2 : ");
        if(scanf("%d", &entree)!=1) {        // On demande d'entrer un nombre >2 pour la taille de la liste
            printf("Input error\n");
            exit(-1);
        }
    } while(entree <= 2);

    Liste liste = NULL;
    liste = initialisation(entree);          // On initialise la liste

    affiche(liste);                          // On affiche tous les elements

    cube(&liste);                             // On met les valeurs au cube

    affichePetit(liste);                     // On affiche les elements plus petit que 150

    return 0;
}
