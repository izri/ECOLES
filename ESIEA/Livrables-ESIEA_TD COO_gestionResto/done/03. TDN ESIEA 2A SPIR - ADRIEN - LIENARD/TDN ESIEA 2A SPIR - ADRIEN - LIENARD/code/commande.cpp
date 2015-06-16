//
//  commande.cpp
//  TP
//
//  Created by Taiki on 31/03/2015.
//  Copyright (c) 2015 Taiki. All rights reserved.
//

#include "main.hpp"

using namespace std;

bool Commande::addCommand(const Plat plat, const uint _quantity)
{
	for(vector<CommandeItem>::iterator iter = command.begin(); iter != command.end(); ++iter)
	{
		if(iter->command == plat)
		{
			if(iter->quantity + _quantity < _quantity)
			{
				iter->quantity = UINT_MAX;
				return false;
			}

			iter->quantity += _quantity;
			return true;
		}
	}

	command.push_back(CommandeItem(plat, _quantity));

	return true;
}

uint Commande::getPrice()
{
	uint finalPrice = 0;

	for(vector<CommandeItem>::iterator iter = command.begin(); iter != command.end(); ++iter)
	{
		if(finalPrice + iter->command.price * iter->quantity < finalPrice)	//WAYYYYYY too much money
		{
			return UINT_MAX;
		}

		finalPrice += iter->command.price * iter->quantity;
	}

	return finalPrice;
}

void Commande::print()
{
	for(vector<CommandeItem>::const_iterator iter = command.begin(); iter != command.end(); ++iter)
	{
		std::cout << "	" << iter->command.name << " x" << iter->quantity << " => " << iter->quantity * iter->command.price << "€" << endl;
	}

	std::cout << "Final price: " << this->getPrice() << "€" << endl << endl;
}

vector<CommandeItem> Commande::dumpContent() const
{
	return command;
}

Plat::Plat(uint ID) : _ID(ID)
{
	switch (_ID)
	{
		case CODE_PIZZA:
			name = "Pizza";
			price = 42;
			break;

		case CODE_PLAT_DU_JOUR:
			name = "Plat du jour";
			price = 42;
			break;

		case CODE_VEGETARIEN:
			name = "Repas végétariens";
			price = 42;
			break;

		case CODE_DESSERT:
			name = "Desserts";
			price = 42;
			break;

		case CODE_BOISSON:
			name = "Boissons";
			price = 42;
			break;

		default:
			name = "Missingno";
			price = UINT_MAX;
			break;
	}
}