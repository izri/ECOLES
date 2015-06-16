%13/05/2013 by Nora IZRI
%PRiSM Laboratory
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %%%%  Edit History  %%%%
    %14/05/2013 modified (structure de donnees+affectation des RBs/cell)
    %modified 15/05/2013 exploration step
    %16/05/2013 modified (recuperer les RB en commun pr chaque cellule i et
    %c 6 cellules voisines ==>  RB_common
    %modified 30/05/2013 ==> calcul du SINR pr les users par rapports aux
    %users voisins uilisant la meme RB
    %modified 03/06/2013 ==> correction de la notion de temps; variante 1
    %du model==> tt les users des differentes cellules emettent a la meme puissance
    %modfied 05/06/2013 ==> ajustement du temps, rajout de la fct de
    %recompense globale au sein d une cellule sur un RB et la fct global de
    %la cellule
    
    
    %%%%%%%%%%%%%%%%%%%%         URGENT          %%%%%%%%%%%%%%%%%%%
    %modified 02/07/2013 ==> correction de kelk erreurs de compilation
    %suite à l introduction de la notion de temps ; j ai introduit une
    %variable ta=1, pr résoudre le problm mais par la suite il faudra
    %remettre la variable t (temps) à la place de ta; et faire biensur les
    %modifs qu il faut dans tt le code par rapport à la mise à jour des
    %RB utilisés etc
    %==> il faut également résoudre le problm de la fct de récompense elle
    %n est pas au bon endroit
    
    %03/07/2013
    %déplacement du block concernant le calcul de la fct récompense
    %début de la fct modifRB dans un fichier indépendent permettant de
    %sélection un autre RB que celui utilisé actuellement
    
    %04/07/2013
    
    %la conf des puissances d emission est faite lors de l etape init ==>
    %il faudra peut être prévoir de faire des modifs par rapport à c
    %puissances lors des mises à jours des RBs utilisés au fur et à mesure
    
    
    
    %05/07/2013
    %les mises à jour de : 
    %lorsque l on choisi un autre RB + verif de la convergence (avec des
    %multiples de 200 ms en relation avec les msg RNTP
    
    
     %10/07/2013: 
          %intégration du calcul du débit pr chaque RB ayant déjà eu un
          %calcul du SINR 
        %sauvegarde dans deux fichiers le SINR et le débit de chaque RB en
        %conflit
        %placer juste une variable cste =2 pr l utiliser lors de l'arrivée
        %d'un msg CQI avec des intervalles de 2 ms
        
        
     
    %11/07/2013
    %voir pr le noise est ce que l on utilise la puissance max ou bien celle tiré aléatoirement
         
    
   %15/07/2013
   %rajout de la notion de charge,
   %il reste kelk fois ou le SINR est > 1 ???
   
   
   %26/07/2013
   %pr que la difference soit >0 pr rentrer dans l algo d allocation, il ne
   %fallait pas mettre le gain et le gaintotal à 0
  
   
   %il faut voir est ce que lorsque l'on change de RB dans une cellule les
   %equations de la fct de récompenses ainsi que celle du calcul de la diff
   %sont liés avec l'ancien rb jusque l'on n a pas de valeurs pr ces fcts à
   %t-1
  
  %voir si c utile de refaire le calcul des RB_common et de la  sommeDistUsersNew     
                    %513==>527
                    
    %29/07/2013
    %t_RNTP  ==> j ai mis sa valeur a 10 au lieu de 200 juste pr tester par
    %rapport à la convergence de l algo en mettant la duree de simul à 50
    
    
    %06/08/2013
    %calcul de la fct gain globale de chaque cellule 
    %on détermine la stabilité si pour chaque cellule, la fct de gain
    %globale n'a pas changé entre une itération et une autre
    
    %07/08/2013
    %il faut utiliser ca pr la partie coordonnées des RB et users pr éviter
    %de tomber sur les coordonnées des eNBs
    
    %1-  Si tu as envi d'enlever toutes les occurrence tu fais
    %setdiff(A,elt,'stable');

    %2- Si tu as envi d'enlever d'une seule occurrence, à savoir la première qui apparaît dans le tableau  tu fais
    %a) q=find(A==elt);
    %b) A=[A(1:q(1)-1), A(q(1)+1:length(A))].

    %==> rajout de la variable "varianteStab" pr définir plusieurs méthodes
    %concernant les conditions de stabilité/convergence de l algo

    
    %20/08
    %==>calcul du debit moyen ET du nbre d'inteférences moyenne par cellule
    %==> pour pouvoir tracer en fct du nbre de RB dans chaque cellule c
    %deux indices de perf
    
    %récupérer la fct de récompense globale par cellule pr tracer une
    %courbe en fct des itérations avec des pas correspondant à l'arrivée
    %d'un msg CQI
    
    
    %27/08
    %cell{q,ta}.nbrRBmodif rajout de cette variable pr permettre de tracer
    %pr chaque cellule q le nbre de modif de RB qui a du se faire durant la simul
    %
    
    
    %30/08
    %il faut revoir comment rajouter dans le while le test de la variable
    %"continuer" ligne 479
    
    
    %03/09
   % rajout d écriture dans les fichiers nécessaire pr tracer les courbes
   % des indices de perf
   
   %04/09
   %Nstabilisation: pr verifier la stabilité 
   %revoir les fct de récompense lorsque l on change de RB
   
   %j'ai mis en commentaire tous les plots pr aller plus vite
   
   
   
     
      %05/09 EcartType=std(AdaptTime);
         %   ConfiInterval=2*EcartType/sqrt(nerrorbar(X1,Y1,Err1,'-o','color','black','LineWidth',2.0);
%au lieu de plot c'est donc errorbar


%tt les plot ont été mis en commentaire ainsi que la commande "clf"
%06/09
%mise en place de la boucle while (1) et rajout de test pr la convergence
%de l algo

%10/09
%quelques corrections d'indice pr les affichages 
%rajout du fichier de sortie "timeSTABLE" pr sauvegarder les times pr vérifier à quel
%moment on a la première stabilité  et surppression des affaichages sur le
%terminal

%gainTotalCell  ==> fct de recompense globale d'une cellule à un instant
%(t) en sommant toutes les fcts de gain de chaque RB de la cellule
%gainTotal ==> fct de recompense globale pour chaque RB

%12/09
%j ai mis en commentaire le calcul de "diffGainTotal" qui se fait après la
%modification des rB car cela génére des erreurs à l exécution alors que
%l'on n a pas besoin de cette variable à ce moment là

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clc;
clear all;
%close all;
%clf %clear figure
varianteStab=1; %1: usage de la fct de gain globale pr chaque cellule; 2 : usage du SINR pr chaque RB de chaque cellule
varianteALGO=1; %1: tous les users utilisent la meme puissance de transmission dans tout le reseau; 2: les users d'une meme cellule sont sur la meme puisssance; 3: la puissance de transmission d un user est en fct de sa distance par rapport au eNB

varianteChooseRB=1;
VALSTABLITE=0;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
N = 50;     %Number of RBs/cell  ==> 6 pr SOAPS
R = 15;     %Radius of Hexagon==> rayon
charge=1;
Nstabilisation=100; %pr verifier que pendant ce nbre d itérations les paramètres n ont pas changé
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
ta=1; %a revoir car pr le moment le rbUserPris est fixé à l étape init alors que les users changent au fur et à mesure

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

switch varianteALGO
    %ce switch a ete fait le 05/06/2013
    case 1
      PuisUsedAll=randi([1, PuisSeuil], 1, 1); %PuisMax
     %j ai mis la ligne précédente en commentaire le 11/07/2013 car je l ai déplacé pr l utilisé lors du calcul de noise tt au début du code 
     for bb=1:V
            %tous les users fonctionnent à la même puissance
            for zz=1:N
             PuisUsed(bb,zz) = PuisUsedAll; %puissance d emission du RB zz au sein de la cellule zz 
             if (PuisUsedAll == PuisSeuil) 
                 Mat(t).matriceRNTP(bb,zz)=1; %utilisation de la puissance max
             else
                 Mat(t).matriceRNTP(bb,zz)=0;
             end
            end
        end
        
    case 2
        for aa=1:V
            for hh=1:N  %PuisMax
             PuisUsed(aa,hh) =randi([1, PuisSeuil], 1, 1);
              if (PuisUsed(aa,hh) == PuisSeuil) 
                 Mat(t).matriceRNTP(aa,hh)=1; %utilisation de la puissance max
             else
                 Mat(t).matriceRNTP(aa,hh)=0;
             end
            end
        end
        
    case 3
          PuisUsedAll=randi([1, PuisMax], 1, 1);
        %rester a completer ce cas par rapport a la distance d un RB et eNB
  
end

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
for j=1:V
    %Vertexes
    cell{j,1}.x = eNB{j}.x + R * cos(tp);
    cell{j,1}.y = eNB{j}.y + R * sin(tp);     
%%   plot(cell{j}.x,cell{j}.y, 'b');  %dessiner la cellule  05/09
% %     if j==1 
% %         plot(eNB{j}.x,eNB{j}.y,'rd'); %emplacement du eNB  ==> le central je le voulais en rouge "ro"
% %     else
% %         plot(eNB{j}.x,eNB{j}.y,'rd'); %emplacement du eNB
% %     end 
    cell{j,1}.nbrUser=randi([1, M], 1, 1);    %affecter un certain nbr d user par cellule
    fprintf(fi, '%d \t %d \n',  j, cell{j,1}.nbrUser);  
    cell{j,1}.cumulInterfRB=0;
    cell{j,1}.cumulDebit=0;
end      

%generation des RBs/Agent de maniere alea
%Generate 3N random points with square that is 2R by 2R
for i=1:V
bool=0;
Cx=[];
Cy=[];
while bool==0
%placer des RBs/Agent de maniere aleatoire dans la cellule i
%générer un nbre important de coordonnées (3*N)
    c_x1 =eNB{i}.x + R-rand(1,3*N)*2*R;
    c_y1 =eNB{i}.y + R-rand(1,3*N)*2*R;
    %get the points within the polygon
    IN = inpolygon(c_x1, c_y1, cell{i}.x, cell{i}.y);
    %drop nodes outside the hexagon
    c_x1 = c_x1(IN);
    c_y1 = c_y1(IN);
 
    Cx=[Cx c_x1];
    Cy=[Cy c_y1];
    %07/08/2013
    %retirer les coordonnées des eNBs
     Cx=setdiff(Cx,eNB{i}.x,'stable'); %cette fct permet d'enlever toutes les occurances de la coordonnée x du eNB + ordonne le tableau 
     Cy=setdiff(Cy,eNB{i}.y,'stable');
%     Cx= find(Cx~=eNB{i}.x);
%     Cy= find(Cy~=eNB{i}.y);
%     
    %choose only N points
    if length(Cx)>= N
        %idx = randperm(length(Cx));
        randperm(length(Cx)); %ranger le vecteur Cx de maniere alea
        randperm(length(Cy));%ranger le vecteur Cy de maniere alea
        %recuperer les coordonnes (x,y) de chaque RB/Agent a placer dans la cellule i 
       % c_x11 = Cx(idx(1:N));
       % c_y11 = Cy(idx(1:N));
        for u=1:N
            %j ai mis directement un 1 car la notation "t" ne passe pas
            %!!!! 03 Juin 2013
           cell{i,1}.RB(u).x =Cx(u);
           cell{i,1}.RB(u).y = Cy(u);
           cell{i,1}.RB(u).dist= distance(eNB{i}.x, eNB{i}.y, cell{i,ta}.RB(u).x, cell{i,ta}.RB(u).y);
           cell{i,1}.RB(u).puissance=PuisUsed(i, u);
           cell{i,1}.nbrRBmodif=0; %27/08/2013
% %            if i==1  plot(cell{i,1}.RB(u).x, cell{i,1}.RB(u).y, 'g*');
% %g*  05/09
% %            else plot(cell{i,1}.RB(u).x, cell{i,1}.RB(u).y, 'm*');
% %            end
        end
        bool=1;
    end
end
 % if i==1  plot(c_x11, c_y11, 'g*');
 % else plot(c_x11, c_y11, 'm*');
 % end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%% placer les voisins a un saut de chaque cellule 
   cell{1,1}.voisins=[2 3 4 5 6 7];
   cell{2,1}.voisins=[1 3 7];
   cell{3,1}.voisins=[1 2 4];
   cell{4,1}.voisins=[1 3 5];
   cell{5,1}.voisins=[1 4 6];
   cell{6,1}.voisins=[1 5 7];
   cell{7,1}.voisins=[1 2 6];
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%t=1 ==> effectuer la phase d'exploration
for k=1:V %etape init de mon algo
    %exploration step of my algo

    %placer les users dans chaque cellule => affectation alea pr l'etape init de mon algo    
    if M>N fprintf ('erreuuuurrrr \n');
    else
    % pris=[];
     cell{k,1}.rbUserPris=[];
     for h=1:cell{k,1}.nbrUser
       %placer les users sur les RBs en se basant sur l'OFDMA ==> canaux
       %orthogonaux
       %il n'existe pas plusieurs users dans la cellule k sur le meme RB
       test=0;
       while test ==0
       selectRB=randi([1, N], 1, 1);  %selectionner un RB parmis N pr chaque user 
       id=intersect(cell{k,1}.rbUserPris, selectRB);%cell{k}.rbUserPris au lieu du vecteur pris 
       if length(id)==0
         %il faut verifier si ce RB n a pas ete deja affecte
         cell{k,1}.user(h).x = cell{k,1}.RB(selectRB).x;
         cell{k,1}.user(h).y = cell{k,1}.RB(selectRB).y;
       %  plot(cell{k}.user{h}.x, cell{k}.user{h}.y, 'k+'); % pr visualiser
       %  les users
       
        % if k==1  plot(cell{k,1}.RB(selectRB).x, cell{k,1}.RB(selectRB).y, 'ro');
        % else
 %%            plot(cell{k,1}.RB(selectRB).x, cell{k,1}.RB(selectRB).y, 'ko');%05/09
       % end
       
         cell{k,1}.user(h).rb = selectRB;
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
         cell{k,1}.user(h).duration = randi([1, dur], 1, 1); %duree de communication
         %il faut calculer les distances entre chaque user et le eNB
         cell{k,1}.user(h).dist = distance(eNB{k}.x, eNB{k}.y, cell{k,1}.user(h).x, cell{k}.user(h).y);
         test =1; 
        % pris=[pris, selectRB]; %mise a jour de l ensemble des RB pris
         cell{k,1}.rbUserPris=[cell{k,1}.rbUserPris, selectRB]; %mise a jour de l ensemble des RB pris
        % cell{k}.user(h).puissance=PuisUsed;
         %else
        %   id
        %   length(id)
       end
      %si trouver alors rechercher à nouveau   
       end
     end
    %  cell{k}.rbUserPris %vecteur contenant les differents RB affecte pr les
    %  user pr la cellule k
    end
    %affecter les proba de collision pr chaque cellule
    sum=0;
    for d=1:length(cell{k,ta}.voisins)
        dd=cell{k,1}.voisins(d);
        if dd~=k 
            sum=sum + cell{dd}.nbrUser;
        end
    end
    cell{k,1}.probCollision=cell{k,ta}.nbrUser/sum;
    %test 04/09 
    if ( cell{k,1}.probCollision > 1)
        %il faut revoir le calul
        cell{k,1}.probCollision= abs(1-cell{k,1}.probCollision);
    end
    
end

%%%%%%%%%%%
continuer = -1;
sauv=1;
sauvegardddd=1;
okStable=0;
okStableA=0;
cellInterf=[];














sumDist=0;
 
for indiCell=1:V
    for uurRB=1:cell{indiCell,1}.nbrUser %length(cell{indiCell,ta}.rbUserPris)
      rb_aA=cell{indiCell,ta}.rbUserPris(uurRB); 
      
      
      sumDist=0;
       for ttapa=1:length(cell{indiCell,ta}.voisins)
                 voisinns=cell{indiCell,ta}.voisins(ttapa);
                 okuRBa =  intersect(cell{voisinns,ta}.rbUserPris, rb_aA) ; %indexe de l user utilisant le wwRbConfli
                 if (length(okuRBa)==1)
                  sumDist=sumDist + cell{voisinns,ta}.RB(okuRBa).puissance * ((1/ cell{voisinns,ta}.RB(okuRBa).dist)^beta); %on peut egalement passer par l user
                 %premiere etape: calculer les SINR     
                end  
      
       end
      
      
      
      
      
      
      cell{indiCell,t}.RB(rb_aA).SINR = calculSINR(cell{indiCell,ta}.RB(rb_aA).dist, sumDist, PuisUsed(indiCell,rb_aA), beta, noise);
 %  fprintf('--------------- t=%g\t\t q=%g\t\t RB=%g \t \t SINR =%f  \n',t,indiCell, rb_aA, cell{indiCell,t}.RB(rb_aA).SINR);
      %30/08
      cell{indiCell,t}.RB(rb_aA).Throughput = W * abs(log2(1 + cell{indiCell,t}.RB(rb_aA).SINR));
      cell{indiCell,1}.cumulDebit=cell{indiCell,1}.cumulDebit+cell{indiCell,t}.RB(rb_aA).Throughput; %20/08            
      Mat(t).qValue(indiCell,rb_aA)=W*abs(log2(1+cell{indiCell,t}.RB(rb_aA).SINR)); %fct QValue 
      Mat(t).apprentissageRB(indiCell,rb_aA)=cell{indiCell,ta}.probCollision * Mat(t).qValue(indiCell,rb_aA); %fct d'apprentissage
      %  fprintf('** sauv=%g\t\t q=%g\t\t wwRbConfli=%g \t \t voisin= %g\n',sauv,q,rb_A, voisin);     
      if (t>1)
          %27/08 ==> quelques petites modifs en utilisant la variable sauv
          %car c le même principe que lorsque l on exécute le mécanisme de
          %changement de RB
      % if (length(intersect(T{sauvegardddd}.cellO{indiCell},rb_aA )) > 0)  
         Mat(t).gain(indiCell,rb_aA)= Mat(t).apprentissageRB(indiCell,rb_aA);% - Mat(sauvegardddd).apprentissageRB(indiCell,rb_aA); 
         %cell{q,t}.probCollision*apprentissageRB(q,ww);
         %  disp('!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!');   %Mat(t).gainTotal(indiCell,rb_aA) +
         Mat(t).gainTotal(indiCell,rb_aA) =  Mat(t).gain(indiCell,rb_aA);
         diffGainTotal(rb_aA) = Mat(t).gain(indiCell,rb_aA); % - Mat(sauvegardddd).gainTotal(indiCell,rb_aA);
       
         diffGainTotal(rb_aA) = Mat(t).qValue(indiCell,rb_aA); % - Mat(sauvegardddd).gainTotal(indiCell,rb_aA);
     
         %  diffGainTotal = Mat(t).gainTotal(indiCell,rb_aA); % - Mat(sauvegardddd).gainTotal(indiCell,rb_aA);
       
         %06/08/2013
       % end
      else
         Mat(t).gain(indiCell,rb_aA)= Mat(t).apprentissageRB(indiCell,rb_aA);
    
         Mat(t).gainTotal(indiCell,rb_aA) =  Mat(t).gain(indiCell,rb_aA); %Mat(t).gainTotal(indiCell,rb_aA) +
      end
      gainTotalCell(indiCell,rb_aA)=Mat(t).gainTotal(indiCell,rb_aA);
   
      %%%%%%%%27/09
       gainTotalCell(indiCell,rb_aA)=Mat(t).gain(indiCell,rb_aA);
   
      
      
      % fprintf('######## t=%g\t\t q=%g\t\t RB=%g \t \t gainTotal(t)=%f  \n',t,q, rb_A,Mat(t).gainTotal(q,rb_A));
    %mis en commentaire 29/08 car trop d affichage
    end
end

  tabRBbb=[];
    for iiiii=1:N 
        %24/09
       tabRBbb=[tabRBbb, iiiii]; 
    end
boolll=2;
boolTest=2;

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
 COUNT=1;
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
OutpuVerfiAAAbbb= strcat('Iter-', num2str(q), '.dat');

    if t==1
         fiTestAAA = fopen(OutpuVerfiAAA, 'w');  %wt
    else
         fiTestAAA = fopen(OutpuVerfiAAA, 'a+');  %wt
    end
    if (countITER(q)==0)
         fiTestAAAbbbbb=fopen(OutpuVerfiAAAbbb, 'w');  %wt
    else
         fiTestAAAbbbbb=fopen(OutpuVerfiAAAbbb, 'a+');  %wt
    end 
    
    
    
    
   RBmodifOK{q}=[];
   unionRB=[]; %30/08
   cellRBcommon{q}=[]; %30/08
% %    %chercher pour chaque cellule q  si c cellules voisines ont utilisé
% %    %les même RB qu'elle

  RRC{q}=[];
  cell{q,1}.cumulDebit=0;
  sumDist=0;
  
    for uurrRB=1:cell{q,1}.nbrUser %length(cell{q,ta}.rbUserPris)
      rb_aaA=cell{q,ta}.rbUserPris(uurrRB);   
      sumDist=0;
       for ttapa=1:length(cell{q,ta}.voisins)
           voisinns=cell{q,ta}.voisins(ttapa);
           okuRBa =  intersect(cell{voisinns,ta}.rbUserPris, rb_aaA) ; %indexe de l user utilisant le wwRbConfli
           if (length(okuRBa)==1)
               sumDist=sumDist + cell{voisinns,ta}.RB(okuRBa).puissance * ((1/ cell{voisinns,ta}.RB(okuRBa).dist)^beta); %on peut egalement passer par l user
                 %premiere etape: calculer les SINR     
           end  
      
       end
   
      cell{q,t}.RB(rb_aaA).SINR = calculSINR(cell{q,ta}.RB(rb_aaA).dist, sumDist, PuisUsed(q,rb_aaA), beta, noise);
 %  fprintf('--------------- t=%g\t\t q=%g\t\t RB=%g \t \t SINR =%f  \n',t,q, rb_aaA, cell{q,t}.RB(rb_aaA).SINR);
     %30/08 
      cell{q,t}.RB(rb_aaA).Throughput = W * abs(log2(1 + cell{q,t}.RB(rb_aaA).SINR));
      cell{q,1}.cumulDebit=cell{q,1}.cumulDebit+cell{q,t}.RB(rb_aaA).Throughput; %20/08            
      Mat(t).qValue(q,rb_aaA)=W*abs(log2(1+cell{q,t}.RB(rb_aaA).SINR)); %fct QValue 
      Mat(t).apprentissageRB(q,rb_aaA)=cell{q,ta}.probCollision * Mat(t).qValue(q,rb_aaA); %fct d'apprentissage
    
       if (t==1)  
         Mat(t).gainCell(q)=0;
         Mat(t).sinrCell(q)=0;
         Mat(t).apprentiCell(q)=0;
         
         Mat(t).apprentiCellALL(q)=0;
         Mat(t).gainCellAll(q)=0;
         Mat(t).sinrCellAll(q)=0;
      
         Mat(t).gain(q,rb_aaA)= Mat(t).apprentissageRB(q,rb_aaA);
         Mat(t).gainTotal(q,rb_aaA) = Mat(t).gain(q,rb_aaA); %Mat(t).gainTotal(q,rb_A) + 
         diffGainTotal(rb_aaA) = Mat(t).gain(q,rb_aaA);% - Mat(t-1).gainTotal(q,wwRbConfli);
         diffGainTotal(rb_aaA) = Mat(t).qValue(q,rb_aaA);% - Mat(t-1).gainTotal(q,wwRbConfli);
        
         else

         Mat(t).gain(q,rb_aaA)= abs( Mat(t).apprentissageRB(q,rb_aaA) - Mat(t-1).apprentissageRB(q,rb_aaA));
        % Mat(t).gainTotal(q,rb_aA)=0;
         Mat(t).gainTotal(q,rb_aaA) = Mat(t-1).gainTotal(q,rb_aaA) + Mat(t).gain(q,rb_aaA);
        
    %% fprintf(2, ' ******************** %d \t \t %g \t %g \t %g \t %g \n', t,   Mat(t-1).gainTotal(q,rb_aaA), Mat(t).gain(q,rb_aaA),Mat(t-1).gain(q,rb_aaA), Mat(t).gainTotal(q,rb_aaA));
        diffGainTotal(rb_aaA) = Mat(t).gain(q,rb_aaA)- Mat(t-1).gain(q,rb_aaA); 
        diffGainTotal(rb_aaA) = Mat(t).qValue(q,rb_aaA)- Mat(t-1).qValue(q,rb_aaA); 
 %%%fprintf(2, ' !!!!!!!!!!!!!!! %d \t \t %d \t \t %g \t %g \t %g \t %g \n', t,  q,  Mat(t-1).gainTotal(q,rb_aaA), Mat(t).gain(q,rb_aaA),Mat(t-1).gain(q,rb_aaA), Mat(t).gainTotal(q,rb_aaA)); 
      end
      gainTotalCell(q,rb_aaA)=Mat(t).gainTotal(q,rb_aaA); %Mat(t).gainTotal(q,rb_aaA);  
      %%%%27/09       
      gainTotalCell(q,rb_aaA)=Mat(t).gain(q,rb_aaA);%  Mat(t).gainTotal(q,newRB);
                           
  
      
     % gainTotalCell(q,rb_aaA)=Mat(t).gainTotal(q,rb_aaA)+gainTotalCell(q,rb_aaA);
     % fprintf('######## t=%g\t\t q=%g\t\t RB=%g \t \t gainTotal(t)=%f  \n',t,q, rb_A,Mat(t).gainTotal(q,rb_A));
    %mis en commentaire 29/08 car trop d affichage
  
    vvvvv=0;
    fprintf(fiSINR_Debit, '%d \t %d \t %d \t %d \t %f \t %f \t %f \n', t,q, vvvvv,  rb_aaA, cell{q,ta}.RB(rb_aaA).dist, cell{q,t}.RB(rb_aaA).SINR, cell{q,t}.RB(rb_aaA).Throughput); %t \t cell{q,t}.RB(wwRbConfli).SINR
                      %t, '\t', cell{q,t}.RB(wwRbConfli).SINR, 
           
    
    end
rbPROBLM{q}=[];
rbcommonCell{q}=[];

affectionINIT{q}=cell{q,ta}.rbUserPris;
%calcul des RB en commun avec chacun des voisins
rbcommoncccc=[];
 for tta=1:length(cell{q,ta}.voisins)      
    voisiiii=cell{q,ta}.voisins(tta);
    Mat(t).matriceInterf(q,voisiiii)=0; %initialiser la case
     %  
    RB_commonVoisin{voisiiii}= intersect(cell{q,ta}.rbUserPris, cell{voisiiii,ta}.rbUserPris);            %indexCell1: permet d'avoir les indexes au sein de la celle q
    Mat(t).matriceInterf(q,voisiiii) = length(RB_commonVoisin{voisiiii}); %nbre de RB en interfe avec la cellule q
    rbcommoncccc=[rbcommoncccc,    RB_commonVoisin{voisiiii}];
    rbcommonCell{q}=unique(rbcommoncccc);
 end
% q  %26/09
% disp(rbcommonCell{q});
     cell{q,1}.cumulDebit=0;
    % for tt=1:length(cell{q,ta}.voisins) 
         
        %on suppose que les cellules restent à la config initiale (indice t=1) par rapport aux voisinages cell{q,1}.voisins
%        voisin=cell{q,ta}.voisins(tt);
     %   Mat(t).matriceInterf(q,voisin)=0; %initialiser la case
     %   if voisin~=q %tt  
            cpt=0;
         %   [RB_common, indexCell1, indexCell2]= intersect(cell{q,ta}.rbUserPris, cell{voisin,ta}.rbUserPris);            %indexCell1: permet d'avoir les indexes au sein de la celle q
            %indexCell2: indexes pr la cellule t
           % if (length(RB_common) > 0)  
           voisin=0;
           if(length(rbcommonCell{q})>0)
              RB_common=[];
              RB_common=rbcommonCell{q};
              cell{q,1}.cumulInterfRB=cell{q,1}.cumulInterfRB+length(RB_common); %20/08 pr calculer le nbre d'interf cumul
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
           fprintf(fiRecompGain, '%d \t %d \t %d \t %f \t %f  \t %f \t %f   \t %f  \t %f   \n', t,q, wwRbConfli, Mat(t).gain(q,wwRbConfli),  Mat(t).gainTotal(q,wwRbConfli), Mat(t).apprentissageRB(q,wwRbConfli),   Mat(t).qValue(q,wwRbConfli),    cell{q,ta}.probCollision      ,diffGainTotal(wwRbConfli));  
       

%disp(diffGainTotal(wwRbConfli) );

    diffGainTotal(wwRbConfli)=-10; %27/09
    if ( diffGainTotal(wwRbConfli) < 0 ) || (t==1)
                    
     %   disp('*************************************************');      
       % il faut changer le rb "wwRbConfli" au niveau de
          % la celle q.
          okchoixRBdispo=-1;  %init   
          RB_usedOK= setdiff(tabRBbb, cell{q,ta}.rbUserPris, 'stable');           %indexCell1: permet d'avoir les indexes au sein de la celle q
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
                     cell{q,t-1}.RB(rbChoix).SINR   =0;
                  end
                 %25/09       
                 sommeDistUsersA=0;
                 for ttaaa=1:length(cell{q,ta}.voisins)  
                    voizz=cell{q,ta}.voisins(ttaaa);
                    okuRB =  intersect(cell{voizz,ta}.rbUserPris, rbChoix) ; %indexe de l user utilisant le wwRbConfli
                    if (length(okuRB)==1)
                       sommeDistUsersA=sommeDistUsersA + cell{voizz,ta}.RB(okuRB).puissance * ((1/ cell{voizz,ta}.RB(okuRB).dist)^beta); %on peut egalement passer par l user
                         %premiere etape: calculer les SINR
                    end  
                 end
               %modif pr le calcul du SINR
                  sinr = calculSINR(cell{q,ta}.RB(rbChoix).dist, sommeDistUsersA , PuisUsed(q,rbChoix), beta, noise);
                  deb = W *abs( log2(1 + sinr)); %cell{q,t}.RB(rbChoix).SINR)
                  qval=W*abs(log2(1+sinr)); %fct QValue  %cell{q,t}.RB(rbChoix).SINR)
                  appr=cell{q,ta}.probCollision * qval; %fct d'apprentissage %Mat(t).apprentissageRB(q,rbChoix)
                   %Mat(t).qValue(q,rbChoix)
              %     if ((cell{q,t}.RB(rbChoix).SINR - cell{q,t}.RB(wwRbConfli).SINR) > 0)   
                   if rbDISPO==1
                     apprMax=appr;
                     qvalMax=qval;
                     sinrMax=sinr;
                     debMax=deb;
                   end
               
                   if ((appr- Mat(t).apprentissageRB(q,wwRbConfli) >0) && (sinr > cell{q,t}.RB(wwRbConfli).SINR) ) 
             %      fprintf('%d \t ====== \t %g \t \t ******  \t  %g \n', q, Mat(t).apprentissageRB(q,wwRbConfli), Mat(t).apprentissageRB(q,rbChoix));
                      if ((apprMax <= appr) && (sinrMax<=sinr))
                     % && (cell{q,t}.RB(maxRB).SINR < cell{q,t}.RB(rbChoix).SINR)
                     %  if (cell{q,t}.RB(maxRB).SINR < cell{q,t}.RB(rbChoix).SINR)
                       
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
                  
                   end 
                
                %   fprintf('maxRB=%d \n', maxRB);
              end
              if boolOKrbchange==1
                 newRB=  maxRB; %pr choisir le meilleur RB
                 okchoixRBdispo=1;
            %    fprintf(2,'%f \n', cell{q,t}.RB(newRB).SINR);
             else
                     newRB=  wwRbConfli;
                     okchoixRBdispo=0;
              end   
             
              
              case 2
                  nbre=length(RB_usedOK); 
                  aleaID=randi([1, nbre], 1, 1);
                  rbChoix=RB_usedOK(nbre);
                  if (rbChoix~=wwRbConfli)
                      newRB= rbChoix;
                 %     disp('************');
                  end
                  okchoixRBdispo=1;
                  
                  
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
                     for ttaaea=1:length(cell{q,ta}.voisins)  
                         voiizz=cell{q,ta}.voisins(ttaaea);
                         okuRB =  intersect(cell{voiizz,ta}.rbUserPris, rbChoix) ; %indexe de l user utilisant le wwRbConfli
                         if (length(okuRB)==1)
                               sommeDistUsersAb=sommeDistUsersAb + cell{voiizz,ta}.RB(okuRB).puissance * ((1/ cell{voiizz,ta}.RB(okuRB).dist)^beta); %on peut egalement passer par l user
                            %premiere etape: calculer les SINR
                
                         end  
                     end
                      %modif pr le calcul du SINR  
                      sinrMax = calculSINR(cell{q,ta}.RB(rbChoix).dist, sommeDistUsersAb , PuisUsed(q,rbChoix), beta, noise);
                      debMax = W *abs(log2(1 + sinrMax)); % cell{q,t}.RB(rbChoix).SINR)
                      qvalMax=W*abs(log2(1+sinrMax)); %fct QValue  %cell{q,t}.RB(rbChoix).SINR)
                      apprMax=cell{q,ta}.probCollision * qvalMax; %fct d'apprentissage
                
                      if ((apprMax- Mat(t).apprentissageRB(q,wwRbConfli) >0) && (sinrMax>cell{q,t}.RB(wwRbConfli).SINR))
                         
                           
                           
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
                for ttaaea=1:length(cell{q,ta}.voisins)  
                    voiizz=cell{q,ta}.voisins(ttaaea);
                    okuRB =  intersect(cell{voiizz,ta}.rbUserPris, rbChoix) ; %indexe de l user utilisant le wwRbConfli
                    if (length(okuRB)==1)
                        sommeDistUsersAb=sommeDistUsersAb + cell{voiizz,ta}.RB(okuRB).puissance * ((1/ cell{voiizz,ta}.RB(okuRB).dist)^beta); %on peut egalement passer par l user
                            %premiere etape: calculer les SINR
                
                    end  
                end
                %modif pr le calcul du SINR  
                sinrMax = calculSINR(cell{q,ta}.RB(rbChoix).dist, sommeDistUsersAb , PuisUsed(q,rbChoix), beta, noise);
                debMax = W *abs(log2(1 + sinrMax)); % cell{q,t}.RB(rbChoix).SINR)
                qvalMax=W*abs(log2(1+sinrMax)); %fct QValue  %cell{q,t}.RB(rbChoix).SINR)
                apprMax=cell{q,ta}.probCollision * qvalMax; %fct d'apprentissage
       
               if ((apprMax- Mat(t).apprentissageRB(q,wwRbConfli) >0)&& (sinrMax > cell{q,t}.RB(wwRbConfli).SINR)) 
            %    if ((cell{q,t}.RB(rbChoix).SINR - cell{q,t}.RB(wwRbConfli).SINR) > 0)   
                 
            
                    if t>1   
                        if (apprMax- Mat(t-1).apprentissageRB(q,wwRbConfli) >0)
                         newRB=  rbChoix; %pr choisir le meilleur RB
                         okchoixRBdispo=1;  
                        end
                    else
                        
                    newRB=  rbChoix; %pr choisir le meilleur RB
                    okchoixRBdispo=1; 
                    %    fprintf(2, '%f \n', cell{q,t}.RB(newRB).SINR);
                    end      
                else
                     newRB=  wwRbConfli;
                %     disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%');
                     okchoixRBdispo=0;
              %       fprintf('PAS D''AMELIORATION DS LA CELLULE %d \n', q);
               end 
                
          
            
              case 2  
                     %choix aléatoire
                 rbChoix=RB_usedOK(1);
                 newRB=  wwRbConfli;    
                 okchoixRBdispo=1;
                 
                 
             case 3
                 rbChoix=RB_usedOK(1);
                 
                 sommeDistUsersAb=0;
                for ttaaea=1:length(cell{q,ta}.voisins)  
                    voiizz=cell{q,ta}.voisins(ttaaea);
                    okuRB =  intersect(cell{voiizz,ta}.rbUserPris, rbChoix) ; %indexe de l user utilisant le wwRbConfli
                    if (length(okuRB)==1)
                        sommeDistUsersAb=sommeDistUsersAb + cell{voiizz,ta}.RB(okuRB).puissance * ((1/ cell{voiizz,ta}.RB(okuRB).dist)^beta); %on peut egalement passer par l user
                            %premiere etape: calculer les SINR
                
                    end  
                end
                %modif pr le calcul du SINR  
                sinrMax = calculSINR(cell{q,ta}.RB(rbChoix).dist, sommeDistUsersAb , PuisUsed(q,rbChoix), beta, noise);
                debMax = W *abs(log2(1 + sinrMax)); % cell{q,t}.RB(rbChoix).SINR)
                qvalMax=W*abs(log2(1+sinrMax)); %fct QValue  %cell{q,t}.RB(rbChoix).SINR)
                apprMax=cell{q,ta}.probCollision * qvalMax; %fct d'apprentissage
                                     
               if ((apprMax- Mat(t).apprentissageRB(q,wwRbConfli) >0) && (sinrMax > cell{q,t}.RB(wwRbConfli).SINR) )
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
             okchoixRBdispo=-1;
             rbPROBLM{q}=[rbPROBLM{q}, wwRbConfli]; %27/09 pr connaitre les gens que j'ai retiré
             cell{q,ta}.nbrRBmodif=cell{q,ta}.nbrRBmodif+1; %27/08
             uRB =  find(cell{q,ta}.rbUserPris == wwRbConfli) ; %indexe de l user utilisant le wwRbConfli
             cell{q,ta}.user(uRB).rb = newRB; %comment
               % récupérer le num du user uRB ??????
                          
             cell{q,ta}.rbUserPris(uRB)=newRB; %mise à jour du vecteur des RB de la cellule q
             switch varianteChooseRB                 
               case 1       
                   cell{q,t}.RB(newRB).SINR=sinrMax;
                   cell{q,t}.RB(newRB).Throughput=debMax;
                   Mat(t).qValue(q,newRB)=qvalMax;
                   Mat(t).apprentissageRB(q,newRB)=apprMax;
               case 2
                   sommeDistUsersAb=0;
                   for ttaaea=1:length(cell{q,ta}.voisins)  
                       voiizz=cell{q,ta}.voisins(ttaaea);
                       okuRB =  intersect(cell{voiizz,ta}.rbUserPris, newRB) ; %indexe de l user utilisant le wwRbConfli
                       if (length(okuRB)==1)
                            sommeDistUsersAb=sommeDistUsersAb + cell{voiizz,ta}.RB(okuRB).puissance * ((1/ cell{voiizz,ta}.RB(okuRB).dist)^beta); %on peut egalement passer par l user
                            %premiere etape: calculer les SINR
                
                       end  
                    end
                    %modif pr le calcul du SINR  
                    cell{q,t}.RB(newRB).SINR = calculSINR(cell{q,ta}.RB(newRB).dist, sommeDistUsersAb , PuisUsed(q,newRB), beta, noise);
                    cell{q,t}.RB(newRB).Throughput = W *abs(log2(1 + cell{q,t}.RB(newRB).SINR)); % cell{q,t}.RB(rbChoix).SINR)
                    Mat(t).qValue(q,newRB)=W*abs(log2(1+cell{q,t}.RB(newRB).SINR)); %fct QValue  %cell{q,t}.RB(rbChoix).SINR)
                    Mat(t).apprentissageRB(q,newRB)=cell{q,ta}.probCollision * Mat(t).qValue(q,newRB); %fct d'apprentissage
               case 3
                    cell{q,t}.RB(newRB).SINR=sinrMax;
                    cell{q,t}.RB(newRB).Throughput=debMax;
                    Mat(t).qValue(q,newRB)=qvalMax;
                    Mat(t).apprentissageRB(q,newRB)=apprMax;
              end
     
                    Mat(t).tabRB(q,newRB) = 1; % pr dire k ce rb est occupe 
                    Mat(t).tabRB(q,wwRbConfli) = 0; %  
 
                    cell{q,1}.cumulDebit = cell{q,1}.cumulDebit - cell{q,t}.RB(wwRbConfli).Throughput; %20/08
                    cell{q,t}.RB(wwRbConfli).Throughput=0; %car il n est plus utilisé
                    cell{q,t}.RB(wwRbConfli).SINR =0; %car il n est plus utilisé        
                    Mat(t).matriceRNTP(q,wwRbConfli)=1;
                    Mat(t).matriceRNTP(q,newRB)=2;
                   % fprintf ('*******  JE SUIS ICI ******** \n');
                  
                    rbCommNew=setdiff(unionRB, wwRbConfli);
                    unionRB=rbCommNew;
                    unionRB=[unionRB,newRB ];
                    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                    fprintf(fiSINR_DebitA, '%d \t %d \t %d \t %d \t %f \t %f \t %f \n', t,q,  voisin, newRB,cell{q,ta}.RB(newRB).dist, cell{q,t}.RB(newRB).SINR, cell{q,t}.RB(newRB).Throughput);  
                     
                    if(t>1)     
                                Mat(t).gain(q,newRB)= abs(Mat(t).apprentissageRB(q,newRB) - Mat(t).apprentissageRB(q,wwRbConfli));     %26/07/2013  à voir avant c était   - Mat(t).apprentissageRB(q,newRB);  
                                Mat(t).gainTotal(q,newRB) =  Mat(t-1).gainTotal(q,newRB) + Mat(t).gain(q,newRB); %Mat(t-1).gainTotal(q,newRB) +
                               %%%%%%% 
                               % Mat(t).gainCell(q)=Mat(t).gainCell(q)- Mat(t).gainTotal(q,wwRbConfli) + Mat(t).gainTotal(q,newRB);
                                diffGainTotal(newRB) = Mat(t).gain(q,newRB); % - Mat(t).gain(q,wwRbConfli);
                             
                                diffGainTotal(newRB) = Mat(t).qValue(q,newRB) - Mat(t-1).qValue(q,newRB);
                      
                            else
                                %init 

                                Mat(t).gain(q,newRB)=Mat(t).apprentissageRB(q,newRB);  
                                Mat(t).gainTotal(q,newRB) = Mat(t).gain(q,newRB);
                               %%%%%%% 
                                Mat(t).gainCell(q)=0;
                                Mat(t).sinrCell(q)=0;
                                Mat(t).apprentiCell(q)=0;
                                
                                Mat(t).apprentiCellALL(q)=0;
                                Mat(t).gainCellAll(q)=0;
                                Mat(t).sinrCellAll(q)=0;
                            
                               diffGainTotal(newRB) = Mat(t).gain(q,newRB);% - Mat(t-1).gainTotal(q,wwRbConfli);                 
                               diffGainTotal(newRB) = Mat(t).qValue(q,newRB);% - Mat(t-1).gainTotal(q,wwRbConfli);
                         
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
   %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    else
     LLV{q}=[];   
   end
 




