#include "client.hpp"

using namespace std;

Client::Client(const string first_name, const string last_name, bool gender, Coordonnees contact)
: first_name(first_name), last_name(last_name), gender(gender), contact(contact) {}

const string Client::get_first_name()
{
    return first_name;
}

const string Client::get_last_name()
{
    return last_name;
}

const string Client::get_gender()
{
    if(gender==true)
    {
            return "Female";
    }
    else
    {
            return "Male";
    }
}
/*const string Client::to_string()
{
    return first_name + " " + last_name;
}*/

void Client::print()
{
    cout<<"First name : "<< this->get_first_name()<< endl;
    cout<<"Last name : "<< this->get_last_name()<< endl;
    cout<<"Gender : " << this->get_gender()<< endl;
    this->contact.Coordonnees::print();
}

void Client::modify()
{
    char choice;

    cout<<"Change first name ? (y/n) : "<< this->get_first_name()<< endl;
    cin>> choice;
    if(choice == 'y' || choice == 'Y')
    {
        cout<< "Enter the new "<<endl;
        cin>> this->first_name;
    }

    cout<<"Change last name ? (y/n) : "<< this->get_last_name()<< endl;
    cin>> choice;
    if(choice == 'y' || choice == 'Y')
    {
        cout<< "Enter the new "<<endl;
        cin>> this->last_name;
    }


    cout<<"Change gender ? (y/n) : " << this->get_gender()<< endl;
    cin>> choice;
    if(choice == 'y' || choice == 'Y')
    {
        gender = false;
    }
}
