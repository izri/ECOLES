#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "resto.hpp"

using namespace std;

class Client : public Printable {
	private :
		string first_name, last_name;
		bool gender;
	public :
		Client(const string first_name, const string last_name, const float gender);
		const string get_first_name();
		const string get_last_name();
		const bool get_gender();
		const string to_string();
};

#endif // CLIENT_HPP