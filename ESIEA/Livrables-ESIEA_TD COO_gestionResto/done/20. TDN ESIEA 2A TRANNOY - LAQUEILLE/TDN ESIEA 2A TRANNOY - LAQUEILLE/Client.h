#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include <iostream>

class Client
{
	public :
		Client(std::string first_name, std::string last_name, int age, int telNum);
        const std::string get_first_name();
        const std::string get_last_name();
		const int getAge();
		const int getTelNum();
		void affichage();

    private :
		std::string m_first_name, m_last_name;
		int m_age,m_tel_num;

};

#endif // CLIENT_HPP
