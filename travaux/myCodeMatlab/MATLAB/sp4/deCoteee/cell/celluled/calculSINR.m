%created 30/05.2013 by Nora IZRI
%PRiSM Laboratory
%modfied 05/06/2013

 function [sinrUserRb] = calculSINR(distanceU, sommeDistUsersPuis,PuissanceU, beta, noise )  
     impactMe=0;  %cell{e}.user(r).dist
   % a=  (1/ cell{e}.RB(r).dist);  
     impactUsers=0;
     impactMe=PuissanceU*(1/distanceU)^beta; 
     %pr ameliorer il faudra multiplier fois un facteur associe a l impact du
     % canal et par cell{e}.RB(r).puissance au lieu de PuissanceU
     impactUsers = sommeDistUsersPuis + noise; %PuissanceU*sommeDistUsers + noise;  %j ai change la puissance 05/06/2013 car j ai mis une puissance pr chaque RB
     %cell{e}.user(r).SINR=impactMe/impactUsers;
     sinrUserRb=impactMe/impactUsers;
     
     
  % for z=1:V
  %    % user=cell{z}.user(h).puissance 
  % end
  %     impactUsers= impactUsers*PuisUsed; %actuellement on suppose que tous
  %     les users fonctionnent avec la meme puissance donc on peut mettre
  %     directement PuisMax, il faudra ameliorer ca, en permettant de
  %     recalculer l impacte des users par: impactUsers_i=
  %     somme_j^cellulesVoisines (puiss_i*dist_ij);  j = eNB et i c le RB
  %      impactUsers=sommeUsers+noise;
  %      cell{e}.user(r).SINR=impactMe/impactUsers;
       

  
  