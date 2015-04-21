<?php 

//Exercice 2 

//Classe Mere
class Vehicule 
{
	var $marque; 
	var $couleur; 
	var $kilometre; 
	var $qteCarburant;
	var $marche; 
	
	function __construct()
	{
	$num = func_num_args(); 
	$args = func_get_args();
	
	switch($num)
	{
		case 5 : 
			{$this -> Marque = $arg[0]; 
			$this -> couleur = $arg[1]; 
			$this -> kilometre = $arg[2];
			$this -> qteCarburant = $arg[3] ;
			$this -> marche = $arg[4] ;
			break ; }
		
		default : 
			echo "Erreur"; 
			break;
	}
	}
	function affichage() 
	{
		echo "<br> Le vehicule de marque " . $this -> marque . " a fait " . $this -> kilometre ", contient " . $this -> qteCarburant "<br>";
		if ($this -> marche == 1) 
			echo "est en marche </br>"; 
	}
	
	function arret() 
	{
		if ($this -> marche == 0 ) 
			echo "Le vehicule est à l'arret </br>"; 
		else 
			echo "Le vehicule roule </br>";
	}
	
	function roule()
	{
		$this -> marche = 1 ; 
		$this -> kilometre += 1 ; 
		$this -> qteCarburant-- ;
	}
}

//Exercice 3
// Classe Filles 

class Train extends Vehicule
{
	var $TypeTrain
	var $NbWagon
	
		function construct()
		{
			$num = func_num_args(); 
			$args = func_get_args();
			switch($num)
				{
					case 0 : 
					{
						$this -> TypeTrain = $args[0];
						$this -> NbWagon = $args[1] ;
						break ; 
					}
					default : echo "Erreur"; 
				}
		}
	function affichage() 
	{
		echo "<hr><hr>";
		parent::affichage();
		echo "Le train, de type  " . $this -> TypeTrain ", a  " . $this -> NbWagon" wagon(s). <br><hr>"
	}
}

class Voiture extends Vehicule
{
	var $TypeCarburant; 
	var $NbPorte; 
	
	function __construct()
	{
		$num = func_num_args(); 
		$args = func_get_args();
		switch($num)
		{
			case 0 : 
			{
				$this->marque=$args[0];
			    $this->couleur=$args[1];
			    $this->kilometres=$args[2];
			    $this->qteCarburant=$args[3];
				$this -> marche = $arg[4] ;
				$this -> TypeCarburant = $args[5] ;
				$this -> NbPorte = $args[6];
				break ; 
			}
	
			default : 
				echo "Erreur";
				break;
		}	
	}
	function affichage() 
	{
		echo "<br>";
		parent::affichage();
		echo "Le vehicule contient le carburant  " . $this -> TypeCarburant . " a  " . $this -> NbPorte ." portes. </br>"
	}
}

//Exercice 4

$myVehi=new Vehicule("Renault", "Rouge", 10000, 60,0);
$myVehi->affichage();
$myVehi->roule();
$myVehi->arret();
$myVoit=new Voiture("Ferrari", "Noir", 100000, 35,1, "Diesel",2);
$myVoit->affichage();
$myVoit->roule();
$myVoit->arret();
$myTrain=new Train("TGV",13);
$myTrain->affichage();
$myTab = array($myVehi, $myVoit, $myTrain);
	foreach ($myTab as $key => $value) 
	{
		$value->affichage();
	}


?>