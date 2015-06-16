//
//  clients.cpp
//  TP
//
//  Created by Taiki on 31/03/2015.
//  Copyright (c) 2015 Taiki. All rights reserved.
//

#include "main.hpp"

using namespace std;

Client::Client(std::string _name) : name(_name), orders()		{}

void Client::addCommande(Commande& order)
{
	orders.push_back(order);
}

std::vector<CommandeItem> Client::dumpAgregated() const
{
	vector<CommandeItem> intermediary;

	if(orders.size() == 0)
	{
		return intermediary;
	}

	bool firstPass = true;

	//We iterate the main array
	for(vector<Commande>::const_iterator iter = orders.begin(); iter != orders.end(); ++iter)
	{
		const vector<CommandeItem> agregate = iter->dumpContent();

		if(firstPass)
		{
			intermediary = agregate;
			firstPass = false;
		}
		else
			intermediary.insert(intermediary.end(), agregate.begin(), agregate.end());
	}

	if(firstPass)
		return intermediary;

	return aggregate(intermediary);
}

void Client::printAgregated() const
{
	cout << "Résumé des commandes du client " << name << " :" << endl;

	//We now build a Command objet that'll do all the hard work
	Commande(dumpAgregated()).print();
}
