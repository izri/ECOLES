#include <iostream>
#include "Client.hpp"
#include <iomanip>

using namespace std;

// Constructeur
Client::Client(){

}

Client::Client(string n, string t, string e, short int a){
    nom=n;
    tel=t;
    email=e;
    age=a;
}


void Client::set_nom(string n){
    nom=n;
}

void Client::set_tel(string t){
    tel=t;
}

void Client::set_age(short int a){
    age=a;
}

void Client::set_email(string e){
    email=e;
}

string Client::get_nom(){
    return nom;
}
string Client::get_tel(){
    return tel;
}
short int Client::get_age(){
    return age;
}
string Client::get_email(){
    return email;
}
unsigned int Client::get_id(){
    return id;
}

Client * Client::next(){
    if(this!=NULL)
        return this->suiv;
    else
        return NULL;
}

Client * Client::last(){
    if(this!=NULL){
        if(this->suiv!=NULL)
            this->last();
        return this;
    }
    else return NULL;
}

void Client::new_client()
{
    int length, i, nb=0;
    int val_id=1;
    Client * cour= new Client;

    if(this==NULL){
        this = cour;
    }
    else{
        this->last()=cour;
    }


    cout << "Entrez le nom du nouveau Client : ";
    getline(cin, cour->nom);

    do
    {
        cout << "Entrez le numero de telephone : ";
        getline(cin, cour->tel);
        if(cour->tel.length()!=10)
        {
            cout << "Numero de telephone non valide\n" << endl;
        }
    }
    while(cour->tel.length()!=10);


    do{
        cout << "Entrez l'email du nouveau Client : ";
        cin >> cour->email;

        length=cour->email.length();
        for(i=0; i<length; i++){
            if(cour->email[i]=='@') nb++;
        }
    }while(nb!=1);

    cout << "Entrez l'age du Client (-1 si N/C) : ";
    cin >> cour->age;
    cour->suiv=NULL;

    cour->show_client();
}


void Client::show_client(){
    cout << "|" << endl;
    cout << "+- Client #" << setfill('0') << setw(5) << this->id << endl;
    cout << "+--- Nom : " << this->nom << endl;
    cout << "+--- Tel : " << this->tel << endl;
    cout << "+--- Age : " << setfill('0') << setw(2) << this->age << endl;
}
