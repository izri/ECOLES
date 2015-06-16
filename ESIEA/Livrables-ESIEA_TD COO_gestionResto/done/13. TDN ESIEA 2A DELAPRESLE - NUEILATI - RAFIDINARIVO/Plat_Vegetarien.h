#ifndef DEF_PLATVEGE
#define DEF_PLATVEGE
#include <iostream>
#include <string>
#include "Plat.h"
class Plat_Vegetarien :public Plat {
	public:
		Plat_Vegetarien (std::string nom, int prix);
};
#endif
