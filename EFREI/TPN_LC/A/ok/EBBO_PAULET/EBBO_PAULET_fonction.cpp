#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "fonctions.h"

using namespace std;


bool yadeszero(vector <etat> grammounete)
{
	for (int i = 0; i<grammounete.size(); i++)
		if (grammounete[i].finie == 0)
			return 1;
	
	return 0;
}


grammaire :: grammaire()
{
    // Variables locales
    ifstream source ( "monfichier.txt" ) ;
    string mot;
    string mot_prec;
    int cpt=-1;


    while ( source >> mot ) //Lecture
    {
       // .push_back(mot)
       //Lettre de début

       if (mot != mot_prec) //creation de nouvelle ligne
       {
            cpt++;
            magrammaire.push_back(vector<string>());
            mot_prec=mot;
            magrammaire[cpt].push_back(mot);

       }

        //Symbole associé
        //nouvelle colonne

        source>>mot;
        if (mot != mot_prec) // Cas S -> S
        {
            magrammaire[cpt].push_back(mot);
        }
    }

    /////////////////////POST TRAITEMENT/////////////////////
    //ordre des terminaux et non terminaux
    for (int cpt=0; cpt<(int)magrammaire.size(); cpt++)
    {

        for (int cpt2=1; cpt2<(int)magrammaire[cpt].size(); cpt2++)
        {

            int cpt3=0;
            bool ok=true;

            while ((cpt3<(int)magrammaire[cpt][cpt2].size()) && (ok))
            {
                //cout<<"cpt : "<<cpt<<"CPT2 : "<<cpt2<<"cpt3 : "<<cpt3<<endl; //affichage de test

                if (magrammaire[cpt][cpt2][cpt3] == magrammaire[cpt][0][0])
                {
                    ok=false;

                }
                cpt3++;

            }
            if (ok)
            {
                magrammaire[cpt].push_back(magrammaire[cpt][cpt2]);
                magrammaire[cpt].erase (magrammaire[cpt].begin()+cpt2);
            }


        }
    }
    //ajout du sommet' donnne sommet :
    string sommet, sommet_prime;
    sommet = magrammaire[0][0];
    sommet_prime = sommet;
    sommet_prime.append("'");
    magrammaire.insert(magrammaire.begin(), vector<string>());
    magrammaire[0].push_back(sommet_prime);
    magrammaire[0].push_back(sommet);




}

void grammaire ::show()
{

    for (int cpt=0; cpt<(int)magrammaire.size(); cpt++)
    {
        for (int cpt2=0; cpt2<(int)magrammaire[cpt].size(); cpt2++)
        {
            cout<<magrammaire[cpt][cpt2]<<" ";
        }
        cout<<endl;
    }
}

char grammaire :: getExpression_char (int X, int Y)
{
    return magrammaire[X][Y][0];
}

string grammaire :: getExpression_string (int X, int Y)
{
    return magrammaire[X][Y];
}

int grammaire :: getSize_int(int X)
{
    return magrammaire[X].size();
}
int grammaire :: getSize_int()
{
    return magrammaire.size();
}

vector <char> premier(char expression, grammaire &magrammaire)
{
    //recherche de l'indice de l'expression
    int cpt=0, index=0;
    vector <char> premiers;
    //old//while (magrammaire.magrammaire[cpt][0][0]!=expression)
    while (magrammaire.getExpression_char(cpt, 0)!=expression)
    {
        cpt++;
    }
    index = cpt; //stockage de l'index de l'expression
    //parcours de l'expression
    //on saute l'indice 1 car c'est le nom de l'expression
    //old// for (cpt=1, cpt<magrammaire.magrammaire[cpt].size(); cpt++)
    for (cpt=1; cpt<magrammaire.getSize_int(cpt); cpt++)
    {
        //ajout de l'indice 0 car on veut le premier char du string
        expression = magrammaire.getExpression_char(cpt, 0);
        //old//expression = magrammaire.magrammaire[index][cpt][0];

        //traitemenent en fonction du cas
       if ((expression<65)||(expression>91))
        {
            //CAS DU TERMINAL
            premiers.push_back(expression);

        }
        if (expression == '@')
        {
            //CAS DE EPSILON, IDENTIQUE AUX TERMINAUX MAIS TRAITé à PART
            premiers.push_back(expression);
        }
        else
        {
            //premiers.push_back(premier(expression, magrammaire));
            premier(expression, magrammaire);

        }
    }
    return premiers;


}


void vide_etat(etat &monetat)
{
	monetat.finie=0;
	monetat.gramm.clear();
	monetat.suivant.clear();
}


