#include "grammaire.h"


string supprimerespace(string a)
{
    int taille_utile = a.size();
    for(int i =0; i<a.size(); i++)
    {
        if(a[i] == ' ')
        {
            for(int j=i; j<a.size()-1; j++)
            {
                a[j] = a[j+1];

            }
            taille_utile--;
        }
    }
    a.resize(taille_utile);
    return a;
}

void lecturefichier(grammaire* g)
{
    string test1,test2(" ");
    ifstream fichier("grammaire.txt");
    size_t found;


    //calcul du nombre de ligne du fichier (utile pour notre SDD)
    int nombre_ligne(0),cpt(0);
    while(getline(fichier,test1))
    {
        nombre_ligne++;
    }
    g->nombre_ligne = nombre_ligne;
    //on peut maintenant allouer la première dimension de notre string** production
    g->production = new string*[nombre_ligne];
    for(int i=0; i<nombre_ligne; i++)
    {
        g->production[i] = new string[2];
    }
    fichier.clear();
    fichier.seekg(0,ios::beg);



    test2 = " ";
    int cpt2, fini, tmp_prec,found2,existant;
    while(getline(fichier,test1))
    {
        if(test1.size() == 1)
        {
            g->production[cpt][0] = test1;
            g->production[cpt][1] = "&";
        }
        else if(test1.size() == 2 && test1[1] == 39)
        {
            g->production[cpt][0] = test1;
            g->production[cpt][1] = "&";
        }
        else
        {
            cpt2 = 1 ;
            fini = 0 ;
            found = 0;
            tmp_prec = found ;
            found = test1.find(test2,found+1);
            //on gère le premier symbole de la ligne
            g->production[cpt][0] = test1.substr(0,found);
            while (fini == 0)
            {
                found2 = 0 ;
                found2 = test1.find(test2,cpt2);
                //cout << endl << tmp_prec << " " << found2 << " " << cpt2 << endl ;
                if (found2 < tmp_prec)
                {
                    found2 = -1 ;
                }
                if (found2 != -1)
                {

                for (int i = 0 ; i < g->elt_grammaire.size() ; i++)
                {
                    if (g->elt_grammaire[i] == test1.substr(tmp_prec , found2-tmp_prec))
                    {
                        existant = 1 ;
                    }
                }
                if (existant != 1)
                {
                    g->elt_grammaire.push_back(test1.substr(tmp_prec , found2-tmp_prec));
                    //cout << endl << "tmp_prec : " << tmp_prec << " found2 : " << found2 << endl ;
                    //cout << endl << "insere " << test1.substr(tmp_prec , found2-tmp_prec) << endl ;
                }
                else {
                    existant = 0 ;
                }
                }
                else
                {
                    for (int i = 0 ; i < g->elt_grammaire.size() ; i++)
                {
                    if (g->elt_grammaire[i] == test1.substr(tmp_prec , test1.size()-tmp_prec))
                    {
                        existant = 1 ;
                    }
                }
                if (existant != 1)
                {
                    g->elt_grammaire.push_back(test1.substr(tmp_prec , test1.size()-tmp_prec));
                    //cout << endl << "tmp_prec : " << tmp_prec << " found2 : " << found2 << endl ;
                    //cout << endl << "insere " << test1.substr(tmp_prec , found2-tmp_prec) << endl ;
                }
                    fini = 1 ;
                }
                tmp_prec = found2+1 ;
                cpt2++ ;
            }
            g->production[cpt][1] = supprimerespace(test1.substr(found));
        }



        cpt++;
    }
    fichier.close();
}

void lecturegrammaire(grammaire g)//affichage de la grammaire stockée en mémoire
{
    cout << "Information : le caractere \"&\" est epsilon\n" << endl;
    cout << "On a la grammaire suivante :" << endl;
    for(int i =0; i<g.nombre_ligne; i++)
    {
        cout << g.production[i][0] << "->" << g.production[i][1] << endl;
    }
    cout << endl;
}

