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
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clc;
clear all;
%close all;
clf %clear figure
varianteALGO=1; %1: tous les users utilisent la meme puissance de transmission dans tout le reseau; 2: les users d'une meme cellule sont sur la meme puisssance; 3: la puissance de transmission d un user est en fct de sa distance par rapport au eNB
V=7; %number of cells => pr le moment nous considerons uniquement 7 cellules
PuisMax= 50;
portion=0.8;
PuisSeuil = PuisMax*portion; %c juste un exemple
PuisUsed=zeros(V, N);
 %choisir une puissance que tous les users vont avoir pr la premiere variante de l algo
dur=10;
t_RNTP=200; %a chaque 200 ms un msg RNTP est envoye sur le lien X2
tConverg=1; % compteur pr calculer le temps de convergence de l algo, il fait que ca soit un multiple de t_RNTP
cpt_RNTP=0; %compteur du msg RNTP
epsilon=10^(-10);
alpha=2;
noise=10^(-alpha)*PuisMax; %noise variance  on peut egalement le prendre directement comme etant 10^(-alpha)
beta=4; %valeur essentiel pour le calcul du SINR d'un user
N = 5;     %Number of RBs/cell
R = 15;     %Radius of Hexagon
M = N;     %Number of users => au max nbre user= nbre de RBs
t=1; %indice de temps
T=2;
TmaxConvergence=1000; %il ne faudrait pas que l'algo converge avec un temps > à 1000 ms; condition:  t_RNTP <= tConverg <= TmaxConvergence
%%%%%%%%%%%%%%%%%%%%%%%%%%%%
tabRB=zeros(V, N);
matriceRNTP=zeros(V, N);%cette matrice va contenir des 1 ou des 0 ==> 1 : le RB est utilise avec une puissance max ==> pas bon car il va déranger
apprentissageRB=zeros(V, N);
qValue=zeros(V, N);
gain=zeros(V, N);
gainTotal=zeros(V, N); %fct gain total au sein de chaque cellule, c la fct a maximiser sur un RB
gainGlobal=zeros(V);

matriceInterf=zeros(V, V);
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

switch varianteALGO
    %ce switch a ete fait le 05/06/2013
    case 1
        PuisUsedAll=randi([1, PuisMax], 1, 1);
        for bb=1:V
            for zz=1:N
             PuisUsed(bb,zz) = PuisUsedAll;  
            end
        end
        
    case 2
        for aa=1:V
            for hh=1:N  
             PuisUsed(aa,hh) =randi([1, PuisMax], 1, 1);
            end
        end
        
    case 3
          PuisUsedAll=randi([1, PuisMax], 1, 1);
        %rester a completer ce cas par rapport a la distance d un RB et eNB
        
end

for c=1:V
    eNB{c}.porte=10; %Km
    eNB{c}.puissanceMax=PuisMax; %db
end
%%%%%%%%%%
tp=linspace(0,2*pi,V); % génère le même t 7 fois (pr les 7 cellules)
%Generating a hexagon with centre (0,0) and,
% To generate 6 adjacent hexagon
% Generating a hexagon 
grid on
hold on
for j=1:V
    %Vertexes
    cell{j,1}.x = eNB{j}.x + R * cos(tp);
    cell{j,1}.y = eNB{j}.y + R * sin(tp);     
    plot(cell{j}.x,cell{j}.y);  %dessiner la cellule
    if j==1 
        plot(eNB{j}.x,eNB{j}.y,'ro'); %emplacement du eNB  
    else
        plot(eNB{j}.x,eNB{j}.y,'ko'); %emplacement du eNB
    end 
    cell{j,1}.nbrUser=randi([1, M], 1, 1);    %affecter un certain nbr d user par cellule
end      

