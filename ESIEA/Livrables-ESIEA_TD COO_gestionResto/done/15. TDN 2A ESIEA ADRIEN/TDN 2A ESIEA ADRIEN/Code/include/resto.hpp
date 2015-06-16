
#ifndef RESTO_HPP
#define RESTO_HPP

#include <iostream>
#include <string>

using namespace std;

typedef struct node{
struct node *succ;
struct node *prec;
float sum;
int IdClient;

}node;

typedef struct node *liste;

class Printable {
	public :
		const string to_string();
		void print() { cout << to_string() << endl; }
};

#endif // RESTO_HPP
