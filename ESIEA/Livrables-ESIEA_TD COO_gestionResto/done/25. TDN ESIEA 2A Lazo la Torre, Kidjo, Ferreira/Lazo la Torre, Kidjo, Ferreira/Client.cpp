#include "Client.h"

using namespace std;

Client :: Client(string const firstName, string const lastName, bool const genr) :
    m_firstName(firstName), m_lastName(lastName), m_genr(genr) {}

string Client :: getFirstName ()const
{
    return m_firstName;
}

string Client :: getLastName ()const
{
    return m_lastName;
}

bool Client :: getGenr ()const
{
    return m_genr;
}

void Client :: afficher(ostream &flux)const
{
    if (m_genr == 0)
        cout << "Mr.";
    else
        cout << "Ms.";
    cout << m_firstName << " " << m_lastName << endl;
}

// Fonction
Client setClient ()
{
    string lastName, firstName;
    bool genr;
    int a (3);
    while (a != 2 && a != 1)
    {
        cout << "1- Homme\n2- Femme\n>";
        cin >> a;
    }
    genr = a + 1;
    cout << "Prenom :" << endl;
    cin >> firstName;
    cout << "Nom :" << endl;
    cin >> lastName;
    Client client(firstName, lastName, genr);
    return client;
}

ostream &operator<<(ostream& flux, Client const& client)
{
    client.afficher(flux);
    return flux;
}
