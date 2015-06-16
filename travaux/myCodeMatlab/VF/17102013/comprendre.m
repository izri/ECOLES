grid on  %06/09
hold on %06/09
%NetworkConfig
t=1;
for j=1:V
 plot(cellule{j}.x,cellule{j}.y, 'b');  %dessiner la cellule  05/09   
 plot(eNB{j}.x,eNB{j}.y,'rd');
    for u=1:N
          if j==1  
               plot(cellule{j,1}.RB(u).x, cellule{j,1}.RB(u).y, 'g*');
%%%%g*  05/09
           else
               plot(cellule{j,1}.RB(u).x, cellule{j,1}.RB(u).y, 'm*');
           end
    end
end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%% placer les voisins a un saut de chaque cellule 
   cellule{1,1}.voisins=[2 3 4 5 6 7];
   cellule{2,1}.voisins=[1 3 7];
   cellule{3,1}.voisins=[1 2 4];
   cellule{4,1}.voisins=[1 3 5];
   cellule{5,1}.voisins=[1 4 6];
   cellule{6,1}.voisins=[1 5 7];
   cellule{7,1}.voisins=[1 2 6];
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%t=1 ==> effectuer la phase d'exploration
for k=1:V %etape init de mon algo
    %exploration step of my algo
       
OutputConfig= strcat('ConfigCellue-', num2str(k), '.dat'); %03/09
fileConfig = fopen(OutputConfig, 'w');  %wt
    %placer les users dans chaque cellule => affectation alea pr l'etape init de mon algo    
    if M>N fprintf ('erreuuuurrrr \n');
    else
    % pris=[];
     cellule{k,1}.rbUserPris=[];
     for h=1:cellule{k,1}.nbrUser
       %placer les users sur les RBs en se basant sur l'OFDMA ==> canaux
       %orthogonaux
       %il n'existe pas plusieurs users dans la cellule k sur le meme RB
       test=0;
       while test ==0
       selectRB=randi([1, N], 1, 1);  %selectionner un RB parmis N pr chaque user 
       id=intersect(cellule{k,1}.rbUserPris, selectRB);%cellule{k}.rbUserPris au lieu du vecteur pris 
       if length(id)==0
         %il faut verifier si ce RB n a pas ete deja affecte
         cellule{k,1}.user(h).x = cellule{k,1}.RB(selectRB).x;
         cellule{k,1}.user(h).y = cellule{k,1}.RB(selectRB).y;
     %   plot(cellule{k}.user{h}.x, cellule{k}.user{h}.y, 'k+'); % pr visualiser         les users
       
        if k==1 
            plot(cellule{k,1}.RB(selectRB).x, cellule{k,1}.RB(selectRB).y, 'ro');
        else
            plot(cellule{k,1}.RB(selectRB).x, cellule{k,1}.RB(selectRB).y, 'ko');%05/09
        end
       

        fprintf(fileConfig, '%d  \t %g \t %g \t %g \n', selectRB, cellule{k,1}.RB(selectRB).x,  cellule{k,1}.RB(selectRB).y, cellule{k,1}.RB(selectRB).dist );
        cellule{k,1}.user(h).rb = selectRB;
         Mat(t).tabRB(k,selectRB) = 1; % pr dire k ce rb est occupe 
         %j ai rajouté le lien avec  Mat(t), pr que je puisse comparer à l
         %instant (t) et (t-1) pr la convergence ==> modif fait le
         %03/07/2013
      
         %04/07/2013 ==> affecter un 2 à la case ou il y avait un 1 dans la
         %matriceRNTP pr dire que ce RB est utilisé et en plus il est à
         %haute puissance
         
         if (Mat(t).matriceRNTP(k,selectRB) == 1) 
             Mat(t).matriceRNTP(k,selectRB)=2; %utilisation de la puissance max
            %ds le cas ou le RB "selectRB" a ete modifie, il ne faut pas
            %oublié de remettre la valeur de cette case à 1
         end
        %%%%%%%%%%%%%%%%%%%%%
         cellule{k,1}.user(h).duration = randi([1, dur], 1, 1); %duree de communication
         %il faut calculer les distances entre chaque user et le eNB
         cellule{k,1}.user(h).dist = distance(eNB{k}.x, eNB{k}.y, cellule{k,1}.user(h).x, cellule{k}.user(h).y);
         test =1; 
        % pris=[pris, selectRB]; %mise a jour de l ensemble des RB pris
         cellule{k,1}.rbUserPris=[cellule{k,1}.rbUserPris, selectRB]; %mise a jour de l ensemble des RB pris
        % cellule{k}.user(h).puissance=PuisUsed;
         %else
        %   id
        %   length(id)
       end
      %si trouver alors rechercher à nouveau   
       end
     end
    %  cellule{k}.rbUserPris %vecteur contenant les differents RB affecte pr les
    %  user pr la cellule k
    end
    %affecter les proba de collision pr chaque cellule
    sum=0;
    for d=1:length(cellule{k,ta}.voisins)
        dd=cellule{k,1}.voisins(d);
        if dd~=k 
            sum=sum + cellule{dd}.nbrUser;
        end
    end
    cellule{k,1}.probCollision=cellule{k,ta}.nbrUser/sum;
    %test 04/09 
    if ( cellule{k,1}.probCollision > 1)
        %il faut revoir le calul
        cellule{k,1}.probCollision= abs(1-cellule{k,1}.probCollision);
    end
        fclose(fileConfig);    
