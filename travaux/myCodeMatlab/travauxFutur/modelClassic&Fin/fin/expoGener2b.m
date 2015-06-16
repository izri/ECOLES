%16/07/2013 by NI
%B nbre de trames à générer
%N nbre de files
%M nbre max d arrivées cette variable n a plus de sens puisque l on utilise
%lambda
%lambda est un vecteur correspondant à chaque lambda de chaque file
%TTI 1 ms le service
function [ time Ar instantGener cumulArrive ] = expoGener2(lambda, tend, M, N, TTI, B, Buffer) %instantGener
i=1;
%TTI=1;
cpt=0;
j=1;
t3=zeros(1,N);
tsim=0; 
mu=1;
ni=zeros(1,Buffer);
Pi=zeros(1,Buffer);
Arriv=0;
cumulArrive=zeros(N,B);
%%%%%%%%%%%%%%%%%%%%%%
OutputFile= strcat('arriveFiles.dat'); %pr les attentes et transmis
fiArrivee = fopen(OutputFile, 'w');  %wt
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
OutputFileGene= strcat('instantsGener.dat'); %pr les attentes et transmis
fiGener = fopen(OutputFileGene, 'w');  %wt
%%%%%%%%%%%%%%%%%
n=1; %indice des queues
%Ar=randi([1, M], 1, 1);
for n=1:N  %parcourir les files
cpt=0;
i=1;
j=1; %indice des trames
instantGener(1)= 0;
while (j<=B) 
    time(i) = -log(rand)/lambda(n); % exprnd(lambda(n)); %
    i=i+1; %index svt
    instantGener(i)=instantGener(i-1) + time(i-1);  %instant de la prochaine arrivée
    Ar(i)=randi([1, lambda(n)], 1, 1); %générer un nbre de clients en entrée
    fprintf(fiGener, '%d \t %d \t %f \t %d \n', i-1, j,  instantGener(i-1), Ar(i) );
    Arriv=Arriv+Ar(i);
    cpt=cpt+time(i-1);
    
   
          if (cpt < TTI)
             ni(Ar(i))=ni(Ar(i))+abs(cpt-tsim);
             tsim=cpt;
          else
             ni(Ar(i))=ni(Ar(i))+abs(TTI-tsim);
             tsim=TTI;
          end
        
            
          
    
    
    
  %cumuler les arrivées durant TTI
    if (cpt==TTI)
      cumulArrive(n,j)=Arriv;
      fprintf(fiArrivee, '%d \t %d  \t %d \n',  n, j, cumulArrive(n,j) );  %indice de la trame et l'arrivée pr cette trame  %n=num de la file; %j=idf de la trame 
      Arriv=0;
      j=j+1;
      cpt=0;
      
    else
      if (cpt>TTI)
        cumulArrive(n,j)=Arriv-Ar(i);
        fprintf(fiArrivee, '%d \t %d  \t %d \n',   n, j, cumulArrive(n,j) );  %indice de la trame et l'arrivée pr cette tram
        Arriv=Ar(i);
        j=j+1;
        cpt=time(i-1);       
      end   
    end 
    t3(n)=t3(n)+tsim;
end

   
Pi=ni/t3(n);
Pi=[(1-sum(Pi)) Pi]; 
%il faut voir comment sauvegarder pr chacune des files n le vecteur de
%distribution de proba
end
fclose(fiArrivee);
fclose(fiGener);
end