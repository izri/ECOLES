

#include <string>
#include <iostream>
#include "CarteFi.h"

using namespace std;

CarteFi::CarteFi() : m_fidelite()
{

}


void CarteFi::changeCarte()
{   string yes;
    int carte;
    cout << "le client possede t-il la carte de fidelite" << endl;
    cout << "1.oui 2.non" <<endl;

    cin >> carte;

    if(carte == 1)
    {
        cout << "Combien de point a le client sur la carte de fidelite ?" << endl;
    cout << "1. 2. 3. 4. 5. 6. 7. 8. 9. 10." << endl;
    int point;
    int reste;

    cin >> point;


    cout << "le client a: " << point << " point"<<endl;

    if(point == 10)
    {
        cout << " le client b�n�ficie d'un repas gratuit !" << endl;

    }else{
            reste= 10- point;
            cout << " le client aura un repas gratuit s'il revient " << reste <<" fois "<<endl;



    }
    }
    else
    {
        cout << "le client b�n�ficie d'une carte de fid�lit� " << endl;
        cout << "le client b�n�ficie de 1 point sur sa carte " << endl;

    }
}












