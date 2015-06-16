#include <iostream>
#include <string>

#include "resto.hpp"
#include "client.hpp"
#include "product.hpp"
#include "command.hpp"
#include "Historique.hpp"
#include "Carte.hpp"



const string Printable::to_string() {
	const type_info &t = typeid(this);
	return t.name();
}

	
ostream& operator<<(ostream& s, Client c) { return s << c.to_string(); }
ostream& operator<<(ostream& s, Product o) { return s << o.to_string(); }
ostream& operator<<(ostream& s, Command o) { return s << o.to_string(); }


int main() {
	
	int PtFidelite;
	Client jane("Nathan", "k-rond", true);
	Client john("Zazou", "Zazou", false);
	Product pizza("Pizza", 10.00);
	Product chianti("Chianti classico", 10.00);
	Command cmd_nathan_pizza(nathan, pizza), cmd_zazou_chianti(zazou, chianti);
	Historique htr_nathan_comd(cmd_nathan_pizza), htr_zazou_comd(cmd_zazou_chianti);
	Carte NbPtNathan(cmd_nathan_pizza,PtFidelite);
	Carte NbPtZazou(cmd_zazou_chianti,PtFidelite);

	cout << Nathan << endl;
	cout << Zazou << endl;
	cout << pizza << endl;
	cout << chianti << endl;
	cout << cmd_nathan_pizza << endl;
	cout << cmd_zazou_chianti << endl;
	cout << NbPtNathan << endl;
	cout << NbPtZazou << endl;

	cout << Pizza("Regina") << endl;
}

