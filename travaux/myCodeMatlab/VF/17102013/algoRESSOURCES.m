

%faire une fonction pr calculer le SINR ==> calculSINR
 %en prametres d entree: le num de la cellule et l'user 
 while ((t<=T_max) && (continuer ~= 0) && (okStable~=V))
fprintf(2,' t=%g  \n',t);
boolll=-1;
boolTest=-1;
%exploitation step 
  for q=1:V
% %    %chercher pour chaque cellule q  si c cellules voisines ont utilisé
% %    %les même RB qu'elle
     sommeDistUsers = 0; 
     for tt=1:length(cell{q,ta}.voisins) 
        %on suppose que les cellules restent à la config initiale (indice t=1) par rapport aux voisinages cell{q,1}.voisins
        voisin=cell{q,ta}.voisins(tt);
        Mat(t).matriceInterf(q,voisin)=0; %initialiser la case
        if voisin~=q %tt  
            cpt=0;
            [RB_common, indexCell1, indexCell2]= intersect(cell{q,ta}.rbUserPris, cell{voisin,ta}.rbUserPris);            %indexCell1: permet d'avoir les indexes au sein de la celle q
            %indexCell2: indexes pr la cellule t
            if (length(RB_common) > 0)
              cell{q,1}.cumulInterfRB=cell{q,1}.cumulInterfRB+length(RB_common); %20/08 pr calculer le nbre d'interf cumul
              cellInterf=[cellInterf, q];
              cellInterfOK=unique(cellInterf);
              LL{q}=RB_common;
              boolll=true;
              %il y a des RB en commun
              %il faut appliquer l'ago d'apprentissage
              % nbreCommun=length(RB_common);
              Mat(t).matriceInterf(q,voisin) = length(RB_common); %nbre de RB en interfe avec la cellule q
         
                for f=1:length(RB_common) %calcul de la plus grande partie du dénominateur pr le caclul du SINR
                ww=RB_common(f);%num de RB
                ss=indexCell2(f); %num du user
                %le test "if" qui suit a ete commente 30/05/2013 car il a
                %ete fait juste pr des raisons de verification
