<?php //Début du php - Ken Moussat - ESILV grE

//Exercice 2: Création d'une classe Vehicule

// classe Vehicule
class Vehicule
{
	
	//attributs de description
	var $marque;
	var $couleur;
	var $km;
	var $carburant;
	


	function __construct()
	{ //constructeur
		$num=func_num_args();
		$args=func_get_args();

			switch ($num) 
			{

			 //constructeur par défaut
			case 0:
				$this->marque="";
				$this->couleur="";
				$this->km="";
				$this->carburant="";
				break;

			case 5:
				$this->marque=$args[0];
				$this->couleur=$args[1];
				$this->km=$args[2];
				$this->carburant=$args[3];
				$this->roule=$args[4];
				break;

			default:
				echo"Erreur: nombre d'arguments incorrect";
				break;
		}
	}

    // méthode arret permettant d'indiquer que le véhicule est à l'arrêt
	function arret(){
		//le véhicule est à l'arrêt
		$this->roule=0;
	}//Fin de la méthode
	

	// méthode roule permettant d'incrémenter le nombre de kilomètres et de réduire la quantité de carburant
	function roule($kmroule,$litreau100){
		//changement de rapport du litre au 100 à litre au km
		$litreaukm = $litreau100 / 100;
		// carburant utilisé en fonction des km roulés par la dépense de carburant au km
		$carbu_used=$kmroule*$litreaukm;
		// le véhicule roule
		$this->roule=1;
		// variable des km roulés s'ajoute aux km de base
		$this->km=$this->km+=$kmroule;
		// incrémentation des kms
		$this->km++;
		// Quantité de carburant restant
		$this->carburant=$this->carburant-=$carbu_used;
	}//Fin de la méthode
	

	// méthode affichage pour les informations d'un véhicule
	function Affichage(){
		// Affichage de la marque, de la couleur, du kilométrage et du carburant restant
		echo"<font color=blue>Marque du véhicule : ".$this->marque."<br>";
		echo"Couleur du véhicule : ".$this->couleur."<br>";
		echo"Kilométrage du véhicule : ".$this->km."<br>";
	/*si le carburant restant est au-dessus de 20 litres
	il affiche le volume restant.
	si le carburant restant est au-dessus de 0 litre et en-dessous de 20 litres
	il affiche un message d'alerte.
	si le carburant restant est égal ou en-dessous de 0 litre
	il affiche un message indiquant qu'il n'y a plus de carburant*/
	 
				if ($this->carburant > 20) {
    echo "Quantité de carburant: ".$this->carburant."</font><br>";
} elseif (($this->carburant < 20) && ($this->carburant > 0)) {
    echo "Quantité de carburant: </font><strong><font color=orange>Attention véhicule n'a plus que ".$this->carburant." litres de carburant!</strong></font><br>";
}  elseif ($this->carburant <= 0) {
    echo "Quantité de carburant:  </font><strong><font color=black>Le véhicule n'a plus de carburant!</strong></font><br>";
}  else {
    echo"Quantité de carburant : </font><strong><font color=black>Le véhicule n'a plus de carburant!</strong></font><br>";
}
		
	}//Fin de la méthode
	

} //fin de la classe Vehicule

echo"<h3><u>Implémentation de l'exercice 2</u></h3>";

// Début de l'implémentation
$voiture = new Vehicule("Peugeot","Gris",20000,60,0);
$voiture->roule(200,1);
$voiture->arret();
$voiture->Affichage();
// Fin de l'implémentation

// Facilite l'affichage entre les implémentations
echo"<br>";
echo"<br>";
echo"<br>";
//fin

/*********************************************************************
**********************************************************************/

//Exercice 3: Création de deux classes: Voiture et Train 

// classe Voiture
class Voiture extends Vehicule{

	//attributs de description
	var $typeCarburant;
	var $nbPorte;

