#include "Restaurant.hpp"
#include "main.hpp"

#include<fstream>
#include<sstream>

using namespace std;

/*
Il faudra une fonction qui permettra d'ajouter un produit.
    Celle-ci permettra de choisir quel type de produit ça sera

A chaque ajout de produit, on rajoute celui-ci dans un tableau à taille variable
    Pour calculer la moyenne de certains produits, on incrémentera un tableau de même taille que celui contenant les produits en fonction
    du nombre d'occurences de chacun dans le tableau en question

*/

    vector <string>  availableProducts;         //Tous les produits confondus
    vector <Product> productsP;
    vector <string>  availableStarters;         //Toutes les entrées
    vector <Product> startersP;
    vector <string>  availableMainCourses;      //Tous les plats
    vector <Product> mainCoursesP;
    vector <string>  availableDrinks;           //Toutes les boissons
    vector <Product> drinksP;
    vector <string>  availableDesserts;         //Tous les desserts
    vector <Product> dessertsP;

    vector <string>  globalHistoryDatas;        //Contient les données de l'historique global
    vector <string>  clientHistoryDatas;        //Contient les données de l'historique client
    string readIdClient;
    int idClient;
    int nbCommand;
    int nbProductsBought;

    bool stop = false;
    bool watch = true;


int main()
{
    initialisation();                                                       //Permet de récupérer les historiques dans les fichiers textes
    cout << "Bonjour !\n" << "Bienvenue dans votre gestionnaire." << endl;      //Un accueil chaleureux

    while(!stop)
    {
        actions();
        updateGlobalHistory();
    }
    return 0;
}


void actions()                              //Regroupe les actions possibles de l'utilisateur
{
    cout << "Que voulez-vous faire ?\n" << endl;
    cout << "1.Consulter la base de donnees\n2.Ajouter un client\n3.Ajouter un produit\n4.Rentrer la commande d'un client\n5.Quitter\n" << endl;
    int firstChoice;
    cin >> firstChoice;
    switch(firstChoice)
    {
    case 1:
        {
            watch = true;
            while (watch)
            {
                dataWatching();
            }
            break;
        }
    case 2:
        {
        Client addedClient = createClient();
        cout << "Ce nouveau client aura pour identifiant le numero: " << idClient << endl << endl;
        break;
        }
    case 3:
        {
        addProduct();
        break;
        }
    case 4:
        makeCommand();
        break;
    case 5:
        cout << "Au revoir !\n" << endl;
        stop = true;
        break;
    default:
        cout << "Ce choix n'existe pas.\n" << endl;
        break;
    }
}

void dataWatching()                                 //Fonction regroupant les possibilités d'interactions de l'utilisateur avec la base de données
{
    cout << "\nQuelles donnees voulez-vous consulter?\n" << endl;
    cout << "1.La liste complete des produits.\n2.La liste des entrees.\n3.La liste des plats.\n4.La liste des boissons.\n5.La liste des desserts." << endl;
    cout << "6.L'historique global.\n7.L'historique d'un client.\n8.Rien, retourner au menu principal.\n" << endl;
    int secondChoice;
    cin >> secondChoice;
    switch(secondChoice)
    {
    case 1:
        {
            cout << "\nVoici la liste complete des produits disponibles:\n" << endl;
            printVector(availableProducts);
            break;
        }
    case 2:
        {
            cout << "\nVoici la liste des entrees disponibles:\n" << endl;
            printVector(availableStarters);
            break;
        }
    case 3:
        {
            cout << "\nVoici la liste des plats disponibles:\n" << endl;
            printVector(availableMainCourses);
            break;
        }
    case 4:
        {
            cout << "\nVoici la liste des boissons disponibles:\n" << endl;
            printVector(availableDrinks);
            break;
        }
    case 5:
        {
            cout << "\nVoici la liste des desserts disponibles:\n" << endl;
            printVector(availableDesserts);
            break;
        }
    case 6:
        {
            cout << "Voici les donnees contenues dans l'historique global:\n" << endl;
            printGlobal(globalHistoryDatas);
            break;
        }
    case 7:
        {
            bool chosenClient = false;
            do{
            getClientHistory();
            cout << "Le client s'appelle-t-il: " << clientHistoryDatas[0] << " " << clientHistoryDatas[1] << "? (o ou n)" << endl;
        char yesOrNo;
        cin >> yesOrNo;

        switch (yesOrNo)
        {
        case 'o':
            {
            chosenClient = true;
            break;
            }
        case 'n':
            cout << "Essayez un autre identifiant." << endl;
            break;
        default:
            cout << "Veuillez effectuer une nouvelle tentative." << endl;
            break;
        }
        }while (!chosenClient);
            printClient(clientHistoryDatas);
            break;
        }
    case 8:
        {
            watch = false;
            break;
        }
    default:
        {
            cout << "Ce choix n'existe pas." << endl;
            break;
        }
    }
}

