clc;
clear all;

AvarianteStab=[1]; % 3 4]; %la 2 est assez compliqué
BvarianteRB=[1];
CvariantePuis=[1]; % 2];
rbListe=[6]; % 15 25 50 75 100];
nbreSimul= 2; %30
allFileDat='*.dat';
allFileTxt='*.txt';
Nstabilisation= 50; %100
%rayon
%charge
tauxErr=1.96; 
valeur=1000;
%matrice=zeros(V, valeur);   
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
               nbITER=[];
               matrice=[];
               for nS=1:nbreSimul
                   %modifier chacune des variables 
            
                   %lancer la simul
                  % ProgInterferenceVariante3
               
                   ProgInterferenceLTE
                   nbITER=[nbITER,COUNT];
                %il faut juste vérifier avant que la dimension de matrice
                %et celle de gainGlobal est pareil
                [nnnnn, lllll]= size(gainGlobal);
                [n1, l1]=size(matrice);
                if(l1~= lllll)
                    %faut d'abord compléter avant de faire la fusion
                    if lllll >l1
                       rrrr=lllll-l1;
                       compl=zeros(V,rrrr);
                       newGGGG=[matrice, compl];
                       matrice=[newGGGG;  gainGlobal];
                    else
                       rrrr=l1-lllll; 
                       compl=zeros(V,rrrr);
                       newGGGG=[gainGlobal, compl];
                       matrice=[matrice;  newGGGG];
                    end

                else
                matrice=[matrice;  gainGlobal];
               % matrice=matrice+gainGlobal;
                end 
                Outputfiilleeele= strcat('resultsSimul',num2str(nS), '.mat');
                save(Outputfiilleeele, 'gainGlobal');   
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
          
          
              gainMMM=mean(matrice);
              ecarttt=std(matrice);
              ajustementIntervaCOnf=(tauxErr*ecarttt)/sqrt(nbreSimul);
              truc=[];
              truc=[truc; gainMMM]; %moyenne pr chaque cellule
              truc=[truc; ajustementIntervaCOnf]; %pr ajuster l'intervalle de confiance
              filePPP='gainMoyenTRace.mat';
              save(filePPP,'truc');
              sucffc2=movefile(filePPP, NEWDIR, 'f');  
              
              
%            valeur=max(nbITER);
%            matrice=zeros(V, valeur);     
%            for iii=1:nbreSimul
%             Outputfiilleeele= strcat('resultsSimul',num2str(iii), '.mat');
%             mattt=load(Outputfiilleeele);
%             
%            end
               
           end
      end
    end
end