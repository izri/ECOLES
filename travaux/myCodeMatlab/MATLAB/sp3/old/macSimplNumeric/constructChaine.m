function [  Spec_concat ] = constructChaine(deb, fin)
Spec_concat = '';
Spec = '';
t=[];
for s=deb:fin 
    Spec = '';
if (s~= fin) 
    Spec_concat = strcat('''Queue' ,num2str(s), ''',');  
    
    %Spec_concat = strcat(Spec_concat, {'Queue'} ,num2str(s), {''','});  
    %Spec_concat=strcat(Spec_concat,{'Queue'},num2str(s','%d'), ', ');
else
   % Spec_concat=strcat(Spec_concat,'', {'Queue'},num2str(s','%d'));
    %Spec_concat = strcat(Spec_concat, {'''Queue'}, num2str(s) );
    Spec_concat = strcat('''Queue', num2str(s), ''''); 
   
    %[Spec_concat '''Queue' num2str(s) ''''];
end
 t=[t,Spec_concat];
%Spec_concat=strcat(Spec_concat, Spec);
end
t
%Spec_concat = [ '[' Spec_concat ']' ];
%Spec_concat = eval(Spec_concat);
Spec_concat
end










%% On concat�ne toutes les cha�nes 'Spec_...'
%% en mettant un espace blanc entre chaque
%% Pour expliquer supposons que numfich = 5 et nbrspec = 19
%% c'est-dire qu'on concat�ne ' Spec_5' ' Spec_6' ... ' Spec_23'
% nbrspec=10;
% numfich=2;
% Spec_concat = '';
% for s = numfich : nbrspec + numfich -1
% Spec_concat = [Spec_concat ' Spec_' num2str(s)]; % mettre un blanc avant Spec_
%                                                  % sinon tout sera coll�
% end
% 
% 
% 
% Spec_concat
% %% On a alors la cha�ne ' Spec_5 Spec_6 .... Spec_23'
% %% Pour l'�valuer comme une expression vectorielle, on rajoute les [ ] dans la cha�ne
% Spec_concat = [ '[' Spec_concat ']' ];
% %% Maintenant on a la cha�ne '[ Spec_5 Spec_6 .... Spec_23]'
% %% Pour Matlab, il ne s'agit que d'une cha�ne de caract�res, donc il faut lui dire de l'�valuer
% %% Comme si on la tapait dans le workspace...
% 
% 
% 
% Spec_concat = eval(Spec_concat);
% %% Maintenant Spec_concat est une matrice