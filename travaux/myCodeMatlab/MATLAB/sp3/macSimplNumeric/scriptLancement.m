clc;
clear all;

capTrame=[669]; % 710 690 650]; 
%669==> 15 RBs
nbreTrame=[2 10 100]; % 180 9 45]; %10 20 30 50];
tailleBuffer=[500 1000 1500 2000 50 100 200];
nbreSimul= 10; %30;
fileDat='arrive*.dat';
filePoisson='PoissonAr*.dat';
file='distribFi*.dat';
file1='taillesTrames.dat';
file2='indic*.dat';
file3='instantsGener.dat';
fichier='results.dat';
fichhhh='results-Ca*.dat';
testttt='NbreTrameMax*';
fichierMoye='resultsAVG.dat';
tauxErr=1.96; %intervalle de confiance de 95%
for iPuis=1:length(nbreTrame)
      clc;
      T_max=nbreTrame(iPuis);
      NEWDiii=strcat('R', num2str(T_max));
      mkdir(NEWDiii);   
      for kStab=1:length(capTrame)  
          C=capTrame(kStab);
          fichTMP=strcat('results-Cap', num2str(C),'-nbreTRame', num2str(T_max), '.dat');
           for rRB=1:length(tailleBuffer)
               %creer repertoire save
               Buffer=tailleBuffer(rRB);
               
               NEWDIR= strcat('NbreTrameMax', num2str(T_max),  '-Capacity', num2str(C), '-Buffer', num2str(Buffer));
               mkdir(NEWDIR);
               %cd(NEWDIR);
               cumulSim1=[];
               cumulSim2=[];
               taiileFrame=[];
               for nS=1:nbreSimul
                   %modifier chacune des variables   
                   %lancer la simul
           
               analyseMacNumSimplOkii
               cumulSim2=[cumulSim2, AttenteFile{2}];
               cumulSim1=[cumulSim1, AttenteFile{1}];
               taiileFrame=[taiileFrame, TailleTrame];
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
                      sss=copyfile(fichier, NEWDIR, 'f');
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
         
            Outputfiillle= strcat('resultsAVG.dat'); %pr les trames
            fiAVG = fopen(Outputfiillle, 'w');  %wt           
            moyenAttente2=mean(cumulSim2);    
            moyenAttente1=mean(cumulSim1);  
            moyenTrame=mean(taiileFrame);
                %%%%%%%%
            ecartTypTR= std(taiileFrame);
            ajustIntervTram=(tauxErr*ecartTypTR)/sqrt(moyenTrame);
                %%%%%%%%
            ecartTypAtteF1= std(cumulSim1);
            ajustIntervF1=(tauxErr*ecartTypAtteF1)/sqrt(moyenAttente1);
                %%%%%%%%
            ecartTypAtteF2= std(cumulSim2);
            ajustIntervF2=(tauxErr*ecartTypAtteF2)/sqrt(moyenAttente2);

            fprintf(fiAVG, '%g \t %g \t %g  \t %g   \t %g  \t %g\n', moyenAttente1,ajustIntervF1, moyenAttente2,ajustIntervF2, moyenTrame, ajustIntervTram  );  %indice de la trame et sa taille
            fclose(fiAVG);
            succcccc2=movefile(fichierMoye, NEWDIR, 'f');
      end
          succeeee=movefile(fichier, fichTMP, 'f');
      end
   
          succffffffff=movefile(fichhhh, NEWDiii, 'f');
          allRep=movefile(testttt, NEWDiii, 'f');
end