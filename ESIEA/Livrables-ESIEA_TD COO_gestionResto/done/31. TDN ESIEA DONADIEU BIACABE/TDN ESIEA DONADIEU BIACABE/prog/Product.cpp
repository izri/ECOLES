#include "Product.h"



Product::Product(){
this->com = 5;
}
unsigned int Product::Infoproduit()
{
   std::cout<<"Quelle est votre commande pour une pizza entrer 0, pour un PJ 1, pour un PV 2, pour un dessert 3, pour une boisson 4 "<<endl;
   std::cin>> this->com;
   std::cout<<"Vous avez choisis"<<std::endl;
   switch(this->com)
   {


   case 0: {
          std::cout<<"Une Pizza"<<std::endl;
           break;
      }

   case 1: {
          std::cout<<"Un Plat du Jour"<<std::endl;
           break;
      }

   case 2: {
          std::cout<<"Un Plat Vegetarien"<<std::endl;
           break;
      }

   case 3: {
          cout<<"Un dessert"<<std::endl;
           break;
      }

   case 4: {
          cout<<"Une boisson"<<endl;
           break;
      }
      default:
          {
           cout<<"Produit non reconnu"<< endl;
           exit(0);
           }

   }
   return com;
}
