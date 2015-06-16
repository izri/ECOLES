#include <iostream>
#include <string>
#include <typeinfo>

#include "resto.hpp"
#include "client.hpp"
#include "product.hpp"
#include "command.hpp"

using namespace std;


int main() {
    Coordonnees contactjane("Jane@toto.com", "0326010203", "Avenue de Champagne", 1,"Epernay", 51200);
    Coordonnees contactjohn("John@toto.com", "0326010203", "Avenue de Champagne", 1,"Epernay", 51200);
    Client jane("Jane", "DOE", true, contactjane);
	Client john("John", "DOE", false, contactjohn);
	Product pizza("Pizza", 10.00);
	Product chianti("Chianti classico", 10.00);
	Command cmd_jane_pizza(jane, pizza), cmd_john_chianti(john, chianti);

	char choice;

	cmd_jane_pizza.print();
	cmd_john_chianti.print();

    cout << "Modify first command ? (y/n)" << endl;
    cin>> choice;
    if(choice == 'y' || choice == 'Y')
    {
        cout << "Modify the informations of the client ? (y/n)" << endl;
        cin>> choice;
        if(choice == 'y' || choice == 'Y')
    {
        jane.modify();
    }
        cout << "Modify the informations of the contact ? (y/n)" << endl;
        cin>> choice;
        if(choice == 'y' || choice == 'Y')
    {
        contactjane.modify();
    }

        cout << "Modify the informations of the product ? (y/n)" << endl;
        cin>> choice;
        if(choice == 'y' || choice == 'Y')
    {
        pizza.modify();
    }
    }

    jane.print();
    contactjane.print();
    pizza.print();

    cout << "Modify second command ? (y/n)" << endl;
    cin>> choice;
    if(choice == 'y' || choice == 'Y')
    {
        cout << "Modify the informations of the client ? (y/n)" << endl;
        cin>> choice;
        if(choice == 'y' || choice == 'Y')
    {
        john.modify();
    }
        cout << "Modify the informations of the contact ? (y/n)" << endl;
        cin>> choice;
        if(choice == 'y' || choice == 'Y')
    {
        contactjohn.modify();
    }

        cout << "Modify the informations of the product ? (y/n)" << endl;
        cin>> choice;
        if(choice == 'y' || choice == 'Y')
    {
        chianti.modify();
    }
    }

    john.print();
    contactjohn.print();
    chianti.print();
}













