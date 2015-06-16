#ifndef DEF_CLIENT
#define DEF_CLIENT
#include <iostream>
#include <string>
#include "Plat.h"

class Commande {
	public:
		Commande (std::string nom);
		void   afficher ();
		void commander (Plat repas);
	private:
		std::string m_nom;
		int m_somme;

};
#endif