void getClientHistory()                                                             //Permet de lire les données d'un client grâce à son id
{
    cout << "Tapez le numero correspondant a l'identifiant du client:\n" << endl;
    int id;
    cin >> id;
    clientHistoryReading(id);
}
Client createClient()
{
    cout << "Entrez le nom de famille du nouveau client:\n";
    char nom[30];
    cin >> nom;

    cout << "\nSon prenom:\n";
    char prenom[30];
    cin >> prenom;

    idClient++;
    Client client(nom, prenom, idClient);

    ostringstream file;
    file << idClient;                                                // On enregistre l'identifiant actuel dans une variable
    string fileName;
    fileName = "id_" + file.str() + ".txt";                             //On transforme la variable contenant le client en string
    string const hierarchy ("Histories/ClientHistories/" + fileName);
    ofstream clientHistory(hierarchy.c_str());                          //On cree un fichier historique correspondant à l'identifiant du client
    clientHistory << nom << endl << prenom << endl << idClient;

    return client;
}

void addProduct ()                                                  //Ajoute un produit à la base de données
{
    cout << "Entrez le nom du nouveau produit:" << endl;;
    char nom[30];
    cin >> nom;

    cout << "Son prix en chiffres:" << endl;;
    float prix = 0;
    cin >> prix;

    Product newProduct(nom, prix);
    if (!alreadyHere(availableProducts, nom))
        availableProducts.push_back(nom);
    else
    {
        cout << "Votre produit est deja sur la carte" << endl;
        return;
    }

    cout << "Son type \ns pour une entree,\nm pour un plat,\nb pour une boisson,\nd pour un dessert:" << endl;
    char type;
    cin >> type;

    switch(type)
    {
    case 's' :
        availableStarters.push_back(nom);
        startersP.push_back(newProduct);
        break;
    case 'm' :
        availableMainCourses.push_back(nom);
        mainCoursesP.push_back(newProduct);
        break;
    case 'b' :
        availableDrinks.push_back(nom);
        drinksP.push_back(newProduct);
        break;
    case 'd' :
        availableDesserts.push_back(nom);
        dessertsP.push_back(newProduct);
        break;
    default:
        cout << "Ce type de produit n'existe pas" << endl;
        break;
    }
}

bool alreadyHere(vector<string> tab, string element)
{
    int i=0;
    for (i=0; i<tab.size();i++)
    {
        if (tab[i] == element)              //Si l'élément est déjà dans le tableau
            return true;                    //alreadyHere est vrai
    }
    return false;
}


void initialisation()                                //Regroupe les fonctions de lecture de la base de donnée au démarrage du programme
{
    productsReading();
    globalHistoryReading();
}

