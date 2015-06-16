#include "client.hpp"
#include <stdio.h>

using namespace std;

Client::Client(const string first_name, const string last_name, const float gender, const int age,const int frequence, const double expenses, const int IdClient)
: first_name(first_name), last_name(last_name), gender(gender), age(age), frequence(frequence), expenses(expenses), IdClient(IdClient) {}
const string Client::get_first_name() { return first_name; }
const string Client::get_last_name() { return last_name; }
const bool Client::get_gender() { return gender; }
const int Client::get_age() {return age;}
const int Client::get_frequence(){return frequence;}
const double Client::get_expenses() {return expenses;}
void Client::HistoriqueClients(liste BestClients, Client client) {
    //BestClients=malloc(sizeof(node));
	BestClients->sum=client.expenses;
	BestClients->IdClient=client.IdClient;
	//BestClients->succ = NULL;


}
// Une fr
/**const string Client::TransformeEnString(int entier)
{
char truc[256];
sprintf(truc,"%d",entier);

}**/
const string Client::TransformeEnString(int age)
{
char truc[256];
sprintf(truc,"%d",age);
return truc;
}

const string Client::to_string() { return first_name + " " + last_name + " " +  TransformeEnString(age) + " ans " + "nombre de venues : " + TransformeEnString(frequence) + " sommes dépensées " + TransformeEnString(expenses) + "€";}


