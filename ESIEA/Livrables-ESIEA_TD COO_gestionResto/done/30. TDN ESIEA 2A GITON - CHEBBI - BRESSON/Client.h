#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Commande.h"

class Client {
public:
    Client();
    void afficher(std::ostream &flux) const;
    unsigned int getIdClient() const;
    void nouvelleCommande();
    void nouvelleVisite();
private:
    unsigned int m_idClient;
    std::vector<Commande> m_histoCommandes;
    std::vector<std::string> m_histoVisites;
    double m_meilleurAddition;
};

std::ostream& operator<<(std::ostream &flux, Client const& client);

#endif // CLIENT_H_INCLUDED
