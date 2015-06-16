#include "product.hpp"

Product::Product(const string name, const float price) : name(name), price(price)
{
}

const string Product::get_name()
{
    return name;
}

const float Product::get_price()
{
    return price;
}

const string Product::to_string()
{
	return name + " (" + tostr(price) + "e)";
}




Pizza::Pizza(const string name, const float price, const int nbChampignon, const int nbPeperoni, const bool sauceTomate) : Product(name, price), nbChampignon(nbChampignon), nbPeperoni(nbPeperoni), sauceTomate(sauceTomate)
{
}

const string Pizza::to_string()
{
	Product::to_string();
	cout << "nombre de champignon : " + tostr(nbChampignon) + " - nombre de peperoni : " + tostr(nbPeperoni) + " - sauce tomate : " + tostr(sauceTomate) << endl;
}

PlatJour::PlatJour(const string name, const float price, const bool dispoAjd) : Product(name, price), dispoAjd(dispoAjd)
{
}

const string PlatJour::to_string()
{
	Product::to_string();
	return "plat disponible aujourd'hui : " + tostr(dispoAjd);
}

PlatVege::PlatVege(const string name, const float price, const int nbSalade, const int nbBrocolis) : Product(name, price), nbSalade(nbSalade), nbBrocolis(nbBrocolis)
{
}

const string PlatVege::to_string()
{
	Product::to_string();
	return "nombre de salade : " + tostr(nbSalade) + " - nombre de brocolis : " + tostr(nbBrocolis);
}

Dessert::Dessert(const string name, const float price, const int nbBoule, const int nbCrepe) : Product(name, price), nbBoule(nbBoule), nbCrepe(nbCrepe)
{
}

const string Dessert::to_string()
{
	Product::to_string();
	return "nombre de boules : " + tostr(nbBoule) + " - nombre de crepes : " + tostr(nbCrepe);
}

Boisson::Boisson(const string name, const float price, const int quantiteCl) : Product(name, price), quantiteCl(quantiteCl)
{
}

const string Boisson::to_string()
{
	Product::to_string();
	return "quantite en cl : " + tostr(quantiteCl);
}
