#ifndef DEF_BOISSON
#define DEF_BOISSON
#include <iostream>
#include <string>
#include "Plat.h"
class Boisson :public Plat {
	public:
		Boisson (std::string nom, int prix);
};
#endif
