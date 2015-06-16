#ifndef DEF_CLIENT
#define DEF_CLIENT

#include <iostream>
#include<string>
#include "Commande.h"

class Client
{

    public:

    Client();
    string getNomClient() const;
    int getPointDeFidelites() const;
    int getTotalDepense() const;
    int estNouveau(int PointsDeFidelites);
    void Nouvelle_Commande();
    void InviterAutreClient(Client &invite, std::string NomClient, int PointDeFideliteInvite);

    private:

    std::string m_NomClient;
    int m_PointDeFidelites;
    int m_nbDePersonnesInvitees;
    Commande m_Commande;
    int m_TotalDepense;

};

#endif
