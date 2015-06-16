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
              
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clc;
clear all;
%close all;
clf %clear figure

varianteALGO=1; %1: tous les users utilisent la meme puissance de transmission dans tout le reseau; 2: les users d'une meme cellule sont sur la meme puisssance; 3: la puissance de transmission d un user est en fct de sa distance par rapport au eNB
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
N = 5;     %Number of RBs/cell
R = 15;     %Radius of Hexagon
M = N;     %Number of users => au max nbre user= nbre de RBs
V=7; %number of cells => pr le moment nous considerons uniquement 7 cellules
rayonPorte_eNB=10; %km
W=180000; %hz bande passante ==> c 180khz pr 1 RB %10/07/2013
%PuissBruit=2; %puissance du bruit, je l avais rajouté en pensant utilisé
%la formule de shannon directement mais je remplace ca par le SINR
t=1; %indice de temps
T=10; %temps de simul
epsilon=10^(-10);
alpha=2;
PuisMax= 50;
portion=0.8;
noise=10^(-alpha)*PuisMax; %noise variance  on peut egalement le prendre directement comme etant 10^(-alpha)
beta=4; %valeur essentiel pour le calcul du SINR d'un user

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
PuisSeuil = PuisMax*portion; %c juste un exemple
PuisUsed=zeros(V, N);
 %choisir une puissance que tous les users vont avoir pr la premiere variante de l algo
