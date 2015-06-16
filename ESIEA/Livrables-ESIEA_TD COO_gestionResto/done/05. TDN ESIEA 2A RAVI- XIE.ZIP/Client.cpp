/*#include <string>
#include <iostream>

#include "Client.h"

using namespace std;

Client::Client() : m_nom(""),m_adresse(""),m_prenom(""),m_telephone("")
{

}

Client::Client(string c,int nbPersonne) : m_nom(""),m_adresse(""),m_prenom(""),m_telephone("")
{

}

void Client::afficher()
{
    cout << "Quel est votre nom ?" << endl;
    //cin >> m_nom;
    getline(cin,m_nom);

    cout << "Quel est votre prenom ?" << endl;
    //cin >> m_prenom;
    getline(cin,m_prenom);

    cout << "Quel est votre adresse ?" << endl;
    //cin >> m_adresse;
    getline(cin,m_adresse);

    cout << "Quel est votre numero de telephone ?" << endl;
    //cin >> m_telephone;
    getline(cin,m_telephone);

    cout << " " << endl;
    cout << "Mon nom : " << m_nom << endl;
    cout << "Mon prenom : " << m_prenom << endl;
    cout << "Mon adresse : " << m_adresse << endl;
    cout << "Mon telephone : " << m_telephone << endl;
    cout << " " << endl;
}

bool Client::faireCommande()
{
    cout << "Voulez-vous commander ? " << endl;
    cout << "oui ou non" << endl;
    string reponse,oui;
    cin >> reponse;

    if(reponse == "oui")
    {
        cout << "Ah! Je suis ravi de voir que mes plats, vous plaise ! " <<endl;
        return true;
    }
    else{
        cout << "Quel dommage !" << endl;
    return false;

    }



}*/


#include <string>
#include <iostream>

#include "Client.h"

using namespace std;

Client::Client() : m_nom(""),m_adresse(""),m_prenom(""),m_telephone("")
{

}

Client::Client(string c,int nbPersonne) : m_nom(""),m_adresse(""),m_prenom(""),m_telephone("")
{

}

void Client::afficher()
{

    cout << "--------------------------------------------------------------------------------" << endl;
    //cin >> m_nom;
    getline(cin,m_nom);
    cout << "Nom du client:" << endl;
    //cin >> m_nom;
    getline(cin,m_nom);

    cout << "Prenom du client:" << endl;
    //cin >> m_prenom;
    getline(cin,m_prenom);

    cout << "Adresse du client: " << endl;
    //cin >> m_adresse;
    getline(cin,m_adresse);

    cout << "Numero de telephone du client: " << endl;
    //cin >> m_telephone;
    getline(cin,m_telephone);

    cout << " " << endl;
    cout << "--------------------------------INFORMATION CLIENT------------------------------" << endl;

    cout << " Nom : " << m_nom << endl;
    cout << " Prenom : " << m_prenom << endl;
    cout << " Adresse : " << m_adresse << endl;
    cout << " Telephone : " << m_telephone << endl;
        cout << "--------------------------------------------------------------------------------" << endl;

    cout << " " << endl;
}

/*bool Client::faireCommande()
{
    cout << "Voulez-vous commander ? " << endl;
    cout << "oui ou non" << endl;
    string reponse,oui;
    cin >> reponse;

    if(reponse == "oui")
    {
        cout << "Ah! Je suis ravi de voir que mes plats, vous plaise ! " <<endl;
        return true;
    }
    else{
        cout << "Quel dommage !" << endl;
    return false;

    }



}*/








