#ifndef CLASSCLIENTS_HPP
#define CLASSCLIENTS_HPP
#include <iostream>
#include <string>
#include <vector>
#include "classcommande.hpp"
#include <windows.h>

using namespace std;


class client
{
	public :
	    int recette;
		int frequence;
	    string name;
	    vector <commande> historisque;
		//methodes
		client(string nom);
		client(std::string nom,int freq, int prix);
		void print_cl() const;
};



#endif
