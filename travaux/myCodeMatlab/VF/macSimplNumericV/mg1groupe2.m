
function Pi=mg1groupe(lambda,mu,t_max,buffer,N,r)

% lambda: le taux d'arriv� des clients
% mu    : introduire le taux de service
while lambda>=r*mu
    disp('la condition de stabilit� "lambda<r*mu " n''est pas v�rifi�e')
    lambda=input('Veuillez r�introduire le taux d''entr�e lambda=')
    mu=input('introduire le taux de service mu=')
end

% t_max: la dur�e de la simulation 
% N    : le niveau fixe de la file d'attente
% r    : la taille du groupe 
while N<r
    disp(' la valeur de r ne peut �tre sup�rieur � celle de N')
    N=input('veuillez rectifier la valeur de N=')
    r=input('veuillez aussi faire entrer la valeur de r=')
 end
%  buffer       : la capacit� de la file
%  tsim      : horloge de la simulation 
%  t1        : date de la prochaine arriv�e
%  t2        : date du prochain d�part
%  n         : nombre de clients dans le syst�me � un instant donn�
%  ni(.)     : dur�e cummul�e pendant laquelle le syst�me contient "n" clients
%  bloquer   : Repr�sente l'�tat du serveur : -true:  si le serveur est bloquer
%                                             -false: si le serveur est d�bloquer
%  secondaire: Repr�sente le type de service effectuer: -true:  si on est dans le service secondaire
%                                                       -false: si on est dans le service primaire
%  Pi         : Vecteur des probabilit�s stationnaires
%  seuil      : Le seuil de contr�le
          % �tape 1: initialisation des param�tres
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
t1=0;
t2=t_max;
tsim=0;
t3=0;
n=0;
%bloquer=true;
%secondaire=false;
ni=zeros(1,buffer);
Pi=zeros(1,buffer);
seuil=r;
while (t3<t_max)
    if (t1<t2)
        if (n>0)
            ni(n)=ni(n)+abs(t1-tsim);
        end
        tsim=t1;
        n=n+1;
        t1=t3+exp(lambda);

    else
        if (n>0)
            ni(n)=ni(n)+abs(t2-tsim);
            n=n-r;
        end        
        tsim=t2;
        if (n<r)
          
            t2=t_max;
        else
            %gen�rer un service
            t2=t3+exp(mu*r);
        end
    end
    t3=t3+tsim;
end

t3
Pi=ni/t3;
Pi=[(1-sum(Pi)) Pi];
end
