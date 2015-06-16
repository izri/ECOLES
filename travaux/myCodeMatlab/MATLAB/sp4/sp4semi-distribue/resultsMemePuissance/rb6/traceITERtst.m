%by Nora IZRI; fichier pour pouvoir tracer les différentes courbes de
%résultats 
%03/09
%mise à jour du fichier 11/09
grid on
hold on
V=7;
%figure(2);
% %tracer les courbes 

figure(1);
id=[];
%for pop=1:V %VerfiGainzzzzzzzzzzzzz
%    nameFile= strcat('IterCellule-', num2str(pop), '.dat'); %pr les attentes et transmis
  nameFile='Classeur2.txt';
    fiDistrib=load(nameFile); 
    [nLigne,kColonne]=size(fiDistrib);
  %  if ((nLigne>0) && (kColonne>0))

for pop=1:V
    ind=pop+1;
     plot(fiDistrib(:,1),fiDistrib(:,ind));
     hold on
    Spec_concat = strcat('Cell ID' ,num2str(pop)); 
    id=[id; Spec_concat]; 

  %  else
   %  fprintf('******        msg erreur ==> fichier vide pp %d \n', pop); 
    %end
end
legend(id(1:V,:));
xlabel('time');
ylabel('Gain fct');

%legend(t(1:V,:));
axis square
hold off