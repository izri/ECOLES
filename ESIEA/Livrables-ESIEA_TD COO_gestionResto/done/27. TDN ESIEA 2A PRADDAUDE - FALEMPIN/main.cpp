#include "main.hpp"
#include "command.hpp"
#include "product.hpp"
#include "client.hpp"
#include "vector"
#include <cstdlib>

ostream& operator<<(ostream& s, Client c)
{
    return s << c.to_string();
}

ostream& operator<<(ostream& s, Product o)
{
    return s << o.to_string();
}

ostream& operator<<(ostream& s, Command o)
{
    return s << o.to_string();
}

const string Printable::to_string()
{
	const type_info &t = typeid(this);
	return t.name();
}

vector<Pizza> PizzaVect;
vector<PlatJour> PlatJourVect;
vector<PlatVege> PlatVegeVect;
vector<Dessert> DessertVect;
vector<Boisson> BoissonVect;

vector<Client> tabClient;
vector<Command> tabCommand;

void add_client()
{
    string first_name;
    string last_name;
    int genderInt = 0;
    bool gender;

    cout << "Entrez le prenom : " << endl;
    cin >> first_name;

    cout << "Entrez le nom : " << endl;
    cin >> last_name;

    cout << "0 pour Homme, 1 pour Femme : ";
    cin >> gender;
    gender = (genderInt != 0);

    tabClient.push_back(*(new Client(first_name, last_name, gender)));
    tabClient.back().to_string();

    system("pause");
}

void gestion_product()
{
    string nom;
    float prix;

    int nbChampignon;
    int nbPeperoni;
    bool sauceTomate;
    bool dispoAjd;
    int nbSalade;
    int nbBrocolis;
    int nbBoule;
    int nbCrepe;
    int quantiteCl;

    unsigned int i;
    unsigned int id;
    int choix = 6;
    int choix1;
    system("cls");

    while(choix !=3)
    {
        cout << "Tapez 0 pour lister les produits" << endl;
        cout << "Tapez 1 pour ajouter un produit" << endl;
        cout << "Tapez 2 pour supprimer un produit" << endl;
        cout << "Tapez 3 pour quitter" << endl;
        cin >> choix;
        system("cls");

        switch (choix)
        {
            case 0:
                cout << "Pizzas" << endl;
                cout << endl;
                for(i = 0 ; i < PizzaVect.size() ; i++)
                {
                    PizzaVect.at(i).to_string();
                }
                cout << endl;
                cout << "Plats du jour" << endl;
                cout << endl;
                for(i = 0 ; i < PlatJourVect.size() ; i++)
                {
                    PlatJourVect.at(i).to_string();
                }
                cout << endl;
                cout << "Plats vegetariens" << endl;
                cout << endl;
                for(i = 0 ; i < PlatVegeVect.size() ; i++)
                {
                    PlatVegeVect.at(i).to_string();
                }
                cout << endl;
                cout << "Desserts" << endl;
                cout << endl;
                for(i = 0 ; i < DessertVect.size() ; i++)
                {
                    DessertVect.at(i).to_string();
                }
                cout << endl;
                cout << "Boissons" << endl;
                cout << endl;
                for(i = 0 ; i < BoissonVect.size() ; i++)
                {
                    BoissonVect.at(i).to_string();
                }
                cout << endl;
                system("pause");
                system("cls");
            break;
            case 1:
                cout << "Tapez 0 pour ajouter une pizza" << endl;
                cout << "Tapez 1 pour ajouter un plat du jour" << endl;
                cout << "Tapez 2 pour ajouter un plat vegetarien" << endl;
                cout << "Tapez 3 pour ajouter un dessert" << endl;
                cout << "Tapez 4 pour ajouter une boisson" << endl;

                cin >> choix1;
                system("cls");

                cout << "Nom ?" << endl;
                cin >> nom;
                cout << "Prix ?" << endl;
                cin >> prix;

                switch (choix1)
                {
                    case 0:
                        cout << "nombre de champignon ?" << endl;
                        cin >> nbChampignon;
                        cout << "nombre de peperoni ?" << endl;
                        cin >> nbPeperoni;
                        cout << "sauce tomate ? (0 non, 1 oui)" << endl;
                        cin >> sauceTomate;
                        PizzaVect.push_back(*(new Pizza(nom, prix, nbChampignon, nbPeperoni, sauceTomate)));
                        PizzaVect.back().to_string();
                    break;
                    case 1:
                        cout << "disponible aujourd'hui ? (0 non, 1 oui)" << endl;
                        cin >> dispoAjd;
                        PlatJourVect.push_back(*(new PlatJour(nom, prix, dispoAjd)));
                        PlatJourVect.back().to_string();
                    break;
                    case 2:
                        cout << "nombre de salade ?" << endl;
                        cin >> nbSalade;
                        cout << "nombre de peperoni ?" << endl;
                        cin >> nbBrocolis;
                        PlatVegeVect.push_back(*(new PlatVege(nom, prix, nbSalade, nbBrocolis)));
                        PlatVegeVect.back().to_string();
                    break;
                    case 3:
                        cout << "nombre de boule ?" << endl;
                        cin >> nbBoule;
                        cout << "nombre de crepe ?" << endl;
                        cin >> nbCrepe;
                        DessertVect.push_back(*(new Dessert(nom, prix, nbBoule, nbCrepe)));
                        DessertVect.back().to_string();
                    break;
                    case 4:
                        cout << "quantite en cl ?" << endl;
                        cin >> quantiteCl;
                        BoissonVect.push_back(*(new Boisson(nom, prix, quantiteCl)));
                        BoissonVect.back().to_string();
                    break;
                }
                system("pause");
                system("cls");
            break;
            case 2:
                cout << "Tapez 0 pour supprimer une pizza" << endl;
                cout << "Tapez 1 pour supprimer un plat du jour" << endl;
                cout << "Tapez 2 pour supprimer un plat vegetarien" << endl;
                cout << "Tapez 3 pour supprimer un dessert" << endl;
                cout << "Tapez 4 pour supprimer une boisson" << endl;

                cin >> choix1;
                system("cls");

                switch (choix1)
                {
                    case 0:
                        for(i = 0 ; i < PizzaVect.size() ; i++)
                        {
                            PizzaVect.at(i).to_string();
                            cout << "id : " << i << endl;
                            cout << endl;
                        }
                    break;
                    case 1:
                        for(i = 0 ; i < PlatJourVect.size() ; i++)
                        {
                            PlatJourVect.at(i).to_string();
                            cout << "id : " << i << endl;
                            cout << endl;
                        }
                    break;
                    case 2:
                        for(i = 0 ; i < PlatVegeVect.size() ; i++)
                        {
                            PlatVegeVect.at(i).to_string();
                            cout << "id : " << i << endl;
                            cout << endl;
                        }
                    break;
                    case 3:
                        for(i = 0 ; i < DessertVect.size() ; i++)
                        {
                            DessertVect.at(i).to_string();
                            cout << "id : " << i << endl;
                            cout << endl;
                        }
                    break;
                    case 4:
                        for(i = 0 ; i < BoissonVect.size() ; i++)
                        {
                            BoissonVect.at(i).to_string();
                            cout << "id : " << i << endl;
                            cout << endl;
                        }
                    break;
                }
                cout << "Tapez l'identifiant du plat a supprimer" << endl;
                cin >> id;
                switch (choix1)
                {
                    case 0:
                        if(id < PizzaVect.size()) PizzaVect.erase(PizzaVect.begin()+id);
                    break;
                    case 1:
                        if(id < PlatJourVect.size()) PlatJourVect.erase(PlatJourVect.begin()+id);
                    break;
                    case 2:
                        if(id < PlatVegeVect.size()) PlatVegeVect.erase(PlatVegeVect.begin()+id);
                    break;
                    case 3:
                        if(id < DessertVect.size()) DessertVect.erase(DessertVect.begin()+id);
                    break;
                    case 4:
                        if(id < BoissonVect.size()) BoissonVect.erase(BoissonVect.begin()+id);
                    break;
                }
                system("cls");
            break;
        }
    }
}

