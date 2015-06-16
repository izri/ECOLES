OutputFileSINR_Throughput= strcat('fileSINR_Throughput.txt');
fiSINR_Debit = fopen(OutputFileSINR_Throughput, 'w');  %wt
OutputFileSINR_ThroughputA= strcat('fileSINR_ThroughputMODIF.txt');
fiSINR_DebitA = fopen(OutputFileSINR_ThroughputA, 'w');  %wt

OutputFileGAIN= strcat('fctRecompGain.txt'); %pr le débit
fiRecompGain = fopen(OutputFileGAIN, 'w');  %wt
OutpuVerzooozzz= strcat('VerfiGainzzzzzzzzzzzzz.txt'); 
fitesttttt= fopen(OutpuVerzooozzz, 'w');
t=1; %indice de temps
COUNT=1;  
fileSortie= strcat('debitMoyInterfMoy.txt'); %pr le débit moyen et le nbre d interférences moyennes %26/08/2013
fichierA = fopen(fileSortie, 'a+');  %wt

OutpuVerfi= strcat('VerfiGain.txt'); %pr le 
fiTest = fopen(OutpuVerfi, 'w');  %wt

sortiFILE= strcat('timeSTABLE.txt'); %pr le débit
fileStable=fopen(sortiFILE, 'w');

continuer = -1;
okStable=0;
okStableA=0;
cellInterf=[];


sauv=1;
sauvegardddd=1;


 
diffGainTotal=zeros(V,N);

sumDist=0;
 
for indiCell=1:V
    for uurRB=1:cellule{indiCell,1}.nbrUser %length(cellule{indiCell,ta}.rbUserPris)
      rb_aA=cellule{indiCell,ta}.rbUserPris(uurRB);       
      sumDist=0;
       for ttapa=1:length(cellule{indiCell,ta}.voisins)
           voisinns=cellule{indiCell,ta}.voisins(ttapa);
           okuRBa =  intersect(cellule{voisinns,ta}.rbUserPris, rb_aA) ; %indexe de l user utilisant le wwRbConfli
           if (length(okuRBa)==1)
               sumDist=sumDist + cellule{voisinns,ta}.RB(rb_aA).puissance * ((1/ cellule{voisinns,ta}.RB(rb_aA).dist)^beta); %on peut egalement passer par l user
                 %premiere etape: calculer les SINR     
           end  
       end
 
    %  sumDist
      cellule{indiCell,t}.RB(rb_aA).SINR = calculSINR(cellule{indiCell,ta}.RB(rb_aA).dist, sumDist, PuisUsed(indiCell,rb_aA), beta, noise);
 %  fprintf('--------------- t=%g\t\t q=%g\t\t RB=%g \t \t SINR =%f  \n',t,indiCell, rb_aA, cellule{indiCell,t}.RB(rb_aA).SINR);
      %30/08
      cellule{indiCell,t}.RB(rb_aA).Throughput = W * abs(log2(1 + cellule{indiCell,t}.RB(rb_aA).SINR));
      cellule{indiCell,1}.cumulDebit=cellule{indiCell,1}.cumulDebit+cellule{indiCell,t}.RB(rb_aA).Throughput; %20/08            
      Mat(t).qValue(indiCell,rb_aA)=W*abs(log2(1+cellule{indiCell,t}.RB(rb_aA).SINR)); %fct QValue 
      Mat(t).apprentissageRB(indiCell,rb_aA)=cellule{indiCell,ta}.probCollision * Mat(t).qValue(indiCell,rb_aA); %fct d'apprentissage
      %  fprintf('** sauv=%g\t\t q=%g\t\t wwRbConfli=%g \t \t voisin= %g\n',sauv,q,rb_A, voisin);     
      if (t>1)
          %27/08 ==> quelques petites modifs en utilisant la variable sauv
          %car c le même principe que lorsque l on exécute le mécanisme de
          %changement de RB
      % if (length(intersect(T{sauvegardddd}.cellO{indiCell},rb_aA )) > 0)  
         Mat(t).gain(indiCell,rb_aA)= Mat(t).apprentissageRB(indiCell,rb_aA);% - Mat(sauvegardddd).apprentissageRB(indiCell,rb_aA); 
         %cellule{q,t}.probCollision*apprentissageRB(q,ww);
         %  disp('!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!');   %Mat(t).gainTotal(indiCell,rb_aA) +
         Mat(t).gainTotal(indiCell,rb_aA) =  Mat(t).gain(indiCell,rb_aA);
         diffGainTotal(indiCell, rb_aA) = Mat(t).gain(indiCell,rb_aA); % - Mat(sauvegardddd).gainTotal(indiCell,rb_aA);
       
         diffGainTotal(indiCell, rb_aA) = Mat(t).qValue(indiCell,rb_aA); % - Mat(sauvegardddd).gainTotal(indiCell,rb_aA);
     
         %  diffGainTotal = Mat(t).gainTotal(indiCell,rb_aA); % - Mat(sauvegardddd).gainTotal(indiCell,rb_aA);
       
         %06/08/2013
       % end
      else
         Mat(t).gain(indiCell,rb_aA)= Mat(t).apprentissageRB(indiCell,rb_aA);
    
         Mat(t).gainTotal(indiCell,rb_aA) =  Mat(t).gain(indiCell,rb_aA); %Mat(t).gainTotal(indiCell,rb_aA) +
      end
    %  gainTotalCell(indiCell,rb_aA)=Mat(t).gainTotal(indiCell,rb_aA);
   
      %%%%%%%%27/09
       gainTotalCell(indiCell,rb_aA)=Mat(t).gain(indiCell,rb_aA);
   
      
      
      % fprintf('######## t=%g\t\t q=%g\t\t RB=%g \t \t gainTotal(t)=%f  \n',t,q, rb_A,Mat(t).gainTotal(q,rb_A));
    %mis en commentaire 29/08 car trop d affichage
    end
    cumulGainTotal=0;
    cumSINR=0;
    cumAPPRENTI=0;




for allRB=1:length(cellule{indiCell,ta}.rbUserPris)
    rbActuel=cellule{indiCell,ta}.rbUserPris(allRB);
    cumulGainTotal= cumulGainTotal + gainTotalCell(indiCell,rbActuel); % Mat(t).gainTotal(q,rbActuel);
    cumSINR=cumSINR+cellule{indiCell,t}.RB(rbActuel).SINR ; %05/09
    cumAPPRENTI=cumAPPRENTI + Mat(t).apprentissageRB(indiCell,rbActuel);
     % vvvvv=0;
   % fprintf(fiSINR_Debit, '%d \t %d \t %d \t %d \t %f \t %f \t %f \n', t,q, vvvvv,  rbActuel, cellule{q,ta}.RB(rbActuel).dist, cellule{q,t}.RB(rbActuel).SINR, cellule{q,t}.RB(rbActuel).Throughput); %t \t cellule{q,t}.RB(wwRbConfli).SINR
                      %t, '\t', cellule{q,t}.RB(wwRbConfli).SINR, 
end
fprintf('****** %g \t cumul= %g \t \n',indiCell,  cumulGainTotal);  
     if (COUNT>1 )
         gainGlobal(indiCell, COUNT)= gainGlobal(indiCell, COUNT-1) + abs(cumulGainTotal); %gainTotalCell(q,rbActuel);
       
         for jjj=1:V
           if (jjj~=indiCell)  
%              if (COUNT<=V)  
%                zzzz=COUNT-1;
%              else
%                zzzz= mod(COUNT, V)+1;
%              end
             %  gainGlobal(jjj, COUNT)=gainGlobal(jjj, zzzz);
               gainGlobal(jjj, COUNT)=gainGlobal(jjj, COUNT-1);
           end
         %  disp(gainGlobal(jjj, COUNT));
         end  
     else
         if indiCell==1
          gainGlobal(indiCell, COUNT)=  abs(cumulGainTotal); %; gainTotalCell(q,rbActuel);  
                   
         for jjj=2:V
          gainGlobal(jjj, COUNT)=0; %gainGlobal(jjj, mod(COUNT, V));
         end 
         end
     end
    
     
     
       Outputfichier= strcat('SINR_ThrougAAA-', num2str(indiCell), '.dat'); %03/09
         if t==1 
             fiSINRDebit = fopen(Outputfichier, 'w');  %wt
         else
              fiSINRDebit = fopen(Outputfichier, 'a+');  %wt
         end
      
       for allRBx=1:cellule{indiCell,ta}.nbrUser   %length(cellule{xx,ta}.rbUserPris)
            indexRB=cellule{indiCell,ta}.rbUserPris(allRBx);
            fprintf(fiSINRDebit, '%d  \t %d \t %d \t %d \t %f \t %g \t %g \n', t,indiCell, COUNT,  indexRB, cellule{indiCell,ta}.RB(indexRB).dist, cellule{indiCell,t}.RB(indexRB).SINR, cellule{indiCell,t}.RB(indexRB).Throughput);      
       end
       fclose(fiSINRDebit); 
     
     
     
     
     
     
  %if (indiCell<V)  
      COUNT=COUNT+1;
 % end
