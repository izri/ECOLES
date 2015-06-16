#ifndef DEF_PIZZA
#define DEF_PIZZA
#include <iostream>
#include <string>
#include "Plat.h"
class Pizza :public Plat {
	public:
		Pizza (std::string nom, int prix);
};
#endif
