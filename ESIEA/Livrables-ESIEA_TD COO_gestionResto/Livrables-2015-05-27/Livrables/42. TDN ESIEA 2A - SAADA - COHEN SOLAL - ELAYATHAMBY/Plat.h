#ifndef PLAT
#define PLAT
#include <string>

using namespace std;

/// class Plat - 
class Plat {
  // Attributes
private:
  string nom;
  double   prix;
  // Operations
public:
  Plat (string nom, double prix = 0);
  // ~Plat ();
  void   aff ();
  double   getPrix ();
};

#endif
