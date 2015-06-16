#ifndef HISTORIQUE_HPP
#define HISTORIQUE_HPP

#include "resto.hpp"
#include "command.hpp"

using namespace std;


class Historique : public Printable {
	private :
			Command command;
	public :
			Historique(Command command);
			const Command get_command();
			const string to_string();
			void print();
};

#endif  // Historique_HPP