#include <iostream>
#include <vector>
#include <string>
using namespace std;
////////////////////////////////////////////////////
////////////////////////////////////////////////////
class Client { //Demande le nom et prénom du client et permet l'attribution d'un code client
private :
string first_name, last_name, code_client;	
public :
Client(const string first_name, const string last_name, const string code_client): first_name(first_name), last_name(last_name), code_client(code_client){}
const string get_first_name(){ return first_name;}
const string get_last_name(){ return last_name;}
const string get_code_client(){ return code_client;}
const string to_string(){ return " NOM : " +first_name + " - PRENOM " +last_name + " - CODE CLIENT : " +code_client;}
};
////////////////////////////////////////////////////
////////////////////////////////////////////////////
class Product{// Permet l'attribution d'un nom et d'un prix à un produit donné
private :
string type, name;
float price;
public :
Product(const string name, const float price): name(name), price(price){}
const string get_name(){ return name;}
const float get_price(){ return price;}
};
////////////////////////////////////////////////////
////////////////////////////////////////////////////
class Command {
	private :
	Client client;
	vector <Product> products;
	float somme, tva;
	public :
	Command(Client client) : client(client){}
	const int get_number();
	const Client get_client();
	const vector<Product> gt_products();
	void add(Product l){
		products.push_back(l);
					somme = somme+l.get_price(); //Calcul de la somme
					tva = (somme*10)/100; //Calcul de la TVA
				}
				void print() { //Affichage de l'addition
				vector<Product>::iterator it;
				cout << "INFORMATIONS LIEES AU CLIENT : " << client.to_string() << endl;
				cout <<"PRIX TOTAL DE LA COMMANDE : " << somme << "€"<< endl;
				cout <<"TVA A 10% : " << tva << "€"<< endl;
			}
		};
////////////////////////////////////////////////////
////////////////////////////////////////////////////
			int main(int argc, const char * argv[]) { //Présentation d'un menu avec les prix et le type de consommation
			Product Pizza("Pizza Margherita ", 22.50);
			Product Spaghetti("Spaghetti Bolognaise", 17.50);
			Product Salade("Salade Fraicheur à l Italienne", 15);
			Product Dessert("Panna Cotta et Tiramisu à la Mangue", 8);
			Product Vins("Vins et Eaux Minérales", 5.50);
			int check;
			bool fin;
			string nom, prenom, codeclient;
			cout << "Champs réservé au serveur" << endl;//Le serveur entre lui-même les informations concernant le client. Le client n'est pas là pour ça.
			cout << endl;
			cout << "Nom" << endl;
			cin >> nom;
			cout << "Prénom" << endl;
			cin >> prenom;
			cout << "[Date de la visite][Heure][N°Table][Nombre de client][Nom du serveur] - Tout attaché" << endl;
			cin >> codeclient;
			Client client(prenom, nom, codeclient);

			Command cmd_c1(client);
			fin=false;
			do{
				cout << "La commande du client" << endl;
				cout << "1 Pizza Margherita" << endl << "2 Spaghetti Bolognaise" << endl << "3 Salade Fraicheur à l Italienne" << endl << "4 Panna Cotta et Tiramisu à la Mangue" << endl << "5 Vins et Eaux Minérales" << endl << "0 Terminer"<<endl;
				cin >> check;
				cout << endl;
				switch (check){//Menu à partir duquel on choisi son plat
					case 1:cmd_c1.add(Pizza);break;
					case 2:cmd_c1.add(Spaghetti);break;					
					case 3:cmd_c1.add(Salade);break;					
					case 4:cmd_c1.add(Dessert);break;
					case 5:cmd_c1.add(Vins);break;
					case 0:fin=true;break;					
				}
			}while(fin!=true);
			cmd_c1.print();
}////////////////////////////////////////////////////
////////////////////////////////////////////////////