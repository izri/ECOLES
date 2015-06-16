#include <iostream>
#include <string>

class Client
{
	public:
		Client(std::string prenom);

		void afficherInfo();
	private:
		std::string m_client;
};
