
#include <iostream>
#include <string>

#include "resto.hpp"
#include "client.hpp"
#include "product.hpp"
#include "command.hpp"

using namespace std;

// STEP 5 :
//   1) surcharge de l'op�rateur << pour �viter de devoir utiliser explicitement to_string()
//   2) s�paration cpp / hpp cf. c (prototypes) / h (definitions) en C
//      occasion de revenir sur la distinction interface / impl�mentation pour qui ne l'a pas comprise
//   3) introduction d'un h�ritage tr�s simple en d�finissant une classe parente Printable simple
//   de toutes les classes de ce TP qui comporte deux m�thodes const string to_string avec une impl
//   par d�faut surcharg�e ensuite et une m�thode print qui ne sera pas surcharg�e
//   4) mais sait d�couvrir dynamiquement le nom de la classe concr�te d�riv�e
//    (introduction de la notion de virtualit�)

//  STEP 6 : compl�ter avec les classes concr�te de Produit - modulariser le programme en le d�coupant
//  en plusieurs fichiers, chacun sp�cialis� suivant un module (module produits, module client (profiling marketing))
//  ...

//  STEP 7 (TP suivant post examen de progr) : Introduction de l'historisation de la relation client (historique des commandes)
//  Le but est, en s�ance de TD de conception de reproduire de mani�re plus autonome
//  le travail de conception du diagramme de classe tel qu'au premier TD, puis d'en r�aliser l'impl�mentation en TP.
//     le livrable � rendre sera d'une part un A4 comportant le diagramme de classe
//      (un scan PDF ou une simple photo d'un manuscrit suffiront)
//       d'autre part un projet CPP + makefile + README.txt qui r�alise ce qui a �t� d�fini par le diagramme de classe
//       travail � r�aliser par bin�me ou trin�me.. tr�s probablement not�.


const string Printable::to_string() {
	const type_info &t = typeid(this);
	return t.name();
}

// Une friandise : la surcharge d'op�rateurs !
ostream& operator<<(ostream& s, Client c) { return s << c.to_string(); }
ostream& operator<<(ostream& s, Product o) { return s << o.to_string(); }
ostream& operator<<(ostream& s, Command o) { return s << o.to_string(); }


int main() {

	Client jane("Jane", "DOE", true);
	Client john("John", "DOE", false);
	Product pizza("Pizza", 10.00);
	Product chianti("Chianti classico", 10.00);
	Command cmd_jane_pizza(jane, pizza), cmd_john_chianti(john, chianti);

	cout << jane << endl;
	cout << john << endl;
	cout << pizza << endl;
	cout << chianti << endl;
	cout << cmd_jane_pizza << endl;
	cout << cmd_john_chianti << endl;

	cout << Pizza("Regina") << endl;
}