end

COUNTStep=COUNT;
for iiii=1:V
    mmm= cellule{iiii,1}.nbrUser;
    fprintf('cellule %d \t nbreRB= %d \n',iiii, mmm);
    disp('!!!!!!');
    disp(cellule{iiii,ta}.rbUserPris);
    disp('*******');
   for l=1:COUNT-1
       fprintf('cell= %g \t iter= %g \t fct= %g \n',iiii, l, gainGlobal(iiii, l));
   end
 
end
















COUNT=COUNTStep-1;
tabRBbb=[];
    for iiiii=1:N 
        %24/09
       tabRBbb=[tabRBbb, iiiii]; 
    end
boolll=2;
boolTest=2;
%diffGainTotal=zeros(1,N);
%cellRBcommon=zeros(1,V); %30/08
boolOKstable=0;
%cptStable=0; 
okiii=0;
boolEND=-1;
cptStable(1)=0;
instantT=[];
cumulCPT=[];
%faire une fonction pr calculer le SINR ==> calculSINR
 %en prametres d entree: le num de la cellule et l'user 
 %(t<=T_max)  && ==> 04/09 j ai enlevé ce test car je dois d'abord
 %atteindre la stabilité et connaitre après combien d'itération c atteint
 
tabREWARD=zeros(1,V);
FFFF=0;
testGLOBAL2=0;
PPPP=0;
 countITER=zeros(1,V);
while (1) %(boolOKstable==0))  %&& (continuer ~= 0)  %(okStable~=V) &&  (t<=T_max)  &&
okiii=okStable;
%fprintf(2,' t=%g \n', t);
if (t>1) 
    
   % fprintf(2,' t=%g \t \t cptStable=%g \t \t okStable= %g  \t \t okiii= %g \n',t, cptStable(t-1), okStable, okiii);
    %fileStable
    fprintf(fileStable,'%g \t \t %g \t \t %g \t \t %g  \n',t, cptStable(t-1), okStable, okiii);
          
else 
  %  fprintf(2,' t=%g \t \t cptStable=%g \t \t okStable= %g  \t \t okiii= %g \n',t, cptStable(1), okStable, okiii);
    fprintf(fileStable,'%g \t \t %g \t \t %g \t \t %g  \n',t, cptStable(1), okStable, okiii);
  
end
okStable=0; %04/09  ==> A VOIR
okStableA=0;  %04/09  ==> A VOIR
boolll=-1;
boolTest=-1;
%exploitation step 
% cellVect=[2:V, 1];
% for qaq=1:length(cellVect)
%     q=cellVect(qaq);
%     
  %  RBproblm=[];
for q=1:V    %%%25/09 
  
%     if t==2
%            testBool=1;
%     end

OutpuVerfiAAA= strcat('VerfiGainProbaInstant-', num2str(q), '.dat');


    if t==1
         fiTestAAA = fopen(OutpuVerfiAAA, 'w');  %wt
    else
         fiTestAAA = fopen(OutpuVerfiAAA, 'a+');  %wt
    end
  
    
    
    
   RBmodifOK{q}=[];
   unionRB=[]; %30/08
   cellRBcommon{q}=[]; %30/08
% %    %chercher pour chaque cellule q  si c cellules voisines ont utilisé
% %    %les même RB qu'elle

  RRC{q}=[];
  cellule{q,1}.cumulDebit=0;
  sumDist=0;
 if (t>1) 
    for uurrRB=1:cellule{q,1}.nbrUser %length(cellule{q,ta}.rbUserPris)
      rb_aaA=cellule{q,ta}.rbUserPris(uurrRB);   
      sumDist=0;
       for ttapa=1:length(cellule{q,ta}.voisins)
           voisinns=cellule{q,ta}.voisins(ttapa);
           okuRBa =  intersect(cellule{voisinns,ta}.rbUserPris, rb_aaA) ; %indexe de l user utilisant le wwRbConfli
           if (length(okuRBa)==1)
               sumDist=sumDist + cellule{voisinns,ta}.RB(okuRBa).puissance * ((1/ cellule{voisinns,ta}.RB(okuRBa).dist)^beta); %on peut egalement passer par l user
                 %premiere etape: calculer les SINR     
           end        
       end
   
      cellule{q,t}.RB(rb_aaA).SINR = calculSINR(cellule{q,ta}.RB(rb_aaA).dist, sumDist, PuisUsed(q,rb_aaA), beta, noise);
 %  fprintf('--------------- t=%g\t\t q=%g\t\t RB=%g \t \t SINR =%f  \n',t,q, rb_aaA, cellule{q,t}.RB(rb_aaA).SINR);
     %30/08 
      cellule{q,t}.RB(rb_aaA).Throughput = W * abs(log2(1 + cellule{q,t}.RB(rb_aaA).SINR));
      cellule{q,1}.cumulDebit=cellule{q,1}.cumulDebit+cellule{q,t}.RB(rb_aaA).Throughput; %20/08            
      Mat(t).qValue(q,rb_aaA)=W*abs(log2(1+cellule{q,t}.RB(rb_aaA).SINR)); %fct QValue 
      Mat(t).apprentissageRB(q,rb_aaA)=cellule{q,ta}.probCollision * Mat(t).qValue(q,rb_aaA); %fct d'apprentissage
    
       if (t==1)  
         Mat(t).gainCell(q)=0;
         Mat(t).sinrCell(q)=0;
         Mat(t).apprentiCell(q)=0;
         
         Mat(t).apprentiCellALL(q)=0;
         Mat(t).gainCellAll(q)=0;
         Mat(t).sinrCellAll(q)=0;
      
         Mat(t).gain(q,rb_aaA)= Mat(t).apprentissageRB(q,rb_aaA);
         Mat(t).gainTotal(q,rb_aaA) = Mat(t).gain(q,rb_aaA); %Mat(t).gainTotal(q,rb_A) + 
     %    diffGainTotal(rb_aaA) = Mat(t).gain(q,rb_aaA);% - Mat(t-1).gainTotal(q,wwRbConfli);
         diffGainTotal(q,rb_aaA) = Mat(t).qValue(q,rb_aaA);% - Mat(t-1).gainTotal(q,wwRbConfli);
        
         else

         Mat(t).gain(q,rb_aaA)= abs( Mat(t).apprentissageRB(q,rb_aaA) - Mat(t-1).apprentissageRB(q,rb_aaA));
        % Mat(t).gainTotal(q,rb_aA)=0;
         Mat(t).gainTotal(q,rb_aaA) = Mat(t-1).gainTotal(q,rb_aaA) + Mat(t).gain(q,rb_aaA);
        
    %% fprintf(2, ' ******************** %d \t \t %g \t %g \t %g \t %g \n', t,   Mat(t-1).gainTotal(q,rb_aaA), Mat(t).gain(q,rb_aaA),Mat(t-1).gain(q,rb_aaA), Mat(t).gainTotal(q,rb_aaA));
     %   diffGainTotal(rb_aaA) = Mat(t).gain(q,rb_aaA)- Mat(t-1).gain(q,rb_aaA); 
        diffGainTotal(q,rb_aaA) = Mat(t).qValue(q,rb_aaA)- Mat(t-1).qValue(q,rb_aaA); 
 %%%fprintf(2, ' !!!!!!!!!!!!!!! %d \t \t %d \t \t %g \t %g \t %g \t %g \n', t,  q,  Mat(t-1).gainTotal(q,rb_aaA), Mat(t).gain(q,rb_aaA),Mat(t-1).gain(q,rb_aaA), Mat(t).gainTotal(q,rb_aaA)); 
      end
      gainTotalCell(q,rb_aaA)=Mat(t).gainTotal(q,rb_aaA); %Mat(t).gainTotal(q,rb_aaA);  
      %%%%27/09       
      gainTotalCell(q,rb_aaA)=Mat(t).gain(q,rb_aaA);%  Mat(t).gainTotal(q,newRB);
                           
  
      
     % gainTotalCell(q,rb_aaA)=Mat(t).gainTotal(q,rb_aaA)+gainTotalCell(q,rb_aaA);
     % fprintf('######## t=%g\t\t q=%g\t\t RB=%g \t \t gainTotal(t)=%f  \n',t,q, rb_A,Mat(t).gainTotal(q,rb_A));
    %mis en commentaire 29/08 car trop d affichage
  
    vvvvv=0;
    fprintf(fiSINR_Debit, '%d \t %d \t %d \t %d \t %f \t %f \t %f \n', t,q, vvvvv,  rb_aaA, cellule{q,ta}.RB(rb_aaA).dist, cellule{q,t}.RB(rb_aaA).SINR, cellule{q,t}.RB(rb_aaA).Throughput); %t \t cellule{q,t}.RB(wwRbConfli).SINR
                      %t, '\t', cellule{q,t}.RB(wwRbConfli).SINR, 
           
    
    end
    
    
