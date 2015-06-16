#ifndef CLIENT_HPP
#define CLIENT_HPP
#include <iostream>
#include <string>

using namespace std;


class Client {
	private :
		string first_name, last_name;
	public :
		Client(const string first_name, const string last_name);
		const string get_first_name();
		const string get_last_name();
		const string to_string();
		void print();
};
#endif