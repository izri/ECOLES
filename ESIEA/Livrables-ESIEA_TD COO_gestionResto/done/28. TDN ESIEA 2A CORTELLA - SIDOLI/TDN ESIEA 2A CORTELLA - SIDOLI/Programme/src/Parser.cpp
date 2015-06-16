#include "Parser.hh"

using namespace	std;

Parser::Parser()
{
  _cmds["help"] = &Data::help;
  _cmds["new client"] = &Data::newClient;
  _cmds["display clients"] = &Data::display;
}

void		Parser::callFunc(std::string const &cmd)
{
  for (map<string, cmdFunc>::iterator it = _cmds.begin(); it != _cmds.end(); ++it)
    {
      if (it->first == cmd)
	(_dump.*(it->second))();
    }
}

Parser::~Parser()
{

}
