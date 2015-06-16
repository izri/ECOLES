#include "Client.h"
#include "Plat.h"
#include "Pizza.h"
#include "Dessert.h"
#include "Boisson.h"
#include "Plat_du_jour.h"
#include "Plat_vegetarien.h"
// Tous les fichiers que nous utilisons.

int main() {
	cout << "Bienvenu dans notre restaurant" << endl; // Début du restaurant
	cout << " " << endl;

// La commande du client

	int a, b, c, e, f;

	Plat_du_jour j("plat du jour", 6);

	Plat_vegetarien v("plat vegetarien", 6);

	Pizza marguerita("Marguerita",7);
	Pizza tuna("Tuna",7);
	Pizza vegetarienne("Vegetarienne",8);		
	Pizza fromages("4_Fromages",8);
	Pizza calzone("Calzone",7);		
	Pizza mexicaine("Mexicaine",8);
	
	Dessert tiramisu("Tiramisu",4);
	Dessert mousse("Mousse au chocolat",3);
	Dessert glace("Glace",4);		
	Dessert gateau("Gateau au chocolat",4);
	
	Boisson coca("Coca-Cola",3);
	Boisson fanta("Fanta",2);
	Boisson ice_tea("Ice-tea",3);		
	Boisson perrier("Perrier",2);
	Boisson eau("Eau minerale",2);	

	Client c1("Yoav", 1);

do {
	cout << "Voici notre menu : " << endl << "Vous avez le choix entre : " << endl << "Des Pizzas (1)" << endl << "Un plat du jour (2)" << endl << "Un plat Vegetarien (3)" << endl << "Des Desserts (4)" << endl << "Des Boissons (5)" << endl; // La carte des produits.
	cout << " " << endl;
	
	cin >> a;

	switch(a) { // Le choix entre les différents produits.
        case 1 : // Nos pizzas
        	cout << "Nous vous proposons :" << endl;
		cout << "Marguerita (Fromage, Sauce tomate, Olives, Origan) = 7€ (1)" << endl << "Tuna (Fromage, Sauce tomate, Thon) = 7€ (2)" << endl << "Végétarienne (Fromage, Poivrons, Artichauts, Champignons) = 8€ (3)" << endl << "4 Fromages (Roquefort, Emmental, Reblochon, Chèvre) = 8€ (4)" << endl << "Calzone (Jambon, Oeuf, Fromage) = 7€ (5)" << endl << "Mexicaine (Merguez, Fromage, Oignons) = 8€ (6)" << endl;
		
		cin >> b;

		switch (b) { // Le choix entre les diffrentes pizzas (vous pouvez en prendre plusieurs).
			case 1 :
				cout << "Vous avez choisi une pizza Marguerita" << endl;
				c1.commande(marguerita); // Le client a commandé une pizza Marguerita	
				break;
			case 2 :
				cout << "Vous avez choisi une pizza Tuna" << endl;
				c1.commande(tuna); // Le client a commandé une pizza Tuna		
				break;
			case 3 :
				cout << "Vous avez choisi une pizza Vegetarienne" << endl;
				c1.commande(vegetarienne); // Le client a commandé une pizza Végétarienne
				break;
			case 4 : 
				cout << "Vous avez choisi une pizza 4 Fromages" << endl;
				c1.commande(fromages); // Le client a commandé une pizza 4 Fromages
				break;
			case 5 : 
				cout << "Vous avez choisi une pizza Calzone" << endl;
				c1.commande(calzone); // Le client a commandé une pizza Calzone
				break;
			case 6 : 
				cout << "Vous avez choisi une pizza Mexicaine" << endl;
				c1.commande(mexicaine); // Le client a commandé une pizza Mexicaine
				break;
			default :
            			cout << "Vous n'avez pas pris de pizza" << endl;
            			break;	
		}
		cout << " " << endl;
		cout << " " << endl;
        	break;

	case 2 : // Le plat du jour
		cout << "Vous avez pris un plat du jour à 6€" << endl;
		c1.commande(j); // Le client a commandé un plat du jour
		break;
	
	case 3 : // Le plat végétarien
		cout << "Vous avez pris un plat vegetarien à 6€" << endl; 
		c1.commande(v); // Le client a commandé un plat végétarien
		break;

        case 4 : // Nos desserts
        	cout << "Nous vous proposons :" << endl;
		cout << "Tiramisu = 4€ (1)" << endl << "Mousse au chocolat = 3€ (2)" << endl << "Glace (Vanille, Fraise, Chocolat, Citron, Framboise, Menthe) = 4€ (3)" << endl << "Gâteau au chocolat avec chantilly (au choix)= 4€ (4)" << endl; 

		cin >> c;

		switch (c) { // Le choix entre les diffrents desserts (vous pouvez en prendre plusieurs).
			case 1 :
				cout << "Vous avez choisi un Tiramisu" << endl;
				c1.commande(tiramisu); // Le client a commandé un Tiramisu
				break;
			case 2 :
				cout << "Vous avez choisi une Mousse au chocolat" << endl;
				c1.commande(mousse); // Le client a commandé une Mousse au chocolat
				break;
			case 3 :
				cout << "Vous avez choisi une Glace" << endl;
				c1.commande(glace); // Le client a commandé une Glace
				break;
			case 4 : 
				cout << "Vous avez choisi un Gateau au chocolat" << endl;
				c1.commande(gateau); // Le client a commandé un Gateau au chocolat
				break;
			default :
            			cout << "Vous n'avez pas pris de dessert" << endl;
            			break;	
		}


		cout << " " << endl;
		cout << " " << endl;
            break;
 
        case 5 : // Nos boissons
        	cout << "Nous vous proposons :" << endl;
		cout << "Cola-Cola (50cl) = 3€ (1)" << endl << "Fanta (33cl) = 2€ (2)" << endl << "Ice tea (50cl) = 3€ (3)" << endl << "Perrier (50cl) = 2€ (4)" << endl << "Eau Minerale (75cl) = 2€ (5)" << endl;

		cin >> e;

		switch (e) { // Le choix entre les diffrentes boissons (vous pouvez en prendre plusieurs).
			case 1 :
				cout << "Vous avez choisi un Coca-Cola" << endl;
				c1.commande(coca); // Le client a commandé un Coca-Cola
				break;
			case 2 :
				cout << "Vous avez choisi un Fanta" << endl;
				c1.commande(fanta); // Le client a commandé un Fanta
				break;
			case 3 :
				cout << "Vous avez choisi un Ice tea" << endl;
				c1.commande(ice_tea); // Le client a commandé un Ice-tea
				break;
			case 4 : 
				cout << "Vous avez choisi un Perrier" << endl;
				c1.commande(perrier); // Le client a commandé un Perrier
				break;
			case 5 : 	
				cout << "Vous avez choisi de l'eau minerale" << endl;
				c1.commande(eau); // Le client a commandé de l'Eau minérale	
			default :
            			cout << "Vous n'avez pas pris de boisson" << endl;
            			break;		
		}

		cout << " " << endl;
		cout << " " << endl;
            break;
 
        default :
            cout << "Pourquoi êtes vous venu ?" << endl;
            break;
    }

	cout << "Voulez-vous l'addition ? (1 pour oui / 0 pour non)" << endl; // Le choix de demander l'addition à tout moment.
	cin >> f;


} while (f==0); // On réitère les choix pour permettre de choisir plusieurs produits différents ou non.



	c1.aff(); // On affiche le montant que dois payer le client


	return 0;
}
