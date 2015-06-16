%by Nora IZRI; fichier pour pouvoir tracer les différentes courbes de
%résultats 


%28/08
%voir pk est ce que j'ai un problm lors de l exécution avec le load du filename2='debitMoyInterfMoy.txt'
%fichier 
grid on
hold on
%figure(2);
% %tracer les courbes 
filename1='VerfiGain.txt'; %pr la fct de gain
dataFile=load(filename1);
[nLine,kCol]=size(dataFile);
if ((nLine>0) && (kCol>0))   
    figure(1);
    plot(dataFile(:,1),dataFile(:,3),'red'); %,'-+','color','red','LineWidth',2.0);
    xlabel('Cell ID');
    ylabel('Gain Cell');
    figure(2);
    plot(dataFile(:,1),dataFile(:,4),'blue' );%,'-+','color','blue','LineWidth',2.0);
    xlabel('Cell ID');   
    ylabel('Proba Collision');

else
    fprintf('msg erreur   ****  VerfiGain    ****   ==> fichier vide \n'); 
end


t=[];
%fct gain
figure(3);
for pp=1:V
    nameFile= strcat('Gain&Proba-', num2str(pp), '.dat'); %pr les attentes et transmis
    fiDistrib=load(nameFile); 
   % fprintf(fiTest, '%d \t %d \t %f \t %f \t  \n', q, t, Mat(t).gainCell(q), cell{q,ta}.probCollision );  
    [nLigne,kColonne]=size(fiDistrib);
    if ((nLigne>0) && (kColonne>0))
    plot(fiDistrib(:,1),fiDistrib(:,3),'red'); %,'-+','color','red','LineWidth',2.0);
    %
    Spec_concat = strcat('Cell ID' ,num2str(pp)); 
    t=[t; Spec_concat]; 
    xlabel('time');
    ylabel('Gain Cell');
    else
     fprintf('msg erreur ==> fichier vide pp %d \n', pp); 
    end
end
figure(4);
%proba de collision
for pp=1:V
    nameFileA= strcat('Gain&Proba-', num2str(pp), '.dat'); %pr les attentes et transmis
    fiDistribA=load(nameFileA); 
    [nLigneA,kColonneA]=size(fiDistribA);
    if ((nLigneA>0) && (kColonneA>0))
     plot(fiDistribA(:,1),fiDistribA(:,4),'red'); %,'-+','color','red','LineWidth',2.0);
     xlabel('Cell ID');
     ylabel('Proba Collision');
    else
    fprintf('msg erreur %d ==> fichier vide \n', pp); 
    end
end

filename2='debitMoyInterfMoy.txt'; %pr le débit moyen et le nbre d interf moyenne
%28/08 ==> problm de load
%fillll=load(filename2); %ca ne marche pas quand il n y a pas le même nbre
%de ligne que de colonne je crois 
%tt ce qui suit a été mis en commentaire le 28/08 car il y a un bug lors du
%load, il faut résoudre ca rapidement
% [nLA,kCA]=size(fillll);
% if ((nLA>0) && (kCA>0))
%     figure(5); %27/08 tracer la courbe du nbre de changement de RB nécessaire pr chaque cellule
%     plot(fillll(:,1),fillll(:,7),'blue' ); %,'-+','color','blue','LineWidth',2.0);
%     xlabel('Cell ID');   
%     ylabel('Proba Collision');
% else
%     fprintf('**********  msg erreur ==> fichier vide ******* \n'); 
% end
axis square
hold off