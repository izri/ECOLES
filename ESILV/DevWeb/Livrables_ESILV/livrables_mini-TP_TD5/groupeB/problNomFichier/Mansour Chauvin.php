<?php
class Vehicule {
	var $marque;
	var $couleur;
	var $kilometres;
	var $qteCarburant;
	

	function Vehicule(){
//recuperer le nombre de paramètres en arguments


	$nb=func_num_args();
//l'ensemble des arguments
	$arguments=func_get_args();


switch($nb)

{

case 0: $this->marque="t";//constructeur par défaut
$this->couleur="b";
$this->kilometre="0";
$this->qteCarburant="0";
break;

case 4: $this->marque=$arguments[0];//constructeur paramétré
$this->couleur=$arguments[1];
$this->kilometre=$arguments[2];
$this->qteCarburant=$arguments[3];
break;

default: echo"erreur"; 
break;

}}	

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
	return $this->qteCarburant;
}
function setMarque($marq){
	$this->marque=$marq;
}
function setCouleur($col){
	$this->couleur=$col;
}
function setKilometre($kil){
	$this->kilometre=$kil;
}
function setQteCarbu($qte){
	$this->qteCarburant=$qte;
}
function affichage(){
echo "la vehicule de marque "	.$this->marque ." de couleur "
.$this->couleur ." ayant un kilometrage de : " .$this->kilometre ." contient " .$this->qteCarburant ."</br>";
}
function arret(){
	if($this->etat == true) $this->etat=false;
	else 
	echo" le vehicule est à l'arret </br>";
}
function roule(){
	if($this->etat == false){
		$this->etat=true;
		$this->kilometre++;
		$this->qteCarburant--;
	}
}

}


//classe fille Voiture
class Voiture extends Vehicule{
	var $carburant;
	var $Nbportes;

function Voiture(){
//recuperer le nombre de paramètres en arguments
	$nb=func_num_args();
//l'ensemble des arguments
	$arguments=func_get_args();


	
	switch($nb)

{	

case 0: //constructeur par défaut
$this->Nbportes="2";
$this->carburant="diesel";
break;

case 2: 
$this->Nbportes=$arguments[0];//constructeur paramétré
$this->carburant=$arguments[1];
break;

default: echo"erreur"; 
break;

}
}

function getNbportes(){
	return $this->Nbportes;
}
function getCarburant(){
	return $this->carburant;
}
function setNbportes($nbp){
	$this->Nbportes=$nbp;
}
function setCarburant($car){	
	$this->carburant=$car;
}
function affichage(){
	
	echo " la voiture possède " .$this->Nbportes ." portes et son carburant est " .$this->carburant . "</br>"	;
}

}



//classe fille Train
class Train extends Vehicule{     
	var $type;
	var $Nbwagons;

function Train(){
//recuperer le nombre de paramètres en arguments
	$nb=func_num_args();
//l'ensemble des arguments
	$arguments=func_get_args();

		
		switch($nb)

{

case 0: //constructeur par défaut
$this->type="RER";
$this->Nbwagons="1";
break;

case 2 :
$this->type=$arguments[0];//constructeur paramétré
$this->Nbwagons=$arguments[1];
break;

default: echo"erreur"; 
break;

}
}
function getType(){
	return $this->type;
}

function getNbwagons(){
	return $this->Nbwagons;
}

function settype($typ){
	$this->type=$typ;
}

function setNbwagons($nbw){
	$this->Nbwagons=$nbw;
}
function affichage(){
	echo " le train possède " .$this->Nbwagons ." portes et son type est " .$this->type . "</br>"	;
}

}


$Lambo = new Voiture("2","diesel");
$Lambo->affichage();
$Lambo= new Vehicule("lamborghini","noire","100","50");	
$Lambo->affichage();

$Ferrari = new Voiture("4","gasoil");
$Ferrari->affichage();
$Ferrari = new Vehicule("ferrari","rouge","500","40");
$Ferrari->affichage();

$RERA = new Train("Rer","2");
$RERA->affichage();
$RERA= new Vehicule("RER","gris","100000","100");
$RERA->affichage();

$TGV= new Train("TGV","10");
$TGV->affichage();
$TGV= new Vehicule("TGV","gris","200000","100");
$TGV->affichage();

$tableau= array($Lambo,$Ferrari,$RERA,$TGV);
print_r($tableau);






?>
