AVANCEMENT DU PROJET
	Nous avons dans ce projet impl�ment� le chargement en m�moire d'une grammaire stock�e sous forme de fichier texte ainsi que son exportation sous le nom de [nomInitial]_modified.txt
	Le programme est �g�lement capable de d�tecter une r�cursivit� gauche directe et de la lever.
	Enfin, le programme d�tecte si une grammaire est factorisable.


AVERTISSEMENT
	Nous avons �tabli une nomenclature dans la structuration des fichiers de grammaire afin d'assurer le fonctionnement du programme.
	Le programme diff�rencie les �tats terminaux des non-terminaux selon leur type (MAJUSCULE ou minuscule).
	Ainsi, un caract�re en majuscule sera consid�r� comme non-terminal et un caract�re en minuscule sera consid�r� comme terminal.
	
	
NOMENCLATURE DES FICHIERS DE TEST:

	Pour le fichier suivant:
	
		AcB
		BA
		Bc
		
	Le programme interpr�tera :
	
		A -> cB
		B -> A
		B -> c
		
	Le premier caract�re d'une ligne est consid�r� comme �tant le sommet et les caract�res suivants, ses transitions.
	Il est imp�ratif de ne pas introduire d'espace � moins qu'il soit un �l�ment de la grammaire.
	Le symbole caract�re vide commun�ment not� par la lettre greque epsilon est isi repr�sent�e par le '~' tilde.