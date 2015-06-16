//
//  resto.cpp
//  TP
//
//  Created by Taiki on 07/04/2015.
//  Copyright (c) 2015 Taiki. All rights reserved.
//

#include "main.hpp"

using namespace std;

#define MIN(a, b) (a > b ? b : a)

//Stats codes
enum
{
	STATS_DUMP,
	STATS_CLIENT,
	STATS_MEAL,

	TOP_CLIENTS = 3,
	TOP_MEALS = 3
};

void Resto::processClient(Client & client, const vector<CommandeItem> request)
{
	//We extract the first element to create the object
	vector<CommandeItem>::const_iterator iterCommand = request.begin();
	if(iterCommand == request.end())
		return;

	cout << "Processing client named " << client.name << endl;

	Commande(client, iterCommand->command, iterCommand->quantity);
	Commande & currentCommande = client.getLastOrder();

	for (++iterCommand; iterCommand != request.end(); ++iterCommand)
		currentCommande.addCommand(iterCommand->command, iterCommand->quantity);

	currentCommande.print();
}

#define LENGTH 5

void Resto::runResto()
{
	string names[LENGTH] = {"Bob", "Bobette", "Bobby", "Terminabob", "Bob"};
	CommandeItem data[LENGTH][3] = {{CommandeItem(Plat(CODE_PIZZA), 2), CommandeItem(Plat(CODE_BOISSON), 3), CommandeItem(Plat(CODE_DESSERT), 9)},
		{CommandeItem(Plat(CODE_VEGETARIEN), 2), CommandeItem(Plat(CODE_BOISSON), 9), CommandeItem(Plat(CODE_DESSERT), 2)},
		{CommandeItem(Plat(CODE_PLAT_DU_JOUR), 2), CommandeItem(Plat(CODE_BOISSON), 3), CommandeItem(Plat(CODE_DESSERT), 9)},
		{CommandeItem(Plat(CODE_PIZZA), 42), CommandeItem(Plat(CODE_BOISSON), 1), CommandeItem(Plat(CODE_DESSERT), 1)},
		{CommandeItem(Plat(CODE_PLAT_DU_JOUR), 2), CommandeItem(Plat(CODE_BOISSON), 3), CommandeItem(Plat(CODE_DESSERT), 9)}};

	for(uint i = 0; i < LENGTH; ++i)
	{
		vector<CommandeItem> current (data[i], data[i] + sizeof(data[i]) / sizeof(CommandeItem));
		processClient(findClientWithNameOrCreate(names[i]), current);
	}

	cout << "Built some data, let's try to extract statistics" << endl << endl;

	showStats(STATS_DUMP);
	showStats(STATS_CLIENT);
	showStats(STATS_MEAL);
}

Client& Resto::findClientWithNameOrCreate(std::string name)
{
	for(vector<Client>::iterator iter = clients.begin(); iter != clients.end(); ++iter)
	{
		if(iter->name == name)
			return *iter;
	}

	Client newClient(name);

	clients.push_back(newClient);

	return clients.back();
}

bool sortClient(sortStruct i, sortStruct j)
{
	return i.balance > j.balance;
}

bool sortCommandItemRevenue(CommandeItem i, CommandeItem j)
{
	return i.command.price * i.quantity > j.command.price * j.quantity;
}

bool sortCommandItemQuantity(CommandeItem i, CommandeItem j)
{
	return i.quantity > j.quantity;
}

void Resto::showStats(uint code) const
{
	switch (code)
	{
		case STATS_DUMP:
		{
			cout << "Dumping the super secret agregated client file" << endl;

			for(vector<Client>::const_iterator iter = clients.begin(); iter != clients.end(); ++iter)
			{
				iter->printAgregated();
			}
			break;
		}

		case STATS_CLIENT:
		{
			vector<sortStruct> balance;
			for(vector<Client>::const_iterator iter = clients.begin(); iter != clients.end(); ++iter)
			{
				uint currentBalance = 0;
				vector<CommandeItem> stuffs = iter->dumpAgregated();

				for(vector<CommandeItem>::const_iterator iterS = stuffs.begin(); iterS != stuffs.end(); ++iterS)
				{
					currentBalance += iterS->command.price * iterS->quantity;
				}

				sortStruct current;
				current.name = iter->name.c_str();
				current.balance = currentBalance;

				balance.push_back(current);
			}

			sort(balance.begin(), balance.end(), sortClient);

			cout << "Top " << MIN(TOP_CLIENTS, balance.size()) << " clients:"<< endl;

			uint i = 0;
			for(vector<sortStruct>::const_iterator iter = balance.begin(); i < TOP_CLIENTS && iter != balance.end(); ++iter)
			{
				cout << "	" << ++i << ". " << iter->name << " with " << iter->balance << "€" << endl;
			}

			cout << endl;

			break;
		}

		case STATS_MEAL:
		{
			vector<CommandeItem> balance;
			for(vector<Client>::const_iterator iter = clients.begin(); iter != clients.end(); ++iter)
			{
				vector<CommandeItem> stuffs = iter->dumpAgregated();

				for(vector<CommandeItem>::const_iterator iterS = stuffs.begin(); iterS != stuffs.end(); ++iterS)
				{
					bool found = false;

					for(vector<CommandeItem>::iterator iterB = balance.begin(); iterB != balance.end(); ++iterB)
					{
						if(iterB->command == iterS->command)
						{
							if(iterB->quantity + iterS->quantity < iterS->quantity)
								iterB->quantity = UINT_MAX;
							else
								iterB->quantity += iterS->quantity;

							found = true;
							break;
						}
					}

					if(!found)
						balance.push_back(*iterS);
				}
			}

			uint i = 0;

			sort(balance.begin(), balance.end(), sortCommandItemQuantity);

			cout << "Top " << MIN(TOP_MEALS, balance.size()) << " meals by volume:"<< endl;
			for(vector<CommandeItem>::const_iterator iter = balance.begin(); i < TOP_CLIENTS && iter != balance.end(); ++iter)
			{
				cout << "	" << ++i << ". " << iter->command.name << " with " << iter->quantity << " sales" << endl;
			}

			sort(balance.begin(), balance.end(), sortCommandItemRevenue);

			i = 0;
			cout << endl << "Top " << MIN(TOP_MEALS, balance.size()) << " meals by revenue:"<< endl;
			for(vector<CommandeItem>::const_iterator iter = balance.begin(); i < TOP_CLIENTS && iter != balance.end(); ++iter)
			{
				cout << "	" << ++i << ". " << iter->command.name << " with " << iter->quantity * iter->command.price << "€" << endl;
			}

			break;
		}

		default:
			cout << "Sorry, can't display stats for code " << code << endl;
			break;
	}
}
