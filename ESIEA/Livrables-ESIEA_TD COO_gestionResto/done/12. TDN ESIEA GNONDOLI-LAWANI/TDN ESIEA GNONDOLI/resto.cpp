#include <iostream>
#include <string>

#include "resto.hpp"
using namespace std;



class Client {
	private :
		string first_name, last_name, type_client;
		bool gender;
	public :
		Client(const string first_name, const string last_name, const string type_client, const float gender)
		: first_name(first_name), last_name(last_name), type_client(type_client), gender(gender) {}
		const string get_first_name() { return first_name; }
		const string get_last_name() { return last_name; }
		const string get_type_client() { return type_client; }
		const bool get_gender() { return gender; }
		const string to_string() { return first_name + " " + last_name + " " +type_client; }
		void print() { cout << "Client : " << (gender ? "Ms " : "Mr ") << to_string() << endl; }
};

class Product {
	private :
		string name;
		float price;
	public :
		Product(const string name, const float price) : name(name), price(price) {}
		const string get_name() { return name; }
		const float get_price() { return price; }
		const string to_string() {
			string s_price = ::to_string(price);
			// il y a certainement plus élégant pour formater..
			s_price = s_price.substr(0, s_price.length() - 4); 
			return name + " (" + s_price + " EUR)";
		}
		void print() { cout << "Product : " << to_string() << endl; }
};

class Command {
	private :
		Client client;
		Product product;
	public :
		Command(Client client, Product product) : client(client), product(product) {}
		const Client get_client() { return client; }
		const Product get_product() { return product; }
		const string to_string() { return product.to_string() + " - " + client.to_string(); }
		void print() {
			cout << "Command : " << product.to_string();
			cout << " pour client " << client.to_string() << endl;
		}
};


int main() {

	cout << "RESTAURANT   PILKEV "  << endl	;
	cout << "Date   :27/04/15 "  << endl	;
	Client alice("alice", "BLONDE", "==>>DEPENSIER", true);
	Client duk("Duk", "BOUKAN", "==>>REGULIER", false);
	Product pizza("Pizza", 10.0);
	Product boisson("Boisson", 1.0);
	Product menustandard("menustandard", 10.0+1.0);
	Product riz("Riz Thai", 12.0);
	Product jusdepomme("jusdepomme", 3.5);
	Product meilleuresventes("meilleuresventes", 12.0+3.5);
	Command cmd_alice_pizza_boisson(alice, menustandard), cmd_john_riz_jusdepomme(duk, meilleuresventes);

	alice.print();
	duk.print();
	pizza.print();
	boisson.print();
	menustandard.print();	
	riz.print();
	jusdepomme.print();
	meilleuresventes.print();
	cmd_alice_pizza_boisson.print();
	cmd_john_riz_jusdepomme.print();
	//system("pause");
}