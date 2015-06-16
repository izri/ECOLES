#include <iostream>

#include "restaurant.h"
#include "client.h"
#include "stock.h"
#include "productquantity.h"
#include "commande.h"

int main()
{
    Restaurant myResto("Mon Resto Sans Nom");

    //On vient d’ouvrir ! On ajoute de la place à l’entrepôt fraîchement créé !
    Stock &stock = myResto.getStock();
    stock.setSpaceAvailable(10);

    //On vient de recevoir une première livraison, on ajoute les nouveaux produits !
    Boisson drink;
    ProductQuantity drinkQ(drink, 42);
    stock.addProduct(drinkQ);

    Dessert dessert;
    ProductQuantity dessertQ(dessert, 34);
    stock.addProduct(dessertQ);

    Pizza pizza;
    ProductQuantity pizzaQ(pizza, 22);
    stock.addProduct(pizzaQ);

    PlatDuJour todaySpecial;
    ProductQuantity todaySpecialQ(todaySpecial, 12);
    stock.addProduct(todaySpecialQ);

    PlatVegetarien vegetarian;
    ProductQuantity vegetarianQ(vegetarian, 42);
    stock.addProduct(vegetarianQ);


    //Bon, avant d’ouvrir au public, on fait un premier état des stocks !
    std::cout << "Etat du stock\n" << "==========" << std::endl;
    std::cout << stock.getState() << "==========\n" << std::endl;

    //Super tout est prêt, les premiers clients arrivent !
    Client pigeon1("Kevin", myResto);
    Client pigeon2("Marine", myResto);

    //Kevin n’a pas très faim aujourd’hui, il ne commande pas grand chose…
    ProductQuantity unPlatDuJour = stock.take(Stock::PLAT_DU_JOUR, 1);

    Commande commandeKevin(pigeon1);
    commandeKevin.addPurchase(unPlatDuJour);

    //« L’addition s’il-vous-plaît ! »
    std::cout << "L'addition de Kevin\n" << "==========" << std::endl;
    std::cout << commandeKevin.getBill() << "==========" << std::endl;
    std::cout << "Prix HT : " << commandeKevin.getPriceHT() << " €" << std::endl;
    std::cout << "Prix TTC : " << commandeKevin.getPriceTTC() << " €\n" << std::endl;

    //Marine a l’air d’être affamée !
    ProductQuantity maxDePizzas = stock.take(Stock::PIZZA, 12);
    ProductQuantity soif = stock.take(Stock::BOISSON, 4);
    ProductQuantity pourFinir = stock.take(Stock::DESSERT, 2);

    Commande commandeMarine(pigeon2);
    commandeMarine.addPurchase(maxDePizzas);
    commandeMarine.addPurchase(soif);
    commandeMarine.addPurchase(pourFinir);

    //Bon, c’est pas tout ça, mais il va falloir payer maintenant !
    std::cout << "L'addition de Marine\n" << "==========" << std::endl;
    std::cout << commandeMarine.getBill() << "==========" << std::endl;
    std::cout << "Prix HT : " << commandeMarine.getPriceHT() << " €" << std::endl;
    std::cout << "Prix TTC : " << commandeMarine.getPriceTTC() << " €\n" << std::endl;

    //DRING ! La journée est terminée ! Même si il n’y a eu que deux clients, les recettes ont été bonnes.
    //Avant de fermer le restaurant, il faut vérifier les stocks.
    std::cout << "Etat du stock en fin de journée\n" << "==========" << std::endl;
    std::cout << stock.getState() << "==========\n" << std::endl;

    return 0;
}

