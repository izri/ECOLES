#ifndef COMMANDE_H
#define COMMANDE_H

#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

#include "client.h"
#include "productquantity.h"

class Commande
{
public:
    Commande(Client &client);
    ~Commande();

    Client& getClient() const;

    void addPurchase(const ProductQuantity &purchase);
    std::vector<ProductQuantity> getPurchases() const;

    unsigned int getPriceHT() const;
    double getPriceTTC() const;

    std::string getBill() const;
private:
    Client &client;

    std::vector<ProductQuantity> purchases;
};

#endif // COMMANDE_H
