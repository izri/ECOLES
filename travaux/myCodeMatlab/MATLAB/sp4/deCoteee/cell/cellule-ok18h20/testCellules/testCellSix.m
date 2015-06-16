%13/05/2013 by Nora IZRI
%PRiSM Laboratory

clc;
clear all;
%close all;

N = 50;     %Number of users
R = 15;     %Radius of Hexagon
c1=R*1.732;
c2=R*0.866;
c3=R*1.500;
t=linspace(0,2*pi,7); % génère le même t 7 fois (pr les 7 cellules)
%Generating a hexagon with centre (0,0)
    %Vertexes
    v{1}.x = R * cos(t);
    v{1}.y = R * sin(t);     
    plot(v{1}.x,v{1}.y);
    grid on
    hold on
    plot(0,0,'ro'); %emplacement du eNB    
       
% To generate 6 adjacent hexagon
%Generating a hexagon 
    %Vertexes
    v_x2 = R * cos(t);
    v_y2 = c1+ R * sin(t);     
    plot(v_x2,v_y2);                % Upper hex
    plot(0,c1,'ko'); %emplacement du eNB
 
  %Vertexes
    v_x3 = R * cos(t);
    v_y3 = -c1+ R * sin(t);     
    plot(v_x3,v_y3);                % Lower hex
    plot(0,-c1,'ko'); %emplacement du eNB
 
 
   %Vertexes
    v_x4 = c3+R * cos(t);
    v_y4 = -c2+ R * sin(t);     
    plot(v_x4,v_y4);                % Right lower hex
    plot(c3,-c2,'ko'); %emplacement du eNB
 
   %Vertexes
    v_x5 = c3+R * cos(t);
    v_y5 = c2+ R * sin(t);     
    plot(v_x5,v_y5);                % Right upper hex
    plot(c3,c2,'ko'); %emplacement du eNB
 
    
    
   
   %Vertexes
    v_x6 = -c3+R * cos(t);
    v_y6 = c2+ R * sin(t);     
    plot(v_x6,v_y6);                % Left upper hex
    plot(-c3,c2,'ko'); %emplacement du eNB
   
   %Vertexes
    v_x7 = -c3+R * cos(t);
    v_y7 = -c2+ R * sin(t);     
    plot(v_x7,v_y7);                % Left lower hex
    plot(-c3,-c2,'ko'); %emplacement du eNB
       
  
%generation des users de maniere alea
%Generate 3N random points with square that is 2R by 2R
%for i=1:7
 %placer des users de maniere aleatoire dans la cellule i
    c_x1 = R-rand(1,3*N)*2*R;
    c_y1 = R-rand(1,3*N)*2*R;
    %get the points within the polygon
    IN = inpolygon(c_x1, c_y1, v{1}.x, v{1}.y);
    %drop nodes outside the hexagon
    c_x1 = c_x1(IN);
    c_y1 = c_y1(IN);
    %choose only N points
    idx = randperm(length(c_x1));
    c_x1 = c_x1(idx(1:N));
    c_y1 = c_y1(idx(1:N));
    plot(c_x1, c_y1, 'm*');

%end   

 
    
%axis square
hold off