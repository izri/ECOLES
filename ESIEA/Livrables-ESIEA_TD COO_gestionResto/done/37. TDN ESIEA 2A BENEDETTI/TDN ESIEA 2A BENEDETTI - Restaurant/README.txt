██████╗ ███████╗███████╗████████╗ █████╗ ██╗   ██╗██████╗  █████╗ ███╗   ██╗████████╗
██╔══██╗██╔════╝██╔════╝╚══██╔══╝██╔══██╗██║   ██║██╔══██╗██╔══██╗████╗  ██║╚══██╔══╝
██████╔╝█████╗  ███████╗   ██║   ███████║██║   ██║██████╔╝███████║██╔██╗ ██║   ██║   
██╔══██╗██╔══╝  ╚════██║   ██║   ██╔══██║██║   ██║██╔══██╗██╔══██║██║╚██╗██║   ██║   
██║  ██║███████╗███████║   ██║   ██║  ██║╚██████╔╝██║  ██║██║  ██║██║ ╚████║   ██║   
╚═╝  ╚═╝╚══════╝╚══════╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝   ╚═╝   

Projet de POO : Restaurant
Léonard Benedetti

1. Compilation

  1) En utilisant make :
  Dans le répertoire ./src, exécuter la commande “make” (un fichier Makefile est présent)
  
  2) En utilisant directement g++ :
  Dans le répertoire ./src, exécuter la commande “g++ -o Restaurant -O2 -Wall -W -I. Products/*.cpp *.cpp”
  
  
2. Analyse technique

  Le programme implémente à peu prêt l’ensemble des fonctionnalités techniques décrites dans le cahier
  des charges. Certaines – qui ne sont que cosmétiques – ne sont pas présentes pour éviter d’alourdir le
  code mais l’ajout de ces dernières est trivial.
  
  La gestion des différents types de plat se fait en utilisant le concept d’héritage ; si l’objectif avait
  été de réaliser un programme destiné à la production, il eût sûrement été plus judicieux d’utiliser des
  classes qui représent le type du produit. Néanmoins, puisque le but était de faire intervenir cette notion
  nous avons conservé l’utilisation de classes dérivées.
  
  
3. Démonstration du programme

  Le programme “Restaurant” fait une démonstration des fonctionnalités disponibles. Par ailleurs le code
  de cette démonstration (disponible dans le fichier “main.cpp”) est commenté de façon à suivre pas à pas
  les étapes. L’utilisation des différentes classes est relativement aisé, les noms de méthodes ayant été
  choisis pour que l’interaction soit la plus intuitive possible.