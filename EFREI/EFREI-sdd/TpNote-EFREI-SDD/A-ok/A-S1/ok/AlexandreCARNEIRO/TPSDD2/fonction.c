#include "fonction.h"

LSCc premierElt(LSCc *lst)
{
    LSCc l;
    l = creationCellule(2);
    *lst = l;
    return l;
}

void construireliste(LSCc *lst,int n)
{
    LSCc p,l;
    int i,j = 2;
    p = premierElt(lst);
    for(i = 0; i<n-1; i++)
    {
        j++;
        l = creationCellule(j);
        p->suivant = l;
        p=l;
    }
}

LSCc creationCellule(int n)
{
    LSCc p;
    p = (LSCc) malloc(sizeof(maillon));
    p->data = n;
    p->suivant = NULL;
    return p;
}

arbre nouveau_singleton(unsigned data)
{
    arbre nouv = (arbre) malloc(sizeof(abrenoeud));
    nouv->data = data;
    nouv->sag = NULL;
    nouv->sad = NULL;

    printf("Nouveau noeud\n");
    return nouv;
}


arbre nouveau_arbre(LSCc lst, unsigned b)
{
    arbre a;
    a = nouveau_singleton(b);
    if(lst->suivant->suivant != NULL)
    {
        a->sag = nouveau_arbre(lst->suivant,lst->suivant->data);
        a->sad = nouveau_arbre(lst->suivant->suivant,lst->suivant->suivant->data);
    }
    if(lst->suivant->suivant == NULL)
    {
        if(lst->suivant != NULL)
        {
            a->sag = nouveau_arbre(lst->suivant,lst->suivant->data);
        }
    }
    return a;
}
