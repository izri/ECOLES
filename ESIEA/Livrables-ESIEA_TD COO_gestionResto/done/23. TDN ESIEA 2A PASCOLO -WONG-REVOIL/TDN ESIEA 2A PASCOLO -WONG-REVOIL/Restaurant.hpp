#ifndef DEF_RESTAURANT
#define DEF_RESTAURANT

#include <string>
#include <ctime>
#include<vector>

using namespace std;


class Client
{
    private:

        string c_surname;
        string c_name;
        int id;

    public:
        Client(const string c_surname, const string c_name, const int id);
        string getName();
        string getSurname();
};

/*class ClientHistory
{
    private:
        int numberOfComings;
        int numberOfCommands;                  //Nombre de commandes passées
        int numberOfElementsBought;            // Nombre d'éléments achetés
        float totalAmountPaid;                          //Argent des commandes accumulé
        //float totalTips;                                //Montant total des pouboires
        //float averageAmountPerCommand;                  //Montant moyen d'une commande
        //float averageElementsPerCommand;                //Nombre d'éléments moyens constituant une commande
        int FidelityPoints;


        string preferedElement;
        string preferedStarter;
        string preferedDrink;
        string preferedMainCourse;
        string preferedDessert;

    public:

};

class GlobalHistory
{
    private:
        int numberofClients;
        int numberOfCommands;                  //Nombre de commandes passées
        int numberOfElementsBought;            // Nombre d'éléments achetés
        //int unicClients;                       //Clients avec une seule commande
        //int regularClients;                    //Clients avec au moins 2 commandes
        float totalAmountPaid;                          //Argent des commandes accumulé
        //float totalTips;                                //Montant total des pouboires
        //float averageAmountPerCommand;                  //Montant moyen d'une commande
        //float averageElementsPerCommand;                //Nombre d'éléments moyens constituant une commande

        string preferedElement;
        string preferedStarter;
        string preferedDrink;
        string preferedMainCourse;
        string preferedDessert;

    public:

};*/

class Product
{
    private:
		string name;
		int price;

	public:
		Product(const string name, const int price);
		string getName();
		int getPrice();
};

class Command
{
    private:

        Client client;
        Product product;
        int cost;

    public:

        Command(Client client, Product product, const int cost);  //Le constructeur de la commande
        void addElem(Product product);      //La fonction qui permet d'ajouter des éléments (entrée, boisson,...)
        vector<Product> products;
        void evaluateCost(int priceToAdd);
        int getCost();
};


class Starter : public Product
{
    public :
		Starter(const string name);
};

class Drink : public Product
{
    public :
		Drink(const string name);
};

class MainCourse : public Product
{
    public :
		MainCourse(const string name);
};

class Dessert : public Product
{
    public :
		Dessert(const string name);
};
#endif

