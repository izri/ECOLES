///This class represents all the customers in the restaurant
#ifndef DEF_CUSTOMER
#define DEF_CUSTOMER

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "tools.h"
#include "order.h"

class Customer
{

	public:
		///Constructor of customer.
		Customer();
        Customer(std::string path);
        Customer(std::string name, std::string surname, unsigned int age, bool gender);
        Customer(const Customer& custo);

		///Method for adding a new visit for a customer.
		void newVisit();
		///Method for add expense for a client.
		void addExpense(unsigned int check);
		///Save the customer in a .txt file.
		void saveCustomer();
		///Change the last id in the id file.
		void saveLastID();
		///Update the Customer information in the corresponding .txt file.
        void updateCustomer(unsigned int check);

        ///Getter of the name of the client.
        std::string getCustomerName();
		///Getter of the age of the client.
        unsigned int getAge();

	private:
		// créer fichier avec last id et faire + 1 pour chaque nouveau client.
		unsigned int m_id;/**<Variable for stocking the id of the customer.*/
		std::string m_name;/**<Variable for stocking the name of the client.*/
		// true = man, false = woman
		bool m_gender;/**<Variable for stocking the gender of the client.*/
		unsigned int m_age;/**<Variable for stocking the age of the customer.*/
		unsigned int m_totalExpense;/**<Variable for stocking all the expenses of the customer.*/
		unsigned int m_totalVisit;/**<Variable for stocking all the visits of a customer.*/
};

/* L'objet est stocké dans un fichier unique chargé a l'aide d'un constructeur */
#endif
