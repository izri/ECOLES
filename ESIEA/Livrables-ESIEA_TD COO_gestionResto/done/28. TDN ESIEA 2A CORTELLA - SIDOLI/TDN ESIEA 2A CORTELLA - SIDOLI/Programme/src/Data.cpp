#include "restaurant.hh"

using namespace	std;

Data::Data()
{

}

void		Data::newClient()
{
  string	name;
  string	first_name;
  string	tel;
  string	mail;
  Client	*cl;

  cout << endl << "|\tNew customer\t|" << endl;
  cout << "Name: ";
  getline(cin, name);
  cout << "First name: ";
  getline(cin, first_name);
  cout << "Telephone: ";
  getline(cin, tel);
  cout << "Mail: ";
  getline(cin, mail);
  cl = new Client(name, first_name, tel, mail);
  _history.addClient(cl);
}

void		Data::help()
{
  cout << endl << "**\tWelcome to the administration panel\t**" << endl << endl;
  cout << "List of available commands:" << endl << endl;
  cout << "\tnew client:\t\tadd a new customer in the database" << endl;
  cout << "\tdisplay clients:\tdisplay all the client saved" << endl;
  cout << "\thelp:\t\t\tdisplay this help" << endl << endl;
}

void		Data::display()
{
  _history.dump();
}

Data::~Data()
{

}
