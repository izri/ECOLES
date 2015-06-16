#include "Client.h"



using namespace std;

Client :: Client(string const firstName, string const lastName, bool const genre) :
    m_firstName(firstName), m_lastName(lastName), m_genre(genre) {}

string Client :: getFirstName ()const
{
    return m_firstName;
}

string Client :: getLastName ()const
{
    return m_lastName;
}


bool Client :: getGenre ()const
{
    return m_genre;
}


void Client :: afficher()const
{
    if (m_genre == 0)
        cout << "Monsieur ";          // si m_genre = 0 Alors le client est un homme => on affiche monsieur
    else
        cout << "Madame ";              // sinon Madame
    cout << m_firstName <<" "<< m_lastName <<endl;
}




Client setClient ()                                   // Pas mis dans le main mais fonctionnel
{
    string firstName, lastName;
    bool genre;
    int a (3);

    while (a != 2 && a != 1)
    {
        cout << " 1- Homme\n 2- Femme\n>";
        cin >> a;    // On demande le genre
    }

    genre = a +  1;
    cout << "Prenom :" << endl;
    cin >> firstName;  //On rentre le prénom
    cout << "Nom :" << endl;
    cin >> lastName;   //On rentre le nom

    Client client(firstName, lastName, genre);
    return client;
}



