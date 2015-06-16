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
    %suite � l introduction de la notion de temps ; j ai introduit une
    %variable ta=1, pr r�soudre le problm mais par la suite il faudra
    %remettre la variable t (temps) � la place de ta; et faire biensur les
    %modifs qu il faut dans tt le code par rapport � la mise � jour des
    %RB utilis�s etc
    %==> il faut �galement r�soudre le problm de la fct de r�compense elle
    %n est pas au bon endroit
    
    %03/07/2013
    %d�placement du block concernant le calcul de la fct r�compense
    %d�but de la fct modifRB dans un fichier ind�pendent permettant de
    %s�lection un autre RB que celui utilis� actuellement
    
    %04/07/2013
    
    %la conf des puissances d emission est faite lors de l etape init ==>
    %il faudra peut �tre pr�voir de faire des modifs par rapport � c
    %puissances lors des mises � jours des RBs utilis�s au fur et � mesure
    
    
    
    %05/07/2013
    %les mises � jour de : 
    %lorsque l on choisi un autre RB + verif de la convergence (avec des
    %multiples de 200 ms en relation avec les msg RNTP
    
    
     %10/07/2013: 
          %int�gration du calcul du d�bit pr chaque RB ayant d�j� eu un
          %calcul du SINR 
        %sauvegarde dans deux fichiers le SINR et le d�bit de chaque RB en
        %conflit
        %placer juste une variable cste =2 pr l utiliser lors de l'arriv�e
        %d'un msg CQI avec des intervalles de 2 ms
        
        
     
    %11/07/2013
    %voir pr le noise est ce que l on utilise la puissance max ou bien celle tir� al�atoirement
         
    
   %15/07/2013
   %rajout de la notion de charge,
   %il reste kelk fois ou le SINR est > 1 ???
   
   
   %26/07/2013
   %pr que la difference soit >0 pr rentrer dans l algo d allocation, il ne
   %fallait pas mettre le gain et le gaintotal � 0
  
   
   %il faut voir est ce que lorsque l'on change de RB dans une cellule les
   %equations de la fct de r�compenses ainsi que celle du calcul de la diff
   %sont li�s avec l'ancien rb jusque l'on n a pas de valeurs pr ces fcts �
   %t-1
  
  %voir si c utile de refaire le calcul des RB_common et de la  sommeDistUsersNew     
                    %513==>527
                    
    %29/07/2013
    %t_RNTP  ==> j ai mis sa valeur a 10 au lieu de 200 juste pr tester par
    %rapport � la convergence de l algo en mettant la duree de simul � 50
    
    
    %06/08/2013
    %calcul de la fct gain globale de chaque cellule 
    %on d�termine la stabilit� si pour chaque cellule, la fct de gain
    %globale n'a pas chang� entre une it�ration et une autre
    
    %07/08/2013
    %il faut utiliser ca pr la partie coordonn�es des RB et users pr �viter
    %de tomber sur les coordonn�es des eNBs
    
    %1-  Si tu as envi d'enlever toutes les occurrence tu fais
    %setdiff(A,elt,'stable');

    %2- Si tu as envi d'enlever d'une seule occurrence, � savoir la premi�re qui appara�t dans le tableau  tu fais
    %a) q=find(A==elt);
    %b) A=[A(1:q(1)-1), A(q(1)+1:length(A))].

    %==> rajout de la variable "varianteStab" pr d�finir plusieurs m�thodes
    %concernant les conditions de stabilit�/convergence de l algo

    
    %20/08
    %==>calcul du debit moyen ET du nbre d'intef�rences moyenne par cellule
    %==> pour pouvoir tracer en fct du nbre de RB dans chaque cellule c
    %deux indices de perf
    
    %r�cup�rer la fct de r�compense globale par cellule pr tracer une
    %courbe en fct des it�rations avec des pas correspondant � l'arriv�e
    %d'un msg CQI
    
    
    %27/08
    %cell{q,ta}.nbrRBmodif rajout de cette variable pr permettre de tracer
    %pr chaque cellule q le nbre de modif de RB qui a du se faire durant la simul
    %
    
    
    %30/08
    %il faut revoir comment rajouter dans le while le test de la variable
    %"continuer" ligne 479
    
    
    %03/09
   % rajout d �criture dans les fichiers n�cessaire pr tracer les courbes
   % des indices de perf
   
   %04/09
   %Nstabilisation: pr verifier la stabilit� 
   %revoir les fct de r�compense lorsque l on change de RB
   
   %j'ai mis en commentaire tous les plots pr aller plus vite
   
   
   
     
      %05/09 EcartType=std(AdaptTime);
         %   ConfiInterval=2*EcartType/sqrt(nerrorbar(X1,Y1,Err1,'-o','color','black','LineWidth',2.0);
%au lieu de plot c'est donc errorbar



%06/09
%mise en place de la boucle while (1) et rajout de test pr la convergence
%de l algo
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clc;
clear all;
%close all;
clf %clear figure
varianteStab=1; %1: usage de la fct de gain globale pr chaque cellule; 2 : usage du SINR pr chaque RB de chaque cellule
varianteALGO=1; %1: tous les users utilisent la meme puissance de transmission dans tout le reseau; 2: les users d'une meme cellule sont sur la meme puisssance; 3: la puissance de transmission d un user est en fct de sa distance par rapport au eNB
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
N = 15;     %Number of RBs/cell
R = 15;     %Radius of Hexagon==> rayon
charge=0.7;
Nstabilisation=2; %pr verifier que pendant ce nbre d it�rations les param�tres n ont pas chang�
M = round(N*charge);     %Number of users => au max nbre user= nbre de RBs
%utilisation de "round" pr convertir le r�el en un entier
V=7; %number of cells => pr le moment nous considerons uniquement 7 cellules
rayonPorte_eNB=10; %km
W=180000; %hz bande passante ==> c 180khz pr 1 RB %10/07/2013
%PuissBruit=2; %puissance du bruit, je l avais rajout� en pensant utilis�
%la formule de shannon directement mais je remplace ca par le SINR
t=1; %indice de temps
T_max=1500; %temps de simul
dur=10; %pr la duree max de communication
t_RNTP=100;%200; %a chaque 200 ms un msg RNTP est envoye sur le lien X2
dur1RNTP=t_RNTP;
t_CQI=2; % 2ms mais max c 3 ms 10/07/2013
cpt_CQI=0;
tConverg=1; % compteur pr calculer le temps de convergence de l algo, il fait que ca soit un multiple de t_RNTP
cpt_RNTP=0; %compteur du msg RNTP
TmaxConvergence=1000; %il ne faudrait pas que l'algo converge avec un temps > � 1000 ms; condition:  t_RNTP <= tConverg <= TmaxConvergence

epsilon=10^(-15);
alpha=2;
PuisMax= 50;
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
matriceRNTP=zeros(V, N);%cette matrice va contenir des 1 ou des 0 ==> 1 : le RB est utilise avec une puissance max ==> pas bon car il va d�ranger
%apprentissageRB=zeros(V, N);
%qValue=zeros(V, N);
%gain=zeros(V, N);
%gainTotal=zeros(V, N); %fct gain total au sein de chaque cellule, c la fct a maximiser sur un RB
gainGlobal=zeros(V);
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
ta=1; %a revoir car pr le moment le rbUserPris est fix� � l �tape init alors que les users changent au fur et � mesure

OutputFileSINR_Throughput= strcat('fileSINR_Throughput.txt');
fiSINR_Debit = fopen(OutputFileSINR_Throughput, 'w');  %wt

OutputFileUser= strcat('nbrUserCell.txt'); %pr le d�bit
fi = fopen(OutputFileUser, 'w');  %wt

OutputFileGAIN= strcat('fctRecompGain.txt'); %pr le d�bit
fiRecompGain = fopen(OutputFileGAIN, 'w');  %wt

fileSortie= strcat('debitMoyInterfMoy.txt'); %pr le d�bit moyen et le nbre d interf�rences moyennes %26/08/2013
fichierA = fopen(fileSortie, 'a+');  %wt

OutpuVerfi= strcat('VerfiGain.txt'); %pr le d�bit
fiTest = fopen(OutpuVerfi, 'w');  %wt

gainTotalCell=zeros(V,N);

switch varianteALGO
    %ce switch a ete fait le 05/06/2013
    case 1
      PuisUsedAll=randi([1, PuisSeuil], 1, 1); %PuisMax
     %j ai mis la ligne pr�c�dente en commentaire le 11/07/2013 car je l ai d�plac� pr l utilis� lors du calcul de noise tt au d�but du code 
     for bb=1:V
            %tous les users fonctionnent � la m�me puissance
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
tp=linspace(0,2*pi,V); % g�n�re le m�me t 7 fois (pr les 7 cellules)
%Generating a hexagon with centre (0,0) and,
% To generate 6 adjacent hexagon
% Generating a hexagon 
grid on
hold on
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
%g�n�rer un nbre important de coordonn�es (3*N)
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
    %retirer les coordonn�es des eNBs
     Cx=setdiff(Cx,eNB{i}.x,'stable'); %cette fct permet d'enlever toutes les occurances de la coordonn�e x du eNB + ordonne le tableau 
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
         %j ai rajout� le lien avec  Mat(t), pr que je puisse comparer � l
         %instant (t) et (t-1) pr la convergence ==> modif fait le
         %03/07/2013
      
         %04/07/2013 ==> affecter un 2 � la case ou il y avait un 1 dans la
         %matriceRNTP pr dire que ce RB est utilis� et en plus il est �
         %haute puissance
         
         if (Mat(t).matriceRNTP(k,selectRB) == 1) 
             Mat(t).matriceRNTP(k,selectRB)=2; %utilisation de la puissance max
            %ds le cas ou le RB "selectRB" a ete modifie, il ne faut pas
            %oubli� de remettre la valeur de cette case � 1
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
      %si trouver alors rechercher � nouveau   
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
      cell{indiCell,t}.RB(rb_aA).SINR = calculSINR(cell{indiCell,ta}.RB(rb_aA).dist, sumDist, PuisUsed(indiCell,rb_aA), beta, noise);
 %  fprintf('--------------- t=%g\t\t q=%g\t\t RB=%g \t \t SINR =%f  \n',t,indiCell, rb_aA, cell{indiCell,t}.RB(rb_aA).SINR);
      %30/08
      cell{indiCell,t}.RB(rb_aA).Throughput = W * log(1 + cell{indiCell,t}.RB(rb_aA).SINR);
      cell{indiCell,1}.cumulDebit=cell{indiCell,1}.cumulDebit+cell{indiCell,t}.RB(rb_aA).Throughput; %20/08            
      Mat(t).qValue(indiCell,rb_aA)=W*log(1+cell{indiCell,t}.RB(rb_aA).SINR); %fct QValue 
      Mat(t).apprentissageRB(indiCell,rb_aA)=cell{indiCell,ta}.probCollision * Mat(t).qValue(indiCell,rb_aA); %fct d'apprentissage
      %  fprintf('** sauv=%g\t\t q=%g\t\t wwRbConfli=%g \t \t voisin= %g\n',sauv,q,rb_A, voisin);     
      if (t>1)
          %27/08 ==> quelques petites modifs en utilisant la variable sauv
          %car c le m�me principe que lorsque l on ex�cute le m�canisme de
          %changement de RB
      % if (length(intersect(T{sauvegardddd}.cellO{indiCell},rb_aA )) > 0)  
         Mat(t).gain(indiCell,rb_aA)= Mat(t).apprentissageRB(indiCell,rb_aA);% - Mat(sauvegardddd).apprentissageRB(indiCell,rb_aA); 
         %cell{q,t}.probCollision*apprentissageRB(q,ww);
         %  disp('!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!');   %Mat(t).gainTotal(indiCell,rb_aA) +
         Mat(t).gainTotal(indiCell,rb_aA) =  Mat(t).gain(indiCell,rb_aA);
         diffGainTotal = Mat(t).gain(indiCell,rb_aA); % - Mat(sauvegardddd).gainTotal(indiCell,rb_aA);
       
         %  diffGainTotal = Mat(t).gainTotal(indiCell,rb_aA); % - Mat(sauvegardddd).gainTotal(indiCell,rb_aA);
       
         %06/08/2013
       % end
      else
         Mat(t).gain(indiCell,rb_aA)= Mat(t).apprentissageRB(indiCell,rb_aA);
         Mat(t).gainTotal(indiCell,rb_aA)=0;
         Mat(t).gainTotal(indiCell,rb_aA) =  Mat(t).gain(indiCell,rb_aA); %Mat(t).gainTotal(indiCell,rb_aA) +
      end
      gainTotalCell(indiCell,rb_aA)=Mat(t).gainTotal(indiCell,rb_aA);
     % fprintf('######## t=%g\t\t q=%g\t\t RB=%g \t \t gainTotal(t)=%f  \n',t,q, rb_A,Mat(t).gainTotal(q,rb_A));
    %mis en commentaire 29/08 car trop d affichage
    end
end


boolll=2;
boolTest=2;

%cellRBcommon=zeros(1,V); %30/08
boolOKstable=0;
%cptStable=0; 
okiii=0;
%faire une fonction pr calculer le SINR ==> calculSINR
 %en prametres d entree: le num de la cellule et l'user 
 %(t<=T_max)  && ==> 04/09 j ai enlev� ce test car je dois d'abord
 %atteindre la stabilit� et connaitre apr�s combien d'it�ration c atteint
while (1) %(boolOKstable==0))  %&& (continuer ~= 0)  %(okStable~=V) &&  (t<=T_max)  &&
okiii=okStable;
fprintf(2,' t=%g \t \t cptStable=%g \t \t okStable= %g  \t \t okiii= %g \n',t, cptStable(t), okStable, okiii);

