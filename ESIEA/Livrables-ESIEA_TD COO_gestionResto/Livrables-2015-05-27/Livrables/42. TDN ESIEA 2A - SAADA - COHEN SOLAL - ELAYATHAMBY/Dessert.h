#include "Plat.h"

/// class Dessert -
class Dessert : public Plat {
    const static int prix = 6;
    // Operations
public:
    Dessert (string nom, unsigned int prix);
    void  aff ();
};

