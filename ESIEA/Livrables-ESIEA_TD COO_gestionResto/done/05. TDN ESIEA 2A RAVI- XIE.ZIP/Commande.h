#ifndef COMMANDE_H_INCLUDED
#define COMMANDE_H_INCLUDED
#include <iostream>
#include <string>


class Commande
{
    public:
        ///CONSTRUCTEUR
    Commande();///constructeur par defaut
    Commande(std::string c);
    ///METHODES
    void init();
    void affichage();
    unsigned int prixTotal();
    void ajoutQte(unsigned int a, unsigned int b);
    //unsigned int prixTotal();
    void setNomClient(std::string c);
    std::string getNomClient();

    private:
        ///ATTRIBUTS
    std::string m_nomClient;
    unsigned int m_qteRepas[5];
    unsigned int m_prix[5];


};


#endif // COMMANDE_H_INCLUDED
