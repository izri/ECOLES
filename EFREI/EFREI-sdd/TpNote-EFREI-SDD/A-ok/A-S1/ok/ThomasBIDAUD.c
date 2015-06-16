#include <stdio.h>
#include <stdlib.h>

//Affichage de nombres premiers suivant une liste simplement chainée créée

typedef struct maillon
{
    struct maillon *suivant;
    int donnee;
}maillon;



void liste_entier(maillon **liste, int n);

void nombres_premier(maillon **liste);

void supprimer(maillon *liste);



void liste_entier(maillon **liste, int n) //Création de la liste d'entiers
{
    int cpt;
    maillon *m=NULL;

    *liste = (maillon*)malloc(sizeof(maillon)); //On initialise la liste
    m = *liste;
    m->donnee = 2; //On la fait commencer par 2 puis on ajoute un maillon qui aura une valeur croissante de 1 en 1
    for(cpt=3; cpt<=n; cpt++)
    {
        m->suivant = (maillon*)malloc(sizeof(maillon));
        m = m->suivant;
        m->donnee = cpt;
    }
    m->suivant = NULL; //A la fin de la liste on prend NULL comme derniere valeur du dernier maillon
}


void nombres_premier(maillon **liste) //Recherche des nombres premiers
{
    int cpt, premier;
    maillon *m=NULL, *temp=NULL;

    m = *liste;
    if(m==NULL || m->donnee!=2) // On verifie que la liste n'est pas nulle et si elle commence bien par 2 (au cas où il y aurait une erreur lors de la création de la liste)
    {
        printf("ERREUR, la liste d'entiers doit commencer par un 2"); //Sinon, on renvoit une phrase d'erreur et on recommence la liste à créer
    }else
    {
        temp = m;
        while(m!=NULL) // Tant qu'on est pas arrivé au bout de la liste
        {
            premier = 1; // On part sur le fait que le nombre est premier
            cpt = 2;
            while(cpt<=((m->donnee)/2) && premier==1) //on teste si le nombre est premier jusqu'à arriver à sa moitié ou que l'on ait déjà trouvé un diviseur au nombre
            {
                premier = ((m->donnee%cpt)==0)?0:1; //Si le modulo du compteur avec le nombre pris avec égal à 0, on a un diviseur donc premier sera égal à 0 sinon on a 1
                cpt++;
            }
            if(premier==0) //On supprime le maillon qui contient le nombre si celui ci est premier après
            {
                temp->suivant = m->suivant;
            }
            temp = m;
            m =temp->suivant;

        }
    }
}

void supprimer(maillon *liste) // A la fin du programme, on libere la mémoire
{
    maillon *m=NULL;
    if(liste!=NULL)
    {
        while(liste->suivant!=NULL)
        {
            m = liste->suivant;
            free(liste);
            liste = m;
        }
        free(liste);
    }
}



/*
typedef struct arbre_binaire {     //Création d'un arbre binaire en largeur
    unsigned content;
    struct arbre_binaire *sag, *sad; //sag=Sous Arbre Gauche et sad=Sous Arbre Droit
} arbre_binaire;

typedef arbre_binaire *arbre;


//Créer et initialiser un nouveau nœud d’arbre

arbre nouveau_noeud(unsigned content)
{
    arbre a;
    a=(arbre)malloc(sizeof(arbre_binaire));
    a->content=content;
    a->sag=NULL;
    a->sad=NULL;
}

arbre nouvelle_branche(m)
{
    arbre a;
    a=nouveau_noeud(m);

    a->sag=nouvelle_branche(n-1,...); //On prend le chiffre sur lequel on pointe actuellement dans la liste
    a->sad=nouvelle_branche(n-1,....); // On avance de 1 dans la liste pour trouver le nombre premier suivant et l'intégrer au sad

    return a;
}
*/



int main()
{
    maillon *liste=NULL, *m;

    liste_entier(&liste, 150); //On crée une liste allant de 2 à 150
    nombres_premier(&liste); // On cherche les nombres premiers
    m=liste; // et on les met dans la variable m pour ensuite les afficher 1 à 1
    //nouveau_noeud(m);
    printf("La liste des nombres premiers est la suivante (jusqu'a 150) :\n");
    while(m!=NULL)
    {
        printf("%d\n", m->donnee);
        //nouvelle_branche()
        m = m->suivant;
    }
    supprimer(liste); // On supprime la liste après


    return 0;
}



