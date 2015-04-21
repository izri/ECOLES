<?php
class Vehicule{
//attributs
var $Marque;
var $Couleur;
var $Kilometre;
var $QteCarburant;
var $etat = false;
//constructeurs
function Vehicule(){ //surcharge de méthodes
//recuperer le nombre de paramètres en arguments
$nb = func_num_args();
//l'ensemble des arguments
$arguments = func_get_args();

switch($nb)
{
case 0: //constructeur par défaut
		$this->Marque="Audi";
		$this->Couleur="noire";
		$this->Kilometre=90000;
		$this->qteCarburant=22;break;
case 4:	$this->Marque=$arguments[0];
		$this->Couleur=$arguments[1];
		$this->Kilometre=$arguments[2];
		$this->qteCarburant=$arguments[3];break;
default: echo "erreur"; break;
}
}
//méthodes Getter et Setter
function getMarque(){
return $this->Marque;
}
function getCouleur(){
return $this->Couleur;
}
function getKilometre(){
return $this->Kilometre;
}
function getqteCarburant(){
return $this->qteCarburant;
}

function setMarque($marq){
$this->Marque=$marq;
}
function setCouleur($col){
$this->Couleur=$col;
}
function setKilometre($kilo){
$this->Kilometre=$kilo;
}
function setqtCarburant($carb){
$this->$this->qteCarburant=$carb;
}
function affichage(){
$affi = array($this->getMarque(),$this->getCouleur(),$this->getKilometre(),$this->getqteCarburant());
echo "Le véhicule de marque : " .$affi[0]."</br>";
echo "De couleur : " .$affi[1]."</br>";
echo "Ayant : ".$affi[2]." kilometres</br>";
echo "Et ayant une quantité de carburant de : " .$affi[3]." litres </br>";
}
function arret(){
if($this->etat==true)
{
$this->etat=false;
echo "le véhicule est a l'arret </br>";
}
}
function roule(){
if($this->etat == false){
$this->etat =true;
$this->Kilometre++;
$this->qteCarburant--;
}
}
}
class Voiture extends Vehicule{
//attributs
var $TypeCarburant;
var $NbrePortes;
//constructeurs
function Voiture(){ 
parent::Vehicule();
$nb1 = func_num_args();
//l'ensemble des arguments
$arguments1=func_get_args();
switch($nb1)
{
case 0: //constructeur par défaut
		$this->TypeCarburant="Essence";
		$this->NbrePortes=5;
		break;
case 2:	$this->$this->TypeCarburant=$arguments1[0];
		$this->NbrePortes=$arguments1[1];
		break;
default: echo "erreur"; break;
}
}
//méthodes Getter et Setter
function getTypeCarburant(){
return $this->TypeCarburant;
}
function getNbrePortes(){
return $this->NbrePortes;
}

function setTypeCarburant($Tcarb){
$this->TypeCarburant=$Tcarb;
}
function setNbrePortes($portes){
$this->NbrePortes=$portes;
}

function affichage1(){
parent::affichage();
echo "Est une voiture de type : " .$this->getTypeCarburant()."</br>";
echo "Qui possède : " .$this->getNbrePortes()." portes </br>";
echo "</br>";
}
}
class Train extends Vehicule{
//attributs
var $Type;
var $NbreWagons;
//var $ListeTrain=array(0,0);
//constructeurs
function Train(){ 
$nb2 = func_num_args();
//l'ensemble des arguments
$arguments2=func_get_args();
switch($nb2)
{
case 0: //constructeur par défaut
		$this->Type="TGV";
		$this->NbreWagons=12;break;
case 2:	$this->$this->Type=$arguments2[0];
		$this->NbreWagons=$arguments2[1];break;
default: echo "erreur"; break;
}
}
//méthodes Getter et Setter
function getType(){
return $this->Type;
}
function getNbreWagons(){
return $this->NbreWagons;
}

function setType($T){
$this->Type=$T;
}
function setNbreWagons($wagons){
$this->NbreWagons=$wagons;
}
function affichage2(){
//parent::affichage();
$aff = array($this->getType(),$this->getNbreWagons());
echo "Le train est un : ".$aff[0]."</br>";
echo "Qui possède : ".$aff[1]." wagons </br>";
echo "</br>";
}
}
//création des instances
$voiture = new Voiture();
$voiture-> setTypeCarburant("diesel");
$voiture-> setNbrePortes("3");

$train = new Train();
$train-> setType("RER");
$train-> setNbreWagons("25");

//affichage des informations
$voiture-> affichage1();
$train-> affichage2();
?>