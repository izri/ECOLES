#include <iostream>
#include <string>
#include <vector>
#include "command.hpp"
#include "client.hpp"
#include "product.hpp"

using namespace std;


Command::Command(const int number, Client client) : number(number), client(client){
	somme=0;
}
const int Command::get_number(){ return number; }
const Client Command::get_client() { return client; }
const vector<Product> Command::gt_products(){ return products;}
void Command::append(Product p) {
	products.push_back(p);
	somme+=p.get_price();
}
void Command::print() {
	vector<Product>::iterator it;
	cout << "Command n°: " << number << endl;
	cout << "client: " << client.to_string() << endl;
	for (it=products.begin(); it<products.end(); it++)
		cout << "-" << it->to_string() << endl;
	cout <<"Prix total " << somme << "€"<< endl;
}
