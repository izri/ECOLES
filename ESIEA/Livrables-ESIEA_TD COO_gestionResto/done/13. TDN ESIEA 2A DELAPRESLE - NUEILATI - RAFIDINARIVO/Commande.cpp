#include "Commande.h"
#include "Plat.h"
using namespace std;
Commande::Commande (string nomDuClient): m_nom(nomDuClient), m_somme(0) {
}

void Commande::commander (Plat repas){ 
	m_somme = m_somme + repas.getPrice(); 
}

void Commande::afficher()
{
	cout << "Client : " << m_nom << endl <<"Vous devez payer la somme de  : " << m_somme << "€ " <<endl;
}
