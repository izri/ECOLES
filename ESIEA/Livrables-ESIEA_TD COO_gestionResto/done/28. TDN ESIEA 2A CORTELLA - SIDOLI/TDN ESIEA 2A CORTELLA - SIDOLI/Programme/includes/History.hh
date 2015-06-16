#ifndef HISTORY_HH_
# define HISTORY_HH_

# include <vector>
# include "Client.hh"

class		History
{
public:
  History();
  ~History();

public:
  int		nbclients() const;
  void		addClient(Client *client);
  void		dump() const;

private:
  std::vector<Client *>	_clients;

};

#endif
