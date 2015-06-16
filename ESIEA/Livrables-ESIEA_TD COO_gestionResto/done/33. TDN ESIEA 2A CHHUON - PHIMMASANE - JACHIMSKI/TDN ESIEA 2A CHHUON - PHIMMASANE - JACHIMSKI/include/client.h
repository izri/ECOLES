#ifndef CLIENT_HPP
#define CLIENT_HPP
#include <string>
#include <iostream>

class Client
{
	public :
		Client(std::string first_name, std::string last_name, int age,int tel);
		const std::string get_first_name();
		const std::string get_last_name();
		const int get_age();
		const int get_tel();
		void afficher();

    private :
		std::string m_first_name, m_last_name;
		int m_age,m_tel;

};

#endif // CLIENT_HPP