okStable=0; %04/09  ==> A VOIR
okStableA=0;  %04/09  ==> A VOIR
boolll=-1;
boolTest=-1;
%exploitation step 
for q=1:V
 OutpuVerfiAAA= strcat('VerfiGainProbaInstant-', num2str(q), '.dat');
    if t==1
         fiTestAAA = fopen(OutpuVerfiAAA, 'w');  %wt
    else
         fiTestAAA = fopen(OutpuVerfiAAA, 'a+');  %wt
    end

   unionRB=[]; %30/08
   cellRBcommon{q}=[]; %30/08
% %    %chercher pour chaque cellule q  si c cellules voisines ont utilis�
% %    %les m�me RB qu'elle
     sommeDistUsers = 0; 
     cell{q,1}.cumulDebit=0;
     for tt=1:length(cell{q,ta}.voisins) 
        %on suppose que les cellules restent � la config initiale (indice t=1) par rapport aux voisinages cell{q,1}.voisins
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
              %il y a des RB en commun
              %il faut appliquer l'ago d'apprentissage
              % nbreCommun=length(RB_common);
              Mat(t).matriceInterf(q,voisin) = length(RB_common); %nbre de RB en interfe avec la cellule q
         
                for f=1:length(RB_common) %calcul de la plus grande partie du d�nominateur pr le caclul du SINR
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
             %  fprintf('########## t=%g\t\t q=%g\t\t RB=%g \t \t voisin= %d \t\t SINR =%f  \n',t,q, wwRbConfli, voisin, cell{q,t}.RB(wwRbConfli).SINR);
      %30/08
          
                     %10/07/2013: rajout de la ligne permettant de calculer le
                     %d�bit avec la formule de shannon
                     cell{q,t}.RB(wwRbConfli).Throughput = W * log(1 + cell{q,t}.RB(wwRbConfli).SINR);
                     cell{q,1}.cumulDebit=cell{q,1}.cumulDebit+cell{q,t}.RB(wwRbConfli).Throughput; %20/08
                     %cell{q,t}.RB(wwRbConfli).SINR %mis en commentaire 10/07/2013
                     %cell{q,t}.RB(wwRbConfli).Throughput %mis en commentaire 10/07/2013
                     %l'�criture dans les deux fichiers today 10/07/2013
                     fprintf(fiSINR_Debit, '%d \t %d \t %d \t %d \t %f \t %f \t %f \n', t,q, voisin,  wwRbConfli, cell{q,ta}.RB(wwRbConfli).dist, cell{q,t}.RB(wwRbConfli).SINR, cell{q,t}.RB(wwRbConfli).Throughput); %t \t cell{q,t}.RB(wwRbConfli).SINR
                      %t, '\t', cell{q,t}.RB(wwRbConfli).SINR, 
                     %  fprintf(fiDebit, '%d \t %d \t %d \t %f \n', t, q, wwRbConfli, cell{q,t}.RB(wwRbConfli).Throughput); %t \t cell{q,t}.RB(wwRbConfli).Throughput
                     %calcul de la fonction d'apprentissage 
                    Mat(t).qValue(q,wwRbConfli)=W*log(1+cell{q,t}.RB(wwRbConfli).SINR); %fct QValue 
                    Mat(t).apprentissageRB(q,wwRbConfli)=cell{q,ta}.probCollision * Mat(t).qValue(q,wwRbConfli); %fct d'apprentissage
                    %  fprintf('** sauv=%g\t\t q=%g\t\t wwRbConfli=%g \t \t voisin= %g\n',sauv,q,wwRbConfli, voisin);
                    if(t>1)   
                      if (length(intersect(T{sauv}.Cel{q},wwRbConfli )) > 0)    
                       Mat(t).gain(q,wwRbConfli)= abs(Mat(t).apprentissageRB(q,wwRbConfli) - Mat(sauv).apprentissageRB(q,wwRbConfli)); %cell{q,t}.probCollision*apprentissageRB(q,ww);
                       %  disp('???????????????');  
                       Mat(t).gainTotal(q,wwRbConfli) = Mat(t-1).gainTotal(q,wwRbConfli) + Mat(t).gain(q,wwRbConfli);
                       %diffGainTotal = Mat(t).gainTotal(q,wwRbConfli) - Mat(sauv).gainTotal(q,wwRbConfli);
                      
                         diffGainTotal = Mat(t).gain(q,wwRbConfli) - Mat(sauv).gain(q,wwRbConfli);
                     %05/09 a voir si c ca la fct � utuliser
                       %06/08/2013                   
                      else
                       %   disp('???????????????'); 
                       Mat(t).gain(q,wwRbConfli)= abs(Mat(t).apprentissageRB(q,wwRbConfli) -  Mat(t-1).apprentissageRB(q,wwRbConfli));
                       Mat(t).gainTotal(q,wwRbConfli) = Mat(t-1).gainTotal(q,wwRbConfli) + Mat(t).gain(q,wwRbConfli);
                    %   diffGainTotal = Mat(t).gainTotal(q,wwRbConfli)- Mat(t-1).gainTotal(q,wwRbConfli); %05/09 je n'avais pas fait la soustraction
                   %05/09
                       diffGainTotal = Mat(t).gain(q,wwRbConfli)- Mat(t-1).gain(q,wwRbConfli); 
                       
                       
                      end   
                  else
                    %init 
                    Mat(t).gain(q,wwRbConfli)= Mat(t).apprentissageRB(q,wwRbConfli);
                    Mat(t).gainTotal(q,wwRbConfli)=0;    
                    Mat(t).gainTotal(q,wwRbConfli) = Mat(t).gainTotal(q,wwRbConfli) + Mat(t).gain(q,wwRbConfli);
                    Mat(t).gainCell(q)=0;
                    Mat(t).sinrCell(q)=0;
                    Mat(t).gainCellAll(q)=0;
                    Mat(t).sinrCellAll(q)=0;
                    %%%%%%% 
                    diffGainTotal = Mat(t).gain(q,wwRbConfli);% - Mat(t-1).gainTotal(q,wwRbConfli);
              
                    % diffGainTotal = Mat(t).gainTotal(q,wwRbConfli);
                    end
                   %gainTotalCell(q,wwRbConfli)=gainTotalCell(q,wwRbConfli)+ Mat(t).gainTotal(q,wwRbConfli);
                   gainTotalCell(q,wwRbConfli)=Mat(t).gainTotal(q,wwRbConfli);%Mat(t).gainTotal(q,wwRbConfli);
                   %%05/09
                   % 
                   
                   
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
                          %  disp('!!!!!!!!!!!!!!!!!');
                           cell{q,ta}.nbrRBmodif=cell{q,ta}.nbrRBmodif+1; %27/08
                            %05/07/2013 ==> ttes les lignes de code de ce
                            %test "if"; on �tait fait aujourd'hui
                            %choisir un RB                  ===> OK
                            %calculer son SNIR              ===> OK
                            %mettre � jour la matriceRNTP   ===> OK
                            % ainsi que la matrice tabRB    ===> OK
                            %et les champs li� o user
                            %mettre � jour cell{q,ta}.rbUserPris; en retirant
                            %de ce tableau le RB wwRbConfli et le remplacer �
                            %son endroit par le nouveau RB    
                        %    fprintf(2,'Je change %g \t avec \t %g \t vois %g \n ',wwRbConfli,newRB, voisin);
                            uRB =  find(cell{q,ta}.rbUserPris == wwRbConfli) ; %indexe de l user utilisant le wwRbConfli
                            cell{q,ta}.user(uRB).rb = newRB; %comment
                           % r�cup�rer le num du user uRB ??????
                            cell{q,ta}.rbUserPris(uRB)=newRB; %mise � jour du vecteur des RB de la cellule q
                           
                            Mat(t).tabRB(q,newRB) = 1; % pr dire k ce rb est occupe 
                            Mat(t).tabRB(q,wwRbConfli) = 0; %  
                     
                            
                            if t>1 cell{q,t-1}.RB(newRB).SINR   =0; end
                            cell{q,t}.RB(newRB).SINR = calculSINR(cell{q,ta}.RB(newRB).dist, 0 , PuisUsed(q,newRB), beta, noise);
                            cell{q,t}.RB(newRB).Throughput = W * log(1 + cell{q,t}.RB(newRB).SINR);
                          
                            Mat(t).qValue(q,newRB)=W*log(1+cell{q,t}.RB(newRB).SINR); %fct QValue
                            Mat(t).apprentissageRB(q,newRB)=cell{q,ta}.probCollision * Mat(t).qValue(q,newRB); %fct d'apprentissage
                            
                            Mat(t-1).apprentissageRB(q,newRB) =0; %30/08
                            Mat(t-1).gainTotal(q,newRB)= 0; %30/08
                            
                            cell{q,1}.cumulDebit = cell{q,1}.cumulDebit - cell{q,t}.RB(wwRbConfli).Throughput; %20/08
                   
                            cell{q,t}.RB(wwRbConfli).Throughput=0; %car il n est plus utilis�
                            cell{q,t}.RB(wwRbConfli).SINR =0; %car il n est plus utilis�
                            
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
                           %%%%%%%%%%%%%%%%
                           rbCommNew=RB_commonNew; %30/08
                           actuelNew=unique(rbCommNew); %30/08
                           unionRB =[unionRB, actuelNew];  %30/08
                       %    cellRBcommon{q}=unionRB;  %30/08
                           %%%%%%%%%%%%%%%%%
                           
                           for f=1:length(RB_commonNew) %calcul de la plus grande partie du d�nominateur pr le caclul du SINR
                            ww=RB_common(f);%num de RB
                          %  ss=indexCell2(f); %num du user   
                            sommeDistUsersNew=sommeDistUsersNew + cell{voisin,ta}.RB(ww).puissance * ((1/ cell{voisin,ta}.RB(ww).dist)^beta); %on peut egalement passer par l user
                           end
                             cell{q,1}.cumulInterfRB=cell{q,1}.cumulInterfRB-length(RB_common)+length(RB_commonNew); %20/08 pr calculer le nbre d'interf cumul
              
                         end
                           %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                           
                            cell{q,t}.RB(newRB).SINR = calculSINR(cell{q,ta}.RB(newRB).dist, sommeDistUsersNew, PuisUsed(q,newRB), beta, noise);
                            %10/07/2013: rajout de la ligne permettant de calculer le
                            %d�bit avec la formule de shannon
       %   fprintf('******* t=%g\t\t q=%g\t\t RB=%g \t \t SINR =%f  \n',t,q, newRB, cell{q,t}.RB(newRB).SINR);
      %30/08
    
                            cell{q,t}.RB(newRB).Throughput = W * log(1 + cell{q,t}.RB(newRB).SINR);
                            cell{q,1}.cumulDebit=cell{q,1}.cumulDebit+cell{q,t}.RB(newRB).Throughput; %20/08
                            %l'�criture dans les deux fichiers today 10/07/2013
                            fprintf(fiSINR_Debit, '%d \t %d \t %d \t %d \t %f \t %f \n', t,q, newRB, voisin,  cell{q,t}.RB(newRB).SINR, cell{q,t}.RB(newRB).Throughput);  

                            %calcul de la fonction d'apprentissage 
                            Mat(t).qValue(q,newRB)=W*log(1+cell{q,t}.RB(newRB).SINR); %fct QValue
                            Mat(t).apprentissageRB(q,newRB)=cell{q,ta}.probCollision * Mat(t).qValue(q,newRB); %fct d'apprentissage

                            if(t>1) 
                                
                                
                               if (length(intersect(T{sauv}.Cel{q},newRB )) > 0)    
                                   Mat(t).gain(q,newRB)= abs(Mat(t).apprentissageRB(q,newRB) - Mat(sauv).apprentissageRB(q,newRB)); %cell{q,t}.probCollision*apprentissageRB(q,ww);
                                 %  disp('???????????????');  
                                  Mat(t).gainTotal(q,newRB) = Mat(t-1).gainTotal(q,newRB) + Mat(t).gain(q,newRB);
                                 % diffGainTotal = Mat(t).gainTotal(q,newRB) - Mat(sauv).gainTotal(q,newRB);
                                  %06/08/2013  
                                  diffGainTotal = Mat(t).gain(q,newRB) - Mat(sauv).gain(q,newRB);
                               
                              else
                                
                                Mat(t).gain(q,newRB)= abs(Mat(t).apprentissageRB(q,newRB) - Mat(t).apprentissageRB(q,wwRbConfli));     %26/07/2013  � voir avant c �tait   - Mat(t).apprentissageRB(q,newRB);  
                                Mat(t).gainTotal(q,newRB) =  Mat(t).gain(q,newRB); %Mat(t-1).gainTotal(q,newRB) +
                               %%%%%%% 
                               % Mat(t).gainCell(q)=Mat(t).gainCell(q)- Mat(t).gainTotal(q,wwRbConfli) + Mat(t).gainTotal(q,newRB);
                                diffGainTotal = Mat(t).gain(q,newRB) - Mat(t).gain(q,wwRbConfli);
                             
                                
                              %  diffGainTotal = Mat(t).gainTotal(q,newRB) - Mat(t).gainTotal(q,wwRbConfli);
                              
                                
                                %26/07/2013 � voir avant c �tait   - Mat(t).gainTotal(q,newRB);  
                                end
                            else
                                %init 
                                Mat(t).gain(q,newRB)=0;
                                Mat(t).gainTotal(q,newRB)=0; 
                                Mat(t).gain(q,newRB)=Mat(t).apprentissageRB(q,newRB);  
                                Mat(t).gainTotal(q,newRB) = Mat(t).gainTotal(q,newRB) + Mat(t).gain(q,newRB);
                               %%%%%%% 
                                Mat(t).gainCell(q)=0;
                                Mat(t).sinrCell(q)=0;
                                Mat(t).gainCellAll(q)=0;
                                Mat(t).sinrCellAll(q)=0;
                             %   diffGainTotal = Mat(t).gainTotal(q,newRB);% - Mat(t-1).gainTotal(q,wwRbConfli);
                          
                               diffGainTotal = Mat(t).gain(q,newRB);% - Mat(t-1).gainTotal(q,wwRbConfli);
                          
                            end
                             gainTotalCell(q,newRB)=Mat(t).gainTotal(q,newRB);%  Mat(t).gainTotal(q,newRB);
                           % %05/09
                            %gainTotalCell(q,newRB)=gainTotalCell(q,newRB)+Mat(t).gainTotal(q,newRB);
                         %%%%%%%%%%%%% 11/07/2013 end pr cette partie de modif 
                          
                        else
                            %pas de changement 
                             Mat(t).matriceRNTP(q,wwRbConfli)=2;
                        end
                    else
                        %remise � z�ro de la variable pr la suite;
                        % ==> gain est soit > 0 (am�lior�) ou = 0
                        % (inchang�)
                        diffGainTotal = 0;
                      %  fprintf ('*******  JE SUIS LAAAAAAAAAAAAAAAAA ******** \n');
                          
                    end
                
            end
           % else
           %    LL{q}=[];
              
           % end
       % end
   %  end  %==> 29/08


    else
     LLV{q}=[];


            
            end
        end % 29/08
             
