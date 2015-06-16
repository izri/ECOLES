//
//  tools.cpp
//  TP
//
//  Created by Taiki on 14/04/2015.
//  Copyright (c) 2015 Taiki. All rights reserved.
//

#include "main.hpp"

using namespace std;

vector<CommandeItem> aggregate(const std::vector<CommandeItem> input)
{
	vector<CommandeItem> output;

	if(input.size() == 0)
		return output;

	//We iterate the commands of the current command
	for(vector<CommandeItem>::const_iterator iterAgreg = input.begin(); iterAgreg != input.end(); ++iterAgreg)
	{
		bool found = false;
		//We iterate to find the current plat in our agregate
		//Theoritically O(n^3) but not big deal thanks to the lack of significant choice
		//If it became a big deal, a solution would be to immediatly insert into the final array (O(n^2)), sort the said array (<= O(n^2)) then compact it (O(n))
		for(vector<CommandeItem>::iterator iterOut = output.begin(); iterOut != output.end(); ++iterOut)
		{
			if(iterOut->command == iterAgreg->command)
			{
				//Overflow protection
				if(iterOut->quantity + iterAgreg->quantity < iterAgreg->quantity)
					iterOut->quantity = UINT_MAX;
				else
					iterOut->quantity += iterAgreg->quantity;

				found = true;
				break;
			}
		}

		//If we couln't find the item
		if(!found)
			output.push_back(*iterAgreg);
	}

	return output;
}
