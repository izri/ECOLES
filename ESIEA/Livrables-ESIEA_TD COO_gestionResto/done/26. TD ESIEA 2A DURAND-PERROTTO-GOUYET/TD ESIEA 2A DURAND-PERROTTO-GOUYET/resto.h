#ifndef RESTO_H
#define RESTO_H

#include <iostream>
#include <string>

using namespace std;

class Printable
{
public :
    const string to_string();
    void print()
    {
        cout << to_string() << endl;
    }
};

#endif // RESTO_H