end %29/08
     
         cellRBcommon{q}=unionRB;  %30/08
RB_Cellll=setdiff(cell{q,ta}.rbUserPris,  cellRBcommon{q}, 'stable');
%[  , ind1, ind2]  %j ai enlev� les indices 30/08 car j ai chang� la fct
%intersect par la fct setdiff pr r�cup�rer l'ensemble des rb qui n ont pas
%�t� tir� en commun avecles voisins

   %calculer le SINR et le debit de chacun de c RB ainsi que la
   %fct de r�compense
sumDit=0;
if (length(RB_Cellll) > 0)
    boolTest=true;
    RRC{q}=RB_Cellll;
  for uuRB=1:length(RB_Cellll)
      rb_A=RB_Cellll(uuRB);            
      cell{q,t}.RB(rb_A).SINR = calculSINR(cell{q,ta}.RB(rb_A).dist, sumDit, PuisUsed(q,rb_A), beta, noise);
 %     fprintf('--------------- t=%g\t\t q=%g\t\t RB=%g \t \t SINR =%f  \n',t,q, rb_A, cell{q,t}.RB(rb_A).SINR);
 % 30/08 
      cell{q,t}.RB(rb_A).Throughput = W * log(1 + cell{q,t}.RB(rb_A).SINR);
      cell{q,1}.cumulDebit=cell{q,1}.cumulDebit+cell{q,t}.RB(rb_A).Throughput; %20/08            
      Mat(t).qValue(q,rb_A)=W*log(1+cell{q,t}.RB(rb_A).SINR); %fct QValue 
      Mat(t).apprentissageRB(q,rb_A)=cell{q,ta}.probCollision * Mat(t).qValue(q,rb_A); %fct d'apprentissage
      %  fprintf('** sauv=%g\t\t q=%g\t\t wwRbConfli=%g \t \t voisin= %g\n',sauv,q,rb_A, voisin);     
      if (t>1)
          %27/08 ==> quelques petites modifs en utilisant la variable sauv
          %car c le m�me principe que lorsque l on ex�cute le m�canisme de
          %changement de RB
