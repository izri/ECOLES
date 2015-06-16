#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/** ------ Nécessaire à l'exercice 1 ------**/

typedef struct Element Element;
struct Element
{
    int nombre;
    Element *suivant;
};

typedef struct Liste Liste;
struct Liste
{
    Element *premier;
};

Liste *initialisation()
{
    Liste *liste = malloc(sizeof(*liste));
    Element *element = malloc(sizeof(*element));

    if (liste == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    element->nombre = 0;
    element->suivant = NULL;
    liste->premier = element;

    return liste;
}

void insertion(Liste *liste, int nvNombre)
{
    /* Création du nouvel élément */
    Element *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->nombre = nvNombre;
    /* Insertion de l'élément au début de la liste */
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}

void suppression(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (liste->premier != NULL)
    {
        Element *aSupprimer = liste->premier;
        liste->premier = liste->premier->suivant;
        free(aSupprimer);
    }
}


void afficherListe(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actuel = liste->premier;

    while (actuel != NULL)
    {
        printf("%d ", actuel->nombre);
        actuel = actuel->suivant;
    }
}

int NombrePremier (int nombre)
{
    int i, nb, test,limite;
    test = 0;

    limite = sqrt(nombre) + 1;

    if (nb % 2 == 0)
    {
        test = 1;
    }
    else
    {
        for (i = 3 ; i < limite && (test == 0); i+=2)
        {
            if (nb % i == 0)
            {
                test = 1;
            }
        }
    }
    if (test == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void exercice1 ()
{
    int i, a;
    a = 0;

    Liste *maliste = initialisation();
    Liste *maliste1 = initialisation();

    printf("Liste des nombres de 1 a 150:\n");
    for (i=15; i>0; i--)
    {
        insertion(maliste, i);
    }
    afficherListe (maliste);
    suppression (maliste);

    printf("\n\n\n");

    printf("Liste des nombres premiers de 1 a 150:\n");
    for (i=150; i>2; i--)
    {
        if (NombrePremier (i) == 1)
        {
            insertion(maliste1, i);
        }
    }
    afficherListe(maliste1);
    suppression(maliste1);
}


/** ------ Nécessaire à l'exercice 2 ------**/

typedef struct noeud
{
    unsigned int info;
    struct noeud *gauche;
    struct noeud *droit;
} noeud ;

noeud *creer (int info_r)
{
    noeud *elem = (noeud *) malloc(sizeof(noeud));
    elem->info = info_r;
    elem->gauche = NULL;
    elem->droit = NULL;
    return (elem);
}

void Ajout_noeud(noeud *node, int info_g, int info_d)
{
    node->gauche = (noeud*) malloc(sizeof(noeud));
    node->gauche->info = info_g;
    node->gauche->gauche = NULL;
    node->gauche->droit = NULL;
    node->droit = (noeud*) malloc(sizeof(noeud));
    node->droit->info = info_d;
    node->droit->gauche = NULL;
    node->droit->droit = NULL;
}

void Lister (noeud *racine)
{
    if (racine != NULL)
    {
        printf("Valeur ==> %d \n", racine->info);
        Lister (racine->gauche);
        Lister (racine->droit);
    }
}

void exercice2 ()
{
    noeud *arbre;
    arbre = creer (0);
    Ajout_noeud(arbre, 1, 4);
    Ajout_noeud(arbre->gauche, 2, 3);
    Ajout_noeud(arbre->droit, 5, 6);
    Lister(arbre);

}


/** ------ Main ------**/

int Choix ()
{
    int ch;
    ch = 0;



    return ch;
}

int main()
{
    int choix;
    choix = 0;

    do
    {
        do
        {
            printf("\n\nQuel exercice voulez vous ? \n");
            printf("1 : Exercice 1\n");
            printf("2 : Exercice 2\n");
            printf("3 : Quitter\n");
            scanf("%d", &choix);
            printf("\n\n");
        } while ((choix < 1) || (choix >3));

        switch (choix)
        {
        case 1:
            exercice1();
            break;
        case 2:
            exercice2();
            break;
        case 3:
            return 0;
        }
    }while (choix != 3);


    return 0;
}

