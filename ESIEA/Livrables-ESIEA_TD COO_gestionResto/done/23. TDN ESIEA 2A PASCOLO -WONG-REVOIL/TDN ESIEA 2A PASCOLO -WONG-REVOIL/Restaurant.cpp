#include "Restaurant.hpp"

using namespace std;

string Client::getName()
{
    return c_name;
}

string Client::getSurname()
{
    return c_surname;
}

string Product::getName()
{
    return name;
}

int Product::getPrice()
{
    return price;
}

void Command::evaluateCost(int priceToAdd)
{
    cost += priceToAdd;
}

int Command::getCost()
{
    return cost;
}

Client::Client(const string c_surname, const string c_name, const int id) : c_surname(c_surname), c_name(c_name), id(id) {}
Product::Product(const string name, const int price) : name(name), price(price) {}
Command::Command(Client client, Product product, const int cost) : client(client), product(product), cost(cost) {}
/*void Client::enregistrerCommande()
{
    ;
}
*/







/*void Personnage::attaquer(Personnage &cible)
{
    cible.recevoirDegats(m_degatsArme);

    //On inflige à la cible les dégâts que cause notre arme
}

void Personnage::boirePotionDeVie(int quantitePotion)
{
    m_vie += quantitePotion;

    if (m_vie > 100) //Interdiction de dépasser 100 de vie

    {

        m_vie = 100;

    }

}

void Personnage::changerArme(string nomNouvelleArme, int degatsNouvelleArme)
{
    m_nomArme = nomNouvelleArme;

    m_degatsArme = degatsNouvelleArme;
}

bool Personnage::estVivant()
{
    return m_vie > 0
}*/
