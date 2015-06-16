#include <iostream>
#include <string>
#include "classclients.hpp"
#include <windows.h>

using namespace std;



client::client(string nom)
{
	name = nom;
	recette = 0;
	frequence = 0;
}



client::client(std::string nom, int freq, int prix)
{
	name = nom;
	recette = prix;
	frequence = freq;
}


void client::print_cl() const
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	cout << "\nClient : ";
	SetConsoleTextAttribute(hConsole, 12);
	cout << name;
	SetConsoleTextAttribute(hConsole, 15);
	cout << " il est venu " << frequence << " fois et a depense "<< recette << " euros" << endl;
}


