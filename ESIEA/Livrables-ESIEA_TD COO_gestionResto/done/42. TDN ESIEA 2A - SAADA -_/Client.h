#include <iostream>

using namespace std;

#include "Plat.h"

/// class Client - 
class Client {
  // Attributes
private:
  string nom;
  short   table;
  short   sommeDue;
  // Operations
public:
  Client (string nom, short unsigned table);

  void   aff ();
  void commande (Plat p);
  // void   paye ();
};