%        if (length(intersect(T{sauvegardddd}.cellO{q},rb_A )) > 0)  
%          Mat(t).gain(q,rb_A)= Mat(t).apprentissageRB(q,rb_A) - Mat(sauvegardddd).apprentissageRB(q,rb_A); 
%          %cell{q,t}.probCollision*apprentissageRB(q,ww);
%          %  disp('!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!');  
%          Mat(t).gainTotal(q,rb_A) = Mat(t-1).gainTotal(q,rb_A) + Mat(t).gain(q,rb_A); %29/08   Mat(t-1).gainTotal
%          diffGainTotal = Mat(t).gainTotal(q,rb_A) - Mat(sauvegardddd).gainTotal(q,rb_A);
%          %06/08/2013
%        else 
           %30/08
         Mat(t).gain(q,rb_A)= abs(Mat(t).apprentissageRB(q,rb_A) - Mat(t-1).apprentissageRB(q,rb_A));
         Mat(t).gainTotal(q,rb_A) = Mat(t-1).gainTotal(q,rb_A) + Mat(t).gain(q,rb_A);
         diffGainTotal = Mat(t).gain(q,rb_A) - Mat(t-1).gain(q,rb_A);
       % diffGainTotal = Mat(t).gainTotal(q,rb_A) - Mat(t-1).gainTotal(q,rb_A);
       
      %  end
      else
         Mat(t).gain(q,rb_A)= Mat(t).apprentissageRB(q,rb_A);
         Mat(t).gainTotal(q,rb_A) = Mat(t).gainTotal(q,rb_A) + Mat(t).gain(q,rb_A);
      end
      gainTotalCell(q,rb_A)=Mat(t).gainTotal(q,rb_A);  %Mat(t).gainTotal(q,rb_A); %05/09
    %  gainTotalCell(q,rb_A)=Mat(t).gainTotal(q,rb_A)+gainTotalCell(q,rb_A);
     % fprintf('######## t=%g\t\t q=%g\t\t RB=%g \t \t gainTotal(t)=%f  \n',t,q, rb_A,Mat(t).gainTotal(q,rb_A));
     % mis en commentaire 29/08 car trop d affichage
  end
