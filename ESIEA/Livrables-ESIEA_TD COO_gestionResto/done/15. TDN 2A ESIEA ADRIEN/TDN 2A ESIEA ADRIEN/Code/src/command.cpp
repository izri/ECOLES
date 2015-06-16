#include "command.hpp"
#include <stdio.h>
using namespace std;

Command::Command(Client client, Product product, int nbproduits) : client(client), product(product), nbproduits(nbproduits) {}
const Client Command::get_client() { return client; }
const Product Command::get_product() { return product; }
const string Command::TransformeEnString(int numb)
{
char truc[256];
sprintf(truc,"%d",numb);
return truc;
}

//const string Command::get_date(string day, string month, string year){return "le: "+ day + "/" + month + "/" + year ;}

const string Command::to_string() { return TransformeEnString(nbproduits) + " " + product.to_string() + " - " + client.to_string(); }


/**const float Addition::addition(int nbproduits,  const float price){return nbproduits*price;}
const string Addition::to_string() { return "Addition " + TransformeEnString(addition(nbproduits,price)) + " " + date(day,month,year); }
**/
 //const float margetotal(int nbproduits, const float marge){return nbproduits*marge;}

