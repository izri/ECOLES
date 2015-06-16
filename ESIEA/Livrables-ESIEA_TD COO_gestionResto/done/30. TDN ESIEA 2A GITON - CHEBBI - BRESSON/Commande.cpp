#include "Commande.h"

using namespace std;

Commande::Commande() {
    cout << endl << "-------- NOUVELLE COMMANDE -----------" << endl << endl;
    cout << "Entrez la date de la commande (JJ/MM/AAAA) : ";
    cin >> m_date;

    int input;

    do {
        cout << endl << "Entrez le plat : " << endl << "0 : Rien" << endl << "1 : Pizza" << endl << "2 : Plat du jour" << endl << "3 : Plat vegetarien" << endl;
        cout << endl << "Le plat : ";
        cin >> input;
    } while(input < 0 || input > 3);

    switch(input) {
    case 0 :
        m_plat = "Rien";
    case 1 :
        m_plat = "Pizza";
        break;
    case 2 :
        m_plat = "Plat du jour";
        break;
    case 3 :
        m_plat = "Plat vegetarien";
        break;
    }

    do {
        cout << endl << "Entrez un complement au plat : " << endl << "0 : Rien" << endl << "1 : Dessert" << endl << "2 : Boisson" << endl;
        cout << endl << "Le complement : ";
        cin >> input;
    } while(input < 0 || input > 2);

    switch(input) {
    case 0 :
        m_autre = "Rien";
    case 1 :
        m_autre = "Dessert";
        break;
    case 2 :
        m_autre = "Boisson";
        break;
    }

    cout << endl << "Entrez l'addition (en euros) : ";
    cin >> m_addition;
}

double Commande::getAddition() const {
    return m_addition;
}

void Commande::afficher(ostream &flux) const {
    flux << endl << "****** COMMANDE ******" << endl << "Date : " << m_date << endl << "Plat : " << m_plat;
    flux << endl << "Complement : " << m_autre << endl << "Total : " << m_addition << " euros" << endl;
}

ostream& operator<<(ostream &flux, Commande const& commande) {
    commande.afficher(flux);
    return flux;
}
