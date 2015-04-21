<?php
class Vehicule{

var $marque;
var $couleur;
var $kilometres;
var $qteCarburant;
	
	
//exo 2
public function __constructeur(){

	
			$this->marque=$args[0];
			$this->couleur=$args[1];
			$this->kilometres=$args[2];
			$this->qteCarburant=$args[3];	
	}
	
//exo3
	public function donnees(){

		return "la marque de la voiture est" .$this->marque . "sa couleur est " .$this->couleur . " le nombre de km :"  .$this->kilometres . "la quantité de carburant est de"   .$this->qteCarburant;
	} 
//méthode 
	public function arret() {

		echo "la voiture est à l'arrêt";
	}
	
//méthode
	public function roule(){

		$this->kilometres = $this->kilometres + 1;
		$this->qteCarburant = $this->qteCarburant - 1;
		echo "La voiture roule";
	}	
}
 
//exo 4
class Voiture extends Vehicule {
	var $nbPortes = 3;
	var $carburant = "diesel";

	public function __constructeur( $couleur,$marque, $kilometres, $qteCarburant, $carburant, $nbPortes){
		$this->carburant=$carburant;
		$this->nbPortes=$nbPortes;
		parent::__constructeur($couleur,$marque,$kilometres, $qteCarburant);
	}
	public function infos(){
		return "Le type de carburant de la voiture est" . $this->carburant . "Le nombre de portes est de" . $this->nbPortes . " - ". parent::donnees();
	}
}
class Train extends Vehicule {
	var $type= "RER";
	var $nombreWagons = 5;
	
	public function __constructeur( $couleur, $marque, $kilometres, $qteCarburant, $type, $nombreWagons){
		$this->type=$type;
		$this->nombreWagons=$nombreWagons;
		parent::__constructeur($couleur, $marque, $kilometres, $qteCarburant);
	}
	public function train(){
		return "Le train est de type:" . $this->type . " Le nombre de wagons est:" . $this->nbWagons . " - ". parent::infos();
	}
}

$vehicule = new Vehicule("jaune", "Toyota", 6135, 3);
 echo $vehicule->donnees();
 $vehicule->roule();
 ?><br/><?php
 echo $vehicule->donnees();
 
 $voiture = new Voiture("jaune", "Opel", 6135, 5, "diesel", 3);
 ?><br/><?php
 echo $voiture->donnees();
 $voiture->roule();
 ?><br/><?php
 echo $voiture->infos();
 
 
 $train = new Train("rouge", "RATP",64615, 564, "RER", 10);
?><br/><?php
echo $train->trains();
?><br/><?php
echo $voiture->train();