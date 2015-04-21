<?php

Class Vehicule {
	var $marque;
	var $couleur;
	var $kilometres;
	var $qteCarburant;
	var $année;
	var $vitesse;

function __construct(){

	$num=func_num_args(); //renvoi le nombre d'arguments
	$args=func_get_args(); //renvoi les valeurs des arguments

	switch($num){

		case 0:
		$this->marque=$marque;
		$this->couleur=$couleur;
		$this->kilometres=$kilometres;
		$this->qteCarburant=$qteCarburant;
		$this->année=$année;
		$this->vitesse=$vitesse;
		break;

//attribuons les place de chaque attribut

		case 4:

		$this->marque=args[0];
		$this->couleur=args[1];
		$this->km=args[2];
		$this->qteCarburant=args[3];
		$this->année=args[4];
		$this->vitesse=args[5];

		break;


	}

}

// methode informations
function informations(){
	 <br>
	  echo " La ". $this-> Marque "d'année"$this->année $this-> Couleur "qui a ". $this -> kilomètre "km a son actif, lui reste " $this -> qteCarburant. "de carburant.";
	 </br> 	
	}	

// methode arret 
function arret(){

$vitesse=0;
echo"<br><br>";

	if ($vitesse==0)
	{
	echo " le Vehicule est a l'arret.";
	}

}

// methode roule
function roule()

// determinos la fonction qui nous permet de savoir si la voiture roule
{
	echo"<br><br>";
	
	if ($vitesse>=1)
	{
		echo " le Vehicule roule."
	}

// la suite nous indique le carburant utilisé en fonction des kilometres parcouruent.	
	
	for ($this->kilometres=1; $this->km<300000; $this->km++) 
	{
		for($this->qteCarburant=30;$this->qteCarburant<=30;$this->qteCarburant--)
				{
				$km=$this->km;
				$coco=$this->qteCarburant;
				
				echo 
				<br> 
				"vous avez parcouru".$km. "kilometres, et avez consomé".$coco. "quantité de carburant";
				<br>
				}
	}
	
}
}
	



// EXERCICE n°3

//1) classe fille "voiture"

//"extends" permet le passage d'une classe à une autre. d'une classe mère a une classe fille.

class Voiture extends Vehicule
{

var $typeCarburant;
var $nombredeportes;

function __construct(){

	$num=func_num_args();
	$args=func_get_args();

	switch ($num) {
		case 0:
            //$this->marque=$marque;
		    //$this->couleur=$couleur;
		    //$this->kilometres=$kilometres;
		    //$this->qteCarburant=$qteCarburant;
		    //$this->année=$année;
		    //$this->vitesse=$vitesse;
			$this->typeCarburant= $typeCarburant;
			$this->nombredeportes= $nombredeportes;
			
			break;
		case 8:
			
		    //$this->marque=args[0];
		    //$this->couleur=args[1];
		    //$this->km=args[2];
		    //$this->qteCarburant=args[3];
		    //$this->année=args[4];
		    //$this->vitesse=args[5];
			$this->typeCarburant=args[6];
			$this->nbportes=args[7];
			
			break;


function informations()

{
<br>
echo "Le véhicule est un ". $this->typeCarburant. " et c'est une ". $this->nombredeportes ." portes.";
</br>	
}

function arret()
		{
			parent::arret();
		}


function roule()
	{
			parent::roule();
	}

	
}
}
}






//2) classe fille "train"

class Train extends Vehicule
{

	//var $marque;
	//var $couleur;
	//var $kilometres;
	//var $qteCarburant;
	//var $année;
	//var $vitesse;
	var $typeTrain;
	var $nbWagons;


	function __construct()
	{

		$num=func_num_args();
		$args=func_get_args();

		switch ($num) {
			case 0:
			//$this->marque=$marque;
		    //$this->couleur=$couleur;
		    //$this->kilometres=$kilometres;
		    //$this->qteCarburant=$qteCarburant;
		    //$this->année=$année;
		    //$this->vitesse=$vitesse;
		      $this->typeTrain=typeTrain;
			  $this->nbWagons=nbWagons;
				
				break;

			case 8:
		    //$this->marque=args[0];
		    //$this->couleur=args[1];
		    //$this->kilometresm=args[2];
		    //$this->qteCarburant=args[3];
		    //$this->année=args[4];
		    //$this->vitesse=args[5];
			$this->typeTrain=args[6];
			$this->nbWagons=args[7];
			
			break;


		}


	}

	function informations()
	{
<br>
echo "Le Train est un ". $this->typeTrain. " et il a ". $this->nbWagons ." Wagons.";
</br>	
	}

	function arret()
	{

		parent::arret();
	}

	function roule()
	{
		parent::roule();
	}

}


//EXERCICE 4


$PanameraS = new Vehicule("Porsche","Noire matte",50000,30,2014,10);
$F458Italia = new Voiture("Hybride",3);
$ZENA = new Train("RER",10);

$tab = array($PanameraS, $F458Italia, $ZENA);
	
	foreach ($tab as $key => $value) 
	{
		$value->informations();
		$value->arret();
		$value->roule();
	}
	
?>