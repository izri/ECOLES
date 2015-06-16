%16/07/2013 by NI
%B nbre de trames à générer
%N nbre de files
%M nbre max d arrivées cette variable n a plus de sens puisque l on utilise
%lambda
%lambda est un vecteur correspondant à chaque lambda de chaque file
%TTI 1 ms le service
function [ time Ar instantGener cumulArrive tt3] = expoGener2(lambda, tend, M, N, TTI, B, Buffer) %instantGener
%à rajouter les sorties le PI
i=1;
%TTI=1;
cpt=0;
j=1;
nb=0;
%tt3=0; %zeros(1,N);
tsim=0; 
mu=1;

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
tt3=zeros(1,N);


for n=1:N  %parcourir les files
cpt=0;
i=1;
j=1; %indice des trames
instantGener(n,1)= 0;
%mis en commentaire 23/07/2013
% ni=zeros(1,Buffer);
% Pi=zeros(1,Buffer);
 %t3=0;
while (j<=B) 
    time(n,i) = -log(rand)/lambda(n); % exprnd(lambda(n)); %
    i=i+1; %index svt
    instantGener(n,i)=instantGener(n,i-1) + time(n,i-1);  %instant de la prochaine arrivée
    Ar(n,i)=randi([1, lambda(n)], 1, 1); %générer un nbre de clients en entrée
    fprintf(fiGener, '%d \t %d \t %f \t %d \n', i-1, j,  instantGener(n,i-1), Ar(n,i) );
    Arriv=Arriv+Ar(n,i);
    cpt=cpt+time(n,i-1);
    %mis en commentaire 23/07/2013
%     nb=nb+Ar(n,i);
%    
    if (cpt < TTI)
      % ni(nb)=ni(nb)+abs(cpt-tsim);
       tsim=cpt;
    else
       % ni(nb)=ni(nb)+abs(TTI-tsim);
        tsim=TTI;
    end
        
            
          
    
    
    
  %cumuler les arrivées durant TTI
    if (cpt==TTI)
        %il faut réduire pr chak nb
      cumulArrive(n,j)=Arriv;
      fprintf(fiArrivee, '%d \t %d  \t %d \n',  n, j, cumulArrive(n,j) );  %indice de la trame et l'arrivée pr cette trame  %n=num de la file; %j=idf de la trame 
      Arriv=0;
      j=j+1;
      cpt=0;
      
    else
      if (cpt>TTI)
        cumulArrive(n,j)=Arriv-Ar(n,i);
        fprintf(fiArrivee, '%d \t %d  \t %d \n',   n, j, cumulArrive(n,j) );  %indice de la trame et l'arrivée pr cette tram
        Arriv=Ar(n,i);
        j=j+1;
        cpt=time(n,i-1);       
      end   
    end 
    %mis en commentaire 23/07/2013
    tt3(n)=tt3(n)+tsim;
end
%mis en commentaire 23/07/2013
%Pi=ni/t3;%
%PI{n}=[(1-sum(Pi)) Pi]; 



%il faut voir comment sauvegarder pr chacune des files n le vecteur de
%distribution de proba
end
fclose(fiArrivee);
fclose(fiGener);
end