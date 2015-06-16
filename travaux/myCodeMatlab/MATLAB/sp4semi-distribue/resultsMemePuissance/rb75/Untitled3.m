clear all;
tauxErr=1.96; 

V=7;
S=7;
for j=1:V
        matrice{j}.val=[];
end
H=100;
compl=zeros(1,H);

for i=1:S
    direct=(num2str(i));
    cd(direct)
    VAL{i}=[];
    for uuj=1:V
     nameFile= strcat('IterCellule-', num2str(uuj), '.dat'); %pr les attentes et transmis
     [n, k]=size(nameFile);
     VAL{i}=load(nameFile);
     VALEUR=VAL{i}(:,4:4);
     matrice{uuj}.val=[matrice{uuj}.val, VALEUR];
  %   disp( matrice{uu}.val);
    end
    cd ..
end
SS=30;
%disp( matrice{1}.val);
for uu=1:V
     filePPP=strcat('gainMoyenTRace',num2str(uu),'.dat');
     efnin=fopen(filePPP, 'w');      
for jj=1:H
    compl(jj)=jj;
    A=mean(matrice{uu}.val(jj,:)) ;
    B=std( matrice{uu}.val(jj,:)) ;
    ajustementIntervaCOnf=(tauxErr*B)/sqrt(SS);
    fprintf(efnin, '%d \t %g \t %g \t %g \t %g \n', jj, A, B , A+ajustementIntervaCOnf, A-ajustementIntervaCOnf);
end
fclose(efnin);
end


  truc=[];
  truc=[truc, compl];