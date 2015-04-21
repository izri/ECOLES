<?php //Exercice 2

class Vehicule  
//Vehicule class
{
	var $range;
	var $name;
	var $options;
	var $colors;
	


	function __construct()
	//Builder function
	{ 
		$number=func_num_args();
		$args=func_get_args();

			switch ($number) 
			{
			case 0:
			//Not default
				$this->range="";
				$this->name="";
				$this->options="";
				$this->colors="";
				$this->km="";
				$this->fuelQt="";
				break;

			case 1:
			// With argues
				$this->range=$args[0];
				$this->name=$args[1];
				$this->options=$args[2];
				$this->colors=$args[3];
				$this->km=$args[4];
				$this->fuelQt=$args[5];
				$this->drive=$args[6];
				break;

			default:
			//If not display
				echo"inexact choice";

				break;
		}
	}

	function drive($kmdrive,$literkm){
		//Car is moving
		$this->drive=1;
		//Incrémentation km
		$this->km++;
		//Fuel quantity
		$this->fuel=$this->fuel-=$carbu_used;
		//Add on km
		$this->km=$this->km+=$kmdrive;
		//Fuel used per km
		$fuel_used=$kmdrive*$literkm;
	}
	
		function stop(){
			//Car is moving
		$this->drive=0;
	}

	function display(){
		//Display features
		echo"<Range of car : "$this->range;
		echo"Name of car : "$this->name;
		echo"Kilometers of car : "$this->km;

	}//End of function
	

} //End of class


// Implementation
$car = new Vehicule("Ford","Fiesta","0","Green",0,500,8);
$car->drive(20,1);
$car->stop();
$car->display();


//Exercice 3

//Train class
class Train extends Vehicule{

	var $status;
	var $wagon;


	function __construct()
	{

		$number=func_num_args();
		$args=func_get_args();

		switch ($number) 
		{
			case 2:
				$this->range=$args[0];
				$this->name=$args[1];
				$this->options=$args[2];
				$this->drive=$args[3];
				$this->status=$args[4];
				$this->wagon=$args[5];
				$this->color=$args[6];
				break;
			
			case 0:
				$this->range="";
				$this->name="";
				$this->km="";
				$this->fuelType="";
				$this->satus="";
				$this->wagon="";
				break;
			
			case 1:
				$this->range=$args[0];
				$this->name=$args[1];
				$this->fuelType=$args[2];
				$this->km=$args[3];
				$this->drive=$args[4];
				break;

		}

	}
		
}

class Car extends Vehicule{
	//Car class

	var $fuelType;
	var $nbDoor;

	function __construct() //Builder function
	{
		$number=func_num_args();
		$args=func_get_args();
						
		switch ($number) {
			
			
			
			//Not default
			case 0:
				$this->range="";
				$this->name="";
				$this->options="";
				$this->color="";
				$this->fuelType="";
				$this->nbDoor="";
			    $this->km="";
			    $this->fuelQt="";
				break;
			
			case 1: //With argues
				$this->rangee=$args[0];
				$this->name=$args[1];
				$this->km=$args[2];
				$this->options=$args[3];
				$this->drive=$args[4];
				break;

			case 2:
				$this->range=$args[0];
				$this->name=$args[1];
				$this->km=$args[2];
				$this->color=$args[3];
				$this->drive=$args[4];
				$this->fuelType=$args[5];
				$this->nbDoor=$args[6];
				break;

			default:
				echo"inexact choice";
				break;
		}

	}
			

			function display(){
			//Display nbDoor and fuelType
		echo"Type of fuel : "$this->fuelType;
		echo"Nomber of doors : "$this->nbDoor;
	}	
}



$Vehicule = new Voiture("Peugeot","206",0,"Green",0,0,"Essence",5);
$Vehicule->drive(0,0);
echo"<h4>Train</h4>";

$Train = new Train("Alstom","66486","Classe1",55000,"TER",10,50,"blanc");
$Train->drive(0,0.0);


//Exercice 4

//Table
$table= array(1=>$car1,2=>$train1);

for ($i=1; $i < 2; $i++) { 
echo"<h1>Car</h1>";
	echo $table[1]->display();
	echo"<h1>Train</h1>";
	echo $table[2]->display();
}

//End of program
?> 