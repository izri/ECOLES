#ifndef CLIENT_HH_
# define CLIENT_HH_

# include <iostream>
# include <string>

class		Client
{
public:
  Client(std::string const &name, std::string const &first_name, std::string const &tel,
	 std::string const &mail);
  ~Client();

public:
  std::string const	&getName() const;
  std::string const	&getFirstName() const;
  std::string const	&getTel() const;
  std::string const	&getMail() const;
  void			setName(std::string const &name);
  void			setFirstName(std::string const &first_name);
  void			setMail(std::string const &mail);
  void			setTel(std::string const &tel);

  enum		sit
    {
      INDOOR = 0, OUTDOOR
    };


private:
  std::string	_name;
  std::string	_firstname;
  std::string	_tel;
  std::string	_mail;
  enum sit	_favorite_table;
  short		_frequence;
  int		_pts;
};

#endif
