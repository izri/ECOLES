Groupe de Damase Aymeric, Rajaona Daka Timoth� et Rondot Romain.

Programme � compiler et ex�cuter sur un terminal linux, car utilisation de la commande clear gr�ce � system
("clear")
Compilation gr�ce � un Makefile:
make
Ex�cution automatique avec le fichier test:
./TD_Restaurant < test

Ex�cution manuelle possible.

Fonctionnement du programme :
Entrer le pr�nom puis nom du client, suivre les instructions du menu pour faire sa commande.
L'acc�s � l'historique se fait par l'espace administrateur en tapant le pr�nom "admin" et le nom "admin", suivre
Les instructions du menu administrateur pour naviguer dedans.
L'arr�t du programme se fait par l'entr�e du pr�nom "shutdown" et du nom "shutdown"

Les taches effectu�es :
-ajout de client ou l'incr�mentation de son nombre de visite si d�j� existant.
-prise de commande.
-historique client (impl�mentation, affichage et top 3)
-surcharge d'op�rateur << pour afficher le contenu d'une classe (nom et pr�nom pour la classe Client, nom et prix
pour classe produit) la surcharge d'op�rateurs << n'a pas �t� faite pour la classe commande, car nous ne sommes pas
parvenus � faire un to_string() pour avoir le contenu affichable dans une string du fait que les produits de notre commande se trouve dans un vector.
-s�paration des fichiers en fonction des classes
-h�ritage des produits selon leur cat�gorie (pizza, dessert, boisson...)
-makefile
-interface simple d'utilisation

Il manque la partie historique des produits , gestion des stocks, r�duction fid�lit�.