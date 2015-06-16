%01/08/2013 by Nora IZRI
%cela permet d'avoir des affectations alea au sein de chaque file d'attente
%pour les paramètres PBR et Bucket

clc;
clear all;
N=2;
C=10; %taille max de la trame
Cap=C;
c_min=zeros(1,N);
c_max=zeros(1,N);
j=1;
a=3; %valeur max pr le seuil min pr générer le PBR
b=5; %valeur max pr le seuil max pr générer le max

%il faut une première affectation des PBR donc des valeurs c_min puis faire
%les c_max ou bien dans le sens inverse on affecte les max puis les débit
%garantie
somme=0;
sum=0;
while ((j<=N) && (Cap>=0))
    c_max(j)=randi([1, Cap], 1, 1); %il ne faut oublier que la somme des c_max =C
    somme=somme+c_max(j);  
    c_min(j)= randi([1, c_max(j)], 1, 1);
    sum=sum+c_min(j);
    if ((Cap-c_max(j) <0) && (j > N)) 
        break;
    else
        if (Cap-c_max(j) > 0)
             Cap=Cap-c_max(j);
        else 
             break;
        end
    end
       j=j+1;
end
somme
sum  
boolRaj=0;
if (mod(somme, C) ~=0) %(somme ~= C)
    raj=C-somme;
    boolRaj=1;
    fprintf ('*******  JE SUIS ICI ******** %d \n', raj);                         
    if(mod(raj, N) ==0)
    %on réparti équitablement avec les N files
        for indd=1:N
            c_max(indd)=c_max(indd)+raj/N;
            %on peut faire la même chose pr le min
            c_min(indd)=c_min(indd)+raj/N;
        end
    else
        %on rajoute tte la masses à la première file qui est la plus
        %prioritaire
        c_max(1)=c_max(1)+raj;
        c_min(1)=c_min(1)+raj;  
    end   
end
if (boolRaj==1)
    sum1=0;
    somme1=0;
    for ttest=1:N
       somme1=somme1+c_max(ttest);  
       sum1=sum1+c_min(ttest); 
    end
    somme1
    sum1
end