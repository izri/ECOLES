nbreMaxRB=0;
tabCumDebi=zeros(1, M);
cellMAx=0;
for xy=1:V
    %récupérer le nbre de RB max utilisé par le réseau
  if(cell{xxC,ta}.nbrUser >= nbreMaxRB )  
      nbreMaxRB = cell{xxC,ta}.nbrUser;
      cellMAx=xy;
  end
end

for parc=1:cell{cellMAx,ta}.nbrUser
    indRB=cell{cellMAx,ta}.rbUserPris(parc);
    %rechercher ce rb dans les autres cellules
  for vvcell=1:V
    if(vvcell~=cellMAx) 
       indCellRB=intersect(cell{vvcell,1}.rbUserPris, indRB); 
       if length(indCellRB)~=0
        % indCellRB =  find(cell{vvcell,ta}.rbUserPris == indRB) ;
        tabCumDebi(indRB)= tabCumDebi(indRB) + cell{vvcell,t}.RB(indRB).Throughput;
       else
           %il n existe pas pr cette cellule vvcell
        fprintf ('########  il n existe pas pr cette cellule vvcell ----  %d  ******** \n', vvcell);  
       end
    end
  end
    
   if (tabCumDebi(indRB) > 0)
         okt(indRB)=1; 
   end
end


for xyo=1:V
   for idr=1:cell{xyo,ta}.nbrUser
       recupRB=cell{xyo,ta}.rbUserPris(idr);
       if (okt(recupRB) == 0)
       tabCumDebi(indRB) 
      % else
           %rien à faire
       end
   end
end
