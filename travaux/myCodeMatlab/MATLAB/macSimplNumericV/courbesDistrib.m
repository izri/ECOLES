%by Nora IZRI; fichier pour pouvoir tracer les différentes courbes de
%résultats 
%04/10/2013
clf

grid on
hold on

N=2; %nbre de files 
%tracer la fct de répartion des proba cumulés
tLeg=[];
    figure(1);
colorss=['b', 'm','r', 'g']; 
for pp=1:N
    nameFile= strcat('distribFile-', num2str(pp), '.dat'); %pr les attentes et transmis
    fiDistrib=load(nameFile); 

    plot(fiDistrib(:,1),fiDistrib(:,3),colorss(pp)); %, '*','LineWidth',2.0);  
    Spec = strcat('File' ,num2str(pp)); 
    tLeg=[tLeg; Spec]; 
    hold on
end
    legend(tLeg(1:N,:));
    xlabel('Buffer size');
    ylabel('Probability');

  hold off