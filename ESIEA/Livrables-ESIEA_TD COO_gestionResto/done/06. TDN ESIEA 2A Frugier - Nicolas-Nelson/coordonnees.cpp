#include "coordonnees.hpp"

using namespace std;

Coordonnees::Coordonnees(string mail, string tel, string street, int num_street, string city, int zip_code)
: mail(mail), tel(tel), street(street), num_street(num_street), city(city), zip_code(zip_code) {}

string Coordonnees::get_mail()
{
    return mail;
}

string Coordonnees::get_tel()
{
    return tel;
}

string Coordonnees::get_street()
{
    return street;
}
int Coordonnees::get_num_street()
{
    return num_street;
}
string Coordonnees::get_city()
{
    return city;
}
int Coordonnees::get_zip_code()
{
    return zip_code;
}

void Coordonnees::print()
{
    cout<<"Mail : "<< this->get_mail()<< endl;
    cout<<"Phone number : "<< this->get_tel()<< endl;
    cout<<"Street: " << this->get_street()<< endl;
    cout<<"Num Street : "<< this->get_num_street()<< endl;
    cout<<"City : "<< this->get_city()<< endl;
    cout<<"Zip Code: " << this->get_zip_code()<< endl;
}

void Coordonnees::modify()
{
    char choice;

    cout<<"Change mail ? (y/n) : "<< this->get_mail()<< endl;
    cin>> choice;
    if(choice == 'y' || choice == 'Y')
    {
        cout<< "Enter the new "<<endl;
        cin>> this->mail;
    }

    cout<<"Change phone number ? (y/n) : "<< this->get_tel()<< endl;
    cin>> choice;
    if(choice == 'y' || choice == 'Y')
    {
        cout<< "Enter the new "<<endl;
        cin>> this->tel;
    }

    cout<<"Change street ? (y/n) : "<< this->get_street()<< endl;
    cin>> choice;
    if(choice == 'y' || choice == 'Y')
    {
        cout<< "Enter the new "<<endl;
        cin>> this->street;
    }

    cout<<"Change num street ? (y/n) : "<< this->get_num_street()<< endl;
    cin>> choice;
    if(choice == 'y' || choice == 'Y')
    {
        cout<< "Enter the new "<<endl;
        cin>> this->num_street;
    }

    cout<<"Change city ? (y/n) : "<< this->get_city()<< endl;
    cin>> choice;
    if(choice == 'y' || choice == 'Y')
    {
        cout<< "Enter the new "<<endl;
        cin>> this->city;
    }

    cout<<"Change zip code ? (y/n) : "<< this->get_zip_code()<< endl;
    cin>> choice;
    if(choice == 'y' || choice == 'Y')
    {
        cout<< "Enter the new "<<endl;
        cin>> this->zip_code;
    }
}

