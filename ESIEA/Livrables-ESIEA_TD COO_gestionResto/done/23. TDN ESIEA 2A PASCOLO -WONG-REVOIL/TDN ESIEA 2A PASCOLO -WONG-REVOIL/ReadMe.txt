		Le programme permet:

	-De consulter une base de données existente:
		-L'historique global
		-L'historique d'un client en particulier en rentrant son identifiant
	-D'ajouter des produits à la liste actuelle (leur nom et leur prix)
	-D'ajouter des clients à la base de données
	-De prendre une commande pour un client, composée d'un ou plusieurs produits.
	
		Atouts:
		
L'ajout d'éléments et la prise en compte de ceux-ci dans les récupérations de données
sont assez simples et facilités par des tableaux dynamiques vector<>.
L'historique global se met à jour en fonction de tous les historiques clients.
	
		Les éléments manquants par rapport au cahier des charges:

Par rapport à notre objectif initial, les notions de temps et de pourboires n'ont pas été mises
en place.
Certaines données des historiques ne se mettent pas à jour, nous avons manqué de temps
pour pouvoir implémenter ces fonctions, même si celles-ci ne relèvent pas
d'une difficulté extrême.

		Principales difficultés rencontrées:

	-Récupérer toutes les données d'un seul coup d'un fichier et les rendre
exploitables dans le reste du code.
	-Utiliser de manière efficace et utile les classes créées nottement
les classes représentant les historiques. Les fichiers et vector sont
utilisés de telle manière que ces classes deviennent obsolètes.