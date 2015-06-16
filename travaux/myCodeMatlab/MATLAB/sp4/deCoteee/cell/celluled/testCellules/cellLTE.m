% Yogesh Mhatre || IGOY.IN
%In this code, the cell radius was 1.4 units.
%You can alter this. For eg. If your cell radius needs to be 1 unit then replace
%1.40 by 1
%2.42 (1.4 x 1.732) by 1.732 (1 x 1.732)
%1.21 (1.4 x 0.866) by 0.866 (1 x 0.866)
%2.10 (1.4 x 1.500) by 1.500 (1 x 1.500)
%Also adjust xa, xb, ya & yb accordingly.
clc;
clear all;
%close all;
R = 1.4;
c1=R*1.732;
c2=R*0.866;
c3= R*1.500;
%Generating a hexagon with centre (0,0)and radius 1.4
t=linspace(0,2*pi,7);
ahx=0+R*cos(t);
bhx=0+R*sin(t);
plot(ahx,bhx);
plot(0,0,'ro');
grid on
hold on
% To generate 6 adjacent hexagon
a1=0+R*cos(t);                        % Upper hex
b1=c1+R*sin(t);
plot(a1,b1);
plot(0,c1,'ko');

a2=0+R*cos(t);                        % Lower hex
b2=-c1+R*sin(t);
plot(a2,b2);
plot(0,-c1,'ko'); %emplacement du eNB

a3=c3+R*cos(t);                      % Right lower hex
b3=-c2+R*sin(t);
plot(a3,b3);
plot(c3,-c2,'ko'); 

a4=c3+R*cos(t);                      % Right upper hex
b4=c2+R*sin(t);
plot(a4,b4);
plot(c3,c2,'ko');
 
a5=-c3+R*cos(t);                     % Left upper hex
b5=c2+R*sin(t);
plot(a5,b5);
plot(-c3,c2,'ko');

a6=-c3+R*cos(t);                     % Left lower hex
b6=-c2+R*sin(t);
plot(a6,b6);
plot(-c3,-c2,'ko');
 

    for i=1:250
        xa=-0.75+1.5*rand(1,1);
        ya=-1.2+2.4*rand(1,1);
        xra(i)=xa;
        yra(i)=ya;
        xb=-1+2*rand(1,1);
        yb=-0.65+1.3*rand(1,1);
        xrb(i)=xb;
        yrb(i)=yb;
        figure(1)
        plot(xra(i),yra(i),'k.');
        hold on
        plot(xrb(i),yrb(i),'k.');
   end
