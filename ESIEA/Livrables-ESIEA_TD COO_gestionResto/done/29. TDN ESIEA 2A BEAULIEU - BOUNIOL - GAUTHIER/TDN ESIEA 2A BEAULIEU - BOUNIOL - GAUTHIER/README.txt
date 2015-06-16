Projet ManaResto
BEAULIEU - BOUNIOL - GAUTHIER

Compte tenu de notre cahier des charges initial, et du délai de développement, nous sommes
plutôt satisfaits de notre résultat; en effet, notre programme dispose d’une interface graphique 
réalisée à l’aide du framework Qt facilitant son accès pour un utilisateur.

Au niveau du back-office, notre programme remplit la majorité des fonctionnalités que nous avions
prévues. Il permet notamment de chercher dans la base de données si le client existe ou non
(en fonction de son nom/prénom). S’il ne s’y trouve pas, il crée un nouveau fichier pour ce
nouveau client. S’il existe, il procède directement à la nouvelle commande. Nous précisons que les
champs de saisies sont protégés contre les caractères malicieux et non appropriés aux champs en question.
Une fois la commande passée, le fichier d’historique des commandes est modifié pour faire apparaitre
en son sein la nouvelle. Le fichier d’historique permet de retrouver qui a acheté quoi et combien dans le temps.
La commande elle, est également stocké dans un fichier qui lui est propre. Fichier dans lequel se trouve toutes
les informations relatives à cette commande, à savoir qu’est-ce qui a été commandé, et pour quel prix au total.

En revanche, nous n’avons pas encore pu implémenter, ou du moins utiliser certains attributs (tel le volume
pour la boisson). Néanmoins, si le projet était prolongé pour une version 1.1, il ne serait pas compliqué 
d’implémenter de telles fonctionnalités.


Pour consulter la documentation ou le git du projet (rendu public 1 jour après la deadline):
http://www.manarestodoc.tk
https://github.com/Squadella/ManaResto


/!\ POUR LA COMPILATION / CRÉATION D’UN EXÉCUTABLE /!\

La compilation s’effectue sur un système Unix (Linux ou MAC). Nous n’avons pas encore implémenté de script de
compilation pour Windows.


Vous devez avoir make et qmake. Pour cela, exécutez dans un terminal:

sudo apt-get update && sudo apt-get install qt5-qmake make g++ qt5-default -y


ensuite:

cd ../build


et endin:

./ManaResto
