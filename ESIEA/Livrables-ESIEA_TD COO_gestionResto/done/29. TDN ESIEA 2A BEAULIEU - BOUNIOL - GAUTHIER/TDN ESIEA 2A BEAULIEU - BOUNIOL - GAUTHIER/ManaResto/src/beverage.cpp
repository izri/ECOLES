#include "beverage.h"
#include "food.h"

///Beverage.cpp class of all the bevergae.

using namespace std;
///Constructor of Beverage for initialisations
Beverage::Beverage() {}
///Calling the Food constructor and getting the informations of the choosen beverage.
Beverage::Beverage(string name) : Food(name)
{
	string temp=name;
	ifstream starter(m_name.c_str());
	//Jumping all the other info
	getline(starter, temp);
	getline(starter, temp);
	getline(starter, temp);
	//reading is there alcohol
	getline(starter, temp);
	m_isAlcohol=strtoul(temp.c_str(), NULL, 0);
	//reading the volume of the brevage
    getline(starter, temp);
    m_volume=strtoul(temp.c_str(), NULL, 0);
}

// GETTER isAlcohol - true = yes, False = no
///Test method for knowing is the Beverage contains alcohol.
bool Beverage::alcoTest() const
{
	if (m_isAlcohol)
	return true;
	else
	return false;
}
// GETTER m_volume
///Getter of the Beverage volume.
unsigned int Beverage::getVolume() const
{
	return m_volume;
}

///Method for updating the number of beverage taken in the beverages file.
void Beverage::updateBeverage()
{
    string temp =m_name;
	ofstream beverage(temp.c_str(), ios::out);
	if(beverage)
	{
		m_totalOrdered++;
		beverage << m_name << endl;
		beverage << m_price << endl;
		beverage << m_totalOrdered << endl;
		beverage << m_isAlcohol << endl;
		beverage << m_volume << endl;
	}
	else
	{
		cerr << "Can't open the dish file : " + temp + "." << endl;
	}
}

///Method for saving the data in a file.
void Beverage::saveBeverage(string path)
{
	ofstream beverage(path.c_str(), ios::out|ios::app);
	if(beverage)
	{
		beverage << m_name;
		beverage << "|";
        beverage << m_price;
		beverage << "|";
		beverage << m_isAlcohol;
        beverage << "|";
		beverage << m_volume << endl;
		beverage.close();
	}
	else
	{
		cerr << "The file given" + path + "is already in use or has been deleted." << endl;
	}
}
