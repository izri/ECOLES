#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

#include <string>

class Client
{
    std::string m_nom;
    std::string m_adresse;
    std::string m_prenom;
    std::string m_telephone;

    public:
        Client();
        Client(std::string c,int nbPersonne); /// permet d'avoir plus de client !

        /*
        Affiche les informations sur le client
        un petit probleme avec getline -> !!!!
        */
        void afficher();
        bool faireCommande();


};

#endif // CLIENT_H_INCLUDED
