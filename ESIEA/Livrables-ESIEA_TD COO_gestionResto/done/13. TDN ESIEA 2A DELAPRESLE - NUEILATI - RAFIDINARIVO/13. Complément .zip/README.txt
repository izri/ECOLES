Nous avons donc réaliser comme le sujet du TD l'exige, un programme de gestion de restaurant.

Nous avons en premier lieu crée l'interface de notre restaurant dans le main , on a utiliser pour cela un switch
dans lequel nous faisions apparaitre les différents choix du client au cours de sa commande. Il a alors la 
possibilité de commander une série de plats de différents types au nombre qu'il désire. Nous avons donc fait pour 
cela une boucle "do while" qui continue à se répéter tant que le client désire prendre un plat. Bien sûr nous avons initialisé un nouveau client grâce à la classe Commande et le résultat final du programme est visible par le biais de la méthode "afficher" méthode de la classe Commande.

Le Client à le choix entre 5 catégories de plats, (Plat du jour), (Plat Végétarien), (Pizza), (Boissons), (Dessert), qui contiennent
chacun 4 choix différents.

Nos classes principales sont la classe Commande  et Plat. La classe Commande mémorise le nom du client mais va surtout faire appel à la classe Plat pour faire intervenir le nom et le prix de chaque plat mais surtout pour additionner le prix de chaque plat (grâce à l'accesseur getPrice). Chaque plat hérite de la classe Plat car selon la règle "il y a héritage quand on peut dire: "A est un B". 
Pour avoir un code plus modulaire et éxécutable,nous avons séparé nos attributs et leurs prototypes en plusieurs
fichier.h , et les méthodes et donc le code de nos fonctions dans des fichiers.cpp. Nous avons préféré mettre la directive using namespace std; dans les fichiers .cpp pour éviter les mauvaises surprises.

Pour le constructeur, nous avons omis le constructeur par défaut et nous avons choisi de créer un constructeur avec (ici pour chaque plat) comme paramètres le nom et le prix. 

Nous avonc alors implémenté dans notre main les différentes bibliothèques associées à nos fichiers crées et nous
avons appelé les fonctions correspondantes.

Finalement nous obtenons bien un programme qui gère les commandes d'un restaurant.