end

%%%%%%%%%%%
% % 
% % sauv=1;
% % sauvegardddd=1;
% % 
% % 
% %  
% % diffGainTotal=zeros(V,N);
% % 
% % sumDist=0;
% %  
% % for indiCell=1:V
% %     for uurRB=1:cellule{indiCell,1}.nbrUser %length(cellule{indiCell,ta}.rbUserPris)
% %       rb_aA=cellule{indiCell,ta}.rbUserPris(uurRB);       
% %       sumDist=0;
% %        for ttapa=1:length(cellule{indiCell,ta}.voisins)
% %            voisinns=cellule{indiCell,ta}.voisins(ttapa);
% %            okuRBa =  intersect(cellule{voisinns,ta}.rbUserPris, rb_aA) ; %indexe de l user utilisant le wwRbConfli
% %            if (length(okuRBa)==1)
% %                sumDist=sumDist + cellule{voisinns,ta}.RB(rb_aA).puissance * ((1/ cellule{voisinns,ta}.RB(rb_aA).dist)^beta); %on peut egalement passer par l user
% %                  %premiere etape: calculer les SINR     
% %            end  
% %        end
% %  
% %     %  sumDist
% %       cellule{indiCell,t}.RB(rb_aA).SINR = calculSINR(cellule{indiCell,ta}.RB(rb_aA).dist, sumDist, PuisUsed(indiCell,rb_aA), beta, noise);
% %  %  fprintf('--------------- t=%g\t\t q=%g\t\t RB=%g \t \t SINR =%f  \n',t,indiCell, rb_aA, cellule{indiCell,t}.RB(rb_aA).SINR);
% %       %30/08
% %       cellule{indiCell,t}.RB(rb_aA).Throughput = W * abs(log2(1 + cellule{indiCell,t}.RB(rb_aA).SINR));
% %       cellule{indiCell,1}.cumulDebit=cellule{indiCell,1}.cumulDebit+cellule{indiCell,t}.RB(rb_aA).Throughput; %20/08            
% %       Mat(t).qValue(indiCell,rb_aA)=W*abs(log2(1+cellule{indiCell,t}.RB(rb_aA).SINR)); %fct QValue 
% %       Mat(t).apprentissageRB(indiCell,rb_aA)=cellule{indiCell,ta}.probCollision * Mat(t).qValue(indiCell,rb_aA); %fct d'apprentissage
% %       %  fprintf('** sauv=%g\t\t q=%g\t\t wwRbConfli=%g \t \t voisin= %g\n',sauv,q,rb_A, voisin);     
% %       if (t>1)
% %           %27/08 ==> quelques petites modifs en utilisant la variable sauv
% %           %car c le même principe que lorsque l on exécute le mécanisme de
% %           %changement de RB
% %       % if (length(intersect(T{sauvegardddd}.cellO{indiCell},rb_aA )) > 0)  
% %          Mat(t).gain(indiCell,rb_aA)= Mat(t).apprentissageRB(indiCell,rb_aA);% - Mat(sauvegardddd).apprentissageRB(indiCell,rb_aA); 
% %          %cellule{q,t}.probCollision*apprentissageRB(q,ww);
% %          %  disp('!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!');   %Mat(t).gainTotal(indiCell,rb_aA) +
% %          Mat(t).gainTotal(indiCell,rb_aA) =  Mat(t).gain(indiCell,rb_aA);
% %          diffGainTotal(indiCell, rb_aA) = Mat(t).gain(indiCell,rb_aA); % - Mat(sauvegardddd).gainTotal(indiCell,rb_aA);
% %        
% %          diffGainTotal(indiCell, rb_aA) = Mat(t).qValue(indiCell,rb_aA); % - Mat(sauvegardddd).gainTotal(indiCell,rb_aA);
% %      
% %          %  diffGainTotal = Mat(t).gainTotal(indiCell,rb_aA); % - Mat(sauvegardddd).gainTotal(indiCell,rb_aA);
% %        
% %          %06/08/2013
% %        % end
% %       else
% %          Mat(t).gain(indiCell,rb_aA)= Mat(t).apprentissageRB(indiCell,rb_aA);
% %     
% %          Mat(t).gainTotal(indiCell,rb_aA) =  Mat(t).gain(indiCell,rb_aA); %Mat(t).gainTotal(indiCell,rb_aA) +
% %       end
% %     %  gainTotalCell(indiCell,rb_aA)=Mat(t).gainTotal(indiCell,rb_aA);
% %    
% %       %%%%%%%%27/09
% %        gainTotalCell(indiCell,rb_aA)=Mat(t).gain(indiCell,rb_aA);
% %    
% %       
% %       
% %       % fprintf('######## t=%g\t\t q=%g\t\t RB=%g \t \t gainTotal(t)=%f  \n',t,q, rb_A,Mat(t).gainTotal(q,rb_A));
% %     %mis en commentaire 29/08 car trop d affichage
% %     end
% %     cumulGainTotal=0;
% %     cumSINR=0;
% %     cumAPPRENTI=0;
% % 
% % 
% % 
% % 
% % for allRB=1:length(cellule{indiCell,ta}.rbUserPris)
% %     rbActuel=cellule{indiCell,ta}.rbUserPris(allRB);
% %     cumulGainTotal= cumulGainTotal + gainTotalCell(indiCell,rbActuel); % Mat(t).gainTotal(q,rbActuel);
% %     cumSINR=cumSINR+cellule{indiCell,t}.RB(rbActuel).SINR ; %05/09
% %     cumAPPRENTI=cumAPPRENTI + Mat(t).apprentissageRB(indiCell,rbActuel);
% %      % vvvvv=0;
% %    % fprintf(fiSINR_Debit, '%d \t %d \t %d \t %d \t %f \t %f \t %f \n', t,q, vvvvv,  rbActuel, cellule{q,ta}.RB(rbActuel).dist, cellule{q,t}.RB(rbActuel).SINR, cellule{q,t}.RB(rbActuel).Throughput); %t \t cellule{q,t}.RB(wwRbConfli).SINR
% %                       %t, '\t', cellule{q,t}.RB(wwRbConfli).SINR, 
% % end
% % fprintf('****** %g \t cumul= %g \t \n',indiCell,  cumulGainTotal);  
% %      if (COUNT>1 )
% %          gainGlobal(indiCell, COUNT)= gainGlobal(indiCell, COUNT-1) + abs(cumulGainTotal); %gainTotalCell(q,rbActuel);
% %        
% %          for jjj=1:V
% %            if (jjj~=indiCell)  
% % %              if (COUNT<=V)  
% % %                zzzz=COUNT-1;
% % %              else
% % %                zzzz= mod(COUNT, V)+1;
% % %              end
% %              %  gainGlobal(jjj, COUNT)=gainGlobal(jjj, zzzz);
% %                gainGlobal(jjj, COUNT)=gainGlobal(jjj, COUNT-1);
% %            end
% %          %  disp(gainGlobal(jjj, COUNT));
% %          end  
% %      else
% %          if indiCell==1
% %           gainGlobal(indiCell, COUNT)=  abs(cumulGainTotal); %; gainTotalCell(q,rbActuel);  
% %                    
% %          for jjj=2:V
% %           gainGlobal(jjj, COUNT)=0; %gainGlobal(jjj, mod(COUNT, V));
% %          end 
% %          end
% %      end
% %     
% %      
% %      
% %        Outputfichier= strcat('SINR_ThrougAAA-', num2str(indiCell), '.dat'); %03/09
% %          if t==1 
% %              fiSINRDebit = fopen(Outputfichier, 'w');  %wt
% %          else
% %               fiSINRDebit = fopen(Outputfichier, 'a+');  %wt
% %          end
% %       
% %        for allRBx=1:cellule{indiCell,ta}.nbrUser   %length(cellule{xx,ta}.rbUserPris)
% %             indexRB=cellule{indiCell,ta}.rbUserPris(allRBx);
% %             fprintf(fiSINRDebit, '%d  \t %d \t %d \t %d \t %f \t %g \t %g \n', t,indiCell, COUNT,  indexRB, cellule{indiCell,ta}.RB(indexRB).dist, cellule{indiCell,t}.RB(indexRB).SINR, cellule{indiCell,t}.RB(indexRB).Throughput);      
% %        end
% %        fclose(fiSINRDebit); 
% %      
% %      
% %      
% %      
% %      
% %      
% %   %if (indiCell<V)  
% %       COUNT=COUNT+1;
% %  % end
% % end
% % 
% % COUNTStep=COUNT;
% % for iiii=1:V
% %     mmm= cellule{iiii,1}.nbrUser;
% %     fprintf('cellule %d \t nbreRB= %d \n',iiii, mmm);
% %     disp('!!!!!!');
% %     disp(cellule{iiii,ta}.rbUserPris);
% %     disp('*******');
% %    for l=1:COUNT-1
% %        fprintf('cell= %g \t iter= %g \t fct= %g \n',iiii, l, gainGlobal(iiii, l));
% %    end
% %  
% % end


%SUITEEEE

%legend(t(1:V,:));
axis square
hold off