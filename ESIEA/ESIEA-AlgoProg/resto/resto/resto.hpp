#ifndef RESTO_HPP
#define RESTO_HPP

#include <iostream>
#include <string>

using namespace std;

class Printable {
	public :
		const string to_string();
		void print() { cout << to_string() << endl; }
};

#endif // RESTO_HPP