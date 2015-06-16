#include "tools.h"

using namespace std;

int getInt() // Had to be secured ...
{
	int user=0;

	cin >> user;

	return user;
}

string getString() // Had to be secured ...
{

	string user;

	cin >> user;

	return user;

}

void printFolder(string FName)
{
	DIR *dir;
	struct dirent *fileInRead;
	dir=opendir(FName.c_str());
	if(dir == NULL)
	{
		cerr << "Can't open the folder check your permissions." << endl;
	}
	else
	{
		fileInRead = readdir(dir);
		fileInRead = readdir(dir);
		while(((fileInRead = readdir(dir))!=NULL))
		{
			cout << fileInRead->d_name << endl;
		}
		closedir(dir);
	}
}

string mostOrderStarter()
{
    unsigned int max=0;
    string temp, name ="ERROR";
    ifstream dish("../ManaResto/dishes/starter/greekSalad.txt");
    if (dish)
    {
        getline(dish, temp);
        getline(dish, temp);
        getline(dish, temp);
        if(strtoul(temp.c_str(), NULL, 0)>max)
        {
            max=strtoul(temp.c_str(), NULL, 0);
            name="greekSalad";
        }
        dish.close();
    }
    ifstream dish1("../ManaResto/dishes/starter/sausage.txt");
    if (dish1)
    {
        getline(dish1, temp);
        getline(dish1, temp);
        getline(dish1, temp);
        if(strtoul(temp.c_str(), NULL, 0)>max)
        {
            max=strtoul(temp.c_str(), NULL, 0);
            name="sausage";
        }
        dish1.close();
    }
    ifstream dish2("../ManaResto/dishes/starter/soup.txt");
    if (dish2)
    {
        getline(dish2, temp);
        getline(dish2, temp);
        getline(dish2, temp);
        if(strtoul(temp.c_str(), NULL, 0)>max)
        {
            max=strtoul(temp.c_str(), NULL, 0);
            name="soup";
        }
        dish2.close();
    }
    ifstream dish3("../ManaResto/dishes/starter/none.txt");
    if (dish3)
    {
        getline(dish3, temp);
        getline(dish3, temp);
        getline(dish3, temp);
        if(strtoul(temp.c_str(), NULL, 0)>max)
        {
            max=strtoul(temp.c_str(), NULL, 0);
            name="none";
        }
        dish3.close();
    }
    stringstream tempo;
    tempo << max;
    string str = tempo.str();
    return name+" - ("+str+")";
}

string mostOrderMain()
{
    unsigned int max=0;
    string temp, name ="ERROR";
    ifstream dish("../ManaResto/dishes/main/steak.txt");
    if (dish)
    {
        getline(dish, temp);
        getline(dish, temp);
        getline(dish, temp);
        if(strtoul(temp.c_str(), NULL, 0)>max)
        {
            max=strtoul(temp.c_str(), NULL, 0);
            name="steak";
        }
        dish.close();
    }
    ifstream dish1("../ManaResto/dishes/main/lasagna.txt");
    if (dish1)
    {
        getline(dish1, temp);
        getline(dish1, temp);
        getline(dish1, temp);
        if(strtoul(temp.c_str(), NULL, 0)>max)
        {
            max=strtoul(temp.c_str(), NULL, 0);
            name="lasagna";
        }
        dish1.close();
    }
    ifstream dish2("../ManaResto/dishes/main/choucroute.txt");
    if (dish2)
    {
        getline(dish2, temp);
        getline(dish2, temp);
        getline(dish2, temp);
        if(strtoul(temp.c_str(), NULL, 0)>max)
        {
            max=strtoul(temp.c_str(), NULL, 0);
            name="choucroute";
        }
        dish2.close();
    }
    ifstream dish3("../ManaResto/dishes/main/none.txt");
    if (dish3)
    {
        getline(dish3, temp);
        getline(dish3, temp);
        getline(dish3, temp);
        if(strtoul(temp.c_str(), NULL, 0)>max)
        {
            max=strtoul(temp.c_str(), NULL, 0);
            name="none";
        }
        dish3.close();
    }
    stringstream tempo;
    tempo << max;
    string str = tempo.str();
    return name+" - ("+str+")";
}

