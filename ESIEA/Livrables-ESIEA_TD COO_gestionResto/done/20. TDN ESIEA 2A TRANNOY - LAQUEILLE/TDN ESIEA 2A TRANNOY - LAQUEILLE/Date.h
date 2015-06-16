#ifndef DATE_H
#define DATE_H
#include <string>
#include <iostream>

class Date
{
    public:
        Date(int jour, int mois, int annee);
        const int jour();
        const int mois();
        const int annee();
        void affichage();

    private:
        int m_jour,m_mois,m_annee;
};

#endif // DATE_H
