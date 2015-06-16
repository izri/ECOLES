#include "date.h"

using namespace std;

Date::Date(int jour, int mois, int annee) : m_jour(jour), m_mois(mois),m_annee(annee) {

}

const int Date::Askjour() {
    return  m_jour;
}

const int Date::Askmois() {
    return  m_mois;
}

const int Date::Askannee() {
    return  m_annee;
}

const void Date::afficher() {

    cout << m_jour << "/" << m_mois << "/" << m_annee << endl;

}

