%13/05/2013 by Nora IZRI
%PRiSM Laboratory

clc;
clear all;
%close all;
clf

N = 50;     %Number of RBs/cell
M = 20;     %Number of users
R = 15;     %Radius of Hexagon
%les trois variables svtes sont defini pr les ajustement des cellules
c1=R*1.732;
c2=R*0.866;
c3=R*1.500;
%le tableau ajust permet de manupuler les ajustements des cellules ainsi
%que les users
%le vecteur ajust correspond aux coordonnees des eNBs
eNB(1,:)=[0,0]; %center 
eNB(2,:)=[0,c1]; % Upper hex
eNB(3,:)=[0,-c1]; % Lower hex
eNB(4,:)=[c3,-c2];  % Right lower hex
eNB(5,:)=[c3,c2];  % Right upper hex
eNB(6,:)=[-c3,c2];    % Left upper hex
eNB(7,:)=[-c3,-c2];  % Left lower hex



t=linspace(0,2*pi,7); % génère le même t 7 fois (pr les 7 cellules)
%Generating a hexagon with centre (0,0) and,
% To generate 6 adjacent hexagon
% Generating a hexagon 
grid on
hold on
for j=1:7
    %Vertexes
    cell{j}.x = eNB(j,1) + R * cos(t);
    cell{j}.y = eNB(j,2) + R * sin(t);     
    plot(cell{j}.x,cell{j}.y);  %dessiner la cellule
    if j==1 plot(eNB(j,1),eNB(j,2),'ro'); %emplacement du eNB  
    else  plot(eNB(j,1),eNB(j,2),'ko'); %emplacement du eNB
    end  
end      
  
%generation des RBs/Agent de maniere alea
%Generate 3N random points with square that is 2R by 2R
for i=1:7
bool=0;
Cx=[];
Cy=[];
while bool==0
%placer des RBs/Agent de maniere aleatoire dans la cellule i
    c_x1 =eNB(i,1) + R-rand(1,3*N)*2*R;
    c_y1 =eNB(i,2) + R-rand(1,3*N)*2*R;
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
         RB{u}.x =Cx(u);
         RB{u}.y = Cy(u);
           if i==1  plot(RB{u}.x, RB{u}.y, 'g*');
           else plot(RB{u}.x, RB{u}.y, 'm*');
           end
        end
        bool=1;
    end
end
 % if i==1  plot(c_x11, c_y11, 'g*');
 % else plot(c_x11, c_y11, 'm*');
 % end
end  

for k=1:7 %etape init de mon algo
% placer les users dans chaque cellule => affectation alea pr l'etape init de mon algo    
if M>N fprintf ('erreuuuurrrr \n');
else
    pris=[];
    for h=1:M
       %placer les users sur les RBs
       test=0;
       while test ==0
       selectRB=randi([1, N], 1, 1);  %selectionner un RB parmis N pr chaque user
       % used{h}=id;
       % for f=1:h
            %parcourir le tableau used
       % end
       % find(used, id); 
       id=intersect(pris, selectRB);
       if length(id)==0
         %il faut verifier si ce RB n a pas ete deja affecte
         user{h}.x = RB{selectRB}.x;
         user{h}.y = RB{selectRB}.y;
         user{h}.rb = selectRB;
         %il faut calculer les distances entre chaque user et le eNB
         
         test =1; 
         pris=[pris, selectRB]; %mise a jour de l ensemble des RB pris
       %  pris
         %else
        %   id
        %   length(id)
       end
      %si trouver alors rechercher à nouveau   
       end
   end
end
end

axis square
hold off