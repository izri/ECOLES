#include <iostream>
#include<fstream>
#include "client.hpp"
#include "produit.hpp"
#include<string>
#include<stdlib.h>

using namespace std;


int main()
{

   ofstream outFile;

   outFile.open("liste.txt",ios::out| ios::app);

 string entete("**********Nouveau Client************");
 string addition("Prix du repas: ");

   	outFile<<entete<<endl;


   string commande;
   string commande1;
   string commande2;
   string commande3;
   string commande4;
   int prix=0;
   string nomclient;
	/*Dessert premiere2("Ile flottante", 16);
	  cout << "Prix :" << premiere2.getPrix() << endl;*/
	cout << "*********************************" << endl;

	Client clt1("Amyot"), clt2("Rateau");
	clt1.afficherInfo();
	clt2.afficherInfo();

       cout<<"Entrez nom du client:"<< endl;
	getline(cin,nomclient);
	outFile<<"Client:"<<nomclient<<endl;


	cout << "**********Voici la carte des plats**********" << endl<<endl;
	cout << "Notre menu se compose d'un plat d'une boisson et d'un dessert " << endl<<endl;

	/*Produit pizza1("Margarita", 12), pizza2("Regina", 15),

pizza3("Calzone", 15);
	  pizza1.afficherInfo();
	  pizza2.afficherInfo();
	  pizza3.afficherInfo();*/


	cout << "1) Les Pizzas (- Regina - Calzone - Margarita -)" << endl;
	cout << "2) Les Plats Vegetariens (- Lasagnes Vegetariennes - Quiche Vegetariennes -)" << endl;
	cout << "3) Le plat du jour (Couscous)" << endl;
	cout << "Tapez votre choix" << endl;

	/*********WHILE POUR CHOISIR DANS LA CARTE **********/
	int y = 0;
	while(1)
	{
		cin >> y; //valeur tapée dans x
		if(y <= 0) cout << "Erreur " <<endl;
		else if(y == 1)
		{
			/**********PIZZA**********/

			Pizza premiere("1) Regina", 15, 42);
			Pizza deuxieme("2) Calzone", 15, 42);
			Pizza troisieme("3) Margarita", 15, 42);

			cout << "Les Pizzas : " << endl;
			cout << "Pizza: " << premiere.getName()<<" - "<<premiere.getPrix()<<" euros " << endl;
			cout << "Pizza: " << deuxieme.getName()<<" - "<<deuxieme.getPrix()<<" euros " << endl;
			cout << "Pizza: " << troisieme.getName() <<" - "<<troisieme.getPrix()<<" euros "<< endl;

			int x = 0;

			while(1)
			{
				cout << "Tapez votre choix: " << endl;
				cin >> x; //valeur tapée dans x
				if(x <= 0) cout << "Erreur " <<endl;
				else if(x == 1)
				{
					cout << "Regina " <<endl<<endl;
					commande="Regina";
					prix+=15;

					break;
				}
				else if(x == 2)
				{
					cout << "Calzone " <<endl<<endl;
					commande="Calzone";
					prix+=15;
					break;
				}
				else if(x == 3)
				{
					cout << "Margarita " <<endl<<endl;
					commande="Margarita";
					prix+=15;
					break;
				}
				else
				{
					cout << "Erreur" << endl;
					break;
				}

			}

			outFile<<commande<<endl;
			break;
		}



		else if(y == 2)
		{
			/**********VEGETARIEN**********/

			Vegetarien un("1) Lasagnes Vegetariennes", 10, 42);
			Vegetarien deux("2) Quiche Vegetarienne", 10, 42);

			cout << "Plats Vegetariens : " << endl;
			cout << "PV: " << un.getName() <<" - "<<un.getPrix()<<" euros "<< endl;
			cout << "PV: " << deux.getName() <<" - "<<deux.getPrix()<<" euros "<< endl;

			int i = 0;
			while(1)
			{
				cout << "Tapez votre choix: " << endl;
				cin >> i; //valeur tapée dans x
				if(i <= 0) cout << "Erreur " <<endl;
				else if(i == 1)
				{
					cout << "Lasagnes Vegetariennes " <<endl<<endl;
					commande1="LasagnesVegetariennes";
					prix+=10;
					break;
				}
				else if(i == 2)
				{
					cout << "Quiche Vegetarienne " <<endl<<endl;
					commande1="QuicheVegetarienne";
					prix+=10;
					break;
				}
				else
				{
					cout << "Erreur" << endl;
					break;
				}
			}
			outFile<<commande1<<endl;
			break;
		}
		else if(y == 3)
		{
			/**********PLATDUJOUR*********/

			Plat unos("1) Couscous", 20, 42);
			//Plat doss("2) Mergez", 16, 42);

			cout << "plat du jour : " << endl;
			cout << "PJ: " << unos.getName()<<" - "<<unos.getPrix()<<" euros " << endl;
			//cout << "PJ : " << doss.getName() << endl;

			int h = 0;
			while(1)
			{
				cout << "Tapez votre choix: " << endl;
				cin >> h; //valeur tapée dans x
				if(h <= 0) cout << "Erreur " <<endl;
				else if(h == 1)
				{
					cout << "Couscous " <<endl<<endl;
					commande2="Couscous";
					prix+=20;
					break;
				}
				/*else if(h == 2)
				  {
				  cout << "Mergez " <<endl;
				  break;
				  }*/
				else
				{
					cout << "Erreur" << endl;
					break;
				}
			}

			outFile<<commande2<<endl;

			break;
		}
		else
		{
			cout << "Erreur" << endl;
			break;
		}
	}








	/**********BOISSON*********/

	Boisson uno("1) Coca Cola", 1, 42);
	Boisson dos("2) Sprite", 1, 42);
	Boisson tres("3) Eau Plate", 1, 42);
	cout << "**********Voici la carte des Boissons**********" << endl;
	//cout << "Les Boissons : " << endl;
	cout << "Boisson: " << uno.getName()<<" - "<<uno.getPrix()<<" euros " << endl;
	cout << "Boisson: " << dos.getName() <<" - "<<dos.getPrix()<<" euros "<< endl;
	cout << "Boisson: " << tres.getName() <<" - "<<tres.getPrix()<<" euros "<< endl;


	int j = 0;
	while(1)
	{
		cout << "Tapez votre choix: " << endl;
		cin >> j; //valeur tapée dans x
		if(j <= 0) cout << "Erreur " <<endl;
		else if(j == 1)
		{
			cout << "Coca Cola " <<endl<<endl;
			commande3="CocaCola";
			prix+=1;
			break;
		}
		else if(j == 2)
		{
			cout << "Sprite " <<endl<<endl;
			commande3="Sprite";
			prix+=1;
			break;
		}
		else if(j == 3)
		{
			cout << "Eau Plate " <<endl<<endl;
			commande3="EauPlate";
			prix+=1;
			break;
		}
		else
		{
			cout << "Erreur" << endl;
			break;
		}



	}

	outFile<<commande3<<endl;

	/**********DESSERT*********/

	Boisson eins("1) Gateau Chocolat", 5, 42);
	Boisson zwei("2) Glace Vanille", 5, 42);
	Boisson drei("3) Glace framboise", 5, 42);
	cout << "**********Voici la carte des Desserts**********" << endl;
	//cout << "Les Boissons : " << endl;
	cout << "Dessert: " << eins.getName()<<" - "<<eins.getPrix()<<" euros " << endl;
	cout << "Dessert: " << zwei.getName() <<" - "<<zwei.getPrix()<<" euros "<< endl;
	cout << "Dessert: " << drei.getName() <<" - "<<drei.getPrix()<<" euros "<< endl;

	int k = 0;
	while(1)
	{
		cout << "Tapez votre choix: " << endl;
		cin >> k; //valeur tapée dans x
		if(k <= 0) cout << "Erreur " <<endl;
		else if(k == 1)
		{
			cout << "Gateau Chocolat " <<endl<<endl;
			commande4="GateauChocolat";
			prix+=5;
			break;
		}
		else if(k == 2)
		{
			cout << "Glace Vanille " <<endl<<endl;
			commande4="GlaceVanille";
			prix+=5;
			break;
		}
		else if(k == 3)
		{
			cout << "Glace Framboise " <<endl<<endl;
			commande4="GlaceFramboise";
			prix+=5;
			break;
		}
		else
		{
			cout << "Erreur" << endl;
			break;
		}
	}

          outFile<<commande4<<endl;
          outFile<<addition;
          outFile<<prix<<endl;


		ifstream inFile;

         inFile.open("liste.txt");



	//Check file open//

	if(inFile.fail()){

	 cerr<<"non ouverture du fichier"<< endl;

	 exit(1);

	}


 string bestp;
 int count[12];



 	for(int j(0);j<12;j++){

	 	count[j]=0;

	 }



	while(!inFile.eof()){

	 inFile>>bestp;


	 if(bestp=="Regina"){
		count[0]++;

	 }


	 if(bestp=="Calzone"){
		count[1]++;
	 }



	 if(bestp=="Margarita"){
		count[2]++;

	 }



	 if(bestp=="LasagnesVegetariennes"){
		count[3]++;

	 }



	if(bestp=="QuicheVegetarienne"){
		count[4]++;

	}


	if(bestp=="Couscous"){
		count[5]++;


	}



	if(bestp=="CocaCola"){
		count[6]++;



	}


	if(bestp=="Sprite"){
		count[7]++;


	}


	if(bestp=="EauPlate"){
		count[8]++;


	}

	if(bestp=="GateauChocolat"){
		count[9]++;


	}
	if(bestp=="GlaceVanille"){
		count[10]++;


	}

	if(bestp=="GlaceFramboise"){
		count[11]++;


	}


	}

	inFile.close();

 int max=0;

  max=count[0];

	for(int i(0);i<12;i++){

	 if(max<count[i]){

		max=count[i];

	 }

	}


	cout<<"Le plat le plus apprecier";
	if(max==count[0]){
		cout<<" Regina"<< endl;


	}


	if(max==count[1]){
		cout<<" Calzone"<< endl;


	}


	if(max==count[2]){
		cout<<" Margarita"<< endl;


	}


	if(max==count[3]){
		cout<<" Lasagnes Vegetariennes"<< endl;


	}

	if(max==count[4]){
		cout<<" Quiche Vegetarienne"<< endl;


	}



	if(max==count[5]){
		cout<<" Couscous"<< endl;


	}


	if(max==count[6]){
		cout<<" Coca Cola"<< endl;


	}


	if(max==count[7]){
		cout<<" Sprite"<< endl;


	}


	if(max==count[8]){
		cout<<" Eau Plate"<< endl;


	}


	if(max==count[9]){
		cout<<" Gateau Chocolat"<< endl;


	}

	if(max==count[10]){
		cout<<" Glace Vanille"<< endl;


	}



	if(max==count[11]){
		cout<<" Glace Framboise"<< endl;


	}

	cout<<endl;



	cout<<"Prix du repas: "<<prix<<" euros"<< endl;

	if(nomclient=="Samuel"){

	outFile<<"Historique des prix du client Samuel dans TotalSa.txt: "<<endl;

	}



	if(nomclient=="Jeremie"){

	outFile<<"Historique des prix du client Jeremie dans TotalEd.txt: "<<endl;

	}


/*************Fichier Samuel Historique Prix*************/

	ofstream outFile1;

	if(nomclient=="Samuel"){



        outFile1.open("TotalSa.txt",ios::out| ios::app);

        int bg=0;

        bg=prix;

        outFile1<<bg<<endl;



	}

	/*************Fichier Jeremie Historique Prix*************/

	ofstream outFile2;

	if(nomclient=="Jeremie"){



        outFile2.open("TotalJe.txt",ios::out| ios::app);

        int bg1=0;

        bg1=prix;

        outFile2<<bg1<<endl;



	}


  	/************Lecture TotalSa.txt*********/



 ifstream inFile1;

 inFile1.open("TotalSa.txt");

 int supp;
 int full=0;

	//Check file open//

	if(inFile1.fail()){

	 cerr<<"File doesn't open"<< endl;

	 exit(1);

	}


	while(!inFile1.eof()){

	 inFile1>>supp;



	 full+=supp;



	}

	inFile1.close();

	outFile1<<"Total "<<full<<"euros"<<endl;


	return 0;
       }