end
    rbPROBLM{q}=[];
rbcommoncellule{q}=[];

affectionINIT{q}=cellule{q,ta}.rbUserPris;
%calcul des RB en commun avec chacun des voisins
rbcommoncccc=[];
 for tta=1:length(cellule{q,ta}.voisins)      
    voisiiii=cellule{q,ta}.voisins(tta);
    Mat(t).matriceInterf(q,voisiiii)=0; %initialiser la case
     %  
    RB_commonVoisin{voisiiii}= intersect(cellule{q,ta}.rbUserPris, cellule{voisiiii,ta}.rbUserPris);            %indexCell1: permet d'avoir les indexes au sein de la celle q
    Mat(t).matriceInterf(q,voisiiii) = length(RB_commonVoisin{voisiiii}); %nbre de RB en interfe avec la cellule q
    rbcommoncccc=[rbcommoncccc,    RB_commonVoisin{voisiiii}];
    rbcommoncellule{q}=unique(rbcommoncccc);
 end
% q  %26/09
% disp(rbcommoncellule{q});
     cellule{q,1}.cumulDebit=0;
    % for tt=1:length(cellule{q,ta}.voisins) 
         
        %on suppose que les cellules restent à la config initiale (indice t=1) par rapport aux voisinages cellule{q,1}.voisins
%        voisin=cellule{q,ta}.voisins(tt);
     %   Mat(t).matriceInterf(q,voisin)=0; %initialiser la case
     %   if voisin~=q %tt  
            cpt=0;
         %   [RB_common, indexCell1, indexCell2]= intersect(cellule{q,ta}.rbUserPris, cellule{voisin,ta}.rbUserPris);            %indexCell1: permet d'avoir les indexes au sein de la celle q
            %indexCell2: indexes pr la cellule t
           % if (length(RB_common) > 0)  
           voisin=0;
           if(length(rbcommoncellule{q})>0)
              RB_common=[];
              RB_common=rbcommoncellule{q};
              cellule{q,1}.cumulInterfRB=cellule{q,1}.cumulInterfRB+length(RB_common); %20/08 pr calculer le nbre d'interf cumul
              cellInterf=[cellInterf, q];
              cellInterfOK=unique(cellInterf);
              LLV{q}=RB_common;
              %%%%%%%%%%%%%%%%
            %  rbComm=RB_common; %30/08
          %    actuel=unique(rbComm); %30/08
           %   cellRBcommon{q}=[cellRBcommon(q), actuel];  %30/08
    %%%%%%%%%%%%%%%%
             rbComm=RB_common; %30/08
             actuel=unique(rbComm); %30/08
             unionRB =[unionRB, actuel];  %30/08
     
             
             %%%%%%%%%%%%%%%%%           
              %%%%%%%%%%%%%%%%%%
              boolll=true;
          
  for rbConfli=1:length(RB_common)     
  wwRbConfli=RB_common(rbConfli);%num de RB
                
                 %  fprintf('--------------- t=%g\t\t q=%g\t\t RB=%g \t \t gainTotal(t)=%f  \n',t,q, wwRbConfli,Mat(t).gainTotal(q,wwRbConfli));
               %mis en commentaire 29/08 car trop d'affichage
  fprintf(fiRecompGain, '%d \t %d \t %d \t %f \t %f  \t %f \t %f   \t %f  \t %f   \n', t,q, wwRbConfli, Mat(t).gain(q,wwRbConfli),  Mat(t).gainTotal(q,wwRbConfli), Mat(t).apprentissageRB(q,wwRbConfli),   Mat(t).qValue(q,wwRbConfli),    cellule{q,ta}.probCollision , diffGainTotal(q, wwRbConfli));  
       

