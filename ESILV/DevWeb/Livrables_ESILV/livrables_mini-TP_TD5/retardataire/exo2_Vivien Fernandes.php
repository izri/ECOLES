<?php
class Vehicule {
 var $Marque; 
 var $couleur; 
 var $kilometres; 
 var $qteCarb; 
 var $marche; 
 function __construct() 
 { 
 	$num = func_num_args(); 
 	$arg = func_get_args(); 
 	switch($num) 
 	{ 
 		case 0: 
 		{ 
 			$this -> Marque = "t"; 
 			$this -> couleur = "b"; 
 			$this -> kilometres = 0;
 			$this -> qteCarb = 0; 
 			$this -> marche = 0; 
 			break; 
 		} 
 		case 5: 
 		{ 
 			$this -> Marque = $arg[0]; 
 			$this -> couleur = $arg[1]; 
 			$this -> kilometres = $arg[2]; 
 			$this -> qteCarb = $arg[3]; 
 			$this -> marche = $arg[4]; 
 			break; 
 		} 
 		default : echo "error"; 
 	} 
 } 
 function affichage() 
 {
echo "Le vehicule de marque "
.$this -> Marque." de couleur "
.$this -> couleur. " contenant "
.$this -> qteCarb." L de carburant ayant parcouru "
.$this -> kilometres." kilomètres"; 
if ($this -> marche == 1) 
	echo " avance.</br>"; 
else 
	echo " n'avance pas .</br>"; 
} 
function arret() 
{ 
	if ($this -> marche == 1) 
		$this->marche=0; 
	echo "Le vehicule se stop.</br>"; 
} 
function roule() 
{ 
	$this->marche=1; 
	$this->kilometres+=1; 
	$this->qteCarb--; 
	echo "Le vehicule consomme un litre d'essence en un kilomètre.</br>";
	 } 
	}


	class Voiture extends Vehicule
	{
		var $carburant;
		var $nbrePorte;
function __construct() 
 { 
 	parent :: __construct();
 	$num = func_num_args(); 
 	$arg = func_get_args(); 
 	switch($num) 
 	{ 
 		case 0: 
 		{ 
 			$this -> carburant = "diesel"; 
 			$this -> nbrePorte = 5; 
 			break; 
 		} 
 		case 2: 
 		{ 
 			$this -> carburant = $arg[0]; 
 			$this -> nbrePorte = $arg[1];  
 			break; 
 		} 
 		default : echo "error"; 
 	} 
 } 
 function affichage() 
 {
echo "Le vehicule a ".$this -> nbrePorte ." porte et utilise un carburant de type " .$this -> carburant ."</br>";

} 



	}

	class Train extends Vehicule
	{

		var $type;
		var $nbreWagon;
		function __construct() 
 { 
 	parent :: __construct();
 	$num = func_num_args(); 
 	$arg = func_get_args(); 
 	switch($num) 
 	{ 
 		case 0: 
 		{ 
 			$this -> type = "TGV"; 
 			$this -> nbreWagon = 6; 
 			break; 
 		} 
 		case 2: 
 		{ 
 			$this -> type = $arg[0]; 
 			$this -> nbreWagon = $arg[1];  
 			break; 
 		} 
 		default : echo "error"; 
 	} 
 } 
 function affichage() 
 {
echo "Le train à  ".$this -> nbreWagon ." Wagon et est de type " .$this -> type ."</br>";
}
	}

	$Polo= new Vehicule("volkswagen","noir","100000","60","1");
	$PoloBis= new Voiture("diesel","5");
	$ALINEA7= new Train("TGV","10");
	$TableauVehicule[0]=$Polo;
	$TableauVehicule[1]=$PoloBis;
	$TableauVehicule[2]=$ALINEA7;

	$Polo -> affichage();
	$PoloBis -> affichage();
	$ALINEA7 -> affichage();
	$Polo -> roule();
	$Polo -> affichage();
	$Polo -> arret();
	$Polo -> affichage();
?>