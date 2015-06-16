///The class reference all the dish in the restaurant.
#ifndef DEF_DISH
#define DEF_DISH

#include <iostream>
#include <string>
#include <fstream>
#include "food.h"

class Dish : public Food
{

	public:
		///Constructor of Dish.
		Dish();
		///Constructor of Dish with a string for loading it into the memory.
		Dish(std::string name);

		///Update the informations of a dish.
		void updateDish();
		///Save the dish in the order.
		void saveDish(std::string path);

		///Getter of the type of dish (starter=1, main=2, dessert=3).
		unsigned short getType() const; // Getter

	private:
		// 1 = starter, 2 = main, 3 = desert
		unsigned short m_type;/**<The type pf the dish (starter=1, main=2, dessert=3).*/

};

#endif
