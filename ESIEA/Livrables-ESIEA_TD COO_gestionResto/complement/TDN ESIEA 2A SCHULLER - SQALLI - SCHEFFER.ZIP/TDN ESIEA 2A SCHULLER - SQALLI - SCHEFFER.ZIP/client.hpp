#ifndef CLIENT_HPP
#define CLIENT_HPP
#include "resto.hpp"

using namespace std;

class Client : public coupon
{
private :
    string prenom, nom;
    bool sex;
public :
    Client(const string prenom, const string nom, const float sex);
    const string get_prenom();
    const string get_nom();
    const bool get_sex();
    const string to_string();
    void affichage();
};
#endif // CLIENT_HPP



