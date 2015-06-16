Projet ManaResto
BEAULIEU - BOUNIOL - GAUTHIER

Compte tenu de notre cahier des charges initial, et du d�lai de d�veloppement, nous sommes
plut�t satisfaits de notre r�sultat; en effet, notre programme dispose d�une interface graphique 
r�alis�e � l�aide du framework Qt facilitant son acc�s pour un utilisateur.

Au niveau du back-office, notre programme remplit la majorit� des fonctionnalit�s que nous avions
pr�vues. Il permet notamment de chercher dans la base de donn�es si le client existe ou non
(en fonction de son nom/pr�nom). S�il ne s�y trouve pas, il cr�e un nouveau fichier pour ce
nouveau client. S�il existe, il proc�de directement � la nouvelle commande. Nous pr�cisons que les
champs de saisies sont prot�g�s contre les caract�res malicieux et non appropri�s aux champs en question.
Une fois la commande pass�e, le fichier d�historique des commandes est modifi� pour faire apparaitre
en son sein la nouvelle. Le fichier d�historique permet de retrouver qui a achet� quoi et combien dans le temps.
La commande elle, est �galement stock� dans un fichier qui lui est propre. Fichier dans lequel se trouve toutes
les informations relatives � cette commande, � savoir qu�est-ce qui a �t� command�, et pour quel prix au total.

En revanche, nous n�avons pas encore pu impl�menter, ou du moins utiliser certains attributs (tel le volume
pour la boisson). N�anmoins, si le projet �tait prolong� pour une version 1.1, il ne serait pas compliqu� 
d�impl�menter de telles fonctionnalit�s.


Pour consulter la documentation ou le git du projet (rendu public 1 jour apr�s la deadline):
http://www.manarestodoc.tk
https://github.com/Squadella/ManaResto


/!\ POUR LA COMPILATION / CR�ATION D�UN EX�CUTABLE /!\

La compilation s�effectue sur un syst�me Unix (Linux ou MAC). Nous n�avons pas encore impl�ment� de script de
compilation pour Windows.


Vous devez avoir make et qmake. Pour cela, ex�cutez dans un terminal:

sudo apt-get update && sudo apt-get install qt5-qmake make g++ qt5-default -y


ensuite:

cd ../build


et endin:

./ManaResto
