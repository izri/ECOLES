#include "client.h"
#include <iostream>
#include <string>

using namespace std;

Client::Client(string first_name,  string last_name, int age, int telNum) : m_first_name(first_name), m_last_name(last_name),m_age(age), m_tel_num(telNum) {

}

const string Client::get_first_name() {
    return  m_first_name;
}

const string Client::get_last_name() {
    return m_last_name;
}

const int Client::getAge() {
    return m_age;
}

const int Client::getTelNum() {
    return m_tel_num;
}



void Client::affichage(){

    cout << "Nom : " << m_last_name << endl;
    cout << "Prenom : " << m_first_name << endl;
    cout << "Age : " << m_age << endl;
    cout << "Telephone : " <<  m_tel_num << endl;

}