	function __construct()
	{//constructeur
		$num=func_num_args();
		$args=func_get_args();
						
		switch ($num) {
			
			
			
			//constructeur par défaut
			case 0:
				$this->marque="";
				$this->couleur="";
				$this->km="";
				$this->carburant="";
				$this->typeCarburant="";
				$this->nbPorte="";
				break;
			
			case 5:
				$this->marque=$args[0];
				$this->couleur=$args[1];
				$this->km=$args[2];
				$this->carburant=$args[3];
				$this->roule=$args[4];
				break;

			case 7:
				$this->marque=$args[0];
				$this->couleur=$args[1];
				$this->km=$args[2];
				$this->carburant=$args[3];
				$this->roule=$args[4];
				$this->typeCarburant=$args[5];
				$this->nbPorte=$args[6];
				break;

			default:
				echo"Erreur: nombre d'arguments incorrect";
				break;
		}

	}
			
			// méthode permettant d'afficher le type de carburant et le nombre de portes du véhicule
			function Affichage(){
				parent::Affichage();
		echo"<font color=red>Type de carburant : ".$this->typeCarburant."<br>";
		echo"Nombre de portes : ".$this->nbPorte."</font><br>";
	}//Fin de la méthode
	
}//Fin de la classe Voiture 



//*************************************************************************


// classe Train
class Train extends Vehicule{

    //attributs de description
	var $type;
	var $nbwagon;



	function __construct()
	{
		//constructeur

		$num=func_num_args();
		$args=func_get_args();

		switch ($num) 
		{
			
			
			//constructeur par défaut
			case 0:
				$this->marque="";
				$this->couleur="";
				$this->km="";
				$this->carburant="";
				$this->type="";
				$this->nbwagon="";
				break;
			
			case 5:
				$this->marque=$args[0];
				$this->couleur=$args[1];
				$this->km=$args[2];
				$this->carburant=$args[3];
				$this->roule=$args[4];
				break;

			case 7:
				$this->marque=$args[0];
				$this->couleur=$args[1];
				$this->km=$args[2];
				$this->carburant=$args[3];
				$this->roule=$args[4];
				$this->type=$args[5];
				$this->nbwagon=$args[6];
				break;

			default:
				echo"Erreur: nombre d'arguments incorrect<br>";
				break;
		}

	}

	       // méthode permettant d'afficher le type de train et le nombre de wagons composant le train
			function Affichage(){
			Vehicule::Affichage();
		echo"<font color=green>Type de train : ".$this->type."<br>";
		echo"Nombre de wagons : ".$this->nbwagon."</font><br>";
		//Fin de la méthode
		
	}
}//Fin de la classe Train



// Implémentation de l'exercice 3
echo"<h3><u>Implémentation de l'exercice 3</u></h3>";

echo"<h4>Voiture</h4>";

$V1 = new Voiture("Bugatti Veyron","Bleu, Noir",80000,40,0,"Essence",2);
$V1->roule(605,3.6);
$V1->Affichage();
echo"<h4>Train</h4>";

$T1 = new Train("RER A","Rouge, Bleu, Blanc",55000,1500,0,"Electrique",25);
$T1->roule(3000,0.4);
$T1->Affichage();

/*********************************************************************
**********************************************************************/

//Exercice 4
/* Création de différentes instances de classes et sauvegarder dans un tableau de 
 véhicules. Afin de manipuler les constructeurs de chaque classe à la création
 des objets. */
 
 
echo"<br>";
echo"<br>";
echo"<br>";
echo"<br>";
echo"<h3><u>Implémentation de l'exercice 4</u></h3>";


// Nouveaux véhicules
$V2 = new Voiture("Porsche 911 Carrera S","Gris métalisé",200000,30,0,"Diesel",2);
$V2->roule(615,5.8);

$T2 = new Train("Tram 1","Orange et jaune",900000,70000,0,"Electrique",10);
$T2->roule(3000,0.4);
// fin déclaration nouveaux véhicules

// déclaration du tableau de véhicule
$tableau= array(1=>$V2,2=>$T2);

//boucle for 
for ($i=1; $i < 2; $i++) { 
echo"<h4>Voiture</h4>";
	echo $tableau[1]->Affichage();
	echo"<br>";
	echo"<h4>Train</h4>";
	echo $tableau[2]->Affichage();
	echo"<br>";
}//fin boucle for

//Fin du php
?> 