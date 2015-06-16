#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <vector>
#include <stdarg.h>

using namespace std;

class Product {

protected:
    float price;
    string name; // nom du produit
    vector<string> ingredients; // tableau de nom d'ingredients
    int type, id;

public:
    /// Abstract class, without constructor

    /// === Methods ===
    int addIngr(...); // ajoute ingredients (dernier param = NULL)
    bool supprIngr(string ingr); // supprime ingredient
    void showInfo();

    /// === getter ===
    string getName() {return this->name;}
    float getPrice() {return this->price;}
    int getId() {return this->id;}

};

/// === Subclasses ===
class Pizza:        public Product {public: Pizza(float price);};
class Salade:       public Product {public: Salade(float price);};
class Cafe:         public Product {public: Cafe(float price);};
class Frite:        public Product {public: Frite(float price);};
class Burger:       public Product {public: Burger(float price);};
class Coca:         public Product {public: Coca(float price);};
class Gateau:       public Product {public: Gateau(float price);};
class Fruit:        public Product {public: Fruit(float price);};
class Tartare:      public Product {public: Tartare(float price);};
class Nem:          public Product {public: Nem(float price);};
class Eau:          public Product {public: Eau(float price);};
class DragonEgg:    public Product {public: DragonEgg(float price);};

#endif // PRODUCT_H
