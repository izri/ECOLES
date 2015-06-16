#ifndef DEF_PLATJOUR
#define DEF_PLATJOUR
#include <iostream>
#include <string>
#include "Plat.h"
class PlatDuJour : public Plat //La classe PlatDuJour hérite de la classe Plat. Il hérite des méthodes et attributs de la classe Plat.
{
	public:
		PlatDuJour (std::string nom, int prix);
};
#endif