cumulGainTotal=0;
cumSINR=0;
cumAPPRENTI=0;


for allRB=1:length(cell{q,ta}.rbUserPris)
    rbActuel=cell{q,ta}.rbUserPris(allRB);
  

    cumulGainTotal= cumulGainTotal + gainTotalCell(q,rbActuel); % Mat(t).gainTotal(q,rbActuel);
    cumSINR=cumSINR+cell{q,t}.RB(rbActuel).SINR ; %05/09
    cumAPPRENTI=cumAPPRENTI + Mat(t).apprentissageRB(q,rbActuel);
     % vvvvv=0;
   % fprintf(fiSINR_Debit, '%d \t %d \t %d \t %d \t %f \t %f \t %f \n', t,q, vvvvv,  rbActuel, cell{q,ta}.RB(rbActuel).dist, cell{q,t}.RB(rbActuel).SINR, cell{q,t}.RB(rbActuel).Throughput); %t \t cell{q,t}.RB(wwRbConfli).SINR
                      %t, '\t', cell{q,t}.RB(wwRbConfli).SINR, 

end

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
 
fprintf(fiTestAAAbbbbb, '%d \t %d \t %g \t %f\n', q, COUNT, countITER(q), gainGlobal(q, COUNT)); %tabREWARD(q));
 
 
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
fprintf(fiTest, '%d \t %d \t %f \t %f \t  %f  \n', q, t, Mat(t).gainCell(q), Mat(t).gainCellAll(q),  cell{q,ta}.probCollision );  

