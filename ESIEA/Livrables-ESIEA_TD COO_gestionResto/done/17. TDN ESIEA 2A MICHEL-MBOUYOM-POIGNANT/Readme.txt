Le programme se porte sur la gestion d'un restaurant en C++.
Notre programme dispose de  classes : Client, Product et Command
Le programme demande � 3 clients de rentrer leur nom et leur pr�nom
Ce "client" est alors ajout� � la base de donn�e de la classe Client
L'ensemble des produits est alors d�clar� dans la base de donn�e de la classe Product.
Apr�s que le client ait donn� son nom et son pr�nom un menu s'affiche alors � l'�cran.
Le client a le choix entre 9 types de produits diff�rents.
Une fois que le client a selectionn� son produit un r�capitulatif de sa commande s'affiche
alors � l'�cran ainsi que le prix de cette derni�re.
Le prix gr�ce � la classe Product qui renvoie le prix du produit.
A la fin le programme affiche le total de la commande des 3 clients.

 Le probl�me que nous avons rencontr� est qu'on ne peut pas d�clarer plusieurs fois le m�me client
 dans une classe m�me avec des param�tres diff�rents.
par exemple on ne peut pas utiliser 2 fois cette ligne en changeant le produit : 
 Command jane(Jane, fruit);
 Command jane(Jane, chocolat);