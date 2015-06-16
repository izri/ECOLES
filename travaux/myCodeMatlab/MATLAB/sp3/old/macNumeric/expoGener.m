%16/07/2013 by NI
function [ instantGener cumulArrive ] = expoGener(lambda, tend, M, N) %instantGener
i=1;
TTI=1;
cpt=0;
j=1;
Ar=0;
Arriv=0;

B=tend/TTI; %nbre de TTI qui passe

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
instantGener=zeros(1,tend+1);
time=zeros(1,tend+1);
instantGener(1)= 0;
  while ( (j<=B)  ) %j<=B : par rapport o nbre de trame B  
      %(time(i) + instantGener(i) <= tend ) &&(i<=tend) &&  %pk?
    time(i) = -log(rand)/lambda;
%     if (i==1) instantGener(i)= 0;%time(i);
%     else 
            i=i+1; %index svt
        if (i>1) % instantGener(i)= time(i);
         instantGener(i)=instantGener(i-1) + time(i-1);
        end
   % end
    i1=i-1;
    Ar=randi([1, M], 1, 1);
    fprintf(fiGener, '%d \t %d \t %f \t %d \n', i1, j,  instantGener(i1), Ar );
    Arriv=Arriv+Ar;
    cpt=cpt+instantGener(i1);
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
        cpt=0;       
      end   
    end 

  end
end
fclose(fiArrivee);
fclose(fiGener);