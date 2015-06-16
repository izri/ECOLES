#include "commande.hpp"

using namespace std;

void ClearScreen()
{
    cout << string(12, '\n');
}

Plat::Plat(int ID)
{
    switch(ID)
    {
        case 1:
            name = "Pizza";
            price = 6.25;
            break;

        case 2:
            name = "Plat du Jour";
            price = 7;
            break;

        case 3:
            name = "Poisson";
            price = 6.5;
            break;

        case 4:
            name = "Boisson";
            price = 0.80;
            break;

        case 5:
            name = "Dessert";
            price = 4;
            break;

        default:
            cout << "     *** Te fous pas de ma gueule." << endl;
            exit(-1);
    }
}

Commande::Commande(Plat eat, uint _quantity, int _day, int _month, int _year)
{
    meal = {eat};
    quantity = {_quantity};
    year = _year;
    month = _month;
    day = _day;

}

Client::Client(std::string _name)
{
    name = _name;
}


void Client::addCommande(Commande _command)
{
    command.push_back(_command);
}

void Commande::addMeal(Plat eat, uint _quantity)
{
    vector<uint>::iterator debQ = quantity.begin();
    int flag=1;

    for(vector<Plat>::const_iterator debPl = meal.begin() ; debPl != meal.end() ; debPl ++)
    {
        if(eat.name == debPl->name)
        {
          flag = 0;
          (*debQ) = (*debQ) + _quantity;

        }

        debQ ++;
    }

    if(flag == 1)
    {
    meal.push_back(eat);
    quantity.push_back(_quantity);
    }
}

double Commande::getPriceMeal(string name)
{
    double price = 0;
    vector<uint>::const_iterator debQ = quantity.begin();

    for(vector<Plat>::const_iterator debPl = meal.begin() ; debPl != meal.end() ; debPl ++)
    {
        price += (debPl->price) * (*debQ);
        debQ ++;
    }

    ifstream listClient("client.txt", ios::app);
    string ligne;
    string ligneComparee("NOM : " + name);

    if(listClient)
    {
        while(getline(listClient, ligne) && ligne.compare(ligneComparee)!=0)
        {

        }

        getline(listClient,ligne);

        if(ligne == "10")
        {
            cout << "          Reduction (-20%) !! Merci pour votre fidelite ! ***" << endl;
            price = price - (20*price/100);
        }

    }

    return price;
}

void Commande::affichage(string name)
{
    cout << "\n\n Vous avez commande : " << endl;

    vector<uint>::iterator debQ = quantity.begin();

    for(vector<Plat>::iterator debPl = meal.begin() ; debPl != meal.end() ; debPl++ )
    {
        cout << "\n                    " << (*debQ) << "x " << debPl->name << " pour " << (debPl->price) * (*debQ) << " euros" << endl;
        debQ++;
    }

    cout << "\n\n Pour un prix de : " << getPriceMeal(name) << " euros" << endl;
    cout << "\n Le " << day << " / " << month << " / " << year << endl;
    cout << "\n\n                        *** Bon appetit! ***" << endl;

}

void Commande::fichierEspion (string name)
{

	ofstream renseignement("registre.txt", ios::app);

	if (renseignement)
	{
		renseignement << endl << "NOM : " << name << endl;
		renseignement << "DATE : " << day << " / " << month << " / " << year << endl;
		renseignement << "PRIX : " << getPriceMeal(name) << " euros " << endl;
		renseignement << "PLATS COMMANDES :" << endl;


		vector<Plat>::iterator iterIntoxEnApproche = meal.begin();
		vector<uint>::iterator iterQuantite = quantity.begin();

		for (;iterIntoxEnApproche != meal.end(); ++iterIntoxEnApproche, ++iterQuantite)
		{
			if (iterIntoxEnApproche->price == 0)
			{
				++iterIntoxEnApproche;
				++iterQuantite;
			}

			renseignement << iterIntoxEnApproche -> name << " x " << *iterQuantite << endl;
		}

	}

	else
	{
		cout << endl << endl << "Desole mais nous n'avons plus d'encre." << endl << endl;
	}
}

// Fonctions hors classes

