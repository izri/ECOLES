UTILISATION:

	Le programme utilise une base de données: resto.sqlite
	Celle-ci doit se trouver dans le répertoire parent pour que le programme fonctionne.
	Pour l'utiliser, il vous faudra importer la librairie SQLITE JDBC (présente dans l'archive ou trouvable sur internet)
	Attention: la base de données ne doit pas être ouverte avec un logiciel tiers si le programme est en cours d'exécution !

FONCTIONNALITES:
	
	- Interface graphique permettant de créer des commandes, de les visualiser et afficher les 3 produits les plus vendus
	- Charger un client existant dans la base de données
	- Créer un nouveau client et l'enregistrer dans la base de données
	- Création de commandes -> base de données
	- Visualisation des commandes
	- Visualisation de produits

HOW TO INTERFACE GRAPHIQUE:

	Onglet "Nouvelle commande":
	
		Dans un premier temps, sélectionnez un client (créé ou charge le client).
		Une fois le client créé, cliquez sur les produits que vous voulez ajouter à la commande.
		Il suffit de cliquer plusieurs fois sur un produit pour incrémenter sa quantité.
		Pour enregistrer la commande (sauvegarde dans la base de données), cliquez sur Enregistrer.
		Pour annuler la commande en cours, cliquez sur Annuler. 
	
	Onglet "Info commande":
	
		Renseignez le nom d'un client pour afficher sa dernière commande
	
	Onglet "Meilleurs ventes":
	
		Affiche les 3 produits les plus vendus.
