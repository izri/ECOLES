///Class customer
#include "customer.h"

using namespace std;

///Constructor with no arguments given.
Customer::Customer()
{

}

///Constructor with given path for loading a Customer into the memory.
Customer::Customer(string path)
{
    ifstream custo(path.c_str());
    string temp;
    if(custo) //reading existing customer
    {
        //reading the ID
        getline(custo, temp);
        m_id=strtoul(temp.c_str(), NULL, 0);
        //Jumping the customer names
        getline(custo, temp);
        m_name=temp;
        //reading the gender
        getline(custo, temp);
        m_gender=strtoul(temp.c_str(), NULL, 0);
        //reading the age
        getline(custo, temp);
        m_age=strtoul(temp.c_str(), NULL, 0);
        //reading the totalExpense
        getline(custo, temp);
        m_totalExpense=strtoul(temp.c_str(), NULL, 0);
        //reading the number of visits
        getline(custo, temp);
        m_totalVisit=strtoul(temp.c_str(), NULL, 0);
        //closing the file.
        custo.close();
    }
    else
    {
        cerr << "Impossible to open file in :" + path + "!" << endl;
    }
}

///Constructor with all the paramters given.
Customer::Customer(string name, string surname, unsigned int age, bool gender) : m_name(name+"_"+surname), m_gender(gender), m_age(age)
{
    ifstream lastId("../ManaResto/lastid.txt");
    string temp;
    getline(lastId,temp);
    m_id=strtoul(temp.c_str(), NULL, 0);
    lastId.close();
    m_totalExpense =0;
    m_totalVisit =0;
}

///Copy constructor.
Customer::Customer(const Customer &custo) : m_id(custo.m_id), m_name(custo.m_name), m_gender(custo.m_gender), m_age(custo.m_age), m_totalExpense(custo.m_totalExpense), m_totalVisit(custo.m_totalVisit)
{

}

///Methode for adding a new visit in a client.
void Customer::newVisit()
{
	m_totalVisit++;
}

///Methode to add an expense.
void Customer::addExpense(unsigned int check) {
	m_totalExpense +=check;
}

///Incrementing m_totalExpense by check and incrementing m_totalVisit by one.
void Customer::updateCustomer(unsigned int check)
{
    string temp =m_name;
    ofstream customer(temp.c_str(), ios::out);
    if(customer)
    {
        m_totalExpense+=check;
        m_totalVisit++;
        customer << m_id << endl;
        customer << m_name << endl;
        customer << m_gender << endl;
        customer << m_age << endl;
        customer << m_totalExpense << endl;
        customer << m_totalVisit << endl;
        customer.close();
    }
    else
    {
        cerr << "Can't open the damn file : " + temp + "." << endl;
    }
}

///Save customer to the history.
void Customer::saveCustomer()
{
    string customerName="../ManaResto/customers/" + m_name + ".txt";
	ofstream custo(customerName.c_str(), ios::out);
	if(custo)
	{
		custo << m_id << endl;
		custo << m_name << endl;
		custo << m_gender << endl;
		custo << m_age << endl;
		custo << m_totalExpense << endl;
		custo << m_totalVisit << endl;
		custo.close();
	}
	else
	{
		cerr << "Fail to open file, check if you are admin on this PC." << endl;
	}
}

///Return m_name.
string Customer::getCustomerName()
{
    return m_name;
}

///Return m_age.
unsigned int Customer::getAge()
{
    return m_age;
}
