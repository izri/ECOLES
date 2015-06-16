#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "historique.h"


using namespace std;

listo malisteC=NULL;
liprod malisteP=NULL;

int AskforNumb(){ /* Demande un entier pour le menu*/
    int d;

      if(scanf("%d", &d) !=1) {
            printf("Input error\n");
            exit(-1);
      }
    return d;
}

int testreturn(){ // Permet de relancer le programme
    printf("\n\nNext : \n0 : Return to menu\n1 : Close the Program\nYour choice : ");
    int choice = AskforNumb();
      if(choice==0){
            return 0;
      }

      if(choice==1){
            return 1;
      }

      if(choice != 0 || choice != 1){
            printf("\nTry again");
            testreturn();
      }
}

void afficherList(listo malisteC) {

    histo* tmp = malisteC;

    //cout << "tu marches pas?" << endl;
    while ( tmp !=NULL) {

        cout << tmp->prenomC << endl;
        cout << tmp->fidelite << endl;
        //cout << "tu marches paeznfniezfpa?" << endl;

        tmp=tmp->suivant;
    }
}



int main()
{

    char nom [80];
    char prenom [80];
    int age;
    int tel;
    int jour;
    int mois;
    int annee;
    char produit[80];
    int prix;
    char defaulte [80];


   /* printf ("Enter the day: ");
    scanf ("%d",&jour);
    printf ("Enter the month: ");
    scanf ("%d",&mois);
    printf ("Enter the year: ");
    scanf ("%d",&annee);

    printf ("Enter your family name: ");
    scanf ("%79s",nom);
    printf ("Enter your first name: ");
    scanf ("%79s",prenom);
    printf ("Enter your age: ");
    scanf ("%d",&age);
    printf ("Entrer les 3 derniers numeros de votre numéro de telephone : ");
    scanf("%d",&tel);

    printf ("Enter the product: ");
    scanf("%79s",produit);
    printf ("Enter the price: ");
    scanf ("%d",&prix);


    Date date(jour,mois,annee);
    Produit manger(produit,prix);
    Client Albert (prenom, nom, age, tel);

    Command LaCommandeMr(Albert,manger,date);
    LaCommandeMr.affiche();

    historique stockage(LaCommandeMr);
    stockage.stockageC(malisteC,LaCommandeMr);
    stockage.stockageP(malisteP,LaCommandeMr);

*/

int restart=0;

    while(restart == 0){
    system("cls");

    printf(" \nQue voulez vous faire ?\n\n 0 : Nouvelle Commande \n 1 : Recherche occurence client \n 2 : Recherche occurence produit\n 3 : Reinitialisation des clients\n 4 : Reinitialisation des produits\n 5 : Afficher votre liste de clients\n 6 : Afficher votre liste de produit\n");
    int addorsoust = AskforNumb();



    if (addorsoust!=0 && addorsoust!= 1 && addorsoust !=2 && addorsoust !=3 && addorsoust !=4 && addorsoust !=5 && addorsoust !=6){

            printf("\nRien faire\n");
            return 0;
    }

    if(addorsoust==0){
        system("cls");


    printf("\n\n------------------Nouveau Client----------------\n\n");


    printf ("Enter the day: ");
    scanf ("%d",&jour);
    printf ("Enter the month: ");
    scanf ("%d",&mois);
    printf ("Enter the year: ");
    scanf ("%d",&annee);

    printf ("Enter your family name: ");
    scanf ("%79s",nom);
    printf ("Enter your first name: ");
    scanf ("%79s",prenom);
    printf ("Enter your age: ");
    scanf ("%d",&age);
    printf ("Entrer les 3 derniers numeros de votre numero de telephone : ");
    scanf("%d",&tel);

    printf ("Enter the product: ");
    scanf("%79s",produit);
    printf ("Enter the price: ");
    scanf ("%d",&prix);


    Date date(jour,mois,annee);
    Produit manger(produit,prix);
    Client Albert (prenom, nom, age, tel);

    Command LaCommandeMr(Albert,manger,date);
    LaCommandeMr.affiche();

    historique stockage(LaCommandeMr);
    stockage.rechercheListo(malisteC,LaCommandeMr);
    stockage.rechercheProd(malisteP,LaCommandeMr);

    afficherList(malisteC);

    restart = testreturn();

    }

     if(addorsoust==1){
        system("cls");

    printf("\n\n------------------Occurence Client----------------\n\n");

    char nom1 [80];
    char prenom1 [80];
    int age1;
    int tel1;

    printf ("Enter your family name: ");
    scanf ("%79s",nom1);
    printf ("Enter your first name: ");
    scanf ("%79s",prenom1);
    printf ("Enter your age: ");
    scanf ("%d",&age1);
    printf ("Entrer les 3 derniers numeros de votre numero de telephone : ");
    scanf("%d",&tel1);

    Client JeanBernard(prenom1,nom1,age1,tel1);
    Date dat(25,04,2015);
    Produit mang(defaulte,159);
    Command com(JeanBernard, mang, dat );
    historique recherche(com);

    int occ = recherche.occurenceC( malisteC, nom1, prenom1);

    JeanBernard.afficher();
    //cout << "est venu :" << occ << " fois." << endl;
    printf("est venu : %d fois.\n", occ);

    afficherList(malisteC);

    restart = testreturn();

    }

    if(addorsoust==2){
        system("cls");

    printf("\n\n------------------Occurence Produit----------------\n\n");

    char produit1 [80];
    char albert [80];
    char eistein [80];
    int prix1;

    printf ("Enter the product: ");
    scanf("%79s",produit1);
    printf ("Enter the price: ");
    scanf ("%d",&prix1);

    Client defo(albert,eistein,150,025);
    Produit plat(produit1,prix1);
    Date da(25,04,2015);
    Command gourmet(defo, plat, da);
    historique recherche(gourmet);

    int occ = recherche.occurenceP( malisteP, produit1);

    cout << "Le nombre d'occurence de : " << produit1 << " est " << occ << endl;

    restart = testreturn();

    }

    if(addorsoust==3){
        system("cls");

    printf("\n\n------------------Reinitialiser la base de donnee des clients----------------\n\n");

    malisteC == NULL;
    cout << "Votre reinitialisation a ete effectue !\n" << endl;

    restart = testreturn();

    }

    if(addorsoust==4){
        system("cls");

    printf("\n\n------------------Reinitialiser la base de donnee des produits----------------\n\n");

    malisteP == NULL;
    cout << "Votre reinitialisation a ete effectue !\n" << endl;

    restart = testreturn();

    }

    if(addorsoust==5){
        system("cls");

    printf("\n\n------------------Afficher la liste de vos clients----------------\n\n");

    histo* tmp = malisteC;

    //cout << "tu marches ?" << endl;
    while ( tmp !=NULL) {

        cout << tmp->prenomC << endl;
        cout << tmp->fidelite << endl;
        //cout << "tu marches bien ?" << endl;

        tmp=tmp->suivant;
    }

    restart = testreturn();

    }

    if(addorsoust==6){
        system("cls");

    printf("\n\n------------------Afficher la liste de vos produits----------------\n\n");

    prod* tmp = malisteP;

    //cout << "tu marches ?" << endl;
    while ( tmp !=NULL) {

        cout << tmp->nomP << endl;
        cout << tmp->nombre << endl;
        //cout << "tu marches bien ?" << endl;

        tmp=tmp->succ;
    }

    restart = testreturn();

    }

    }

    return 0;
}
