

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
        cout << " le client bénéficie d'un repas gratuit !" << endl;

    }else{
            reste= 10- point;
            cout << " le client aura un repas gratuit s'il revient " << reste <<" fois "<<endl;



    }
    }
    else
    {
        cout << "le client bénéficie d'une carte de fidélité " << endl;
        cout << "le client bénéficie de 1 point sur sa carte " << endl;

    }
}












