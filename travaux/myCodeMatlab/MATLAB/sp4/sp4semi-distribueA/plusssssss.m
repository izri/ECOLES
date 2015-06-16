%RB_Cellll=setdiff(cell{q,ta}.rbUserPris,  cellRBcommon{q}, 'stable');

%%%%%%%%%%%%%%%  A RENDRE PLUS TARD
%RB_Cellll=setdiff(affectionINIT{q}, rbPROBLM{q}, 'stable'); %27/09 ==> je prend en compte la première affectation avec les rb que j'ai retiré pr avoir l'ensemble des rbs ou il faut leur recalculer

%   if (length(RB_Cellll) > 0)
%       %revéfier
%      % disp('******');
%         for uuRB=1:length(RB_Cellll)
%              rb_A=RB_Cellll(uuRB); 
%              sumDist=0;
%              for ttapa=1:length(cell{q,ta}.voisins)
%                voisinns=cell{q,ta}.voisins(ttapa);
%                okuRBa =  intersect(cell{voisinns,ta}.rbUserPris, rb_A) ; %indexe de l user utilisant le wwRbConfli
%                if (length(okuRBa)==1)
%                  sumDist=sumDist + cell{voisinns,ta}.RB(okuRBa).puissance * ((1/ cell{voisinns,ta}.RB(okuRBa).dist)^beta); %on peut egalement passer par l user
%                  %premiere etape: calculer les SINR     
%                end  
%              end
%              
%                   cell{q,t}.RB(rb_A).SINR = calculSINR(cell{q,ta}.RB(rb_A).dist, sumDist, PuisUsed(q,rb_A), beta, noise);
%              %  fprintf('--------------- t=%g\t\t q=%g\t\t RB=%g \t \t SINR =%f  \n',t,q, rb_aaA, cell{q,t}.RB(rb_aaA).SINR);
%                  %30/08 
%                   cell{q,t}.RB(rb_A).Throughput = W * abs(log2(1 + cell{q,t}.RB(rb_A).SINR));
%                   cell{q,1}.cumulDebit=cell{q,1}.cumulDebit+cell{q,t}.RB(rb_A).Throughput; %20/08            
%                   Mat(t).qValue(q,rb_A)=W*abs(log2(1+cell{q,t}.RB(rb_A).SINR)); %fct QValue 
%               %26/09 ==> obligatoire de garder en sauvegarde la valeur
%               %précédente de la fct d'apprentissage
%                   valINIT= Mat(t).apprentissageRB(q,rb_A);
%                   Mat(t).apprentissageRB(q,rb_A)=cell{q,ta}.probCollision * Mat(t).qValue(q,rb_A); %fct d'apprentissage
% 
%                     if (t==1)  
%                          Mat(t).gainCell(q)=0;
%                          Mat(t).sinrCell(q)=0;
%                          Mat(t).apprentiCell(q)=0;
% 
%                          Mat(t).apprentiCellALL(q)=0;
%                          Mat(t).gainCellAll(q)=0;
%                          Mat(t).sinrCellAll(q)=0;
% 
%                          Mat(t).gain(q,rb_A)= Mat(t).apprentissageRB(q,rb_A);
%                          Mat(t).gainTotal(q,rb_A) = Mat(t).gain(q,rb_A); %Mat(t).gainTotal(q,rb_A) + 
%                          diffGainTotal(rb_A) = Mat(t).gain(q,rb_A);% - Mat(t-1).gainTotal(q,wwRbConfli);
%                          diffGainTotal(rb_A) = Mat(t).qValue(q,rb_A);% - Mat(t-1).gainTotal(q,wwRbConfli);
%         
%                               else
%                   
%                          Mat(t).gain(q,rb_A)= abs( Mat(t).apprentissageRB(q,rb_A) - valINIT);
%                           % Mat(t).gainTotal(q,rb_aA)=0;
%                          valINITTTT=Mat(t).gainTotal(q,rb_A);
%                          Mat(t).gainTotal(q,rb_A) = valINITTTT + Mat(t).gain(q,rb_A);
% 
%                     %% fprintf(2, ' ******************** %d \t \t %g \t %g \t %g \t %g \n', t,   Mat(t-1).gainTotal(q,rb_aaA), Mat(t).gain(q,rb_aaA),Mat(t-1).gain(q,rb_aaA), Mat(t).gainTotal(q,rb_aaA));
%                         diffGainTotal(rb_A) = Mat(t).gain(q,rb_A)- Mat(t-1).gain(q,rb_A); 
%                         valinitVa=Mat(t).qValue(q,rb_A);
%                         diffGainTotal(rb_A) = Mat(t).qValue(q,rb_A)- valinitVa; 
% 
%                      end
%         
%              initGain=gainTotalCell(q,rb_A);
%              gainTotalCell(q,rb_A)=Mat(t).gainTotal(q,rb_A); %Mat(t).gainTotal(q,rb_aaA);
%            
%              
%              
%              %%%%%%%%27/09
%              gainTotalCell(q,rb_A)=Mat(t).gain(q,rb_A); %Mat(t).gainTotal(q,rb_aaA);
%              gainGlobal(q, COUNT) = max(0, gainGlobal(q, COUNT) - initGain + gainTotalCell(q,rb_A));
%         end
%   end


%%%%%%%%%%%%%%% FIN DU A RENDRE