void creationvariable_first_follow(grammaire g,vector <string*>* first_follow)
{
    string* p(NULL);
    bool test(0);

    //introduction du symbole créant la règle dans notre vector
    for(int i =0; i<g.nombre_ligne; i++)
    {
        test = 0;
        if(i==0)
        {
            p = new string[3];
            p[0] = g.production[i][0];//on prend le symbole qui est à gauche de la flèche
            first_follow->push_back(p);
            //cout << *first_follow[0][0] << endl;
        }
        else
        {
            for(std::vector<string*>::iterator it = first_follow->begin(); it != first_follow->end(); ++it)
            {
                if(*it[0] == g.production[i][0])
                {
                    test = 1;
                }
            }
            if(test == 0)
            {
                p = new string[3];
                p[0] = g.production[i][0];
                first_follow->push_back(p);
            }
        }
    }

    //calcul du premier
    int cpt(0);
    for(std::vector<string*>::iterator it = first_follow->begin(); it != first_follow->end(); ++it)
    {
        for(int i =0; i<g.nombre_ligne; i++)
        {
            if(*it[0] == g.production[i][0])
            {
                first_follow->at(cpt)[1] += g.production[i][1][0]; //on donne le premier
            }
        }
        cpt++;
    }


    //majuscule : entre 65 et 90
    string symbole,symbole2;
    for(int i =0; i<first_follow->size(); i++)
    {
        for(int j = 0; j<first_follow->at(i)[1].size();j++)
        {
            if(first_follow->at(i)[1][j] > 64 && first_follow->at(i)[1][j] < 91) //si le caractère est majuscule
            {
                symbole = first_follow->at(i)[1][j];
                for(int k=0; k<first_follow->size(); k++)
                {
                    if(first_follow->at(k)[0] == symbole)
                    {
                        symbole2 = first_follow->at(k)[1];
                        for(int h =0; h<symbole2.size();h++)
                        {
                            if(symbole2[h] == first_follow->at(k)[0][0]) //si le caractère est égal à la majuscule relevée, on l'efface
                            {
                                symbole2.erase(h,1);
                                h--;
                            }
                        }
                        first_follow->at(i)[1].replace(j,1,symbole2);
                    }
                }
            }
        }
    }

    //suppresion des caractères redondants
    for(int i =0; i<first_follow->size(); i++)
    {
        for(int j =0; j<first_follow->at(i)[1].size(); j++)//on parcourt les caractères premiers relevés
        {
            //cout << first_follow->at(i)[0] << " " << first_follow->at(i)[1] << endl;
            for(int k =j+1; k<first_follow->at(i)[1].size(); k++)//on parcourt les caractères suivants à comparer
            {
                //cout << first_follow->at(i)[0] << " " << first_follow->at(i)[1] << " "<< first_follow->at(i)[1][j] << " " << first_follow->at(i)[1][k] << endl;
                if(first_follow->at(i)[1][j] == first_follow->at(i)[1][k])
                {
                    //cout << "redondance" << endl;
                    first_follow->at(i)[1].erase(k-1,1);
                    k--;
                    j--;
                }
            }
            //cout << "Devient " <<  first_follow->at(i)[0] << " " << first_follow->at(i)[1] << " " << endl;
        }
    }
    cout << "Les premiers de chaque symbole non-terminal sont :" << endl;
    for(int i =0; i<first_follow->size(); i++)
    {
        cout << "F(" << first_follow->at(i)[0] << ")= { " << first_follow->at(i)[1] << " }" << endl;
    }
    cout <<endl;

    //fin des caractères premiers


    symbole.clear();
    symbole2.clear();
    test = 0;
    //début des caractères suivants

    /*
    for(int i=0; i<first_follow->size(); i++)//on parcourt les règles
    {
        symbole = first_follow->at(i)[0];//on prend le symbole qui fait la règle (la lettre à gauche de la flèche)
        for(int j=0; j<g.nombre_ligne; j++)
        {
            for(int k=0; k<g.production[j][1].size(); k++) //on parcourt les caractères de ce que produit la règle
            {

                if(k < g.production[j][1].size() -1) //si le caractère n'est pas un symbole terminal et qu'il n'est pas le dernier de la règle
                {
                    if(g.production[j][1][k] == symbole.c_str()[0])
                    {
                        symbole2 += g.production[j][1][k+1];
                    }
                }
                else //segfault si on fait k+1
                {
                    symbole2 += first_follow->at(i)[0];
                    //cout << symbole2 << endl;
                }
            }
        }
        first_follow->at(i)[2] = symbole2;
        //cout << symbole2 << endl;
        symbole.clear();
        symbole2.clear();
    }
    */
    int position(0);
    for(int i=0; i<first_follow->size(); i++)
    {
        symbole = first_follow->at(i)[0];//on prend le symbole qui fait la règle (la lettre à gauche de la flèche)
        for(int j=0; j<g.nombre_ligne; j++)//parcours des règles
        {
            if(g.production[j][1].find(symbole.c_str())!=std::string::npos)//si on trouve que symbole est présent dans la règle, on prend le caractère suivant
            {
                position = g.production[j][1].find(symbole.c_str());
                if(position < g.production[j][1].size()-1)
                {
                    symbole2 += g.production[j][1][position+1];
                }
            }
        }
        first_follow->at(i)[2] = symbole2;
        //cout << symbole2 << endl;
        symbole.clear();
        symbole2.clear();
    }
    test = 0;

    //recherche de espilon dans les suivants conservés
    for(int i=0; i<first_follow->size(); i++)
    {
        symbole = first_follow->at(i)[2];
        for(int j=0; j<g.nombre_ligne; j++) //on regarde si espilon est dans la règle
        {
            if(g.production[j][1].find('&')!=std::string::npos)//si on trouve espilon
            {
                //il faut maintenant voir si le suivant retenu est celui du symbole ou non
                //ex: dans S(A), vérifier qu'on a bien S(A) = S(B) U ...
                if(symbole.find(g.production[j][0][0])!=std::string::npos) //si epsilon est absent et que le suivant n'est pas le mot qui fait la règle
                {
                    symbole += first_follow->at(i)[0];// si epsilon appartient à P(B) et qu'on est dans S(mot) avec mot != de B, S(mot) = P(B) U S(mot)
                }
            }
        }
        first_follow->at(i)[2] = symbole;
        symbole.clear();
    }




    //suppresion des caractères redondants
    for(int i =0; i<first_follow->size(); i++)
    {
        for(int j =0; j<first_follow->at(i)[2].size(); j++)//on parcourt les caractères premiers relevés
        {
            //cout << first_follow->at(i)[0] << " " << first_follow->at(i)[2] << endl;
            for(int k =j+1; k<first_follow->at(i)[2].size(); k++)//on parcourt les caractères suivants à comparer
            {
                //cout << first_follow->at(i)[0] << " " << first_follow->at(i)[1] << " "<< first_follow->at(i)[1][j] << " " << first_follow->at(i)[1][k] << endl;
                if(first_follow->at(i)[2][j] == first_follow->at(i)[2][k])
                {
                    //cout << "redondance" << endl;
                    first_follow->at(i)[2].erase(k,1);
                    k--;
                    j--;
                }
            }
            //cout << "  "<<first_follow->at(i)[2] << " " << endl;
        }
        //cout << endl;
    }


    //convertir les majuscules en premiers, ou en suivant
    for(int i=0; i<first_follow->size(); i++)
    {
        for(int j=0; j< first_follow->at(i)[2].size(); j++)
        {
            for(int k=0; k<first_follow->size(); k++)
            {
                if(first_follow->at(k)[0][0] == first_follow->at(i)[2][j])
                {
                    first_follow->at(i)[2].replace(j,1,first_follow->at(k)[1]);
                }
            }
        }
    }

    //on remplace & par $
    for(int i=0; i<first_follow->size(); i++)//parcours des règles
    {
        for(int j=0; j<first_follow->at(i)[2].size(); j++)// parcours des caractères des suivants
        {
            if(first_follow->at(i)[2][j] == '&')
            {
                first_follow->at(i)[2][j] = '$';
            }
        }
    }

     //suppresion des caractères redondants
    for(int i =0; i<first_follow->size(); i++)
    {
        for(int j =0; j<first_follow->at(i)[2].size(); j++)//on parcourt les caractères premiers relevés
        {
            //cout << first_follow->at(i)[0] << " " << first_follow->at(i)[2] << endl;
            for(int k =j+1; k<first_follow->at(i)[2].size(); k++)//on parcourt les caractères suivants à comparer
            {
                //cout << first_follow->at(i)[0] << " " << first_follow->at(i)[1] << " "<< first_follow->at(i)[1][j] << " " << first_follow->at(i)[1][k] << endl;
                if(first_follow->at(i)[2][j] == first_follow->at(i)[2][k])
                {
                    //cout << "redondance" << endl;
                    first_follow->at(i)[2].erase(k,1);
                    k--;
                    j--;
                }
            }
            //cout << "  "<<first_follow->at(i)[2] << " " << endl;
        }
        //cout << endl;
    }

    if(first_follow->at(0)[2].find('$')==std::string::npos)//si on trouve pas le caractère $ dans l'axiome, on le rajoute
    {
        //axiome a toujours $ dans ses suivants
        first_follow->at(0)[2] += '$';
    }


    cout << "Les suivants de chaque symbole non-terminal sont :" << endl;
    for(int i =0; i<first_follow->size(); i++)
    {
        cout << "S(" << first_follow->at(i)[0] << ")= { " << first_follow->at(i)[2] << " }" << endl;
    }
    delete p;
    return;
}