dur=10;
t_RNTP=200; %a chaque 200 ms un msg RNTP est envoye sur le lien X2
t_CQI=2; % 2ms mais max c 3 ms 10/07/2013
tConverg=1; % compteur pr calculer le temps de convergence de l algo, il fait que ca soit un multiple de t_RNTP
cpt_RNTP=0; %compteur du msg RNTP
TmaxConvergence=1000; %il ne faudrait pas que l'algo converge avec un temps > à 1000 ms; condition:  t_RNTP <= tConverg <= TmaxConvergence
%%%%%%%%%%%%%%%%%%%%%%%%%%%%
tabRB=zeros(V, N);
matriceRNTP=zeros(V, N);%cette matrice va contenir des 1 ou des 0 ==> 1 : le RB est utilise avec une puissance max ==> pas bon car il va déranger
apprentissageRB=zeros(V, N);
qValue=zeros(V, N);
gain=zeros(V, N);
gainTotal=zeros(V, N); %fct gain total au sein de chaque cellule, c la fct a maximiser sur un RB
gainGlobal=zeros(V);
matriceInterf=zeros(V, V); %contient le nbre de RB qui interfere entre une cellule i et une cellule j
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
        PuisUsedAll=randi([1, PuisSeuil], 1, 1); %PuisMax
        for bb=1:V
            %tous les users fonctionnenet à la même puissance
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
grid on
hold on
for j=1:V
    %Vertexes
    Mat(t).cell{j}.x = eNB{j}.x + R * cos(tp);
    Mat(t).cell{j}.y = eNB{j}.y + R * sin(tp);     
    plot(Mat(t).cell{j}.x,Mat(t).cell{j}.y);  %dessiner la cellule
    if j==1 
        plot(eNB{j}.x,eNB{j}.y,'ro'); %emplacement du eNB  
    else
        plot(eNB{j}.x,eNB{j}.y,'ko'); %emplacement du eNB
    end 
    Mat(t).cell{j}.nbrUser=randi([1, M], 1, 1);    %affecter un certain nbr d user par cellule
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
    IN = inpolygon(c_x1, c_y1, Mat(t).cell{i}.x, Mat(t).cell{i}.y);
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
           Mat(t).cell{i}.RB(u).x =Cx(u);
           Mat(t).cell{i}.RB(u).y = Cy(u);
           Mat(t).cell{i}.RB(u).dist= distance(eNB{i}.x, eNB{i}.y, Mat(t).cell{i}.RB(u).x, Mat(t).cell{i}.RB(u).y);
           Mat(t).cell{i}.RB(u).puissance=PuisUsed(i, u);
           
           if i==1  plot(Mat(t).cell{i}.RB(u).x, Mat(t).cell{i}.RB(u).y, 'g*');
           else plot(Mat(t).cell{i}.RB(u).x, Mat(t).cell{i}.RB(u).y, 'm*');
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
   cell{1}.voisins=[2 3 4 5 6 7];
   cell{2}.voisins=[1 3 7];
   cell{3}.voisins=[1 2 4];
   cell{4}.voisins=[1 3 5];
   cell{5}.voisins=[1 4 6];
   cell{6}.voisins=[1 5 7];
   cell{7}.voisins=[1 2 6];
   %il faut voir par la suite comment faire pr rajouter les voisinages à
   %deux et trois sauts
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%t=1 ==> effectuer la phase d'exploration
for k=1:V %etape init de mon algo
    %exploration step of my algo

    %placer les users dans chaque cellule => affectation alea pr l'etape init de mon algo    
    if M>N fprintf ('erreuuuurrrr \n');
    else
    % pris=[];
     Mat(t).cell{k}.rbUserPris=[];
     for h=1:Mat(t).cell{k}.nbrUser
       %placer les users sur les RBs en se basant sur l'OFDMA ==> canaux
       %orthogonaux
       %il n'existe pas plusieurs users dans la cellule k sur le meme RB
       test=0;
       while test ==0
       selectRB=randi([1, N], 1, 1);  %selectionner un RB parmis N pr chaque user 
       id=intersect(Mat(t).cell{k}.rbUserPris, selectRB);%cell{k}.rbUserPris au lieu du vecteur pris 
       if length(id)==0
         %il faut verifier si ce RB n a pas ete deja affecte
         Mat(t).cell{k}.user(h).x = Mat(t).cell{k}.RB(selectRB).x;
         Mat(t).cell{k}.user(h).y = Mat(t).cell{k}.RB(selectRB).y;
       %  plot(cell{k}.user{h}.x, cell{k}.user{h}.y, 'k+'); % pr visualiser
       %  les users
         Mat(t).cell{k}.user(h).rb = selectRB;
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
         Mat(t).cell{k}.user(h).duration = randi([1, dur], 1, 1); %duree de communication
         %il faut calculer les distances entre chaque user et le eNB
         Mat(t).cell{k}.user(h).dist = distance(eNB{k}.x, eNB{k}.y, Mat(t).cell{k}.user(h).x, Mat(t).cell{k}.user(h).y);
         test =1; 
        % pris=[pris, selectRB]; %mise a jour de l ensemble des RB pris
         Mat(t).cell{k}.rbUserPris=[Mat(t).cell{k}.rbUserPris, selectRB]; %mise a jour de l ensemble des RB pris
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
    for d=1:length(cell{k}.voisins)
        dd=cell{k}.voisins(d);
        if dd~=k 
            sum=sum + Mat(t).cell{dd}.nbrUser;
        end
    end
    Mat(t).cell{k}.probCollision=Mat(t).cell{k}.nbrUser/sum;
end

%%%%%%%%%% A VOIR!!!!!!  04/07/2013
%t=t+1; %car t=1 c etait l etape d init

%%%%%%%%%%%
continuer = -1;

%faire une fonction pr calculer le SINR ==> calculSINR
 %en prametres d entree: le num de la cellule et l'user 
 while ((t<=T) && (continuer ~= 0))

%exploitation step 
  for q=1:V
