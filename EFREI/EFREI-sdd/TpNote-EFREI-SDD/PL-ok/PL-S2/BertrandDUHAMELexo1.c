#include <stdio.h>
#include <stdlib.h>

typedef struct LSC
{
    int Val;
    struct LSC *Next;
} LSC;

typedef LSC* LSCLSC;

LSCLSC CreationCellule(int cpt)
{
    LSCLSC Cellule = NULL;
    Cellule = (LSCLSC)malloc(sizeof(LSC));
    Cellule -> Val = cpt;
    Cellule -> Next = NULL;
    return Cellule;
}

LSCLSC PremierElement(LSCLSC *Liste)
{
    int cpt = 1;
    LSCLSC p;
    p = CreationCellule(cpt);
    *Liste = p;
    return p;
}

void ConstruireListe(LSCLSC *Liste,int nb)
{
    int cpt = 1;
    LSCLSC p, t;
    t = PremierElement(Liste);

    while( cpt < nb )
    {
        p = CreationCellule(cpt);
        p -> Next = t -> Next;
        t -> Next = p;
        cpt++;
    }
}

void Afficher(LSCLSC Liste)
{

    LSCLSC Element = Liste;
    Element = Element -> Next;
    if (Element == NULL) printf("Liste Vide \n");
    else
        while(Element != NULL)
        {
            printf("Valeur : %d  \n\n", Element -> Val);
            Element = Element -> Next;
        }
}

LSCLSC RecherchePremier(LSCLSC Liste) /* Ne marche pas */
{
    LSC *tmp=Liste;
    int i;
    int cpt=0, Reste, Valeur;

    tmp = tmp->Next;

    while(tmp != NULL)
    {
        for (i = 2; i <= tmp->Val-1; i++)
        {
            Valeur=tmp->Val;
            printf ("%d %d\n",Valeur,i);
            Reste = Valeur%i;
            if (Reste==0){cpt++;}
            printf ("%d %d %d %d\n",Valeur,i,Reste,cpt);  // Pour afficher toutes les données pour résoudre mon problèe sans succès
        }
        if (cpt==0 || Valeur!=1){printf ("%d est premier\n\n", tmp -> Val);}
        tmp = tmp->Next;
        cpt = 0;
    }
    return NULL;
}


int main()
{
    LSCLSC Liste;
    int nb;
    printf ("Saisir le nombre Valeurs\n");
    scanf("%d",&nb);
    nb++;

    ConstruireListe(&Liste,nb);
    Afficher(Liste);

    RecherchePremier(Liste);

    return 0;
}