%disp(diffGainTotal(wwRbConfli) );

 %   diffGainTotal(wwRbConfli)=-10; %27/09
    if ( diffGainTotal(q,wwRbConfli) < 0 ) || (t==1)
                    
     %   disp('*************************************************');      
       % il faut changer le rb "wwRbConfli" au niveau de
          % la celle q.
          okchoixRBdispo=-1;  %init   
          RB_usedOK= setdiff(tabRBbb, cellule{q,ta}.rbUserPris, 'stable');           %indexCell1: permet d'avoir les indexes au sein de la celle q
                  % disp(RB_usedOK);
          
          if ( length(RB_usedOK)>1)
             switch varianteChooseRB              
              case 1  %CHOISIR LE MEILLEUR RB
                maxRB=RB_usedOK(1);
                boolOKrbchange=0;
               % fprintf(2, 'maxRB=%d \n', maxRB);
              for rbDISPO=1:length(RB_usedOK)
                  rbChoix=RB_usedOK(rbDISPO);
                  if t>1 
                     cellule{q,t-1}.RB(rbChoix).SINR   =0;
                  end
                 %25/09       
                 sommeDistUsersA=0;
                 for ttaaa=1:length(cellule{q,ta}.voisins)  
                    voizz=cellule{q,ta}.voisins(ttaaa);
                    okuRB =  intersect(cellule{voizz,ta}.rbUserPris, rbChoix) ; %indexe de l user utilisant le wwRbConfli
                    if (length(okuRB)==1)
                       sommeDistUsersA=sommeDistUsersA + cellule{voizz,ta}.RB(okuRB).puissance * ((1/ cellule{voizz,ta}.RB(okuRB).dist)^beta); %on peut egalement passer par l user
                         %premiere etape: calculer les SINR
                    end  
                 end
               %modif pr le calcul du SINR
                  sinr = calculSINR(cellule{q,ta}.RB(rbChoix).dist, sommeDistUsersA , PuisUsed(q,rbChoix), beta, noise);
                  deb = W *abs( log2(1 + sinr)); %cellule{q,t}.RB(rbChoix).SINR)
                  qval=W*abs(log2(1+sinr)); %fct QValue  %cellule{q,t}.RB(rbChoix).SINR)
                  appr=cellule{q,ta}.probCollision * qval; %fct d'apprentissage %Mat(t).apprentissageRB(q,rbChoix)
                   %Mat(t).qValue(q,rbChoix)
              %     if ((cellule{q,t}.RB(rbChoix).SINR - cellule{q,t}.RB(wwRbConfli).SINR) > 0)   
                   if rbDISPO==1
                     apprMax=appr;
                     qvalMax=qval;
                     sinrMax=sinr;
                     debMax=deb;
                   end
               
                   
                   
                    FFF= gainGlobal(q, COUNT); 
                   TESTTTT=FFF-Mat(t).apprentissageRB(q,wwRbConfli)+appr;
                   
                   if (TESTTTT>=FFF)
                   if ((appr- Mat(t).apprentissageRB(q,wwRbConfli) >0) && (sinr > cellule{q,t}.RB(wwRbConfli).SINR) ) 
             %      fprintf('%d \t ====== \t %g \t \t ******  \t  %g \n', q, Mat(t).apprentissageRB(q,wwRbConfli), Mat(t).apprentissageRB(q,rbChoix));
                   NNNNN= FFF-Mat(t).apprentissageRB(q,wwRbConfli)+apprMax;
             if ((apprMax <= appr) && (sinrMax<=sinr) && (NNNNN >=TESTTTT))
                     % && (cellule{q,t}.RB(maxRB).SINR < cellule{q,t}.RB(rbChoix).SINR)
                     %  if (cellule{q,t}.RB(maxRB).SINR < cellule{q,t}.RB(rbChoix).SINR)
                       
                         if t>1
                         if (appr- Mat(t-1).apprentissageRB(q,wwRbConfli) >0)     
                            maxRB=  rbChoix;  
                            boolOKrbchange=1;
                            apprMax=appr;
                            qvalMax=qval;
                            sinrMax=sinr;
                            debMax=deb;
                         end
                         else 
                             
                            maxRB=  rbChoix;  
                            boolOKrbchange=1;

                            apprMax=appr;
                            qvalMax=qval;
                            sinrMax=sinr;
                            debMax=deb;
                       end
                      end
                   else
              %                fprintf('%d \t ######  \t %g \t \t -----------------  \t  %g \n', q, Mat(t).apprentissageRB(q,wwRbConfli), Mat(t).apprentissageRB(q,rbChoix));
                           newRB=  wwRbConfli;
                %     disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%');
                     okchoixRBdispo=0;
                   end
                   else
                                newRB=  wwRbConfli;
                %     disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%');
                     okchoixRBdispo=0;
              end
                %   fprintf('maxRB=%d \n', maxRB);
              end
              if boolOKrbchange==1
                 newRB=  maxRB; %pr choisir le meilleur RB
                 okchoixRBdispo=1;
            %    fprintf(2,'%f \n', cellule{q,t}.RB(newRB).SINR);
              else
                     newRB=  wwRbConfli;
                     okchoixRBdispo=0;
              end   
             
              
              case 2
                  nbre=length(RB_usedOK); 
                  aleaID=randi([1, nbre], 1, 1);
                  rbChoix=RB_usedOK(aleaID);
                  if (rbChoix~=wwRbConfli)
                      newRB= rbChoix;
                    %  disp('************');
                      okchoixRBdispo=1;
                  else
                      newRB= wwRbConfli;
                      okchoixRBdispo=0;
                  end
          
                  
                  
               case 3  
                     okchoixRBdispo=0;
                     verif =0;
                     nbre=length(RB_usedOK);
                     setR=[];
                     RBinters=[];
                     RBinters=RB_usedOK;
                   while verif ==0   
                     nbre=length(RBinters); 
                    if nbre>0
                     aleaID=randi([1, nbre], 1, 1); 
                     rbChoix=RBinters(aleaID);
              
                     sommeDistUsersAb=0;
                     for ttaaea=1:length(cellule{q,ta}.voisins)  
                         voiizz=cellule{q,ta}.voisins(ttaaea);
                         okuRB =  intersect(cellule{voiizz,ta}.rbUserPris, rbChoix) ; %indexe de l user utilisant le wwRbConfli
                         if (length(okuRB)==1)
                               sommeDistUsersAb=sommeDistUsersAb + cellule{voiizz,ta}.RB(okuRB).puissance * ((1/ cellule{voiizz,ta}.RB(okuRB).dist)^beta); %on peut egalement passer par l user
                            %premiere etape: calculer les SINR
                
                         end  
                     end
                      %modif pr le calcul du SINR  
                      sinrMax = calculSINR(cellule{q,ta}.RB(rbChoix).dist, sommeDistUsersAb , PuisUsed(q,rbChoix), beta, noise);
                      debMax = W *abs(log2(1 + sinrMax)); % cellule{q,t}.RB(rbChoix).SINR)
                      qvalMax=W*abs(log2(1+sinrMax)); %fct QValue  %cellule{q,t}.RB(rbChoix).SINR)
                      apprMax=cellule{q,ta}.probCollision * qvalMax; %fct d'apprentissage
                
                      if ((apprMax- Mat(t).apprentissageRB(q,wwRbConfli) >0) && (sinrMax>cellule{q,t}.RB(wwRbConfli).SINR))
                         
                           
                           
                             if t>1
                                 if (apprMax- Mat(t-1).apprentissageRB(q,wwRbConfli) >0)
                                    newRB=  rbChoix; %pr choisir le meilleur RB
                                    okchoixRBdispo=1; 
                                    verif=1;
                                    break;
                                 end
                             else  
                                 
                                   newRB=  rbChoix; %pr choisir le meilleur RB
                                   okchoixRBdispo=1; 
                                   verif=1;
                                    break;
                           
                              end
                      else
                          newRB=  wwRbConfli;
                          okchoixRBdispo=0;
                          setR=[setR, rbChoix];
                          RBinters=setdiff(RB_usedOK, setR);
                      end
                   
                    else
                        break;
                    end 
                  end 
        %       fprintf('i am here newRB=%d \t wwRbConfli=%d \n', newRB,
        %       wwRbConfli ); %26/09
                 
            end
          else
           if ( length(RB_usedOK)==1)             
            switch varianteChooseRB                 
              case 1     
                rbChoix=RB_usedOK(1);
                      %25/09       
                sommeDistUsersAb=0;
                for ttaaea=1:length(cellule{q,ta}.voisins)  
                    voiizz=cellule{q,ta}.voisins(ttaaea);
                    okuRB =  intersect(cellule{voiizz,ta}.rbUserPris, rbChoix) ; %indexe de l user utilisant le wwRbConfli
                    if (length(okuRB)==1)
                        sommeDistUsersAb=sommeDistUsersAb + cellule{voiizz,ta}.RB(okuRB).puissance * ((1/ cellule{voiizz,ta}.RB(okuRB).dist)^beta); %on peut egalement passer par l user
                            %premiere etape: calculer les SINR
                
                    end  
                end
                %modif pr le calcul du SINR  
                sinrMax = calculSINR(cellule{q,ta}.RB(rbChoix).dist, sommeDistUsersAb , PuisUsed(q,rbChoix), beta, noise);
                debMax = W *abs(log2(1 + sinrMax)); % cellule{q,t}.RB(rbChoix).SINR)
                qvalMax=W*abs(log2(1+sinrMax)); %fct QValue  %cellule{q,t}.RB(rbChoix).SINR)
                apprMax=cellule{q,ta}.probCollision * qvalMax; %fct d'apprentissage
       
                
                         FFF= gainGlobal(q, COUNT); 
                   TESTTTT=FFF-Mat(t).apprentissageRB(q,wwRbConfli)+apprMax;
                   
            if (TESTTTT>=FFF)
                
               if ((apprMax- Mat(t).apprentissageRB(q,wwRbConfli) >0)&& (sinrMax > cellule{q,t}.RB(wwRbConfli).SINR)) 
            %    if ((cellule{q,t}.RB(rbChoix).SINR - cellule{q,t}.RB(wwRbConfli).SINR) > 0)   
                 
            
                    if t>1   
                        if (apprMax- Mat(t-1).apprentissageRB(q,wwRbConfli) >0)
                         newRB=  rbChoix; %pr choisir le meilleur RB
                         okchoixRBdispo=1;  
                        end
                    else
                        
                    newRB=  rbChoix; %pr choisir le meilleur RB
                    okchoixRBdispo=1; 
                    %    fprintf(2, '%f \n', cellule{q,t}.RB(newRB).SINR);
                    end      
                else
                     newRB=  wwRbConfli;
                %     disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%');
                     okchoixRBdispo=0;
              %       fprintf('PAS D''AMELIORATION DS LA CELLULE %d \n', q);
               end 
            else
                         newRB=  wwRbConfli;
                %     disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%');
                     okchoixRBdispo=0;
                   end
            
              case 2  
                     %choix aléatoire
                 rbChoix=RB_usedOK(1);
