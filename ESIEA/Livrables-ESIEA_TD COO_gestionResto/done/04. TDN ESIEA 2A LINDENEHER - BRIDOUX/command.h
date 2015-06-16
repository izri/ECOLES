#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <vector>
#include <ctime>

#include "product.h"

using namespace std;

class Command {

private:
    vector<Product*> products; // tableau de produits
    float totalPrice, userNote;
    time_t date;

public:
    /// === Constructors / destructor ===
    Command(); // init date, totalPrice et userNote
    ~Command(); // libere produits de la memoire

    /// === Methods ===
    bool addProducts(Product *prod); // ajoute produit
    bool deleteProduct(int index); // supprime produit
    float computePrice(); // mit a jour totalPrice
    void showInfo(); // liste les produits

    /// === setter / getter / isStatut ===
    bool isEmpty() {return (this->products.size() == 0)? true:false;} // true si la commande est vide, flase sinon

    void setNote(float n) {if(n<0)n=0; if(n>5)n=5; this->userNote = n;}

    time_t getDate() {return this->date;}
    int getNbProd() {return this->products.size();}
    float getTotalPrice() {return this->totalPrice;}
    float getUserNote() {return this->userNote;}
    vector<Product*> getProds() {return this->products;}
};

#endif // COMMAND_H
