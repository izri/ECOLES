<?php

/*EXERCICE 2*/

class Vehicule{
	
	var $marque;
	var $couleur;
	var $km; // nombre de km parcourus
	var $qCarburant; // quantité de carburant restante
	var $conso; // consommation du véhicule L/100km
	var $mvt; //Booléen qui sert à savoir si la voiture est en mouvement ou non
	
	function __construct(){
		
		$num = func_num_args();
		$args = func_get_args();
		
		switch($num){
		
			case 0 :
				$this->marque ="";
				$this->couleur ="";
				$this->km ="";
				$this->mvt = false; //véhicule est à l'arrêt par défaut
				$this->qCarburant ="";
				$this->conso ="";
				break;
				
			case 6 :
				$this->marque = $args[0];
				$this->couleur = $args[1];
				$this->km = $args[2];
				$this->mvt = $args[3];
				$this->qCarburant = $args[4];
				$this->conso = $args[5];
				break;
				
			default :
				echo "Erreur! Le nombre d'arguments est incorrect."; 
				break;
		}
	}
	
	function Afficher()  //Afficher les informations de la voiture
	
	{  
		echo "Marque : ".$this->marque."</br>";
		echo "Couleur : ".$this->couleur."</br>";
		echo "Kilométrage : ".$this->km."km</br>";
		echo "Quantité carburant : ".$this->qCarburant."L</br>";
		echo "Consommation : ".$this->conso."L/100km</br>";
	}
	
	function arret()
	{
		$this->mvt = false;
	}
	
	function roule(){
		if($this->qCarburant > $this->conso/100)
		{ 
			$this->mvt = true; //véhicule en mouvement
			$this->km++; 
			$this->qCarburant -= $this->conso/100;
		}
	}
}

/*EXERCICE 3*/
class Voiture extends Vehicule
{
	var $typeCarburant;
	var $nbPortes;
	
	function __construct()
	{	
		$num = func_num_args();
		$args = func_get_args();
		
		switch($num){
			
			case 0 :
				$this->marque = "";
				$this->couleur = "";
				$this->km = "";
				$this->mvt = false;//par défaut le véhicule est à l'arrêt
				$this->qCarburant = "";
				$this->conso ="";
				$this->typeCarburant = "";
				$this->nbPortes = "";
				break;
				
			case 8 :
				$this->marque = $args[0];
				$this->couleur = $args[1];
				$this->km = $args[2];
				$this->mvt = $args[3];
				$this->qCarburant = $args[4];
				$this->conso = $args[5];
				$this->typeCarburant = $args[6];
				$this->nbPortes = $args[7];
				break;
				
			default :
				echo "Erreur! Le nombre d'arguments est incorrect."; 
				break;
		}
	}
	
	function Afficher()
	{
		parent::Afficher();
		echo "Type de carburant : ".$this->typeCarburant."</br>";
		echo "Nombre de portes : ".$this->nbPortes." portes</br>";
	}
}

class Train extends Vehicule
{
	var $type;
	var $nbWagons;
	
	function __construct()
	{
		
		$num = func_num_args();
		$args = func_get_args();
		
		switch($num)
		{
			case 0 :
				$this->marque = "";
				$this->couleur = "";
				$this->km = "";
				$this->mvt = false;
				$this->qCarburant = "";
				$this->conso = "";
				$this->type = "";
				$this->nbWagons = "";
				break;
				
			case 8 :
				$this->marque = $args[0];
				$this->couleur = $args[1];
				$this->km = $args[2];
				$this->mvt = $args[3];
				$this->qCarburant = $args[4];
				$this->conso = $args[5];
				$this->type = $args[6];
				$this->nbWagons = $args[7];
				break;
				
			default :
				echo "Erreur! Le nombre d'arguments est incorrect."; 
				break;
		}
	}
	
	function Afficher(){
		parent::Afficher();
		echo "Type de train : ".$this->type."</br>";
		echo "Nombre de wagons : ".$this->nbWagons." wagons</br>";
	}
}

/*EXERCICE 4*/
 $V1 = new Vehicule();
 $V1->Afficher();
 echo "</br></br>";
 
 $V2 = new Vehicule("Renault", "gris", 60, false, 50, 5);
 $V2->Afficher();
 echo "</br></br>";
  
 $V3 = new Voiture("Renault", "gris", 60, false, 50, 5, "diesel", 6);
 $V3->Afficher();
 echo "</br></br>";
 
 
 $d = 25;
 $index = 0;
 
 while($index<$d){
	$V3->roule();
	$index++;
 };
	$V3->arret();
    $V3->Afficher();
 echo "</br></br>";
  
 $T1 = new Train();
 $T1->Afficher();
 echo "</br></br>";
 
 $table = array(1=>$V1,2=>$V2,3=>$V3,4=>$T1);

foreach($table as $i => $value){
	echo "Véhicule N° ".$i."</br></br>";
	echo $value->Afficher();
	echo "</br></br>";
}
?>