%                  newRB=  rbChoix; %wwRbConfli;   
%                %  disp('#########');
%                  okchoixRBdispo=1;
                   if (rbChoix~=wwRbConfli)
                      newRB= rbChoix;
                    %  disp('************');
                      okchoixRBdispo=1;
                  else
                      newRB= wwRbConfli;
                      okchoixRBdispo=0;
                  end
                 
             case 3
                 rbChoix=RB_usedOK(1);
                 
                 sommeDistUsersAb=0;
                for ttaaea=1:length(cellule{q,ta}.voisins)  
                    voiizz=cellule{q,ta}.voisins(ttaaea);
                    okuRB =  intersect(cellule{voiizz,ta}.rbUserPris, rbChoix) ; %indexe de l user utilisant le wwRbConfli
                    if (length(okuRB)==1)
                        sommeDistUsersAb=sommeDistUsersAb + cellule{voiizz,ta}.RB(okuRB).puissance * ((1/ cellule{voiizz,ta}.RB(okuRB).dist)^beta); %on peut egalement passer par l user
                            %premiere etape: calculer les SINR
                
                    end  
                end
                %modif pr le calcul du SINR  
                sinrMax = calculSINR(cellule{q,ta}.RB(rbChoix).dist, sommeDistUsersAb , PuisUsed(q,rbChoix), beta, noise);
                debMax = W *abs(log2(1 + sinrMax)); % cellule{q,t}.RB(rbChoix).SINR)
                qvalMax=W*abs(log2(1+sinrMax)); %fct QValue  %cellule{q,t}.RB(rbChoix).SINR)
                apprMax=cellule{q,ta}.probCollision * qvalMax; %fct d'apprentissage
                                     
               if ((apprMax- Mat(t).apprentissageRB(q,wwRbConfli) >0) && (sinrMax > cellule{q,t}.RB(wwRbConfli).SINR) )
                     newRB=  rbChoix; %pr choisir le meilleur RB
                     okchoixRBdispo=1; 
                     
                     
                        if t>1  
                            if (apprMax- Mat(t-1).apprentissageRB(q,wwRbConfli) >0)
                                newRB=  rbChoix; %pr choisir le meilleur RB
                                okchoixRBdispo=1;
                            end
                        else
                         newRB=  rbChoix; %pr choisir le meilleur RB
                         okchoixRBdispo=1; 
                       end
                else
                     newRB=  wwRbConfli;
                     okchoixRBdispo=0;
               end 
          
            end 
           else
               if ( length(RB_usedOK)==0)
                  newRB=  wwRbConfli;
                  %              disp('**********'); 
                  okchoixRBdispo=0;
              %    fprintf('PAS DE RB DISPO PR LA CELLULE %d \n', q);
               end
            end
          
           
     end             
                      %04/07/2013 ==> a voir
 if (newRB ~= wwRbConfli)           
    if (okchoixRBdispo == 1 ) 
        fprintf('COUNT= %d ---- cell %d -- RB %d   --new %d \n', COUNT,q, wwRbConfli,newRB);

             okchoixRBdispo=-1;
             rbPROBLM{q}=[rbPROBLM{q}, wwRbConfli]; %27/09 pr connaitre les gens que j'ai retiré
             cellule{q,ta}.nbrRBmodif=cellule{q,ta}.nbrRBmodif+1; %27/08
             uRB =  find(cellule{q,ta}.rbUserPris == wwRbConfli) ; %indexe de l user utilisant le wwRbConfli
             cellule{q,ta}.user(uRB).rb = newRB; %comment
               % récupérer le num du user uRB ??????
                          
             cellule{q,ta}.rbUserPris(uRB)=newRB; %mise à jour du vecteur des RB de la cellule q
             switch varianteChooseRB                 
               case 1       
                   cellule{q,t}.RB(newRB).SINR=sinrMax;
                   cellule{q,t}.RB(newRB).Throughput=debMax;
                   Mat(t).qValue(q,newRB)=qvalMax;
                   Mat(t).apprentissageRB(q,newRB)=apprMax;
               case 2
                   sommeDistUsersAb=0;
                   for ttaaea=1:length(cellule{q,ta}.voisins)  
                       voiizz=cellule{q,ta}.voisins(ttaaea);
                       okuRB =  intersect(cellule{voiizz,ta}.rbUserPris, newRB) ; %indexe de l user utilisant le wwRbConfli
                       if (length(okuRB)==1)
                            sommeDistUsersAb=sommeDistUsersAb + cellule{voiizz,ta}.RB(okuRB).puissance * ((1/ cellule{voiizz,ta}.RB(okuRB).dist)^beta); %on peut egalement passer par l user
                            %premiere etape: calculer les SINR
                
                       end  
                    end
                    %modif pr le calcul du SINR  
                    cellule{q,t}.RB(newRB).SINR = calculSINR(cellule{q,ta}.RB(newRB).dist, sommeDistUsersAb , PuisUsed(q,newRB), beta, noise);
                    cellule{q,t}.RB(newRB).Throughput = W *abs(log2(1 + cellule{q,t}.RB(newRB).SINR)); % cellule{q,t}.RB(rbChoix).SINR)
                    Mat(t).qValue(q,newRB)=W*abs(log2(1+cellule{q,t}.RB(newRB).SINR)); %fct QValue  %cellule{q,t}.RB(rbChoix).SINR)
                    Mat(t).apprentissageRB(q,newRB)=cellule{q,ta}.probCollision * Mat(t).qValue(q,newRB); %fct d'apprentissage
             
            
               case 3
                    cellule{q,t}.RB(newRB).SINR=sinrMax;
                    cellule{q,t}.RB(newRB).Throughput=debMax;
                    Mat(t).qValue(q,newRB)=qvalMax;
                    Mat(t).apprentissageRB(q,newRB)=apprMax;
              end
     
                    Mat(t).tabRB(q,newRB) = 1; % pr dire k ce rb est occupe 
                    Mat(t).tabRB(q,wwRbConfli) = 0; %  
 
                    cellule{q,1}.cumulDebit = cellule{q,1}.cumulDebit - cellule{q,t}.RB(wwRbConfli).Throughput + cellule{q,t}.RB(newRB).Throughput; %20/08
                    cellule{q,t}.RB(wwRbConfli).Throughput=0; %car il n est plus utilisé
                    cellule{q,t}.RB(wwRbConfli).SINR =0; %car il n est plus utilisé        
                    Mat(t).matriceRNTP(q,wwRbConfli)=1;
                    Mat(t).matriceRNTP(q,newRB)=2;
                   % fprintf ('*******  JE SUIS ICI ******** \n');
                  
                    rbCommNew=setdiff(unionRB, wwRbConfli);
                    unionRB=rbCommNew;
                    unionRB=[unionRB,newRB ];
                    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                    fprintf(fiSINR_DebitA, '%d \t %d \t %d \t %d \t %f \t %f \t %f \n', t,q,  voisin, newRB,cellule{q,ta}.RB(newRB).dist, cellule{q,t}.RB(newRB).SINR, cellule{q,t}.RB(newRB).Throughput);  
                     
                    if(t>1)     
                                Mat(t).gain(q,newRB)= abs(Mat(t).apprentissageRB(q,newRB) - Mat(t).apprentissageRB(q,wwRbConfli));     %26/07/2013  à voir avant c était   - Mat(t).apprentissageRB(q,newRB);  
                                Mat(t).gainTotal(q,newRB) =  Mat(t-1).gainTotal(q,newRB) + Mat(t).gain(q,newRB); %Mat(t-1).gainTotal(q,newRB) +
                               %%%%%%% 
                               % Mat(t).gainCell(q)=Mat(t).gainCell(q)- Mat(t).gainTotal(q,wwRbConfli) + Mat(t).gainTotal(q,newRB);
                            %    diffGainTotal(newRB) = Mat(t).gain(q,newRB); % - Mat(t).gain(q,wwRbConfli);
                             
                                diffGainTotal(q,newRB) = Mat(t).qValue(q,newRB) - Mat(t-1).qValue(q,newRB);
                      
                            else
                                %init 

                                Mat(t).gain(q,newRB)=abs(Mat(t).apprentissageRB(q,newRB) - Mat(t).apprentissageRB(q,wwRbConfli));  %Mat(t).apprentissageRB(q,newRB);  
                                Mat(t).gainTotal(q,newRB) = Mat(t).gain(q,newRB);
                               %%%%%%% 
                                Mat(t).gainCell(q)=0;
                                Mat(t).sinrCell(q)=0;
                                Mat(t).apprentiCell(q)=0;
                                
                                Mat(t).apprentiCellALL(q)=0;
                                Mat(t).gainCellAll(q)=0;
                                Mat(t).sinrCellAll(q)=0;
                            
                          %     diffGainTotal(newRB) = Mat(t).gain(q,newRB);% - Mat(t-1).gainTotal(q,wwRbConfli);                 
                               diffGainTotal(q,newRB) = Mat(t).qValue(q,newRB);% - Mat(t-1).gainTotal(q,wwRbConfli);
                         
                            end
                             gainTotalCell(q,newRB)=Mat(t).gainTotal(q,newRB);%  Mat(t).gainTotal(q,newRB);
                          
                             %%%%27/09
                             
                             gainTotalCell(q,newRB)=Mat(t).gain(q,newRB);%  Mat(t).gainTotal(q,newRB);
 
                        else
                            %pas de changement 
                             Mat(t).matriceRNTP(q,wwRbConfli)=2;
                       
                        end                   
                end
    end               
 end

   %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        cellRBcommon{q}=unionRB;  %26/09
%RB_Cellll=setdiff(cellule{q,ta}.rbUserPris,  cellRBcommon{q}, 'stable');

%%%%%%%%%%%%%%%  A RENDRE PLUS TARD
%RB_Cellll=setdiff(affectionINIT{q}, rbPROBLM{q}, 'stable'); %27/09 ==> je prend en compte la première affectation avec les rb que j'ai retiré pr avoir l'ensemble des rbs ou il faut leur recalculer