else
    if (length(RB_Cellll) == 0)
     RRC{q}=[];
     cell{q,1}.cumulDebit=0;
     sumDist=0;
    for uurrRB=1:cell{q,1}.nbrUser %length(cell{q,ta}.rbUserPris)
      rb_aaA=cell{q,ta}.rbUserPris(uurrRB);            
      cell{q,t}.RB(rb_aaA).SINR = calculSINR(cell{q,ta}.RB(rb_aaA).dist, sumDist, PuisUsed(q,rb_aaA), beta, noise);
 %  fprintf('--------------- t=%g\t\t q=%g\t\t RB=%g \t \t SINR =%f  \n',t,q, rb_aaA, cell{q,t}.RB(rb_aaA).SINR);
     %30/08 
      cell{q,t}.RB(rb_aaA).Throughput = W * log(1 + cell{q,t}.RB(rb_aaA).SINR);
      cell{q,1}.cumulDebit=cell{q,1}.cumulDebit+cell{q,t}.RB(rb_aaA).Throughput; %20/08            
      Mat(t).qValue(q,rb_aaA)=W*log(1+cell{q,t}.RB(rb_aaA).SINR); %fct QValue 
      Mat(t).apprentissageRB(q,rb_aaA)=cell{q,ta}.probCollision * Mat(t).qValue(q,rb_aaA); %fct d'apprentissage
      %  fprintf('** sauv=%g\t\t q=%g\t\t wwRbConfli=%g \t \t voisin= %g\n',sauv,q,rb_A, voisin);     
      if (t>1)
          %27/08 ==> quelques petites modifs en utilisant la variable sauv
          %car c le m�me principe que lorsque l on ex�cute le m�canisme de
          %changement de RB
