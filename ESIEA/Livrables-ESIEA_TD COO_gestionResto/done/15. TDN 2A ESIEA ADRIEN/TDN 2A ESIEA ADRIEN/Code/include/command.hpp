
#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "resto.hpp"
#include "client.hpp"
#include "product.hpp"

using namespace std;


class Command : public Printable {
	private :
		Client client;
		Product product;
		int nbproduits;
	public :
		Command(Client client, Product product, int nbproduits);
		const Client get_client();
		const Product get_product();
        const float margetotal(int nbproduits, const float marge);
        const string get_date(string day, string month, string year);
        const string TransformeEnString(int numb);
		const string to_string();
};
/**
class MeilleurClient : public Printable{

     private :  Client listeClients[500];
     public :  Client Historique(Client listeClients[500], int i);


};
**/
#endif // COMMAND_HPP