%   if (length(RB_Cellll) > 0)
%       %revéfier
%      % disp('******');
%         for uuRB=1:length(RB_Cellll)
%              rb_A=RB_Cellll(uuRB); 
%              sumDist=0;
%              for ttapa=1:length(cellule{q,ta}.voisins)
%                voisinns=cellule{q,ta}.voisins(ttapa);
%                okuRBa =  intersect(cellule{voisinns,ta}.rbUserPris, rb_A) ; %indexe de l user utilisant le wwRbConfli
%                if (length(okuRBa)==1)
%                  sumDist=sumDist + cellule{voisinns,ta}.RB(okuRBa).puissance * ((1/ cellule{voisinns,ta}.RB(okuRBa).dist)^beta); %on peut egalement passer par l user
%                  %premiere etape: calculer les SINR     
%                end  
%              end
%              
%                   cellule{q,t}.RB(rb_A).SINR = calculSINR(cellule{q,ta}.RB(rb_A).dist, sumDist, PuisUsed(q,rb_A), beta, noise);
%              %  fprintf('--------------- t=%g\t\t q=%g\t\t RB=%g \t \t SINR =%f  \n',t,q, rb_aaA, cellule{q,t}.RB(rb_aaA).SINR);
%                  %30/08 
%                   cellule{q,t}.RB(rb_A).Throughput = W * abs(log2(1 + cellule{q,t}.RB(rb_A).SINR));
%                   cellule{q,1}.cumulDebit=cellule{q,1}.cumulDebit+cellule{q,t}.RB(rb_A).Throughput; %20/08            
%                   Mat(t).qValue(q,rb_A)=W*abs(log2(1+cellule{q,t}.RB(rb_A).SINR)); %fct QValue 
%               %26/09 ==> obligatoire de garder en sauvegarde la valeur
%               %précédente de la fct d'apprentissage
%                   valINIT= Mat(t).apprentissageRB(q,rb_A);
%                   Mat(t).apprentissageRB(q,rb_A)=cellule{q,ta}.probCollision * Mat(t).qValue(q,rb_A); %fct d'apprentissage
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
   %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    else
     LLV{q}=[];   
   end
 




cumulGainTotal=0;
cumSINR=0;
cumAPPRENTI=0;


for allRB=1:length(cellule{q,ta}.rbUserPris)
    rbActuel=cellule{q,ta}.rbUserPris(allRB);
  

    cumulGainTotal= cumulGainTotal + gainTotalCell(q,rbActuel); % Mat(t).gainTotal(q,rbActuel);
    cumSINR=cumSINR+cellule{q,t}.RB(rbActuel).SINR ; %05/09
    cumAPPRENTI=cumAPPRENTI + Mat(t).apprentissageRB(q,rbActuel);
     % vvvvv=0;
   % fprintf(fiSINR_Debit, '%d \t %d \t %d \t %d \t %f \t %f \t %f \n', t,q, vvvvv,  rbActuel, cellule{q,ta}.RB(rbActuel).dist, cellule{q,t}.RB(rbActuel).SINR, cellule{q,t}.RB(rbActuel).Throughput); %t \t cellule{q,t}.RB(wwRbConfli).SINR
                      %t, '\t', cellule{q,t}.RB(wwRbConfli).SINR, 

end
    COUNT=COUNT+1; 
  %       %27/09
     if (COUNT>1 )
         gainGlobal(q, COUNT)= gainGlobal(q, COUNT-1) + cumulGainTotal; %gainTotalCell(q,rbActuel);
       
         for jjj=1:V
           if (jjj~=q)  
             if (COUNT<=V)  
               zzzz=COUNT-1;
             else
               zzzz= mod(COUNT, V)+1;
             end
             %  gainGlobal(jjj, COUNT)=gainGlobal(jjj, zzzz);
               gainGlobal(jjj, COUNT)=gainGlobal(jjj, COUNT-1);
           end
         %  disp(gainGlobal(jjj, COUNT));
         end  
     else
         if q==1
          gainGlobal(q, COUNT)=  cumulGainTotal; %; gainTotalCell(q,rbActuel);  
                   
         for jjj=2:V
          gainGlobal(jjj, COUNT)=0; %gainGlobal(jjj, mod(COUNT, V));
         end 
         end
     end


 if(t>1)
        Mat(t).gainCellAll(q)=Mat(t-1).gainCellAll(q) + cumulGainTotal;
        Mat(t).sinrCellAll(q)= Mat(t-1).sinrCellAll(q) + cumSINR; %05/09
      %  fprintf('** t-1=%g\t\t q=%g\t\t gainCell(t)=%f \t \t gainCell(t-1)= %f\n',t-1,q,Mat(t).gainCell(q), Mat(t-1).gainCell(q));   
        Mat(t).gainCell(q)= gainGlobal(q, COUNT); %cumulGainTotal; % Mat(t-1).gainCell(q) +

else 
        Mat(t).gainCell(q)=  gainGlobal(q, COUNT); %cumulGainTotal;
        Mat(t).gainCellAll(q)=cumulGainTotal;
        Mat(t).sinrCellAll(q)= cumSINR; %05/09
 end
 zzaaazz=1;
 if ( COUNT>1)
           if ((COUNT<=V)  ) 
               zzaaazz=COUNT-1;
             else
               zzaaazz= mod(COUNT, V)+1;
           end
    fprintf(fitesttttt, '%d \t %d \t %d  \t %g \t  \t %g \t \t %g \t \t %g \n', t, q,  COUNT,   Mat(t).gainCell(q), gainGlobal(q, COUNT), gainGlobal(q, COUNT-1), cumulGainTotal);
 else
     
    fprintf(fitesttttt, '%d \t %d \t %d  \t %g \t  \t %g \t \t %g \t \t %g  \n', t, q,  COUNT,   Mat(t).gainCell(q), gainGlobal(q, COUNT), 0, cumulGainTotal);
     
 end

 countITER(q)=countITER(q)+1; %cumul du nbre d iteration necessaire
 
 
 
for qcell=1:V 
    
OutpuVerfiAAAbbb= strcat('Iter-', num2str(qcell), '.dat');
    if (COUNT==1)
         fiTestAAAbbbbb=fopen(OutpuVerfiAAAbbb, 'w');  %wt
    else
         fiTestAAAbbbbb=fopen(OutpuVerfiAAAbbb, 'a+');  %wt
    end 
%if      COUNT > 7   
fprintf(fiTestAAAbbbbb, '%d \t %d \t %g \t %f \t %g \t %g\n', qcell, COUNT, countITER(qcell), gainGlobal(qcell, COUNT), cellule{qcell,1}.cumulDebit); %tabREWARD(q));  , Mat(t).gainCell(qcell)
% else
%  fprintf(fiTestAAAbbbbb, '%d \t %d \t %g \t %f \t %g \t %g\n', qcell, COUNT, countITER(qcell), gainGlobal(qcell, COUNT), cellule{qcell,1}.cumulDebit, 0); %tabREWARD(q));   
% end
fclose(fiTestAAAbbbbb);
end
 
%  if COUNT>1
%  if (gainGlobal(q, COUNT) ~= gainGlobal(q, COUNT-1))
%       Mat(t).gainCell(q)=gainGlobal(q, COUNT);
%  else
%            Mat(t).gainCell(q)=gainGlobal(q, COUNT-1);
%  end
%  else
%      Mat(t).gainCell(q)=gainGlobal(q, COUNT);
%  end
%Mat(t).gainCell(q)= cumulGainTotal;
Mat(t).sinrCell(q)= cumSINR; %05/09
Mat(t).apprentiCell(q)=cumAPPRENTI;

if t>1 Mat(t).apprentiCellALL(q)=Mat(t-1).apprentiCellALL(q)+cumAPPRENTI;
else
    Mat(t).apprentiCellALL(q)=cumAPPRENTI;
end
fprintf(fiTest, '%d \t %d \t %f \t %f \t  %f  \n', q, t, Mat(t).gainCell(q), Mat(t).gainCellAll(q),  cellule{q,ta}.probCollision );  

fprintf(fiTestAAA, '%d \t %d \t %f \t %f \t %f \t %f \t %f \t %f \n', q, t, Mat(t).gainCell(q),Mat(t).gainCellAll(q), cellule{q,ta}.probCollision, Mat(t).apprentiCellALL(q), Mat(t).sinrCell(q), Mat(t).apprentiCell(q) );  
 
%arrivée d un msg CQI  ==> 10/07/2013 ==> 20/08 modif d'emplacement de ce
%test
if (mod(COUNT, t_CQI) ==0) %c COUNT au lieu de t pr le modulo
    cpt_CQI(q)=cpt_CQI(q)+1;  
        %  Mat(t).gainCell(q);    
    %écriture dans un fichier 20/08 la fct globale de chaque cellule pr tracer une courbe en fct du nbre d'itérations
 %27/08
    OutputFileGainProb= strcat('Gain&Proba-', num2str(q), '.dat'); %pr les attentes et transmis
    if (cpt_CQI(q)==1)
         fiDistrib = fopen(OutputFileGainProb, 'w');  %wt
   % fprintf(fiDistrib, '%d \t %f \t %f \n',  q,  PI{yy}(xx), sommeProba);  %indice de la trame et sa taille
    else
          fiDistrib = fopen(OutputFileGainProb, 'a+');  %wt
    end
    
   fprintf(fiDistrib, '%d \t %d \t %f \t %f \t %f  \t %f \t %f \n', q, t, Mat(t).gainCellAll(q), Mat(t).gainCell(q), cellule{q,ta}.probCollision, Mat(t).apprentiCell(q), Mat(t).sinrCell(q) );  
   fclose(fiDistrib);
