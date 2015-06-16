#include <iostream>
#include <string>

using namespace std;


class Client {
	private :
		string prenom, nom;

	public :
		Client(string prenom, string nom)
		: prenom(prenom), nom(nom) {}
		string getprenom() { return prenom; }
		string getnom() { return nom; }
		
		void print() { cout << "La commande de "<< prenom  <<" " <<  nom <<" est :" << endl;


 }
};

class Product {
	private :
		string name;
		float price;
	public :
		Product(string name, float price) : name(name), price(price) {}
		string getname() { return name; }
		float getprice() { return price; }
		
			void print() {  cout << "-"<< price << endl;             }
};

class Command {
	private :
		Client client;
		Product product;
	public :
		Command(Client client, Product product) : client(client), product(product) {}
		Client get_client() { return client; }
		Product get_product() { return product; }
		

};


int main() {

int choice;
int compte; 
string prenom;
string nom;
string produit;
int total = 0;

//Declaration des produits

Product eau("Eau", 2.0);
Product alcool("Alcool", 4.0);
Product soda("Soda", 3.5); 
Product pizza("Pizza", 10.0);
Product pates("Pates", 9.0);
Product vegan("Vegan", 13.5);
Product moelleux("Moelleux", 5.0);
Product creme("Creme", 5.5);
Product fraisier("Vegan", 5.0);   

  

cout << "prenom du client ?" <<endl;
cin>>prenom;
cout << "nom du client ?" <<endl;
cin>>nom;
 

//Declaration du client numéro 1


Client numero1(prenom,nom);


   cout << "Faite votre choix :" << endl;

   cout << "1.Carafe d'eau" << endl;
   cout << "2.Boisson alcoolisee" << endl;
   cout << "3.Soda" << endl;
   cout << "4.Pizza" << endl;
   cout << "5.Pates" << endl;
   cout << "6.Plat Vegan avec sa sauce de tofue" << endl;
   cout << "7.Moelleux au chocolat" << endl;
   cout << "8.Creme brulee" << endl;
   cout << "9.Fraisier" << endl;

   cin>>choice;

   switch(choice) { 
 
   case 1 :  produit = "Carafe d'eau";  total = total + 2; break; 

   case 2 :  produit = "Boisson alcoolisee"; total = total + 4;  break;
  
   case 3 :  produit = "Soda"; total = total + 3.5;  break;

   case 4 :  produit = "Pizza"; total = total + 10;  break;

   case 5 :  produit = "Pates"; total = total + 9; break;

   case 6 :  produit = "Plat Vegan avec sa sauce de tofue"; total = total + 13.5;  break;
 
   case 7 :  produit = "Moelleux au chocolat"; total = total + 5.0; break;

   case 8 :  produit = "Creme brulee"; total = total + 5.5; break; 

   case 9 :  produit = "Fraisier"; total = total + 5.0;  break; 
}

     // Command cmdnumero1(prenom, produit);

	

    numero1.print();                                    //affichage de la commande 
    
    cout << "-" << produit << endl;
    cout << "Le prix de la commande est de : " <<endl;
    
    

  
     switch(choice) { 
 
   case 1 :  eau.print();     break; 

   case 2 :  alcool.print();  break;
  
   case 3 :  soda.print();    break;

   case 4 :  pizza.print();   break;

   case 5 :  pates.print();   break;

   case 6 :  vegan.print();   break;
 
   case 7 :  moelleux.print();   break;

   case 8 :  creme.print();      break; 

   case 9 :  fraisier.print();   break; 
}

cout << "prenom du client ?" <<endl;
cin>>prenom;
cout << "nom du client ?" <<endl;
cin>>nom;
 

//Declaration du client numéro 2 


Client numero2(prenom,nom);


   cout << "Faite votre choix :" << endl;

   cout << "1.Carafe d'eau" << endl;
   cout << "2.Boisson alcoolisee" << endl;
   cout << "3.Soda" << endl;
   cout << "4.Pizza" << endl;
   cout << "5.Pates" << endl;
   cout << "6.Plat Vegan avec sa sauce de tofue" << endl;
   cout << "7.Moelleux au chocolat" << endl;
   cout << "8.Creme brulee" << endl;
   cout << "9.Fraisier" << endl;

   cin>>choice;

  switch(choice) { 
 
   case 1 :  produit = "Carafe d'eau";  total = total + 2; break; 

   case 2 :  produit = "Boisson alcoolisee"; total = total + 4;  break;
  
   case 3 :  produit = "Soda"; total = total + 3.5;  break;

   case 4 :  produit = "Pizza"; total = total + 10;  break;

   case 5 :  produit = "Pates"; total = total + 9; break;

   case 6 :  produit = "Plat Vegan avec sa sauce de tofue"; total = total + 13.5;  break;
 
   case 7 :  produit = "Moelleux au chocolat"; total = total + 5.0; break;

   case 8 :  produit = "Creme brulee"; total = total + 5.5; break; 

   case 9 :  produit = "Fraisier"; total = total + 5.0;  break; 
}


     // Command cmdnumero1(prenom, produit);

	

    numero2.print();                                    //affichage de la commande 
    
    cout << "-" << produit << endl;
    cout << "Le prix de la commande est de : " <<endl;
    
    

  
     switch(choice) { 
 
   case 1 :  eau.print();     break; 

   case 2 :  alcool.print();  break;
  
   case 3 :  soda.print();    break;

   case 4 :  pizza.print();   break;

   case 5 :  pates.print();   break;

   case 6 :  vegan.print();   break;
 
   case 7 :  moelleux.print();   break;

   case 8 :  creme.print();      break; 

   case 9 :  fraisier.print();   break; 
}

   
 cout << "prenom du client ?" <<endl;
cin>>prenom;
cout << "nom du client ?" <<endl;
cin>>nom;
 

//Declaration du client numéro 3 


Client numero3(prenom,nom);


   cout << "Faite votre choix :" << endl;

   cout << "1.Carafe d'eau" << endl;
   cout << "2.Boisson alcoolisee" << endl;
   cout << "3.Soda" << endl;
   cout << "4.Pizza" << endl;
   cout << "5.Pates" << endl;
   cout << "6.Plat Vegan avec sa sauce de tofue" << endl;
   cout << "7.Moelleux au chocolat" << endl;
   cout << "8.Creme brulee" << endl;
   cout << "9.Fraisier" << endl;

   cin>>choice;

   switch(choice) { 
 
   case 1 :  produit = "Carafe d'eau";  total = total + 2; break; 

   case 2 :  produit = "Boisson alcoolisee"; total = total + 4;  break;
  
   case 3 :  produit = "Soda"; total = total + 3.5;  break;

   case 4 :  produit = "Pizza"; total = total + 10;  break;

   case 5 :  produit = "Pates"; total = total + 9; break;

   case 6 :  produit = "Plat Vegan avec sa sauce de tofue"; total = total + 13.5;  break;
 
   case 7 :  produit = "Moelleux au chocolat"; total = total + 5.0; break;

   case 8 :  produit = "Creme brulee"; total = total + 5.5; break; 

   case 9 :  produit = "Fraisier"; total = total + 5.0;  break; 
}

     // Command cmdnumero1(prenom, produit);

	

    numero3.print();                                    //affichage de la commande 
    
    cout << "-" << produit << endl;
    cout << "Le prix de la commande est de : " <<endl;
    
    

  
     switch(choice) { 
 
   case 1 :  eau.print();     break; 

   case 2 :  alcool.print();  break;
  
   case 3 :  soda.print();    break;

   case 4 :  pizza.print();   break;

   case 5 :  pates.print();   break;

   case 6 :  vegan.print();   break;
 
   case 7 :  moelleux.print();   break;

   case 8 :  creme.print();      break; 

   case 9 :  fraisier.print();   break; 
}       
	
cout << "Le cout total de la commande est de  : "  << total << " euros" <<endl;	

}