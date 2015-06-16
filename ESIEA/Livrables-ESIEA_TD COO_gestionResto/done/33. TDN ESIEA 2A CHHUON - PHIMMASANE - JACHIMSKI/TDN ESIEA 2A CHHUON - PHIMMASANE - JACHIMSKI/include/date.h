#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <string>

class Date
{
    public:
        Date(int jour, int mois, int annee);
        const int Askjour();
        const int Askmois();
        const int Askannee();
        const void afficher();
    private:
        int m_jour;
        int m_mois;
        int m_annee;
};

#endif // DATE_H
