#include "Client.h"

using namespace std;

Client::Client() {
    cout << endl << "============== NOUVEAU CLIENT ==============" << endl << endl;

    m_meilleurAddition = 0;

    cout << "Numero client : ";
    cin >> m_idClient;

    int input;

    do {
        cout << endl << "Ajouter une visite (1 : OUI, 2 : NON) ? ";
        cin >> input;
    } while(input != 1 && input != 2);

    if(input == 1) {
        cout << endl << "Visite le (JJ/MM/AAAA) : ";
        string inputString;
        cin >> inputString;
        m_histoVisites.push_back(inputString);
    }

    do {
        cout << endl << "Ajouter une commande (1 : OUI, 2 : NON) ? ";
        cin >> input;
    } while(input != 1 && input != 2);

    if(input == 1) {
        Commande nouvelleCommande;
        m_histoCommandes.push_back(nouvelleCommande);
        if(nouvelleCommande.getAddition() > m_meilleurAddition)
            m_meilleurAddition = nouvelleCommande.getAddition();
    }
}

void Client::afficher(ostream &flux) const {
    flux << endl << "######### FICHE CLIENT #########" << endl << endl << "ID Client : " << m_idClient << endl;

    flux << endl << "Historique des visites : " << endl;

    for(unsigned int i(0); i < m_histoVisites.size(); i++)
            flux << "- " << m_histoVisites[i] << endl;

    flux << endl << "Historique des commandes : " << endl << endl;

    for(unsigned int i(0); i < m_histoCommandes.size(); i++)
            flux << m_histoCommandes[i];

    flux << endl << "Addition la plus elevee : " << m_meilleurAddition << endl;
}

unsigned int Client::getIdClient() const {
    return m_idClient;
}

void Client::nouvelleCommande() {
    Commande nouvelleCommande;

    if(nouvelleCommande.getAddition() > m_meilleurAddition)
        m_meilleurAddition = nouvelleCommande.getAddition();

    m_histoCommandes.push_back(nouvelleCommande);
}

void Client::nouvelleVisite() {
    cout << endl << "Visite le (JJ/MM/AAAA) : ";
    string inputString;
    cin >> inputString;
    m_histoVisites.push_back(inputString);
}

ostream& operator<<(ostream &flux, Client const& client) {
    client.afficher(flux);
    return flux;
}
