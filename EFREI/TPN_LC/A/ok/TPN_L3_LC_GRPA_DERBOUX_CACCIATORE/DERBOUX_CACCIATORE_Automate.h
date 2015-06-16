#ifndef AUTOMATE_H_INCLUDED
#define AUTOMATE_H_INCLUDED
#include "DERBOUX_CACCIATORE_Interfa.h"
#include "DERBOUX_CACCIATORE_Langage.h"
#include <vector>


class Automate{

private:
     vector <Interfa> autom;
    Langage *l;

public :
    Automate (Langage *language);
      int setAutomate(Interfa inter); //ATTENTION VERIF AUSSI QUE IN PAR EGAL A AUTRE IN
        void ConstruireAuto();
        void ConstruireI0();
            void suivant(Interfa inter);
            int ConstruireIn(Interfa inter, char lecture);



};

#endif // AUTOMATE_H_INCLUDED
