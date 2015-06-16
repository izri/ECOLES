#include "client.hpp"

using namespace std;
//méthode -> fonction

//Nom de la classe :: methode
Client::Client(std::string client) //Constructeur ne retourne rien
{
	m_client = client;

	//if(fichier amyot.txt deja existant)
	//on charge les infos du client
	//else le client n'exitse pas on creer amyot.txt on stocke des infos.

	//Produit.txt
	//pizza 42 5


	//produit.xml
	//<produit>
	//  <name></name>
	//  <prix></prix>
	//  <q></q>
	//</produit>

}

void Client::afficherInfo()
{
	cout << "Client : " << m_client << endl;

}
