#include <stdio.h>
#include <stdlib.h>

typedef struct nombre
{
    struct nombre *next;
    int valeur;
}nombre;

void creer_liste_entiers(nombre **liste, int n);
void afficherliste(nombre **liste);
void nombreparfait(nombre **liste);


int main()
{
    nombre *liste=NULL, *liste2=NULL;
    int n=501;

    creer_liste_entiers(&liste, n);
    afficherliste(&liste);
    nombreparfait(&liste);


    return 0;
}



void creer_liste_entiers(nombre **liste, int n) //fonction qui crée la liste
{
    int cpt;
    nombre *m=NULL;

    *liste = (nombre*)malloc(sizeof(nombre));
    m = *liste;

    for(cpt=1; cpt<n+1; cpt++)
    {
        m->next = (nombre*)malloc(sizeof(nombre));
        m = m->next;
        m->valeur = cpt;
    }
    m -> next = NULL;
}

void afficherliste(nombre **liste) //fonction qui affiche la liste
{
        nombre *m ;
        m = *liste;

       while (m -> next != NULL)
    {
        printf("%d\n", m -> valeur);
        m = m -> next;

    }
}


void nombreparfait(nombre **liste) //fonction qui affiche les nombres parfaits
{

        nombre *m, *temp ;
        m = *liste;
        int cpt;
        int diviseur;

        while (m->next != NULL)
        {
            cpt=1;
            diviseur=0;

            while (cpt < m->valeur) //on calcule la somme des diviseurs du chiffre
            {
                if (m->valeur%cpt == 0)
                {
                    diviseur= diviseur + cpt;
                }

                cpt=cpt+1;
            };

            if (diviseur == m->valeur) // on regarde si la somme des diviseurs est égale au chiffre
            {
              printf("le nombre %d est un nombre parfait\n", m->valeur);
            }

                temp=m;
                m=m->next;

        }

}
