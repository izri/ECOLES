		Le programme permet:

	-De consulter une base de donn�es existente:
		-L'historique global
		-L'historique d'un client en particulier en rentrant son identifiant
	-D'ajouter des produits � la liste actuelle (leur nom et leur prix)
	-D'ajouter des clients � la base de donn�es
	-De prendre une commande pour un client, compos�e d'un ou plusieurs produits.
	
		Atouts:
		
L'ajout d'�l�ments et la prise en compte de ceux-ci dans les r�cup�rations de donn�es
sont assez simples et facilit�s par des tableaux dynamiques vector<>.
L'historique global se met � jour en fonction de tous les historiques clients.
	
		Les �l�ments manquants par rapport au cahier des charges:

Par rapport � notre objectif initial, les notions de temps et de pourboires n'ont pas �t� mises
en place.
Certaines donn�es des historiques ne se mettent pas � jour, nous avons manqu� de temps
pour pouvoir impl�menter ces fonctions, m�me si celles-ci ne rel�vent pas
d'une difficult� extr�me.

		Principales difficult�s rencontr�es:

	-R�cup�rer toutes les donn�es d'un seul coup d'un fichier et les rendre
exploitables dans le reste du code.
	-Utiliser de mani�re efficace et utile les classes cr��es nottement
les classes repr�sentant les historiques. Les fichiers et vector sont
utilis�s de telle mani�re que ces classes deviennent obsol�tes.