#include "product.h"

/// === Methods for Product === ///

/**
 | Ajoute des ingredients a un produit
 | @param   ... Un certain nombre de nom d'ingredients (string), la liste de param doit se terminer par NULL
 | @return  res Le nombre d'ingredients ajoutes
*/
int Product::addIngr(...) { /// fonction a parametre infini !
    int res = 0;
    char *param;

    va_list ap; // prepare la lecture des parametres
    va_start(ap, NULL);

    while((param = va_arg(ap, char*)) != NULL) { // tant qu'on a pas atteint le dernier param (NULL)
        this->ingredients.push_back(param); // ajoute l'ingredient
        res++;
    }

    va_end(ap);
    return res; // le nombre d'ingredients ajoutes
}

/**
 | Supprime la premiere occurrence d'un ingredient d'un produit
 | @param   ingr Le nom de l'ingredient a supprimer
 | @return  true si l'ingredient a ete supprime, false sinon
*/
bool Product::supprIngr(string ingr) {
    for(unsigned int i=0; i < this->ingredients.size(); i++) {
        if(this->ingredients.at(i) == ingr) { // recherche la premiere occurence de ingr
            this->ingredients.erase(this->ingredients.begin() + i); // trouve ! on la vire du tableau
            return 1;
        }
    }

    return 0;
}

/**
 | Affiche les informations d'un produit (prix, ingredients, etc.)
*/
void Product::showInfo() {
    cout << "Nom du produit : " << this->name << endl;
    cout << "Prix : " << this->price << " euros" << endl;

    for(unsigned int i=0; i < this->ingredients.size(); i++) { // pour chaque ingredient
        cout << "Ingredient " << i+1 << " : " << this->ingredients.at(i) << endl;
    }
}


/// === Constructors for subclasses === ///

Pizza::Pizza(float price) {
    this->id = 0;
    this->type = 2;
    this->price = price;

    this->name = "Pizza 4 fromages\t\t";
    this->ingredients.push_back("pate a pizza");
    this->ingredients.push_back("creme fraiche");
    this->ingredients.push_back("mozzarella");
    this->ingredients.push_back("chevre");
    this->ingredients.push_back("100g raclette");
    this->ingredients.push_back("gruyere rape");
}

Salade::Salade(float price) {
    this->id = 1;
    this->type = 1;
    this->price = price;

    this->name = "Salade d'ete\t\t\t";
    this->ingredients.push_back("batavia");
    this->ingredients.push_back("400g lardons");
    this->ingredients.push_back("4 oeufs");
    this->ingredients.push_back("200g mozzarella");
    this->ingredients.push_back("1 poivron rouge");
    this->ingredients.push_back("des de jambon blanc");
}

Cafe::Cafe(float price) {
    this->id = 2;
    this->type = 4;
    this->price = price;

    this->name = "Cafe noir\t\t\t";
    this->ingredients.push_back("graine de cafe du Congo");
}

Frite::Frite(float price) {
    this->id = 3;
    this->type = 2;
    this->price = price;

    this->name = "Frite McDo\t\t\t";
    this->ingredients.push_back("frites");
    this->ingredients.push_back("huile cancerigene");
}

Burger::Burger(float price) {
    this->id = 4;
    this->type = 2;
    this->price = price;

    this->name = "Big Mac\t\t\t";
    this->ingredients.push_back("2 pains a burger");
    this->ingredients.push_back("2 steaks haches 45g");
    this->ingredients.push_back("1 tranches de cheddar");
    this->ingredients.push_back("2 feuilles de salade (#vegetarien)");
    this->ingredients.push_back("1 oignon");
    this->ingredients.push_back("du courage");
}

Coca::Coca(float price) {
    this->id = 5;
    this->type = 4;
    this->price = price;

    this->name = "Coca\t\t\t\t";
    this->ingredients.push_back("1 pepsi");
}

Gateau::Gateau(float price) {
    this->id = 6;
    this->type = 3;
    this->price = price;

    this->name = "Gateau yaourt\t\t";
    this->ingredients.push_back("1/2 paquet de levure");
    this->ingredients.push_back("1 pot de yaourt");
    this->ingredients.push_back("2 pots de sucre");
    this->ingredients.push_back("3 pots de farine");
    this->ingredients.push_back("2 oeufs");
}

Fruit::Fruit(float price) {
    this->id = 7;
    this->type = 3;
    this->price = price;

    this->name = "Fruit au choix\t\t";
}

Tartare::Tartare(float price) {
    this->id = 8;
    this->type = 1;
    this->price = price;

    this->name = "Tartare de saumon\t\t";
    this->ingredients.push_back("400g de saumon");
    this->ingredients.push_back("1 citron");
    this->ingredients.push_back("1 cuilliere a soupe de vinaigre balsamique");
    this->ingredients.push_back("1 cuilliere a soupe d'huile d'olive");
}

Nem::Nem(float price) {
    this->id = 9;
    this->type = 1;
    this->price = price;

    this->name = "Nems chinois\t\t\t";
    this->ingredients.push_back("5 nems congeles");
}

Eau::Eau(float price) {
    this->id = 10;
    this->type = 4;
    this->price = price;

    this->name = "Cristaline\t\t\t";
    this->ingredients.push_back("eau du robinet");
}

DragonEgg::DragonEgg(float price) {
    this->id = 11;
    this->type = 2;
    this->price = price;

    this->name = "Omelette d'oeufs de dragon\t";
    this->ingredients.push_back("oeuf de dragon Drogon");
    this->ingredients.push_back("oeuf de dragon Rhaegal");
    this->ingredients.push_back("oeuf de dragon Viserion");
    this->ingredients.push_back("une pincee de Khaleesi");
    this->ingredients.push_back("Winter Is Coming");
}
