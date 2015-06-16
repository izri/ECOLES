#ifndef CLIENT_HPP_INCLUDED
#define CLIENT_HPP_INCLUDED


#include <iostream>
#include <string>
#include <cstring>

using namespace std;


class Client
{
    private:
        string nom;
        string tel;
        string email;
        short int age;
        unsigned int id;
        class Client * suiv;

    public :
        Client();
        Client(string n, string t, string e, short int a);


        void new_client();

        void set_nom(string n);
        void set_tel(string t);
        void set_age(short int a);
        void set_email(string e);

        string get_nom();
        string get_tel();
        short int get_age();
        string get_email();
        unsigned int get_id();


        Client * next();
        Client * last();

        void show_client();

        void show_all_client();
};


#endif // CLIENT_HPP_INCLUDED
