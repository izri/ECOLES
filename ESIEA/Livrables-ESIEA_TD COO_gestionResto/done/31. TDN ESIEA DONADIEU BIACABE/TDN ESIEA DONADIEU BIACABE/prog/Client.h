#ifndef DEF_CLIENT
#define DEF_CLIENT
#include <string>
#include <iostream>

class Client
{
public:

Client();
void SetNomclient();
void Setadresse();
std::string getNomClient();
std::string getadresse();
void InfoClient();
std::string NomClient;
std::string adresse;
unsigned int tel;
unsigned int IDclient;
};


#endif // CLIENT_INCLUDED
