Le programme poss�de diff�rentes fonctionnalit�es permettant de :
 - ajouter un plat
 - supprimer un plat
 - lister tous les plats
  > avec pour chaque type de plat sa propre composition sp�cifique
Pour les commandes il est possible de :
 - ajouter des produits dans une commande
 - avoir le prix total de la commande

Cependant de nombreuses fonctions poss�dent des bugs, notamment des crash dont nous ne savons
pas d'o� ils viennent (apr�s to_string, le debug dit qu'il arrive � effectuer to_string, mais
il crash juste apr�s alors qu'il n'y a plus de code � lire � part system("pause"); ...)