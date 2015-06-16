#ifndef DATA_HH_
# define DATA_HH_

# include <iostream>
# include <string>
# include "History.hh"

class			Data
{
public:
  Data();
  ~Data();

public:
  void		help();
  void		newClient();
  void		display();

private:
  History	_history;
};

#endif