% %    %chercher pour chaque cellule q  si c cellules voisines ont utilisé
% %    %les même RB qu'elle
     sommeDistUsers = 0; 
 
     for tt=1:length(cell{q}.voisins) 
        %on suppose que les cellules restent à la config initiale (indice t=1) par rapport aux voisinages cell{q,1}.voisins
        voisin=cell{q}.voisins(tt);
        Mat(t).matriceInterf(q,voisin)=0; %initialiser la case
        
        if voisin~=q %tt
            
            cpt=0;
            t
            ta=1; %a revoir car pr le moment le rbUserPris est fixé à l étape init alors que les users changent au fur et à mesure
           if t>1 [RB_common, indexCell1, indexCell2]= intersect(Mat(t-1).cell{q}.rbUserPris, Mat(t-1).cell{voisin}.rbUserPris);
            %indexCell1: permet d'avoir les indexes au sein de la celle q
            %indexCell2: indexes pr la cellule t
           else 
               [RB_common, indexCell1, indexCell2]= intersect(Mat(t).cell{q}.rbUserPris, Mat(t).cell{voisin}.rbUserPris);
           end
            if (length(RB_common) > 0)
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
                sommeDistUsers=sommeDistUsers + Mat(t).cell{voisin}.RB(ww).puissance * (1/ Mat(t).cell{voisin}.RB(ww).dist)^beta; %on peut egalement passer par l user
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
                Mat(t).cell{q}.RB(wwRbConfli).SINR = calculSINR(Mat(t).cell{q}.RB(wwRbConfli).dist, sommeDistUsers, PuisUsed(q,wwRbConfli), beta, noise);
                %10/07/2013: rajout de la ligne permettant de calculer le débit 
                Mat(t).cell{q}.RB(wwRbConfli).Throughput=W*log(1 + Mat(t).cell{q}.RB(wwRbConfli).SINR);
                %cell{q,t}.RB(wwRbConfli).SINR %mis en commentaire 10/07/2013
                %cell{q,t}.RB(wwRbConfli).Throughput %mis en commentaire 10/07/2013
                %calcul de la fonction d'apprentissage 
                Mat(t).qValue(q,wwRbConfli)=log(1+Mat(t).cell{q}.RB(wwRbConfli).SINR); %fct QValue
                Mat(t).apprentissageRB(q,wwRbConfli)=Mat(t).cell{q}.probCollision * Mat(t).qValue(q,wwRbConfli); %fct d'apprentissage
                
                if(t>1) 
                    Mat(t).gain(q,wwRbConfli)= Mat(t).apprentissageRB(q,wwRbConfli) - Mat(t-1).apprentissageRB(q,wwRbConfli); %cell{q,t}.probCollision*apprentissageRB(q,ww);
                    Mat(t).gainTotal(q,wwRbConfli) = Mat(t).gainTotal(q,wwRbConfli) + Mat(t).gain(q,wwRbConfli);
                   %%%%%%% 
                    diffGainTotal = Mat(t).gainTotal(q,wwRbConfli) - Mat(t-1).gainTotal(q,wwRbConfli);
                    
                else
                    %init 
                    Mat(t).gain(q,wwRbConfli)=0;
                    Mat(t).gainTotal(q,wwRbConfli)=0;    
                end
                 
                %04/07/2013 g fait sortir ce test, car au cas o il faut
                %changer de RB c mieux de refaire les calcul ailleurs
                if ( diffGainTotal < 0 )
                        % il faut changer le rb "wwRbConfli" au niveau de
                        % la celle q.
                        
                        
                        %modifRB(cellSouci, RBsouci,nbrUser, rbUserPrisCell, tabRB, N )  
                      
                        newRB=modifRB(q,wwRbConfli, Mat(t).cell{q}.nbrUser, Mat(t).cell{q}.rbUserPris  , Mat(t).tabRB ,N);
                        newRB
                        %04/07/2013 ==> a voir
                        if (newRB ~= wwRbConfli)
                            %05/07/2013 ==> ttes les lignes de code de ce
                            %test "if"; on était fait aujourd'hui
                            %choisir un RB                  ===> OK
                            %calculer son SNIR
                            %mettre à jour la matriceRNTP   ===> OK
                            % ainsi que la matrice tabRB    ===> OK
                            %et les champs lié o user
                            %mettre à jour cell{q,ta}.rbUserPris; en retirant
                            %de ce tableau le RB wwRbConfli et le remplacer à
                            %son endroit par le nouveau RB 
                            
                            
                            uRB =  find(Mat(t).cell{q}.rbUserPris == wwRbConfli) ; %indexe de l user utilisant le wwRbConfli
                            Mat(t).cell{q}.user(uRB).rb = newRB; %comment
                           % récupérer le num du user uRB ??????
                            Mat(t).cell{q}.rbUserPris(uRB)=newRB;
                           
                            Mat(t).tabRB(q,newRB) = 1; % pr dire k ce rb est occupe 
                            Mat(t).tabRB(q,wwRbConfli) = 0; %  
                           
                            Mat(t).cell{q}.RB(newRB).SINR =0; %a calculer
                            
                            
                            
                            Mat(t).matriceRNTP(q,wwRbConfli)=1;
                            Mat(t).matriceRNTP(q,newRB)=2;
                            fprintf ('*******  JE SUIS ICI ******** \n');
                        else
                            %pas de changement
                             Mat(t).matriceRNTP(q,wwRbConfli)=2;
                        end
                    else
                        %remise à zéro de la variable pr la suite;
                        % ==> gain est soit > 0 (amélioré) ou = 0
                        % (inchangé)
                        diffGainTotal = 0;
                    end
                
              end 
                else
                Mat(t+1).cell{q}.rbUserPris = Mat(t).cell{q}.rbUserPris;
                Mat(t+1).cell{voisin}.rbUserPris = Mat(t).cell{voisin}.rbUserPris;
              end
        end
     end
     
     
     