%                 if cell{t}.RB(ww).dist == cell{t}.user(ss).dist
%                     cpt=cpt+1;
%                     fprintf ('%d %d OKIIIIIIIIIIIII %d %d \n',t, cpt, q, length(RB_common)); 
%                 end
% modified 05/06/2013 ==> integration de la puissance de chaque user
                sommeDistUsers=sommeDistUsers + cell{voisin,ta}.RB(ww).puissance * ((1/ cell{voisin,ta}.RB(ww).dist)^beta); %on peut egalement passer par l user
                %premiere etape: calculer les SINR
               
            end
                    %sommeDistUsers contient a ce niveau l impact des users utilisant le
                    %meme RB dans les cellules voisines a un saut

                    %qd on change un RB; il faut mettre a jour:
                    %cell{k}.probCollision, cell{d}.nbrUser, 

                    %%%%%%%%%%%%%%%%%           %%%%%%%%%%%%%   %%%%%%
                    %%%%%%%%%%%%%%%%%           %%%%%%%%%%%%%   %%%%%
                    %la ligne svt a ete mise le 03/07/2013, mais c pas sur que c le
                    %bon endroit
                    diffGainTotal=0;
                    for rbConfli=1:length(RB_common)     
                     wwRbConfli=RB_common(rbConfli);%num de RB
                     Mat(t).gainTotal(q,wwRbConfli)= 0; % erreur corrige le 02/07/2013; il faut ini cette variable
                     %%%%%%%%%%%%%%      affectation SINR     %%%%%%%%%%%%
                     cell{q,t}.RB(wwRbConfli).SINR = calculSINR(cell{q,ta}.RB(wwRbConfli).dist, sommeDistUsers, PuisUsed(q,wwRbConfli), beta, noise);
               fprintf('########## t=%g\t\t q=%g\t\t RB=%g \t \t SINR =%f  \n',t,q, wwRbConfli, cell{q,t}.RB(wwRbConfli).SINR);
   
          
                     %10/07/2013: rajout de la ligne permettant de calculer le
                     %débit avec la formule de shannon
                     cell{q,t}.RB(wwRbConfli).Throughput = W * log(1 + cell{q,t}.RB(wwRbConfli).SINR);
                     cell{q,1}.cumulDebit=cell{q,1}.cumulDebit+cell{q,t}.RB(wwRbConfli).Throughput; %20/08
                     %cell{q,t}.RB(wwRbConfli).SINR %mis en commentaire 10/07/2013
                     %cell{q,t}.RB(wwRbConfli).Throughput %mis en commentaire 10/07/2013
                     %l'écriture dans les deux fichiers today 10/07/2013
                     fprintf(fiSINR_Debit, '%d \t %d \t %d \t %d \t %f \t %f \t %f \n', t,q, voisin,  wwRbConfli, cell{q,ta}.RB(wwRbConfli).dist, cell{q,t}.RB(wwRbConfli).SINR, cell{q,t}.RB(wwRbConfli).Throughput); %t \t cell{q,t}.RB(wwRbConfli).SINR
                      %t, '\t', cell{q,t}.RB(wwRbConfli).SINR, 
                     %  fprintf(fiDebit, '%d \t %d \t %d \t %f \n', t, q, wwRbConfli, cell{q,t}.RB(wwRbConfli).Throughput); %t \t cell{q,t}.RB(wwRbConfli).Throughput
                     %calcul de la fonction d'apprentissage 
                    Mat(t).qValue(q,wwRbConfli)=log(1+cell{q,t}.RB(wwRbConfli).SINR); %fct QValue 
                    Mat(t).apprentissageRB(q,wwRbConfli)=cell{q,ta}.probCollision * Mat(t).qValue(q,wwRbConfli); %fct d'apprentissage
                    %  fprintf('** sauv=%g\t\t q=%g\t\t wwRbConfli=%g \t \t voisin= %g\n',sauv,q,wwRbConfli, voisin);
                    if(t>1)   
                      if (length(intersect(T{sauv}.Cel{q},wwRbConfli )) > 0)    
                       Mat(t).gain(q,wwRbConfli)= Mat(t).apprentissageRB(q,wwRbConfli) - Mat(sauv).apprentissageRB(q,wwRbConfli); %cell{q,t}.probCollision*apprentissageRB(q,ww);
                       %  disp('???????????????');  
                       Mat(t).gainTotal(q,wwRbConfli) = Mat(t).gainTotal(q,wwRbConfli) + Mat(t).gain(q,wwRbConfli);
                       diffGainTotal = Mat(t).gainTotal(q,wwRbConfli) - Mat(sauv).gainTotal(q,wwRbConfli);
                       %06/08/2013                   
                      else
                       Mat(t).gain(q,wwRbConfli)= Mat(t).apprentissageRB(q,wwRbConfli);
                       Mat(t).gainTotal(q,wwRbConfli) = Mat(t).gainTotal(q,wwRbConfli) + Mat(t).gain(q,wwRbConfli);
                       diffGainTotal = Mat(t).gainTotal(q,wwRbConfli);
                     end   
                  else
                    %init 
                    Mat(t).gain(q,wwRbConfli)= Mat(t).apprentissageRB(q,wwRbConfli);
                    Mat(t).gainTotal(q,wwRbConfli)=0;    
                    Mat(t).gainTotal(q,wwRbConfli) = Mat(t).gainTotal(q,wwRbConfli) + Mat(t).gain(q,wwRbConfli);
                    Mat(t).gainCell(q)=0;
                    %%%%%%% 
                    diffGainTotal = Mat(t).gainTotal(q,wwRbConfli);% - Mat(t-1).gainTotal(q,wwRbConfli);
                end
                
                   gainTotalCell(q,wwRbConfli)=Mat(t).gainTotal(q,wwRbConfli);
                 %  fprintf('--------------- t=%g\t\t q=%g\t\t RB=%g \t \t gainTotal(t)=%f  \n',t,q, wwRbConfli,Mat(t).gainTotal(q,wwRbConfli));
               %mis en commentaire 29/08 car trop d'affichage
               fprintf(fiRecompGain, '%d \t %d \t %d \t %f \t %f  \t %f \t %f   \t %f  \t %f   \n', t,q, wwRbConfli, Mat(t).gain(q,wwRbConfli),  Mat(t).gainTotal(q,wwRbConfli), Mat(t).apprentissageRB(q,wwRbConfli),   Mat(t).qValue(q,wwRbConfli),    cell{q,ta}.probCollision      ,diffGainTotal);  
              
                %04/07/2013 g fait sortir ce test, car au cas o il faut
                %changer de RB c mieux de refaire les calcul ailleurs
                if ( diffGainTotal < 0 )
                        % il faut changer le rb "wwRbConfli" au niveau de
                        % la celle q.
               %modifRB(cellSouci, RBsouci,nbrUser, rbUserPrisCell, tabRB, N )   
                        newRB=modifRB(q,wwRbConfli, cell{q,ta}.nbrUser, cell{q,ta}.rbUserPris  , Mat(t).tabRB ,N);
                      % newRB
                        %04/07/2013 ==> a voir
                        if (newRB ~= wwRbConfli)
                           cell{q,ta}.nbrRBmodif=cell{q,ta}.nbrRBmodif+1; %27/08
                            %05/07/2013 ==> ttes les lignes de code de ce
                            %test "if"; on était fait aujourd'hui
                            %choisir un RB                  ===> OK
                            %calculer son SNIR              ===> OK
                            %mettre à jour la matriceRNTP   ===> OK
                            % ainsi que la matrice tabRB    ===> OK
                            %et les champs lié o user
                            %mettre à jour cell{q,ta}.rbUserPris; en retirant
                            %de ce tableau le RB wwRbConfli et le remplacer à
                            %son endroit par le nouveau RB    
                        %    fprintf(2,'Je change %g \t avec \t %g \t vois %g \n ',wwRbConfli,newRB, voisin);
                            uRB =  find(cell{q,ta}.rbUserPris == wwRbConfli) ; %indexe de l user utilisant le wwRbConfli
                            cell{q,ta}.user(uRB).rb = newRB; %comment
                           % récupérer le num du user uRB ??????
                            cell{q,ta}.rbUserPris(uRB)=newRB;
                           
                            Mat(t).tabRB(q,newRB) = 1; % pr dire k ce rb est occupe 
                            Mat(t).tabRB(q,wwRbConfli) = 0; %  
                     
                            cell{q,t}.RB(newRB).SINR =0; %a calculer
                            cell{q,1}.cumulDebit = cell{q,1}.cumulDebit - cell{q,t}.RB(wwRbConfli).Throughput; %20/08
                   
                            cell{q,t}.RB(wwRbConfli).Throughput=0; %car il n est plus utilisé
                            cell{q,t}.RB(wwRbConfli).SINR =0; %car il n est plus utilisé
                            
                            Mat(t).matriceRNTP(q,wwRbConfli)=1;
                            Mat(t).matriceRNTP(q,newRB)=2;
                           % fprintf ('*******  JE SUIS ICI ******** \n');
                            
                            %%%%%%%%%%%%% 11/07/2013  begin
                       
                            Mat(t).gainTotal(q,wwRbConfli)= 0; 
                            %%%%%%%%%%%%%%      affectation SINR     %%%%%%%%%%%%
                            Mat(t).gainTotal(q,newRB)= 0;    
                            
                         
                            %26/07/2013 voir si c utile de refaire le calcul des RB_common et de la  sommeDistUsersNew     
                    %513==>527        
                           [RB_commonNew, indexCell1New, indexCell2New]= intersect(cell{q,ta}.rbUserPris, cell{voisin,ta}.rbUserPris);            %indexCell1: permet d'avoir les indexes au sein de la celle q
          
                            
                            %26/07/2013
                           sommeDistUsersNew=0;
                         if(length(RB_commonNew)>0)
                           for f=1:length(RB_commonNew) %calcul de la plus grande partie du dénominateur pr le caclul du SINR
                            ww=RB_common(f);%num de RB
                          %  ss=indexCell2(f); %num du user   
                            sommeDistUsersNew=sommeDistUsersNew + cell{voisin,ta}.RB(ww).puissance * ((1/ cell{voisin,ta}.RB(ww).dist)^beta); %on peut egalement passer par l user
                           end
                          cell{q,1}.cumulInterfRB=cell{q,1}.cumulInterfRB-length(RB_common)+length(RB_commonNew); %20/08 pr calculer le nbre d'interf cumul
              
                         end
                           %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                           
                            cell{q,t}.RB(newRB).SINR = calculSINR(cell{q,ta}.RB(newRB).dist, sommeDistUsersNew, PuisUsed(q,newRB), beta, noise);
                            %10/07/2013: rajout de la ligne permettant de calculer le
                            %débit avec la formule de shannon
          fprintf('******* t=%g\t\t q=%g\t\t RB=%g \t \t SINR =%f  \n',t,q, newRB, cell{q,t}.RB(newRB).SINR);
   
    
                            cell{q,t}.RB(newRB).Throughput = W * log(1 + cell{q,t}.RB(newRB).SINR);
                            cell{q,1}.cumulDebit=cell{q,1}.cumulDebit+cell{q,t}.RB(newRB).Throughput; %20/08
                            %l'écriture dans les deux fichiers today 10/07/2013
                            fprintf(fiSINR_Debit, '%d \t %d \t %d \t %d \t %f \t %f \n', t,q, newRB, voisin,  cell{q,t}.RB(newRB).SINR, cell{q,t}.RB(newRB).Throughput);  

                            %calcul de la fonction d'apprentissage 
                            Mat(t).qValue(q,newRB)=log(1+cell{q,t}.RB(newRB).SINR); %fct QValue
                            Mat(t).apprentissageRB(q,newRB)=cell{q,ta}.probCollision * Mat(t).qValue(q,newRB); %fct d'apprentissage

                            if(t>1) 
                                Mat(t).gain(q,newRB)= Mat(t).apprentissageRB(q,newRB) - Mat(t).apprentissageRB(q,wwRbConfli);     %26/07/2013  à voir avant c était   - Mat(t).apprentissageRB(q,newRB);  
                                Mat(t).gainTotal(q,newRB) = Mat(t).gainTotal(q,newRB) + Mat(t).gain(q,newRB);
                               %%%%%%% 
                               % Mat(t).gainCell(q)=Mat(t).gainCell(q)- Mat(t).gainTotal(q,wwRbConfli) + Mat(t).gainTotal(q,newRB);
                                diffGainTotal = Mat(t).gainTotal(q,newRB) - Mat(t).gainTotal(q,wwRbConfli);
                                %26/07/2013 à voir avant c était   - Mat(t).gainTotal(q,newRB);  
                            else
                                %init 
                                Mat(t).gain(q,newRB)=0;
                                Mat(t).gainTotal(q,newRB)=0; 
                                Mat(t).gain(q,newRB)=Mat(t).apprentissageRB(q,newRB);  
                                Mat(t).gainTotal(q,newRB) = Mat(t).gainTotal(q,newRB) + Mat(t).gain(q,newRB);
                               %%%%%%% 
                                Mat(t).gainCell(q)=0;
                                diffGainTotal = Mat(t).gainTotal(q,newRB);% - Mat(t-1).gainTotal(q,wwRbConfli);
                            end
                            gainTotalCell(q,newRB)=Mat(t).gainTotal(q,newRB);
                         %%%%%%%%%%%%% 11/07/2013 end pr cette partie de modif 
                          
                        else
                            %pas de changement 
                             Mat(t).matriceRNTP(q,wwRbConfli)=2;
                        end
                    else
                        %remise à zéro de la variable pr la suite;
                        % ==> gain est soit > 0 (amélioré) ou = 0
                        % (inchangé)
                        diffGainTotal = 0;
                      %  fprintf ('*******  JE SUIS LAAAAAAAAAAAAAAAAA ******** \n');
                          
                    end
                
            end
            else
               LL{q}=[];
              
            end
        end
   %  end  %==> 29/08
     
