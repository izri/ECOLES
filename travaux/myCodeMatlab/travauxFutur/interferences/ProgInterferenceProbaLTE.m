historique
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% clear all;
% clc;
%rand('state',sum(100*clock)) %initialisation du générateur aléatoire
%close all;
%clf %clear figure
varianteStab=1; %1: usage de la fct de gain globale pr chaque cellule; 2 : usage du SINR pr chaque RB de chaque cellule

varianteALGO=1; %1: tous les users utilisent la meme puissance de transmission dans tout le reseau; 2: les users d'une meme cellule sont sur la meme puisssance; 3: la puissance de transmission d un user est en fct de sa distance par rapport au eNB
varianteChooseRB=3;
Nstabilisation=2; %pr verifier que pendant ce nbre d itérations les paramètres n ont pas changé
N =6;     %Number of RBs/cell  ==> 6 pr SOAPS

strategy=1; %pour choisir soit l'utilisation de la distance ou des proba 
distributionProba=1; %pr le choix entre une distribution uniforme ou bien les zones
zone=1; %pr choisir soit la zone 1 (celle au tour du eNodeB) ou la 2 
repartitionZone=1; %1: répartition de la cellule en deux zones identiques, 2: répartition en 2/3 au tour du eNB et 1/3 extérieur





VALLLL=100;
VALSTABLITE=0;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
R = 500;     %Radius of Hexagon==> rayon km ==> convertir en m 01/10/2013
charge=0.8;
M = round(N*charge);     %Number of users => au max nbre user= nbre de RBs
%utilisation de "round" pr convertir le réel en un entier
V=7; %number of cells => pr le moment nous considerons uniquement 7 cellules
rayonPorte_eNB=10; %km
W=180000; %hz bande passante ==> c 180khz pr 1 RB %10/07/2013
%PuissBruit=2; %puissance du bruit, je l avais rajouté en pensant utilisé
%la formule de shannon directement mais je remplace ca par le SINR
t=1; %indice de temps
T_max=1000; %temps de simul
dur=10; %pr la duree max de communication
t_RNTP=200;%200; %a chaque 200 ms un msg RNTP est envoye sur le lien X2
dur1RNTP=t_RNTP;
t_CQI=2; % 2ms mais max c 3 ms 10/07/2013
cpt_CQI=zeros(1,V);
tConverg=1; % compteur pr calculer le temps de convergence de l algo, il fait que ca soit un multiple de t_RNTP
cpt_RNTP=0; %compteur du msg RNTP
TmaxConvergence=1000; %il ne faudrait pas que l'algo converge avec un temps > à 1000 ms; condition:  t_RNTP <= tConverg <= TmaxConvergence
COUNT=1;
epsilon=10^(-5);
alpha=2;
PuisMax= 40; %50w
portion=0.8;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
PuisSeuil = PuisMax*portion; %c juste un exemple
PuisUsedAll=randi([1, PuisSeuil], 1, 1); %PuisMax
noise=10^(-alpha)*PuisMax; %noise variance  on peut egalement le prendre directement comme etant 10^(-alpha)

beta=4; %valeur essentiel pour le calcul du SINR d'un user

PuisUsed=zeros(V, N);
debitMoyen=zeros(V); %20/08
nbreInterfMoyen=zeros(V); %20/08
 %choisir une puissance que tous les users vont avoir pr la premiere variante de l algo
%%%%%%%%%%%%%%%%%%%%%%%%%%%%
tabRB=zeros(V, N);
matriceRNTP=zeros(V, N);%cette matrice va contenir des 1 ou des 0 ==> 1 : le RB est utilise avec une puissance max ==> pas bon car il va déranger
%apprentissageRB=zeros(V, N);
%qValue=zeros(V, N);
%gain=zeros(V, N);
%gainTotal=zeros(V, N); %fct gain total au sein de chaque cellule, c la fct a maximiser sur un RB
%%gainGlobal=zeros(1,V);
matriceInterf=zeros(V, V); %contient le nbre de RB qui interfere entre une cellule i et une cellule j ==> NBRE D INTERFERENCE
%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%les trois variables svtes sont defini pr les ajustement des cellules
c1=R*1.732;
c2=R*0.866;
c3=R*1.500;
%le tableau ajust permet de manupuler les ajustements des cellules ainsi
%que les users
%le vecteur ajust correspond aux coordonnees des eNBs
eNB{1}.x=0; eNB{1}.y=0; %center 
eNB{2}.x=0; eNB{2}.y=c1; % Upper hex
eNB{3}.x=0; eNB{3}.y=-c1; % Lower hex
eNB{4}.x=c3; eNB{4}.y=-c2;  % Right lower hex
eNB{5}.x=c3; eNB{5}.y=c2;  % Right upper hex
eNB{6}.x=-c3; eNB{6}.y= c2;    % Left upper hex
eNB{7}.x=-c3; eNB{7}.y=-c2;  % Left lower hex
ta=1; %a revoir car pr le moment le rbUserActifs est fixé à l étape init alors que les users changent au fur et à mesure