fprintf(fiTestAAA, '%d \t %d \t %f \t %f \t %f \t %f \t %f \t %f \n', q, t, Mat(t).gainCell(q),Mat(t).gainCellAll(q), cell{q,ta}.probCollision, Mat(t).apprentiCellALL(q), Mat(t).sinrCell(q), Mat(t).apprentiCell(q) );  
 
%arrivée d un msg CQI  ==> 10/07/2013 ==> 20/08 modif d'emplacement de ce
%test
if (mod(t, t_CQI) ==0)
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
    
   fprintf(fiDistrib, '%d \t %d \t %f \t %f \t %f  \t %f \t %f \n', q, t, Mat(t).gainCellAll(q), Mat(t).gainCell(q), cell{q,ta}.probCollision, Mat(t).apprentiCell(q), Mat(t).sinrCell(q) );  
   fclose(fiDistrib);
end
fclose(fiTestAAA);
fclose(fiTestAAAbbbbb);



 
%if q<V 
    COUNT=COUNT+1; 
%end
end %le end de l'ensemble des cellules 

%%%%%%%%%%%%%%fin du parcours de toutes les cellules

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
  
     
      for xxC=1:V
      Outputfichier= strcat('SINR_Throug-', num2str(xxC), '.dat'); %03/09
         if t==1 
             fiSINRDebit = fopen(Outputfichier, 'w');  %wt
         else
              fiSINRDebit = fopen(Outputfichier, 'a+');  %wt
         end
      
       for allRBx=1:cell{xxC,ta}.nbrUser   %length(cell{xx,ta}.rbUserPris)
            indexRB=cell{xxC,ta}.rbUserPris(allRBx);
