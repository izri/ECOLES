#include "Client.h"

using namespace std;


string getNomClient() const
{
    return m_NomClient;
}

int getPointDeFidelites() const
{
    return m_PointDeFidelites;
}

int getTotalDepense() const
{
    return m_TotalDepens�;
}

int Client::estNouveau(int PointsDeFidelites)
{
       m_PointDeFidelites=PointsDeFidelites+1;
}

void Client::Nouvelle_Commande()
{
        m_TotalDepens�=m_TotalDepens�+m_Commande.getPrixCommande();
}

void Client::InviterAutreClient(Client &invite,std::string NomClientInvite)
{
    invite.getNomeClient()=NomClientInvite;
    invite.estNouveau(invite.getPointDeFidelite);
    m_nbDePersonnesInvitees+=1;
}

Client::Client()
{
    m_NomClient="Mr Chouchou";
    m_PointDeFidelites=0;
    m_nbDePersonnesInvitees=0;
    m_PrixCommande=0;
    m_TotalDepense=0;
}
