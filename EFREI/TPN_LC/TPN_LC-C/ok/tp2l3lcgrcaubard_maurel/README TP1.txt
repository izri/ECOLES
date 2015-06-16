AVANCEMENT DU PROJET
	Nous avons dans ce projet implémenté le chargement en mÈmoire d'une grammaire stockÈe sous forme de fichier texte ainsi que son exportation sous le nom de [nomInitial]_modified.txt
	Le programme est ÈgÈlement capable de dÈtecter une rÈcursivitÈ gauche directe et de la lever.
	Enfin, le programme dÈtecte si une grammaire est factorisable.


AVERTISSEMENT
	Nous avons établi une nomenclature dans la structuration des fichiers de grammaire afin d'assurer le fonctionnement du programme.
	Le programme différencie les états terminaux des non-terminaux selon leur type (MAJUSCULE ou minuscule).
	Ainsi, un caractère en majuscule sera considéré comme non-terminal et un caractère en minuscule sera considéré comme terminal.
	
	
NOMENCLATURE DES FICHIERS DE TEST:

	Pour le fichier suivant:
	
		AcB
		BA
		Bc
		
	Le programme interprètera :
	
		A -> cB
		B -> A
		B -> c
		
	Le premier caractère d'une ligne est considéré comme étant le sommet et les caractères suivants, ses transitions.
	Il est impératif de ne pas introduire d'espace à moins qu'il soit un élément de la grammaire.
	Le symbole caractËre vide communément noté par la lettre greque epsilon est isi représentée par le '~' tilde.