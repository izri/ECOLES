#include "order.h"

using namespace std;

///This constructor asks to the client the 3 courses he can have and a beverage.
Order::Order()
{
	//Choosing the starter
	string courseName="dishes/starters/";
	printFolder(courseName);
	//Adding the food name
	courseName+=getString();
	//Opening the food and building the entity
	ifstream starter(courseName.c_str());
	if(starter)
	{
		starter.close();
		m_starter=Dish(courseName);
	}
	else
	{
		cerr << "check the spelling of what you typed." << endl;
	}

	//Choosing main
	courseName="dishes/mains/";
	printFolder(courseName);
	courseName+=getString();
	ifstream main(courseName.c_str());
	if(main)
	{
		main.close();
		m_main=Dish(courseName);
	}
	else
	{
		cerr << "check the spelling of what you typed." << endl;
	}

	//Choosing dessert
    courseName="dishes/deerts/";
	printFolder(courseName);
	courseName+=getString();
	ifstream dessert(courseName.c_str());
	if(dessert)
	{
		dessert.close();
		m_main=Dish(courseName);
	}
	else
	{
		cerr << "check the spelling of what you typed." << endl;
	}

	//Choosing beverage
	courseName="beverages/";
	printFolder(courseName);
	courseName+=getString();
	ifstream beverage(courseName.c_str());
	if(beverage)
	{
		beverage.close();
		m_drink=Beverage(courseName);
	}
	else
	{
		cerr << "check the spelling of what you typed." << endl;
	}

	//Loading the order ID.
	string temp;
	ifstream lastID("lastid.txt");
	if(lastID)
	{
		getline(lastID, temp);
		getline(lastID, temp);
		m_idOrder=strtoul(temp.c_str(), NULL, 0);
		lastID.close();
	}
	else
	{
		cerr << "The id file has been deleted or can't be read." << endl;
	}
	m_totalPrice=0;
}

///Choose the dishes in the list and load them.
Order::Order(unsigned short starter, unsigned short mainDishe, unsigned short dessert, unsigned short beverage)
{
    ifstream lastId("../ManaResto/lastid.txt");
    string temp;
    getline(lastId,temp);
    getline(lastId, temp);
    m_idOrder =strtoul(temp.c_str(), NULL, 0);
    lastId.close();

    m_totalPrice =0;

        // Starters
    if(starter==1)
    {
        m_starter=Dish("../ManaResto/dishes/starter/greekSalad.txt");
    }
    else if(starter==2)
    {
        m_starter=Dish("../ManaResto/dishes/starter/soup.txt");
    }
    else if(starter==3)
    {
        m_starter=Dish("../ManaResto/dishes/starter/sausage.txt");
    }
    else
    {
        m_starter=Dish("../ManaResto/dishes/starter/none.txt");
    }
        // Mains
    if(mainDishe==1)
    {
        m_main=Dish("../ManaResto/dishes/main/steak.txt");
    }
    else if(mainDishe==2)
    {
        m_main=Dish("../ManaResto/dishes/main/choucroute.txt");
    }
    else if(mainDishe==3)
    {
        m_main=Dish("../ManaResto/dishes/main/lasagna.txt");
    }
    else
    {
        m_main=Dish("../ManaResto/dishes/main/none.txt");
    }
        // Dessert
    if(dessert==1)
    {
        m_dessert=Dish("../ManaResto/dishes/dessert/ice.txt");
    }
    else if(dessert==2)
    {
        m_dessert=Dish("../ManaResto/dishes/dessert/tiramisu.txt");
    }
    else if(dessert==3)
    {
        m_dessert=Dish("../ManaResto/dishes/dessert/bavarois.txt");
    }
    else
    {
        m_dessert=Dish("../ManaResto/dishes/dessert/none.txt");
    }
        // Beverage
    if(beverage==1)
    {
        m_drink=Beverage("../ManaResto/beverages/beer.txt");
    }
    else if(beverage==2)
    {
        m_drink=Beverage("../ManaResto/beverages/wine.txt");
    }
    else if(beverage==3)
    {
        m_drink=Beverage("../ManaResto/beverages/coca.txt");
    }
    else
    {
        m_drink=Beverage("../ManaResto/beverages/none.txt");
    }

}

