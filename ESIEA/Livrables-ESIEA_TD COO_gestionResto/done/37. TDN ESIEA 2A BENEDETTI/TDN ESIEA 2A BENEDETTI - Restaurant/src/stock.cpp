#include "stock.h"

Stock::Stock(const unsigned int &spaceAvailable) :
    spaceAvailable(spaceAvailable),
    spaceUsed(0)
{
}

Stock::~Stock()
{
}

unsigned int Stock::getSpaceAvailable() const
{
    return this->spaceAvailable;
}

void Stock::setSpaceAvailable(const unsigned int spaceAvailable)
{
    if(spaceAvailable < this->spaceUsed)
    {
        throw std::invalid_argument("You can not reduce the storage space more than there is object stored in it.");
    }

    this->spaceAvailable = spaceAvailable;
}

unsigned int Stock::getSpaceUsed() const
{
    return this->spaceUsed;
}

void Stock::addProduct(const ProductQuantity &product)
{
    if(product.quantity == 0)
        return;

    std::vector<ProductQuantity>::iterator iter = std::find_if(this->products.begin(), this->products.end(), ProductQuantity::productTypeEqual(typeid(*product.product)));

    if(iter == this->products.end())
        this->products.push_back(product);
    else
    {
        iter->quantity += product.quantity;
    }

    this->spaceUsed += product.quantity;
}

std::vector<ProductQuantity> Stock::getStocks() const
{
    return products;
}

ProductQuantity Stock::take(const TypeProduit &typeProduit, const unsigned int &quantity)
{
    if(quantity > this->spaceUsed)
        throw std::invalid_argument("You can not take more products than what there is in stock.");

    const std::type_info *typeRequested;

    switch(typeProduit)
    {
    case BOISSON:
        typeRequested = &typeid(Boisson);
        break;

    case DESSERT:
        typeRequested = &typeid(Dessert);
        break;

    case PIZZA:
        typeRequested = &typeid(Pizza);
        break;

    case PLAT_DU_JOUR:
        typeRequested = &typeid(PlatDuJour);
        break;

    case PLAT_VEGETARIEN:
        typeRequested = &typeid(PlatVegetarien);
        break;

    default:
        throw std::invalid_argument("The type requested does not exist.");
    }

    std::vector<ProductQuantity>::iterator iter = std::find_if(this->products.begin(), this->products.end(), ProductQuantity::productTypeEqual(*typeRequested));

    if(iter == this->products.end())
        throw std::invalid_argument("The type requested is not in stock.");

    if(iter->quantity < quantity)
        throw std::invalid_argument("The type requested exists, but is not available in sufficient quantity.");

    iter->quantity -= quantity;
    this->spaceUsed -= quantity;

    return ProductQuantity(*iter->product, quantity);
}

std::string Stock::getState() const
{
    std::stringstream stateStream;

    for(std::vector<ProductQuantity>::const_iterator iter = this->products.begin() ; iter != this->products.end() ; ++iter)
    {
        stateStream << iter->product->getName() << " × " << iter->quantity << "\n";
    }

    return stateStream.str();
}
