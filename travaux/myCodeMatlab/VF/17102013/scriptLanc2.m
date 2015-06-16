clc;
clear all;
% 
% AvarianteStab=[1]; % 3 4]; %la 2 est assez compliqué
% BvarianteRB=[1];
% CvariantePuis=[2];
rbListe=[6 15 25 50 75 100];
nbreSimul= 30; %30
allFileDat='*.dat';%SINR_Throug  SINR_ThrougAAA-
allFileDa2t='fileSINR_Throughput*.txt';
allFileTxt='*.txt';
fInter='Iter-*.dat';
fVerfiGain='VerfiGain*.dat';
fGain='Gain&Proba-*.dat';
fconfig='ConfigCellue-*.dat';
% fctRecompGain
% debitMoyInterfMoy
% 
% nbreMODIF
% nbrUserCell
% resumeConv
% timeSTABLE
% VerfiGain*.txt
fiiii='resumeConv.txt';
fileOK='IterCellule-*.dat';
%Nstabilisation= 50; %100
%rayon
%charge
tauxErr=1.96; 
valeur=1000;
Vv=7;
AAA=0;
      for rRB=1:length(rbListe)
               %creer repertoire save
               N=rbListe(rRB);
               NEWDIR= strcat('Choix3-RB', num2str(N));
               mkdir(NEWDIR);
             
               for nS=1:nbreSimul
                rand('seed',sum(100*clock)); %initialisation du générateur aléatoire
              
              %  rand('state',sum(100*clock));
                ProgInterferenceLTEq
               
                Outputfiilleeele= strcat('resultsSimul',num2str(nS), '.mat');
                save(Outputfiilleeele, 'gainGlobal');   
%               %creer repertoire save portant le n° de la simul
                NEWD=strcat('Simul', num2str(nS));
                mkdir(NEWD);
                MMDIR=strcat(num2str(nS+AAA));
                mkdir(MMDIR);
                recept=copyfile(fileOK, MMDIR , 'f');
                rept=copyfile(fiiii, MMDIR , 'f');
                suuu=movefile(allFileTxt, NEWD, 'f');
                suuuuC=movefile(Outputfiilleeele, NEWD, 'f');
                succ=movefile(allFileDat, NEWD, 'f');
                
%                succ2=movefile(allFileDa2t, NEWD, 'f');
%                succ4=movefile(fInter, NEWD, 'f');       
%                succ5=movefile(fVerfiGain, NEWD, 'f'); 
%                succ6=movefile(fGain, NEWD, 'f'); 
%                succ7=movefile(fconfig, NEWD, 'f'); 
%                suc8=movefile(fileOK, NEWD, 'f'); 
%  
%  
%  
%                 
%                 
                
                
                
                
                
                
                
                
                if ((succ==1) && (suuu==1) && (suuuuC==1) && (recept==1) )
                 succ2=movefile(NEWD, NEWDIR, 'f');
                 succ3=movefile(MMDIR, NEWDIR, 'f');    
                 if ((succ2==0)  && (succ3==0) )
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
                               if (suuuuC==0)
                                  fprintf('ERREUUUUUUUUR de copie avec suuuuC \n');
                                  break;
                    
                           
                          else
                                 if (recept==0)
                                  fprintf('ERREUUUUUUUUR de copie avec recept \n');
                                  break;
                    
                                 end
                               end
                         end
                    end
                end
  
               end

           end
