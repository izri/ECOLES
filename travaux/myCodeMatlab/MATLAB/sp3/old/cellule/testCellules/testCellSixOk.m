%13/05/2013 by Nora IZRI
%PRiSM Laboratory

clc;
clear all;
%close all;
clf

N = 50;     %Number of users
R = 15;     %Radius of Hexagon
%les trois variables svtes sont defini pr les ajustement des cellules
c1=R*1.732;
c2=R*0.866;
c3=R*1.500;
%le tableau ajust permet de manupuler les ajustements des cellules ainsi
%que les users
ajust(1,:)=[0,0];
ajust(2,:)=[0,c1]; % Upper hex
ajust(3,:)=[0,-c1]; % Lower hex
ajust(4,:)=[c3,-c2];  % Right lower hex
ajust(5,:)=[c3,c2];  % Right upper hex
ajust(6,:)=[-c3,c2];    % Left upper hex
ajust(7,:)=[-c3,-c2];  % Left lower hex

t=linspace(0,2*pi,7); % génère le même t 7 fois (pr les 7 cellules)
%Generating a hexagon with centre (0,0) and,
% To generate 6 adjacent hexagon
% Generating a hexagon 

grid on
hold on
for j=1:7
    %Vertexes
    v{j}.x = ajust(j,1) + R * cos(t);
    v{j}.y = ajust(j,2) + R * sin(t);     
    plot(v{j}.x,v{j}.y);  
    if j==1 plot(ajust(j,1),ajust(j,2),'ro'); %emplacement du eNB  
    else  plot(ajust(j,1),ajust(j,2),'ko'); %emplacement du eNB
    end  
end      
  
%generation des users de maniere alea
%Generate 3N random points with square that is 2R by 2R
for i=1:7
    
bool=0;
Cx=[];
Cy=[];
while bool==0
%placer des users de maniere aleatoire dans la cellule i
    c_x1 = ajust(i,1) + R-rand(1,3*N)*2*R;
    c_y1 =ajust(i,2) + R-rand(1,3*N)*2*R;
    %get the points within the polygon
    IN = inpolygon(c_x1, c_y1, v{i}.x, v{i}.y);
    %drop nodes outside the hexagon
    c_x1 = c_x1(IN);
    c_y1 = c_y1(IN);
    Cx=[Cx c_x1];
    Cy=[Cy c_y1];
    %choose only N points
    if length(Cx)>= N
        idx = randperm(length(Cx));
         %recuperer les coordonnes (x,y) de chaque user a placer dans la cellule i 
        c_x11 = Cx(idx(1:N));
        c_y11 = Cy(idx(1:N));
        bool=1;
    end
end
  if i==1  plot(c_x11, c_y11, 'g*');
  else plot(c_x11, c_y11, 'm*');
  end
end  


%     %Vertexes
%     v{2}.x = R * cos(t);    
%     v{2}.y = c1+ R * sin(t);     
%     plot(v{2}.x,v{2}.y);        % Upper hex         
%     plot(0,c1,'ko'); %emplacement du eNB
%  
%   %Vertexes
%     v{3}.x = R * cos(t);
%     v{3}.y = -c1+ R * sin(t);     
%     plot(v{3}.x,v{3}.y);                % Lower hex
%     plot(0,-c1,'ko'); %emplacement du eNB
%  
%  
%    %Vertexes
%     v{4}.x = c3+R * cos(t);
%     v{4}.y = -c2+ R * sin(t);     
%     plot(v{4}.x,v{4}.y);                % Right lower hex
%     plot(c3,-c2,'ko'); %emplacement du eNB
%  
%    %Vertexes
%     v{5}.x = c3+R * cos(t);
%     v{5}.y = c2+ R * sin(t);     
%     plot(v{5}.x,v{5}.y);                % Right upper hex
%     plot(c3,c2,'ko'); %emplacement du eNB
%    
%    %Vertexes
%    v{6}.x = -c3+R * cos(t);
%    v{6}.y = c2+ R * sin(t);     
%     plot(v{6}.x,v{6}.y);                % Left upper hex
%     plot(-c3,c2,'ko'); %emplacement du eNB
%    
%    %Vertexes
%     v{7}.x = -c3+R * cos(t);
%     v{7}.y = -c2+ R * sin(t);     
%     plot(v{7}.x,v{7}.y);                % Left lower hex
%     plot(-c3,-c2,'ko'); %emplacement du eNB
%        

% for i=2:2
% %     bool=0;
% %     Leng=0;
% %     idx=[];
% %     c_x1=[];
% %     c_y1=[];
% %     k=1;
% %     while bool==0
% %         fprintf(2,'iteration k=%g\n',k);
% %          %placer des users de maniere aleatoire dans la cellule i
% %             c_x1 = R-rand(1,2*N)*2*R;
% %             c_y1 = R-rand(1,2*N)*2*R;
% %             %get the points within the polygon
% %             IN = inpolygon(c_x1, c_y1, v{1}.x, v{1}.y);
% %             %drop nodes outside the hexagon
% %             c_x1 =[c_x1, c_x1(IN)]
% %             c_y1 = [c_y1, c_y1(IN)]
% %             %choose only N points
% %             idx =[idx, randperm(length(c_x1))];
% %             Leng=length(idx);
% %             %recuperer les coordonnes (x,y) de chaque user a placer dans la cellule
% %             %i
% %             if Leng>=N
% %                 idx1=idx(1:N);
% %                 c_x11 = c_x1(idx1);
% %                 c_y11 = c_y1(idx1);
% %                 bool=1;
% %             end
% %       k=k+1;      
% %     end
% % 
% %     plot(c_x11, c_y11, 'm*');
% 
% bool=0;
% Cx=[];
% Cy=[];
% while bool==0
% %placer des users de maniere aleatoire dans la cellule i
%     c_x1 = R-rand(1,3*N)*2*R;
%     c_y1 =c1+ R-rand(1,3*N)*2*R;
%     %get the points within the polygon
%     IN = inpolygon(c_x1, c_y1, v{i}.x, v{i}.y);
%     %drop nodes outside the hexagon
%     c_x1 = c_x1(IN);
%     c_y1 = c_y1(IN);
%     Cx=[Cx c_x1];
%     Cy=[Cy c_y1];
%     %choose only N points
%     if length(Cx)>= N
%         idx = randperm(length(Cx));
%         c_x11 = Cx(idx(1:N));
%         c_y11 = Cy(idx(1:N));
%         bool=1;
%     end
% end
%     plot(c_x11, c_y11, 'm*');
% end   
% 
%  
    
%axis square
hold off