OutputFileSINR_Throughput= strcat('fileSINR_Throughput.txt');
fiSINR_Debit = fopen(OutputFileSINR_Throughput, 'w');  %wt
OutputFileSINR_ThroughputA= strcat('fileSINR_ThroughputMODIF.txt');
fiSINR_DebitA = fopen(OutputFileSINR_ThroughputA, 'w');  %wt

OutputFileUser= strcat('nbrUserCell.txt'); %pr le débit
fi = fopen(OutputFileUser, 'w');  %wt

OutputFileGAIN= strcat('fctRecompGain.txt'); %pr le débit
fiRecompGain = fopen(OutputFileGAIN, 'w');  %wt
  OutpuVerzooozzz= strcat('VerfiGainzzzzzzzzzzzzz.txt'); 
    fitesttttt= fopen(OutpuVerzooozzz, 'w');

    
fileSortie= strcat('debitMoyInterfMoy.txt'); %pr le débit moyen et le nbre d interférences moyennes %26/08/2013
fichierA = fopen(fileSortie, 'a+');  %wt

OutpuVerfi= strcat('VerfiGain.txt'); %pr le 
fiTest = fopen(OutpuVerfi, 'w');  %wt

sortiFILE= strcat('timeSTABLE.txt'); %pr le débit
fileStable=fopen(sortiFILE, 'w');

gainTotalCell=zeros(V,N);

configNet

for c=1:V
    eNB{c}.porte=rayonPorte_eNB; %Km
    eNB{c}.puissanceMax=PuisMax; %db
end
%%%%%%%%%%
tp=linspace(0,2*pi,V); % génère le même t 7 fois (pr les 7 cellules)
%Generating a hexagon with centre (0,0) and,
% To generate 6 adjacent hexagon
% Generating a hexagon 
grid on  %06/09
hold on %06/09
%figure(1);

topologyNet

%%%%%%%%%%%
continuer = -1;
sauv=1;
sauvegardddd=1;
okStable=0;
okStableA=0;
cellInterf=[];

 
diffGainTotal=zeros(V,N);

sumDist=0;
 %calcul des indices a t=1
for indiCell=1:V
    for uurRB=1:cellule{indiCell,1}.nbrAgents %length(cellule{indiCell,ta}.rbUserActifs)
      rb_aA=cellule{indiCell,ta}.rbUserActifs(uurRB); 
      sumDist=0;
       for ttapa=1:length(cellule{indiCell,ta}.voisins)
                 voisinns=cellule{indiCell,ta}.voisins(ttapa);
                 okuRBa =  intersect(cellule{voisinns,ta}.rbUserActifs, rb_aA) ; %indexe de l user utilisant le wwRbConfli
                 if (length(okuRBa)==1)
                  sumDist=sumDist + cellule{voisinns,ta}.RB(rb_aA).puissance * ((1/ cellule{voisinns,ta}.RB(rb_aA).dist)^beta); %on peut egalement passer par l user
                 %premiere etape: calculer les SINR     
                end  
      
       end
      
        
      cellule{indiCell,t}.RB(rb_aA).SINR = calculSINR(cellule{indiCell,ta}.RB(rb_aA).dist, sumDist, PuisUsed(indiCell,rb_aA), beta, noise);
  
      %%%%%%%%%%%%%%%%%%%%%%
      cellule{indiCell,t}.RB(rb_aA).Throughput = W * abs(log2(1 + cellule{indiCell,t}.RB(rb_aA).SINR));
      cellule{indiCell,1}.cumulDebit=cellule{indiCell,1}.cumulDebit+cellule{indiCell,t}.RB(rb_aA).Throughput; %20/08            
      Mat(t).qValue(indiCell,rb_aA)=W*abs(log2(1+cellule{indiCell,t}.RB(rb_aA).SINR)); %fct QValue 
      Mat(t).apprentissageRB(indiCell,rb_aA)=cellule{indiCell,ta}.probCollision * Mat(t).qValue(indiCell,rb_aA); %fct d'apprentissage
 %%%%%%%%%%%
      Mat(t).gain(indiCell,rb_aA)= Mat(t).apprentissageRB(indiCell,rb_aA);% - Mat(sauvegardddd).apprentissageRB(indiCell,rb_aA); 
      Mat(t).gainTotal(indiCell,rb_aA) =  Mat(t).gain(indiCell,rb_aA);
      diffGainTotal(indiCell, rb_aA) = Mat(t).gain(indiCell,rb_aA); % - Mat(sauvegardddd).gainTotal(indiCell,rb_aA);  
      diffGainTotal(indiCell, rb_aA) = Mat(t).qValue(indiCell,rb_aA); % - Mat(sauvegardddd).gainTotal(indiCell,rb_aA);
      
      Mat(t).gainCell(indiCell)=0;
      Mat(t).sinrCell(indiCell)=0;
      Mat(t).apprentiCell(indiCell)=0;
         
      Mat(t).apprentiCellALL(indiCell)=0;
      Mat(t).gainCellAll(indiCell)=0;
      Mat(t).sinrCellAll(indiCell)=0;
      gainTotalCell(indiCell,rb_aA)=Mat(t).gain(indiCell,rb_aA);
    
    end
    cumulGainTotal=0;
    cumSINR=0;
    cumAPPRENTI=0;


