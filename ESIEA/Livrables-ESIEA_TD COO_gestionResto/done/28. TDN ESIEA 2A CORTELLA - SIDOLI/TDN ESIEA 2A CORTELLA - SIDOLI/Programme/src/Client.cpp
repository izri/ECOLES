#include "Client.hh"

Client::Client(std::string const &name, std::string const &first_name, std::string const &tel,
	       std::string const &mail) : _name(name), _firstname(first_name), _tel(tel), _mail(mail)
{
  std::cout << "New registered customer." << std::endl << std::endl;
}

std::string const	&Client::getName() const
{
  return (_name);
}

std::string const	&Client::getFirstName() const
{
  return (_firstname);
}

std::string const	&Client::getTel() const
{
  return (_tel);
}

std::string const	&Client::getMail() const
{
  return (_mail);
}

void			Client::setName(std::string const &name)
{
  _name = name;
}

void			Client::setFirstName(std::string const &first_name)
{
  _firstname = first_name;
}

void			Client::setMail(std::string const &mail)
{
  _mail = mail;
}

void			Client::setTel(std::string const &tel)
{
  _tel = tel;
}

Client::~Client()
{

}
