<?php
//COURANT Louise TD B
class Vehicule{
	var $marque;
	var $couleur;
	var $kilometres;
	var $qteCarburant;
	
	
	public function __construct(){
		$nums = func_num_args();
		
		if($nums == 4 ) {
			$args = func_get_args();
			
			$this->marque=$args[0];
			$this->couleur=$args[1];
			$this->kilometres=$args[2];
			$this->qteCarburant=$args[3];	
		}
	}
	
	public function infos(){
		return "marque=" . $this->marque . " - couleur=" . $this->couleur . "  - kilometres="  . $this->kilometres . "  -   qteCarburant="   . $this->qteCarburant;
	}
	public function arret() {
		echo "arret";
	}
	
	public function roule(){
		$this->kilometres = $this->kilometres + 1;
		$this->qteCarburant = $this->qteCarburant - 1;
	}	
}

class Voiture extends Vehicule {
	var $carburant = "diesel";
	var $nbPortes = 3;
	
	public function __construct($marque, $couleur, $kilometres, $qteCarburant, $carburant, $nbPortes){
		$this->carburant=$carburant;
		$this->nbPortes=$nbPortes;
		parent::__construct($marque, $couleur, $kilometres, $qteCarburant);
	}
	public function infos(){
		return "VOITURE: carburant=" . $this->carburant . " - nbPortes=" . $this->nbPortes . " - ". parent::infos();
	}
}


class Train extends Vehicule {
	var $type= "tgv";
	var $nbWagons = 8;
	
	public function __construct($marque, $couleur, $kilometres, $qteCarburant, $type, $nbWagons){
		$this->type=$type;
		$this->nbWagons=$nbWagons;
		parent::__construct($marque, $couleur, $kilometres, $qteCarburant);
	}
	public function infos(){
		return "TRAIN: type=" . $this->type . " - nbPWagons=" . $this->nbWagons . " - ". parent::infos();
	}
}


$v = new Vehicule("peugeot", "red", 1000, 5);
 echo $v->infos();
 
 $v->roule();
 ?><br/><?php
 echo $v->infos();
 
 $voiture = new Voiture("peugeot", "red", 1000, 5, "essence", 9);
 ?><br/><?php
 echo $voiture->infos();
 $voiture->roule();
 ?><br/><?php
 echo $voiture->infos();
 
 
 $train = new Train("renault", "noir",200000, 300000, "ter", 8);
 ?><br/><?php
 echo $train->infos();
 

?>