%15/07/2013 by Nora IZRI
    %%%%%%%%%%%%% History
      %   modified 16/07/2013 
      %rajout des sauvegardes de résultat dans les fichiers
      %modified 17/07/2013
      % processus poisson en entree de chacune des files     
%PRiSM Laboratory
%23/07/2013 ==> ok pr le calcul des distributions de chaque files
%==> il faudra intégrer les distributions des trames
%à rajouter la notion de stabilité ==> ligne 151
%voir la ligne 204 par rapport à la variable t3 est ce k je peux la laisser
%la bas
%25/07/2013 ==> finalisation de la condition de stabilité

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% clc;
% clear all;
%close all;
%clf %clear figure
 
% grid on
% hold on
%on suppose que la trame a deja une partie ctrl et entete ==> ce qui
%signifie que la variable C est associee uniquement a la partie info
%C=710; %taille max de la trame
Cap=C;
N=2; %nbre de files 
n=1; %indice de la trame courante
M=5; %nbre de paquets max a generer en entree
%T_max=10; %la duree de simul
TTI=1; %la duree de construction de la trame;
%H=T/TTI; %nbre de trames possibles de generer
if mod(T_max,TTI)==0
    H=floor(T_max/TTI); %nbre de TTI qui passe
else
    H=floor(T_max/TTI)+1;
end
portion=0.4;
MaxVal=round(T_max*portion);
epsilon=10^(-6);
a=3; %valeur max pr le seuil min pr générer le PBR
b=5; %valeur max pr le seuil max pr générer le max
%Buffer=1700; %taille max du buffer
%lambda=6; 
hm=10; %valeur max de lambda
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
OutputFileTrame= strcat('taillesTrames.dat'); %pr les trames
fiTrame = fopen(OutputFileTrame, 'w');  %wt

OutputFile= strcat('indicesPerf.dat'); %pr les attentes et transmis
fi = fopen(OutputFile, 'w');  %wt
OutputFileStep1= strcat('indicesPerfStep1.dat'); %pr les attentes et transmis
fiStep1 = fopen(OutputFileStep1, 'w');  %wt
somme=0;
j=1;
c_min=zeros(1,N);
c_max=zeros(1,N);
c_max(1)=2457; %1638;
c_min(1)=16;
lambda(1)=30; %240kb/s
%buffer(1)=1700;
c_max(2)=819; %410;
c_min(2)=8;
lambda(2)=700; %320kb/s = 40 o/TTI //// 700 o/TTI = 5.6 Mb/s
%buffer(2)=500;
%%%%% section affectation des valeurs buffer, min et max associé pr chaque file
while ((j<=N) ) %&& (Cap>=0)
    buffer(j)=Buffer; %on suppose que toutes les files ont la meme taille de buffer
%  lambda(j)=randi([1, hm], 1, 1);
    %parametres min et max pr la QoS
    %pr le moment tte les files on les meme seuils min et max
   
    %c_max(j)=randi([1, Cap], 1, 1);  %mis en commentaire 18/09 %il ne faut oublier que la somme des c_max =C
    somme=somme+c_max(j);
    %c_min(j)= randi([1, c_max(j)], 1, 1); %mis en commentaire 18/09
   % lambda(j)= c_min(j); %randi([ c_min(j), c_max(j)], 1, 1); %pr verifier que les files sont stables, la somme des rho est < à 1
   
    
    %mis en commentaire 18/09
%     if ((Cap-c_max(j) <0) && j > N) 
%         break;
%     else
%         if (Cap-c_max(j) > 0)
%              Cap=Cap-c_max(j);
%         else
%             break;
%         end
%     end
%     
       j=j+1;
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%etant donné qu'avec ce model, on suppose que les trames ont été déjà
%pré-rempli par les PBRs
minTotal=0;
for d=1:N
    minTotal = minTotal+ c_min(d);
end

%capacity=somme-minTotal; %capacité restante dans la trame
capacity=C; %-minTotal;
 %récup de data d entree à partir du fichier 

 
 %extraire les valeurs des  arrivees du fichier 
 ArriveFile=zeros(N,H);
 t3=zeros(1,N);
 % time Ar instantGener cumulArrive
 [tempsAr ArrivInst instantGene ArriveFile t3]=expoGener2(lambda, T_max, M, N, TTI, H, buffer); %Buffer);
 bool=0;
 
 [linf col]=size(tempsAr);
 [linF nbrAr ]=size(ArrivInst);
