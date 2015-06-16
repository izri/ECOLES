#include "restaurant.hh"

using namespace	std;

void		getInput()
{
  Parser	p;
  string	input;

  while (cin.good())
    {
      cout << "[admin]> ";
      getline(cin, input);
      p.callFunc(input);
    }
}

int		main(UNUSED(int argc), UNUSED(char **argv))
{
  getInput();
  return (0);
}
