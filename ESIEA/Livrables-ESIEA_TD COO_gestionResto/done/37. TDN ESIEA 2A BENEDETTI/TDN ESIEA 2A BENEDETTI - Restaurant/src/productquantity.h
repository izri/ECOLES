#ifndef PRODUCTQUANTITY
#define PRODUCTQUANTITY

#include <iostream>
#include <functional>
#include <typeinfo>

#include "produit.h"

struct ProductQuantity
{
    ProductQuantity(Produit &product, const unsigned int &quantity) :
        product(&product),
        quantity(quantity)
    {
    }

    Produit *product;
    unsigned int quantity;

    struct productTypeEqual : public std::unary_function<const ProductQuantity &, bool>
    {
        productTypeEqual(const std::type_info &typeProduct) : typeProduct(typeProduct) {}

        inline bool operator() (const ProductQuantity &productQuantity) const
        {
            return typeProduct == typeid(*productQuantity.product);
        }

        const std::type_info &typeProduct;
    };
};

#endif // PRODUCTQUANTITY

