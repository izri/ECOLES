<?php

class Vehicule{

var $marque;
var $couleur;
var $kilometre;
var $qteCarbu;
var $etat= false;

function Commande(){ 

	$nb=func_num_args();
	$arguments=func_get_args();
	
	switch($nb)
	{
		case 0 :
		$this->marque="t";
		$this->couleur="b";
		$this->kilometre=0;
		$this->qteCarbu=0;
		break;
		
		case 4 : 
		$this->marque=$arguments[0];
		$this->couleur=$arguments[1];
		$this->kilometre=$arguments[2];
		$this->qteCarbu=$arguments[3];
		break;
		default: echo "erreur "; break;
	}
}

function getMarque(){
	return $this->marque;
}
function getCouleur(){
	return $this->couleur;
}
function getKilometre(){
	return $this->kilometre;
}
function getQteCarbu(){
	return $this->qteCarbu;
}

function setMarque($marq){
	$this->marque=$marq;
}
function setCouleur($couleur){
	$this->couleur =$couleur;
}
function setKilometre($kilom){
	$this->kilometre=$kilom;
}
function setQteCarbu($qtecarb){
	$this->qteCarbu=$qtecarb;
}

function affichage(){
	echo "Le véhicule de marque ".$this->getMarque."<br>";
	echo "de couleur " .$this->getCouleur."<br>";
	echo "ayant un kilometrage de : " .$this->getKilometre."<br>";
	echo "contient " .$this->getQteCarbu."<br>";
}

function arret(){
	if($this->etat=true)
	$this->etat=false;
	echo "le vehicule est à l'arret </br>";
}

function roule(){
	if($this->etat == false){
		$this->etat = true;
		$this->kilometre++;
		$this->qteCarbu--;
	}
}
};
?>


//exercice 3 

class Voiture extends Vehicule{

var $typeCarbu;
var $nbPorte;

};

class Train extends Vehicule{

var $type;
var $nbWagon;

};