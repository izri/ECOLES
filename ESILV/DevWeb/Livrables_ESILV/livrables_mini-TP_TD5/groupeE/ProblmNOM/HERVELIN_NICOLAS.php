<?php

// EXERCICE 2:

class Vehicule {

	var $marque;
	var $modele;
	var $couleur;
	var $puissance;
	var $kms;


	function __construct(){

		$num=func_num_args();
		$args=func_get_args();

		switch($num) {

			case 0:
				$this->marque="";
				$this->modele="";
				$this->couleur="";
				$this->puissance="";
				$this->kms="";
				break;

			case 6:
				$this->marque=$args[0];
				$this->modele=$args[1];
				$this->couleur=$args[2];
				$this->puissance=$args[3];
				$this->kms=$args[4];
				$this->roule=$args[5];
				break;

			default:
				echo"Erreur !!!";
				break;
		}
	}


	function Affichage(){

		echo"Marque du véhicule : ".$this->marque."<br>";
		echo"Modèle du véhicule: ".$this->modele. "<br>";
		echo"Couleur du véhicule : ".$this->couleur."<br>";
		echo"Kilométrage du véhicule : ".$this->kms."<br>";

	/*Indique le nombre de kilomètres restants avant la prochaine révision du véhicule*/
		$rev = 20000;
			if ($this->kms < $rev) {
				echo "<font color = red>Effectuer la révision du véhicule dans: "$rev - $this->kms"kms </font> <br>";
			}
			else {
				do {
					$rev = $rev + 20000;
				while ($this->kms < $rev)
					}
				echo "<font color = red>Effectuer la révision du véhicule dans: "$rev - $this->kms"kms </font> <br>";
			}
	   	
	}


	function arret(){

		$this->roule=0;
	}


	function roule(kmsroules){

		$this->roule=1;
		$this->kms=$this->kms + $kmsroules;
	}
}



// EXERCICE 3:

class Voiture extends Vehicule {

	var $carburant;
	var $nbPortes;

	function __construct() {

		$num=func_num_args();
		$args=func_get_args();
						
		switch ($num) {
		
			case 0:
				$this->marque="";
				$this->modele="";
				$this->couleur="";
				$this->puissance="";
				$this->kms="";
				$this->carburant="";
				$this->nbPortes="";
				break;
			
			case 6:
				$this->marque=$args[0];
				$this->modele=$args[1];
				$this->couleur=$args[2];
				$this->puissance=$args[3];
				$this->kms=$args[4];
				$this->roule=$args[5];
				break;

			case 8:
				$this->marque=$args[0];
				$this->modele=$args[1];
				$this->couleur=$args[2];
				$this->puissance=$args[3];
				$this->kms=$args[4];
				$this->roule=$args[5];
				$this->carburant=$args[6];
				$this->nbPortes=$args[7];
				break;

			default:
				echo"Erreur !!!";
				break;
		}

	}


	function Affichage(){
			parent::Affichage();
		echo"Type de carburant : ".$this->carburant."<br>";
		echo"Nombre de portes : ".$this->nbPortes."<br>";
	}
}


class Train extends Vehicule{

	var $type;
	var $nbwagon;



	function __construct()
	{

		$num=func_num_args();
		$args=func_get_args();

		switch ($num) 
		{
			
			case 0:
				$this->marque="";
				$this->modele="";
				$this->couleur="";
				$this->puissance="";
				$this->kms="";
				$this->type="";
				$this->nbwagon="";
				break;
			
			case 6:
				$this->marque=$args[0];
				$this->modele=$args[1];
				$this->couleur=$args[2];
				$this->puissance=$args[3];
				$this->kms=$args[4];
				$this->roule=$args[5];
				break;

			case 8:
				$this->marque=$args[0];
				$this->modele=$args[1];
				$this->couleur=$args[2];
				$this->puissance=$args[3];
				$this->kms=$args[4];
				$this->roule=$args[5];
				$this->type=$args[6];
				$this->nbwagon=$args[7];
				break;

			default:
				echo"Erreur !!!";
				break;
		}

	}


		function Affichage(){
			Vehicule::Affichage();
		echo"Type de train : ".$this->type."<br>";
		echo"Nombre de wagons : ".$this->nbwagon."<br>";
		//Fin de la méthode
		
	}
}


$V1 = new Voiture("Peugeot","207","noire","120 ch",77777,"Essence",3);
$V1->roule(150);
$V1->Affichage();


$T1 = new Train("SNCF","TGV","Bleu, Blanc","1300 kW",1000,"Electrique",14);
$T1->roule(800);
$T1->Affichage();


$V2 = new Voiture("Renault","Clio","bleue","70 ch",55555,"Diesel",5);
$V2->roule(115,1.8);

$T2 = new Train("SNCF","TER","Bleu","500 kW",400000,"Electrique",8);
$T2->roule(3000,0.4);


$tableau1= array(1=>$V1,2=>$T1);
$tableau2= array(1=>$V2,2=>$T2);


echo"Voiture";
echo $tableau1[1]->Affichage();
echo $tableau2[1]->Affichage();
echo"<br>";
echo"Train";
echo $tableau1[2]->Affichage();
echo $tableau2[2]->Affichage();

?>