[RB_Cellll, ind1, ind2]=intersect(cell{q,ta}.rbUserPris,RB_common);
   %calculer le SINR et le debit de chacun de c RB ainsi que la
   %fct de récompense
sumDit=0;
if (length(RB_Cellll) > 0)
    boolTest=true;
    RRC{q}=RB_Cellll;
  for uuRB=1:length(RB_Cellll)
      rb_A=RB_Cellll(uuRB);            
      cell{q,t}.RB(rb_A).SINR = calculSINR(cell{q,ta}.RB(rb_A).dist, sumDit, PuisUsed(q,rb_A), beta, noise);
       fprintf('--------------- t=%g\t\t q=%g\t\t RB=%g \t \t SINR =%f  \n',t,q, rb_A, cell{q,t}.RB(rb_A).SINR);
   
      cell{q,t}.RB(rb_A).Throughput = W * log(1 + cell{q,t}.RB(rb_A).SINR);
      cell{q,1}.cumulDebit=cell{q,1}.cumulDebit+cell{q,t}.RB(rb_A).Throughput; %20/08            
      Mat(t).qValue(q,rb_A)=log(1+cell{q,t}.RB(rb_A).SINR); %fct QValue 
      Mat(t).apprentissageRB(q,rb_A)=cell{q,ta}.probCollision * Mat(t).qValue(q,rb_A); %fct d'apprentissage
      %  fprintf('** sauv=%g\t\t q=%g\t\t wwRbConfli=%g \t \t voisin= %g\n',sauv,q,rb_A, voisin);     
      if (t>1)
          %27/08 ==> quelques petites modifs en utilisant la variable sauv
          %car c le même principe que lorsque l on exécute le mécanisme de
          %changement de RB
       if (length(intersect(T{sauvegardddd}.cellO{q},rb_A )) > 0)  
         Mat(t).gain(q,rb_A)= Mat(t).apprentissageRB(q,rb_A) - Mat(sauvegardddd).apprentissageRB(q,rb_A); 
         %cell{q,t}.probCollision*apprentissageRB(q,ww);
         %  disp('!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!');  
         Mat(t).gainTotal(q,rb_A) = Mat(t).gainTotal(q,rb_A) + Mat(t).gain(q,rb_A);
         diffGainTotal = Mat(t).gainTotal(q,rb_A) - Mat(sauvegardddd).gainTotal(q,rb_A);
         %06/08/2013
        end
      else
         Mat(t).gain(q,rb_A)= Mat(t).apprentissageRB(q,rb_A);
         Mat(t).gainTotal(q,rb_A) = Mat(t).gainTotal(q,rb_A) + Mat(t).gain(q,rb_A);
      end
      gainTotalCell(q,rb_A)=Mat(t).gainTotal(q,rb_A);
     % fprintf('######## t=%g\t\t q=%g\t\t RB=%g \t \t gainTotal(t)=%f  \n',t,q, rb_A,Mat(t).gainTotal(q,rb_A));
    %mis en commentaire 29/08 car trop d affichage
  end
