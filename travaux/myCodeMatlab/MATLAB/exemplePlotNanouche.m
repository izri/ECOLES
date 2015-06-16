%filename='LatencyAvgeNoChurnAllExp.xlsx';
 filename1='SimulResults\TreeDeviationNoChurnAlpha.xls';
 filename2='SimulResults\GossipDeviationNoChurnAlpha.xls';
 filename3='SimulResults\SV1DeviationNoChurnAlpha.xls';
 filename4='SimulResults\SV2DeviationNoChurnAlpha.xls';
 
 x1=xlsread(filename1,1,'A1:A10');
 y1=xlsread(filename1,1,'B1:B10');
 z1=xlsread(filename1,1,'D1:D9');
 errorbar(x1,y1,z1,'-o','color','blue','LineWidth',2.0);
 %plot(x1,y1,'-+','color','red','LineWidth',2.0);
 %line(x,y,'.','color','r','LineWidth',2.0);
 %grid on;
 hold on;

x2=xlsread(filename2,1,'A1:A10');
y2=xlsread(filename2,1,'B1:B10');
z2=xlsread(filename2,1,'D1:D9');
errorbar(x2,y2,z2,'-+','color','red','LineWidth',2.0);
%plot(x2,y2,'-*','color','blue','LineWidth',2.0);
%line(x,y,'-x','b','LineWidth',2.0);
%grid on;
hold on;
 
x3=xlsread(filename3,1,'A1:A10');
y3=xlsread(filename3,1,'B1:B10');
z3=xlsread(filename3,1,'D1:D9');
errorbar(x3,y3,z3,'--+','color','black','LineWidth',2.0);
%plot(x3,y3,'-+','color','black','LineWidth',2.0);
%line(x,y,'-*','b','LineWidth',2.0);
%grid on;
hold on;

x4=xlsread(filename4,1,'A1:A10');
y4=xlsread(filename4,1,'B1:B10');
z4=xlsread(filename4,1,'D1:D9');
errorbar(x4,y4,z4,'--o','color','black','LineWidth',2.0);
%plot(x4,y4,'-o','color','black','LineWidth',2.0);
%line(x,y,'-*','b','LineWidth',2.0);

xlabel('Values dynamics (Alpha)');
ylabel('Average deviation');
legend('Tree','Gossip','SV1','SV2',1);
grid on;
hold on;