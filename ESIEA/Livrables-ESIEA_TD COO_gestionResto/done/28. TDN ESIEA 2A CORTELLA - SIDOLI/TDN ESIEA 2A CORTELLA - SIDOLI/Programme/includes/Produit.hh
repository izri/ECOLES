#ifndef PRODUIT_HH_
# define PRODUIT_HH_

# include <string>

class		Produit
{
public:
  Produit();
  ~Produit();

public:
  void		ajout_produit(std::string const &type, int price);

protected:
  std::string	_type;
  int		_price;
};

#endif
