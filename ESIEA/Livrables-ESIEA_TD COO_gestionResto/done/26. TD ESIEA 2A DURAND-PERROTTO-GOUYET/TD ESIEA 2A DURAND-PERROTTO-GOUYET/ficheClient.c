#include "ficheClient.h"
#include "vector"
#include <iostream>
#include <string>

using namespace std;

Client::Client(const string prenom, const string nom, const float genre)
    : prenom(prenom), nom(nom), genre(genre) {}

const string Client::get_prenom()
{
    return prenom;
}
const string Client::get_nom()
{
    return nom;
}
const bool Client::get_genre()
{
    return genre;
}
const string Client::to_string()
{
    return prenom + " " + nom;
}

void Client::affichage()
{

    if(genre == 0) cout << to_string() << "   Homme" << endl;
    else cout << to_string() << "   Femme" << endl;

}








