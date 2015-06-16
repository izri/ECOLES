#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "resto.hpp"
#include "coordonnees.hpp"

using namespace std;

class Client : public Printable {
	private :
		string first_name, last_name;
		bool gender;
		Coordonnees contact;
	public :
		Client(const string first_name, const string last_name, bool gender, Coordonnees contact);
		const string get_first_name();
		const string get_last_name();
		const string get_gender();
		//const string to_string();
		void print();
		void modify();
};

#endif // CLIENT_HPP
