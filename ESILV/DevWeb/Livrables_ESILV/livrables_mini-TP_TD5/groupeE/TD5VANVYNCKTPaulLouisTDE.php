<?php // TD5 EXERCICES 2,3 et 4 Paul Louis VAN VYNCKT

//localhost/mesfichiers
//Exercice 2: Classe véhicule

// classe Vehicule
class Vehicule{//attributs
	
        var $marque;
	var $couleur;
	var $km;
	var $carburant;

// constructeur
function __construct(){
		$num=func_num_args();
                $args=func_get_args();

			switch ($num) 
			{
                         case 0:
				$this->marque="";
				$this->couleur="";
				$this->km="";
				$this->carburant="";
				break;
                         case 5:
				$this->marque=$args[0];
				$this->couleur=$args[1];
				$this->km=$args[2];
				$this->carburant=$args[3];
				$this->roule=$args[4];
				break;
                        default:
				echo"Stop";
				break;}
	}

// Méthode arrêt 
function arret(){
		$this->roule=0;
                }
	
//Méthode roule 
function roule($kmroule,$litreaukm){
		
		$carbu_used=$kmroule*$litreaukm;
		$this->roule=1;
		$this->km=$this->km+=$kmroule;
		$this->km++;
		$this->carburant=$this->carburant-=$carbu_used;
	                            }
	
//Méthode affichage 
function Affichage(){
		echo"<font color=red>Marque du véhicule : ".$this->marque."<br>";
		echo"Couleur du véhicule : ".$this->couleur."<br>";
		echo"Kilométrage du véhicule : ".$this->km."<br>";
	

	 if ($this->carburant > 20) {
    echo "Quantité de carburant: ".$this->carburant."</font><br>";
} elseif (($this->carburant < 20) && ($this->carburant > 0)) {

    echo "Quantité de carburant: </font><strong><font color=blue> Il reste seulement ".$this->carburant." litres, faites attention </strong></font><br>";
}  elseif ($this->carburant <= 0) {

    echo "Quantité de carburant:  </font><strong><font color=blue> Plus de carburant pour le véhicule</strong></font><br>";
}  else {

    echo"Quantité de carburant : </font><strong><font color=blue>Plus de carburant pour le véhicule</strong></font><br>";
}
		
	}
	

} 

echo"<h3><u> Résultats</u></h3>";

$voiture = new Vehicule("Opel","Green",20000,60,0);
$voiture->roule(20,1);
$voiture->arret();
$voiture->Affichage();

echo"<br>";
echo"<br>";
echo"<br>";






//Exercice 3: création de Voiture et Train 

//classe Voiture
class Voiture extends Vehicule{

//attributs 	
var $typeCarburant;
var $nbPorte;

//constructeur
function __construct(){
	$num=func_num_args();
$args=func_get_args();
						
		switch ($num) {
			
			case 0:
				$this->marque="";
				$this->couleur="";
				$this->km="";
				$this->carburant="";
				$this->typeCarburant="";
				$this->nbPorte="";
				break;
			case 5:
				$this->marque=$args[0];
				$this->couleur=$args[1];
				$this->km=$args[2];
				$this->carburant=$args[3];
				$this->roule=$args[4];
				break;
                        case 7:
				$this->marque=$args[0];
				$this->couleur=$args[1];
				$this->km=$args[2];
				$this->carburant=$args[3];
				$this->roule=$args[4];
				$this->typeCarburant=$args[5];
				$this->nbPorte=$args[6];
				break;
                        default:
				echo"Stop";
				break;
		}

	}
			
// méthode Affiche Voiture
function Affichage(){
				parent::Affichage();
		echo"<font color=red>Type de carburant : ".$this->typeCarburant."<br>";
		echo"Nombre de portes = ".$this->nbPorte."</font><br>";
	}//Fin de la méthode
	} 



// classe Train
class Train extends Vehicule{

//attributs 
var $type;
var $nbwagon;

function __construct(){//constructeur
		
$num=func_num_args();
$args=func_get_args();

		switch ($num) 
		{	case 0:
				$this->marque="";
				$this->couleur="";
				$this->km="";
				$this->carburant="";
				$this->type="";
				$this->nbwagon="";
				break;
			case 5:
				$this->marque=$args[0];
				$this->couleur=$args[1];
				$this->km=$args[2];
				$this->carburant=$args[3];
				$this->roule=$args[4];
				break;
                        case 7:
				$this->marque=$args[0];
				$this->couleur=$args[1];
				$this->km=$args[2];
				$this->carburant=$args[3];
				$this->roule=$args[4];
				$this->type=$args[5];
				$this->nbwagon=$args[6];
				break;

			default:
				echo"Stop<br>";
				break;
}
}
// méthode Affiche Train
function Affichage(){
			Vehicule::Affichage();
		
echo"<font color=green>Type de train : ".$this->type."<br>";
echo"Nombre de wagons : ".$this->nbwagon."</font><br>";
		
		}
}

// Implémentation 
echo"<h3><u>Résultats</u></h3>";

echo"<h4>Voiture</h4>";

$V1 = new Voiture("Opel","cascada",80000,70,0,"Essence",2);
$V1->roule(85,0.6);
$V1->Affichage();
echo"<h4>Train</h4>";

$T1 = new Train("RER C","Rouge,Bleu,Vert",55000,1500,0,"Electricité",25);
$T1->roule(3000,0.4);
$T1->Affichage();





//Exercice 4

echo"<br>";
echo"<br>";
echo"<br>";
echo"<br>";
echo"<h3><u>Résultats</u></h3>";

// On déclare 2 nouveaux véhicules : La voiture et le Train, V2 et T2
$V2 = new Voiture("Citroën","C3",200000,120,0,"essence",2);
$V2->roule(115,1.8);

$T2 = new Train("Tram 1","Bleu et Rouge",900000,70000,0,"Electrique",10);
$T2->roule(3000,0.4);



$tableau= array(1=>$V2,2=>$T2);// c'est un tableau déclaré pour les 2 véhicules


for ($i=1; $i < 2; $i++) { 
echo"<h4>Voiture</h4>";
	echo $tableau[1]->Affichage();
	echo"<br>";
	echo"<h4>Train</h4>";
	echo $tableau[2]->Affichage();
	echo"<br>";
}

?> 