%        if (length(intersect(T{sauvegardddd}.cellO{q},rb_aaA )) > 0)  
%          Mat(t).gain(q,rb_aaA)= Mat(t).apprentissageRB(q,rb_aaA) - Mat(sauvegardddd).apprentissageRB(q,rb_aaA); 
%          %cell{q,t}.probCollision*apprentissageRB(q,ww);
%          %  disp('!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!');  
%          Mat(t).gainTotal(q,rb_aaA) = Mat(t-1).gainTotal(q,rb_aaA) + Mat(t).gain(q,rb_aaA);
%          diffGainTotal = Mat(t).gainTotal(q,rb_aaA) - Mat(sauvegardddd).gainTotal(q,rb_aaA);
%          %06/08/2013
%        else
      
         Mat(t).gainTotal(q,rb_aaA) =0;
         Mat(t).gain(q,rb_aaA)= abs( Mat(t-1).apprentissageRB(q,rb_aaA) - Mat(t-1).apprentissageRB(q,rb_aaA));
        % Mat(t).gainTotal(q,rb_aA)=0;
         Mat(t).gainTotal(q,rb_aaA) = Mat(t-1).gainTotal(q,rb_aaA) + Mat(t).gain(q,rb_aaA);
         diffGainTotal = Mat(t).gainTotal(q,rb_aaA) - Mat(t-1).gainTotal(q,rb_aaA);
        %diffGainTotal = Mat(t).gain(q,rb_aaA) - Mat(t-1).gain(q,rb_aaA);
      % end
      end
      gainTotalCell(q,rb_aaA)=Mat(t).gainTotal(q,rb_aaA); %Mat(t).gainTotal(q,rb_aaA);
     % gainTotalCell(q,rb_aaA)=Mat(t).gainTotal(q,rb_aaA)+gainTotalCell(q,rb_aaA);
     % fprintf('######## t=%g\t\t q=%g\t\t RB=%g \t \t gainTotal(t)=%f  \n',t,q, rb_A,Mat(t).gainTotal(q,rb_A));
    %mis en commentaire 29/08 car trop d affichage
    end
    
     
    end
