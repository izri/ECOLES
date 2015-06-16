#ifndef COMMANDE_H_INCLUDED
#define COMMANDE_H_INCLUDED

#include <iostream>
#include <string>

class Commande {
public :
    Commande();
    void afficher(std::ostream &flux) const;
    double getAddition() const;
private :
    std::string m_date;
    std::string m_plat;
    std::string m_autre;
    double m_addition;
};

std::ostream& operator<<(std::ostream &flux, Commande const& commande);

#endif // COMMANDE_H_INCLUDED
