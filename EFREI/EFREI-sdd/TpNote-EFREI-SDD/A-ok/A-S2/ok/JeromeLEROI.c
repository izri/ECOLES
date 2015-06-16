#include <stdio.h>
#include <stdlib.h>

typedef struct Elt
{
    int nombre;
    struct Elt *suiv;
}Elt;

void creationLSC(Elt **lsc, int n);
void nbparfait(Elt **liste);

void creationLSC(Elt **lsc, int n)
{
    int cpt;
    Elt *element=NULL;

    *lsc = (Elt*)malloc(sizeof(Elt));
    element = *lsc;
    element->nombre = 2;

    for(cpt=3; cpt<=n; cpt++)
    {
        element->suiv = (Elt*)malloc(sizeof(Elt));
        element = element->suiv;
        element->nombre = cpt;
    }
    element->suiv = NULL;
}

void nbparfait(Elt **lsc)
{
    Elt *tempo, *prec;
    tempo = *lsc;
    while(tempo!=NULL)
    {
        prec = tempo;
        if (tempo->nombre == 2)
        {
            prec->suiv=tempo->suiv;
            free(tempo);
        }
        else
        {

        }
        tempo = tempo->suiv;
    }
}

int main()
{
    int n;
    Elt *lsc=NULL, *tempo;

    printf("Veuillez saisir N :\n");
    scanf("%d", &n);
    creationLSC(&lsc, n);
    tempo=lsc;
    while(tempo!=NULL)
    {
        printf("Valeur : %d\n", tempo->nombre);
        tempo = tempo->suiv;
    }
    nbparfait(&lsc);


    return 0;
}