else
     RRC{q}=[];
end



     end %29/08
     
     
     
%ici il faut avoir une boucle pr tt les RB de chaque cellule pr calculer le
%gain de la cellule

cumulGainTotal=0;
for allRB=1:length(cell{q,ta}.rbUserPris)
    rbActuel=cell{q,ta}.rbUserPris(allRB);
    cumulGainTotal= cumulGainTotal + gainTotalCell(q,rbActuel); % Mat(t).gainTotal(q,rbActuel);
end
if(t>1)
        Mat(t).gainCell(q)=Mat(t-1).gainCell(q)+ cumulGainTotal; 
      %  fprintf('** t-1=%g\t\t q=%g\t\t gainCell(t)=%f \t \t gainCell(t-1)= %f\n',t-1,q,Mat(t).gainCell(q), Mat(t-1).gainCell(q));
 else
        Mat(t).gainCell(q)= cumulGainTotal; 
end

fprintf(fiTest, '%d \t %d \t %f \t %f \t  \n', q, t, Mat(t).gainCell(q), cell{q,ta}.probCollision );  
   


 
%arrivée d un msg CQI  ==> 10/07/2013 ==> 20/08 modif d'emplacement de ce
%test
if (mod(t, t_CQI) ==0)
    cpt_CQI=cpt_CQI+1;  
        %  Mat(t).gainCell(q);    
    %écriture dans un fichier 20/08 la fct globale de chaque cellule pr tracer une courbe en fct du nbre d'itérations
 %27/08
    OutputFileGainProb= strcat('Gain&Proba-', num2str(q), '.dat'); %pr les attentes et transmis
    if (cpt_CQI==1)
         fiDistrib = fopen(OutputFileGainProb, 'w');  %wt
   % fprintf(fiDistrib, '%d \t %f \t %f \n',  q,  PI{yy}(xx), sommeProba);  %indice de la trame et sa taille
    else
          fiDistrib = fopen(OutputFileGainProb, 'a+');  %wt
    end
    
    fprintf(fiDistrib, '%d \t %d \t %f \t %f \t  \n', q, t, Mat(t).gainCell(q), cell{q,ta}.probCollision );  
    fclose(fiDistrib);
