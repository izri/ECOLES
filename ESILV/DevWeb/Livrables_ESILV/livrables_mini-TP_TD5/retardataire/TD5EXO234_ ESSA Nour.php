<html>
<head>
        <meta charset="utf-8" />
</head>		
<body>

<?php 

$A = new Vehicule("abc","Noir","00000","200"); 
$A->Affiche(); 

$B= new Voiture("abc","Noir","00000","200","essence","5"); 
$B->Affiche(); 

$C= new Train("abc","Noir","00000","200","TGV","10"); 
$C->Affiche();


class Vehicule
{
	var $Marque;
	var $Couleur;
	var $Kilometre;
	var $qteCarb; 
	
	
	function Vehicule(){
		$max=func_num_args();
		$args=func_get_args();
		switch($max){
			
			case 0: 
			$this->Marque="BMW";
			$this->Couleur="Noir";
			$this->Kilometre="1000";
			$this->qteCarb="100";
			
	
			case 4:
			$this->Marque=$args[0];
			$this->Couleur=$args[1];
			$this->Kilometre=$args[2];
			$this->qteCarb=$args[3];
			break;
			default:
			echo"ERROR";
		}
	}
		function Affiche()
		{
			echo "<br><br> La Marque du Vehicule est ". $this->Marque ."<br>  " .
			"La couleur du Vehicule est  ". $this->Couleur ."<br> ".
			"Le Vehicule a parcouru ". $this->Kilometre ." Km <br>".
			"La quantité de carburants est ". $this->qteCarb ."" ; 
		}
		
		
		function Roule($nb)
		{	
			$this->kilométres+=$nb; 
			$this->qteCarburant-=$nb; 
		}
		
		function Arret()
		{
			echo "<br>Le vehicule est en arret <br>"; 
		}
		
}


class Voiture extends Vehicule
{
	var $TypeCarb;
	var $Nbportes; 
	
	function Voiture()
	{
		$max=func_num_args();
		$args=func_get_args();
		parent::Vehicule($args[0],$args[1],$args[2],$args[3]); 
		 
		switch($max)
		{
		case 6:
		$this->TypeCarb=$args[4];
		$this->Nbportes=$args[5]; 
		break; 
		}
	}
		function Affiche()
	{
		parent::Affiche(); 
		echo"<br>Type de Carburant : ". $this->TypeCarb ."<br>".
		"Nombre de portes : ". $this->Nbportes."<br>" ; 	
	}
	
}

class Train extends Vehicule 
{
	var $Type;
	var $Nbwagons; 
	
	function Train()
	{
		$max=func_num_args();
		$args=func_get_args();
		parent::Vehicule($args[0],$args[1],$args[2],$args[3]); 
		
		switch($max)
		{ 
		case 6:
		$this->Type=$args[4];
		$this->Nbwagons=$args[5]; 
		break; 
		
		}
	}
	
	function Affiche()
	{
		parent::Affiche();
        echo"<br>Type de Train : ". $this->Type ."<br>".
		"Nombre de wagons : ". $this->Nbwagons."<br>"		; 		
	}
	
}

?>

</body>

</html>