#ifndef COMMAND_H
#define COMMAND_H
#include <string>
#include <iostream>
#include "Client.h"
#include "Product.h"
#include "Date.h"

class Command
{

	public :
		Command(Client client, Product product, Date date, float prixTotal);

		const Client getClientInfos();
		const int getJour();
		const int getMois();
		const int getAnnee();
		const Product getProd();
		const float totalPrice();
		void affichage();

    private :
		Client m_client;
		Product m_product;
		Date m_date;
		float m_total;
};

#endif // COMMAND_HPP
