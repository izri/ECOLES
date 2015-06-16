#ifndef CLASSCOMMANDE_HPP
#define CLASSCOMMANDE_HPP
#include <iostream>
#include <string>
#include <vector>
#include "classproduit.hpp"
#include <windows.h>



class commande
{
public :
	string date;
	vector <produits> liste;
	commande(produits premier,string anne);
	commande(string anne);
	int total();
	void afficherCMD();
	void ajouterpo(produits a);
};

#endif