int clientExist(std::string name)
{
    ifstream nameList("client.txt", ios::app);
    string ligne;
    string ligneComparee ("NOM : " + name);

    if(nameList)
    {
        while (getline(nameList, ligne))
        {
            if(ligne.compare(ligneComparee) == 0)
            {
                return 1;
            }
        }

        return 0;
    }

    else
    {
      return -1;
    }
}

void addEntrance(string name)
{

    string ligne;
    char a;
    char b;
    string ligneComparee("NOM : " + name);
    ifstream oldClient("client.txt");
    ofstream newClient("client2.txt", ios::app);


    if(clientExist(name) == 1)
    {

        if(oldClient)
        {
            while(getline(oldClient, ligne) && ligne.compare(ligneComparee)!=0)
            {
                newClient << ligne << endl;
            }

            newClient << ligne << endl;
            oldClient.get(a);
            if(a == '9')
            {
                newClient << "10";
            }
            else
            {
                if(a == '1')
                {
                    oldClient.get(b);

                    if(b == '0')
                    {
                        newClient << 1;
                    }

                    else
                    {
                        a = a+1;
                        newClient << a;
                    }
                }

                else
                {
                    a = a+1;
                    newClient << a;
                }
            }

            while(getline(oldClient, ligne))
            {
                newClient << ligne << endl;
            }

            newClient.close();
            oldClient.close();

            remove("client.txt");
            rename("client2.txt", "client.txt");
        }
    }

    else
    {
        addClient(name);
    }

    newClient.close();
    remove("client2.txt");

}

void addClient(string name)
{

    ofstream listClient("client.txt", ios::app);

    if(listClient)
    {
        listClient << endl << "NOM : " << name << endl;
        listClient << "1" << endl;
    }

    else
    {
        cout << endl << endl << "Desole mais nous n'avons plus d'encre." << endl << endl;
    }
}

void addPlat(int ID, int quantity)
{
    ofstream mealListW("plat.txt", ios::app);
    int i;

    switch(ID)
    {
        case 1:

            if(mealListW)
            {
              for(i=0 ; i<quantity ; i++)
              {
              mealListW << " 1 " << endl;
              }
            }
            break;

        case 2:
            if(mealListW)
            {
              for(i=0 ; i<quantity ; i++)
              {
              mealListW << " 2 " << endl;
              }
            }
            break;

        case 3:
            if(mealListW)
            {
              for(i=0 ; i<quantity ; i++)
              {
              mealListW << " 3 " << endl;
              }
            }
            break;

        case 4:
            if(mealListW)
            {
              for(i=0 ; i<quantity ; i++)
              {
              mealListW << " 4 " << endl;
              }
            }
            break;

        case 5:
            if(mealListW)
            {
              for(i=0 ; i<quantity ; i++)
              {
              mealListW << " 5 " << endl;
              }
            }
            break;
    }
}

void freqPlat()
{
    ifstream plateList("plat.txt", ios::app);
    string ligne;

    int pizza=0;
    int pdj=0;
    int boisson=0;
    int poisson=0;
    int dessert=0;

    cout << "      *** Resume des commandes ***" << endl;

    if(plateList)
    {
        while(getline(plateList, ligne))
        {

            if(ligne.compare(" 1 ") == 0)
            {
                pizza = pizza + 1;
            }

            if(ligne.compare(" 2 ") == 0)
            {
                pdj++;
            }

            if(ligne.compare(" 3 ") == 0)
            {
                poisson++;
            }

            if(ligne.compare(" 4 ") == 0)
            {
                boisson++;
            }

            if(ligne.compare(" 5 ") == 0)
            {
                dessert++;
            }

        }


    cout << " Pizza x" << pizza << endl;
    cout << " PDJ x" << pdj << endl;
    cout << " Poisson x" << poisson << endl;
    cout << " Boisson x" << boisson << endl;
    cout << " Dessert x" << dessert << endl << endl;
    }

    else
    {
        cout << endl << "   Desole, personne n'est passe chez vous. :-(" << endl;
    }
}

void clearHisto()
{
    ofstream registre("registre.txt");
    ofstream plat("plat.txt");

    registre << endl;
    plat << endl;

    return;
}

