#ifndef PRODUIT_H_INCLUDED
#define PRODUIT_H_INCLUDED


#include <string>
#include <iostream>



class Produit
{
    private:

        std :: string m_name;
        float m_prix;

    public:

        Produit ();
        Produit(std :: string name, float prix);
        std :: string getName()const;
        float getPrix ()const;
};


Produit setProduit ();


class Boisson : public Produit
{
    public:
        Boisson (std :: string name, float prix);
};

class PlatDuJour : public Produit
{
    public:
        PlatDuJour (std :: string name, float prix);
};


class Pizza : public Produit
{
    public:
        Pizza (std :: string name, float prix);
};

class Vegetarien : public Produit
{
    public:
        Vegetarien (std :: string name, float prix);
};


class Dessert : public Produit
{
    public:
        Dessert (std :: string name, float prix);
};





#endif // PRODUIT_H_INCLUDED
