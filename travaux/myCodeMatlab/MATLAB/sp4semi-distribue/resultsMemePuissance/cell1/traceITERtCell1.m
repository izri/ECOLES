%by Nora IZRI; fichier pour pouvoir tracer les différentes courbes de
%résultats 
%03/09
clear all;
clc;
%mise à jour du fichier 11/09
grid on
hold on
Vc=6;
%figure(2);
% %tracer les courbes 
nbRB=[6 15 25 50 75 100];
figure(1);
etiquette=[];
nameE=' RB';
blanc=' ';
for pop=1:Vc %VerfiGainzzzzzzzzzzzzz
    nameFile= strcat('gainMoyenTRace1-', num2str(pop), '.dat'); %pr les attentes et transmis
    fiDistrib=load(nameFile); 
    [nLigne,kColonne]=size(fiDistrib);
    if ((nLigne>0) && (kColonne>0))
     rb = nbRB(pop);
     convertir=num2str(rb);
    if pop==1
     nameE='   RB';
     concat = strcat( convertir, blanc, blanc, nameE);   
     
    else
        if pop==Vc
            nameE=' RB';
        concat = strcat(convertir, nameE);
        else
                 nameE='  RB';
             concat = strcat(convertir, nameE); 
        end
    end
     etiquette=[etiquette; concat]
     plot(fiDistrib(:,1),fiDistrib(:,2));     
     hold on
    else
     fprintf('******        msg erreur ==> fichier vide pp %d \n', pop); 
    end
end
legend(etiquette(1:Vc,:));
xlabel('time');
ylabel('Gain fct');

%legend(t(1:V,:));
axis square
hold off