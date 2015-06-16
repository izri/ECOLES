%24/05/2013 by Nora IZRI
    %%%%%%%%%%%%% History
      %   modified 27/05/2013
      %   modified 29/05/2013
%PRiSM Laboratory
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clc;
clear all;
%close all;
%clf %clear figure
%on suppose que la trame a deja une partie ctrl et entete ==> ce qui
%signifie que la variable C est associee uniquement a la partie info
C=10; %taille max de la trame
N=2; %nbre de files 
n=1; %indice de la trame courante
M=5; %nbre de paquets max a generer en entree
T=10; %la duree de simul
TTI=2; %la duree de construction de la trame;
t=1; %la notion de temps discret ==> init a 1 car matlab ne peut pas commencer a 0 pr les tableaux
t_deb=1; %initialisation
t_fin=1; %initialisation
a=1; %valeur max pr le seuil min
b=3; %valeur max pr le seuil max 
hm=10; %valeur max de lambda
Buffer=10; %taille max du buffer

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

ni=zeros(N,Buffer);
Pi=zeros(N,Buffer);

somme=0;
Cap=C;

j=1;
%%%%% section affectation des valeurs buffer, min et max associé pr chaque file
while ((j<=N) && (Cap>=0))
    %parametres min et max pr la QoS
    %pr le moment tte les files on les meme seuils min et max
    c_min(j)=randi([1, a], 1, 1);
   %  Cap=Cap-c_min(j);       
    c_max(j)=randi([1, Cap], 1, 1); %il ne faut oublier que la somme des c_max =C
     %modif le 15/07/2013 avant c était un tirage entre 1 et b pr le c_max
    somme=somme+c_max(j);
    if (Cap-c_max(j) >0) 
         Cap=Cap-c_max(j);
    else
         Cap=0;
    end
     
    
 
    buffer(j)=Buffer; %on suppose que toutes les files ont la meme taille de buffer
    %lambda(j)=randi([1, hm], 1, 1);
    lambda(j)= c_min(j);%randi([c_min(j),c_max(j) ], 1, 1);%pr vérifier que la somme des rho < 1
    j=j+1;
end

%%%%%%%%%%%%%%%%% section processus d arrivee au niveau des files %%%%%%%%%
H=T/TTI; %nbre de trames possibles de generer
v=1;
s=1;
e=1;
z=s+TTI;


 
 ArriveFile=zeros(N,H);
  % time Ar instantGener cumulArrive
 [tempsAr ArrivInst instantGene ArriveFile]=expoGener2(lambda, T, M, N, TTI, 2*H, Buffer);

%18/07/2013
 %pr ce cas, faut changer le fct de génération des arrivées car il faudrait
 %quelle compte les arrivées dans une file en 2 pas, c'est à dire que l'on
 %va considérer par exemple que le TTI =2, le premier pas t=1 et le second
 %c t=2
 
 
 
%chaque file i correspond a une M/D/L_i/B_i
while s<=T
    if e < s <=z
        %il faut transformer les arrives de chaque file par un processus de
        %poisson =>fct de repartition de l expo: y=f(x)=1-e^(-mu x)
        %donc on aura : x= - ln(1-y) / mu
        %il ne faut pas oublier la stabilite de la file en calculant 
        %rho = lamdba E[X]/debit; en considerant que mu=debit/E[X]
      for g=1:N
        trame(v).file(g).A(s)= ArriveFile(g,v); %randi([1, M], 1, 1); %il faut specifier un processus d arrivee 
      end
      if s==z 
        e=s;
        z=e+TTI;
        v=v+1;
      end
    end
    s=s+1;
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%



%%%%%%%%%%% section creation des trames %%%%%%%%%%%%
%15/07/2013 ==> j'ai remplacé dans le code svt toutes les occurences de C
%par somme qui correspond à la capacité réelle de la trame à travers les
%c_max de chaque file
while t<=T
  
    if t==1
      n=1; 
      for i=1:N
         trame(n).file(i).L(t)=c_min(i);%min(c_min(i); trame(n).file(i).W(t
         trame(n).file(i).W(t)=0;
         trame(n).file(i).out(t)=0;
      end
      trame(n).taille=0;
      sommeOUT=0;
      t_deb=t;
      t_fin = t_deb+TTI;
    else
        if t_deb < t <= t_fin
            sommeOUT=0;
            for h=1:N
               trame(n).file(h).L(t)=min(max(0,c_max(h)-trame(n).file(h).out(t-1) ), trame(n).file(h).W(t-1) +trame(n).file(h).A(t)); %ce que je peux encore extraire de cette file
               trame(n).file(h).out(t)=min(max(0, somme-trame(n).taille)+sommeOUT, trame(n).file(h).L(t)); 
               sommeOUT=sommeOUT+trame(n).file(h).out(t); %tt ce que j ai pu extraire jusqu à présent
               trame(n).file(h).W(t)=max(0, min(buffer(h), trame(n).file(h).W(t-1)+trame(n).file(h).A(t))- trame(n).file(h).out(t)); 
               trame(n).taille= trame(n).taille+trame(n).file(h).out(t);
            end
          if t==t_fin
           %entamer la trame svte 
            t_deb=t;
            t_fin = t_deb+TTI;
            trame(n+1).taille = 0;
            %%%premiere desserte par les PBRs
            for q=1:N
              trame(n+1).file(q).L(t_deb)=c_min(q);
              trame(n+1).file(q).W(t_deb)=0;
       %       trame(n+1).file(q).A(t)=5; %il faut specifier un processus d arrivee
              trame(n+1).file(q).out(t_deb)=0;
            end
            sommeOUTini=0;
            for r=1:N
              trame(n+1).file(r).L(t)=min(max(0,c_max(r)-trame(n+1).file(r).out(t-1)), trame(n).file(r).W(t) +trame(n+1).file(r).A(t));  
              trame(n+1).file(r).out(t)=min(max(0, somme-trame(n+1).taille)+sommeOUTini, trame(n+1).file(r).L(t)); 
              sommeOUTini=sommeOUTini+trame(n).file(r).out(t_deb);  
              trame(n+1).file(r).W(t)=max(0, min(buffer(r), trame(n).file(r).W(t)+trame(n+1).file(r).A(t))- trame(n+1).file(r).out(t)); 
              trame(n+1).taille=trame(n+1).taille+ trame(n+1).file(r).out(t_deb);
            end
            n=n+1;
          end
    
        end
    end 
%trame(n).taille

t=t+1;
end
