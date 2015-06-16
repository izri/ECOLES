parr=1;
capacity=C;

% 
% for d=1:N
%     minTotal = minTotal+ c_min(d);
% end

sommeMin=0;
if (cycle==1)
while ( (parr<=N) && (sizeT < capacity))
    trame(n).file(h).L = min(c_min(h), trame(n).file(parr).X + trame(n).file(parr).A);
    trame(n).file(h).out = min(max(0, capacity-trame(n).taille)+sommeOUT, trame(n).file(parr).L); %transmis
    sommeMin=sommeMin+trame(n).file(parr).out;      
    sommeOUT = min(sommeOUT+trame(n).file(parr).out, capacity-trame(n).taille);
     %tt ce que j ai pu extraire jusqu à présent  
    % disp( trame(n).file(h).out);
    trame(n).file(parr).X =max(0, min(buffer(parr), trame(n).file(parr).X+trame(n).file(parr).A)- trame(n).file(parr).out); %Attente
         
    if ((sizeT+trame(n).file(parr).out <=capacity) ) %  (sommeOUT <=capacity)
             sizeT= sizeT+trame(n).file(parr).out;
             bool=0;
     else
           %   sizeT=sizeT-trame(n).file(h).out;
              tailleRetirStep1(parr)=trame(n).file(parr).out;
              bool=1;
             % break;
      end 
            
          %sizeT=trame(n).taille;
      trame(n).taille=min(sizeT, capacity);
    
    sortiFile(parr)= sortiFile(parr)+trame(n).file(parr).out;
    parr=parr+1;
end
capacity=C-sommeMin;
cycle=2;
else
    
    tailleRetirStep1(h)=0;
    %normal