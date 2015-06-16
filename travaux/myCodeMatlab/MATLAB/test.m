clc
clear all

F=[2 3 6 8 9 10 3 5 99 9 44 87];
v=zeros(1,4);
for i=1:4
   v=F-1; 
   plot(v);
   hold on
end
legend('v1','v2', 'v3', 'v4', 1);
F
v