end
fclose(fiTestAAA);




 
%if q<V 

%end
end %le end de l'ensemble des cellules 

%%%%%%%%%%%%%%fin du parcours de toutes les cellules

   if ((cpt_RNTP >= 1) && (t> dur1RNTP) ) %on utilise cette variable pour être sur que l'on a bien reçu déjà un premier msg RNTP
     for celParcour=1:V
      for inde=1:length(cellule{celParcour,ta}.voisins) 
        %on suppose que les cellules restent à la config initiale (indice t=1) par rapport aux voisinages cellule{q,1}.voisins
        vois=cellule{celParcour,ta}.voisins(inde);
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
  
     
      for xxC=1:V
      Outputfichier= strcat('SINR_Throug-', num2str(xxC), '.dat'); %03/09
         if t==1 
             fiSINRDebit = fopen(Outputfichier, 'w');  %wt
         else
              fiSINRDebit = fopen(Outputfichier, 'a+');  %wt
         end
      
       for allRBx=1:cellule{xxC,ta}.nbrUser   %length(cellule{xx,ta}.rbUserPris)
            indexRB=cellule{xxC,ta}.rbUserPris(allRBx);
%             if t==1 
%              fprintf('------ t=%g \t\t cellule =%g\t\t RB=%g \t \t SINR =%f  \t \t   \n',t,xxC, indexRB, cellule{xxC,t}.RB(indexRB).SINR);         
%             else
%              fprintf('------ t=%g \t\t cellule =%g\t\t RB=%g \t \t SINR =%f  \t \t  t-1   =%g \t \t SINRaa =%f  \t \t nbremodif = %d \n',t,xxC, indexRB, cellule{xxC,t}.RB(indexRB).SINR, t-1,  cellule{xxC,t-1}.RB(indexRB).SINR, cellule{q,ta}.nbrRBmodif);         
%             end
            %03/09 ==> rajout de c fichiers
       fprintf(fiSINRDebit, '%d  \t %d \t %d \t %f \t %f \t %f \n', t,xxC,   indexRB, cellule{xxC,ta}.RB(indexRB).dist, cellule{xxC,t}.RB(indexRB).SINR, cellule{xxC,t}.RB(indexRB).Throughput);      
       end
        fclose(fiSINRDebit);
      end
% % 06/08/2013
%==> condition de stabilité ==> convergence de l algo
 
% if COUNT>=2
%      celluleOKiii=[];
%     switch varianteStab
%         case 1    
%             diffG=0;
%             for cc=1:V
%                 diffG=gainGlobal(cc, COUNT)-gainGlobal(cc, COUNT-1);
%                 if (diffG<= epsilon) %round(diffG)==0)   % ==0   <= epsilon
%                     %rajout du round 05/09
%                      okStable=okStable+1;
%                      celluleOKiii=[celluleOKiii, cc];
%                      continuer=0;
%                 else
%                      continuer=1;
%                 end
%             end   
%             
%       end
%    
%    disp(celluleOKiii);  %25/09
%    
%    
%         
%    
%     if q==V 
%     COUNT=COUNT+1; 
%     end
% end


if t>=2     
    celluleOKiii=[];
 
    switch varianteStab
        case 1    
            %utiliser la fct de gain globale au sein de chaque cellule
            diffG=0;
            diffG1=0;
            for cc=1:V
                diffG=Mat(t).gainCell(cc)-Mat(t-1).gainCell(cc);
                if (COUNT<=V)  
                     zzzz=COUNT-1;
                else
                     zzzz= mod(COUNT, V)+1;
                end
            %    diffG1 = gainGlobal(cc, COUNT) - gainGlobal(cc, zzzz);
               %diffG
                if (diffG<= epsilon) %round(diffG)==0)   % ==0   <= epsilon
                    %rajout du round 05/09
                     okStable=okStable+1;
                     celluleOKiii=[celluleOKiii, cc];
                     continuer=0;
                               %   disp('i am here');
                else
                     continuer=1;
                end
            end
             %  disp(celluleOKiii); 
%             
%                %04/09 test rajouter
%             if(okStable==V)
%                   cptStable=cptStable+1;   
%             end
%             %04/09 test rajouter
%             if (cptStable == Nstabilisation)
%                  boolOKstable=1;
%             else
%                  boolOKstable=0;
%             end
%             
          
        case 2
            %07/08/2013
            %voir par rapport aux SINR des RBs utilisés
             diffSINR=0;
             tabSINRstable=zeros(1,V);

             for xxC=1:V
                for allRBx=1:cellule{xxC,ta}.nbrUser   %length(cellule{xx,ta}.rbUserPris)
                    %cellule{q,ta}.rbUserPris(uRB)
                    indexRB=cellule{xxC,ta}.rbUserPris(allRBx);
                    aa=t-1; 
                    diffSINR = cellule{xxC,t}.RB(indexRB).SINR - cellule{xxC,aa}.RB(indexRB).SINR; 
                  %  cellule{q,t}.RB(newRB).SINR
                    %Mat(t).gainCell(cc)-Mat(t-1).gainCell(cc); 
                    if (round(diffSINR)==0) %==0   <= epsilon
                          %rajout du round 05/09
                         okStableA=okStableA+1;
                         continuer=0;
                    else
                         continuer=1;
                    end
                end
                %modif rajouter le 28/08
                if(okStableA == length(cellule{xxC,ta}.rbUserPris)) 
                    tabSINRstable(xxC)=1;
                    continuer=0; %30/08
                 else
                     continuer=1;  %30/08
                end
             end
          
             
             for xw=1:V
                 if (tabSINRstable(xw)==1)
                     okStable=okStable+1;
                     celluleOKiii=[celluleOKiii, xw];
                 end
             end
          %   disp(celluleOKiii); 
%           %rajout de ce test 05/09   
%             if(okStable==V)
%                   cptStable=cptStable+1;   
%             end
%             %04/09 test rajouter
%             if (cptStable == Nstabilisation)
%                  boolOKstable=1;
%             else
%                  boolOKstable=0;
%             end
%              
        case 3  
             %05/09   
           %utiliser la fct de SINR globale au sein de chaque cellule 
            diffSS=0;
            for cc=1:V
                diffSS=Mat(t).sinrCell(q) - Mat(t-1).sinrCell(q) ; 
                if (diffSS<= epsilon) %round(diffSS)==0)   % ==0   <= epsilon
                    %rajout du round 05/09
                     okStable=okStable+1;
                     celluleOKiii=[celluleOKiii, cc];
                     continuer=0;
                else
                     continuer=1;
                end
            end
           % disp(celluleOKiii); 
%              %04/09 test rajouter
%             if(okStable==V)
%                   cptStable=cptStable+1;   
%             end
%             %04/09 test rajouter
%             if (cptStable == Nstabilisation)
%                  boolOKstable=1;
%             else
%                  boolOKstable=0;
%             end
%             
%              
            
            %07/08/2013 ==> a venir
            %tester sur le nbre d interférences entre 2 itérations non
            %consécutives pour chacune des cellules comme ce que j'avais
            %fait pr le SP3   
  
       case 4   
            %utiliser la fct de gain globale au sein de chaque cellule
            diffAPP=0;
            for cc=1:V
                diffAPP=Mat(t).apprentiCell(cc)-Mat(t-1).apprentiCell(cc); 
                if (diffAPP <= epsilon) %round(diffAPP)==0)   % ==0   <= epsilon
                    %rajout du round 05/09
                     okStable=okStable+1;
                     celluleOKiii=[celluleOKiii, cc];
                     continuer=0;
                else
                     continuer=1;
                end
            end
          %   disp(celluleOKiii);  %utile pr les verifs ==> 11/09
       
    end %fin du switch
  
    
    
    
 
    
    
    
   disp(celluleOKiii);  %25/09
 
%   disp(cellule{q,1}.nbrRBmodif);
end

           
  
if boolll == 1
     sauv=t;
     for ce=1:V
         T{sauv}.Cel{ce}=unique(LLV{ce});

     end
end
 
if boolTest==1
    sauvegardddd=t;
    for indC=1:V
        T{sauvegardddd}.cellO{indC}=unique(RRC{indC});
    end
end