void suiv_begin(etat &monetat)// creer le tableau suivant, mais il n'est pas finie
{
	
	
	
	
	
	for (int i = 0; i<monetat.gramm.size();i++)
	{
		if (monetat.gramm[i][1]!=".")
		{
			// on verifie que l'etat n'es pas deja dans le vector
			bool verifpasdejadedan = 1;
			for (int j = 0; j<monetat.suivant.size(); j++)
				if (monetat.suivant[i][0] == monetat.gramm[i][1][1]+"")
					verifpasdejadedan = 0;

			if (verifpasdejadedan)
			{
				vector < string > aputer;
				aputer.push_back(monetat.gramm[i][1][1]+"");

			
			}

			

		}
	}
}

string avance_point(string monslip)
{
	for (int i = 0; i<monslip.size(); i++)
		if (monslip[i] == '.')
		{
			monslip.erase(monslip.begin()+i);
			monslip.insert(i+1,".");

			break;
		}
	return monslip;
}


void supr_doublon_splvector(vector <string> toto)
{

}



vector <etat> grammaire::creation_automate()
{
	vector <etat> automate;
	string vide = "default";
	etat unetat;
	vide_etat(unetat);

	// creation des etats finaux (r1, r2...)
	vector <vector <string> > suivant;
	for (int i = 0; i< magrammaire.size(); i++)
	{
		for (int j = 1; j<magrammaire[i].size(); j++)
		{
			vector <string> apusher;
			apusher.push_back(magrammaire[i][0]);
			if (magrammaire[i][j] != "@")
				apusher.push_back(magrammaire[i][j]+".");
			else 
				apusher.push_back(".");
			suivant.push_back(apusher);
		}
	}


	// creation de l'etat de base
	for (int i = 0; i< magrammaire.size(); i++)
	{
		for (int j = 1; j<magrammaire[i].size(); j++)
		{
			vector <string> apusher;
			apusher.push_back(magrammaire[i][0]);
			if (magrammaire[i][j] != "@")
				apusher.push_back("."+magrammaire[i][j]);
			else 
				apusher.push_back(".");
			unetat.gramm.push_back(apusher);
		}
	}
	

	// on remplie suivant avec ce qui peut suivre (si on a .AB on rajoute A)
	suiv_begin(unetat);

	// on rajoute le premier etat
	automate.push_back(unetat);


	// affichage de I0 :
	cout << endl << "I0 : "<< endl;
	for (int i = 0; i<unetat.gramm.size(); i++)
	{
		cout << unetat.gramm[i][0] << "	" << unetat.gramm[i][1]<< endl;
	}



	// on rentre dans la boucle
	vide_etat(unetat);
	while (yadeszero(automate)) 
	{
		// on cherche un etat non finie (ou finie = 0)
		int etat_a_completer;
		for (int i = 0; i<automate.size(); i++)
			if (automate[i].finie == 0)
				etat_a_completer = i;

		int lettre_sav = 0;
		//on cherche un truc qui pointe vers vide
		for (int i = 0; i<automate[etat_a_completer].suivant.size();i++)
			if (automate[etat_a_completer].suivant[i].size() == 1)
				lettre_sav = i;



		//des qu'il est trouvé on creer un etat independant, on utilise unetat
		vide_etat(unetat);
		// on remplie en bougeant le point
		for (int i =0; i< automate[etat_a_completer].gramm.size(); i++)
		{
			for (int j = 0; j<automate[etat_a_completer].gramm[i][1].size();j++)
			{
				if (automate[etat_a_completer].gramm[i][1][j] == '.')
				{
					// premiere secu, on s'assure que le pont n'est oas le dernier caractere
					if (j != automate[etat_a_completer].gramm[i][1].size())
					{
						// on regarde si c'est le bon caractere
						if (automate[etat_a_completer].gramm[i][1][j+1]+"" == automate[etat_a_completer].suivant[lettre_sav][0])
						{
							// on le mait avec le point de decaler
							vector <string> tempa;
							tempa.push_back(automate[etat_a_completer].gramm[i][0]);
							tempa.push_back(avance_point(automate[etat_a_completer].gramm[i][1]));
							unetat.gramm.push_back(tempa);

						}
					}


					break;
				}
			}

		}
		// on stoque ce qui se rajoutte avec les points bougé
		/*while (gramm_pasfinie())
		{
			vector <string> grammamaitre;
			for (int i = 0; i<unetat.gramm.size(); i++)
			{
				//on recherche le point
				for (int j = 0;j<unetat.gramm[i][1].size(); j++)
					if (unetat.gramm[i][1][j] == '.')
						if (j != unetat.gramm[i][1].size())
						{
							grammamaitre.push_back(unetat.gramm[i][1][j+1]+"");
						}

			}
			// on push les etats a rajouté

			// on suprimme les doublons


		}*/
		

		// on regarde si il existe deja
		// si il existe, on fait pointé vers lui et on oublie notre etat creer
		//sinon on l'insert et on fait pointer vers automate.size()-1
	}

	// on rajoutte tous les r1 etc


	return automate;
}
