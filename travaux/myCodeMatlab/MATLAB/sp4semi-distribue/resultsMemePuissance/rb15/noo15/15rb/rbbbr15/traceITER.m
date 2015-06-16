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
for pop=1:V %VerfiGainzzzzzzzzzzzzz
    nameFile= strcat('IterCellule-', num2str(pop), '.dat'); %pr les attentes et transmis
    fiDistrib=load(nameFile); 
    [nLigne,kColonne]=size(fiDistrib);
    if ((nLigne>0) && (kColonne>0))
    plot(fiDistrib(:,2),fiDistrib(:,4)); %,'-+','color','red','LineWidth',2.0);
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

%legend(t(1:V,:));
axis square
hold off