%generation des RBs/Agent de maniere alea
%Generate 3N random points with square that is 2R by 2R
for i=1:V
bool=0;
Cx=[];
Cy=[];
while bool==0
%placer des RBs/Agent de maniere aleatoire dans la cellule i
    c_x1 =eNB{i}.x + R-rand(1,3*N)*2*R;
    c_y1 =eNB{i}.y + R-rand(1,3*N)*2*R;
    %get the points within the polygon
    IN = inpolygon(c_x1, c_y1, cell{i}.x, cell{i}.y);
    %drop nodes outside the hexagon
    c_x1 = c_x1(IN);
    c_y1 = c_y1(IN);
    Cx=[Cx c_x1];
    Cy=[Cy c_y1];
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
           cell{i,1}.RB(u).dist= distance(eNB{i}.x, eNB{i}.y, cell{i,1}.RB(u).x, cell{i,1}.RB(u).y);
           cell{i,1}.RB(u).puissance=PuisUsed(i, u);
           if i==1  plot(cell{i,1}.RB(u).x, cell{i,1}.RB(u).y, 'g*');
           else plot(cell{i,1}.RB(u).x, cell{i,1}.RB(u).y, 'm*');
           end
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
       %placer les users sur les RBs base sur l'OFDMA
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
         cell{k,1}.user(h).rb = selectRB;
         tabRB(k,selectRB) =1; % pr dire k ce rb est occupe
         cell{k,1}.user(h).duration = randi([1, dur], 1, 1); %duree de communication
         %il faut calculer les distances entre chaque user et le eNB
         cell{k,1}.user(h).dist=distance(eNB{k}.x, eNB{k}.y, cell{k,1}.user(h).x, cell{k}.user(h).y);
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
    for d=1:length(cell{k,1}.voisins)
        dd=cell{k,1}.voisins(d);
        if dd~=k 
            sum=sum + cell{dd}.nbrUser;
        end
    end
    cell{k,1}.probCollision=cell{k,1}.nbrUser/sum;
end


%faire une fonction pr calculer le SINR ==> calculSINR
 %en prametres d entree: le num de la cellule et l'user 
 while t<=T

%exploitation step 
  for q=1:V
% %    %chercher pour chaque cellule q  si c 6 cellules voisines ont utilisé
% %    %les même RB qu'elle
     sommeDistUsers=0; 
     for tt=1:length(cell{q,1}.voisins) %on suppose que les cellules restent à la config initiale (indice t=1) par rapport aux voisinages cell{q,1}.voisins
        voisin=cell{q,1}.voisins(tt);
        if voisin~=tt   
            cpt=0;
            [RB_common, indexCell1, indexCell2]= intersect(cell{q,t}.rbUserPris, cell{voisin,t}.rbUserPris);
            %indexCell1: permet d'avoir les indexes au sein de la celle q
            %indexCell2: indexes pr la cellule t
        
            if length(RB_common) > 0
            %il y a des RB en commun
            %il faut appliquer l'ago d'apprentissage
            % nbreCommun=length(RB_common);
            Mat(t).matriceInterf(q,voisin)=length(RB_common); 
            for f=1:length(RB_common)
                ww=RB_common(f);%num de RB
                ss=indexCell2(f); %num du user
                %le test "if" qui suit a ete commente 30/05/2013 car il a
                %ete fait juste pr des raisons de verification
%                 if cell{t}.RB(ww).dist == cell{t}.user(ss).dist
%                     cpt=cpt+1;
%                     fprintf ('%d %d OKIIIIIIIIIIIII %d %d \n',t, cpt, q, length(RB_common)); 
%                 end
% modified 05/06/2013 ==> integration de la puissance de chaque user

                sommeDistUsers=sommeDistUsers + cell{voisin,1}.RB(ww).puissance * (1/ cell{voisin,t}.RB(ww).dist)^beta; %on peut egalement passer par l user
                %premiere etape: calculer les SINR
            end
            %sommeDistUsers contient a ce niveau l impact des users utilisant le
            %meme RB dans les cellules voisines a un saut
          
            %qd on change un RB; il faut mettre a jour:
            %cell{k}.probCollision, cell{d}.nbrUser, 
            end
        end
     end
% 
    cell{q,t}.RB(ww).SINR = calculSINR(cell{q,t}.RB(ww).dist, sommeDistUsers, PuisUsed(q,ww), beta, noise);
    %calcul de la fonction d'apprentissage 
    Mat(t).qValue(q,ww)=log(1+cell{q,t}.RB(ww).SINR); %fct QValue
    Mat(t).apprentissageRB(q,ww)=cell{q,t}.probCollision * Mat(t).qValue(q,ww); %fct d'apprentissage
    if(t>1) 
        Mat(t).gain(q,ww)= Mat(t).apprentissageRB(q,ww) - Mat(t-1).apprentissageRB(q,ww); %cell{q,t}.probCollision*apprentissageRB(q,ww);
        Mat(t).gainTotal(q,ww)= Mat(t).gainTotal(q,ww)+Mat(t).gain(q,ww);
    else
        Mat(t).gain(q,ww)=0;
        Mat(t).gainTotal(q,ww)=0;    
    end
   if (mod(t, t_RNTP) == 0)
     %arriver d un msg RNTP
     cpt_RNTP=cpt_RNTP+1; %compteur du nombre de msg RNTP
  
   end
  end
% 
t=t+1;

end
axis square
hold off