%linf == nbre de files
%on sait que: col=nbrAr mais c juste pr tester
stock=zeros(1,N);
for u=1:N
    stock(u)=1;
end
tsim=zeros(1,N); 
mu=1;

nb=zeros(1,N); 

tailleRetir=zeros(1,N);
t1=0;
tailleRetirStep1=zeros(1,N);
%%%%%%%%%%% section creation des trames %%%%%%%%%%%%
%critère de stabilité à rajoute rpar rapport à la taille des trames

 tabSizeTrame=[];
 stab=0;
 cycle=0;
 boolModif=0;
 TailleTrame=[];
 nn=1;
while (nn<=H) 
       for i=1:N
          %indiquer que les sorties et les attentes sont nulles
         trame(nn).file(i).X=0;
         trame(nn).file(i).out=0;
         trame(nn).file(i).A= 0; % randi([1, M], 1, 1); %à transformer en proccessus de poisson
       end
       trame(nn).taille=0;
        nn=nn+1;
      end
 
while ((n<=H) && (t1<=T_max) && (stab==0) ) %modi 20/09 n<=T_max par n<=H

%       for i=1:N
%           %indiquer que les sorties et les attentes sont nulles
%          trame(n).file(i).X=0;
%          trame(n).file(i).out=0;
%          trame(n).file(i).A= 0; % randi([1, M], 1, 1); %à transformer en proccessus de poisson
%       end
      trame(n).taille=0;
  
      h=1;
      if(bool ==0) 
          sizeT=0;
          sommeOUT=0;
          bool=-1;
      else
          sizeT=0;
          for in=1:N
             sizeT=sizeT+tailleRetir(in);
          end
          sommeOUT=sizeT;
          bool=-1;
      end
     trame(n).taille=sizeT;
     sortiFile=zeros(1,N);

     for cptFile=1:N %arrivees
       trame(n).file(cptFile).A =  ArriveFile(cptFile,n);  
   % disp(trame(n).file(cptFile).A );
     end
  
       %problm avec sizeT ==> 3/10/2013
   capacity=C;    
   cycle=1;
     while ( (h<=N) && (sizeT < capacity) ) %on vérifie aussi par rapport à la taille de la trame
%          if (h==1)
%             cycle=1; 
%          end
         if cycle==1
             ni=zeros(N,buffer(h)+1);
             Pi=zeros(1,buffer(h)+1); 
         end
         if (boolModif==0) 
              count=0;
         else
              count=abs(count-TTI);  %18/09 ==> voir si c utile de faire ca!!!!
         end
            hg=stock(h);    
           while ((hg<col) && (count <TTI)) %arrivee ==> pr la distr de proba
           count=min(TTI, count+tempsAr(h,hg));
          % nb(h)=nb(h)+ArrivInst(h,hg);
       
           if (count <= TTI)
            if (nb(h)>0) 
                ni(h,nb(h))=ni(h,nb(h))+abs(count-tsim(h));
            end
            nb(h)= min( buffer(h), nb(h)+ArrivInst(h,hg));
            tsim(h)=count;
           end
         %  disp( tsim(h));
             hg=hg+1;
           end
   
parr=1;
sommeMin=0;
if (cycle==1)
 
while ( (parr<=N) && (sizeT < capacity))
    trame(n).file(parr).L = min(c_min(parr), trame(n).file(parr).X + trame(n).file(parr).A);
    trame(n).file(parr).out = min(max(0, capacity-trame(n).taille)+sommeOUT, trame(n).file(parr).L); %transmis
    trame(n).file(parr).initOut=trame(n).file(parr).out;
    sommeMin=sommeMin+trame(n).file(parr).out;      
    sommeOUT = min(sommeOUT+trame(n).file(parr).out, capacity-trame(n).taille);
     %tt ce que j ai pu extraire jusqu à présent  
    % disp( trame(n).file(h).out);
    trame(n).file(parr).A=max(0,trame(n).file(parr).A-trame(n).file(parr).out);
    trame(n).file(parr).X =max(0, min(buffer(parr), trame(n).file(parr).A)); % trame(n).file(parr).X+trame(n).file(parr).A)- trame(n).file(parr).out); %Attente
      %min(buffer(h),max(0, trame(n).file(h).X+trame(n).file(h).A- trame(n).file(h).out));    
    if ((sizeT+trame(n).file(parr).out <=capacity) ) %  (sommeOUT <=capacity)
             sizeT= sizeT+trame(n).file(parr).out;
             bool=0;
     else
           %   sizeT=sizeT-trame(n).file(h).out;
              tailleRetirStep1(parr)=trame(n).file(parr).out;
              bool=1;
             % break;
      end 
         
          %sizeT=trame(n).taille;
   
   % disp(trame(n).taille);
    fprintf(fiStep1, '%g \t %g \t %g \t %g \t %g \t %g \t %g\n', n ,  parr, trame(n).file(parr).out, trame(n).file(parr).L, trame(n).file(parr).X, sommeOUT,  trame(n).taille);  %indice de la trame et sa taille
 
    sortiFile(parr)= sortiFile(parr)+trame(n).file(parr).out;
    parr=parr+1;
