#include <iostream>
#include "grammaire.h"
using namespace std ;

struct Etat{
vector< vector<string> >  automate_lr ; // tableau en trois dimensions pour contenir tous les etats du slr
// premiere colonne : les transitions de chaque etat, 2eme colonne : les premiers symboles de chaque regles, troisieme colonne:
// les etats d'arrivée de chaque symbole, 4eme colonne : les actions sur les etats.
// on ajoute un vector d'entiers :
vector<Etat*> tableau_etats_suivants; // tableau de pointeurs vers les suivants
vector<int> numero_elements_pointes ;
vector<string> elements_pointes ; // tableau des elemts par lesquels on derive
int numero_etat ;
int nombre_etats ;
};

void Automate_lr(grammaire* a) ;
int retourner_position_element(vector<string> a , string b , int elt_fin) ;
int comparer_etats (vector<string> a , vector<string> b);
string extraire_premier(string a , vector<string> b) ;
int trouver_redondance(string a , vector<string> b) ;
int redondance_regle(string elt_depart, string elt_avant_point, string elt_apres_point , Etat* regle) ;
vector<Etat*> effectuer_derivation( Etat* a , grammaire* b , Etat* Etat_base , vector<Etat*> c) ;
int comparer_tables(vector< vector<string> > a , vector< vector<string> > b) ;
