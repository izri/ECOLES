#include "Vente.h"
#include <iostream>
#include <string>

using namespace std;

Vente::Vente() : m_nbPizza(),m_nbPv(),m_nbPj(),m_nbBoisson(),m_nbDessert()
{

}

Vente::Vente(string c, int nb) : m_nbPizza(),m_nbPv(),m_nbPj(),m_nbBoisson(),m_nbDessert()
{

}

/// manque les 2 focntions !!!
int prix=0;
int prix3=0;
void Vente::vente(){


TicketCaisse prix2;

prix3=resumeTicket();
    prix=prix + prix3;




cout << "votre recette actuel est " << prix << " euros " << endl;

}




