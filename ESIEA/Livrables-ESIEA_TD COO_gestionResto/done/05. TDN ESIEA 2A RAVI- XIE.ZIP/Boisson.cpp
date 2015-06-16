#include <string>
#include <iostream>
#include "Boisson.h"

using namespace std;

Boisson::Boisson() : m_gazeux("coca"),m_nonGazeux(""),m_eau(""),m_jus(""),m_soda(""),m_alcool("")
{

}

Boisson::Boisson(string c, int nb) : m_gazeux(""),m_nonGazeux(""),m_eau(""),m_jus(""),m_soda(""),m_alcool("")
{

}

void Boisson::temperature()
{
    int degre;
    cout << "Voulez-vous une boisson froide ou chaude ? " << endl;
    cout << " Quel degre souhaitez-vous ? " <<endl;
    cin >> degre;
    if(degre < 10)
    {
        cout << "Votre boisson est gelee ! J'ai froid pour vous ! " << endl;
    }
    else
    {
        cout << "Votre boisson chaude arrive ! " << endl;
    }
}

void Boisson::choixBoisson()
{   cout << "---Choisissez votre boisson !--- " << endl;
    cout << "0.Boisson gazeuse" << endl;
    cout << "1.Boisson non gazeuse" << endl;
    cout << "2.Eau" << endl;
    cout << "3.Jus" << endl;
    cout << "4.Soda" << endl;
    cout << "5.Alcool" << endl;
    cout << "6.Non merci !" << endl;

    int numero;
    cin >> numero;

    int maBoisson(numero);

    switch(maBoisson)
    {
        case 0:
            cout << "Rentrez le nom de votre boisson " << endl;
            cin >> m_gazeux;
            //getline(cin,m_gazeux);
            cout << "Je prendrais " << m_gazeux << " ! " << endl;
            break;

        case 1:
            cout << "Rentrez le nom de votre boisson " << endl;
            cin >> m_nonGazeux;
            //getline(cin,m_nonGazeux);
            cout << "Je prendrais " << m_nonGazeux << " ! " << endl;
            break;

        case 2:
            cout << "Rentrez le nom de votre boisson " << endl;
            cin >> m_eau;
            cout << "Je prendrais " << m_eau << " ! " << endl;
            break;

        case 3:
            cout << "Rentrez le nom de votre boisson " << endl;
            cin >> m_jus;
            cout << "Je prendrais " << m_jus << " ! " << endl;
            break;

        case 4:
            cout << "Rentrez le nom de votre boisson " << endl;
            cin >> m_soda;
            cout << "Je prendrais " << m_soda << " ! " << endl;
            break;

        case 5:
            cout << "Rentrez le nom de votre boisson " << endl;
            cin >> m_alcool;
            cout << "Je prendrais " << m_alcool << " ! " << endl;
            break;

        default:
            cout << " Comment ? Prendriez-vous un cafe peut etre ? " << endl;
            break;


    }

}

