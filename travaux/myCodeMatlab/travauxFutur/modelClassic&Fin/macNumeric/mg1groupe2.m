
function Pi=mg1groupe(lambda,mu,t_max,buffer,N,r)

% lambda: le taux d'arrivé des clients
% mu    : introduire le taux de service
while lambda>=r*mu
    disp('la condition de stabilité "lambda<r*mu " n''est pas vérifiée')
    lambda=input('Veuillez réintroduire le taux d''entrée lambda=')
    mu=input('introduire le taux de service mu=')
end

% t_max: la durée de la simulation 
% N    : le niveau fixe de la file d'attente
% r    : la taille du groupe 
while N<r
    disp(' la valeur de r ne peut être supérieur à celle de N')
    N=input('veuillez rectifier la valeur de N=')
    r=input('veuillez aussi faire entrer la valeur de r=')
 end
%  buffer       : la capacité de la file
%  tsim      : horloge de la simulation 
%  t1        : date de la prochaine arrivée
%  t2        : date du prochain départ
%  n         : nombre de clients dans le système à un instant donné
%  ni(.)     : durée cummulée pendant laquelle le système contient "n" clients
%  bloquer   : Représente l'état du serveur : -true:  si le serveur est bloquer
%                                             -false: si le serveur est débloquer
%  secondaire: Représente le type de service effectuer: -true:  si on est dans le service secondaire
%                                                       -false: si on est dans le service primaire
%  Pi         : Vecteur des probabilités stationnaires
%  seuil      : Le seuil de contrôle
          % étape 1: initialisation des paramètres
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
            %genérer un service
            t2=t3+exp(mu*r);
        end
    end
    t3=t3+tsim;
end

t3
Pi=ni/t3;
Pi=[(1-sum(Pi)) Pi];
end
