#include "food.h"

using namespace std;
	///Empty constructor for initialisation.
	Food::Food() {}
	///Constructor with the given file path. Load all the info inside all atribute reading the corresponding ".txt".
	Food::Food(string name) : m_name(name)
	{
		string temp=name;
		ifstream starter(m_name.c_str());
		//reading the name
		getline(starter, temp);
		//reading the price
		getline(starter, temp);
		m_price=strtoul(temp.c_str(), NULL, 0);
		//reading the total ordered
		getline(starter, temp);
		m_totalOrdered=strtoul(temp.c_str(), NULL, 0);
		//closing the file.
		starter.close();
	}

	// Getter m_name
	string Food::getName() const {
		return m_name;
	}
	// Getter m_price
	unsigned int Food::getPrice() const {
		return m_price;
	}
	// Getter m_totalOrdered
	unsigned int Food::getTotalOrdered() const {
		return m_totalOrdered;
	}

	///Adding 1 to the number of ordered.
	void Food::addOrdered() {
		m_totalOrdered++;
	}
