Ce programme a été réalisé en se servant du modèle donné sur le Drive par les professeurs d'informatique. 
Il a fallu un long temps d'adaption au travail de la conception orientée objet en C++.
C'est pourquoi, bien que la plupart des parties importantes du diagramme ont été réalisé, tout n'a pas été finalisé.
Ce programme a repris la distribution en fichiers .hpp et .cpp mais il a été ajouté plusieurs fonctions et aussi critères.
Par exemple un client a en plus du nom et du genre, un âge, un nombre de venues dans le restaurant, la valeur totale de ses dépenses ainsi qu'un identifiant pour pouvoir
le reconnaître dans un historique des clients.
De plus, un produit a un nombre, car il peut être commandé en plusieurs exemplaires, ainsi qu'une marge. Le prix et marge du produit changent en fonction
du nombre de produits vendus à la commande.
On a essayé par la suite de définir ce qu'était un "meilleur client" en se basant sur une valeur minimum de dépenses. 
Cette opération est effectuée afin de réduire l'historique des clients à un fichier meilleur client (dans le code sous forme de liste).

Le fichier principal est "resto.cpp".