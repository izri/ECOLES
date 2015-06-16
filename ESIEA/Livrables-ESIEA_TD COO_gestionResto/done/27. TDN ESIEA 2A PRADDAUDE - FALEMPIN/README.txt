Le programme possède différentes fonctionnalitées permettant de :
 - ajouter un plat
 - supprimer un plat
 - lister tous les plats
  > avec pour chaque type de plat sa propre composition spécifique
Pour les commandes il est possible de :
 - ajouter des produits dans une commande
 - avoir le prix total de la commande

Cependant de nombreuses fonctions possèdent des bugs, notamment des crash dont nous ne savons
pas d'où ils viennent (après to_string, le debug dit qu'il arrive à effectuer to_string, mais
il crash juste après alors qu'il n'y a plus de code à lire à part system("pause"); ...)