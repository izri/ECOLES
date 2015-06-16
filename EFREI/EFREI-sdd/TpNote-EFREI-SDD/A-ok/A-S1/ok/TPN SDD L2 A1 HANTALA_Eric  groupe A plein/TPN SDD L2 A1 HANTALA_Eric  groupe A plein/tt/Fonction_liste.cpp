#include <iostream>
#include "liste.h"

using namespace std;

void init (liste* lsc)
{

    lsc->head=NULL;
    lsc->fin=NULL;
    lsc->length=0;
}

bool testlscvide (liste* lsc)
{
    if (lsc->head ==NULL)
    {
        return 1;
    }else
    {
        return 0;
    }
}

void Afficher(liste* lsc)
{

    cell* element = NULL;
    element = lsc->head;
    if (testlscvide(lsc))
    {
        printf("Liste Vide \n");
    }
    else
    {
        while(element != NULL)
        {
            printf("%d", element->val);
            printf("\n");
            element = element->next;

        }
    }

}

void newcell(liste* lsc, cell* nouveau)
{

    if (lsc->head == NULL)
    {

        lsc->head=nouveau;
        lsc->fin =nouveau;
    }else
        {
        lsc->fin->next=nouveau;
        lsc-> fin =nouveau;
        }

}

void verifpremier(liste* lsc,int borne)
{
    cell* actuel;

    if (testlscvide(lsc)) return ;


    for(int i=3; i< borne;i++)
    {
        actuel = lsc->head->next;

        while (((i%actuel->val)!=0)&&(actuel->next != NULL))
        {
            actuel = actuel->next;
        }

    if (actuel->next == NULL)
       {

        cell* premier = (cell*) malloc(sizeof(cell));
        premier->val=i;
        premier->next=NULL;
        newcell(lsc,premier);
       }
    }
    return;
}


