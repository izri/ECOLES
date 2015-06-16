#include "Command.h"

using namespace std;

Command::Command(Client client, Product product, Date date, float prixTotal) : m_client(client), m_product(product), m_date(date), m_total(prixTotal){

}

const Client Command::getClientInfos(){
    return m_client;
}

const int Command::getJour() {
    return m_date.jour();
}

const int Command::getMois() {
    return m_date.mois();
}

const int Command::getAnnee() {
    return m_date.annee();
}

const Product Command::getProd(){
    return m_product;
}


const float Command::totalPrice(){
    return m_total;
}


