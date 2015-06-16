#ifndef RESTO__H_INCLUDED
#define RESTO__H_INCLUDED

#include <string>

using namespace std;

class Commande
{
private: // modificateur

    // Attributs
    string m_nomClient;
    unsigned int m_prix[5];
    unsigned int m_qteRepas[5];

public:

    // Constructeur
    Commande();
    Commande(string c);

    // Méthodes
    void afficher();
    unsigned int prixTotal();

    //Setter
    void ajouterPizza(unsigned int p);
    void ajouterPJ(unsigned int p);
    void ajouterDessert(unsigned int p);
    void ajouterBoisson(unsigned int p);
    void ajouterRV(unsigned int p);

    // Setter NOM
    void setNomClient(string c);

    //Getter NOM
    string getNomClient();
};



class Produit
{
protected:
    string m_nomProduit;
    unsigned int m_prix[5];

public:
    // constructeur

    Produit(string e);
    void Selectionner(Commande commande1);
};

class Client
{
private:
    string m_nomClient;



public:
    // constructeur
    Client();
    Client(string c);

    // methodes
    void Commander(Produit produit1);
    void Payer();
};

class PJ : public Produit
{

};

class Pv : public Produit
{

};

class Pizza : public Produit
{

};

class Dessert : public Produit
{

};

class Boisson : public Produit
{

};




#endif // RESTO__H_INCLUDED
