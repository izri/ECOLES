#include <stdio.h>
#include <stdlib.h>

/// CLOSSET MANON GROUPE A L2
/// EXERCICE 1 :

/// definition
typedef struct liste_entier
{
    int nombre;
    struct liste_entier *next;

} liste_entier;

/// creation de la liste simplement chainee
void creationliste(liste_entier **liste, int n)
{
    int i;
    liste_entier * maillon = NULL;

    *liste = (liste_entier*)malloc(sizeof(liste_entier)); // allocation dynamique pour le premier maillon

    maillon = *liste;

    maillon->nombre = 2; // premier maillon contient le chiffre 2

    for(i = 3 ; i <= n ; i++)   // creation des maillons suivants
    {
        maillon->next = (liste_entier*)malloc(sizeof(liste_entier)); // allocation dynamique

        maillon = maillon->next;

        maillon->nombre = i;
    }
    maillon->next = NULL;

}

/// Parcours de la liste en gardant que les nombre premiers

void Parcourir_Nb_premier(liste_entier ** liste, int n)
{

    int cpt, premier;
    liste_entier *maillon = NULL;
    liste_entier *temp = NULL;

    maillon = *liste;

    if(maillon == NULL || maillon->nombre != 2)
    {
        printf("la liste d'entiers doit commencer par un 2");
    }
    else
    {
        temp = maillon;

        while(maillon != NULL) //on parcourt toute la liste
        {
            premier = 1;
            cpt = 2;
            while(cpt<=((maillon->nombre)/2) && premier==1) //on teste si le nombre est premier par dichotomie
            {
                premier = ((maillon->nombre % cpt) == 0)?0:1;  //Si le modulo = 0 on a que un seul diviseur donc premier = 0
                cpt = cpt + 1;

                if(premier == 0) //si le nombre n'est pas premier on supprime le maillon
                {
                    temp->next = maillon->next;
                }
            }
            temp = maillon;
            maillon = temp->next;
        }
    }
}
/// affichage de la liste:
void Afficher(liste_entier * liste) // affiche le contenu de chaque maillon jusqu'a ce que l'on tombe sur une case remplie par "NULL"
{
    liste_entier * maillon = liste;

    if (maillon == NULL) printf("Liste Vide \n");
    else
        while(maillon != NULL)
        {
            printf(" %d \n", maillon->nombre);
            maillon = maillon->next;
        }

}

/// EXERCICE 2 ARBRE

///definition
typedef struct element_arbre
{
    int val;
    struct element_arbre *droite;
    struct element_arbre *gauche;
} element_arbre;

typedef struct element_arbre *arbre;

void ajouter_elements(arbre *liste)
{
    int val;

    do
    {
        printf("\n     Entrer la valeur %c ajouter :     ",133);
        fflush(stdin);
    }
    while(scanf("%d",&val)==0);
    arbre tmp;
    tmp = *liste;

    arbre tmpnoeud;
    tmpnoeud = NULL;

    arbre element = (arbre)malloc(sizeof(element_arbre));
    element->val = val;
    element->droite = NULL;
    element->gauche = NULL;

    if (tmp)
    {
        do
        {
            tmpnoeud = tmp;
            if (val > tmp->val)
            {
                tmp = tmp->droite;
                if (!tmp)
                {
                    tmpnoeud->droite = element;
                }
            }
            else
            {
                tmp = tmp->gauche;
                if (!tmp)
                {
                    tmpnoeud->gauche = element;
                }
            }

        }
        while (tmp);
    }
    else
    {
        *liste = element;
    }
}

void affichage(arbre *liste,int profondeur)
{
    int i;
    arbre tmp;
    tmp = *liste;
    if (!tmp)
    {
        return;
    }
    if (tmp->gauche)
    {
        affichage(&tmp->gauche,profondeur+1);
    }
    for (i = 0; i < profondeur; i++)
    {
        printf("    ");
    }
    printf("%d \n",tmp->val);

    if (tmp->droite)
    {
        affichage(&tmp->droite,profondeur+1);
    }

}

void vider(arbre *liste)
{
    arbre tmp;
    tmp = *liste;
    if(!tmp)
    {
        return;
    }
    if (tmp->gauche)
    {
        vider(&tmp->gauche);
    }
    if (tmp->droite)
    {
        vider(&tmp->droite);
    }

    free(tmp);
    *liste = NULL;
}

int main()
{
    /// exercice 1 :

    liste_entier *liste = NULL;
    creationliste(&liste, 150);
    Parcourir_Nb_premier(&liste,150);
    Afficher(liste);


    /// exercice 2 :

    arbre arbre1;
    arbre1 = NULL;
    int i,cpt;
 printf("\n   saisiie nbre     ");
    scanf("%d",&i);
    printf("\n");

    for( cpt= 0; cpt < i; cpt++)
    {
        ajouter_elements(&arbre1);
    }
        affichage(&arbre1,0);

        vider(&arbre1);

    return 0;
}








