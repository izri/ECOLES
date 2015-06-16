Etudiant : ROPELEWSKI Maxime
Classe : 2A1

Pour ce système de gestion des commandes d'un restaurant, j'ai utilisé le langage Java couplé avec une base de données SQLite. Dans un premier temps, le programme permet de récupérer la commande d'un client, puis il stocke les informations importantes dans la base de données. J'ai défini 2 tables : la première "Commandes" qui sert à stocker la date, le prix et les différents plats de la commande. Et la deuxième table "Client" qui nous permet de gérer les différentes informations sur nos clients comme leur adresse et leurs précédentes commandes.

[x] Prendre une commande
	[x] Le client est nouveau
	[x] Le client existe
[x] Afficher la dernière commande
[x] Historique des 5 dernières commandes
[x] Historique des 5 meilleures commandes
[x] Afficher le dernier client enregistré 
[x] Historique des 5 derniers clients
[x] Historique des 5 meilleurs clients
[x] Affichage de toutes les commandes d'un client
[x] Afficher les meilleurs ventes sous forme de classement

La base de données est déjà remplie avec des clients pour faciliter les tests des fonctions listant plusieurs clients.
La libraire JDBC(sqlite-jdbc-3.8.7) a été utilisée pour executer des requêtes sur la base de données.