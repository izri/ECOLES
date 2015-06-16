#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <iostream>
#include <string>



class Produit {

	public :
		Produit(std::string name, float price);
        const std::string get_name();
        const float get_price();
		void afficher();
		/*string to_string() const;*/

    private :
		std::string m_nom;
		float m_prix;
};


#endif // PRODUCT_HPP