for allRB=1:length(cellule{indiCell,ta}.rbUserActifs)
    rbActuel=cellule{indiCell,ta}.rbUserActifs(allRB);
    cumulGainTotal= cumulGainTotal + gainTotalCell(indiCell,rbActuel); % Mat(t).gainTotal(q,rbActuel);
    cumSINR=cumSINR+cellule{indiCell,t}.RB(rbActuel).SINR ; %05/09
    cumAPPRENTI=cumAPPRENTI + Mat(t).apprentissageRB(indiCell,rbActuel);
     % vvvvv=0;
   % fprintf(fiSINR_Debit, '%d \t %d \t %d \t %d \t %f \t %f \t %f \n', t,q, vvvvv,  rbActuel, cellule{q,ta}.RB(rbActuel).dist, cellule{q,t}.RB(rbActuel).SINR, cellule{q,t}.RB(rbActuel).Throughput); %t \t cellule{q,t}.RB(wwRbConfli).SINR
                      %t, '\t', cellule{q,t}.RB(wwRbConfli).SINR, 

end
     if (COUNT>1 )
         gainGlobal(indiCell, COUNT)= gainGlobal(indiCell, COUNT-1) + abs(cumulGainTotal); %gainTotalCell(q,rbActuel);
       
         for jjj=1:V
           if (jjj~=indiCell)  
               gainGlobal(jjj, COUNT)=gainGlobal(jjj, COUNT-1);
           end
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
      
       for allRBx=1:cellule{indiCell,ta}.nbrAgents   %length(cellule{xx,ta}.rbUserActifs)
            indexRB=cellule{indiCell,ta}.rbUserActifs(allRBx);
            fprintf(fiSINRDebit, '%d  \t %d \t %d \t %d \t %g \t %g \t %g \n', t,indiCell, COUNT,  indexRB, cellule{indiCell,ta}.RB(indexRB).dist, cellule{indiCell,t}.RB(indexRB).SINR, cellule{indiCell,t}.RB(indexRB).Throughput);      
       end
       fclose(fiSINRDebit); 
      
      COUNT=COUNT+1;
end
COUNT=COUNT-1;
tabRBbb=[];
    for iiiii=1:N 
        %24/09
       tabRBbb=[tabRBbb, iiiii]; %ce tableau est utilisé lorsque je veux récupérer la liste des RBs dispo dans une cellule 
       %genre:  RB_usedOK= setdiff(tabRBbb, cellule{q,ta}.rbUserActifs, 'stable');           %indexCell1: permet d'avoir les indexes au sein de la celle q
          
    end
boolll=2;
boolTest=2;
boolOKstable=0; 
okiii=0;
boolEND=-1;
cptStable(1)=0;



while (1)
    