%             if t==1 
%              fprintf('------ t=%g \t\t cellule =%g\t\t RB=%g \t \t SINR =%f  \t \t   \n',t,xxC, indexRB, cell{xxC,t}.RB(indexRB).SINR);         
%             else
%              fprintf('------ t=%g \t\t cellule =%g\t\t RB=%g \t \t SINR =%f  \t \t  t-1   =%g \t \t SINRaa =%f  \t \t nbremodif = %d \n',t,xxC, indexRB, cell{xxC,t}.RB(indexRB).SINR, t-1,  cell{xxC,t-1}.RB(indexRB).SINR, cell{q,ta}.nbrRBmodif);         
%             end
            %03/09 ==> rajout de c fichiers
       fprintf(fiSINRDebit, '%d  \t %d \t %d \t %f \t %f \t %f \n', t,xxC,   indexRB, cell{xxC,ta}.RB(indexRB).dist, cell{xxC,t}.RB(indexRB).SINR, cell{xxC,t}.RB(indexRB).Throughput);      
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
               
                if (diffG<= epsilon) %round(diffG)==0)   % ==0   <= epsilon
                    %rajout du round 05/09
                     okStable=okStable+1;
                     celluleOKiii=[celluleOKiii, cc];
                     continuer=0;
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
                for allRBx=1:cell{xxC,ta}.nbrUser   %length(cell{xx,ta}.rbUserPris)
                    %cell{q,ta}.rbUserPris(uRB)
                    indexRB=cell{xxC,ta}.rbUserPris(allRBx);
                    aa=t-1; 
                    diffSINR = cell{xxC,t}.RB(indexRB).SINR - cell{xxC,aa}.RB(indexRB).SINR; 
                  %  cell{q,t}.RB(newRB).SINR
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
                if(okStableA == length(cell{xxC,ta}.rbUserPris)) 
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
 
