La grammaire doit �tre indiqu� dans le fichier grammaire.txt
Tout les symbole doivent �tre s�par� par un espace
Dans le cas d'un symbole d�rivant le mot vide, juste mettre un ESPACE derri�re le non-terminal

Le mot test� est modifiable dans le main.cpp et est suivi d'un dollars
Il est stock� dans un vector.
Le main est actuellement configur� pour lire le mot : aababb.

Nous avons arbitrairement fait le choix d'utiliser en priorit� les shifts.

ATTENTION
Les first et follow ne fonctionnant pas totalement, les follow n�cessaire ont �t� int�gr� "en dur dans le code".
Ils sont modifiables dans le fichier tableAnalyse.cpp � partir de la ligne 133.