void productsReading()                                      //Lit et enregistre dans un tableau chaque liste de produit
{
    ifstream allProducts("Products/AllProducts.txt");
    if (allProducts)
    {
        string line;
        string name;
        string price;
        allProducts >> name;
        allProducts >> price;
        allProducts.clear();
        allProducts.seekg(0, ios::beg);
        while(getline(allProducts, line))
        {
            availableProducts.push_back(name);
            int intPrice = convertStringToInt(price);
            Product product(name, intPrice);
            productsP.push_back(product);
            allProducts >> name;
            allProducts >> price;
        }
        availableProducts.push_back(name);
        int intPrice = convertStringToInt(price);
        Product product(name, intPrice);
        productsP.push_back(product);
    }
    else
        cout << "Erreur lors de la lecture du fichier texte." << endl;

    ifstream starters("Products/Starters.txt");
    if (starters)
    {
        //Product
        string line;
        string name;
        string price;
        starters >> name;
        starters >> price;
        starters.clear();
        starters.seekg(0, ios::beg);
        while(getline(starters, line))
        {
            availableStarters.push_back(name);
            int intPrice = convertStringToInt(price);
            Product product(name, intPrice);
            startersP.push_back(product);
            starters >> name;
            starters >> price;
        }
        availableStarters.push_back(name);
        int intPrice = convertStringToInt(price);
        Product product(name, intPrice);
        startersP.push_back(product);
    }
    else
        cout << "Erreur lors de la lecture du fichier texte." << endl;

    ifstream mainCourses("Products/MainCourses.txt");
    if (mainCourses)
    {
        string line;
        string name;
        string price;
        mainCourses >> name;
        mainCourses >> price;
        mainCourses.clear();
        mainCourses.seekg(0, ios::beg);
        while(getline(mainCourses, line))
        {
            availableMainCourses.push_back(name);
            int intPrice = convertStringToInt(price);
            Product product(name, intPrice);
            mainCoursesP.push_back(product);
            mainCourses >> name;
            mainCourses >> price;
        }
        availableMainCourses.push_back(name);
        int intPrice = convertStringToInt(price);
        Product product(name, intPrice);
        mainCoursesP.push_back(product);
    }
    else
        cout << "Erreur lors de la lecture du fichier texte." << endl;

    ifstream drinks("Products/Drinks.txt");
    if (drinks)
    {
        string line;
        string name;
        string price;
        drinks >> name;
        drinks >> price;
        drinks.clear();
        drinks.seekg(0, ios::beg);
        while(getline(drinks, line))
        {
            availableDrinks.push_back(name);
            int intPrice = convertStringToInt(price);
            Product product(name, intPrice);
            drinksP.push_back(product);
            drinks >> name;
            drinks >> price;
        }
        availableDrinks.push_back(name);
        int intPrice = convertStringToInt(price);
        Product product(name, intPrice);
        drinksP.push_back(product);
    }
    else
        cout << "Erreur lors de la lecture du fichier texte." << endl;

    ifstream desserts("Products/Desserts.txt");
    if (desserts)
    {
        string line;
        string name;
        string price;
        desserts >> name;
        desserts >> price;
        desserts.clear();
        desserts.seekg(0, ios::beg);
        while(getline(desserts, line))
        {
            availableDesserts.push_back(name);
            int intPrice = convertStringToInt(price);
            Product product(name, intPrice);
            dessertsP.push_back(product);
            desserts >> name;
            desserts >> price;
        }
        availableDesserts.push_back(name);
        int intPrice = convertStringToInt(price);
        Product product(name, intPrice);
        dessertsP.push_back(product);
    }
    else
        cout << "Erreur lors de la lecture du fichier texte." << endl;

}


void globalHistoryReading()                                             //Lit toutes les informations contenues dans l'historique global actuel
{
    ifstream globalHistory("Histories/GlobalHistory.txt");
    if (globalHistory)
    {
        string line;
        while(getline(globalHistory, line))
        {
            globalHistoryDatas.push_back(line);
        }
        idClient = convertStringToInt(globalHistoryDatas[0]);
        nbCommand = convertStringToInt(globalHistoryDatas[1]);
        nbProductsBought = convertStringToInt(globalHistoryDatas[2]);
    }
    else
        cout << "Erreur lors de la lecture du fichier texte." << endl;
}

void printGlobal(vector<string> global)                             //Affiche toutes les cases d'un tableau dynamique contenant des strings
{
    cout << "Le nombre de client est de: " << global[0] << endl;
    cout << "Le nombre commandes est de: " << global[1] << endl;
    cout << "Le nombre de produits commandes est de: " << global[2] << endl;
    cout << "Le montant total des recettes est de: " << global[3] << endl;
    cout << "Le produit le plus commande est: " << global[4] << endl;
    cout << "L'entree la plus commandee est: " << global[5] << endl;
    cout << "Le plat le plus commande est: " << global[6] << endl;
    cout << "La boisson la plus commandee est: " << global[7] << endl;
    cout << "Le dessert le plus commande est: " << global[8] << endl;
}


