
function [ instantGener cumulArrive ] = expoGener(lambda, tend, M, N) %instantGener
i=1;
TTI=1;
cpt=0;
j=1;
Ar=0;
Arriv=0;

B=tend/TTI; %nbre de TTI qui passe

cumulArrive=zeros(N,B);
OutputFile= strcat('arriveFiles.dat'); %pr les attentes et transmis
fiArrivee = fopen(OutputFile, 'w');  %wt

OutputFileGene= strcat('instantsGener.dat'); %pr les attentes et transmis
fiGener = fopen(OutputFileGene, 'w');  %wt

n=1;

Ar=randi([1, M], 1, 1);
for n=1:N  %parcourir les files
i=1;
j=1;
instantGener=zeros(1,tend+1);
time=zeros(1,tend+1);
while ((time(i) + instantGener(i) <= tend ) &&(i<=tend) && (j<=B)  ) 
    
    time(i) = -log(rand)/lambda;
    if (i==1) instantGener(i)= time(i);
    else 
        if (i>1) % instantGener(i)= time(i);
         instantGener(i)=instantGener(i-1) + time(i-1);
        end
    end

    Ar=randi([1, M], 1, 1);
    fprintf(fiGener, '%d \t %d \t %f \t %d \n', i, j,  instantGener(i), Ar );
    Arriv=Arriv+Ar;
    cpt=cpt+instantGener(i);
    if (cpt>TTI)
        cumulArrive(n,j)=Arriv-Ar;
        fprintf(fiArrivee, '%d \t %d  \t %d \n',   n, j, cumulArrive(n,j) );  %indice de la trame et l'arrivée pr cette tram
        Arriv=Ar;
        j=j+1;
        cpt=0;
     
    else 
        if (cpt==TTI)
        cumulArrive(n,j)=Arriv;
        fprintf(fiArrivee, '%d \t %d  \t %d \n',  n, j, cumulArrive(n,j) );  %indice de la trame et l'arrivée pr cette trame  %n=num de la file; %j=idf de la trame 
        Arriv=0;
        j=j+1;
        cpt=0;
        end
         
    end
      
    i=i+1;

    end

end
fclose(fiArrivee);
fclose(fiGener);




%-log( -rand(n,m) + 1 ) / b;
%time = -log(rand)/lambda; %loiexp( b );


% 
% 
% 
% clc;
% clear all;
% 
% 
% n=10;
% lambda=0.02;
% 
% T=zeros(1,n);
% T(1)=-log(rand)/lambda;
% for i = 2:n
%     T(i)=T(i-1)-log(rand)/lambda
% end 
% %-log( -rand(n,m) + 1 ) / b;
% %time = -log(rand)/lambda; %loiexp( b );
% 
