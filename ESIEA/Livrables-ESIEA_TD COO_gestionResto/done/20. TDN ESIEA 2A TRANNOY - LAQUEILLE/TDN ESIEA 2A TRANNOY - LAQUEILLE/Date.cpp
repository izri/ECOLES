#include "Date.h"

using namespace std;

Date::Date(int jour, int mois, int annee) : m_jour(jour), m_mois(mois), m_annee(annee){

    }

const int Date::jour(){
    return m_jour;
}

const int Date::mois(){
    return m_mois;
    }

const int Date::annee(){
    return m_annee;
    }

void Date::affichage(){
    cout << "Date : " << m_jour << "/" << m_mois << "/" << m_annee << endl;
}
