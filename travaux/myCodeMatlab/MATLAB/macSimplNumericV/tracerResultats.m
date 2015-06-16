%16/07/2013
 grid on
 hold on
%tracer les courbes
 filename1='taillesTrames.dat';
 filename2='indicesPerf.dat';
 
 %tracer les tailles des trames 
     fileT=load(filename1);
    % y1=load(filename1,1,'A1:A10');
     xlabel('Trame ID');
     ylabel('Trame Size');
     figure(1);
     plot(fileT(:,1),fileT(:,2),'-+','color','red','LineWidth',2.0);
     %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
     dataFile=load(filename2);
     [n,k]=size(dataFile);
     [jj,ll]=sort(dataFile(:,1));
     dataFile=dataFile(ll,:);
     deb=0;
     figure(2);
     t=[];
     color=['r', 'g', 'b', 'm']; 
 
   for ii=1:N %nombre de file
        v=find(dataFile(:,1)==ii); % B= sortrows(A)  
    if length(v)>0
        G{ii}=dataFile(deb+1:n, 2:k);
        deb=v(length(v));
        %legend('Queue',1);   %1 en haut à droite
        %xlabel('TRame ID');
        %ylabel('Wait Queue');
       % figure(ii+1);
        plot(G{ii}(:,1),G{ii}(:,4), color(ii)); %,'*','color','blue','LineWidth',2.0);
        %plot(G{ii}(:,1),G{ii}(:,4),'r','LineWidth',1.5,'Marker','*');
        Spec_concat = strcat('Queue' ,num2str(ii)); 
        t=[t; Spec_concat];
        hold on
    end
   end
   %  axis([0 0]);
   
     legend(t(1:N,:));
      %
     % rep='';
%       a='Q1';
%       b='Q2';
%       rep=[''' a ''' ',' ''' b '''];
%       
      % constructChaine(1, N);
     
     
      %legend('Q1', 'Q2' ,1);
      xlabel('Trame ID');
      ylabel('Wait Queue');
%     xlabel('Queue ID');
%     ylabel('Wait');
%     figure(2);
%     plot(dataFile(:,2),dataFile(:,5),'*','color','blue','LineWidth',2.0);
    
   
hold off