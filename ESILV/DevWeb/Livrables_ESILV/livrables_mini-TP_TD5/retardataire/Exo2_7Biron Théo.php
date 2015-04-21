<?php

class Vehicule{

 var $marque;
 var $couleur;
 var $km;
 var $qteCarburant;
 var $marche;

function Constructeur()
{
	$num = func_num_args();
	$args = func_get_args();
	switch($num)
	{
		case 0 :
		$this->marque = "t";
		$this->couleur = "b";
		$this->km = 0;
		$this->qteCarburant = 0;
		$this->marche = 0;
		break;
		
		case 1 :
		$this->marque = $args[0];
		$this->couleur = $args[1];
		$this->km = $args[2];
		$this->qteCarburant = $args[3];
		$this->marche = $args[4];
		break;
		
		default :
		echo "Error";
	}
}

function Arret()
{
	if($this->marche == 1)
		$this->marche = 0;
	echo "Le vehicule est à l'arrêt </br>";
}

function Roule()
{
	$this->marche = 1;
	$this->km += 1;
	$this->qteCarburant--;
}

function Affiche()
{
	echo "Le vehicule de marque "
	.$this->marque. " de couleur "
	.$this->couleur. " a fait "
	.$this->km. " km, et contient "
	.$this->qteCarburant. "</br>";
	if($this->marche == 1)
		echo " est en marche";
}
}

class Voiture extends Vehicule{
var $carburant;
var $nbportes;
	
function Voiture()
{
	$num = func_num_args();
	$args = func_get_args();
	switch($num)
	{
		case 0 :
		$this->carburant = "";
		$this->nbportes = 0;
		break;
		
		case 1 :
		$this->carburant = $args[0];
		$this->nbportes = $args[1];
		break;
		
		default :
		echo "Error";
	}
}
}

class Train extends Vehicule{
var $type;
var $nbwagons;
	
function Train()
{
	$num = func_num_args();
	$args = func_get_args();
	switch($num)
	{
		case 0 :
		$this->type = "";
		$this->nbwagons = 0;
		break;
		
		case 1 :
		$this->type = $args[0];
		$this->nbwagons = $args[1];
		break;
		
		default :
		echo "Error";
	}
}
}

?>