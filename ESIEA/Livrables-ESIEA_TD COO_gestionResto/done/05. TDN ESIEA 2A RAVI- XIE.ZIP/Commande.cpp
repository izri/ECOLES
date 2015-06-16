#include <string>
#include "Commande.h"

using namespace std;

void Commande::init()
{
    for(int i(0); i<5; i++)
    {
        m_qteRepas[i]=0;
    }
    m_prix[0]=6;
    m_prix[1]=8;
    m_prix[2]=10;
    m_prix[3]=5;
    m_prix[4]=2;
}


Commande::Commande() : m_nomClient("Jack")
{
    init();
}

Commande::Commande(string c) : m_nomClient(c)
{
    init();
}

unsigned int Commande::prixTotal()
{
   unsigned int somme;
   for(int i(0); i<5; i++)
   {
       somme = m_prix[i]+m_qteRepas[i];
   }
   return somme;
}

void Commande::affichage()
{
    //int nbPizza,nbPJ,prixtotal,nbPV,nbDessert,nbBoisson;

    cout << "Client " << m_nomClient << endl;
    cout << "Prix total de la commande "<< prixTotal() <<endl;
    cout<< "Combien de pizza voulez-vous? " << endl;
    cout<< "Combien de plat du jour voulez-vous? "<< endl;
    cout<< "Combien de plat végétarien voulez-vous? " << endl;
    cout<< "Combien de dessert voulez-vous? "<< endl;
    cout<< "Combien de boisson voulez-vous? "<< endl;
    cout<< "Prix total de la commande: " << prixTotal() << endl;

}

void Commande::ajoutQte(unsigned int a, unsigned int b)
{
    m_qteRepas[b] += a;
}

void Commande::setNomClient(string c)
{

    string monAge;
    m_nomClient = c;

    cout << "Entrez votre Nom " << endl;
    cin >> m_nomClient;
    cout << "Entrez votre age " << endl;
    cin >> monAge;

    cout << "Nom : "<< m_nomClient << endl;
    cout << "Age : "<< monAge << endl;

}

string Commande::getNomClient()
{
    return m_nomClient;
}









