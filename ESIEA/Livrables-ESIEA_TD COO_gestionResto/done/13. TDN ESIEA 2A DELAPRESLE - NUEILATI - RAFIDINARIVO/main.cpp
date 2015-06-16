#include <iostream>
#include "Commande.h"
#include "Plat.h"
#include "Pizza.h"
#include "Dessert.h"
#include "Boisson.h"
#include "PlatDuJour.h"
#include "Plat_Vegetarien.h"

using namespace std;

int main()
{
	int input = 0;
	int reponse = 0;
	int repas = 0;

	cout << "Bonjour et bienvenue dans notre restaurant" << endl;
	cout << " " << endl;

	//Le menu
	Plat_Vegetarien salade("Salade Verte", 5);
	Plat_Vegetarien nems("Nems végétariens", 5);
	Plat_Vegetarien terrine("Terrine de lentilles", 5);
	Plat_Vegetarien tarte("Tarte aux courgettes", 5);

	Boisson orangina("Orangina",2);
	Boisson coca("Coca-Cola",2);
	Boisson oasis("Oasis",2);		
	Boisson vin("Vin Rouge",2);

	Pizza provencale("La Provencale",7);
	Pizza orientale("L'Orientale",7);
	Pizza cannibale("La Cannibale",7);		
	Pizza indienne("L'Indienne",7);

	PlatDuJour tajine("Tajine Saoudien", 6);
	PlatDuJour boeuf("Boeuf Frites", 6);
	PlatDuJour tagliatelles("Tagliatelles chèvre", 6);
	PlatDuJour poulet("Poulet tandoori", 6);

	Dessert fondant("Fondant Chocolat",4);
	Dessert tiramisu("Tiramisu Italienne",4);
	Dessert clafoutis("Clafoutis Cerise",4);		
	Dessert flan("Flan à la banane",4);

	Commande client("Alexis");

	do
	{
		cout << "Choississez une famille de produit :" << endl <<"1. Plats du jours" << endl << "2. Plats végétariens" << endl <<"3. Pizzas"<< endl <<"4.Boissons" << endl <<"5.Desserts"<< endl;

		cout <<"Selection: ";
		cin>> input;
		switch (input){
			case 1:
				cout <<"Voici nos différents plats du jour ainsi que leurs prix: "<< endl;
				cout <<"1.Tajine Saoudien / 6 euros" << endl <<"2.Boeuf Frites / 6 euros" << endl << "3.Tagliatelles chèvre / 6 euros" << endl << "4.Poulet tandoori / 6 euros" << endl;
				cout <<"Selection: ";
				cin>> input;
				switch(input){
					case 1 :
						cout << "Tajine Saoudien" << endl;
						client.commander(tajine); 	
						break;
					case 2 :
						cout << "Boeuf Frites" << endl;
						client.commander(boeuf); 		
						break;
					case 3 :
						cout << "Tagliatelles chèvre" << endl;
						client.commander(tagliatelles);
						break;
					case 4 : 
						cout << "Poulet tandoori" << endl;
						client.commander(poulet); 
						break;
					default :
						cout << "Je ne comprends pas votre commande" << endl;
						break;	
				}
				cout << " " << endl;
				break;
			case 2:
				cout <<"Voici nos différents plats végétariens ainsi que leurs prix: "<< endl;
				cout <<"1.Salade Verte / 5 euros" << endl <<"2.Nems végétariens / 5 euros" << endl << "3.Terrine de lentilles / 5 euros" << endl << "4.Tarte aux courgettes / 5 euros" << endl;
				cout <<"Selection: ";
				cin>> input;
				switch(input){
					case 1 :
						cout << "Salade Verte" << endl;
						client.commander(salade); 	
						break;
					case 2 :
						cout << "Nems végétariens" << endl;
						client.commander(nems); 		
						break;
					case 3 :
						cout << "Terrine de lentilles" << endl;
						client.commander(terrine);
						break;
					case 4 : 
						cout << "Tarte aux courgettes" << endl;
						client.commander(tarte); 
						break;
					default :
						cout << "Je ne comprends pas votre commande" << endl;
						break;	
				}
				cout << " " << endl;
				break;
			case 3:
				cout <<"Voici nos différentes pizzas ainsi que leurs prix: "<< endl;
				cout <<"1.La Provencale / 7 euros" << endl <<"2.L'Orientale / 7 euros" << endl << "3.La Cannibale / 7 euros" << endl << "4.L'Indienne / 7 euros" << endl;
				cout <<"Selection: ";
				cin>> input;
				switch(input){
					case 1 :
						cout << "La Provencale" << endl;
						client.commander(provencale); 	
						break;
					case 2 :
						cout << "L'Orientale" << endl;
						client.commander(orientale); 		
						break;
					case 3 :
						cout << "La Cannibale" << endl;
						client.commander(cannibale);
						break;
					case 4 : 
						cout << "L'Indienne" << endl;
						client.commander(indienne); 
						break;
					default :
						cout << "Je ne comprends pas votre commande" << endl;
						break;	
				}
				cout << " " << endl;
				break;
			case 4:
				cout <<"Voici nos différentes boissons ainsi que leurs prix: "<< endl;
				cout <<"1.Orangina/ 2 euros" << endl <<"2.Coca-Cola / 2 euros" << endl << "3.Oasis / 2 euros" << endl << "4.Vin Rouge / 2 euros" << endl;
				cout <<"Selection: ";
				cin>> input;
				switch(input){
					case 1 :
						cout << "Orangina" << endl;
						client.commander(orangina); 	
						break;
					case 2 :
						cout << "Coca-Cola" << endl;
						client.commander(coca); 		
						break;
					case 3 :
						cout << "Oasis" << endl;
						client.commander(oasis);
						break;
					case 4 : 
						cout << "Vin Rouge" << endl;
						client.commander(vin); 
						break;
					default :
						cout << "Je ne comprends pas votre commande" << endl;
						break;	
				}
				cout << " " << endl;
				break;
			case 5:
				cout <<"Voici nos différents desserts ainsi que leurs prix: "<< endl;
				cout <<"1.Fondant Chocolat / 4 euros" << endl <<"2.Tiramisu Italienne/ 4 euros" << endl << "3.Clafoutis Cerise / 4 euros" << endl << "4.Flan à la banane / 4 euros" << endl;
				cout <<"Selection: ";
				cin>> input;
				switch(input){
					case 1 :
						cout << "Fondant Chocolat" << endl;
						client.commander(fondant); 	
						break;
					case 2 :
						cout << "Tiramisu Italienne" << endl;
						client.commander(tiramisu); 		
						break;
					case 3 :
						cout << "Clafoutis Cerise" << endl;
						client.commander(clafoutis);
						break;
					case 4 : 
						cout << "Flan à la banane" << endl;
						client.commander(flan); 
						break;
					default :
						cout << "Je ne comprends pas votre commande" << endl;
						break;	
				}
				cout << " " << endl;
				break;
			default :
				cout << "Vous n'avez rien commandé .." << endl;
				break;
		}
		repas += 1;
		cout << "Voulez-vous autre chose ? 1.oui ou 2.non" << endl; 
		cin >> reponse;
	} while (reponse == 1); 
	client.afficher(); cout << "Vous avez commandé: " << repas << " repas" << endl;
	return 0;
}