string mostOrderDesert()
{
    unsigned int max=0;
    string temp, name ="ERROR";
    ifstream dish("../ManaResto/dishes/dessert/ice.txt");
    if (dish)
    {
        getline(dish, temp);
        getline(dish, temp);
        getline(dish, temp);
        if(strtoul(temp.c_str(), NULL, 0)>max)
        {
            max=strtoul(temp.c_str(), NULL, 0);
            name="ice";
        }
        dish.close();
    }
    ifstream dish1("../ManaResto/dishes/dessert/tiramisu.txt");
    if (dish1)
    {
        getline(dish1, temp);
        getline(dish1, temp);
        getline(dish1, temp);
        if(strtoul(temp.c_str(), NULL, 0)>max)
        {
            max=strtoul(temp.c_str(), NULL, 0);
            name="tiramisu";
        }
        dish1.close();
    }
    ifstream dish2("../ManaResto/dishes/dessert/bavarois.txt");
    if (dish2)
    {
        getline(dish2, temp);
        getline(dish2, temp);
        getline(dish2, temp);
        if(strtoul(temp.c_str(), NULL, 0)>max)
        {
            max=strtoul(temp.c_str(), NULL, 0);
            name="bavarois";
        }
        dish2.close();
    }
    ifstream dish3("../ManaResto/dishes/dessert/none.txt");
    if (dish3)
    {
        getline(dish3, temp);
        getline(dish3, temp);
        getline(dish3, temp);
        if(strtoul(temp.c_str(), NULL, 0)>max)
        {
            max=strtoul(temp.c_str(), NULL, 0);
            name="none";
        }
        dish3.close();
    }
    stringstream tempo;
    tempo << max;
    string str = tempo.str();
    return name+" - ("+str+")";
}

string mostOrderBeverage()
{
    unsigned int max=0;
    string temp, name ="ERROR";
    ifstream dish("../ManaResto/beverages/beer.txt");
    if (dish)
    {
        getline(dish, temp);
        getline(dish, temp);
        getline(dish, temp);
        if(strtoul(temp.c_str(), NULL, 0)>max)
        {
            max=strtoul(temp.c_str(), NULL, 0);
            name="beer";
        }
        dish.close();
    }
    ifstream dish1("../ManaResto/beverages/wine.txt");
    if (dish1)
    {
        getline(dish1, temp);
        getline(dish1, temp);
        getline(dish1, temp);
        if(strtoul(temp.c_str(), NULL, 0)>max)
        {
            max=strtoul(temp.c_str(), NULL, 0);
            name="wine";
        }
        dish1.close();
    }
    ifstream dish2("../ManaResto/beverages/coca.txt");
    if (dish2)
    {
        getline(dish2, temp);
        getline(dish2, temp);
        getline(dish2, temp);
        if(strtoul(temp.c_str(), NULL, 0)>max)
        {
            max=strtoul(temp.c_str(), NULL, 0);
            name="coca";
        }
        dish2.close();
    }
    ifstream dish3("../ManaResto/beverages/none.txt");
    if (dish3)
    {
        getline(dish3, temp);
        getline(dish3, temp);
        getline(dish3, temp);
        if(strtoul(temp.c_str(), NULL, 0)>max)
        {
            max=strtoul(temp.c_str(), NULL, 0);
            name="none";
        }
        dish3.close();
    }
    stringstream tempo;
    tempo << max;
    string str = tempo.str();
    return name+" - ("+str+")";
}

