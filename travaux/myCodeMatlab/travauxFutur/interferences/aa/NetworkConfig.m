%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
historique
clear all;
clc;
%close all;
%clf %clear figure
varianteStab=1; %1: usage de la fct de gain globale pr chaque cellule; 2 : usage du SINR pr chaque RB de chaque cellule
varianteALGO=1; %1: tous les users utilisent la meme puissance de transmission dans tout le reseau; 2: les users d'une meme cellule sont sur la meme puisssance; 3: la puissance de transmission d un user est en fct de sa distance par rapport au eNB
varianteChooseRB=1;
Nstabilisation=2; %pr verifier que pendant ce nbre d itérations les paramètres n ont pas changé
N = 6;     %Number of RBs/cell  ==> 6 pr SOAPS

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

% eNB{1}.x=0; eNB{1}.y=0; %center 
% eNB{2}.x=0; eNB{2}.y=c1; % Upper hex
% eNB{3}.x=0; eNB{3}.y=-c1; % Lower hex
% eNB{4}.x=c3; eNB{4}.y=-c2;  % Right lower hex
% eNB{5}.x=c3; eNB{5}.y=c2;  % Right upper hex
% eNB{6}.x=-c3; eNB{6}.y= c2;    % Left upper hex
% eNB{7}.x=-c3; eNB{7}.y=-c2;  % Left lower hex
% 
% 


%le vecteur ajust correspond aux coordonnees des eNBs
eNB{1}.x=0; eNB{1}.y=0; %center 
eNB{7}.x=0; eNB{7}.y=c1; % Upper hex
eNB{4}.x=0; eNB{4}.y=-c1; % Lower hex
eNB{3}.x=c3; eNB{3}.y=-c2;  % Right lower hex
eNB{2}.x=c3; eNB{2}.y=c2;  % Right upper hex
eNB{6}.x=-c3; eNB{6}.y= c2;    % Left upper hex
eNB{5}.x=-c3; eNB{5}.y=-c2;  % Left lower hex
ta=1; %a revoir car pr le moment le rbUserPris est fixé à l étape init alors que les users changent au fur et à mesure


OutputFileUser= strcat('nbrUserCell.txt'); %pr le débit
fi = fopen(OutputFileUser, 'w');  %wt




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
% % grid on  %06/09
% % hold on %06/09
%figure(1);
for j=1:V
    %Vertexes
    cellule{j,1}.x = eNB{j}.x + R * cos(tp);
    cellule{j,1}.y = eNB{j}.y + R * sin(tp);     
% %     plot(cellule{j}.x,cellule{j}.y, 'b');  %dessiner la cellule  05/09
% %     if j==1 
% %        plot(eNB{j}.x,eNB{j}.y,'rd'); %emplacement du eNB  ==> le central je le voulais en rouge "ro"
% %     else 
% %       plot(eNB{j}.x,eNB{j}.y,'rd'); %emplacement du eNB 
% %     end 
    cellule{j,1}.nbrUser=randi([1, M], 1, 1);    %affecter un certain nbr d user par cellule
    fprintf(fi, '%d \t %d \n',  j, cellule{j,1}.nbrUser);  
    cellule{j,1}.cumulInterfRB=0;
    cellule{j,1}.cumulDebit=0;
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
    IN = inpolygon(c_x1, c_y1, cellule{i}.x, cellule{i}.y);
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
           cellule{i,1}.RB(u).x = Cx(u);
           cellule{i,1}.RB(u).y = Cy(u);
           cellule{i,1}.RB(u).dist= distance(eNB{i}.x, eNB{i}.y, cellule{i,ta}.RB(u).x, cellule{i,ta}.RB(u).y);
           cellule{i,1}.RB(u).puissance=PuisUsed(i, u);
           cellule{i,1}.nbrRBmodif=0; %27/08/2013
% %            if i==1  
% %                plot(cellule{i,1}.RB(u).x, cellule{i,1}.RB(u).y, 'g*');
% % %%%%g*  05/09
% %            else
% %                plot(cellule{i,1}.RB(u).x, cellule{i,1}.RB(u).y, 'm*');
% %            end
        end
        bool=1;
    end
end
 % if i==1  plot(c_x11, c_y11, 'g*');
 % else plot(c_x11, c_y11, 'm*');
 % end
end

fclose(fi);
% % %legend(t(1:V,:));
% % axis square
% % hold off
