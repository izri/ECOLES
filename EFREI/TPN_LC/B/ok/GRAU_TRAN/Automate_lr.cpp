#include "Automate_lr.h"
#include "windows.h"
#include <iostream>
#include<sstream>

using namespace std ;
void Automate_lr(grammaire* a)
{
vector<Etat*> Conteneur_SLR ;
    Etat* LR(NULL) ;
    // initialisation de l'automate: le premier etat
    LR = new Etat[1] ;

    LR->numero_etat = 0 ;
    LR->nombre_etats = 0 ;

    for (int i = 0 ; i < a->nombre_ligne ; i++){ // le meme nombre de lignes que le nombre de regles
        LR->automate_lr.push_back(vector<string>(0)) ;
    }

    for (int i = 0 ; i < a->nombre_ligne ; i++){
        LR->automate_lr[i].push_back(a->production[i][0]) ; // premiere case correspondant à l'etat d'origine
        LR->automate_lr[i].push_back(".") ; // deuxieme case correspondant à la partie avant le point. Elle contiendra aussi le point
        LR->automate_lr[i].push_back("."+a->production[i][1]) ; // troisieme case correspondant à la règle
    }
    // le tableau des regles est initialisé
    // initialisation des elements par lesquels on derive
    // l'element que l'on derive est l'element qui se situe dans la deuxieme case
    string nouvelle_derivation ;
    int redondance = 0 ;
    for (int i = 0 ; i < a->nombre_ligne ; i++){
        nouvelle_derivation = extraire_premier(LR->automate_lr[i][2].substr(1) , a->elt_grammaire) ; // on sort le premier element le plus à gauche. Le substr pour enlever le point

        redondance = trouver_redondance(nouvelle_derivation , LR->elements_pointes) ; // on regarde si la derivation a deja ete enregistrée

        if (redondance == 0){ // si l element n apas encore ete enregistré, on le fait
            LR->elements_pointes.push_back(nouvelle_derivation) ;
        }
    }
    // on ainitialisé le tableau enregistrant les elements pas lesquels on derive
    // on initialise à present le tableau des numeros suivants
    Conteneur_SLR.push_back(LR) ;

int nouvelle_taille = 1 ;
int ancienne_taille = 0 ;
int Etat_actuel = 0 ;
while (ancienne_taille < nouvelle_taille)//ancienne_taille < nouvelle_taille)// cela signifie qu'il y a de l'ajout
{

    ancienne_taille = Conteneur_SLR.size();
   Conteneur_SLR = effectuer_derivation(Conteneur_SLR[Etat_actuel] , a , LR , Conteneur_SLR) ;
    nouvelle_taille = Conteneur_SLR.size() ;
    Etat_actuel++ ;
}
for (int j = 0 ; j < Conteneur_SLR.size() ; j++)
{
    cout <<endl << endl ;
    cout << "etat numero: " << Conteneur_SLR[j]->numero_etat << endl ;
    cout << "il va vers :" ;
    for (int i = 0 ; i <Conteneur_SLR[j]->numero_elements_pointes.size() ; i++){
        cout <<Conteneur_SLR[j]->numero_elements_pointes[i] << " " ;
    }
    cout << endl ;
for (int i = 0 ; i < Conteneur_SLR[j]->automate_lr.size() ; i++)
    {
        cout << Conteneur_SLR[j]->automate_lr[i][0] << "  " << Conteneur_SLR[j]->automate_lr[i][1] << "  " << Conteneur_SLR[j]->automate_lr[i][2] << endl ;
    }
}
    // il reste l'initialisation du dernier composant: les suivants de cet etat

}

