SAADA Yoav
COHEN-SOLAL Samuel
ELAYATHAMBY Ajanthan

Explication du diagramme :

Dans notre diagramme nous avons la Classe Client qui est notre classe mère. La Classe Plat hérite dela Classe Client, ce qui nous permet     en C++ de se déplacer suivant les fichiers Plat.h et Client.h .
Ensuite nous avons réalsié plusieurs fichiers pour chacune des Classes suivantes : Pizza, Plat vegetérien, Plat du jour, Dessert et Boisson
Elles hérites tous de la Classe Plat et donc, elles sont reliées à la Classe Client.

Comme la classe Client possède les Méthodes suivantes : aff(), Client (string nom, unsigned int table) et commande (string nom, prix)
Nous avons fait correspondre dans le fichier main.cpp à chaque produits la possibilité de commander une pizza, un plat du jour, un plat végétarien, un dessert ou une boisson avec un prix prédéfini dans le menu, par le biais de la méthode commande.


En ce qui concerne le programme, dans le cadre de notre TP, nous avions comme objectif de concevoir un programme en langage C++ permettant d'effectuer plusieurs tâches. 
Nous avons donc réalisé ce programme qui est capable d'afficher un menu de tous les plats possible de notre carte. Il compote les différentes pizza, le plat du jour, les plats végétariens, les desserts ainsi que les boissons. Après avoir choisit un des éléments du menu, le programme va demander au client si il a fini sa commande. Si c'est le cas alors il affichera le prix du produit unique choisit par le client, sinon il affiche à nouveau le menu pour que le client poursuive sa commande puis il lui sera demander si sa commande est fini. Si c'est le cas alors le programme calculera la somme total des produits commandé par le client et l'affichera, afin que celui-ci voit ce qu'il doit payer.
