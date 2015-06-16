  _____     ___            _  _             _ 		 ,,
 |_   _|   | _ \    o O O | \| |    ___    | |_     ___
   | |     |  _/   o      | .` |   / _ \   |  _|   / -_)
  _|_|_   _|_|_   TS__[O] |_|\_|   \___/   _\__|   \___|
_|"""""|_| """ | {======|_|"""""|_|"""""|_|"""""|_|"""""|
"`-0-0-'"`-0-0-'./o--000'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'
   ___     ___     ___     ___     ___    _  _
  /   \   |   \   | _ \   |_ _|   | __|  | \| |
  | - |   | |) |  |   /    | |    | _|   | .` |
  |_|_|   |___/   |_|_\   |___|   |___|  |_|\_|
_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|
"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'
   _       ___     ___    _  _     ___     ___     ___
  | |     |_ _|   | __|  | \| |   /   \   | _ \   |   \
  | |__    | |    | _|   | .` |   | - |   |   /   | |) |
  |____|  |___|   |___|  |_|\_|   |_|_|   |_|_\   |___/
_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|
"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'
   ___      ___    ___     ___
  / __|    | _ \  |_ _|   | _ \
  \__ \    |  _/   | |    |   /
  |___/   _|_|_   |___|   |_|_\
_|"""""|_| """ |_|"""""|_|"""""|
"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'

Compile avec la commande `g++ *.cpp`

Notre système enregistre tous les clients ayant commandé quelque chose de le restaurant, enregistre ce
qu'ils commandent et quand, note l'instant où la commande à été enregistré puis est capable de diffuser
divers statistiques sur ce qui se vend le mieux, qui achète le plus etc...
Par défaut, les statistiques sont générés pour les 3 premiers plats ou clients. Toutefois, changer cette
constante est trivial, puisqu'il suffit de changer le nombre définissant `TOP_CLIENTS` ou `TOP_MEALS`
dans `resto.cpp`.

Notre projet est constitué de 5 classes, ce qui est légèrement moins qu'initialement prévu pour les
raisons suivantes:

	- Nous avons conçu le système de sauvegarde et de chargement de l'application, reposant sur la
		sérialisation du contenu de l'historique dans un fichier JSON. Le système reposait sur une
		classe `Stock` qui autorisait ou non les commandes en fonction de si le stock était disponible.
		Les tests se sont révélés concluant mais le code fut retiré au dernier moment en raison
		de l'absence de système natif en C++ pour traiter les fichier JSON. Nous utilisions jusqu'à ce
		moment une librairie mais ne pouvant garantir une compilation rapide et simple, le système sur
		lequel le projet final sera compilé étant inconnu, nous avons décidé de retirer ce point mineur.
		Le système permettait alors la gestion dynamique et concurante du stock et assez facilement
		de l'interfacer avec le réseau.

	- Nous avons décidé d'utiliser un seul objet `Plat` pour définir les plats au lieu de l'approche
		consistant à créer de nombreux objets héritant de l'objet Plat en raison de la simplicité de
		l'objet en lui même et de la complexité de créer un constructeur polymorphe, pouvant renvoyer
		un objet statiquement alloué en fonction du code entré. L'objet consiste donc simplement d'une
		coquille vide et d'un profil dépendant du code d'initialisation. Utiliser des enfants de `Plat`
		aurait été faisable en allouant dynamiquement les instances mais aurait constitué simplement de
		profils préinstallés, et n'était donc pas techniquement pertinent (la libération de la mémoire
		étant alors à notre charge sans gain significatif)