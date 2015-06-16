#include <stdio.h>
#include <stdlib.h>

typedef struct noeud /// On crée un maillon, ici appelé noeud
{
    int x;
    struct noeud *suivant;
} noeud;

noeud *ajout(noeud *tete, int val)///Fonction d'ajout d'un maillon a la liste
{
    noeud *p_new = malloc(1*sizeof(p_new));

    if (p_new != NULL) ///Si tout se passe bien et qu'on a alloué la mémoire necessaire
    {
        p_new->suivant = NULL;
        p_new->x = val;

        if(tete == NULL) tete = p_new; ///Si liste vide, alors tete prend le premier maillon (adresse)
        else
        {
            noeud *p = tete;
            while (p->suivant != NULL) p = p->suivant; ///On va jusqu'au dernier maillon (adresse)
            p->suivant = p_new;
        }
    }

    return tete;

}

void afficher(tete)///Fonction d'affichage de la liste chainée
{
    noeud *p = tete;
    while (p != NULL)
    {
        printf("%d -> ", p->x);
        p = p->suivant;
    }

}

int isPremier(noeud* nombre)///Calcul d'un nombre premier
{
    int i = 2;

   if (nombre->suivant->x == 1) return 0;///1 n'est pas un nombre premier
   if (nombre->suivant->x == 2) return 1; ///On traite le cas particulier de 2, qui est le seul nombre premier pair
  while (i < nombre->suivant->x)
  {
        if (nombre->suivant->x % i == 0) return 0;///Divisible par autre chose que lui meme et 1, donc pas premier
        i++;
   }
 return 1;///Sinon, il est premier, on retourne 1.

}

noeud *suppr(noeud *tete)
{
    int nombre;

    noeud *p = tete;
    noeud *ptemp = NULL;
    while (p->suivant != NULL)
    {
       /* if (p->x == 1)
        {
            ptemp = tete;
            tete = p->suivant;

            free (ptemp);///On n'oublie pas de libérer le maillon a supprimer de la liste
        }
        else
        {*/
            if (isPremier(p->suivant) == 0)///Si la valeur est un nombre qui n'est pas premier alors on va supprimer le maillon
            {
                ptemp = p->suivant;
                p->suivant = p->suivant->suivant;

                free(ptemp);///Suppression du maillon faible ...
            }

    p = p->suivant;
    }
    return tete;
}

int main()
{
    noeud *tete = NULL;
    int cpt, n = 0;

    printf("Quelle est la valeur de N ? ");
    scanf("%d", &n);

    for (cpt = 1; cpt <= n; cpt++) tete = ajout(tete, cpt);

    afficher(tete);


    printf("\n");

    while(tete->suivant != NULL)
    {
           printf("%d ", isPremier(tete));
           tete = tete->suivant;
    }

    printf("\n");
    afficher(suppr(tete));


    return 0;
}
