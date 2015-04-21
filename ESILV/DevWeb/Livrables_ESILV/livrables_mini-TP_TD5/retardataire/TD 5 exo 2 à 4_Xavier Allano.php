<?php 
class Vehicule 
{
	var $marque; 
	var $couleur; 
	var $kilometre; 
	var $qteCarburant; 
	var $marche; 
	
	function construct()
	{
	$num = func_num_args(); 
	$args = func_get_args();
	switch($num)
	{
		case 0 : 
		{$this -> Marque = "t"; 
		$this -> couleur = "6"; 
		$this -> kilometre = 0;
		$this -> qteCarburant = 0 ; 
		$this -> marche = 0 ; 
		//$this -> carburant = "diesel";
		break ; }
		
		case 5 : 
		{$this -> Marque = $arg[0]; 
		$this -> couleur = $arg[1]; 
		$this -> kilometre = $arg[2];
		$this -> qteCarburant = $arg[3] ;
		$this -> marche = $arg[4] ;
		break ; }
		
		default : echo "erreur"; 
	}
	}
	function affichage() 
	{
		echo "Le vehicule de marque " . $this -> marque . " a fait " . $this -> kilometre ", contient " . $this -> qteCarburant "</br>"
		if ($this -> marche == 1) 
			echo "est en marche"; 
	}
	
	function arret() 
	{
		if ($this -> marche == 1 ) 
			$this -> marche == 0 ;
			echo "Le vehicule est à l'arret </br>"; 
	}
	
	function roule()
	{
		$this -> marche = 1 ; 
		$this -> kilometre += 1 ; 
		$this -> qteCarburant-- ;
	}

	/*function voiture()
	{
		$this -> carburant;
	}*/
}

class Voiture extends Vehicule
{
	var $carburant; 
	var $nbporte; 

	function construct()
	{
	$num = func_num_args(); 
	$args = func_get_args();
	switch($num)
	{
		case 0 : 
		{$this -> carburant = "diesel"; 
		$this -> nbporte = "4"; 
		break ; }
		
		case 5 : 
		{$this -> carburant = $arg[0]; 
		$this -> nbporte = $arg[1]; 
		break ; }
		
		default : echo "erreur"; 
	}
}

class Train extends Vehicule
{
	var $type; 
	var $nbwagon; 
 
	function construct()
	{
	$num = func_num_args(); 
	$args = func_get_args();
	switch($num)
	{
		case 0 : 
		{$this -> type = "INTERCITES"; 
		$this -> nbwagon = "1"; 

		break ; }
		
		case 5 : 
		{$this -> type = $arg[0]; 
		$this -> nbwagon = $arg[1]; 

		break ; }
		
		default : echo "erreur"; 
	}
}