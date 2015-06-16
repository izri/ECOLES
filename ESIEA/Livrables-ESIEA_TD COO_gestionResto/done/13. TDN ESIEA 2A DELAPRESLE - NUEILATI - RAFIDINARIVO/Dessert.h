#ifndef DEF_DESSERT
#define DEF_DESSERT
#include <iostream>
#include <string>
#include "Plat.h"
class Dessert :public Plat {
	public:
		Dessert (std::string nom, int prix);
};
#endif
