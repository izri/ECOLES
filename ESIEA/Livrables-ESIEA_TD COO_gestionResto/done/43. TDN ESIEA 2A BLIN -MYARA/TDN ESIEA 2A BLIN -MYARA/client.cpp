#include "client.hpp"

using namespace std;

Client::Client(std::string client)
{
	m_client = client;
}

void Client::afficherInfo()
{
	cout << "Client : " << m_client << endl;
}
