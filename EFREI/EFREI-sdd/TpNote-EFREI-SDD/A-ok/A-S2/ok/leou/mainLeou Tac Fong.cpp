#include <iostream>
#include "WINDOWS.h"

using namespace std;
/*----------------------Exercice 1--------------------------*/
/*Structures*/
typedef struct parfait
{
    int n;
    parfait *suivant;

}m_parfait;

typedef m_parfait *LSCParfait;

/*Fonctions*/
LSCParfait Creation_maillon_tete(LSCParfait head, int choix)   /// on ajoute les maillons � la t�te
{
    LSCParfait nv = (LSCParfait)malloc(sizeof(m_parfait));  /// nouveau maillon
    nv->n = choix;  /// on remplit les champs
    nv->suivant = head; /// on ajoute le nouveau maillon � la t�te

    return nv;  /// nv devient t�te
}

void Afficher_liste(LSCParfait head)
{
    LSCParfait l = head;    /// pointeur qui parcourt la liste
    while(l != NULL)   /// on s'arrete � la fin de la liste
    {
        cout << l->n << endl;
        l = l->suivant;
    }

    return;
}

LSCParfait Creation_liste(LSCParfait head)     /// cr�e une liste cha�n�e de nombres
{
    int choix;  /// n entr� par l'utilisateur
    do
    {
        cout << "Entrer le nombre d'entiers (superieur a 2) : ";
        cin >> choix;
    }while(choix < 2);  /// saisie s�curis�e pour le choix N

    do   /// on cr�e liste
    {
        head = Creation_maillon_tete(head, choix);
        choix = choix - 1;
    }while(choix > 0);

    return head;

}

LSCParfait Supprimer_liste(LSCParfait head)     /// suprrime une liste
{
    LSCParfait temp = head; /// pointeur temporaire qui permet de liberer un maillon sans perdre la liste
    while(head != NULL)
    {
        head = head->suivant;
        free(temp);
        temp = head;
    }

    return head;
}

int Test_Parfait(LSCParfait entier)   /// on veux savoir si le nombre est parfait
{
    LSCParfait diviseurs = NULL;     /// On cr�e un liste des diviseurs de n
    int cpt = 1;    /// on cr�e un compteur qui testera le reste de la division euclidienne de n par cpt
    int modulo; /// si modulo est nul, cpt est u diviseur de n , sinon cpt augmente de 1

    while (cpt != entier->n - 1)    /// on cr�e la liste des diviseurs de n
    {
        modulo = entier->n % cpt;
        if(modulo == 0)
        {
            diviseurs = Creation_maillon_tete(diviseurs, cpt);
        }
        cpt ++;
    }

    int resultat = 0;    /// resultat de la somme des diviseurs de n
    LSCParfait l = diviseurs;  /// pointeur qui va parcourir la liste des diviseurs
    while(l != NULL)    /// on parcours la liste des diviseurs
    {
        resultat = resultat + l->n;
        l = l->suivant;
    }

    diviseurs = Supprimer_liste(diviseurs);  /// on lib�re la m�moire

    if(resultat == entier->n)
    {
        return true;    /// si le n est parfait, on retourne vrai
    }
    else
    {
        return false;   /// inversement
    }

}

LSCParfait Tri_liste(LSCParfait head)   /// on tri les nombres parfaits
{
    LSCParfait l = head->suivant;   /// pointeur qui parcourt la liste
    LSCParfait pl = head;   /// pointeur qui pr�c�de l

    while(l != NULL)
    {
        if(Test_Parfait(l)) /// l pointe sur un nombre parfait
        {
            pl = l;
            l = l->suivant;
        }
        else    /// sinon on supprime le maillon de l
        {
            pl->suivant = l->suivant;
            free(l);
            l = pl->suivant;
        }
    }

    return head;
}

/*---------------------------------Exercice 2-------------------------------*/
// Structures
typedef struct branche
{
    int n;
    branche *g;
    branche *d;
}a_branche;

typedef a_branche *arbre;

/*LSCParfait Creation_maillon_queue(LSCParfait head, int choix)   /// n�cessaire pour cr�er une file
{
    LSCParfait
}*/

/*arbre Remplir_arbre(arbre a, LSCParfait head)
{
    LSCParfait head2 = NULL;   /// on cr�e une liste qui servira de file
    LSCParfait l = head;    /// pointeur qui parcourt la t�te
    ///head2 = Creation_maillon_queue(head2, l->n);

    while(l != NULL)
    {

    }

    return a;
}*/


/* Fonction main */

int main()
{
    LSCParfait head = NULL;     /// t�te de liste
    head = Creation_liste(head);    /// on cr�e notre liste
    cout << "Liste des N nombres : " << endl;
    Afficher_liste(head);   /// on l'affiche
    head = Tri_liste(head);
    cout << "Liste des nombres parfaits : " << endl;
    Afficher_liste(head);

    /*arbre a = NULL;
    a = Remplir_arbre(a, head);*/


    return 0;
}
