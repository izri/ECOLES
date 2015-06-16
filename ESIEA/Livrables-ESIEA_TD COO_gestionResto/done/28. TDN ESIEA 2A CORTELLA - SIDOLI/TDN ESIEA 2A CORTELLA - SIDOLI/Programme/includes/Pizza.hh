#ifndef PIZZA_HH_
# define PIZZA_HH_

# include "Produit.hh"

# define DRINK_PRICE	2

class		Pizza : public Produit
{
public:
  Pizza();
  ~Pizza();

public:
  void		ajout_boisson(std::string const &type);

};

#endif
