<?php
class Vehicule{

	var $marque;
	var $couleur;
	var $kilometre;
	var $qdtCarbu;

	function Vehicule(){
		$num=func_num_args();
		$arguments=func_get_args();
		switch ($num) {
			case 0:
			$this->marque="t";
			$this->couleur="b";
			$this->kilometre="0";
			$this->qdtCarbu="0";
			break;

			case 4;
			$this->marque=$arguments[0];
			$this->couleur=$arguments[1];
			$this->kilometre=$arguments[2];
			$this->qdtCarbu=$arguments[3];
			break;
			
			default: echo"erreur";
			break;
		}

	}
	function affichage(){

		echo "le Vehicule de marque". $this->marque.
		"de couleur " . $this->couleur . "ayant roulé "
		. $this->kilometre . "contient ". $this->qdtCarbu . "</br>";
	}

	function arret(){

		echo "le Vehicule est à l'arret </br>";
		$this->mouv=false;
	}

	function roule (){
		$this->kilometre++;
		$this->qdtCarbu--;
		$this->mouv=true;
		echo "le Vehicule est en marche </br>";
	
	}

}

// Exercice 3

class Voiture extends Vehicule{
	var $carburant;
	var $nb_portes;


	function voiture(){

		parent::Vehicule();
		$num=func_num_args();
		$arguments=func_get_args();

		switch ($num) {
			case 6:
				$this->marque=$arguments[0];
				$this->couleur=$arguments[1];
				$this->kilometre=$arguments[2];
				$this->qdtCarbu=$arguments[3];
				$this->roule=$arguments[4];
				$this->carburant=$arguments[5];
				$this->nb_portes=$arguments[6];
				break;
			
			default:
				echo"erreur";
				break;
		}


	}

	function affichage(){

		parent::affichage();

		echo"la voiture fonctionne grace au carburant suivant: " .$this->carburant
		. "et possède " .$this->nb_portes ."</br>";
	}

}


class Train {
	var $type;
	var $nb_wagons;

	function train(){

		parent::Vehicule();
		$num=func_num_args();
		$arguments=func_get_args();

		switch ($num) {
			case 2 :
				$this->marque=$arguments[0];
				$this->couleur=$arguments[1];
				$this->kilometre=$arguments[2];
				$this->qdtCarbu=$arguments[3];
				$this->roule=$arguments[4];
				$this->carburant=$arguments[5];
				$this->type=$arguments[6];
				$this->nb_portes=$arguments[7];
				break;
			
			default:
				echo"erreur";
				break;
		}

		$this->type=$type
		$this->nb_wagons=$nb_wagons;
	}

	function affichage(){

		parent::affichage();

		echo"le train est du type: " .$this->type
		. "et possède " .$this->nb_portes ."</br>";
	}
}



// Exercice 4

$Va= new Voiture("Fiat", "rouge", 60000, 50, 0, "Diesel",3);
$Va->roule(100, 5);

$Ta= new Train("TGV", "bleu", 5000, 1000, 0, "Electrique",20);
$Ta->roule(1000, 0.1);


new $tab = array(1 => Va , 2=>Ta );

for for ($i=1; $i < 2; $i++) { 

	$tableau[1]->Affichage();
	
	$tableau[2]->Affichage();
	}


?>