% % mise en commentaire des  lignes svtes permettant le calcul de la
% récompense car je l ai déplacé plus haut dans la boucle mise le
% 03/07/2013
%     Mat(t).gainTotal(q,ww)= 0; % erreur corrige le 02/07/2013; il faut ini cette variable
%     cell{q,ta}.RB(ww).SINR = calculSINR(cell{q,ta}.RB(ww).dist, sommeDistUsers, PuisUsed(q,ww), beta, noise);
%     %calcul de la fonction d'apprentissage 
%     Mat(t).qValue(q,ww)=log(1+cell{q,ta}.RB(ww).SINR); %fct QValue
%     Mat(t).apprentissageRB(q,ww)=cell{q,ta}.probCollision * Mat(t).qValue(q,ww); %fct d'apprentissage
%     if(t>1) 
%         Mat(t).gain(q,ww)= Mat(t).apprentissageRB(q,ww) - Mat(t-1).apprentissageRB(q,ww); %cell{q,t}.probCollision*apprentissageRB(q,ww);
%         Mat(t).gainTotal(q,ww) = Mat(t).gainTotal(q,ww) + Mat(t).gain(q,ww);
%     else
%         Mat(t).gain(q,ww)=0;
%         Mat(t).gainTotal(q,ww)=0;    
%     end

  end
% 
%ce test permet d indiquer d'un msg RNTP est arrivé et qu il faut verifier
%par rapport à la convergence de l algo
   if (mod(t, t_RNTP) == 0)
     %arriver d un msg RNTP
     cpt_RNTP=cpt_RNTP+1; %compteur du nombre de msg RNTP
  
        % note le 03/07/2013: a voir ce qui suit
        % il faut comparer la matrice à l instant (t) et à (t-1) pr voir s
        % il y a eu changement si c le cas pas de convergence encore
        
     for celParcour=1:V
      for inde=1:length(cell{celParcour}.voisins) 
        %on suppose que les cellules restent à la config initiale (indice t=1) par rapport aux voisinages cell{q,1}.voisins
        vois=cell{celParcour}.voisins(inde);
        if (Mat(t).matriceInterf(celParcour,vois) >  Mat(t).matriceInterf(celParcour,vois))
            continuer=1;
        else
            continuer=0; %il faut arrêter l'algo, convergence OK
        end
      end 
     end
        
   end
   if (continuer == 0)
                fprintf ('---------  FIN CONVERGENCE OK   --------- \n');
                break;   
   end
 t=t+1;  
end
axis square
hold off