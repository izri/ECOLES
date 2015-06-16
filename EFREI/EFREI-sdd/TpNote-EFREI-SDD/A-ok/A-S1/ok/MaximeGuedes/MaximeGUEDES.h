#ifndef MAXIMEGUEDES_H_INCLUDED
#define MAXIMEGUEDES_H_INCLUDED

//EXERCICE 1
typedef struct liste
{
    int nombre;
    struct liste* succ;
} Liste_chainee;


//Cr�e une liste chain�e avec les nombres de 2 au nombre sp�cifi� en param�tre
Liste_chainee* LSC_RemplissageListe (int);

//�limine tous les maillons d'une chaine qui ne sont pas des nombre premiers
Liste_chainee* LSC_NombrePremier (Liste_chainee*);

//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

//EXERCICE 2

typedef struct arbre_binaire
{
    int nombre;
    struct arbre_binaire* sag;
    struct arbre_binaire* sad;
}Arbre;

//cr�e l'arbre parfait contenant la liste des �l�ments rentr�e en param�tre
Arbre* ABR_CreationArbre (int*);

#endif // MAXIMEGUEDES_H_INCLUDED
