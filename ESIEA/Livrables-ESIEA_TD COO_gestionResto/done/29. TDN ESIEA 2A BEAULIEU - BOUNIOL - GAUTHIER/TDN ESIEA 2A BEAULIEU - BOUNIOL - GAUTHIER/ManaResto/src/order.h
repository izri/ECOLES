///This class will regroup all the food ordered.
#ifndef DEF_ORDER
#define DEF_ORDER

#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include "beverage.h"
#include "dish.h"
#include "tools.h"

class Order
{

	public:
		///Constructor of an order.
		Order();
		///Construcor of an order with all the meals given.
        Order(unsigned short starter, unsigned short mainDishe, unsigned short dessert, unsigned short beverage);

        ///Sum the price of all meal.
        unsigned int ntaxPrice();
		///Sum the price of all meal and add taxes.
        void totalPrice();
        ///Update the value of each dish taken.
        void updateOrder();
		///Save an order into the database.
		void saveOrder(std::string customerName);

		// Getter
		///Getter of the total price of the Order.
        unsigned int getPrice();
		///Getter of the starter name.
        std::string getNameStarter();
		///Getter of the main name.
        std::string getNameMain();
		///Getter of the dessert name.
        std::string getNameDesert();
		///Getter of the beverage name.
        std::string getNameBeverage();

	private:
		unsigned int m_idOrder; /**<Variable for stocking the order number.
								This value is stocked inside the file lastid.txt in the root folder.*/
		unsigned int m_totalPrice; /**<Variable for stocking th total price of the order (if the price of the dishes change, this value won't be affected).*/
		Dish m_starter; /**<Variable for stocking the starter Dish of the Customer.*/
		Dish m_main; /**<Variable for stocking the main Dish of the Customer.*/
		Dish m_dessert; /**<Variable for stocking the dessert Dish of the Customer.*/
		Beverage m_drink; /**<Variable for stocking the Beverage of the Customer.*/
};

#endif