void add_command()
{
    unsigned int choix, id, i;

    cout << "Tapez 0 pour ajouter une pizza" << endl;
    cout << "Tapez 1 pour ajouter un plat du jour" << endl;
    cout << "Tapez 2 pour ajouter un plat vegetarien" << endl;
    cout << "Tapez 3 pour ajouter un dessert" << endl;
    cout << "Tapez 4 pour ajouter une boisson" << endl;

    cin >> choix;
    if (choix > 4 || choix < 0) return;
    else system("cls");

    switch (choix)
    {
        case 0:
            cout << "Pizzas" << endl;
            cout << endl;
            for(i = 0 ; i < PizzaVect.size() ; i++)
            {
                PizzaVect.at(i).to_string();
            }
            cout << endl;
        break;
        case 1:
            cout << "Plats du jour" << endl;
            cout << endl;
            for(i = 0 ; i < PlatJourVect.size() ; i++)
            {
                PlatJourVect.at(i).to_string();
            }
            cout << endl;
        break;
        case 2:
            cout << "Plats vegetariens" << endl;
            cout << endl;
            for(i = 0 ; i < PlatVegeVect.size() ; i++)
            {
                PlatVegeVect.at(i).to_string();
            }
            cout << endl;
        break;
        case 3:
            cout << "Desserts" << endl;
            cout << endl;
            for(i = 0 ; i < DessertVect.size() ; i++)
            {
                DessertVect.at(i).to_string();
            }
            cout << endl;
        break;
        case 4:
            cout << "Boissons" << endl;
            cout << endl;
            for(i = 0 ; i < BoissonVect.size() ; i++)
            {
                BoissonVect.at(i).to_string();
            }
            cout << endl;
        break;
    }

    cout << "Entrez l'indice du plat a ajouter :" << endl;
    cin >> id;

    switch (choix)
    {
        case 0:
            tabCommand.push_back(*(new Command(tabClient.back(), PizzaVect.at(id))));
        break;
        case 1:
            tabCommand.push_back(*(new Command(tabClient.back(), PlatJourVect.at(id))));
        break;
        case 2:
            tabCommand.push_back(*(new Command(tabClient.back(), PlatVegeVect.at(id))));
        break;
        case 3:
            tabCommand.push_back(*(new Command(tabClient.back(), DessertVect.at(id))));
        break;
        case 4:
            tabCommand.push_back(*(new Command(tabClient.back(), BoissonVect.at(id))));
        break;
    }

}

void bilan()
{
    unsigned int i;
    system("cls");
    cout << "| BILAN |" << endl;
    cout << endl;

    for(i = 0 ; i < tabCommand.size() ; i++)
    {
        cout << "Prix de la commande numero ";
        cout << i+1 << endl;
        cout << tabCommand.at(i).get_totalPrice();
        cout << " euros" << endl;
        cout << endl;
    }

    system("pause");
    system("cls");
}

int main()
{
    int choice = -1;

    while(choice != 3)
    {
        system("cls");
        cout << "Entrez 0 pour prendre une commande" << endl;
        cout << "Entrez 1 pour gerer les produits" << endl;
        cout << "Entrez 2 pour acceder au prix des commandes" << endl;
        cout << "Entrez 3 pour quitter" << endl;

        cin >> choice;

        if(choice == 0)	add_command();
        if(choice == 1) gestion_product();
        if(choice == 2) bilan();
    }

}
