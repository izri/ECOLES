<?php

#EXERCICE1

class Commande

{
	
	var $nomClient;
	
	var $facture;
	
	var $commande=array(0,0,0,0,0); 
//$commandes: (0,1,0,3,0)
	
//=>le client aura commande 1 plat du jour et 3 boissons.
	
	var 
$prixParCategorie=array(5,5,6,2,18); 
//ici, prix_pizza=5 euros etc..

	
		function __construct()
	
		{

			$num=func_num_args(); 
		//ca renvois le nombre d'arguments
		
			$args=func_get_args(); 
		//cela retourne un tableau avec les arguments
		

			switch ($num)
		
			{


		case 0:
	
			$this->nomClient="Charlie";

				//$this->facture=0;

				break;
			
		case 1:
			    
			$this->nomClient=$args[0];
			    
			break;
			
			default:
	echo "error";

				break;
	   
 			}

		}

	
		
		function calculerFacture()
	
		{

			foreach($this->commande as $key => $value) 
			//$key="indice" du tableau

			$this->facture+=$this->commande[$key]*$this->prixParCategorie[$key];
			//commandes[$key] donne le nombre de plats commandés que l'on multiplie au prix du plats(prixParCategorie[$key])
	       
			//le résultat est ajouté à facture actuelle
	
		}

	
			/*function commanderPizza($nbre)
	
			{
		$this->commandes[0] += $nbre;
	
			}
	

			function faireCommande($nbPizza, $nbPlatduJour, $nbRepasV, $nbBoisson, $nbDessert)

			{
		
				$this->commande[0]+=$nbPizza;
		
				$this->commande[1]+=$nbPlatduJour;
			
				$this->commande[2]+=$nbRepasV;
		
				$this->commande[3]+=$nbBoisson;
		
				$this->commande[4]+=$nbDessert;
	
			}

	

			function afficher()
	
			{
		
				echo "<hr><br>";
		
		echo "Nom du client: ".$this->nomClient."<br>";
	
				echo "si a une commande: <br> ";
		
				echo $this->commande[0]." pizza<br>";
		
				echo $this->commande[1]." plat du jour<br>";
		
				echo $this->commande[2]." repas végétarien<br>";
		
				echo $this->commande[3]." boisson<br>";
		
				echo $this->commande[4]." dessert<br>";
		
				echo "Facture: ".$this->facture." euros <br><hr>";
	
			}


		
		}

		$monObjet=new Commande();
		
$monObjet->afficher();
		
$firstCommande=new Commande("Jack");
		
$firstCommande->faireCommande(0,1,0,3,0);	

		$firstCommande->calculerFacture();
		
$firstCommande->afficher();

		
		
		?>

		
<?php



#EXERCICE2

class Vehicule

{
	
		var $marque;

		var $couleur;

		var $kilometres;
    
		var $qteCarburant;
    
		var $roule=0; //si==0 alors ne roule pas.
    
		var $etat;
    //var $TypeCarburant;
    //var $nbPorte;

	

		function __construct()
	
		{
		
			$num=func_num_args();
		
			$args=func_get_args();
		
			switch ($num) 
		
			{
			

			case 4:
				
			$this->marque=$args[0];
				
			$this->couleur=$args[1];

			$this->kilometres=$args[2];

			$this->qteCarburant=$args[3];

			$this->etat="Arrêt";
				
				
			break;
			
			
			default:
 echo "Error";
				
			break;
		
			}
	
		}

	

		function afficher()
	
		{
		
			echo "<hr><br>";
		
			echo "Marque: ".$this->marque."<br>";
		
			echo "Couleur: ".$this->couleur."<br>";
		
			echo "Kilométrage de la voiture: ".$this->kilometres." Km <br>";
	
			echo "Quantité de carburant: ".$this->qteCarburant." Litres <br>";
		
			echo "État du véhicule: ".$this->etat."<br>";
	
		}

	

		function arret()
	
		{
		
			if( $this->roule==0)
		
			{
				
				echo "Ce véhicule est à l'arrêt.";
		
			}
		
			else
		
			{
			
				echo "Ce véhicule roule.";
		
			}
	
		}

	
			
			
		function roule()
	
		{
		$this->etat="Roule.";

				$this->kilometres++;
		
				$this->qteCarburant--;
	
		}

}




class Voiture extends Vehicule

{
	
	var $TypeCarburant;
	
	var $nbPorte;

	

	function __construct()
	
	{
			
		$num=func_num_args();
			
		$args=func_get_args();
			
		switch ($num) 
			

	{
				
		case 6:
				   
		 $this->marque=$args[0];
	
		 $this->couleur=$args[1];
				    
		 $this->kilometres=$args[2];
				    
		 $this->qteCarburant=$args[3];
				    
		 $this->etat="Arrêt";
					
		 $this->TypeCarburant=$args[4];
					
		 $this->nbPorte=$args[5];
					
		 break;
				
				

		default:
					
		echo "Error";
					
		break;
			
	}
	
	
	}

	

	function afficher()
	
	{
		echo "<br>";

			parent::afficher();
		
			echo "Type de carburant: ".$this->TypeCarburant."<br>";
	    
			echo "Nombre de portes: ".$this->nbPorte."<br>";
    
	}

}




class Train

{
	
	var $Type;
	
	var $nbWagons;

	

	function __construct()
	
	{
		
		$num=func_num_args();
		
		$args=func_get_args();
		
		switch ($num) 
		
		{
			
		
			case 2:
			 
				$this->Type=$args[0];
			    
				$this->nbWagons=$args[1];
			    
				break;
				
			
				default:
			   
				echo "Error"; //si mauvais nombre d'arguments.
			    
				break;
		
		}
	
	}

	

	function afficher()
	
	{
		
		echo "<hr><hr>";
		
		echo "Ce train est de type: ".$this->Type."<br>";
		
		echo "Ce train comporte ".$this->nbWagons." wagons. <br><hr>";
	
	}

}





$myVehi=new Vehicule("Fiat", "Noire", 14000, 60);

$myVehi->afficher();

$myVehi->roule();

$myVehi->arret();

$myVoit=new Voiture("Toyota", "Rose", 14000, 35, "Hybride",3);

$myVoit->afficher();

$myVoit->roule();

$myVoit->arret();

$myTrain=new Train("Rer",13);

$myTrain->afficher();

$myTab = array($myVehi, $myVoit, $myTrain);
	

	foreach ($myTab as $key => $value) 

	{
		
		$value->afficher();
	
	}
	


?>









