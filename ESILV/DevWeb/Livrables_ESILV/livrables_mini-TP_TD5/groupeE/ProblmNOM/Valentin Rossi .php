<html>

<meta charset="utf-8"/>
<body>

<?php

//exercice 2: Classe Voiture

class Vehicule
{

	var $marque;
	var $couleur;
	var $kilometre;
	var $qtcarbu;

	function Vehicule()
	{

		$num=func_num_args();
		$arguments=func_get_args();

			switch($num){

			case 0:
			$this->marque="";
			$this->couleur="";
			$this->kilometre="";
			$this->qtcarbu="";
			break;

			case 5:
			$this->marque=$arguments[0];
			$this->couleur=$arguments[1];
			$this->kilometre=$arguments[2];
			$this->qtcarbu=$arguments[3];
			$this->roule=$arguments[4];
			break;

			default: echo "erreur";
			break;
		}

	}

      function arret()
      {
       	$this->roule=0;
       }

        function roule()
       {

       	$this->kilometre++;
       	$this->qtcarbu--;
       	$this->roule=1;
     
       }

    function affichage()
    {

       	echo "le véhicule de marque ".$this->marque."</br>",
       	"de couleur ".$this->couleur."</br>","ayant roulé "
       	.$this->kilometre." km après un plein</br>","contient "
       	.$this->qtcarbu."L de 
       	carburant. </br>";

    }  

    


}

//implémentation exercice 2
$Voiture=new Vehicule("KIA","noir",6000,80,5);
$Voiture->roule();
$Voiture->arret();
$Voiture->affichage();
	
//exercice 3

//classe Voiture
class Voiture extends Vehicule
{

	var $typecarburant;
	var $nbporte;

	function __construct() 
    {

		$num=func_num_args();
		$arguments=func_get_args();

		switch($num)
		{
			case 0:
				$this->marque="";
				$this->couleur="";
				$this->kilometre="";
				$this->typecarburant="";
				$this->qtcarbu="";
				$this->nbporte="";
				break;

			case 5:
			$this->marque=$arguments[0];
			$this->couleur=$arguments[1];
			$this->kilometre=$arguments[2];
			$this->qtcarbu=$arguments[3];
			$this->roule=$arguments[4];
			break;
    		
    		case 7:
    		$this->marque=$arguments[0];
			$this->couleur=$arguments[1];
			$this->kilometre=$arguments[2];
			$this->qtcarbu=$arguments[3];
			$this->roule=$arguments[4];
    		$this->typecarburant=$arguments[5];
			$this->nbporte=$arguments[6];
			break;

			default:
			echo"erreur";
			break;
		}

	 function affichage()
		{

			parent::affichage();
			echo"la voiture fonctionne grace au carburant suivant: "
			.$this->typecarburant. "et possède "
			.$this->nbporte." nombre de portes<br>";
		}
	}
}

//classe Train

class Train extends Vehicule
{
	var $type;
	var $nbwagons;


	function __construct()
	{
		$num=func_num_args();
		$arguments=func_get_args();


		switch($num)
		{
			case 0:
			$this->marque="";
			$this->couleur="";
			$this->kilometre="";
			$this->qtcarbu="";
			$this->type="";
			$this->nbwagons="";
			break;
			

			case 3:
			$this->marque=$args[0];
			$this->couleur=$args[1];
			$this->kilometre=$args[2];
			$this->qtcarbu=$args[3];
			$this->roule=$args[4];
			break;


			case 6:
			$this->marque=$args[0];
			$this->couleur=$args[1];
			$this->kilometre=$args[2];
			$this->qtcarbu=$args[3];
			$this->roule=$args[4];
			$this->type=$args[5];
			$this->nbwagons=$args[6];
			break;

			default:
			echo"erreur";
				break;
		}
	}

	function affichage()
	{
		Vehicule::affichage();
		echo"Le type du train est ".$this->type." qui contient"
		.$this->nbwagons." wagons<br>";
	} 	
}

//Implémentation exercice 3:


$T = new Train("métro","Vert, Blanc",70000,1500,0,"Electrique",5);
$T->roule();
$T->affichage();

$V = new Voiture("Ferrari","Noir",80000,45,0,"Essence",2);
$V->roule();
$V->affichage();


//exercice 4

$V1 = new Voiture("Porsche","Rouge",10000,150,0,"Diesel",2);
$V1->roule();

$T1 = new Train("TGV","Bleu",600000,7000,0,"Electrique",4);
$T1->roule();

$tableau= array(1=>$V1,2=>$T1);

for ($i=1; $i < 2; $i++) 
{ 
	echo $tableau[1]->affichage();
	echo $tableau[2]->affichage();
}

?>

</body>

</html>	




		
	    
	











