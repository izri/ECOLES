#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "commande.hpp"

using namespace std;



Client::Client(string nom,float age,bool sexe,int etoile){
	m_nom=nom; 
	m_age=age;
	m_sexe=sexe;
	m_etoile=etoile;
}

void Client::client_print(){
	cout << "Client : ";
	if(m_sexe==true) cout << "Mr.";
	else cout << "Mme.";

	cout << m_nom << " a " << m_age << " ans et a " << m_etoile << " etoiles" << endl;

}

string Client::getNom(){
	return m_nom;
}

float Client::getAge(){
	return m_age;
}

bool Client::getSexe(){
	return m_sexe;
}

int Client::getEtoile(){
	return m_etoile;
}

Product::Product(const string name, const float price){
	m_name=name;
	m_price=price;
}


const string Product::get_name(){
	return m_name;
}


const float Product::get_price(){
	return m_price;
}

void Product::product_print(){
	cout << "Product : " << m_name << endl<<"Cost: "<< m_price <<" € l'unité."<< endl; 
}




Commande::Commande(Client client,Product produit, float quantite): m_client(client), m_produit(produit), m_quantite(quantite){}


const Client Commande::getClient(){
	return m_client;
}

const Product Commande::getProduct(){
	return m_produit;
}

const float Commande::getQuantite(){
	return m_quantite;
}

void Commande::commande_print(){
	cout << endl;
	m_client.client_print(); 
	m_produit.product_print();
	cout << "En " << m_quantite << " fois" << endl;
}

float Commande::addition(){
	return m_produit.get_price()*m_quantite;
}


Node::Node(Client client,Node *succ1): info(client), succ(succ1){}


Node *recherche(Node *client,string name){

	while(client!=NULL&&client->info.getNom()!=name){
		client=client->succ;
	}

	if(client ==NULL)
		return NULL;


	return client;
}




int main(){



	float addition;

	Client alex("Alex",19,true,10);

	Product pizza("Pizza",10);
	Product dessert("Dessert",2);
	Product vegetarien("Vegan",8);
	Product boisson("Boisson",5);
	Product pdj("Plat du jour",12);

	Node n(alex,NULL);
	Node *tete=&n;
	Node *queue=&n;
	string ClientName;
	float ClientAge;
	int ClientSexe;
	bool Sexe;
	int flag;
	int commande;
	int nombre;
	cout << "Veuillez rentrer un chiffre "<< endl <<"1. Rechercher un client." << endl << "2.Inscrire un client"<< endl <<"3.Commande (utilisateur déjà enregistré)" << endl << "4.Quitter"<< endl;
	cin >> flag;

	while(flag!=4){
		n=*tete;
		
		if(flag==1){
			cout << "Entrer un nom à chercher."<< endl ;
			string name;

			cin >> name;

			Node *seekName=recherche(&n,name);


			if(seekName!=NULL){
				seekName->info.client_print();
			}

			else{
				cout << "Monsieur ou Madame " << name << " n'est jamais venu au restaurant, veuillez l'inscrire" << endl ;

			}
		}

		if(flag== 2){

			cout << "Rentrez le nom du client"<< endl;
			cin >> ClientName;
			cout << "Rentrez l'age du client"<< endl;
			cin >> ClientAge;
			cout << "Rentrez le sexe du client(0 pour les filles et autre pour les garcons)"<< endl;
			cin >> ClientSexe;
			if(ClientSexe==0){
				Sexe=false;
			}
			else { Sexe=true;}
			Client nouveauClient(ClientName,ClientAge,Sexe,0);
			Node nouveauNoeud(nouveauClient,NULL);
			queue->succ=&nouveauNoeud;
			queue=&nouveauNoeud;
		}

		if(flag==3){
                        n=*tete;
			cout << "Entrer le nom de la personne (déjà enregistré) qui commande."<< endl ;
			string name;

			cin >> name;

			Node *seekName=recherche(&n,name);

			if(seekName!=NULL){
				seekName->info.client_print();
                                cout << endl << endl;
				cout << "1.Pizza" << endl << "2.Plat du Jour" << endl << "3.Vegetarien" << endl << "4.Boisson" << endl << "5.Dessert" << endl ;
				cin >> commande;
				cout << "Combien?" << endl;
				cin >> nombre;

				if(commande==1){
					Commande newCommande(seekName->info,pizza,nombre);
					newCommande.commande_print();
					addition=newCommande.addition();
					cout << "L'addition total est de: "<< addition << " €" << endl;

				}
				if(commande==2){
					Commande newCommande(seekName->info,pdj,nombre);
					newCommande.commande_print();
					addition=newCommande.addition();
					cout << "L'addition total est de: "<< addition << " €" << endl;
				}
				if(commande==3){
					Commande newCommande(seekName->info,vegetarien,nombre);
					newCommande.commande_print();
					addition=newCommande.addition();
					cout << "L'addition total est de: "<< addition << " €" << endl;
				}
				if(commande==4){
					Commande newCommande(seekName->info,boisson,nombre);
					newCommande.commande_print();
					addition=newCommande.addition();
					cout << "L'addition total est de: "<< addition << " €" << endl;
				}
				if(commande==5){
					Commande newCommande(seekName->info,dessert,nombre);
					newCommande.commande_print();
					addition=newCommande.addition();
					cout << "L'addition total est de: "<< addition << " €" << endl;
				}


			}
			else{
				cout << "Le client " << name << " n'existe pas, veuillez l'inscrire" << endl ; 
			}
		}
		if(flag!=1&&flag!=2&&flag!=3){
			break;
		}

		cout << "Veuillez rentrer un chiffre "<< endl <<"1. Rechercher un client." << endl << "2.Inscrire un client"<< endl <<"3.Commande (utilisateur déjà enregistré)" << endl << "4.Quitter"<< endl;
		cin >> flag;
	}

	
	return 0;
}
