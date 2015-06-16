#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int returnChoixType (int i){
    do {
    cout << "Veuillez entrer 1 2 ou 3 ou 4" << endl;
    cout <<"1) Entree"<<endl;
    cout <<"2) Plats "<<endl;
    cout <<"3) Dessert"<<endl;
    cout <<"4) Supprimer article"<<endl;
    cin >> i;
    }while(i!=1 && i!=2 && i!=3 && i!=4 && i!=1234);
    return i;
}

int returnChoixEntree(int i){
    do{
    cout <<"Choisissez une Entree 1 2 ou 3"<<endl;
    cout <<"1) Salade" <<endl;
    cout <<"2) Soupe Jap"<<endl;
    cout <<"3) Chorba"<<endl;
    cin >>i;
    }
    while(i!=1 && i!=2 && i!=3 &&  i!=1234);
    return i;
}

int returnChoixPlat(int i){
    do{
    cout <<"Choisissez un plat 1 2 ou 3"<<endl;
    cout <<"1) Couscous" <<endl;
    cout <<"2) Sushi"<<endl;
    cout <<"3) Cassoulet"<<endl;
    cin >>i;
    }while(i!=1 && i!=2 && i!=3  && i!=1234);
    return i;
}
int returnChoixDessert(int i){
    do{
    cout <<"Choisissez un dessert 1 2 ou 3"<<endl;
    cout <<"1) Gateau Chocolat" <<endl;
    cout <<"2) Boule De Coco" <<endl;
    cout <<"3) Corne de Gazelle"<<endl;
    cin >>i;
    }while(i!=1 && i!=2 && i!=3 && i!=1234 );
    return i;
}

void sauvegarde(int nombreClient, int comptE1, int comptE2, int comptE3, int comptP1, int comptP2, int comptP3,int comptD1, int comptD2,int comptD3, int comptEsp, int comptCB){

    string date;
    cout << "Veuillez entrer la date de cette façon JJ/MM/AA"<<endl;
    cin >> date;

    string const nomFichier("historique.txt");
    ofstream monFlux(nomFichier.c_str(),ios::app);

    if(monFlux)
    {

        monFlux << "----------------------------------------------------------------------------------------------------------------------"<<endl;
        monFlux << "Bonjour les statistique du " <<date<<" sont"<<endl;
        monFlux <<"Aujourd'hui il y a eu "<< nombreClient <<" clients"<<endl<<endl;
        monFlux <<"Il y a eu "<<comptE1<<" salade(s) commandee(s)"<<endl<< "Il y a eu "<<comptE2<<" soupe(s) jap' commandee(s)"<<endl<< "Il y a eu "<<comptE3<<" Chorba(s) commandee(s)"<<endl<< endl;
        monFlux << "Il y a eu "<<comptP1<<" Couscous(s) commandee(s)"<<endl << "Il y a eu "<<comptP2<<" Sushi(s) jap' commandee(s)"<<endl<< "Il y a eu "<<comptP3<<" Cassoulet(s) commandee(s)"<<endl << endl;
        monFlux << "Il y a eu "<<comptD1<<" Gateau chocolat"<<endl<< "Il y a eu "<<comptD2<<" Boule COCO"<<endl<< "Il y a eu "<<comptD3<<" Corne de gazelle"<<endl<<endl;
        monFlux <<"Il y a eu " <<comptEsp<<" paiements en espece" <<endl<<"Il y a eu " <<comptCB<<" paiements en CB" << endl<<endl;
}    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
    cout <<"L'historique du "<<date<<" a ete sauvegarde dans le fichier historique.txt"<<endl;
    }

