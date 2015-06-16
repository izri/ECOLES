		 ___________________________________________________________________________________
		|                                                                                   |
		|                                                                                   |
		|  Programme Gestion Restaurant : Sazadaly Maxime et Cl�mence Viard - 2�me ann�e    |
		|                                                                                   |
		|		                   Classe 2A2                                       |
		|                                                                                   |
		|___________________________________________________________________________________|
		



						/!\ IMPORTANT /!\

Ce programme n'a �t� test� que sous Windows. N�anmoins, aucune fonction syst�me n'ont �t� appel�es. Il ne devrait a priori ne pas avoir de soucis.

La ligne de compilation est : g++ -Wall commande.c commande.h main.h -fexceptions -std=c++11 -o commande.exe

Nous conseillons n�anmoins d'utiliser CodeBlocks (que nous avons utilis�). Si � la compilation une erreur appara�t,
allez dans Project -> Build Options et cochez "Have g++ follow the C++11 ISO C++ language standard [-std=c++11]"

						/!\ IMPORTANT /!\


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



					// Fonctionnalit�s du programme \\


	- Gestion des commandes (facturation, datation, application de r�duction, etc.) selon le client
	- Gestion des clients (mise en m�moire de la liste des clients et de leurs venues)
	- Gestion de la fidelit� (r�duction de 20% toute les 10 commandes, parce qu'on est tr�s gentil chez nous)
	- Base de donn�es externe (.txt regroupant des informations, permettant une fermeture du programme et une sauvegarde des donn�es)
	- Possibilit� d'effacer la base de donn�es de commandes, mais maintient permanent de la liste des clients, car chez nous, nos clients, on les aime
	- Analyse des commandes : calcul du nombre de plats command�s.


					
					   // Bilan de la r�alisation \\

	Nous avons r�alis� ce premier programme en C++ en ayant des ambitions un peu trop grande. En effet, nous nous sommes
un peu perdu dans la gestion des donn�es. Premi�rement, voulant passer par des tableaux, nous avons perdu du temps. En effet, aucune sauvegarde n'�tait possible.
	N�anmoins, d�s lors que nous avons eu l'id�e des fichiers .txt, notre id�e s'est �claircie : nous n'avions plus besoin de la classe Historique, que nous
avons �cart�e. Cet axe de travail s'est r�v�l� tr�s int�ressant, bien qu'il a fallu apprendre � communiquer avec nos amis les .txt
	Beaucoup de temps a �t� pass� � chercher comment modifier un caract�re pr�cis d'un fichier, mais nous avons d�cid� au final de recr�er un fichier
txt et de le copier au caract�re pr�s.

	Notre diagramme de classe a beaucoup �t� modifi� suite � l'utilisation des .txt, mais nous sommes fiers du r�sultat obtenu.
	



Ce projet a �t� r�alis� sous CodeBlocks 13.12