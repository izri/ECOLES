%created 03/07.2013 by Nora IZRI
%PRiSM Laboratory


 function [newRBCell] = modifRB(cellSouci, RBsouci,nbrUser, rbUserPrisCell, tabRB, N )  
 %rbUserPrisCell==> cell{cellSouci,1}.rbUserPris   
 %tabRB(V, N) : matrice contenant des 1 et des 0, 1 pr dire que le RB est
     %utilis�; avec V le nbre de cellule, et N le nbre de RB
     %N: nbre de RB par cellule
     % NbrUser � travers cette variable on d�termine le nbre de RB dispo
     diffRBdispo = N - nbrUser;
     if (diffRBdispo > 0 )
%          tabRBbb=[];
%          for i=1:N
%             tabRBbb=[tabRBbb, i]; 
%          end
%         %il existe encore des RB dispo, il faut changer le RBsouci
%         %puisqu'il d�grade la fct de r�compense de la cellule
%         %intersect
%       [RB_used indexC1, indexC2]= intersect(rbUserPrisCell, tabRBbb);            %indexCell1: permet d'avoir les indexes au sein de la celle q
%           if ( length(RB_used)>=1)
%               
%           end
       verif =0;
       while verif ==0
          newRBCell=randi([1, N], 1, 1);  %selectionner un RB parmis N pr chaque user 
         if (newRBCell~=RBsouci)
             idVerif=intersect(rbUserPrisCell, newRBCell);%cell{k}.rbUserPris au lieu du vecteur pris 
             if (length(idVerif) == 0) 
                 %si je suis l�,cela veut dire que le RB que je viens de
                 %choisir est dispo dans la cellule
                 verif=1;
             end
             %il ne faut oublier de mettre ca juste apr�s l'appel de cette
             %fct: cell{cellSouci,1}.rbUserPris=[cell{cellSouci,1}.rbUserPris, newRBCell];
                %ainsi que toutes les mises � jour qu'il faut au niveau des
                %users et rb pr les varaibles/parametres
         end
         
       end
         
     else 
         fprintf ('*******  erreuuuurrrr il n y a plus de RB dispo pr la cellule ----  %d  ******** \n', cellSouci);
         newRBCell=RBsouci; %pas de changement
     end
    