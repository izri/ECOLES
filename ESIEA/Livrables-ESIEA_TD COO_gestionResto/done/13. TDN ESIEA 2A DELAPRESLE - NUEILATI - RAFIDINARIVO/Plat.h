#ifndef DEF_PLAT
#define DEF_PLAT
#include <cassert>
#include <iostream>
#include <string>
 
class Plat {
public:
  Plat(std::string nom, int prix = 0);
int getPrice ();
private:
  std::string nom;
  int prix;
};

#endif
