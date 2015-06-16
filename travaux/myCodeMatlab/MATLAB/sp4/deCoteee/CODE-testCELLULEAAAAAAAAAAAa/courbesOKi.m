%by Nora IZRI; fichier pour pouvoir tracer les différentes courbes de
%résultats 
%03/09
%mise à jour du fichier 11/09
grid on
hold on
V=7;
%figure(2);
% %tracer les courbes 
filename1='VerfiGain.txt'; %pr la fct de gain
dataFile=load(filename1);
[nLine,kCol]=size(dataFile);
figure(1);
id=[];
for pop=1:V
    nameFile= strcat('VerfiGainProbaInstant-', num2str(pop), '.dat'); %pr les attentes et transmis
    fiDistrib=load(nameFile); 
    [nLigne,kColonne]=size(fiDistrib);
    if ((nLigne>0) && (kColonne>0))
    plot(fiDistrib(:,2),fiDistrib(:,3)); %,'-+','color','red','LineWidth',2.0);
    %
    Spec_concat = strcat('Cell ID' ,num2str(pop)); 
    id=[id; Spec_concat]; 
    hold on
    else
     fprintf('******        msg erreur ==> fichier vide pp %d \n', pop); 
    end
end
legend(id(1:V,:));
xlabel('time');
ylabel('Gain fct');




toto=[];
%fct gain
figure(2);
for ppp=1:V
    nameFilee= strcat('VerfiGainProbaInstant-', num2str(ppp), '.dat'); %pr les attentes et transmis
    fiDiistrib=load(nameFilee); 
   % fprintf(fiTest, '%d \t %d \t %f \t %f \t  \n', q, t, Mat(t).gainCell(q), cell{q,ta}.probCollision );  
    [nnLigne,kkColonne]=size(fiDiistrib);
    if ((nnLigne>0) && (kkColonne>0))
    plot(fiDiistrib(:,2),fiDiistrib(:,6)); %,'-+','color','red','LineWidth',2.0);
    %
    Spec_concataA = strcat('Cell ID' ,num2str(ppp)); 
    toto=[toto; Spec_concataA]; 
   hold on
    else
     fprintf('msg erreur ==> fichier vide pp %d \n', ppp); 
    end
end
legend(toto(1:V,:));
xlabel('time');
ylabel('Learning Cell');



tooto=[];
%fct gain
figure(3);
for pppp=1:V
    nameFiile= strcat('VerfiGainProbaInstant-', num2str(pppp), '.dat'); %pr les attentes et transmis
    fiiDistrib=load(nameFiile); 
   % fprintf(fiTest, '%d \t %d \t %f \t %f \t  \n', q, t, Mat(t).gainCell(q), cell{q,ta}.probCollision );  
    [nnnLigne,kkkColonne]=size(fiiDistrib);
    if ((nnnLigne>0) && (kkkColonne>0))
    plot(fiiDistrib(:,2),fiiDistrib(:,7)); %,'-+','color','red','LineWidth',2.0);
    %
    Spec_concataaA = strcat('Cell ID' ,num2str(pppp)); 
    tooto=[tooto; Spec_concataaA]; 
   hold on
    else
     fprintf('msg erreur ==> fichier vide pp %d \n', pppp); 
    end
end
legend(tooto(1:V,:));
xlabel('time');
ylabel('SINR Cell');



















t=[];
%fct gain
% % figure(4);
% % for pp=1:V
% %     nameFile= strcat('Gain&Proba-', num2str(pp), '.dat'); %pr les attentes et transmis
% %     fiDistrib=load(nameFile); 
% %    % fprintf(fiTest, '%d \t %d \t %f \t %f \t  \n', q, t, Mat(t).gainCell(q), cell{q,ta}.probCollision );  
% %     [nLigne,kColonne]=size(fiDistrib);
% %     if ((nLigne>0) && (kColonne>0))
% %     plot(fiDistrib(:,2),fiDistrib(:,3)); %,'-+','color','red','LineWidth',2.0);
% %     %
% %     Spec_concatA = strcat('Cell ID' ,num2str(pp)); 
% %     t=[t; Spec_concatA]; 
% %    hold on
% %     else
% %      fprintf('msg erreur ==> fichier vide pp %d \n', pp); 
% %     end
% % end
% % legend(t(1:V,:));
% % xlabel('time');
% % ylabel('Gain Cell');
% figure(4);
% %proba de collision
% for pp=1:V
%     nameFileA= strcat('Gain&Proba-', num2str(pp), '.dat'); %pr les attentes et transmis
%     fiDistribA=load(nameFileA); 
%     [nLigneA,kColonneA]=size(fiDistribA);
%     if ((nLigneA>0) && (kColonneA>0))
%      plot(fiDistribA(:,1),fiDistribA(:,4),'red'); %,'-+','color','red','LineWidth',2.0);
%      xlabel('Cell ID');
%      ylabel('Proba Collision');
%     else
%     fprintf('msg erreur %d ==> fichier vide \n', pp); 
%     end
% end
%legend(t(1:V,:));
axis square
hold off