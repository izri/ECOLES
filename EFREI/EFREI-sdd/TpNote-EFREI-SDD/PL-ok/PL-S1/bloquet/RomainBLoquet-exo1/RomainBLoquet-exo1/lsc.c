#include <stdlib.h>
#include <stdio.h>
#include "lsc.h"

Lsc creaNode () // creation du noeud
{
    Lsc boite;
    boite = NULL;
    boite = (Lsc)malloc(sizeof(node));


    do
    {
        printf ("Entrer un nombre :\n");
        fflush(stdin);
    }
    while ((scanf("%d",&boite->val)==0));
    boite->succ = NULL;
    return boite;
}

Lsc premierElt (Lsc *liste) // creation du premier element
{
    Lsc p;
    p = creaNode ();
    *liste = p;
    return p;
}

void creaLsc (Lsc *liste) // creation de la liste
{
    int nbcase;
    int cpt = 0;
    do
    {
        printf ("entrez le nombre de case de votre liste :\n");
        fflush(stdin);
    }
    while ((scanf("%d",&nbcase)==0));

    Lsc t,p;
    t = premierElt (liste);
    cpt++;

    while (cpt < nbcase)
    {
        p = creaNode ();
        t->succ = p;
        t=p;
        cpt ++;
    }
}

int taiLsc (Lsc liste) // calcule de la taille de la liste
{
    int cpt = 0;
    if (liste != NULL)
    {
        cpt ++;
        while (liste->succ != NULL)
        {
            liste=liste->succ;
            cpt ++;
        }
        return cpt;
    }
    else
    {
        return cpt;
    }
}

void affichLsc (Lsc liste) // afficher la liste
{
    if (liste == NULL)
    {
        printf ("La liste est vide\n");
    }
    else
    {
        while (liste!=NULL)
        {
            printf ("%d\t",liste->val);
            liste = liste->succ;
        }
    }
}

void affichePremier (Lsc liste) // afficher les nombre premiers
{
    {
        if (liste == NULL)
        {
            printf ("La liste est vide\n");
        }
        else
        {
            while (liste!=NULL)
            {
                if ((liste->val)%2 != 0 || (liste->val)== 2 )
                {

                    {
                        printf ("%d\t",liste->val);
                    }

                }

                liste = liste->succ;
            }
        }
    }

}

void creaLsc2 (Lsc *liste, int nbcase) // creation de la liste avec un nombre de case definit alla de l'entier 2 a N
{

    int cpt = 0;

    Lsc t,p;
    t = premierElt2 (liste);
    t->val=2;
    cpt++;

    while (cpt < nbcase)
    {
        p = creaNode2 ();
        p->val = (t->val)+1;
        t->succ = p;
        t=p;
        cpt ++;
    }
}

Lsc creaNode2 () // creation du noeud
{
    Lsc boite;
    boite = NULL;
    boite = (Lsc)malloc(sizeof(node));
    boite->val = 0;
    boite->succ = NULL;
    return boite;
}

Lsc premierElt2 (Lsc *liste) // creatiuon du premier element
{
    Lsc p;
    p = creaNode2 ();
    *liste = p;
    return p;

}
