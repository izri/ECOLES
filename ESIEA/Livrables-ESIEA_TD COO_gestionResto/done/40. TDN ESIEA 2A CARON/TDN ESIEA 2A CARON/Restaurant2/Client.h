#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

#include <string>
#include <iostream>



class Client
{

    private:
        std :: string m_lastName, m_firstName;
        bool m_genre;


    public:
        //Client ();
        Client(std :: string const firstName, std :: string const lastName, bool const genre = 0);
        std :: string getFirstName ()const;
        std :: string getLastName ()const;
        bool getGenre () const;
        void demander ();
        void afficher ()const;

};


Client setClient ();
std :: ostream &operator<<(std :: ostream& flux, Client const& client);


#endif // CLIENT_H_INCLUDED
