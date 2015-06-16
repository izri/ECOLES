#include "Client.h"
#include "Commande.h"
#include "Product.h"
using namespace std;
Commande::Commande()
{
this->NumCommande=0;
this->prixtotal=0;
}




unsigned int Commande::setcommande()
{
  this->NumCommande=Client.IDclient;
}

void Commande::progcommande()
{
    int i=0;int temp =0;int tab[5]={0};
    while(i==0)
    {

        temp=Product.Infoproduit();
        tab[temp]=tab[temp]+1;
        prixtotal=prixtotal+Product.prix[temp];
         std::cout<<"Avez vous fini de commander oui 1 non 0"<< std::endl;
         std::cin>>i;
    }
std::cout<<"Vous avez commandé "<<tab[0]<<"pizza, "<<tab[1]<<"PJ, "<<tab[2]<<"PV, "<<tab[3]<<"dessert et "<<tab[4]<<"boisson"<< std::endl;
 std::cout<<"Pour un coût total de "<<prixtotal<<"."<< std::endl;
}
