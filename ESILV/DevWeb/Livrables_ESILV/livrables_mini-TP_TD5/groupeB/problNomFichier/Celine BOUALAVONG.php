<?php
class Vehicule{
var $marque;
var $couleur;
var $kilometres;
var $qteCarburant;
	
	
public function __constructeur(){

	$numero = func_numero_args();
		
	if($numero == 4 ) {
			$args = func_get_args();
			$this->marque=$args[0];
			$this->couleur=$args[1];
			$this->kilometres=$args[2];
			$this->qteCarburant=$args[3];	
			}
	}
	
public function informations(){

		return "la marque de la voiture est" . $this->marque . "sa couleur est " . $this->couleur . " le nombre de km :"  . $this->kilometres . "la quantitée de carburant est de"   . $this->qteCarburant;
	}
public function arret() {

		echo "la voiture est à l'arret";
	}
	
public function roule(){

		$this->kilometres = $this->kilometres + 1;
		$this->qteCarburant = $this->qteCarburant - 1;
	}	
}

class Voiture extends Vehicule {
	var $nbPortes = 5;
	var $carburant = "diesel";

	public function __constructeur( $couleur,$marque, $kilometres, $qteCarburant, $carburant, $nbPortes){
		$this->carburant=$carburant;
		$this->nbPortes=$nbPortes;
		parent::__constructeur($couleur,$marque,$kilometres, $qteCarburant);
	}
	public function infos(){
		return "Le type de carburant de la voiture est" . $this->carburant . "le nombre de porte est de" . $this->nbPortes . " - ". parent::infos();
	}
}
class Train extends Vehicule {
	var $type= "INTERCITES";
	var $nombreWagons = 5;
	
	public function __construct( $couleur, $marque, $kilometres, $qteCarburant, $type, $nombreWagons){
		$this->type=$type;
		$this->nombreWagons=$nombreWagons;
		parent::__construct($couleur, $marque, $kilometres, $qteCarburant);
	}
	public function informations(){
		return "le train est de type :" . $this->type . " nombre de wagons est de" . $this->nbWagons . " - ". parent::infos();
	}
}

$vehicule = new Vehicule("grise", "Opel", 1234, 5);
 echo $vehicule->informations();
 
 $vehicule->roule();
 ?><br/><?php
 echo $vehicule->informations();
 
 $voiture = new Voiture("grise", "Opel", 1234, 5, "diesel", 5);
 ?><br/><?php
 echo $voiture->informations();
 $voiture->roule();
 ?><br/><?php
 echo $voiture->informations();
 
 
 $train = new Train("blanc et vert", "RATP",12345, 12345, "INTERCITE", 5);
?>