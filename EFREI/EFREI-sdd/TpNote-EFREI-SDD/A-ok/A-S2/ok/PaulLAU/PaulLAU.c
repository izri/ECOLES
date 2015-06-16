#include <stdio.h>
#include <stdlib.h>
#include "PaulLAU.h"

int saisirN()
{
    int vrai;
        vrai = 0;
        int n;
        while(!vrai)
        {
            printf("\n Indiquez le nombre N elements dans la liste chainee d'entiers (>2) : ");
            scanf("%d",&n);
            fflush(stdin);
            if(n>=3) vrai=1;
        }
        return n;
}

void creerLSC(liste lst, int n)
{
    int cpt = 3;
    liste m,tmp;
    tmp = lst;
    while(cpt != n+1)
    {
        m = (liste)malloc(sizeof(liste));
        m->info = cpt;
        m->succ = NULL;
        tmp->succ = m;
        tmp = tmp->succ;
        cpt++;
    }
}

void afficherLSC(liste lst)
{
    liste tmp;
    tmp = lst;
    if(lst == NULL) printf("\nERREUR : Liste vide.\n");
    else
    {
        while(tmp != NULL)
        {
            printf("\nNombre contenu dans la liste : %d.",tmp->info);
            tmp = tmp->succ;
        }
    }
}

liste calculParfait(liste lst)
{
    liste parfait;
    liste tempo;
    if(lst == NULL) printf("\nERREUR : Liste vide.\n");
    else
    {
        int cpt, somdiv;
        liste tmp, div,
        temp;
        tmp = lst;
        while(tmp != NULL)
        {
            cpt = 1;
            somdiv = 0;
            while(cpt<=tmp->info)
            {
                if(tmp->info%cpt == 0)
                {
                    div = (liste)malloc(sizeof(liste));
                    div->succ = NULL;
                    div->info = cpt;
                    tempo->succ = div;
                    tempo = tempo->succ;
                    somdiv = somdiv + div->info;
                }
                cpt++;
            }
            if(somdiv == tmp->info)
            {
                parfait = (liste)malloc(sizeof(liste));
                parfait->succ = NULL;
                parfait->info = cpt;
                temp->succ = parfait;
                temp = temp->succ;
            }
            tmp = tmp->succ;
        }
    }
    return parfait;
}

int main()
{
    printf("\n\n\n      TPN SDD L2 du 18/11\n       GpA session II\n\n");
    system("pause");
    system("cls");
    liste lsc, lparfait;
    int n;
    lsc = (liste)malloc(sizeof(liste));
    lsc->succ = NULL;
    lsc->info = 2;
    n = saisirN();
    creerLSC(lsc,n);
    afficherLSC(lsc);
    lparfait = calculParfait(lsc);
    afficherLSC(lparfait);


    return 0;
}
