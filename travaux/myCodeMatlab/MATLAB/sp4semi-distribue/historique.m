%13/05/2013 by Nora IZRI
%PRiSM Laboratory
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %%%%  Edit History  %%%%
    %14/05/2013 modified (structure de donnees+affectation des RBs/cell)
    %modified 15/05/2013 exploration step
    %16/05/2013 modified (recuperer les RB en commun pr chaque cellule i et
    %c 6 cellules voisines ==>  RB_common
    %modified 30/05/2013 ==> calcul du SINR pr les users par rapports aux
    %users voisins uilisant la meme RB
    %modified 03/06/2013 ==> correction de la notion de temps; variante 1
    %du model==> tt les users des differentes cellules emettent a la meme puissance
    %modfied 05/06/2013 ==> ajustement du temps, rajout de la fct de
    %recompense globale au sein d une cellule sur un RB et la fct global de
    %la cellule
    
    
    %%%%%%%%%%%%%%%%%%%%         URGENT          %%%%%%%%%%%%%%%%%%%
    %modified 02/07/2013 ==> correction de kelk erreurs de compilation
    %suite à l introduction de la notion de temps ; j ai introduit une
    %variable ta=1, pr résoudre le problm mais par la suite il faudra
    %remettre la variable t (temps) à la place de ta; et faire biensur les
    %modifs qu il faut dans tt le code par rapport à la mise à jour des
    %RB utilisés etc
    %==> il faut également résoudre le problm de la fct de récompense elle
    %n est pas au bon endroit
    
    %03/07/2013
    %déplacement du block concernant le calcul de la fct récompense
    %début de la fct modifRB dans un fichier indépendent permettant de
    %sélection un autre RB que celui utilisé actuellement
    
    %04/07/2013
    
    %la conf des puissances d emission est faite lors de l etape init ==>
    %il faudra peut être prévoir de faire des modifs par rapport à c
    %puissances lors des mises à jours des RBs utilisés au fur et à mesure
    
    
    
    %05/07/2013
    %les mises à jour de : 
    %lorsque l on choisi un autre RB + verif de la convergence (avec des
    %multiples de 200 ms en relation avec les msg RNTP
    
    
     %10/07/2013: 
          %intégration du calcul du débit pr chaque RB ayant déjà eu un
          %calcul du SINR 
        %sauvegarde dans deux fichiers le SINR et le débit de chaque RB en
        %conflit
        %placer juste une variable cste =2 pr l utiliser lors de l'arrivée
        %d'un msg CQI avec des intervalles de 2 ms
        
        
     
    %11/07/2013
    %voir pr le noise est ce que l on utilise la puissance max ou bien celle tiré aléatoirement
         
    
   %15/07/2013
   %rajout de la notion de charge,
   %il reste kelk fois ou le SINR est > 1 ???
   
   
   %26/07/2013
   %pr que la difference soit >0 pr rentrer dans l algo d allocation, il ne
   %fallait pas mettre le gain et le gaintotal à 0
  
   
   %il faut voir est ce que lorsque l'on change de RB dans une cellule les
   %equations de la fct de récompenses ainsi que celle du calcul de la diff
   %sont liés avec l'ancien rb jusque l'on n a pas de valeurs pr ces fcts à
   %t-1
  
  %voir si c utile de refaire le calcul des RB_common et de la  sommeDistUsersNew     
                    %513==>527
                    
    %29/07/2013
    %t_RNTP  ==> j ai mis sa valeur a 10 au lieu de 200 juste pr tester par
    %rapport à la convergence de l algo en mettant la duree de simul à 50
    
    
    %06/08/2013
    %calcul de la fct gain globale de chaque cellule 
    %on détermine la stabilité si pour chaque cellule, la fct de gain
    %globale n'a pas changé entre une itération et une autre
    
    %07/08/2013
    %il faut utiliser ca pr la partie coordonnées des RB et users pr éviter
    %de tomber sur les coordonnées des eNBs
    
    %1-  Si tu as envi d'enlever toutes les occurrence tu fais
    %setdiff(A,elt,'stable');

    %2- Si tu as envi d'enlever d'une seule occurrence, à savoir la première qui apparaît dans le tableau  tu fais
    %a) q=find(A==elt);
    %b) A=[A(1:q(1)-1), A(q(1)+1:length(A))].

    %==> rajout de la variable "varianteStab" pr définir plusieurs méthodes
    %concernant les conditions de stabilité/convergence de l algo

    
    %20/08
    %==>calcul du debit moyen ET du nbre d'inteférences moyenne par cellule
    %==> pour pouvoir tracer en fct du nbre de RB dans chaque cellule c
    %deux indices de perf
    
    %récupérer la fct de récompense globale par cellule pr tracer une
    %courbe en fct des itérations avec des pas correspondant à l'arrivée
    %d'un msg CQI
    
    
    %27/08
    %cellule{q,ta}.nbrRBmodif rajout de cette variable pr permettre de tracer
    %pr chaque cellule q le nbre de modif de RB qui a du se faire durant la simul
    %
    
    
    %30/08
    %il faut revoir comment rajouter dans le while le test de la variable
    %"continuer" ligne 479
    
    
    %03/09
   % rajout d écriture dans les fichiers nécessaire pr tracer les courbes
   % des indices de perf
   
   %04/09
   %Nstabilisation: pr verifier la stabilité 
   %revoir les fct de récompense lorsque l on change de RB
   
   %j'ai mis en commentaire tous les plots pr aller plus vite
   
   
   
     
      %05/09 EcartType=std(AdaptTime);
         %   ConfiInterval=2*EcartType/sqrt(nerrorbar(X1,Y1,Err1,'-o','color','black','LineWidth',2.0);
%au lieu de plot c'est donc errorbar


%tt les plot ont été mis en commentaire ainsi que la commande "clf"
%06/09
%mise en place de la boucle while (1) et rajout de test pr la convergence
%de l algo

%10/09
%quelques corrections d'indice pr les affichages 
%rajout du fichier de sortie "timeSTABLE" pr sauvegarder les times pr vérifier à quel
%moment on a la première stabilité  et surppression des affaichages sur le
%terminal

%gainTotalCell  ==> fct de recompense globale d'une cellule à un instant
%(t) en sommant toutes les fcts de gain de chaque RB de la cellule
%gainTotal ==> fct de recompense globale pour chaque RB

%12/09
%j ai mis en commentaire le calcul de "diffGainTotal" qui se fait après la
%modification des rB car cela génére des erreurs à l exécution alors que
%l'on n a pas besoin de cette variable à ce moment là
