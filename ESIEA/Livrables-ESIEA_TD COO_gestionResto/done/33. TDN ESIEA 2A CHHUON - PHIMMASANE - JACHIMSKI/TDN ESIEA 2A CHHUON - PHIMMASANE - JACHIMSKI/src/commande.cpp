#include "commande.h"


using namespace std;

Command::Command(Client client, Produit product, Date date) : m_client(client), m_product(product), m_date(date) {

}

/*Command::Command(Client client2) : m_client(client2) {

}

Command::Command(Produit product) :m_product(product) {

}
*/

const string Command::get_clientL(){
    return m_client.get_last_name();
}

const string Command::get_clientF(){
    return m_client.get_first_name();
}

const int Command::get_dateJ() {
    return m_date.Askjour();
}

const int Command::get_dateM() {
    return m_date.Askmois();
}

const int Command::get_dateA() {
    return m_date.Askannee();
}

const string Command::get_productN() {
    return m_product.get_name();
}

const int Command::get_productP() {
    return m_product.get_price();
}

/*int prixTotal {

}
*/

void Command::affiche() {

    cout << "Nom : " << get_clientL() << endl;
    cout << "Prenom : " << get_clientF() << endl;
    cout << "Date : " << get_dateJ() << "/" << get_dateM() << "/" << get_dateA() << endl;
    cout << "Voici votre commande : " << get_productN() << endl;
}