end   
     
%ici il faut avoir une boucle pr tt les RB de chaque cellule pr calculer le
%gain de la cellule

cumulGainTotal=0;
cumSINR=0;
for allRB=1:length(cell{q,ta}.rbUserPris)
    rbActuel=cell{q,ta}.rbUserPris(allRB);
    cumulGainTotal= cumulGainTotal + gainTotalCell(q,rbActuel); % Mat(t).gainTotal(q,rbActuel);
    cumSINR=cumSINR+cell{q,t}.RB(rbActuel).SINR ; %05/09
end

if(t>1)
        Mat(t).gainCellAll(q)=Mat(t-1).gainCellAll(q)+ cumulGainTotal;
        Mat(t).sinrCellAll(q)= Mat(t-1).sinrCellAll(q)+cumSINR; %05/09
      %  fprintf('** t-1=%g\t\t q=%g\t\t gainCell(t)=%f \t \t gainCell(t-1)= %f\n',t-1,q,Mat(t).gainCell(q), Mat(t-1).gainCell(q));   

end
Mat(t).gainCell(q)= cumulGainTotal;
Mat(t).sinrCell(q)= cumSINR; %05/09


fprintf(fiTest, '%d \t %d \t %f \t %f \t  %f  \n', q, t, Mat(t).gainCell(q), Mat(t).gainCellAll(q),  cell{q,ta}.probCollision );  

fprintf(fiTestAAA, '%d \t %d \t %f \t %f \t %f  \n', q, t, Mat(t).gainCell(q),Mat(t).gainCellAll(q), cell{q,ta}.probCollision );  
 
%arriv�e d un msg CQI  ==> 10/07/2013 ==> 20/08 modif d'emplacement de ce
%test
if (mod(t, t_CQI) ==0)
    cpt_CQI=cpt_CQI+1;  
        %  Mat(t).gainCell(q);    
    %�criture dans un fichier 20/08 la fct globale de chaque cellule pr tracer une courbe en fct du nbre d'it�rations
 %27/08
    OutputFileGainProb= strcat('Gain&Proba-', num2str(q), '.dat'); %pr les attentes et transmis
    if (cpt_CQI==1)
         fiDistrib = fopen(OutputFileGainProb, 'w');  %wt
   % fprintf(fiDistrib, '%d \t %f \t %f \n',  q,  PI{yy}(xx), sommeProba);  %indice de la trame et sa taille
    else
          fiDistrib = fopen(OutputFileGainProb, 'a+');  %wt
    end
    
   fprintf(fiDistrib, '%d \t %d \t %f \t %f \t %f  \n', q, t, Mat(t).gainCellAll(q), Mat(t).gainCell(q), cell{q,ta}.probCollision );  
   fclose(fiDistrib);
