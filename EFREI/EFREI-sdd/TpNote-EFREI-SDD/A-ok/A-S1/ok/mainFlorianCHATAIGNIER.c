#include <stdio.h>
#include <stdlib.h>

struct maillon
{
    int nombre;
    struct maillon* suivant;
};
typedef struct maillon* liste;

struct noeud            /// UTILISE SEULEMENT DANS L'EXO 2
{
    int nombre;
    struct noeud* filsGauche;
    struct noeud* filsDroit;
};
typedef struct noeud* arbre;


///Prototypes de fonctions
void creation_liste_avec_entiers(liste*,int);
void affichage_liste(liste*);
void garder_nombre_entiers(liste*);
void trier_liste_arbre(liste*);

int main()          /// MAIN : EXO 1 et EXO 2 DEDANS
{
    liste maListe;                                  /// DEBUT EXO 1
    creation_liste_avec_entiers(&maListe,30);
    affichage_liste(&maListe);
    printf("\n\n\n");

    garder_nombre_entiers(&maListe);
    affichage_liste(&maListe);                      /// FIN EXO 1

    /// DEBUT EXO 2
    printf("\n\n\n\n\n");


    return 0;
}


void creation_liste_avec_entiers(liste *lst, int n)
{
    liste l = NULL;
    int compteur;
    ///Création du tout premier maillon
    *lst = (liste)malloc(sizeof(struct maillon));
    l=*lst;
    l->nombre=2;

    ///On ajoute le reste de la liste chaînée de 1 en 1 jusqu'à 150
    for (compteur=3;compteur<=n;compteur++)
    {
        l->suivant=(liste)malloc(sizeof(struct maillon));
        l=l->suivant;
        l->nombre=compteur;
    }
    l->suivant=NULL; /// On est sorti de la boucle : on annonce la fin de la liste chaînée--> le pointeur sur le maillon suivant est NULL car ce maillon n'existe pas
}


void affichage_liste(liste *lst)
{
    liste l;
    l=*lst;
    while(l->suivant!=NULL)
    {
        printf("%d\n",l->nombre);
        l=l->suivant;
    }
}



void garder_nombre_entiers(liste *lst)
{
    liste l, lstDePassage;
    l=*lst;
    int diviseurEventuel, estPremier;

    while (l->suivant!=NULL)
    {
        estPremier=1;
        diviseurEventuel=2;
        while (estPremier==1 && diviseurEventuel<=(l->nombre)/2)
        {
            if (l->nombre%diviseurEventuel==0)
            {
                estPremier=0;
            }
            diviseurEventuel=diviseurEventuel+1;
        }
        if (estPremier==0)
        {
            lstDePassage->suivant= l->suivant;
        }
        lstDePassage=l;             ///On fait ça pour garder la valeur du maillon précédent (comme ça, si le nombre n'est pas premier, on peut supprimer ce maillon en
        l=lstDePassage->suivant;    /// faisant pointer le pointeur "suivant" du maillon précédent sur le pointeur "suivant" du maillon actuel.
    }
}






///EXO 2


void trier_liste_arbre(liste *lst)
{
    liste l;
    l=*lst;
}
