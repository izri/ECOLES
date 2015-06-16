#ifndef COMMAND_HPP
#define COMMAND_HPP
#include <iostream>
#include <string>
#include <vector>
#include "client.hpp"
#include "product.hpp"
using namespace std;


class Command {
	private :
		int number;
		Client client;
		vector<Product> products;
		float somme;
	public :
	Command(const int number, Client client);
		const int get_number();
		const Client get_client();
		const vector<Product> gt_products();
		void append(Product p);
		void print();
};

#endif