%   disp(cell{q,1}.nbrRBmodif);
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
                  if(length(OKtrouve)==1) VALSTABLITE=instantT(OKtrouve); end
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

 
 for indcell=1:V
    OutpuVerzzzz= strcat('VerfiGainzzzzzzzzzzzzz-', num2str(indcell), '.dat'); 
    fitestttttcell= fopen(OutpuVerzzzz, 'w');

     
     for cpt=1:(COUNT-1)
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
        calcNbreModifTotal=calcNbreModifTotal+ cell{qaa,1}.nbrRBmodif; 
         fprintf(fileMODIF,'%d \t %d \t %d \n', qaa, t, cell{qaa,1}.nbrRBmodif);
    end
    fclose(fileMODIF);
    for qa=1:V
     %20/08==> indice de perf
        debitMoyen(qa)=cell{qa,1}.cumulDebit/(t-1);
        nbreInterfMoyen(qa)=cell{qa,1}.cumulInterfRB/(t-1);
        fprintf(fichierA, '%d \t %d \t %d  \t %d  \t %f \t %f \t %d \n', (t-1), qa, N, cell{qa,1}.nbrUser,  debitMoyen(qa), nbreInterfMoyen(qa), cell{qa,ta}.nbrRBmodif );  
      %pr le tracer de ces deux courbes debit moyen et nbre d interference moyenne, cela se fera avec gnuplot ou excel par la suite car ilfaut tte les valeurs      
       %le N correspond au nbre de RB max/cell
    end
 end
 
 if ( (okStable== V) && (cptStable(t) == Nstabilisation))
     
   fprintf ('---------  FIN CONVERGENCE OK   --------- COUNT = %d \n', COUNT);
   fprintf(' PREMIERE STABLITE %d \t nbre calcNbreModifTotal= %d *****  -- %d ms  \t duree de convergence  \n',VALSTABLITE,  calcNbreModifTotal,   tConverg);
   for uu=1:V 
    fprintf('====== reçu %d  \t msg RNTP  ---- \t %d msg CQI \n', cpt_RNTP, cpt_CQI(uu));
   end 
 % fprintf ('---------  FIN CONVERGENCE OK   --------- nbre calcNbreModifTotal= %d ***** reçu %d  \t msg RNTP  ---- \t %d msg CQI -- %d ms  \t duree de convergence  \n', calcNbreModifTotal, cpt_RNTP, cpt_CQI,  tConverg);
 end
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