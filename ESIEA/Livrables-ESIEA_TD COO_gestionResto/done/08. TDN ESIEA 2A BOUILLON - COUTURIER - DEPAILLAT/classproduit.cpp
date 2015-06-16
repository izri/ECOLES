#include <iostream>
#include <string>
#include "classproduit.hpp"
#include <windows.h>

using namespace std;



produits::produits (string name,int prix)
{
	price = prix;
	P_name=name;
}


void produits::pirnt_P()
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "-";
    SetConsoleTextAttribute(hConsole, 10);
    cout << P_name;
    SetConsoleTextAttribute(hConsole, 15);
    cout << " : " << price << " euros\n";
}


pizza::pizza(string name) : produits(name,10) {}

vegeta::vegeta(std::string name) : produits(name,20) {}

jour::jour(std::string name) : produits(name,30) {}

boisson::boisson(std::string name) : produits(name,40) {}

dessert::dessert(std::string name) : produits(name,50) {}