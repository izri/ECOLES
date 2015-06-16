#include <string>
#include <iostream>

#include "Dessert.h"

using namespace std;

Dessert::Dessert() : m_froid("")
{

}

Dessert::Dessert(string c) : m_froid("")
{

}

void Dessert::gele()
{
    cout << "Voulez vous un dessert bien froid ?" << endl;
    string reponse,yes;
    cin >> reponse;
    if(reponse == "yes")
    {
        cout << "Rentrez votre niveau de froideur :" << endl;
        cout << "1. 2. 3. 4. 5." << endl;
        cin >> m_froid;
        cout << " " << endl;
        cout << "Mon niveau de fraicheur est de : " << m_froid << endl;
    }
    else
    {
        cout << "Prenez votre temps ! Il fait tellement chaud ! " << endl;
    }

}

