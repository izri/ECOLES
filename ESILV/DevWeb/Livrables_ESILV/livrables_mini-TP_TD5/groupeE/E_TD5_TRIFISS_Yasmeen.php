<?php



/*				EXERCICE 2				*/

class Vehicule{
	
	var $marque;
	var $couleur;
	var $kilometres;
	var $qteCarburant;

	function __construct(){
		
		$num = func_num_args();
		$args = func_get_args();
		
		switch($num){
			case 0 :
				$this->marque = "none";
				$this->couleur = "none";
				$this->kilometres = 100;
				$this->qteCarburant = 100;
				break;
			case 4 :
				$this->marque = $args[0];
				$this->couleur = $args[1];
				$this->kilometres = $args[2];
				$this->qteCarburant = $args[3];
				break;
			default :
				echo "Erreur"; 
				break;
		}
	}
	
	function affichage(){
		echo "Marque : ".$this->marque."</br>";
		echo "Couleur : ".$this->couleur."</br>";
		echo "Nombre de kilomètres: ".$this->kilometres."</br>";
		echo "Quantité de carburant: ".$this->qteCarburant."</br>";
	}
	
	function arret(){
		
	}
	
	function roule(){
		$this->kilometres++;
		$this->qteCarburant--;
	}
}




/*				EXERCICE 3				*/

class Voiture extends Vehicule{
	
	var $carburant;
	var $nbPortes;
	
	function __construct(){
		
		$num = func_num_args();
		$args = func_get_args();
		
		switch($num){
			case 0 :
				$this->marque = "none";
				$this->couleur = "none";
				$this->kilometres = 100;
				$this->qteCarburant = 100;
				$this->carburant = "none";
				$this->nbPortes = 0;
				break;
			case 6 :
				$this->marque = $args[0];
				$this->couleur = $args[1];
				$this->kilometres = $args[2];
				$this->qteCarburant = $args[3];
				$this->carburant = $args[4];
				$this->nbPortes = $args[5];
				break;
			default :
				echo "Erreur"; 
				break;
		}
	}
	
	function affichage(){
		parent::affichage();
		echo "Type de carburant : ".$this->carburant."</br>";
		echo "Nombre de portes : ".$this->nbPortes."</br>";
	}
}

class Train extends Vehicule{
	
	var $type;
	var $nbWagons;
	
	function __construct(){
		
		$num = func_num_args();
		$args = func_get_args();
		
		switch($num){
			case 0 :
				$this->marque = "none";
				$this->couleur = "none";
				$this->kilometres = 100;
				$this->qteCarburant = 100;
				$this->type = "none";
				$this->nbWagons = "none";
				break;
			case 6 :
				$this->marque = $args[0];
				$this->couleur = $args[1];
				$this->kilometres = $args[2];
				$this->qteCarburant = $args[3];
				$this->type = $args[4];
				$this->nbWagons = $args[5];
				break;
			default :
				echo "Erreur"; 
				break;
		}
	}
	
	function affichage(){
		parent::affichage();
		echo "Type de train : ".$this->type."</br>";
		echo "Nombre de wagons : ".$this->nbWagons."</br>";
	}
}



/*				EXERCICE 4				*/
 
 $vehicule0 = new Vehicule("Citroen", "Rouge", 100, 100);
 $vehicule1 = new Voiture("Renault", "Bleu", 100, 100,"diesel",5);
 $vehicule2 = new Train("", "Vert", 100, 100,"TGV",20);
 
 $tab[0]=$vehicule0;
 $tab[1]=$vehicule1;
 $tab[2]=$vehicule2;
 
foreach($tab as $key => $value){
	echo "<strong>Véhicule ".$key."</strong></br>";
	echo $value->affichage();
	echo "</br>";
}
?>