end

end


   if ((cpt_RNTP >= 1) && (t> dur1RNTP) ) %on utilise cette variable pour être sur que l'on a bien reçu déjà un premier msg RNTP
     for celParcour=1:V
      for inde=1:length(cell{celParcour,ta}.voisins) 
        %on suppose que les cellules restent à la config initiale (indice t=1) par rapport aux voisinages cell{q,1}.voisins
        vois=cell{celParcour,ta}.voisins(inde);
        if (mod((t+1), dur1RNTP)~=0)
        if (Mat(t).matriceInterf(celParcour,vois) >  Mat(mod((t+1), dur1RNTP)).matriceInterf(celParcour,vois))
           %le nbre d interférence a augmenté ==> continuer à dérouler l
           %algo
            continuer=1;
        else
            continuer=0; %il faut arrêter l'algo, convergence OK
        end
        end
      end 
     end
   end
   
   
% % 06/08/2013
%==> condition de stabilité ==> convergence de l algo
if t>1  
    switch varianteStab
        case 1    
            %utiliser la fct de gain globale au sein de chaque cellule
            diffG=0;
            for cc=1:V
                diffG=Mat(t).gainCell(cc)-Mat(t-1).gainCell(cc); 
                if (diffG==0)
                     okStable=okStable+1;
                     continuer=0;
                else
                     continuer=1;
                end
            end
        case 2
            %07/08/2013
            %voir par rapport aux SINR des RBs utilisés
             diffSINR=0;
             tabSINRstable=zeros(1,V);
     
             for xx=1:V
                for allRBx=1:length(cell{xx,ta}.rbUserPris)
                    %cell{q,ta}.rbUserPris(uRB)
                    indexRB=cell{xx,ta}.rbUserPris(allRBx);
                    aa=t-1;
                    diffSINR=cell{xx,t}.RB(indexRB).SINR - cell{xx,aa}.RB(indexRB).SINR; 
                  %  cell{q,t}.RB(newRB).SINR
                    %Mat(t).gainCell(cc)-Mat(t-1).gainCell(cc); 
                    if (diffSINR==0)
                         okStableA=okStableA+1;
                         continuer=0;
                    else
                         continuer=1;
                    end
                end
                %modif rajouter le 28/08
                if(okStableA == length(cell{xx,ta}.rbUserPris)) 
                    tabSINRstable(xx)=1;
                end
             end
          
             
             for xw=1:V
                 if (tabSINRstable(xw)==1)
                     okStable=okStable+1;
                 end
             end
        case 3  
            %07/08/2013 ==> a venir
            %tester sur le nbre d interférences entre 2 itérations non
            %consécutives pour chacune des cellules comme ce que j'avais
            %fait pr le SP3           
    end