void updateGlobalHistory()                                  //Permet de mettre à jour l'historique global en utilisant tous les historiques clients
{
    globalHistoryDatas[0] = convertIntToString(idClient);
    int i=1;
    for (i=1;i<4;i++)
    {
        globalHistoryDatas[i] = '0';
    }
    i=9;
    for (i=9;i<17;i++)
    {
        globalHistoryDatas[i] = '0';
    }
    i=1;
    for (i=1;i<=idClient;i++)
    {
        clientHistoryReading(i);
        int nbCommandsG = convertStringToInt(globalHistoryDatas[1]);
        int nbProductsG = convertStringToInt(globalHistoryDatas[2]);
        int amountG = convertStringToInt(globalHistoryDatas[3]);
        int nbCommandsC = convertStringToInt(clientHistoryDatas[3]);
        int nbProductsC = convertStringToInt(clientHistoryDatas[4]);
        int amountC = convertStringToInt(clientHistoryDatas[5]);

        nbCommandsG += nbCommandsC;
        nbProductsG += nbProductsC;
        amountG += amountC;

        globalHistoryDatas[1] = convertIntToString(nbCommandsG);             //On ajoute client par client le nombre de commandes
        globalHistoryDatas[2] = convertIntToString(nbProductsG);             //On ajoute client par client le nombre de produits commandés
        globalHistoryDatas[3] = convertIntToString(amountG);             //On ajoute client par client le montant dépensé
    }
    writingFromVector(globalHistoryDatas, "Histories/GlobalHistory.txt");
}

void clientHistoryReading(int id)                                             //Lit toutes les informations contenues dans l'historique global actuel
{
    string idString = convertIntToString(id);
    string fileName = "Histories/ClientHistories/id_" + idString + ".txt";
    ifstream clientHistory(fileName.c_str());
    clientHistoryDatas.clear();
    if (clientHistory)
    {
        string line;
        while(getline(clientHistory, line))
        {
            clientHistoryDatas.push_back(line);
        }
    }
    else
        cout << "Erreur lors de la lecture du fichier texte." << endl;
}

void printClient(vector<string> client)                             //Affiche toutes les cases d'un tableau dynamique contenant les données d'un client
{
    cout << "Voici les donnees contenues dans l'historique cu client:\n" << endl;
    cout << "Le nombre de commandes passees par ce client est de: " << client[3] << endl;
    cout << "Le nombre de produits commandes est de: " << client[4] << endl;
    cout << "Le montant depense par ce client est de: " << client[5] << endl;
    cout << "Le produit le plus commande est: " << client[6] << endl;
    cout << "L'entree la plus commandee est: " << client[7] << endl;
    cout << "Le plat le plus commande est: " << client[8] << endl;
    cout << "La boisson la plus commandee est: " << client[9] << endl;
    cout << "Le dessert le plus commande est: " << client[10] << endl;
    cout << "Le nombre de points de fidelite de ce client est de: " << client[11] << endl;
}