end
 trame(n).taille=min(sizeT, capacity);
 %disp(trame(n).taille);
cycle=2;
sommeOUT=0;
end   

          TEST=trame(n).file(h).X; % +  max(0, trame(n).file(h).A-trame(n).file(h).out) 
          trame(n).file(h).L = min(max(0,c_max(h)-trame(n).file(h).out ), TEST);
%           n
        %  disp( trame(n).file(h).L);
%            h
          trame(n).file(h).out = min(max(0, capacity-(trame(n).taille+sommeOUT)), trame(n).file(h).L); %transmis
       %   disp(trame(n).file(h).out);
          Btest=sommeOUT+trame(n).file(h).out;
          trame(n).file(h).A=max(0,trame(n).file(h).A-trame(n).file(h).out);
          sommeOUT = min(Btest, max(0,capacity-sizeT)); %trame(n).taille));
              %tt ce que j ai pu extraire jusqu à présent
          trame(n).file(h).X =max(0, min(buffer(h), trame(n).file(h).A)); %trame(n).file(h).X+trame(n).file(h).A)- trame(n).file(h).out); %Attente
         %min(buffer(h),max(0, trame(n).file(h).X+trame(n).file(h).A- trame(n).file(h).out)); 
          sortiFile(h)= sortiFile(h)+trame(n).file(h).out;

          %calcul des services pr la distrib de proba
          if (count >= TTI)
              if (nb(h)>0) 
               ni(h,nb(h))=ni(h,nb(h))+abs(TTI-tsim(h));
              % disp(nb(h));
              % disp('***');
              % disp(sortiFile(h));
%              aaaa= sortiFile(h)
%               bbb= nb(h)
               nb(h)=nb(h)- sortiFile(h); %max(0, nb(h)- sortiFile(h)); %trame(n).file(h).out); %service
              end
              tsim(h)=TTI;
              boolModif=1;
              stock(h)=hg-1; %pr garder une trame de l indice ou l on c arrêté
          else
              boolModif=0;
          end 

          if ((sizeT+trame(n).file(h).out <=capacity) ) %  (sommeOUT <=capacity)
             sizeT= sizeT+trame(n).file(h).out;
             bool=0;
          else
              tailleRetir(h)=tailleRetirStep1(h)+trame(n).file(h).out;
              bool=1;
             % break;
          end 
 
      %  trame(n).taille=min(sizeT, capacity);
        fprintf(fi, '%g \t %g \t %g \t %g \t %g \t %g \t %g\n', h, n ,  trame(n).file(h).out, trame(n).file(h).L, trame(n).file(h).X, sommeOUT,  trame(n).taille);  %indice de la trame et sa taille
        h=h+1;        
    end %fin de la boucle qui parcours ttes les files
     
    
       trame(n).taille=min(sizeT, capacity);
    
    
       TailleTrame=[TailleTrame, trame(n).taille];
       fprintf(fiTrame, '%g \t %g \n',  n, trame(n).taille);  %indice de la trame et sa taille
       %condition de convergence/stabilité ==> 24/07/2013
       %25/07/2013 ==> finalisation de la condition de stabilité
     
       
       
       
       