string lessOrderStarter()
{
    unsigned int max=1000000;
    string temp, name ="ERROR";
    ifstream dish("../ManaResto/dishes/starter/greekSalad.txt");
    if (dish)
    {
        getline(dish, temp);
        getline(dish, temp);
        getline(dish, temp);
        if(strtoul(temp.c_str(), NULL, 0)<max)
        {
            max=strtoul(temp.c_str(), NULL, 0);
            name="greekSalad";
        }
        dish.close();
    }
    ifstream dish1("../ManaResto/dishes/starter/sausage.txt");
    if (dish1)
    {
        getline(dish1, temp);
        getline(dish1, temp);
        getline(dish1, temp);
        if(strtoul(temp.c_str(), NULL, 0)<max)
        {
            max=strtoul(temp.c_str(), NULL, 0);
            name="sausage";
        }
        dish1.close();
    }
    ifstream dish2("../ManaResto/dishes/starter/soup.txt");
    if (dish2)
    {
        getline(dish2, temp);
        getline(dish2, temp);
        getline(dish2, temp);
        if(strtoul(temp.c_str(), NULL, 0)<max)
        {
            max=strtoul(temp.c_str(), NULL, 0);
            name="soup";
        }
        dish2.close();
    }
    ifstream dish3("../ManaResto/dishes/starter/none.txt");
    if (dish3)
    {
        getline(dish3, temp);
        getline(dish3, temp);
        getline(dish3, temp);
        if(strtoul(temp.c_str(), NULL, 0)<max)
        {
            max=strtoul(temp.c_str(), NULL, 0);
            name="none";
        }
        dish3.close();
    }
    stringstream tempo;
    tempo << max;
    string str = tempo.str();
    return name+" - ("+str+")";
}

string lessOrderMain()
{
    unsigned int max=1000000;
    string temp, name ="ERROR";
    ifstream dish("../ManaResto/dishes/main/steak.txt");
    if (dish)
    {
        getline(dish, temp);
        getline(dish, temp);
        getline(dish, temp);
        if(strtoul(temp.c_str(), NULL, 0)<max)
        {
            max=strtoul(temp.c_str(), NULL, 0);
            name="steak";
        }
        dish.close();
    }
    ifstream dish1("../ManaResto/dishes/main/lasagna.txt");
    if (dish1)
    {
        getline(dish1, temp);
        getline(dish1, temp);
        getline(dish1, temp);
        if(strtoul(temp.c_str(), NULL, 0)<max)
        {
            max=strtoul(temp.c_str(), NULL, 0);
            name="lasagna";
        }
        dish1.close();
    }
    ifstream dish2("../ManaResto/dishes/main/choucroute.txt");
    if (dish2)
    {
        getline(dish2, temp);
        getline(dish2, temp);
        getline(dish2, temp);
        if(strtoul(temp.c_str(), NULL, 0)<max)
        {
            max=strtoul(temp.c_str(), NULL, 0);
            name="choucroute";
        }
        dish2.close();
    }
    ifstream dish3("../ManaResto/dishes/main/none.txt");
    if (dish3)
    {
        getline(dish3, temp);
        getline(dish3, temp);
        getline(dish3, temp);
        if(strtoul(temp.c_str(), NULL, 0)<max)
        {
            max=strtoul(temp.c_str(), NULL, 0);
            name="none";
        }
        dish3.close();
    }
    stringstream tempo;
    tempo << max;
    string str = tempo.str();
    return name+" - ("+str+")";
}

string lessOrderDesert()
{
    unsigned int max=1000000;
    string temp, name ="ERROR";
    ifstream dish("../ManaResto/dishes/dessert/ice.txt");
    if (dish)
    {
        getline(dish, temp);
        getline(dish, temp);
        getline(dish, temp);
        if(strtoul(temp.c_str(), NULL, 0)<max)
        {
            max=strtoul(temp.c_str(), NULL, 0);
            name="ice";
        }
        dish.close();
    }
    ifstream dish1("../ManaResto/dishes/dessert/tiramisu.txt");
    if (dish1)
    {
        getline(dish1, temp);
        getline(dish1, temp);
        getline(dish1, temp);
        if(strtoul(temp.c_str(), NULL, 0)<max)
        {
            max=strtoul(temp.c_str(), NULL, 0);
            name="tiramisu";
        }
        dish1.close();
    }
    ifstream dish2("../ManaResto/dishes/dessert/bavarois.txt");
    if (dish2)
    {
        getline(dish2, temp);
        getline(dish2, temp);
        getline(dish2, temp);
        if(strtoul(temp.c_str(), NULL, 0)<max)
        {
            max=strtoul(temp.c_str(), NULL, 0);
            name="bavarois";
        }
        dish2.close();
    }
    ifstream dish3("../ManaResto/dishes/dessert/none.txt");
    if (dish3)
    {
        getline(dish3, temp);
        getline(dish3, temp);
        getline(dish3, temp);
        if(strtoul(temp.c_str(), NULL, 0)<max)
        {
            max=strtoul(temp.c_str(), NULL, 0);
            name="none";
        }
        dish3.close();
    }
    stringstream tempo;
    tempo << max;
    string str = tempo.str();
    return name+" - ("+str+")";
}

