#include "dish.h"

using namespace std;

///Empty constructor for initialisation.
Dish::Dish() {}
///Calling the Food constructor and getting the type of the meal.
Dish::Dish(string name) : Food(name)
{
	string temp=name;
	ifstream starter(m_name.c_str());
	//Jumping all the other info
	getline(starter, temp);
	getline(starter, temp);
	getline(starter, temp);
	//reading the type number
	getline(starter, temp);
	m_type=strtoul(temp.c_str(), NULL, 0);
	//closing the file.
	starter.close();
}

// GETTER isAlcohol - true = yes, False = no
///Getter of dish type.
unsigned short Dish::getType() const {
	return m_type;
}

///Method for updating the number of dish taken in the dishes file.
void Dish::updateDish()
{
	//selecting the type of food (starter main or dessert).
    string folder;
    //Opening the corresponding file.
    folder+=m_name;
	ofstream dish(folder.c_str(), ios::out);
	if(dish)
	{
		m_totalOrdered++;
		dish << m_name << endl;
		dish << m_price << endl;
		dish << m_totalOrdered << endl;
		dish << m_type << endl;
	}
	else
	{
		cerr << "Can't open the dish file : " + folder + "." << endl;
	}
}

///Method for saving dish to history.
void Dish::saveDish(string path)
{
	//saving in the folder the information about the dish.
	//the name, the price, the type
	ofstream dish(path.c_str(), ios::out|ios::app);
	if(dish)
	{
		dish << m_name;
		dish << "|";
		dish << m_price;
		dish << "|";
		dish << m_type << endl;
		dish.close();
	}
	else
	{
		cerr << "The file given" + path + "is already in use or has been deleted." << endl;
	}
}
