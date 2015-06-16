#include <string>
#include <iostream>
#include "PlatV.h"

using namespace std;

PlatV::PlatV() : m_legume()
{

}

PlatV::PlatV(string c, unsigned int legume) : m_legume()
{

}

unsigned int PlatV::ajoutLegume(unsigned int legume)
{
    cout << "Voulez vous des legumes en plus dans votre plat ? " << endl;
    cout << "----Choisissez votre niveau---- : " << endl;
    cout << " minimum 1. 2. 3. 4. 5. maximum" << endl;

    cin >> legume;
    if(legume < 3)
    {
        cout << "Vous n'aimez pas les légumes a ce que je vois !" << endl;
    }
    else{
        cout << " Miam ! J'adore la verdure ! " << endl;
    }
    return legume;
}










