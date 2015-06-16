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
	public :
		Command(Client client, Product product);
		const Client get_client();
		const Product get_product();
		const string to_string();
};

#endif // COMMAND_HPP