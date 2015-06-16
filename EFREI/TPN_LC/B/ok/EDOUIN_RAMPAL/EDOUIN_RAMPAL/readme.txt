La grammaire doit être indiqué dans le fichier grammaire.txt
Tout les symbole doivent être séparé par un espace
Dans le cas d'un symbole dérivant le mot vide, juste mettre un ESPACE derrière le non-terminal

Le mot testé est modifiable dans le main.cpp et est suivi d'un dollars
Il est stocké dans un vector.
Le main est actuellement configuré pour lire le mot : aababb.

Nous avons arbitrairement fait le choix d'utiliser en priorité les shifts.

ATTENTION
Les first et follow ne fonctionnant pas totalement, les follow nécessaire ont été intégré "en dur dans le code".
Ils sont modifiables dans le fichier tableAnalyse.cpp à partir de la ligne 133.