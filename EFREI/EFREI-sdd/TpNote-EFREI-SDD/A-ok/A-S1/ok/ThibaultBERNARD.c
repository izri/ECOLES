#include <stdlib.h>
#include <stdio.h>

#include <string.h>


typedef struct Nombre {
long nombre ;
struct Nombre *suivant;
}Nombre;

   typedef struct arbre {
    unsigned content;
    struct arbre *sag, *sad;
} arbre;

/*typedef struct file {
    list tete;
    list queue;
} file;*/

Nombre* creationcellule (void);
Nombre*  premierELT (Nombre **);
void construireliste(Nombre **,long);
void Supprimer(Nombre**);
void Nombre_premier(void);
int arbre_vide(arbre *);
arbre* nouveau_noeux(long);

Nombre * creationcellule ()
{
    Nombre * p ;
    p = (Nombre*)malloc(sizeof(Nombre));

    printf("Saisir le nombre entier :\n");

    scanf("%ld",&p->nombre);

    p -> suivant = NULL ;
    return p;
}

Nombre * premierELT (Nombre ** lst)
{
    Nombre* l ;
    l = creationcellule();
    *lst = l;
    return l ;
}

void construireliste(Nombre ** lst,long n)
{
    Nombre * p,*l;
    long cpt ;
    p=premierELT(lst);

    for(cpt=2;cpt<=n;cpt++)
    {
        l=creationcellule();
        p -> suivant = l ;
        p = l ;
    }
}

void Afficher(Nombre * liste)
{
    Nombre * element = liste;
    if (element == NULL)
    {
        printf("Liste vide \n");
    }
    else
    {
        while(element != NULL)
        {
            printf("Le nombre est : %ld \n ", element->nombre);
            element = element -> suivant ;
        }
    }
}

void Supprimer(Nombre**liste)
{

    Nombre* p=*liste , *tempo;

   while (p != NULL )
   {
       tempo = p ;
       p=p->suivant;
       tempo -> suivant = p -> suivant ;
       free(p);
   }
}

void Nombre_premier()
{
    long nombre ,reste, i, est_premier ;

    printf("les 150 plus petits nombres premier sont :");

    for (nombre=2;nombre<150;nombre++)
    {
        est_premier = 1 ;

        for (i=2;i<nombre;i++)
        {
            reste = nombre % i ;
            if (reste == 0)
            {
               est_premier = 0;                        // il n'est pas premier
            }
        }

        if (est_premier != 0)                           // est premier
        {
            printf("; %ld",nombre);
        }

    }
}

/// Vérifier qu’un arbre est vide.
int arbre_vide(arbre * t) {
    if (t == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

///Créer et initialiser un nœud d’arbre.
arbre* nouveau_noeux(long content) {
    arbre* t ;

  t = (arbre*)malloc(sizeof(arbre)) ;
  t ->content = content ;
  t -> sag = NULL ;
  t -> sad = NULL ;
  return t ;
}

///Il me manque les fonction enfiler et dépiler;
/*
/// 3.  Parcourir un arbre  en largeur.
void parcourir_arbre_largeur(arbre* t) {

    lQueue* f ;

    if (t == NULL)
    {
        return ;
    }

    f=Nouvelle_liste();
        Emfiler(t,f);

    while(f != NULL)
    {
     Defiler((void **)&t,f);
        if (arbre_vide(t->sag) != NULL );
            {
                Emfiler(t->sag, f);
            }
        if(arbre_vide(t->sad) != NULL)
            {
                Emfiler(t->sad, f);
            }
    }
}
*/

int main()
{

    ///---------------------------Liste chainée------------------------------
    long info ;
    Nombre * lst;
    arbre* a ;
    long N ;

    printf("Saisir le nombre de N entier souhaite :\n");
    scanf("%ld",&N);

    construireliste(&lst,N);
    Afficher(lst);

    printf("\n");
    Nombre_premier();

    ///----------------------Arbres-------------------------------------------------

    arbre_vide(a);
    nouveau_noeux(info);


    return 0;
}
