#ifndef STOCK_H
#define STOCK_H

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <typeinfo>
#include <string>
#include <sstream>

#include "productquantity.h"

#include "Products/boisson.h"
#include "Products/dessert.h"
#include "Products/pizza.h"
#include "Products/platdujour.h"
#include "Products/platvegetarien.h"

class Stock
{
public:
    Stock(const unsigned int &spaceAvailable);
    ~Stock();
    enum TypeProduit { BOISSON, DESSERT, PIZZA, PLAT_DU_JOUR, PLAT_VEGETARIEN };

    unsigned int getSpaceAvailable() const;
    void setSpaceAvailable(const unsigned int spaceAvailable);

    unsigned int getSpaceUsed() const;

    void addProduct(const ProductQuantity &product);
    std::vector<ProductQuantity> getStocks() const;

    ProductQuantity take(const TypeProduit &typeProduit, const unsigned int &quantity);

    std::string getState() const;

private:
    unsigned int spaceAvailable;
    unsigned int spaceUsed;

    std::vector<ProductQuantity> products;
};

#endif // STOCK_H