for q=1:V 
rbcommoncellule{q}=[];
rbcommoncccc=[];
    if (t>1)
        %pr le recalculer des indices (SINR etc)
         for uurrRB=1:cellule{q,1}.nbrUser
          rb_aaA=cellule{q,ta}.rbUserActifs(uurrRB);   
          sumDist=0;
          for ttapa=1:length(cellule{q,ta}.voisins)
           voisinns=cellule{q,ta}.voisins(ttapa);
           okuRBa =  intersect(cellule{voisinns,ta}.rbUserActifs, rb_aaA) ; %indexe de l user utilisant le wwRbConfli
           if (length(okuRBa)==1)
               sumDist=sumDist + cellule{voisinns,ta}.RB(rb_aaA).puissance * ((1/ cellule{voisinns,ta}.RB(rb_aaA).dist)^beta); %on peut egalement passer par l user
                 %premiere etape: calculer les SINR     
           end        
          end
          
          
          cellule{q,t}.RB(rb_aaA).SINR = calculSINR(cellule{q,ta}.RB(rb_aaA).dist, sumDist, PuisUsed(q,rb_aaA), beta, noise);
          cellule{q,t}.RB(rb_aaA).Throughput = W * abs(log2(1 + cellule{q,t}.RB(rb_aaA).SINR));
          cellule{q,1}.cumulDebit=cellule{q,1}.cumulDebit+cellule{q,t}.RB(rb_aaA).Throughput; %20/08            
          Mat(t).qValue(q,rb_aaA)=W*abs(log2(1+cellule{q,t}.RB(rb_aaA).SINR)); %fct QValue 
          Mat(t).apprentissageRB(q,rb_aaA)=cellule{q,ta}.probCollision * Mat(t).qValue(q,rb_aaA); %fct d'apprentissage

          Mat(t).gain(q,rb_aaA)= abs( Mat(t).apprentissageRB(q,rb_aaA) - Mat(t-1).apprentissageRB(q,rb_aaA));
          Mat(t).gainTotal(q,rb_aaA) = Mat(t-1).gainTotal(q,rb_aaA) + Mat(t).gain(q,rb_aaA);
          diffGainTotal(q,rb_aaA) = Mat(t).qValue(q,rb_aaA)- Mat(t-1).qValue(q,rb_aaA);
          gainTotalCell(q,rb_aaA)=Mat(t).gain(q,rb_aaA);%  Mat(t).gainTotal(q,newRB);

  
         end
    end
%calculer l'ensemble des RB en communs  
    for tta=1:length(cellule{q,ta}.voisins)      
        voisiiii=cellule{q,ta}.voisins(tta);
        Mat(t).matriceInterf(q,voisiiii)=0; %initialiser la case
        RB_commonVoisin{voisiiii}= intersect(cellule{q,ta}.rbUserActifs, cellule{voisiiii,ta}.rbUserActifs);            %indexCell1: permet d'avoir les indexes au sein de la celle q
        Mat(t).matriceInterf(q,voisiiii) = length(RB_commonVoisin{voisiiii}); %nbre de RB en interfe avec la cellule q
        rbcommoncccc=[rbcommoncccc,    RB_commonVoisin{voisiiii}];
        rbcommoncellule{q}=unique(rbcommoncccc);
    end   
     RB_usedOK= setdiff(tabRBbb, cellule{q,ta}.rbUserActifs, 'stable'); %les RB libres dans la cellule q
  
     if(length(rbcommoncellule{q})>0)
         RB_common=[];
         RB_common=rbcommoncellule{q};
         switch strategy
             case 1
                 %utilisation de la distance
                 %je chosi le RB le plus loin de moi en espérant que cette
                 %stratégie va permettre de réduire les interférences.
                 
                 
             case 2
                 %utilisation des proba
                 %deux possiblités sont proposées: 
                 switch distributionProba
                     case 1
                         %pas de découpage de la cellule en zones
                         
                     case 2
                         %découpage de chaque cellule en deux zones
%zone=1; %pr choisir soit la zone 1 (celle au tour du eNodeB) ou la 2 
%repartitionZone=1; %1: répartition de la cellule en deux zones identiques, 2: répartition en 2/3 au tour du eNB et 1/3 extérieur

                        switch zone
                            
                            case 1
                                switch repartitionZone
                                   
                                    case 1
                                        
                                    case 2
                                    
                                end
                                
                            case 2
                                 switch repartitionZone
                                   
                                    case 1
                                        
                                    case 2
                                    
                                 end
                        end

                         
                 end
         end
              
     end

end  
end






%faire une fonction pr calculer le SINR ==> calculSINR
 %en prametres d entree: le num de la cellule et l'user 
  
 

 
 %fermeture des fichiers 
fclose(fitesttttt);
fclose(fileStable);
fclose(fiSINR_DebitA);
fclose(fiSINR_Debit); %pr vérifier les valeurs des débits et SINR
fclose(fi);
fclose(fiTest);
fclose(fiRecompGain);
fclose(fichierA); %les graphiques se feront en dehors de ce code matlab

axis square  %mis en commentaire 06/09
hold off