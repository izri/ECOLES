#include "commande.h"

Commande::Commande(Client &client) :
    client(client)
{
}

Commande::~Commande()
{
}

Client& Commande::getClient() const
{
    return this->client;
}

void Commande::addPurchase(const ProductQuantity &purchase)
{
    if(purchase.quantity == 0)
        return;

    std::vector<ProductQuantity>::iterator iter = std::find_if(this->purchases.begin(), this->purchases.end(), ProductQuantity::productTypeEqual(typeid(*purchase.product)));

    if(iter == this->purchases.end())
        this->purchases.push_back(purchase);
    else
    {
        iter->quantity += purchase.quantity;
    }
}

std::vector<ProductQuantity> Commande::getPurchases() const
{
    return this->purchases;
}

unsigned int Commande::getPriceHT() const
{
    unsigned int priceHT = 0;

    for(std::vector<ProductQuantity>::const_iterator iter = this->purchases.begin() ; iter != this->purchases.end() ; ++iter)
    {
        priceHT += iter->product->getPrice() * iter->quantity;
    }

    return priceHT;
}

double Commande::getPriceTTC() const
{
    double priceTTC = 0;

    for(std::vector<ProductQuantity>::const_iterator iter = this->purchases.begin() ; iter != this->purchases.end() ; ++iter)
    {
        priceTTC += (static_cast<double>(iter->product->getPrice()) * (1.0 + (iter->product->getTva() / 100))) * static_cast<double>(iter->quantity);
    }

    return priceTTC;
}

std::string Commande::getBill() const
{
    std::stringstream billStream;

    for(std::vector<ProductQuantity>::const_iterator iter = this->purchases.begin() ; iter != this->purchases.end() ; ++iter)
    {
        billStream << iter->product->getName() << " × " << iter->quantity << "\n";
    }

    return billStream.str();
}
