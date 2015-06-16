ni=zeros(N,Buffer+1);
Pi=zeros(1,Buffer+1);
 nb=zeros(1,N);
 
 
 while ((n<=T_max) && (t1<=T_max))

        while ( (h<=N) && (sizeT < capacity) ) %on vérifie aussi par rapport à la taille de la trame
        count=0;
        hg=stock(h);

       while ((hg<col) && (count <TTI))
           count=count+tempsAr(h,hg);
           nb(h)=nb(h)+ArrivInst(h,hg);

           if (count < TTI)
            if (nb(h)>0) 
                ni(h,nb(h))=ni(h,nb(h))+abs(count-tsim(h));
            end
            tsim(h)=count;
           end
             hg=hg+1;
       end
         
          trame(n).file(h).out = min(max(0, capacity-trame(n).taille)+sommeOUT, trame(n).file(h).L); %transmis
           if (count >= TTI)
              if (nb(h)>0) 
               ni(h,nb(h))=ni(h,nb(h))+abs(TTI-tsim(h));
               nb(h)=nb(h)- trame(n).file(h).out; %service
              end
              tsim(h)=TTI;
              stock(h)=hg-1; %pr garder une trame de l indice ou l on c arrêté
         end 
        end
 n=n+1;
 t1=t1+1;

end
fclose(fiTrame);
fclose(fi);
% 
% 23/07/2013
for rr=1:N
 Pi=ni(rr,:)/t3(rr);
 PI{rr}=[(1-sum(Pi)) Pi];
 PI{rr}
 Pi=[];
end


 