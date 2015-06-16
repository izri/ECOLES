#ifndef COMMANDE_HPP
#define COMMANDE_HPP

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
//#include <vector.h> 





class Client{

	private:
		std::string m_nom;
                float m_age;
                int m_etoile;
		bool m_sexe;
               
 	public:
		Client(std::string nom,float age,bool sexe,int etoile);
		std::string getNom();
		float getAge(); 
		bool getSexe();
                int getEtoile();
                

                 void client_print();
};

class Product {
	private :
		std::string m_name;
		float m_price;
	public :
		Product(const std::string name, const float price) ;
		const std::string get_name(); 
		const float get_price(); 
		void product_print(); 
};


class Commande
{

	private: 
		Client m_client;
                Product m_produit;
		float m_quantite;
		//vector<Produit> m_produit;
		

	public: 
		Commande(Client client,Product produit,float quantite);
                const Client getClient();
                const Product getProduct();
                const float getQuantite();
             //   void ajout(Product produit, unsigned int quantite);
                void commande_print();
                float addition();

};

class Node 
{


public:
Client info;
Node *succ;
Node(Client client,Node *succ1);
//int recherche(Node *client,std::string name);
};



#endif










