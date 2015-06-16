#include "History.hh"

using namespace	std;

History::History()
{

}

int		History::nbclients() const
{
  return (_clients.size());
}

void		History::addClient(Client *client)
{
  _clients.push_back(client);
}

void		History::dump() const
{
  for (vector<Client *>::const_iterator it = _clients.begin(); it != _clients.end(); ++it)
    {
      cout << endl << "************" << endl;
      cout << "Customer " << (*it)->getFirstName() << " " << (*it)->getName() << endl;
      cout << "E-mail: " << (*it)->getMail() << endl;
      cout << "Phone: " << (*it)->getTel() << endl;
      cout << "************" << endl;
    }
  cout << endl;
}

History::~History()
{
  while (!_clients.empty())
    {
      delete _clients.back();
      _clients.pop_back();
    }
}