string lessOrderBeverage()
{
    unsigned int max=1000000;
    string temp, name ="ERROR";
    ifstream dish("../ManaResto/beverages/beer.txt");
    if (dish)
    {
        getline(dish, temp);
        getline(dish, temp);
        getline(dish, temp);
        if(strtoul(temp.c_str(), NULL, 0)<max)
        {
            max=strtoul(temp.c_str(), NULL, 0);
            name="beer";
        }
        dish.close();
    }
    ifstream dish1("../ManaResto/beverages/wine.txt");
    if (dish1)
    {
        getline(dish1, temp);
        getline(dish1, temp);
        getline(dish1, temp);
        if(strtoul(temp.c_str(), NULL, 0)<max)
        {
            max=strtoul(temp.c_str(), NULL, 0);
            name="wine";
        }
        dish1.close();
    }
    ifstream dish2("../ManaResto/beverages/coca.txt");
    if (dish2)
    {
        getline(dish2, temp);
        getline(dish2, temp);
        getline(dish2, temp);
        if(strtoul(temp.c_str(), NULL, 0)<max)
        {
            max=strtoul(temp.c_str(), NULL, 0);
            name="coca";
        }
        dish2.close();
    }
    ifstream dish3("../ManaResto/beverages/none.txt");
    if (dish3)
    {
        getline(dish3, temp);
        getline(dish3, temp);
        getline(dish3, temp);
        if(strtoul(temp.c_str(), NULL, 0)<max)
        {
            max=strtoul(temp.c_str(), NULL, 0);
            name="none";
        }
        dish3.close();
    }
    stringstream tempo;
    tempo << max;
    string str = tempo.str();
    return name+" - ("+str+")";
}

unsigned long int totalIncome()
{
    DIR *dir;
    string FName="../ManaResto/orders/", tmp;
    struct dirent *fileInRead;
    unsigned long int sum=0;
    dir=opendir(FName.c_str());
    if(dir == NULL)
    {
        cerr << "Can't open the folder check your permissions." << endl;
    }
    else
    {
        fileInRead = readdir(dir);
        fileInRead = readdir(dir);
        while(((fileInRead = readdir(dir))!=NULL))
        {
            tmp =FName+fileInRead->d_name;
            ifstream order(tmp.c_str());
            getline(order, tmp);
            getline(order, tmp);
            sum+=strtoul(tmp.c_str(), NULL, 0);
            order.close();
        }
        closedir(dir);
    }
    return sum;
}

string fidelityCustomer()
{
    DIR *dir;
    string FName="../ManaResto/customers/", tmp, tmp1, name;
    struct dirent *fileInRead;
    unsigned long int max=0;
    dir=opendir(FName.c_str());
    if(dir == NULL)
    {
        cerr << "Can't open the folder check your permissions." << endl;
    }
    else
    {
        fileInRead = readdir(dir);
        fileInRead = readdir(dir);
        while(((fileInRead = readdir(dir))!=NULL))
        {
            tmp =FName+fileInRead->d_name;
            ifstream order(tmp.c_str());
            getline(order, tmp);
            getline(order, tmp);
            tmp1=tmp;
            getline(order, tmp);
            getline(order, tmp);
            getline(order, tmp);
            getline(order, tmp);
            if(strtoul(tmp.c_str(), NULL, 0)>max)
            {
                name=tmp1;
                max =strtoul(tmp.c_str(), NULL, 0);
            }
            order.close();
        }
        closedir(dir);
    }
    stringstream tempo;
    tempo << max;
    string str = tempo.str();
    return name +" - ("+str+")";
}