int main()
{
    int testEstClient=1;
    int motDePasseAdmin=1234;
    int yesOrNot=0;
    int especeOuCarte=0;
    int numClient=1;
    int nombreClient;
    int quit=0;
    int choixType=0;
    int choixEntree=0;
    int choixPlat=0;
    int choixDessert=0;
    int choixAdmin=0;
    int comptE1=0;
    int comptE2=0;
    int comptE3=0;
    int comptP1=0;
    int comptP2=0;
    int comptP3=0;
    int comptD1=0;
    int comptD2=0;
    int comptD3=0;
    int comptEsp=0;
    int comptCB=0;

    int comptEE1=0;
     int comptEE2=0;
     int comptEE3=0;
     int comptPP1=0;
     int comptPP2=0;
     int comptPP3=0;
     int comptDD1=0;
     int comptDD2=0;
     int comptDD3=0;
     int j;
//Cote client
cout << "Bonjour vous etes le premier client"<< endl;
do{
    choixType=returnChoixType(choixType);
    if(choixType==1){
        choixEntree=returnChoixEntree(choixEntree);
        if(choixEntree==1) {
            comptE1++;

        }
        else if(choixEntree==2) {
            comptE2++;

        }
        else if(choixEntree==3) {
            comptE3++;

        }







        cout << "Voulez vous choisir autre chose( 1 ou 2)?" << endl;
        cout << "1) Oui" << endl << "2) Non" <<endl;
        cin >> yesOrNot;

        if(yesOrNot==1){
            continue;
        }
        if(yesOrNot==2){
        cout <<endl;
        cout << "Comment souhaitez vous reglez Espece ou carte bancaire ou abandonner la commande ? Entrez 1 ou 2 ou 3" << endl;
        cin >> especeOuCarte;
        if(especeOuCarte==1){
            comptEsp++;
            comptEE1=comptEE1+comptE1;
     comptEE2=comptEE2+comptE2;
     comptEE3=comptEE3+comptE3;
     comptPP1=comptPP1+comptP1;
     comptPP2=comptPP2+comptP2;
     comptPP3=comptPP3+comptP3;
     comptDD1=comptDD1+comptD1;
     comptDD2=comptDD2+comptD2;
     comptDD3=comptDD3+comptD3;
     comptE1=0;
     comptE2=0;
     comptE3=0;
     comptP1=0;
     comptP2=0;
     comptP3=0;
     comptD1=0;
     comptD2=0;
     comptD3=0;
            cout<<endl<<"Merci au revoir, votre commande à ete enregistre !"<<endl;
        numClient++;
        }
        if(especeOuCarte==2){
            comptCB++;
            comptEE1=comptEE1+comptE1;
     comptEE2=comptEE2+comptE2;
     comptEE3=comptEE3+comptE3;
     comptPP1=comptPP1+comptP1;
     comptPP2=comptPP2+comptP2;
     comptPP3=comptPP3+comptP3;
     comptDD1=comptDD1+comptD1;
     comptDD2=comptDD2+comptD2;
     comptDD3=comptDD3+comptD3;
     comptE1=0;
     comptE2=0;
     comptE3=0;
     comptP1=0;
     comptP2=0;
     comptP3=0;
     comptD1=0;
     comptD2=0;
     comptD3=0;
            cout<<endl<<"Merci au revoir, votre commande a ete enregistre !"<<endl;
        numClient++;
        }
     if(especeOuCarte==3)
     {
         cout<< "abandon de commande"<<endl;
          comptE1=0;
     comptE2=0;
     comptE3=0;
     comptP1=0;
     comptP2=0;
     comptP3=0;
     comptD1=0;
     comptD2=0;
     comptD3=0;


     }
        }

    }
    if(choixType==2){
        choixPlat=returnChoixPlat(choixPlat);
        if(choixPlat==1) {
            comptP1++;
        }
        else if(choixPlat==2) {
            comptP2++;
        }
        else if(choixPlat==3) {
            comptP3++;
        }
        cout << "Voulez vous choisir autre chose( 1 ou 2)?" << endl;
        cout << "1) Oui" << endl << "2) Non" <<endl;
        cin >> yesOrNot;
        if(yesOrNot==1){
            continue;
        }
        if(yesOrNot==2){
        cout <<endl;
        cout << "Comment souhaitez vous reglez Espece ou carte bancaire ou abandonner la commande ? Entrez 1 ou 2 ou 3" << endl;
        cin >> especeOuCarte;
        if(especeOuCarte==1){
            comptEsp++;
            comptEE1=comptEE1+comptE1;
     comptEE2=comptEE2+comptE2;
     comptEE3=comptEE3+comptE3;
     comptPP1=comptPP1+comptP1;
     comptPP2=comptPP2+comptP2;
     comptPP3=comptPP3+comptP3;
     comptDD1=comptDD1+comptD1;
     comptDD2=comptDD2+comptD2;
     comptDD3=comptDD3+comptD3;
     comptE1=0;
     comptE2=0;
     comptE3=0;
     comptP1=0;
     comptP2=0;
     comptP3=0;
     comptD1=0;
     comptD2=0;
     comptD3=0;

            cout<<endl<<"Merci au revoir, votre commande a ete enregistre !"<<endl;
        numClient++;
        }
        if(especeOuCarte==2){
            comptCB++;
             comptEE1=comptEE1+comptE1;
     comptEE2=comptEE2+comptE2;
     comptEE3=comptEE3+comptE3;
     comptPP1=comptPP1+comptP1;
     comptPP2=comptPP2+comptP2;
     comptPP3=comptPP3+comptP3;
     comptDD1=comptDD1+comptD1;
     comptDD2=comptDD2+comptD2;
     comptDD3=comptDD3+comptD3;
     comptE1=0;
     comptE2=0;
     comptE3=0;
     comptP1=0;
     comptP2=0;
     comptP3=0;
     comptD1=0;
     comptD2=0;
     comptD3=0;
            cout<<endl<<"Merci au revoir, votre commande a ete enregistre !"<<endl;
        numClient++;
        }

        if(especeOuCarte==3)
     {
         cout<< "abandon de commande"<<endl;
        comptE1=0;
        comptE2=0;
        comptE3=0;
        comptP1=0;
        comptP2=0;
        comptP3=0;
        comptD1=0;
        comptD2=0;
        comptD3=0;


     }
        }
    }
    if(choixType==3){
        choixDessert=returnChoixDessert(choixDessert);
        if(choixDessert==1) {
            comptD1++;
        }
        else if(choixDessert==2) {
            comptD2++;
        }
        else if(choixDessert==3) {
            comptD3++;
        }
        cout << "Voulez vous choisir autre chose( 1 ou 2)?" << endl;
        cout << "1) Oui" << endl << "2) Non" <<endl;
        cin >> yesOrNot;
        if(yesOrNot==1){
            continue;
        }
        if(yesOrNot==2){
        cout <<endl;
        cout << "Comment souhaitez vous regler 1)Espece ou 2)Carte Bancaire ou abandonner la commande ? Entrez 1 ou 2 ou 3" << endl;
        cin >> especeOuCarte;
        if(especeOuCarte==1){
            comptEsp++;
            comptEE1=comptEE1+comptE1;
     comptEE2=comptEE2+comptE2;
     comptEE3=comptEE3+comptE3;
     comptPP1=comptPP1+comptP1;
     comptPP2=comptPP2+comptP2;
     comptPP3=comptPP3+comptP3;
     comptDD1=comptDD1+comptD1;
     comptDD2=comptDD2+comptD2;
     comptDD3=comptDD3+comptD3;
     comptE1=0;
     comptE2=0;
     comptE3=0;
     comptP1=0;
     comptP2=0;
     comptP3=0;
     comptD1=0;
     comptD2=0;
     comptD3=0;
            cout<<endl<<"Merci au revoir, votre commande a ete enregistre !"<<endl;
        numClient++;
        }
        if(especeOuCarte==2){
            comptCB++;
            comptEE1=comptEE1+comptE1;
     comptEE2=comptEE2+comptE2;
     comptEE3=comptEE3+comptE3;
     comptPP1=comptPP1+comptP1;
     comptPP2=comptPP2+comptP2;
     comptPP3=comptPP3+comptP3;
     comptDD1=comptDD1+comptD1;
     comptDD2=comptDD2+comptD2;
     comptDD3=comptDD3+comptD3;
     comptE1=0;
     comptE2=0;
     comptE3=0;
     comptP1=0;
     comptP2=0;
     comptP3=0;
     comptD1=0;
     comptD2=0;
     comptD3=0;
            cout<<endl<<"Merci au revoir, votre commande a ete enregistre !"<<endl;
        numClient++;
        }
        if(especeOuCarte==3)
     {
         cout<< "abandon de commande"<<endl;
          comptE1=0;
     comptE2=0;
     comptE3=0;
     comptP1=0;
     comptP2=0;
     comptP3=0;
     comptD1=0;
     comptD2=0;
     comptD3=0;


     }

        }
    }
        //commande suppression de plat
    if(choixType==4)
        {
            if (comptE1>0 ||comptE2>0||comptE3>0 ||comptP1>0 ||comptP2>0||comptP3>0 ||comptD1>0 ||comptD2>0||comptD3>0)
            {
    cout << endl;
    cout << "Vous avez "<< endl;
    cout << "1: "<<comptE1<<" salade(s) commandee(s)"<<endl;
    cout << "2: "<<comptE2<<" soupe(s) jap' commandee(s)"<<endl;
    cout << "3: "<<comptE3<<" Chorba(s) commandee(s)"<<endl;
    cout << "4: "<<comptP1<<" Couscous(s) commandee(s)"<<endl;
    cout << "5: "<<comptP2<<" Sushi(s) jap' commandee(s)"<<endl;
    cout << "6: "<<comptP3<<" Cassoulet(s) commandee(s)"<<endl;
    cout << "7: "<<comptD1<<" Gateau chocolat"<<endl;
    cout << "8: "<<comptD2<<" Boule COCO"<<endl;
    cout << "9: "<<comptD3<<" Corne de gazelle"<<endl;

    cout <<"Que voulez-vous supprimer ?"<<endl;

    cout <<"taper de 1 a 9 "<<endl;
    cin >>j;




                if (j==1 && comptE1>=1 )
                {
                comptE1--;
                cout << "vous avez enlevez 1 salade"<<endl;
                }
                    else if(j==1 && comptE1<=0)
                    {cout<<"pas de salade a enlever"<<endl;}


                if (j==2 && comptE2>=1 )
                {
                comptE2--;
                cout << "vous avez enlevez 1 soupe jap"<<endl;
                }
                    else if(j==2 && comptE2<=0)
                    {cout<<"pas de soupe jap a enlever"<<endl;}

                if (j==3 && comptE3>=1 )
                {
                comptE3--;
                cout << "vous avez enlevez 1 chorba"<<endl;
                }
                    else if(j==3 && comptE3<=0)
                    {cout<<"pas de chorba a enlever"<<endl;}

                if (j==4 && comptP1>=1 )
                {
                comptP1--;
                cout << "vous avez enlevez 1 couscous"<<endl;
                }
                    else if(j==4 && comptP1<=0)
                    {cout<<"pas de couscous a enlever"<<endl;}

                if (j==5 && comptP2>=1 )
                {
                comptP2--;
                cout << "vous avez enlevez 1 sushi"<<endl;
                }
                    else if(j==5 && comptP2<=0)
                    {cout<<"pas de sushi a enlever"<<endl;}

                if (j==6 && comptP3>=1 )
                {


                cout << "vous avez enlevez 1 cassoulet"<<endl;

                comptP3--;
                }
                    else if(j==6 && comptP3<=0)
                    {cout<<"pas de cassoulet a enlever"<<endl;}

                if (j==7 && comptD1>=1 )
                {
                comptD1--;
                cout << "vous avez enlevez 1 gateau chocolat"<<endl;
                }
                    else if(j==7 && comptD1<=0)
                    {cout<<"pas de gateau chocolat a enlever"<<endl;}

                if (j==8 && comptD2>=1 )
                {
                comptD2--;
                cout << "vous avez enlevez 1 boule COCO"<<endl;
                }
                    else if(j==8 && comptD2<=0)
                    {cout<<"pas de boule COCO a enlever"<<endl;}

                if (j==9 && comptD3>=1 )
                {
                comptD3--;
                cout << "vous avez enlevez 1 corne de gazelle"<<endl;
                }
                    else if(j==9 && comptD3<=0)
                    {cout<<"pas de corne de gazelle a enlever"<<endl;}

                    }



                else
                {
                cout <<"Vous n'avez pas d'article a enlever." <<endl;

                }
        }
    //TAPER LE MDP ADMIN LORS DU CHOIX POUR ACCEDER A LA PAGE ADMIN
        if(choixType==motDePasseAdmin){
        testEstClient=0;
    }
        cout << endl;
        if(testEstClient==1){
        cout << "Bonjour vous etes le client numero " <<numClient<< endl;
    }
}
    while (testEstClient==1);
//Coté ADMIN
nombreClient=numClient-1;
cout << "Bonjour ADMIN"<<endl;
do{
cout<<"Que souhaitez vous faire ?" << endl;
cout <<"1) Consulter le nombre de client de la journee"<<endl <<"2) Consulter les statistiques sur les entrees" << endl;
cout <<"3) Consulter les statistiques sur les plats" <<endl<<"4) Consulter les statistiques sur les desserts" <<endl;
cout <<"5) Consulter les statistiques sur les modes de paiements"<<endl<<"6) Sauvegarder l'historique du jour" <<endl;
cout << "7) Quitter"<<endl;

        cin >> choixAdmin;
    if(choixAdmin==1){
    cout << "Aujourd'hui il y a eu "<<nombreClient <<" clients"<<endl;
}
    if(choixAdmin==2){
    cout << endl;
    cout << "Il y a eu "<<comptEE1<<" salade(s) commandee(s)"<<endl;
    cout << "Il y a eu "<<comptEE2<<" soupe(s) jap' commandee(s)"<<endl;
    cout << "Il y a eu "<<comptEE3<<" Chorba(s) commandee(s)"<<endl;
}
    if(choixAdmin==3){
    cout << endl;
    cout << "Il y a eu "<<comptPP1<<" Couscous(s) commandee(s)"<<endl;
    cout << "Il y a eu "<<comptPP2<<" Sushi(s) jap' commandee(s)"<<endl;
    cout << "Il y a eu "<<comptPP3<<" Cassoulet(s) commandee(s)"<<endl;
}
    if(choixAdmin==4){
    cout << endl;
    cout << "Il y a eu "<<comptDD1<<" Gateau chocolat"<<endl;
    cout << "Il y a eu "<<comptDD2<<" Boule COCO"<<endl;
    cout << "Il y a eu "<<comptDD3<<" Corne de gazelle"<<endl;
}
    if(choixAdmin==5) {
    cout<<"Il y a eu " <<comptEsp<<" paiements en espece" <<endl;
    cout<<"Il y a eu " <<comptCB<<" paiements en CB" << endl;
}
    if(choixAdmin==6){
    sauvegarde(nombreClient,comptEE1,comptEE2,comptEE3,comptPP1,comptPP2,comptPP3,comptDD1,comptDD2,comptDD3,comptEsp,comptCB);
}

if(choixAdmin==7){
    quit=1;
}
cout<<endl;
}
while(quit==0);
return 0;
}
