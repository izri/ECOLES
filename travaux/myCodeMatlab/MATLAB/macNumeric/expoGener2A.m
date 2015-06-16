%16/07/2013 by NI
function [ instantGener cumulArrive ] = expoGener2(lambda, tend, M, N) %instantGener
i=1;
TTI=1;
cpt=0;
j=1;
Ar=0;
Arriv=0;

if mod(tend,TTI)==0
    B=tend/TTI; %nbre de TTI qui passe
else
    B=floor(tend/TTI)+1;
end

cumulArrive=zeros(N,B);
%%%%%%%%%%%%%%%%%%%%%%
OutputFile= strcat('arriveFiles.dat'); %pr les attentes et transmis
fiArrivee = fopen(OutputFile, 'w');  %wt
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
OutputFileGene= strcat('instantsGener.dat'); %pr les attentes et transmis
fiGener = fopen(OutputFileGene, 'w');  %wt
%%%%%%%%%%%%%%%%%
n=1; %indice des queues
Ar=randi([1, M], 1, 1);
for n=1:N  %parcourir les files
cpt=0;
i=1;
j=1; %indice des trames
instantGener(1)= 0;
while (j<=B) 
    time(i) = -log(rand)/lambda; 
    i=i+1; %index svt
    instantGener(i)=instantGener(i-1) + time(i-1);  
    Ar=randi([1, M], 1, 1);
    fprintf(fiGener, '%d \t %d \t %f \t %d \n', i-1, j,  instantGener(i-1), Ar );
    Arriv=Arriv+Ar;
    cpt=cpt+time(i-1);
    if (cpt==TTI)
      cumulArrive(n,j)=Arriv;
      fprintf(fiArrivee, '%d \t %d  \t %d \n',  n, j, cumulArrive(n,j) );  %indice de la trame et l'arrivée pr cette trame  %n=num de la file; %j=idf de la trame 
      Arriv=0;
      j=j+1;
      cpt=0;
    else
      if (cpt>TTI)
        cumulArrive(n,j)=Arriv-Ar;
        fprintf(fiArrivee, '%d \t %d  \t %d \n',   n, j, cumulArrive(n,j) );  %indice de la trame et l'arrivée pr cette tram
        Arriv=Ar;
        j=j+1;
        cpt=time(i-1);       
      end   
    end 

  end
end
fclose(fiArrivee);
fclose(fiGener);
end