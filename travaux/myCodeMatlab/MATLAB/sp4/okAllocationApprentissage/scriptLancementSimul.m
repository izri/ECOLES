clc;
clear all;

AvarianteStab=[1 3 4]; %la 2 est assez compliqué
BvarianteRB=[1 3];
CvariantePuis=[1 2];
rbListe=[6 15 25 50 75 100];
nbreSimul= 30;
allFileDat='*.dat';
allFileTxt='*.txt';
Nstabilisation= 100;
%rayon
%charge

for iPuis=1:length(CvariantePuis)
    clc;
    varianteALGO=CvariantePuis(iPuis);
    for jRB=1:length(BvarianteRB)
        varianteChooseRB=BvarianteRB(jRB);
      for kStab=1:length(AvarianteStab)  
          varianteStab=AvarianteStab(kStab);
           for rRB=1:length(rbListe)
               %creer repertoire save
               N=rbListe(rRB);
               NEWDIR= strcat('Puis', num2str(varianteALGO), '-ChooseRB', num2str(varianteChooseRB), '-Stab', num2str(varianteStab),'-RB', num2str(N));
               mkdir(NEWDIR);
               %cd(NEWDIR);
               for nS=1:nbreSimul
                   %modifier chacune des variables 
            
                   %lancer la simul
                  % ProgInterferenceVariante3
               
                   ProgInterferenceLTE
%               %creer repertoire save portant le n° de la simul
                NEWD=strcat('Simul', num2str(nS));
                mkdir(NEWD);
              
                succ=movefile(allFileDat, NEWD, 'f');
                suuu=movefile(allFileTxt, NEWD, 'f');
                
                
                if ((succ==1) && (suuu==1))
                 

                      succ2=movefile(NEWD, NEWDIR, 'f');
%                   %  suuu2=movefile(allFileTxt, NEWD, 'f');
%                     
                    if (succ2==0)  
                        fprintf('ERREUUUUUUUUR de copie avec succ2 \n');
                        break; 
                    end     
                else
                    fprintf('ERREUUUUUUUUR de copie avec succ  ou suuu \n');
                    break;
                end
                
                
                
                %copier tous les fichiers dans le répertoire qu'il faut 
%                  cd(NEWDIR);
%                  cd(NEWD);
%                  cd ..
%                  cd ..
               end
        end
      end
    end
end