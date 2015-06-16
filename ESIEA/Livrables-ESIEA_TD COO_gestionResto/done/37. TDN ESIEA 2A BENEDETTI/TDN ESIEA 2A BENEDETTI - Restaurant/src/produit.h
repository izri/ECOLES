#ifndef PRODUIT_H
#define PRODUIT_H

#include <string>

class Produit
{
public:
    Produit(const unsigned int &price, const double &tva);
    ~Produit();

    unsigned int getPrice() const;
    void setPrice(const unsigned int &price);

    double getTva() const;
    void setTva(const double &tva);

    virtual std::string getName() const = 0;

private:
    unsigned int price;
    double tva;
};

#endif // PRODUIT_H
