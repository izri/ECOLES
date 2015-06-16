#ifndef DEF_BEVERAGE
#define DEF_BEVERAGE

#include <iostream>
#include <fstream>
#include <string>
#include "food.h"
///This class correspond to all the drink in the restaurant.
class Beverage : public Food
{

public:
	///Constructor of Beverage
	Beverage();
	///Constructor of Beverage with a string for loading it into the memory.
	Beverage(std::string name);

	///Method for updating th informations of a beverage
	void updateBeverage();
	///Method for saving beverage in the order.
	void saveBeverage(std::string path);
	// Getter
	///Function for testing the presence of alcohol.
	bool alcoTest() const;
	///Getter of volume of a beverage.
	unsigned int getVolume() const;

private:
	bool m_isAlcohol; /**<Variable for knowing is there is alcohol (if true, there is alcohol).*/
	unsigned int m_volume;/**<Variable for the volume of the beverage.*/

};

#endif