void makeCommand()                                  //Fonction permettant de prendre un commande pour un client.
{
    bool chosenClient = false;
    do
    {
        cout << "\nRentrez l'identifiant du client prenant la commande:" << endl;
        int idCommand;
        cin >> idCommand;
        clientHistoryReading(idCommand);
        cout << "Le client s'appelle-t-il: " << clientHistoryDatas[0] << " " << clientHistoryDatas[1] << "? (o ou n)" << endl;
        char yesOrNo;
        cin >> yesOrNo;
        switch (yesOrNo)
        {
        case 'o':
            {
            chosenClient = true;
            break;
            }
        case 'n':
            cout << "Essayez un autre identifiant." << endl;
            break;
        default:
            cout << "Veuillez effectuer une nouvelle tentative." << endl;
            break;
        }
    }while (!chosenClient);
    Client clientCommand(clientHistoryDatas[0], clientHistoryDatas[1], convertStringToInt(clientHistoryDatas[02]));
    cout << "Veuillez ajouter un (seul) produit à la commande en rentrant son nom:" << endl;
    string productName;
    cin >> productName;

    string name;
    string price;
    string thatProductName;
    int thatProductPrice;

    int i=0;
    for (i=0; i<availableProducts.size();i++)
    {
        if (availableProducts[i] == productName)
        {
            thatProductName = productsP[i].getName();
            thatProductPrice = productsP[i].getPrice();
        }
    }
    Product chosenProduct(thatProductName, thatProductPrice);
    Command command(clientCommand, chosenProduct, chosenProduct.getPrice());
    bool another = true;
    int totalCost = 0;
    int nbProducts = 1;
    do
    {
        cout << "\nVoulez-vous ajouter un autre produit a cette commande?(o ou n)" << endl;
        char otherProduct;
        cin >> otherProduct;
        switch (otherProduct)
        {
        case 'o':
            totalCost = addProductToCommand(command);
            nbProducts++;
            break;
        case 'n':
            {
            another = false;
            cout << "La cout de la commande s'eleve donc a "  << totalCost << "euros." << endl;
            commandAdded(nbProducts, totalCost);
            break;
            }
        default:
            cout << "Veuillez effectuer une nouvelle tentative." << endl;
            break;
        }
    }while(another);
}

int addProductToCommand(Command command)                        //La commande de base ne contient qu'un produit, cette fonction permet de lui en rajouter.
{
    cout << "Veuillez ajouter un (seul) produit a la commande en rentrant son nom:" << endl;
    string productName;
    cin >> productName;

    string name;
    string price;
    string thatProductName;
    int thatProductPrice;

    int i=0;
    for (i=0; i<availableProducts.size();i++)
    {
        if (availableProducts[i] == productName)
        {
            thatProductName = productsP[i].getName();
            thatProductPrice = productsP[i].getPrice();
        }
    }
    command.evaluateCost(thatProductPrice);
    return command.getCost();
}

void commandAdded(int nbProducts, int totalCost)                        //On actualise les données de l'historique client lorsqu'une commande est passée
{
    int nbCommandsClient = convertStringToInt(clientHistoryDatas[3]);
    nbCommandsClient++;
    //int nbCommandsGlobal = convertStringToInt(globalHistoryDatas[1]);
    //nbCommandsGlobal++;
    clientHistoryDatas[3] = convertIntToString(nbCommandsClient);
    //globalHistoryDatas[1] = convertIntToString(nbCommandsGlobal);

    int totalCostClient = convertStringToInt(clientHistoryDatas[5]);
    totalCostClient+= totalCost;
    //int totalCostGlobal = convertStringToInt(globalHistoryDatas[3]);
    //totalCostGlobal+= TotalCost;
    clientHistoryDatas[5] = convertIntToString(totalCostClient);
    //globalHistoryDatas[3] = convertIntToString(totalCostGlobal);
}

int convertStringToInt(string toConvert)
{
    stringstream ss(toConvert);
    int integer;
    ss >> integer;
    return integer;
}

float convertStringToFloat(string toConvert)
{
    stringstream ss(toConvert);
    float floating;
    ss >> floating;
    return floating;
}

string convertIntToString(int toConvert)
{
    stringstream ss;
    ss << toConvert;
    string str = ss.str();
    return str;
}

void writingFromVector(vector<string> tab, string filePath)             //Permet d'écrire les données contenues dans un tableau dynamiquec ligne par ligne dans un txt
{
    ofstream written(filePath.c_str());

    if(written)
    {
        int i=0;
        for (i=0;i<tab.size();i++)
        {
            written << tab[i] << endl;
        }
    }
    else
        cout << "Erreur lors de la lecture du fichier texte." << endl;

}

void printVector(vector<string> tab)                             //Affiche toutes les cases d'un tableau dynamique contenant des strings
{
    int i = 0;
    for(i=0;i<tab.size();i++)
    {
        cout << tab[i] << endl;
    }
}