end
fclose(fiTestAAA);
end %le end de l'ensemble des cellules 


   if ((cpt_RNTP >= 1) && (t> dur1RNTP) ) %on utilise cette variable pour �tre sur que l'on a bien re�u d�j� un premier msg RNTP
     for celParcour=1:V
      for inde=1:length(cell{celParcour,ta}.voisins) 
        %on suppose que les cellules restent � la config initiale (indice t=1) par rapport aux voisinages cell{q,1}.voisins
        vois=cell{celParcour,ta}.voisins(inde);
        if (mod((t+1), dur1RNTP)~=0)
        if (Mat(t).matriceInterf(celParcour,vois) >  Mat(mod((t+1), dur1RNTP)).matriceInterf(celParcour,vois))
           %le nbre d interf�rence a augment� ==> continuer � d�rouler l
           %algo
            continuer=1;
        else
            continuer=0; %il faut arr�ter l'algo, convergence OK
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
%==> condition de stabilit� ==> convergence de l algo
if t>=2  
    switch varianteStab
        case 1    
            %utiliser la fct de gain globale au sein de chaque cellule
            diffG=0;
            for cc=1:V
                diffG=Mat(t).gainCell(cc)-Mat(t-1).gainCell(cc); 
                if (round(diffG)==0)   % ==0   <= epsilon
                    %rajout du round 05/09
                     okStable=okStable+1;
                     continuer=0;
                else
                     continuer=1;
                end
            end
                
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
            %voir par rapport aux SINR des RBs utilis�s
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
                 end
             end
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
                diffSS=Mat(t).sinrCell(q) -Mat(t-1).sinrCell(q) ; 
                if (round(diffSS)==0)   % ==0   <= epsilon
                    %rajout du round 05/09
                     okStable=okStable+1;
                     continuer=0;
                else
                     continuer=1;
                end
            end

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
            %tester sur le nbre d interf�rences entre 2 it�rations non
            %cons�cutives pour chacune des cellules comme ce que j'avais
            %fait pr le SP3   
    end
end


             
tConverg=tConverg+1;   
if boolll == 1
     sauv=t;
     for ce=1:V
         T{sauv}.Cel{ce}=LLV{ce};

     end
end

if boolTest==1
    sauvegardddd=t;
    for indC=1:V
        T{sauvegardddd}.cellO{indC}=RRC{indC};
    end
end

%ce test permet d indiquer d'un msg RNTP est arriv� et qu il faut verifier
%par rapport � la convergence de l algo
   if (mod(t, t_RNTP) == 0)
     %arriver d un msg RNTP
     cpt_RNTP=cpt_RNTP+1; %compteur du nombre de msg RNTP
  
        % note le 03/07/2013: a voir ce qui suit
        % il faut comparer la matrice � l instant (t) et � (t-1) pr voir s
        % il y a eu changement si c le cas pas de convergence encore
        
%      for celParcour=1:V
%       for inde=1:length(cell{celParcour,ta}.voisins) 
%         %on suppose que les cellules restent � la config initiale (indice t=1) par rapport aux voisinages cell{q,1}.voisins
%         vois=cell{celParcour,ta}.voisins(inde);
%         if (Mat(t).matriceInterf(celParcour,vois) >  Mat(t).matriceInterf(celParcour,vois))
%             continuer=1;
%         else
%             continuer=0; %il faut arr�ter l'algo, convergence OK
%         end
%       end 
%      end
        
   end
  
          %j'ai d�plac� ce test 05/09  car il �tait r�p�titif dans les 3 cas du switch  
            if (t>1) 
            if(okStable==V) 
                  cptStable(t)=cptStable(t-1)+1;   %06/09
            end
            else
                cptStable(t)=0;
            end
            %04/09 test rajouter
            if (cptStable(t) == Nstabilisation)
                 boolOKstable=1;
                % break; %06/09 
            else
                 boolOKstable=0;
            end 
            if(t>1) %06/09
              if (cptStable(t) - cptStable(t-1) == 1)
                break;
              end
            end
            
 t=t+1;  
 end
 
 
 fprintf(2,' t=%g \t \t cptStable=%g \t \t okStable= %g \t \t okiii=%g  \n',t, cptStable(t), okStable, okiii);

 if ((t>1) && (okStable== V) )
     %26/08 rajout de ce test; et correction que sur la division c par
     %(t-1) et non t
     calcNbreMoyenInterf=0;
     calcNbreModifTotal=0;
    for qaa=1:V  %03/09
        calcNbreModifTotal=calcNbreModifTotal+ cell{qaa,1}.nbrRBmodif; 
    end
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
  fprintf ('---------  FIN CONVERGENCE OK   --------- re�u %d  \t msg RNTP  ---- \t %d msg CQI -- %d s  \t duree de convergence  \n', cpt_RNTP, cpt_CQI,  tConverg);
 end
 


fclose(fiSINR_Debit); %pr v�rifier les valeurs des d�bits et SINR
fclose(fi);
fclose(fiTest);
fclose(fiRecompGain);
fclose(fichierA); %les graphiques se feront en dehors de ce code matlab

axis square
hold off