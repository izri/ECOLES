Groupe de Damase Aymeric, Rajaona Daka Timothé et Rondot Romain.

Programme à compiler et exécuter sur un terminal linux, car utilisation de la commande clear grâce à system
("clear")
Compilation grâce à un Makefile:
make
Exécution automatique avec le fichier test:
./TD_Restaurant < test

Exécution manuelle possible.

Fonctionnement du programme :
Entrer le prénom puis nom du client, suivre les instructions du menu pour faire sa commande.
L'accès à l'historique se fait par l'espace administrateur en tapant le prénom "admin" et le nom "admin", suivre
Les instructions du menu administrateur pour naviguer dedans.
L'arrêt du programme se fait par l'entrée du prénom "shutdown" et du nom "shutdown"

Les taches effectuées :
-ajout de client ou l'incrémentation de son nombre de visite si déjà existant.
-prise de commande.
-historique client (implémentation, affichage et top 3)
-surcharge d'opérateur << pour afficher le contenu d'une classe (nom et prénom pour la classe Client, nom et prix
pour classe produit) la surcharge d'opérateurs << n'a pas été faite pour la classe commande, car nous ne sommes pas
parvenus à faire un to_string() pour avoir le contenu affichable dans une string du fait que les produits de notre commande se trouve dans un vector.
-séparation des fichiers en fonction des classes
-héritage des produits selon leur catégorie (pizza, dessert, boisson...)
-makefile
-interface simple d'utilisation

Il manque la partie historique des produits , gestion des stocks, réduction fidélité.