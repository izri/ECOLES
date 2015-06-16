Le programme se porte sur la gestion d'un restaurant en C++.
Notre programme dispose de  classes : Client, Product et Command
Le programme demande à 3 clients de rentrer leur nom et leur prénom
Ce "client" est alors ajouté à la base de donnée de la classe Client
L'ensemble des produits est alors déclaré dans la base de donnée de la classe Product.
Aprés que le client ait donné son nom et son prénom un menu s'affiche alors à l'écran.
Le client a le choix entre 9 types de produits différents.
Une fois que le client a selectionné son produit un récapitulatif de sa commande s'affiche
alors à l'écran ainsi que le prix de cette derniére.
Le prix grâce à la classe Product qui renvoie le prix du produit.
A la fin le programme affiche le total de la commande des 3 clients.

 Le probléme que nous avons rencontré est qu'on ne peut pas déclarer plusieurs fois le même client
 dans une classe même avec des paramétres différents.
par exemple on ne peut pas utiliser 2 fois cette ligne en changeant le produit : 
 Command jane(Jane, fruit);
 Command jane(Jane, chocolat);