vector<Etat*> effectuer_derivation( Etat* a , grammaire* b , Etat* Etat_base , vector<Etat*> c){
    Etat* temp(NULL) ;
    int cpt_regles = 0 ;
    string chaine_temp ;
    string element_decale ;

    int nouv_regle_entrante = 1 ;
    int regle_redondante = 0 ;
    string element_depart , element_avant_point, element_apres_point ;

    int tables_egales = 0 ;

    string nouvelle_derivation ;
        int redondance = 0 ;
        int numero_table_egale = 0 ;
    // effectuer le decalage de l'etat vers la case de gauche
    // pour simplifier tout les elements qui entreront ensuite, on prendra les deux premiers à gauche. le deuxieme correspond aux etats suivants
    // pour chacun de ces etats, on prend le premier à gauche
    for (int i = 0 ; i < a->elements_pointes.size() ; i++){ // pour chaque element par lequel on peut deriver, on le fait

            tables_egales = 0 ;
            nouv_regle_entrante = 1 ;
            regle_redondante = 0 ;
            cpt_regles = 0 ;
            redondance = 0 ;
            numero_table_egale = 0 ;
            temp = new Etat[1] ;

        for (int j = 0 ; j < a->automate_lr.size() ; j++){ // pour chaque regle
            if (a->elements_pointes[i] == extraire_premier(a->automate_lr[j][2].substr(1) , b->elt_grammaire)) // si le premier elt à gauche est bien egal à l'element qu on derive
            {
                //alors on effectue la derivation
                temp->automate_lr.push_back(vector<string>(0)) ;
                temp->automate_lr[cpt_regles].push_back(a->automate_lr[j][0]) ; // on a entré l'état initial
                chaine_temp = a->automate_lr[j][1].substr(0 , a->automate_lr[j][1].size()-1) ; // on extrait la partie avant le point
                temp->automate_lr[cpt_regles].push_back(chaine_temp+a->elements_pointes[i]+".") ; // on concatene le tout en ajoutant le point à la fin : on a notre deuxieme case
                // on s'occupe de créer la troisieme case, avec l'element decalé en moins
                chaine_temp = a->automate_lr[j][2].substr(1+a->elements_pointes[i].size()) ; // on extrait la chaine sans l'etat derive
                temp->automate_lr[cpt_regles].push_back("."+chaine_temp) ; // on concatene le point avec la nouvelle chaine

                cpt_regles++ ;
            }
        }
        // une fois la derivation effectuée, il faut mettre les etats complementaires.

    while (nouv_regle_entrante == 1) // tant q'une nouvelle regle arrive
    {
        nouv_regle_entrante = 0 ;
        for (int j = 0 ; j < temp->automate_lr.size() ; j++){
            //on extrait le premier à gauche, et on regarde si une ou plusieurs regles existent depuis cet element (un non terminal)
            // on verifie si cette regle existe deja
            for (int k = 0 ; k < Etat_base->automate_lr.size() ; k++){
                if (Etat_base->automate_lr[k][0] == extraire_premier(temp->automate_lr[j][2].substr(1) , b->elt_grammaire))
                {
                    //on verifie la redondance de la regle
                    if(redondance_regle(Etat_base->automate_lr[k][0] , Etat_base->automate_lr[k][1] , Etat_base->automate_lr[k][2] , temp) == 0) // si la regle n'a pas encore ete posée
                    {
                        // on l'entre dans temp
                        temp->automate_lr.push_back(vector<string>(0)) ;
                        temp->automate_lr.back().push_back(Etat_base->automate_lr[k][0]) ;
                        temp->automate_lr.back().push_back(Etat_base->automate_lr[k][1]) ;
                        temp->automate_lr.back().push_back(Etat_base->automate_lr[k][2]) ;
                        nouv_regle_entrante = 1 ; // on a entré une nouvelle regle, on recommence le processus !
                    }
                }
            }
        }
    }
    nouv_regle_entrante = 1 ;
    // on a à présent la table suivante, mais on ne sait pas si cette table existe ou non
    // il faut donc la vérifier
    for (int j = 0 ; j < c.size() ; j++)
    {
        if (tables_egales == 0)
        {
            tables_egales = comparer_tables(temp->automate_lr , c[j]->automate_lr) ; // on verifie si la table existe
            if (tables_egales== 1)
            {
                numero_table_egale = j ;
            }
        }
    }

    if (tables_egales==0) // on créer cette nouvelle table
    {
        for (int j = 0 ; j < temp->automate_lr.size() ; j++){
            nouvelle_derivation = extraire_premier(temp->automate_lr[j][2].substr(1) , b->elt_grammaire) ; // on sort le premier element le plus à gauche. Le substr pour enlever le point
            redondance = trouver_redondance(nouvelle_derivation , temp->elements_pointes) ; // on regarde si la derivation a deja ete enregistrée

            if (redondance == 0){ // si l element n apas encore ete enregistré, on le fait
                temp->elements_pointes.push_back(nouvelle_derivation) ;
            }
        }
    // on a initialisé le tableau enregistrant les elements pas lesquels on derive
    // on initialise à present le tableau des numeros suivants
    temp->numero_etat = a->nombre_etats+1; // on attribue le numero de suivant du nombre d etat
    a->nombre_etats = a->nombre_etats+1 ;// il y a un etat de plus
    temp->nombre_etats = a->nombre_etats ;

    a->numero_elements_pointes.push_back(temp->numero_etat) ;
    c.back()->nombre_etats = a->nombre_etats ;
    c.back()->numero_elements_pointes.push_back(temp->numero_etat) ;

    c.push_back(new Etat[1]) ;
    c.back()->numero_etat = temp->numero_etat ;
    c.back()->nombre_etats = temp->nombre_etats ;
    for (int j = 0 ; j < temp->automate_lr.size() ; j++){
        c.back()->automate_lr.push_back(vector<string>(0)) ;
        c.back()->automate_lr[j].push_back(temp->automate_lr[j][0]) ;
        c.back()->automate_lr[j].push_back(temp->automate_lr[j][1]) ;
        c.back()->automate_lr[j].push_back(temp->automate_lr[j][2]) ;
       // cout << endl ;
       // cout << temp->automate_lr[j][0] << "  " << temp->automate_lr[j][1] << "  " << temp->automate_lr[j][2] << endl ;
    }

    //cout << endl << endl ;
    for (int j = 0 ; j < temp->elements_pointes.size() ; j++){
        c.back()->elements_pointes.push_back(temp->elements_pointes[j]) ;
    }
    }
    else // on ajoute la liaison de l'element actuel vers la table existante
    {
        a->numero_elements_pointes.push_back(c[numero_table_egale]->numero_etat) ;
    }
    for (int j = 0 ; j < temp->automate_lr.size() ; j++){
        //cout << endl ;
        //cout << temp->automate_lr[j][0] << "  " << temp->automate_lr[j][1] << "  " << temp->automate_lr[j][2] << endl ;
    }
    delete temp ;
    temp = NULL ;
}
return c ;
}
int comparer_tables(vector< vector<string> > a , vector< vector<string> > b)
 {
     int egal = 0 ;
     int tmp = 0 ;
     int identique = 0 ;
     if (a.size() == b.size())
     {
         for (int i = 0 ; i < a.size() ; i++)
         {
             for(int j = 0 ; j < 3 ; j++){
                if(a[i][j] == b[i][j])
                {
                    tmp++ ;
                }
             }
             if (tmp == 3)
             {
                 egal++ ;
             }
             tmp = 0 ;
         }
         if (egal == a.size())
         {
            identique = 1 ;
         }
     }

     return identique ;
 }

