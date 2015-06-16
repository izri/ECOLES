#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>
#include "client.hpp"
#include "product.hpp"
#include "command.hpp"
using namespace std;

ostream& operator<<(ostream& s, Client c) { return s << c.to_string(); }
ostream& operator<<(ostream& s, Product o) { return s << o.to_string(); }

void hist_client(Client client){
	string nom, prenom, contenue;
	int nb_visite;
	bool exist=false;
	ifstream histofile ("./data/historique_client.txt",ios::in);
	ofstream tempfile("./data/temp.txt", ios::trunc);
	if(histofile){
		if(tempfile){
			getline(histofile, contenue);
			tempfile << contenue<< endl;
			tempfile << "nom" << " " << "prenom" << " "<< 0<< endl;
			do{
				histofile >> nom >> prenom >> nb_visite;
				if(nom.compare(client.get_last_name())==0 && prenom.compare(client.get_first_name())==0){
					exist=true;
					nb_visite++;
				}
				if(nom.compare("nom")!=0 && prenom.compare("prenom")!=0)
					tempfile << nom << " "<< prenom << " "<< nb_visite << endl;
				
			}while(histofile.eof()==false);
			
			if(exist==false)
				tempfile << client.get_last_name() << " "<< client.get_first_name() << " "<< 1 << endl;
			tempfile << "nom" << " " << "prenom" << " "<< 0<< endl;
			histofile.close();
			tempfile.close();
			ofstream histofile ("./data/historique_client.txt",ofstream::binary);
			ifstream tempfile("./data/temp.txt", ofstream::binary);
			if(histofile){
				if(tempfile){
					tempfile.seekg (0,tempfile.end);
  					long size = tempfile.tellg();
 					tempfile.seekg (0);
  					char* buffer = new char[size];
  					tempfile.read (buffer,size);
 					histofile.write (buffer,size);
 					delete[] buffer;
  					histofile.close();
  					tempfile.close();
				}else{
					cerr << "ouverture temp.txt impossible"<<endl;
					exit (-1);
				}

			}else{
				cerr << "ouverture historique_client.txt impossible"<<endl;
				exit (-1);
			}

		}else{
			cerr << "ouverture temp.txt impossible"<<endl;
			exit (-1);
		}

	}else{
		cerr << "ouverture historique_client.txt impossible"<<endl;
		exit (-1);
	}

}
void meilleur_client(){
	string nom1="nom", prenom1="prenom", nom2="nom", prenom2="prenom", nom3="nom", prenom3="prenom", nomTemp, prenomTemp, contenue;
	int nb_commande1=0, nb_commande2=0, nb_commande3=0, nb_commandeTemp;

	ifstream histofile ("./data/historique_client.txt",ios::in);
	if(histofile){
		getline(histofile, contenue);
		do{
				histofile >> nomTemp >> prenomTemp >> nb_commandeTemp;
				if(nb_commandeTemp>=nb_commande1){
					nb_commande3=nb_commande2;
					nom3=nom2;
					prenom3=prenom2;
					nb_commande2=nb_commande1;
					nom2=nom1;
					prenom2=prenom1;
					nb_commande1=nb_commandeTemp;
					nom1=nomTemp;
					prenom1=prenomTemp;
				}else if(nb_commandeTemp>=nb_commande2){
					nb_commande3=nb_commande2;
					nom3=nom2;
					prenom3=prenom2;
					nb_commande2=nb_commandeTemp;
					nom2=nomTemp;
					prenom2=prenomTemp;
				}else if(nb_commandeTemp>=nb_commande3){
					nb_commande3=nb_commandeTemp;
					nom3=nomTemp;
					prenom3=prenomTemp;
				}	
		}while(histofile.eof()==false);
		cout<<"Top 3 des meilleurs clients"<<endl<<endl;
		cout << "1)"<< nom1<<" "<< prenom1<< " "<< nb_commande1<<endl;
		cout << "2)"<< nom2<< " "<< prenom2<< " "<< nb_commande2<<endl;
		cout << "3)"<< nom3<< " "<< prenom3<< " "<< nb_commande3<<endl;
	}else{
		cerr << "ouverture historique_client.txt impossible"<<endl;
		exit (-1);
	}

}
void afficher_hist_client(){

	ifstream histofile("./data/historique_client.txt",ios::in);
	if(histofile){
		histofile.seekg (0,histofile.end);
  		long size = histofile.tellg();
 		histofile.seekg (0, histofile.beg);
  		char* buffer = new char[size];
  		histofile.read (buffer,size);
  		cout << string(buffer) << endl;
	}else{
		cerr << "ouverture historique_client.txt impossible"<<endl;
		exit (-1);
	}
}
int main() {
	system("clear");
	//deffinition des différent produit
	Pizza pizza_regina("Regina", 7.50);
	Pizza pizza_margherita("Margherita", 7);
	Pizza pizza_calzone("calzone",8);
	Plat_jour plat_jour("Plat du jour", 10);
	Salade salade_cesaar("Salade Cesar", 6);
	Salade salade_chevre("Salade Chevre", 6.50);
	Dessert dessert_glace("glace", 3);
	Dessert dessert_fondant("Fondant chocolat",4);
	Dessert dessert_tarte_pomme("Tarte au pommes", 3.50);
	Boisson boisson_soda("Soda", 1.50);
	Boisson boisson_biere("Biere", 3);
	Boisson boisson_cocktail("Cocktail de fruits", 2.50);
	bool fin;
	int choix, command_number=0, action=0;
	string nom, prenom;
	do{
		system("clear");
		cout << "Bienvenu dans notre restaurant" << endl;
		cout << endl;
		cout << "votre prenom" << endl;
		cin >> prenom;
		cout << "votre nom" << endl;
		cin >> nom;
		if(nom.compare("shutdown")==0 && prenom.compare("shutdown")==0)//eteindre le programme
			action=1;
		if(nom.compare("admin")==0 && prenom.compare("admin")==0)//accès adinistrateur
			action=2;
		if(action==2){
			fin=false;
			do{
				system("clear");
				cout << "Espace administrateur" <<endl <<endl;
				cout << "Que souhaitez vous faire?"<< endl <<"Afficher historique client (1)" << endl << "Afficher meilleur client (2)"<<endl<< "Afficher historique produit (3)" << endl << "Afficher meilleur produit (4)"<<endl<<"Quiter l'espace administrateur (0)"<<endl;
				cin >> choix;
				cout <<endl;
				switch(choix){
					case 1:
					afficher_hist_client();
					sleep(4);
					break;
					case 2:
					meilleur_client();
					sleep(4);
					break;
					case 0:
					fin=true;
					break;
					default:
					cout<<"Demande non définit";
					break;
				}
			}while(fin==false);
		}
		if(action==0){//action a faire si un client souhaite faire une commande
			
			Client client(prenom, nom);
			hist_client(client);
			command_number++;
			Command cmd_client(command_number, client);
			fin=false;
			do{
				system("clear");
				cout << "votre commande" << endl;
				cmd_client.print();
				cout << endl;
				cout << "Que souhaitez vous ajouter à votre commande?" << endl;
				cout << "Pizza (1)" << endl << "Plat du jour (2)" << endl << "Une Salade( 3)" << endl << "Dessert (4)" << endl << "Boisson (5)" << endl << "Terminer la commande(0)"<<endl;
				cin >> choix;
				cout << endl;
				switch (choix){
					case 1:
					cout << "Quel Pizza souhaiter vous?" << endl << pizza_regina.get_name() << "(1)" << endl << pizza_calzone.get_name() << "(2)" << endl << pizza_margherita.get_name() << "(3)" << endl;
					cin >> choix;
					switch(choix){
						case 1:
						cout << "Une regina" << endl;
						cmd_client.append(pizza_regina);
						sleep(1);
						break;
						case 2:
						cout << "Une calzone" << endl;
						cmd_client.append(pizza_calzone);
						sleep(1);
						break;
						case 3:
						cout << "Une margherita" << endl;
						cmd_client.append(pizza_margherita);
						sleep(1);
						break;
						default:
						cout << "Vous n'avez pas choisit de pizza" << endl;
						sleep(1);
					}
					break;
					case 2:
					cout << "Un Plat du jour" << endl;
					cmd_client.append(plat_jour);
					sleep(1);
					break;
					case 3:
					cout << "Quel Salade souhaiter vous?" << endl << salade_cesaar.get_name() << "(1)" << endl << salade_chevre.get_name() << "(2)" << endl;
					cin >> choix;
					switch(choix){
						case 1:
						cout << "une salade Cesar" << endl;
						cmd_client.append(salade_cesaar);
						sleep(1);
						break;
						case 2:
						cout << "une salade de chèvre" << endl;
						cmd_client.append(salade_chevre);
						sleep(1);
						break;
						default:
						cout << "Vous n'avez pas choisit de salade" << endl;
						sleep(1);
					}
					break;
					case 4:
					cout << "Quel Dessert souhaiter vous?" << endl << dessert_fondant.get_name() << "(1)" << endl << dessert_glace.get_name() << "(2)" << endl << dessert_tarte_pomme.get_name() << "(3)" << endl;
					cin >> choix;
					switch(choix){
						case 1:
						cout << "un fondant" << endl;
						cmd_client.append(dessert_fondant);
						sleep(1);
						break;
						case 2:
						cout << "une glace" << endl;
						cmd_client.append(dessert_glace);
						sleep(1);
						break;
						case 3:
						cout << "une tarte au pomme" << endl;
						cmd_client.append(dessert_tarte_pomme);
						sleep(1);
						break;
						default:
						cout << "Vous n'avez pas choisit de dessert" << endl;
						sleep(1);
					}
					break;
					case 5:
					cout << "Quel boisson souhaiter vous?" << endl << boisson_soda.get_name() << "(1)" << endl << boisson_biere.get_name() << "(2)" << endl << boisson_cocktail.get_name() << "(3)" << endl;
					cin >> choix;
					switch(choix){
						case 1:
						cout << "un soda" << endl;
						cmd_client.append(boisson_soda);
						sleep(1);
						break;
						case 2:
						cout << "une bière" << endl;
						cmd_client.append(boisson_biere);
						sleep(1);
						break;
						case 3:
						cout << "un cocktail" << endl;
						cmd_client.append(boisson_cocktail);
						sleep(1);
						break;
						default:
						cout << "Vous n'avez pas choisit de boisson" << endl;
						sleep(1);
					}
					break;
					case 0:
					fin=true;
					break;
					default:
					cout << "Choisissez un plat parmis la liste" << endl;
					sleep(1);
				}
				
			}while(fin!=true);
			cmd_client.print();
			cout << "merci de votre visite, Vous pouvez vous avancé au caisse pour payer et retirer votre commande" << endl;
			sleep(4);
		}
	}while(action!=1);

}
