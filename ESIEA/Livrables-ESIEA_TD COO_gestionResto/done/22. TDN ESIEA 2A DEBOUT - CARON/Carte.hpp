#ifndef CARTE_HPP
#define CARTE_HPP

#include "resto.hpp"
#include "command.hpp"

using namespace std;


class Carte : public Printable {
	private :
			Command command;
			int PtFidelite;
	public :
			Carte(Command command, int PtFidelite);
			const Command get_PtFidelite();
			const string to_string();
			void print();
};

#endif  // Carte_HPP