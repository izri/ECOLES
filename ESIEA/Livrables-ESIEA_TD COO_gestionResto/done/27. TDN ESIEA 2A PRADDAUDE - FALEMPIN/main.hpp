#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <typeinfo>

using namespace std;

template <typename T> string tostr(const T& t)
{
   ostringstream os;
   os<<t;
   return os.str();
}

class Printable
{
	public :
		const string to_string();
		void print()
		{
		    cout << to_string() << endl;
        }
};

#endif // MAIN_HPP
