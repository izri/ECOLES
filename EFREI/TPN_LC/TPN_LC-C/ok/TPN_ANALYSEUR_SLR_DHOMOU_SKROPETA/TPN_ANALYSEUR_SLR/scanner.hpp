#ifndef _SCANNER_HPP_
#define _SCANNER_HPP_

typedef unsigned short Ushort;

char fetch_first(char);

/**
* Permet de lire le fichier
* contenant la grammaire
* @param char*
* @return void
*/
void readFile(char*);

/**
* Cr�ation d'une table d'analyse
* � partir de la grammaire
* @param void
* @return void
*/
void createAnalyseTable();

/**
* Analyse de la grammaire et
* cr�ation d'une table de grammaire
* @param void
* @return void
*/
void splitGrammar();

/**
* Petit test d'affichage
* @param
* @return void
*/
void display();

/**
* Verification terminaux
* et des non terminaux
* @param
* @return void
*/
void checkTerminaux();


/**
* Creation des firsts et
* des follows
* @param void
* @return void
*/
void createFirstAndFollow();

/**
*
* @param void
* @return void
*/
void createFirst();

/**
*
* @param void
* @return void
*/
void createFollow();

/**
* V�rifie si le caract�re lu est
* terminal en v�rifiant si c'est
* un caract�re minuscule
* @param char
* @return bool
*/
bool isTerminal(char);


/**
* V�rifie si le caractere lu est
* non terminal en v�rifiant si c'est
* un caract�re majuscule
* @param char
* @return void
*/
bool isNonTerminal(char);


#endif // _SCANNER_HPP_
