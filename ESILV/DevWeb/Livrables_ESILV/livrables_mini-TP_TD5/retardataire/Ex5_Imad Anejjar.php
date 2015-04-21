<?php
//Exo2
	class Vehicule{
var $marque;
var $couleur;
var $kilometres;
var $qteCarburant;

function ConstructeurDefaut(){
	$this->marque="Renault";
	$this->couleur="Gris";
	$this->kilometres=138000;
	$this->qteCarburant= "Diesel";

}

function Constructeur($marque,$couleur,$kilometres,$qteCarburant){
	$this->marque = $marque;
	$this->couleur = $couleur;
	$this->kilometres = $kilometres;
	$this->qteCarburant = $qteCarburant;
}
}

//Exo3
class Voiture extends Vehicule {
	function ConstructeurVoiture($marque,$couleur,$kilometres,$qteCarburant,$portes){
		parent::Constructeur($couleur,$marque,$kilometres, $qteCarburant);
		$this->portes = $portes;
	}
}

class Train extends Vehicule {
	function ConstructeurTrain($marque,$couleur,$kilometres,$qteCarburant,$wagons,$type){
		parent::Constructeur($couleur,$marque,$kilometres, $qteCarburant);
		$this->wagons = $wagons;
		$this->type = $type;
	}
}

//Exo4
$Clio = new Voiture("Clio","Vert",200000,"plein",5);
$R8 = new Voiture("Audi R8","Noir",20000,"plein",5);
$TER = new Train("","Bleu",250000,"plein",16,"TER");

var $liste=array($Clio,$R8,$TER);
for($i=0; $i<2;i++{
		echo liste[i];
	}