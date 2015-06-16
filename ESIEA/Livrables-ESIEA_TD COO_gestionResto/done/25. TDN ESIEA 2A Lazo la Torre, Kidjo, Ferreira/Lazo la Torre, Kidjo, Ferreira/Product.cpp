#include "Product.h"

using namespace std;

Product :: Product () : m_name(" "), m_price(0) {}


Product::Product(string name, float price) : m_name(name), m_price(price){}

string Product :: getName ()const
{
    return m_name;
}

float Product :: getPrice ()const
{
    return m_price;
}

Product setProduct ()
{
    int i(0);
    string nomDuPlat(0);
    while (i < 1 || i > 5)
    {
        cout << "1- Pizza\n2- Plat du jour\n3- Vegetarien\n4 -Dessert\n5- Boisson" << endl;
        cin >> i;
    }
    cout << "Nom du plat :" << endl;
    cin >> nomDuPlat;
        Pizza product1 (nomDuPlat, 10);
        PlatDuJour product2 (nomDuPlat, 15);
        Vegetarien product3 (nomDuPlat, 12);
        Dessert product4 (nomDuPlat, 5);
        Boisson product5 (nomDuPlat, 2);
    switch (i)
    {
        case 1:
            return product1;
            break;
        case 2:
            return product2;
            break;
        case 3:
            return product3;
            break;
        case 4:
            return product4;
            break;
        case 5:
            return product5;
            break;
    }
    return product1;
}



Pizza :: Pizza (string name, float price) : Product(name,price) {}

PlatDuJour :: PlatDuJour (string name, float price) : Product(name,price) {}

Vegetarien :: Vegetarien (string name, float price) : Product(name,price) {}

Dessert :: Dessert (string name, float price) : Product(name,price) {}

Boisson :: Boisson (string name, float price) : Product(name,price) {}
