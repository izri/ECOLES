#ifndef COORDONNEE_HPP
#define COORDONNEE_HPP

#include "resto.hpp"

using namespace std;

class Coordonnees : public Printable {
	private :
        string mail, tel, street, city;
        int num_street, zip_code;
	public :
		Coordonnees(string mail, string tel, string street, int num_street, string city, int zip_code);
		string get_mail();
		string get_tel();
		string get_street();
		int get_num_street();
		string get_city();
		int get_zip_code();
		//const string to_string();
		void print();
		void modify();
};

#endif // COORDONNEE_HPP

