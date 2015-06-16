clc;
clear all;

capTrame=[669]; % 710 690 650]; 
%669==> 15 RBs
nbreTrame=[2 10 100]; % 180 9 45]; %10 20 30 50];
tailleBuffer=[500 1000 1500 2000 50 100 200];
nbreSimul= 1; %30;
fileDat='arrive*.dat';
filePoisson='PoissonAr*.dat';
file='distribFi*.dat';
file1='taillesTrames.dat';
file2='indic*.dat';
file3='instantsGener.dat';
fichier='results.dat';
fichhhh='results-Ca*.dat';
testttt='NbreTrameMax*';

for iPuis=1:length(nbreTrame)
      clc;
      T_max=nbreTrame(iPuis);
      NEWDiii=strcat('R', num2str(T_max));
      mkdir(NEWDiii);   
      for kStab=1:length(capTrame)  
          C=capTrame(kStab);
          fichTMP=strcat('results-Cap', num2str(C), '.dat');
           for rRB=1:length(tailleBuffer)
               %creer repertoire save
               Buffer=tailleBuffer(rRB);
               
               NEWDIR= strcat('NbreTrameMax', num2str(T_max),  '-Capacity', num2str(C), '-Buffer', num2str(Buffer));
               mkdir(NEWDIR);
               %cd(NEWDIR);
               for nS=1:nbreSimul
                   %modifier chacune des variables   
                   %lancer la simul
    
               
               analyseMacNumSimplOkii
            
            
            
%               %creer repertoire save portant le n° de la simul
                NEWD=strcat('Simul', num2str(nS));
                mkdir(NEWD); 
                succ=movefile(fileDat, NEWD, 'f');
                suuu=movefile(filePoisson, NEWD, 'f');
                suuu2=movefile(file, NEWD, 'f');
                suuu1=movefile(file1, NEWD, 'f');
                suuu4=movefile(file2, NEWD, 'f');
                suuu3=movefile(file3, NEWD, 'f');
                
                
                if ((succ==1) && (suuu==1) && (suuu1==1) && (suuu2==1) && (suuu3==1) && (suuu4==1) )
                 

                      succ2=movefile(NEWD, NEWDIR, 'f');
%                   %  suuu2=movefile(allFileTxt, NEWD, 'f');
        
                    if (succ2==0)  
                        fprintf('ERREUUUUUUUUR de copie avec succ2 \n');
                        break; 
                    end     
                else
                    if (succ==0)
                    fprintf('ERREUUUUUUUUR de copie avec succ \n');  
                       break;
                    else
                            if (suuu==0)
                               fprintf('ERREUUUUUUUUR de copie avec suuu \n');        
                             break;
                            else
                               if (suuu1==0)
                               fprintf('ERREUUUUUUUUR de copie avec suuu1 \n');        
                                break;
                               else
                                if (suuu2==0)
                               fprintf('ERREUUUUUUUUR de copie avec suuu2 \n');        
                             break;
                                else
                             if (suuu3==0)
                               fprintf('ERREUUUUUUUUR de copie avec suuu3 \n');        
                              break;
                             else
                                if (suuu4==0)
                               fprintf('ERREUUUUUUUUR de copie avec suuu4 \n');        
                              break;
                                
                            end
                            end   
                            end
                                end 
                            end
                 
                    end
                end
                
                
                
                %copier tous les fichiers dans le répertoire qu'il faut 
%                  cd(NEWDIR);
%                  cd(NEWD);
%                  cd ..
%                  cd ..
               end
           end

        succeeee=movefile(fichier, fichTMP, 'f');
      end
   
      succffffffff=movefile(fichhhh, NEWDiii, 'f');

      allRep=movefile(testttt, NEWDiii, 'f');
end