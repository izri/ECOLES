SAADA Yoav
COHEN-SOLAL Samuel
ELAYATHAMBY Ajanthan

Explication du diagramme :

Dans notre diagramme nous avons la Classe Client qui est notre classe m�re. La Classe Plat h�rite dela Classe Client, ce qui nous permet     en C++ de se d�placer suivant les fichiers Plat.h et Client.h .
Ensuite nous avons r�alsi� plusieurs fichiers pour chacune des Classes suivantes : Pizza, Plat veget�rien, Plat du jour, Dessert et Boisson
Elles h�rites tous de la Classe Plat et donc, elles sont reli�es � la Classe Client.

Comme la classe Client poss�de les M�thodes suivantes : aff(), Client (string nom, unsigned int table) et commande (string nom, prix)
Nous avons fait correspondre dans le fichier main.cpp � chaque produits la possibilit� de commander une pizza, un plat du jour, un plat v�g�tarien, un dessert ou une boisson avec un prix pr�d�fini dans le menu, par le biais de la m�thode commande.


En ce qui concerne le programme, dans le cadre de notre TP, nous avions comme objectif de concevoir un programme en langage C++ permettant d'effectuer plusieurs t�ches. 
Nous avons donc r�alis� ce programme qui est capable d'afficher un menu de tous les plats possible de notre carte. Il compote les diff�rentes pizza, le plat du jour, les plats v�g�tariens, les desserts ainsi que les boissons. Apr�s avoir choisit un des �l�ments du menu, le programme va demander au client si il a fini sa commande. Si c'est le cas alors il affichera le prix du produit unique choisit par le client, sinon il affiche � nouveau le menu pour que le client poursuive sa commande puis il lui sera demander si sa commande est fini. Si c'est le cas alors le programme calculera la somme total des produits command� par le client et l'affichera, afin que celui-ci voit ce qu'il doit payer.
