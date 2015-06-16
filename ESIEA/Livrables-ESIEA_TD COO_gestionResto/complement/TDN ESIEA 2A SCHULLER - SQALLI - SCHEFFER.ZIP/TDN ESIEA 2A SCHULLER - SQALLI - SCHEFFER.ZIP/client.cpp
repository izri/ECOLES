#include "client.hpp"
#include "vector"
#include <iostream>
#include <string>

using namespace std;

Client::Client(const string first_name, const string prenom, const float sex)
    : first_name(first_name), prenom(prenom), sex(sex) {}
	void Client::affichage()
{

    if(sex == 0) cout << to_string() << "   Homme" << endl;
    else cout << to_string() << "   Femme" << endl;

}

const string Client::get_nom()
{
    return first_name;
}
const string Client::get_prenom()
{
    return prenom;
}
const bool Client::get_sex()
{
    return sex;
}
const string Client::to_string()
{
    return nom + " " + prenom;
}







