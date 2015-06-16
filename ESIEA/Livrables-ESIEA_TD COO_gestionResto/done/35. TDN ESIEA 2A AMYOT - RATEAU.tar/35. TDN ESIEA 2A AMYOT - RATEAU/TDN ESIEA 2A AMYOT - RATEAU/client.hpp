#include <iostream>
#include <string>

class Client
{
	public:
		//Accessible de n'importe ou dans le code
		Client(std::string prenom); //Constructeur
		//~Personne(); // Destructeur Pas nécessaire

		void afficherInfo();
	private:
		//Espace restreint aux méthodes de la classe
		std::string m_client; // std aussi devant string aussi
};
