#include "Client.h"

Client::Client()
{
      this->NomClient="inconnu";
      this->adresse="inconnu";
      this->tel=0;
      this->IDclient=0;


}

void Client::SetNomclient()
{
    std::cout<<"Entrer le nom du client"<<std::endl;
    std::cin>>this->NomClient;

}
void Client::Setadresse()
{std::cout<<"Entrer l'adresse  du client"<<std::endl;
    std::cin>>this->adresse;

}
std::string Client::getNomClient()
{


    return (this->NomClient);
}
std::string Client::getadresse()
{
    return (this->adresse);
}
void Client::InfoClient()
{

    std::cout<<"Entrer Numeros de telephone client"<<std::endl;
    std::cin>>this->tel;
    std::cout<<"Entrer ID client"<<std::endl;
    std::cin>>this->IDclient;
}
