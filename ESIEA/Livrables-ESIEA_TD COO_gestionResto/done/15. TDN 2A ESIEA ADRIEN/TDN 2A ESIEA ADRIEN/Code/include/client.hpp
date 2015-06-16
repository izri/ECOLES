#ifndef CLIENT_H
#define CLIENT_H

#include "resto.hpp"
#include <list>

using namespace std;

class Client : public Printable {
	private :
		string first_name, last_name;
		bool gender;
		const int age, frequence;
		const double expenses;
		const int IdClient; //C'est le numéro d'identifiant du client

	public :
		Client(const string first_name, const string last_name, const float gender, const int age,const int frequence, const double expenses, const int IdClient);
		const string get_first_name();
		const string get_last_name();
		const bool get_gender();
		const int get_age();
		const int get_frequence();
		const double get_expenses();
		const string to_string();
		const string TransformeEnString(int age);
		void HistoriqueClients(liste BestClients, Client client);



};


#endif // CLIENT_H