///Simple sum.
unsigned int Order::ntaxPrice()
{
    unsigned int check=0;
    check+=m_starter.getPrice();
    check+=m_main.getPrice();
    check+=m_dessert.getPrice();
    check+=m_drink.getPrice();
    return check;
}

///Get the price all all meals and apply the corresponding taxes.
void Order::totalPrice()
{
	unsigned int check=0, temp;
    check+=m_starter.getPrice();
    check+=m_main.getPrice();
	check+=m_dessert.getPrice();
    temp=(unsigned int)((long double)check*(0.1));
	check+=temp;
	//ajouter un paramètre TVA
	if (m_drink.alcoTest())
	{
		check+=m_drink.getPrice();
        temp=(unsigned int)((long double)m_drink.getPrice()*(0.2));
		check+=temp;
	}
	else
	{
		check+=m_drink.getPrice();
        temp=(unsigned int)((long double)m_drink.getPrice()*(0.1));
		check+=temp;
	}
	m_totalPrice=check;
}

///Return m_totalPrice.
unsigned int Order::getPrice()
{
    return m_totalPrice;
}

///Update the number of each dish taken.
void Order::updateOrder()
{
    m_starter.updateDish();
    m_main.updateDish();
    m_dessert.updateDish();
    m_drink.updateBeverage();
}

///Save the order in the history and in the folder orders.
void Order::saveOrder(string customerName)
{
	//Opening the history file and put the customer name and the order id.
    ofstream history("../ManaResto/history/history.txt", ios::out|ios::app);
	if(history)
	{
		history << customerName + "|";
		history << m_idOrder << endl;
		history.close();
	}
	else
	{
		cerr << "The history file can't be opened check if the file has been deleted or is in use." << endl;
	}
	//Opening the orders file and put the order inside.
	stringstream tempo;
	tempo << m_idOrder;
	string str = tempo.str();
    string path="../ManaResto/orders/" + str + ".txt";
	ofstream orders(path.c_str(), ios::out);
	if(orders)
	{
		orders << m_idOrder << endl;
        orders << m_totalPrice << endl;
		orders.close();
		m_starter.saveDish(path);
		m_main.saveDish(path);
		m_dessert.saveDish(path);
        m_drink.saveBeverage(path);
	}
	else
	{
		cerr << "The orders files can't be opened check if the folder has been deleted." << endl;
	}
}

///Read the path of the given food and parse it for having the name
string Order::getNameStarter()
{
    string name=m_starter.getName();
    size_t pos;

    stringstream tempo;
    tempo << m_starter.getPrice();
    string str = tempo.str();

    name = name.substr(28, 10);
    pos = name.find(".");
    name = name.substr(0, pos);
    if(name=="none")
    {
        name="No starter ordered.";
    }
    return "Starter : "+name+" - Price : "+str+"$ (untaxed)";
}

///Read the path of the given food and parse it for having the name
string Order::getNameMain()
{
    string name=m_main.getName();
    size_t pos;

    stringstream tempo;
    tempo << m_main.getPrice();
    string str = tempo.str();

    name = name.substr(25, 10);
    pos = name.find(".");
    name = name.substr(0, pos);
    if(name=="none")
    {
        name="No main dish ordered.";
    }
    return "Main : "+name+" - Price : "+str+"$ (untaxed)";
}

///Read the path of the given food and parse it for having the name
string Order::getNameDesert()
{
    string name=m_dessert.getName();
    size_t pos;

    stringstream tempo;
    tempo << m_dessert.getPrice();
    string str = tempo.str();

    name = name.substr(28, 10);
    pos = name.find(".");
    name = name.substr(0, pos);
    if(name=="none")
    {
        name="No desert ordered.";
    }
    return "Desert : "+name+" - Price : "+str+"$ (untaxed)";
}

///Read the path of the given food and parse it for having the name
string Order::getNameBeverage()
{
    string name=m_drink.getName();
    size_t pos;

    stringstream tempo;
    tempo << m_drink.getPrice();
    string str = tempo.str();

    name = name.substr(23, 10);
    pos = name.find(".");
    name = name.substr(0, pos);
    if(name=="none")
    {
        name="No beverage ordered.";
    }
    return "Beverage : "+name+" - Price : "+str+"$ (untaxed)";
}