%ce test permet d indiquer d'un msg RNTP est arrivé et qu il faut verifier
%par rapport à la convergence de l algo
   if (mod(COUNT, t_RNTP) == 0)  %c COUNT au lieu de t
     %arriver d un msg RNTP
     cpt_RNTP=cpt_RNTP+1; %compteur du nombre de msg RNTP
  
        % note le 03/07/2013: a voir ce qui suit
        % il faut comparer la matrice à l instant (t) et à (t-1) pr voir s
        % il y a eu changement si c le cas pas de convergence encore
        
%      for celParcour=1:V
%       for inde=1:length(cellule{celParcour,ta}.voisins) 
%         %on suppose que les cellules restent à la config initiale (indice t=1) par rapport aux voisinages cellule{q,1}.voisins
%         vois=cellule{celParcour,ta}.voisins(inde);
%         if (Mat(t).matriceInterf(celParcour,vois) >  Mat(t).matriceInterf(celParcour,vois))
%             continuer=1;
%         else
%             continuer=0; %il faut arrêter l'algo, convergence OK
%         end
%       end 
%      end
        
   end
       
          %j'ai déplacé ce test 05/09  car il était répétitif dans les 3 cas du switch  
            if (t>1) 
            if(okStable==V) 
                cptStable(t)=cptStable(t-1)+1;   %06/09  
                instantT=[instantT, t];
                cumulCPT=[cumulCPT, cptStable(t)];
            else
                cptStable(t)=0; %cptStable(t-1); %modif le 12/09
                instantT=[];
                cumulCPT=[];
            end
            else
                cptStable(t)=0;
                instantT=[];
                cumulCPT=[];
            end
            %04/09 test rajouter
            if (cptStable(t) == Nstabilisation)
                 boolOKstable=1;
                 
                % break; %06/09 
            else
                 boolOKstable=0;
            end 
            if(t>1) %06/09
              if ((cptStable(t) >1) &&(cptStable(t) - cptStable(t-1) == 1)) %1 
                %  fprintf(2,'------------------ t=%g \t \t cptStable=%g \t \t okStable= %g  \t \t okiii= %g \n \n',t, cptStable(t), okStable, okiii);
               if(cptStable(t) == Nstabilisation)
               %   fprintf(fileStable,'%g \t \t %g \t \t %g \t \t %g  \n',t, cptStable(t), okStable, okiii);
                  boolEND=1;
                  OKtrouve=find(cumulCPT == 1);
                  if(length(OKtrouve)==1) 
                      VALSTABLITE=instantT(OKtrouve); 
                  end
                  tConverg=t; %tConverg+1; 
                  break;
              end
              else
                  boolEND=0;
              end
            end
          %  fprintf(2,'################ t=%g \t \t cptStable=%g \t \t okStable= %g  \t \t okiii= %g \n \n',t, cptStable(t), okStable, okiii);
             fprintf(fileStable,'%g \t \t %g \t \t %g \t \t %g  \n',t, cptStable(t), okStable, okiii);
                
 t=t+1;  
end

 zzaaazz=1;
COUNT
 for qcell=1:V 
    
OutpuVerfiAAAbbb= strcat('IterCellule-', num2str(qcell), '.dat');
 %   if (COUNT==1)
         fiTestAAAbbbbb=fopen(OutpuVerfiAAAbbb, 'w');  %wt
%     else
%          fiTestAAAbbbbb=fopen(OutpuVerfiAAAbbb, 'a+');  %wt
%     end 
%if      COUNT > 7   
for kkkk=1:VALLLL %COUNT
    if kkkk<=COUNT
        fprintf(fiTestAAAbbbbb, '%d \t %d \t %g \t %g \t %g \n', qcell, kkkk, countITER(qcell), gainGlobal(qcell, kkkk), cellule{qcell,1}.cumulDebit); %tabREWARD(q));  , Mat(t).gainCell(qcell)
    else
       fprintf(fiTestAAAbbbbb, '%d \t %d \t %g  \t %g \t %g\n', qcell, kkkk, countITER(qcell), gainGlobal(qcell, COUNT), cellule{qcell,1}.cumulDebit); %tabREWARD(q));   
    end
end
fclose(fiTestAAAbbbbb);
end
 
 for indcell=1:V
    OutpuVerzzzz= strcat('VerfiGainzzzzzzzzzzzzz-', num2str(indcell), '.dat'); 
    fitestttttcell= fopen(OutpuVerzzzz, 'w');

     
     for cpt=1:(COUNT)
           if ((cpt<=V) && (cpt>1) ) 
               zzaaazz=cpt-1;
             else
               zzaaazz= mod(cpt, V)+1;
           end
           
           if cpt>1
            fprintf(fitestttttcell, '%d \t %d \t %d  \t %g \t  \t %g \t \t %g \t \t %g \n', t,indcell,  cpt,   Mat(t).gainCell(indcell), gainGlobal(indcell, cpt), gainGlobal(indcell, cpt-1), cumulGainTotal);
           else   
           fprintf(fitestttttcell, '%d \t %d \t %d  \t %g \t  \t %g \t \t %g \t \t %g \n', t,indcell,  cpt,   Mat(t).gainCell(indcell), gainGlobal(indcell, cpt), 0, cumulGainTotal);
      
           end
     end
     fclose(fitestttttcell);
 end




 if (boolEND==1) 
   %  fprintf(2,' t=%g \t \t cptStable=%g \t \t okStable= %g \t \t okiii=%g  \n',t, cptStable(t), okStable, okiii);
     fprintf(fileStable,'%g \t \t %g \t \t %g \t \t %g  \n',t, cptStable(t), okStable, okiii);

 else
   % fprintf(2,' t=%g \t \t cptStable=%g \t \t okStable= %g \t \t okiii=%g  \n',t-1, cptStable(t-1), okStable, okiii);
    fprintf(fileStable,'%g \t \t %g \t \t %g \t \t %g  \n',t-1, cptStable(t-1), okStable, okiii);

 end
 if ((t>1) && (okStable== V) )
     %26/08 rajout de ce test; et correction que sur la division c par
     %(t-1) et non t
     calcNbreMoyenInterf=0;
     calcNbreModifTotal=0;

     sortiFILEA= strcat('nbreMODIF.txt'); %pr le débit
     fileMODIF=fopen(sortiFILEA, 'w');

    for qaa=1:V  %03/09
        calcNbreModifTotal=calcNbreModifTotal+ cellule{qaa,1}.nbrRBmodif; 
         fprintf(fileMODIF,'%d \t %d \t %d \n', qaa, t, cellule{qaa,1}.nbrRBmodif);
    end
    fclose(fileMODIF);
    for qa=1:V
     %20/08==> indice de perf
        debitMoyen(qa)=cellule{qa,1}.cumulDebit/(t-1);
        nbreInterfMoyen(qa)=cellule{qa,1}.cumulInterfRB/(t-1);
        fprintf(fichierA, '%d \t %d \t %d  \t %d  \t %f \t %f \t %d \n', (t-1), qa, N, cellule{qa,1}.nbrUser,  debitMoyen(qa), nbreInterfMoyen(qa), cellule{qa,ta}.nbrRBmodif );  
      %pr le tracer de ces deux courbes debit moyen et nbre d interference moyenne, cela se fera avec gnuplot ou excel par la suite car ilfaut tte les valeurs      
       %le N correspond au nbre de RB max/cell
    end
 end
 
 if ( (okStable== V) && (cptStable(t) == Nstabilisation))
  sortiFILEeee= strcat('resumeConv.txt'); %pr le débit
  fileStableeeee=fopen(sortiFILEeee, 'w');
   
   fprintf ('---------  FIN CONVERGENCE OK   --------- COUNT = %d \n', COUNT);
   fprintf(' PREMIERE STABLITE %d \t nbre calcNbreModifTotal= %d *****  -- %d ms  \t duree de convergence  \n',VALSTABLITE,  calcNbreModifTotal,   tConverg);
  
   fprintf(fileStableeeee, '%d \t %d \t %d \t %d \n', VALSTABLITE, calcNbreModifTotal, COUNT, tConverg  );
   for uu=1:V 
    fprintf('====== reçu %d  \t msg RNTP  ---- \t %d msg CQI \n', cpt_RNTP, cpt_CQI(uu));
   end 
 % fprintf ('---------  FIN CONVERGENCE OK   --------- nbre calcNbreModifTotal= %d ***** reçu %d  \t msg RNTP  ---- \t %d msg CQI -- %d ms  \t duree de convergence  \n', calcNbreModifTotal, cpt_RNTP, cpt_CQI,  tConverg);
 
 fclose(fileStableeeee);
 end
 fclose(fitesttttt);
fclose(fileStable);
fclose(fiSINR_DebitA);
fclose(fiSINR_Debit); %pr vérifier les valeurs des débits et SINR

fclose(fiTest);
fclose(fiRecompGain);
fclose(fichierA); %les graphiques se feront en dehors de ce code matlab
 