/*
void recursivite_gauche(grammaire* g)
{
    grammaire* g_receive(NULL) , g_tmp(NULL);
    g_receive = new grammaire[1];
    g_tmp = new grammaire[1] ;
    int taille ;

    do{

    taille = 0 ;
     for (int i = 0 ; i < g->nombre_ligne ; i++)
     {
         for (int j = 0 ; j < g->nombre_ligne;j++)
         {
             if(g->production[j][0] != g->production[i][0])
             {
                 if(g->production[i][0] == g->production[j][1].substr(0,g->production[i][0].size()))
                 {
                    taille++;
                 }
             }
         }
     }

    if(taille != 0)
    {
         g_receive->production = new string*[taille];
         for(int i =0; i<taille; i++)
         {
             g_receive->production[i] = new string[2];
         }

        for (int i = 0 ; i < g->nombre_ligne ; i++)
        {
            g_tmp->production[i] = new string[2];
            for (int j = 0 ; j < 2 ; j++)
            {
                g_tmp->production[i][j] = g->production[i][j] ;
            }

        }
         g_tmp->nombre_ligne = g->nombre_ligne;

            for(int i=0; i<nombre_ligne; i++)
            {
                delete g->production[i];
            }
            delete g->production;
            delete g;

             for(int i =0; i<g_tmp->nombre_ligne + taille; i++)
             {
                 g->production[i] = new string[2];
                 for (int j = 0 ; j < 2 ; j++)
                {
                    if (i< g_tmp->nombre_ligne)
                    {
                         g_tmp->production[i][j] = g->production[i][j] ;
                    }
                    else
                    {
                        g_tmp->production[i][j] = g_receive->production[i-g_tmp->nombre_ligne][j] ;
                    }
                }
             }
    }


    }while(taille != 0);

    for(int i=0; i<g_receive->nombre_ligne; i++)
    {
        delete g_receive->production[i];
    }
    delete g_receive->production;
    delete g_receive;

    for(int i=0; i<g_tmp->nombre_ligne; i++)
    {
        delete g_tmp->production[i];
    }
    delete g_tmp->production;
    delete g_tmp;
}

*/

