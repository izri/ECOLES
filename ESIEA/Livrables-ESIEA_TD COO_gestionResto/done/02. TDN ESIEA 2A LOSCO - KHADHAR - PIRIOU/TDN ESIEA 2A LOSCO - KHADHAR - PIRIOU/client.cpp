#include "client.hpp"
#include "vector"
#include <iostream>
#include <string>

using namespace std;

Client::Client(const string first_name, const string last_name, const float gender)
    : first_name(first_name), last_name(last_name), gender(gender) {}
const string Client::get_first_name()
{
    return first_name;
}
const string Client::get_last_name()
{
    return last_name;
}
const bool Client::get_gender()
{
    return gender;
}
const string Client::to_string()
{
    return first_name + " " + last_name;
}

void Client::affichage()
{

    if(gender == 0) cout << to_string() << "   Homme" << endl;
    else cout << to_string() << "   Femme" << endl;

}








