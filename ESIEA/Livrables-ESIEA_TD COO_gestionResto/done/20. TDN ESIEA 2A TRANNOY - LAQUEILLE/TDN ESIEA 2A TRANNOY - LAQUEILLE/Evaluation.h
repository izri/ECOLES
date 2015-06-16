#ifndef EVALUATION_H
#define EVALUATION_H
#include <iostream>
#include <string>

class Evaluation
{
  	public :
		Evaluation(int noteAccueil, int noteService, int noteCuisine, int noteProprete);
        const int getAccueil();
        const int getService();
		const int getCuisine();
		const int getProprete();
		void affichage();

    private :
		int m_accueil, m_service, m_cuisine, m_proprete;
};

#endif // EVALUATION_H