int redondance_regle(string elt_depart, string elt_avant_point, string elt_apres_point , Etat* regle)
{
    int redondance = 0 ;
    for (int i = 0 ; i < regle->automate_lr.size() ; i++){
        if (elt_depart== regle->automate_lr[i][0])
        {
            if (elt_avant_point == regle->automate_lr[i][1])
            {
                if (elt_apres_point == regle->automate_lr[i][2]){
                redondance = 1 ;
                }
            }
        }
    }
    return redondance ;
}

string extraire_premier(string a , vector<string> b){
    int trouve = 0 ;
    string elt ;
    for (int i = 0 ; i < b.size() ; i++)
    {
        if((a.substr(0,b[0].size()) == b[i]) && (trouve == 0))
        {
            trouve = 1 ;
            elt = b[i] ;
        }
    }
    return elt ;

}

int trouver_redondance(string a , vector<string> b){
int redondance = 0 ;
for (int i = 0 ; i < b.size() ; i++){
    if (a == b[i]){
        redondance = 1 ;
    }
}
return redondance ;
}

int comparer_etats (vector<string> a , vector<string> b)
{
    int egal = 0 ;
    int egalite_vraie = 0 ;
    if (a.size() == b.size()) // si les tailles sont egales alors on continue
    {
        for (int i = 0 ; i < a.size() ; i++)
        {
            for (int j = 0 ; j < b.size() ; j++)
            {
                if (a[i] == b[j]) // si on trouve un meme element
                {
                    egal++ ;
                }
            }
        }
        if (egal == a.size())
        {
            egalite_vraie = 1 ; // l'egalite est alors verifiée
        }
    }
    return egalite_vraie ;
}

int retourner_position_element(vector<string> a , string b , int elt_fin)
{
    int index= -1 ;
    for(int i= 0 ; i < elt_fin ; i++)
    {
        if (a[i]==b)
        {
            index = i ;
            return i;
        }
    }
    return index ; // retourner la position de l element qui existe deja
}