end

tConverg=tConverg+1;   
if boolll == 1
     sauv=t;
     for ce=1:V
         T{sauv}.Cel{ce}=LL{ce};

     end
end

if boolTest==1
    sauvegardddd=t;
    for cee=1:V
        T{sauvegardddd}.cellO{cee}=RRC{cee};
    end
end

%ce test permet d indiquer d'un msg RNTP est arrivé et qu il faut verifier
%par rapport à la convergence de l algo
   if (mod(t, t_RNTP) == 0)
     %arriver d un msg RNTP
     cpt_RNTP=cpt_RNTP+1; %compteur du nombre de msg RNTP
  
        % note le 03/07/2013: a voir ce qui suit
        % il faut comparer la matrice à l instant (t) et à (t-1) pr voir s
        % il y a eu changement si c le cas pas de convergence encore
        
%      for celParcour=1:V
%       for inde=1:length(cell{celParcour,ta}.voisins) 
%         %on suppose que les cellules restent à la config initiale (indice t=1) par rapport aux voisinages cell{q,1}.voisins
%         vois=cell{celParcour,ta}.voisins(inde);
%         if (Mat(t).matriceInterf(celParcour,vois) >  Mat(t).matriceInterf(celParcour,vois))
%             continuer=1;
%         else
%             continuer=0; %il faut arrêter l'algo, convergence OK
%         end
%       end 
%      end
        
   end
   
 t=t+1;  
 end
 
 if (t>1)
     %26/08 rajout de ce test; et correction que sur la division c par
     %(t-1) et non t
    for qa=1:V
     %20/08==> indice de perf
        debitMoyen(qa)=cell{qa,1}.cumulDebit/(t-1);
        nbreInterfMoyen(qa)=cell{qa,1}.cumulInterfRB/(t-1);
        fprintf(fichierA, '%d \t %d \t %d  \t %d  \t %f \t %f \t %d \n', (t-1), qa, N, cell{qa,1}.nbrUser,  debitMoyen(qa), nbreInterfMoyen(qa), cell{qa,ta}.nbrRBmodif );  
      %pr le tracer de ces deux courbes debit moyen et nbre d interference moyenne, cela se fera avec gnuplot ou excel par la suite car ilfaut tte les valeurs      
       %le N correspond au nbre de RB max/cell
    end
 end
 
 if (okStable== V)
  fprintf ('---------  FIN CONVERGENCE OK   --------- reçu %d  \t msg RNTP  ---- \t %d msg CQI -- %d s  \t duree de convergence  \n', cpt_RNTP, cpt_CQI,  tConverg);
 end
 