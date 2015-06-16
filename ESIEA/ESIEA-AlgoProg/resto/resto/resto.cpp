#include <iostream>
#include <string>
#include <typeinfo>

#include "resto.hpp"
#include "client.hpp"
#include "product.hpp"
#include "command.hpp"

using namespace std;

const string Printable::to_string() {
	const type_info &t = typeid(this);
	return t.name();
}

// Une friandise : la surcharge d'opérateurs !
ostream& operator<<(ostream& s, Client c) { return s << c.to_string(); }
ostream& operator<<(ostream& s, Product o) { return s << o.to_string(); }
ostream& operator<<(ostream& s, Command o) { return s << o.to_string(); }


int main() {

	Client jane("Jane", "DOE", true);
	Client john("John", "DOE", false);
	Product pizza("Pizza", 10.00);
	Product chianti("Chianti classico", 10.00);
	Command cmd_jane_pizza(jane, pizza), cmd_john_chianti(john, chianti);

	cout << jane << endl;
	cout << john << endl;
	cout << pizza << endl;
	cout << chianti << endl;
	cout << cmd_jane_pizza << endl;
	cout << cmd_john_chianti << endl;

	cout << Pizza("Regina", 10) << endl;
	return 0;
}













