#ifndef COMMAND_HPP
#define COMMAND_HPP
#include <string>
#include <iostream>
#include "client.h"
#include "produit.h"
#include "Date.h"

class Command
{

	public :
		Command(Client client, Produit product, Date date);
		Command(Client client2);
		Command(Produit product);


		const std::string get_clientL();
		const std::string get_clientF();
		const std::string get_productN();
		const int get_productP();
		const int get_dateJ();
		const int get_dateM();
		const int get_dateA();
		int prixTotal();
		void affiche();

    private :
		Client m_client;
		Produit m_product;
		Date m_date;
};

#endif // COMMAND_HPP
