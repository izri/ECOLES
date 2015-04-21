<?php
echo "<h1> Mini-TP: classe mère et classes filles (TP5 Exercices 2, 3 et 4) </h1>";
//Exercice 2

//Classe Vehicule
class Vehicule{
//Attributs
var $marque;
var $couleur;
var $kilometres;
var $qteCarburant;
var $mouv=false;

//Constructeurs
function Vehicule(){ // ou function __construct()
$num=func_num_args(); //récupère le nombre d'arguments envoyés au constructeur
$arguments=func_get_args(); //récupère l'ensemble des arguments envoyés au constructeur

switch($num){
//Constructeur par défaut
case 0:
$this->marque="";
$this->couleur="";
$this->kilometres=0;
$this->qteCarburant=0;
$this->mouv=false;
break;

case 5:
$this->marque=$arguments[0];
$this->couleur=$arguments[1];
$this->kilometres=$arguments[2];
$this->qteCarburant=$arguments[3];
$this->mouv=$arguments[4];
break;

default: echo "Erreur </br>";
break;
}
}

//Méthodes
function affichage(){
echo "Marque du véhicule: ".$this->marque."</br>";
echo "Couleur: ".$this->couleur."</br>";
echo "Kilomètres: ".$this->kilometres."</br>";
echo "Quantité de carburant: ".$this->qteCarburant."</br>";
}

function arret(){
if($this->mouv==false) echo "Arrêt du véhicule </br>";
}

function roule(){
if($this->mouv==true){
$this->kilometres++;
$this->qteCarburant--;
echo "Vehicule en mouvement </br>";
}
}
} //fin de la classe Vehicule


//Exercice 3
//Classe Voiture
class Voiture extends Vehicule{
//Attributs
var $typeCarburant;
var $nbre_portes;

//Constructeurs
function Voiture(){
$num=func_num_args();
$args=func_get_args();

switch($num){
case 0:
$this->marque="";
$this->couleur="";
$this->kilometres=0;
$this->qteCarburant=0;
$this->mouv=false;
$this->typeCarburant="";
$this->nbre_portes=0;
break;

case 7:
$this->marque=$args[0];
$this->couleur=$args[1];
$this->kilometres=$args[2];
$this->qteCarburant=$args[3];
$this->mouv=$args[4];
$this->typeCarburant=$args[5];
$this->nbre_portes=$args[6];

break;

default: echo "Erreur </br>";
break;
}
}

//Méthodes
function affichage(){
parent::affichage();
echo "Type de carburant: ".$this->typeCarburant."</br>";
echo "Nombre de portes: ".$this->nbre_portes."</br>";
}
} //fin de la classe Voiture

//Classe Train
class Train extends Vehicule{
//Attributs
var $type;
var $nbre_wagons;

//Constructeurs
function Train(){
$num=func_num_args();
$args=func_get_args();

switch($num){
case 0:
$this->marque="";
$this->couleur="";
$this->kilometres=0;
$this->qteCarburant=0;
$this->mouv=false;
$this->type="";
$this->nbre_wagons=0;
break;

case 7:
$this->marque=$args[0];
$this->couleur=$args[1];
$this->kilometres=$args[2];
$this->qteCarburant=$args[3];
$this->mouv=$args[4];
$this->type=$args[5];
$this->nbre_wagons=$args[6];
break;

default: echo "Erreur </br>";
break;
}
}

//Méthodes
function affichage(){
parent::affichage();
echo "Type de train: ".$this->type."</br>";
echo "Nombre de wagons: ".$this->nbre_wagons."</br>";
}
} //fin de la classe Train


//Exercice 4
echo "<h2> Exercice 4 </h2>";
//Création des instances/objets
$vehicule=new Vehicule("VTT","Bleu Ciel",2,0,true);
$voiture=new Voiture("MINI","Rouge",40000,100,false,"Essence",2);
$train=new Train("TGV","Gris et Bleu",360000,15000,true,"Electrique",10);

//Tableau de véhicules
$tab=array($vehicule,$voiture,$train);

//Affichage du tableau
for($i=0; $i<count($tab); $i++){
current($tab[$i]);
echo $tab[$i]->affichage();
echo $tab[$i]->roule();
echo $tab[$i]->arret();
echo "</br>";
}

?>