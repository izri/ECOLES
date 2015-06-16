#include "Produit.h"


using namespace std;


Produit :: Produit () : m_name(" "), m_prix(0) {}


Produit::Produit(string name, float prix) : m_name(name), m_prix(prix){}

string Produit :: getName ()const
{
    return m_name;
}

float Produit :: getPrix ()const
{
    return m_prix;
}

Produit setProduit ()
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


        Pizza produit1 (nomDuPlat, 9);
        PlatDuJour produit2 (nomDuPlat, 8);
        Vegetarien produit3 (nomDuPlat, 7);
        Dessert produit4 (nomDuPlat, 3);
        Boisson produit5 (nomDuPlat, 2);
    switch (i)
    {
        case 1:
            return produit1;
            break;

        case 2:
            return produit2;
            break;

        case 3:
            return produit3;
            break;

        case 4:
            return produit4;
            break;

        case 5:
            return produit5;
            break;
    }
    return produit1;
}


PlatDuJour :: PlatDuJour (string name, float prix) : Produit(name,prix)  {}
Pizza :: Pizza (string name, float prix) : Produit(name,prix)  {}
Vegetarien :: Vegetarien (string name, float prix) : Produit(name,prix)  {}
Dessert :: Dessert (string name, float prix) : Produit(name,prix)  {}
Boisson :: Boisson (string name, float prix) : Produit(name,prix)   {}
