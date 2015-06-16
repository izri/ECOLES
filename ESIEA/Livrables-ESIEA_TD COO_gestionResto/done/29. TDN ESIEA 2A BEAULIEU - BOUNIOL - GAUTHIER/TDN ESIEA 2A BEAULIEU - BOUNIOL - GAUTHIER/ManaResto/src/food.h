///This class correspond to all the restaurant product.
#ifndef DEF_FOOD
#define DEF_FOOD

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

class Food {

	public:
		///Constructor of food.
		Food();
		///Constructor for loading informations into the memory with a given string.
		Food(std::string nameF);

		// Getter
		///Getter of the name of the food.
		std::string getName() const;
		///Getter of the price of the food.
		unsigned int getPrice() const;
		///Getter of the number of ordered food.
		unsigned int getTotalOrdered() const;

		///Method for incrementing the number of the food ordered.
		void addOrdered();

	protected:
		std::string m_name;/**<Name of the food.*/
		unsigned int m_price;/**<price of the food.*/
		unsigned int m_totalOrdered;/**<Number of this sort of food ordered.*/

};

#endif
