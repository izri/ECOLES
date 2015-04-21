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
 			$this -> Marque = ""; 
 			$this -> couleur = ""; 
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

 function affichages() 
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
 			$this -> carburant = ""; 
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

echo "Le vehicule a "
.$this -> nbrePorte .
" portes a pour carburant "
 .$this -> carburant .
 "</br>";

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
 			$this -> type = ""; 
 			$this -> nbreWagon = 4; 
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

echo "Le train à  "
.$this -> nbreWagon .
" wagons et est un "
 .$this -> type .
 "</br>";

}
	}
	$Eurostar= new Train("TGV","30");
	$Renault= new Vehicule("renault","bleu","60000","40","1");
	$Scenic= new Voiture("diesel","5");
	
	$TableauVehicule[0]=$Renault;
	$TableauVehicule[1]=$Scenic;
	$TableauVehicule[2]=$Eurostar;

	$Renault -> affichages();
	$Scenic -> affichage();
	$Scenic -> affichages();
	$Eurostar -> affichage();
	$Renault -> roule();
	$Renault -> affichages();
	$Renault -> arret();
	$Renault -> affichages();
?>