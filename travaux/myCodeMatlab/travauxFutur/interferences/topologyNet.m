
for j=1:V
    %Vertexes
    cellule{j,1}.x = eNB{j}.x + R * cos(tp);
    cellule{j,1}.y = eNB{j}.y + R * sin(tp);     
    plot(cellule{j}.x,cellule{j}.y, 'b');  %dessiner la cellule  05/09
    if j==1 
        plot(eNB{j}.x,eNB{j}.y,'rd'); %emplacement du eNB  ==> le central je le voulais en rouge "ro"
    else
        plot(eNB{j}.x,eNB{j}.y,'rd'); %emplacement du eNB
    end 
    cellule{j,1}.nbrAgents=randi([1, M], 1, 1);    %affecter un certain nbr d user par cellule
    fprintf(fi, '%d \t %d \n',  j, cellule{j,1}.nbrAgents);  
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
           cellule{i,1}.RB(u).x =Cx(u);
           cellule{i,1}.RB(u).y = Cy(u);
           cellule{i,1}.RB(u).dist= distance(eNB{i}.x, eNB{i}.y, cellule{i,ta}.RB(u).x, cellule{i,ta}.RB(u).y);
           cellule{i,1}.RB(u).puissance=PuisUsed(i, u);
           cellule{i,1}.nbrRBmodif=0; %27/08/2013
           if i==1  plot(cellule{i,1}.RB(u).x, cellule{i,1}.RB(u).y, 'g*');
%%%%g*  05/09
           else plot(cellule{i,1}.RB(u).x, cellule{i,1}.RB(u).y, 'm*');
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
     cellule{k,1}.rbUserActifs=[];
     for h=1:cellule{k,1}.nbrAgents
       %placer les users sur les RBs en se basant sur l'OFDMA ==> canaux
       %orthogonaux
       %il n'existe pas plusieurs users dans la cellule k sur le meme RB
       test=0;
       while test ==0
       selectRB=randi([1, N], 1, 1);  %selectionner un RB parmis N pr chaque user 
       id=intersect(cellule{k,1}.rbUserActifs, selectRB);%cellule{k}.rbUserActifs au lieu du vecteur pris 
       if length(id)==0
         %il faut verifier si ce RB n a pas ete deja affecte
         cellule{k,1}.user(h).x = cellule{k,1}.RB(selectRB).x;
         cellule{k,1}.user(h).y = cellule{k,1}.RB(selectRB).y;
     %   plot(cellule{k}.user{h}.x, cellule{k}.user{h}.y, 'k+'); % pr visualiser         les users
       
        if k==1  plot(cellule{k,1}.RB(selectRB).x, cellule{k,1}.RB(selectRB).y, 'ro');
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
         cellule{k,1}.rbUserActifs=[cellule{k,1}.rbUserActifs, selectRB]; %mise a jour de l ensemble des RB pris
        % cellule{k}.user(h).puissance=PuisUsed;
         %else
        %   id
        %   length(id)
       end
      %si trouver alors rechercher à nouveau   
       end
     end
    %  cellule{k}.rbUserActifs %vecteur contenant les differents RB affecte pr les
    %  user pr la cellule k
    end
    %affecter les proba de collision pr chaque cellule
    sum=0;
    for d=1:length(cellule{k,ta}.voisins)
        dd=cellule{k,1}.voisins(d);
        if dd~=k 
            sum=sum + cellule{dd}.nbrAgents;
        end
    end
    cellule{k,1}.probCollision=cellule{k,ta}.nbrAgents/sum;
    %test 04/09 
    if ( cellule{k,1}.probCollision > 1)
        %il faut revoir le calul
        cellule{k,1}.probCollision= abs(1-cellule{k,1}.probCollision);
    end
         fclose(fileConfig);  
end
