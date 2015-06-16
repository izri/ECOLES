#ifndef PARSER_HH_
# define PARSER_HH_

# include <iostream>
# include <string>
# include <map>
# include "Data.hh"

typedef void	(Data::*cmdFunc)(void);

class		Parser
{
public:
  Parser();
  ~Parser();

public:
  void		callFunc(std::string const &cmd);

private:
  std::map<std::string, cmdFunc>	_cmds;
  Data					_dump;
};

#endif
