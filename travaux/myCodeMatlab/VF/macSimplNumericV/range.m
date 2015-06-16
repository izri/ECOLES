filename2='indicesPerf.dat';
M=load(filename2);

[n,k]=size(M);
[jj,ll]=sort(M(:,1));
M=M(ll,:);
deb=0;
for i=1:N %nombre de file
  v=find(M(:,1)==i);
  G{i}=M(deb+1:n,2:k);
  deb=v(length(v));
  
end