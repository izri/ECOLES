// Fonction qui renvoie 1 si un indice de performance est stabilisée, 0 sinon
// Remarques : * i permet d'accéder dans le tableau à l'indice de performance qu'on veut tester
//			   * (i+1)%1001 permet d'accéder à la valeur qu'avait l'indice de performance 1000 clients servis AUPARAVANT
int est_stable(double tab[1001], int i)
{
	int res;
	
	if(tab[(i+1)%1001] == -1) // on a pas encore servi assez de client pour savoir si stable ou pas
		res = 0;
	else
	{
		if(tab[i] != 0)
		{
			if( (fabs( (tab[(i+1)%1001] - tab[i]) ) / tab[i]) < 0.00001)
				res = 1;
			else
				res = 0;
		}
		else // Cas particulier : tab[i] == 0
		{
			if(tab[(i+1)%1001] == tab[i])
				res = 1;
			else
				res = 0;
		}
	}
	return res;
}
