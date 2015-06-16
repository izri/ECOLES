//
//  commande.h
//  TP
//
//  Created by Taiki on 31/03/2015.
//  Copyright (c) 2015 Taiki. All rights reserved.
//

#ifndef __TP__commande__
#define __TP__commande__

#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <stddef.h>
#include <limits.h>

class Plat
{
public:
	uint _ID;
	
	std::string name;
	uint price;
	
	Plat(uint ID);
	
	bool operator== (const Plat plat) const
	{
		return _ID == plat._ID;
	}
};

class CommandeItem
{
public:
	CommandeItem(Plat _command, uint _quantity) : command(_command), quantity(_quantity)
	{
		
	}
	
	Plat command;
	uint quantity;
};

//Commande and Client require each other
class Commande;

class Client
{
	std::vector<Commande> orders;
	
public:

	std::string name;
	
	Client(std::string _name);
	
	void addCommande(Commande& order);
	std::vector<CommandeItem> dumpAgregated() const;
	void printAgregated() const;
	
	Commande & getLastOrder()
	{
		return orders.back();
	}
};


class Commande
{
	std::vector<CommandeItem> command;
	std::time_t timeOfCommand;

	uint getPrice();
	
public:
	Commande(Client& client, const Plat plat, const uint _quantity)
	{
		command.insert(command.end(), CommandeItem(plat, _quantity));
		
		client.addCommande(*this);
		timeOfCommand = std::time(NULL);
	}
	
	Commande(const std::vector<CommandeItem> content) : command(content) {};
	
	bool addCommand(const Plat plat, const uint _quantity);
	std::vector<CommandeItem> dumpContent() const;
	
	void print();
};

class Resto
{
	std::vector<Client> clients;
	
	void processClient(Client & client, const std::vector<CommandeItem> request);
	
public:
	
	void runResto();
	Client& findClientWithNameOrCreate(std::string name);
	void showStats(uint code) const;
};

enum PLAT_CODES
{
	CODE_PIZZA,
	CODE_PLAT_DU_JOUR,
	CODE_VEGETARIEN,
	CODE_DESSERT,
	CODE_BOISSON
};

struct sortStruct {
	const char * name;
	uint balance;
};

std::vector<CommandeItem> aggregate(const std::vector<CommandeItem> input);

#endif /* defined(__TP__commande__) */
