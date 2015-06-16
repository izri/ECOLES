WebResto
Developpé avec le framework PHP Laravel.

Lien de l'instance auto-hebergée : webresto.p1rox.fr

Compte Rendu :
Nous avons réussi à créer une application qui respecte bien ce que nous avions prévu dans le CDC.

Premièrement, l'application nous permet une gestion des tables d'un restaurant.
On peut voir si une table est occupée, le détail des commandes actuelles d'une table en particulier,
le nom du client de la table s'il est référencé. Enfin sur toutes les pages est affiché le nombre de
tables occupées par rapport au nombre total de tables.

Deuxièmement, nous avons implémenté un système de gestion de clients, ceci afin de pouvoir en fidéliser certains. Un formulaire permet la création de la fiche client, on peut y saisir des informations comme :
la société, le nom, le prénom, etc. La vue d'une fiche client liste les différentes informations sur le client, ainsi que ces dernières visites au restaurant avec le détail de chaque commande passée.

Troisièmement, notre application permet la gestion des stocks. Pour cela, un formulaire permet la création d'un produit avec pour informations requises : nom, prix unitaire, quantité. La fiche produit peut-être modifiée si souhaité. Si un produit est en rupture de stock, une alerte s'affichera sur la page d'accueil.

Enfin, notre application lie tous ces éléments à travers les commandes. En effet, un client va vouloir passer commande. Pour accéder au formulaire de création de commande, il faut :
    - avoir au moins une table,
    - avoir au moins une table occupée,
    - avoir au moins un produit.
Le formulaire va demander à quelle table il faut assigner la commande, le produit commandé, la quantité.
En complément une page d'aide est à disposition.

Bien que le résultat soit fonctionnel, il reste néanmoins quelques fonctionnalités que nous n'avons pas eu le temps d'implémenter:
    -les analyses statistiques
    -un système d'authentification: le procpriétaire possèderait un compte administrateur avec l'accès à la gestion des stocks et les statistiques tandis que les employés auraient un accès plus restreint

Installation à l'aide de Docker:
Prérequis: docker-compose, docker
 - Allez dans le dossier docker
 - Pour tout lancer sans rien faire éxecutez : « docker-compose up -d »
 - Pour construire seulement l'image de l'application (sans la base de données).
 Il faut executer : « docker build -t WebResto ».

PS : l'image de l'application ne sert à rien sans la base de données.