% %        tabSizeTrame=[tabSizeTrame, trame(n).taille];
% %         if n>MaxVal
% %             %for stab=1:n
% %             if( tabSizeTrame(n) ~=0 )
% %                if (mod((n),MaxVal)+1~=0)
% %                      if ((abs(tabSizeTrame(mod((n),MaxVal)+1)- tabSizeTrame(n))/ tabSizeTrame(n)) < epsilon  )
% %                          stab=1;
% %                      else 
% %                          stab=0;
% %                      end
% %                else
% %                     if ((abs(tabSizeTrame(mod(n,MaxVal)+1)- tabSizeTrame(n))/ tabSizeTrame(n)) < epsilon  )
% %                          stab=1;
% %                     else 
% %                          stab=0;
% %                     end
% %                end     
% %             else %cas particulier : tabSizeTrame(n)=0
% %                  if (mod((n+1),MaxVal)~=0)
% %                      if (tabSizeTrame(mod((n+1),MaxVal))== tabSizeTrame(n))
% %                           stab=1; %arrêt
% %                      else 
% %                           stab=0;
% %                      end
% %                  else
% %                       if (tabSizeTrame(mod(n,MaxVal)+1)== tabSizeTrame(n))
% %                           stab=1; %arrêt
% %                      else 
% %                           stab=0;
% %                      end
% %                  end
% %             end
% %             %end
% %         else
% %             %pas suffisamment d'itérations
% %              stab=0;
% %         end
        % plot( n, trame(n).taille, '-*','color','blue','LineWidth',2.0); % figure
         %plot(x2,y2,'-*','color','blue','LineWidth',2.0);
 n=n+1;
 t1=t1+1;
 
end

for kkk=1:N
    OutputFileeee= strcat('indicePerffff-', num2str(kkk), '.dat'); %pr les attentes et transmis
    fiDistribbbbb = fopen(OutputFileeee, 'w');  %wt
    for uuu=1:H
     moyyyy=mean(trame(uuu).file(kkk).X);   
     ecartTypA= std(trame(uuu).file(kkk).X);
     tauxErrA=1.96; %intervalle de confiance de 95%
     ajustementIntervaA=(tauxErrA*ecartTypA)/sqrt(moyyyy);
     fprintf(fiDistribbbbb, '%g \t %g \t %g  \t %g \n',  uuu ,  trame(uuu).file(kkk).X, moyyyy, ajustementIntervaA);  %indice de la trame et sa taille
    end    
    fclose(fiDistribbbbb);
end


OutputFileTrameA= strcat('results.dat'); %pr les trames
fiTrameA = fopen(OutputFileTrameA, 'a+');  %wt
moy=mean(TailleTrame);
ecartTyp= std(TailleTrame);
tauxErr=1.96; %intervalle de confiance de 95%
ajustementInterva=(tauxErr*ecartTyp)/sqrt(moy);
intervaConf1=moy+ajustementInterva;
intervaConf2=moy-ajustementInterva;
    
TailleTrame
%mean(TailleTrame);



fclose(fiTrame);
fclose(fi);
fclose(fiStep1);
% 
% 23/07/2013
for rr=1:N
 Pi=ni(rr,:)/t3(rr);
 PI{rr}=[(1-sum(Pi)) Pi];
 PI{rr};
 sum(PI{rr})
 Pi=[];
end

fprintf(fiTrameA, '%g \t %g \t %g \t %g \t %g \t %g \t %g \t %g \n', Buffer, moy, ecartTyp, ajustementInterva, intervaConf1, intervaConf2, PI{1}(buffer(1)+1), PI{2}(buffer(2)+1));  %indice de la trame et sa taille
fclose(fiTrameA);

for yy=1:N
    OutputFile= strcat('distribFile-', num2str(yy), '.dat'); %pr les attentes et transmis
    fiDistrib = fopen(OutputFile, 'w');  %wt
    sommeProba=0;
    for xx=1:buffer(yy)+1
    %   fprintf(fiDistrib, '%d \t %d \n',  xx,  PI{yy}(xx));  %indice de la trame et sa taille
       sommeProba=sommeProba+  PI{yy}(xx); %pr vérifier que la distribution est bien = à 1
       fprintf(fiDistrib, '%d \t %f \t %f \n',  (xx-1),  PI{yy}(xx), sommeProba);  %indice de la trame et sa taille
       
    end
  %  fprintf(fiDistrib, '%f \t %g \t %g \n',  sommeProba, sommeProba, sommeProba);  %indice de la trame et sa taille   
 % sommeProba 
  fclose(fiDistrib);
end


 %hold off