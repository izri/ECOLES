<?php
//MINI-TP TD5 DINA MAZLOUM 
//Exercice 2 
//----------

class Vehicule{
//attributs
var $marque;
var $couleur;
var $kilometre;
var $qtecarbu;
var $mouv=false;

function __construct()
{
$num=func_num_args();
$arguments=func_get_args();

switch($num)
{ case 0:
$this->marque="t";
$this->couleur="b";
$this->kilometre=0;
$this->qtecarbu=0;
break;

case 4:
$this->marque=$arguments[0];
$this->couleur=$arguments[1];
$this->kilometre=$arguments[2];
$this->qtecarbu=$arguments[3];
break;
default:echo "erreur vehicule"; break;
}
}

function affichage (){
echo " le vehicule de marque".$this->marque. "de couleur " .$this->couleur ."ayant roule" .
$this->kilometre. "contient" .$this->qtecarbu. "</br>";
}

function arret (){
echo "le vehicule est a l'arret </br>";
if($this->mouv==false);
}

function roule(){
if($this->mouv==false)
{
$this->kilometre++;
$this->qtecarbu--;
$this->mouv=true;
echo "le vehicule est en marche</br>";

}
}
}

// Exercice3
//----------


class Voiture extends Vehicule{
var $type_carbu;
var $nb_portes;

function _construct()
{

$num=func_num_args();
$arg=func_get_args();

switch($num)
{ 
case 6:
$this-> marque= arg[0];
$this-> couleur= arg[1];
$this-> kilometre= arg[2];
$this-> qtecarbu= arg[3];
$this-> type_carbu= arg[4];
$this-> nb_portes= arg[5];
$this-> roule= arg[6];
break;

case 0:
$this->marque = "";
$this->couleur = "";
$this->kilometres = 0;
$this->qtecarbu = 0;
$this->type_carbu = "";
$this->nb_portes = 0;
$this->roule= false;
break;



default:echo "erreur voiture"; break;
}
}


function affichage(){
parent::affichage();
echo "nombre de porte dans ce vehicule:" .$this->nb_portes."</br>";
echo " type de carburant utilise dans ce vehicule:" .$this->type_carbu."</br>";
}
}


class Train extends Vehicule{
var $nb_wagon;
var $typetrain;

function _construct()
{

$num=func_num_args();
$arg=func_get_args();

switch($num)
{ case 6 :
$this-> marque= arg[0];
$this-> couleur= arg[1];
$this-> kilometre= arg[2];
$this-> qtecarbu= arg[3];
$this-> typetrain= arg[4];
$this-> nb_wagon= arg[5];
$this-> roule= arg[6];
break;

case 0 :
$this->marque = "t";
$this->couleur = "b";
$this->kilometres = 0;
$this->qtecarbu = 0;
$this->typetrain = "none";
$this->nb_wagon= 0;
$this->roule= false;
break;
default:echo "erreur Train"; break;
}
}

function affichage(){
parent::affichage();
echo "nombre de wagons dans ce train :" .$this->nb_wagon."</br>";
echo " type de train:" .$this->typetrain."</br>";
}
}


//Exerice4//

$vehicule1= new Vehicule("MG MOTORS","NOIR",0,150);
$vehicule4= new Vehicule("TOYOTA","NOIR",0,150);
$vehicule2= new Voiture("MITSUBISHI MOTORS","BLEU",10,20,"Diesel",3,true);
$vehicule5= new Voiture("LANDROVER","JAUNE",10,200,"Diesel",3,true);
$vehicule3= new Train("NC","ROUGE",105,3000,"TER",25,false);


$tab[0]=$vehicule1;
$tab[1]=$vehicule2;
$tab[2]=$vehicule3;
$tab[3]=$vehicule4;
$tab[4]=$vehicule5;


foreach($tab as $key => $value){
	echo "Vehicule ".$key."</br>";
	echo $value->affichage();
	echo "</br>";
}
?>