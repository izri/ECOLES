		 ___________________________________________________________________________________
		|                                                                                   |
		|                                                                                   |
		|  Programme Gestion Restaurant : Sazadaly Maxime et Clémence Viard - 2ème année    |
		|                                                                                   |
		|		                   Classe 2A2                                       |
		|                                                                                   |
		|___________________________________________________________________________________|
		



						/!\ IMPORTANT /!\

Ce programme n'a été testé que sous Windows. Néanmoins, aucune fonction système n'ont été appelées. Il ne devrait a priori ne pas avoir de soucis.

La ligne de compilation est : g++ -Wall commande.c commande.h main.h -fexceptions -std=c++11 -o commande.exe

Nous conseillons néanmoins d'utiliser CodeBlocks (que nous avons utilisé). Si à la compilation une erreur apparaît,
allez dans Project -> Build Options et cochez "Have g++ follow the C++11 ISO C++ language standard [-std=c++11]"

						/!\ IMPORTANT /!\


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



					// Fonctionnalités du programme \\


	- Gestion des commandes (facturation, datation, application de réduction, etc.) selon le client
	- Gestion des clients (mise en mémoire de la liste des clients et de leurs venues)
	- Gestion de la fidelité (réduction de 20% toute les 10 commandes, parce qu'on est très gentil chez nous)
	- Base de données externe (.txt regroupant des informations, permettant une fermeture du programme et une sauvegarde des données)
	- Possibilité d'effacer la base de données de commandes, mais maintient permanent de la liste des clients, car chez nous, nos clients, on les aime
	- Analyse des commandes : calcul du nombre de plats commandés.


					
					   // Bilan de la réalisation \\

	Nous avons réalisé ce premier programme en C++ en ayant des ambitions un peu trop grande. En effet, nous nous sommes
un peu perdu dans la gestion des données. Premièrement, voulant passer par des tableaux, nous avons perdu du temps. En effet, aucune sauvegarde n'était possible.
	Néanmoins, dès lors que nous avons eu l'idée des fichiers .txt, notre idée s'est éclaircie : nous n'avions plus besoin de la classe Historique, que nous
avons écartée. Cet axe de travail s'est révélé très intéressant, bien qu'il a fallu apprendre à communiquer avec nos amis les .txt
	Beaucoup de temps a été passé à chercher comment modifier un caractère précis d'un fichier, mais nous avons décidé au final de recréer un fichier
txt et de le copier au caractère près.

	Notre diagramme de classe a beaucoup été modifié suite à l'utilisation des .txt, mais nous sommes fiers du résultat obtenu.
	



Ce projet a été réalisé sous CodeBlocks 13.12