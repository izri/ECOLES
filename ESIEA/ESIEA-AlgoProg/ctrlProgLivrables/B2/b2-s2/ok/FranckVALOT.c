#include <stdlib.h>
#include <stdio.h>

typedef struct maillon{
    int info;
    struct maillon * succ;
}t_maillon;

void afficher_tout(t_maillon * liste){
    t_maillon * cour=liste;

    do{
        printf("%d\n", cour->info);
        cour=cour->succ;
    }while(cour!=liste);
}

t_maillon*  liste_parfaite(t_maillon * liste){
    t_maillon * cour=liste;
    t_maillon * tmp = NULL;
    t_maillon * parfaite=NULL;
    t_maillon * cour_parfaite=NULL;
    int i;
    int compteur;


    do{
        printf("%d ", cour->info);
        compteur=0;
        for(i=1; i<cour->info; i++){
            if((cour->info)%i==0){
                compteur+=i;
            }
        }
        if(compteur==cour->info){
            if(parfaite==NULL){
                parfaite=malloc(sizeof(t_maillon));
                parfaite->info=cour->info;
                parfaite->succ=NULL;
                cour_parfaite=parfaite;
            }
            else{
                cour_parfaite->succ = malloc(sizeof(t_maillon));
                cour_parfaite=cour_parfaite->succ;
                cour_parfaite->info=compteur;
                cour_parfaite->succ=NULL;
            }
            cour=cour->succ;
        }
    }while(cour!=liste);

    cour_parfaite->succ=parfaite;
    return parfaite;
}

int main(){
    t_maillon * liste=NULL;
    t_maillon * parfaite=NULL;
    t_maillon * cour=NULL;
    int n;
    int i;

    printf("Veuillez saisir le nombre d'element que vous voulez dans votre liste (>0): ");

    do{
        scanf("%d", &n);
        if(n<=0){
            printf("Erreur de saisie, veuillez recommencer\n");
        }
    }while(n<=0);

    for(i=1; i<=n; i++){
        if(liste!=NULL){
            cour->succ=malloc(sizeof(t_maillon));
            cour=cour->succ;
            cour->info=i;
            cour->succ=NULL;
        }
        else{
            liste = malloc(sizeof(t_maillon));
            liste->succ=NULL;
            liste->info=i;
            cour=liste;
        }
    }
    cour->succ=liste;


    afficher_tout(liste);
   // afficher_parfait(liste);
    parfaite=liste_parfaite(liste);

    afficher_tout(liste);
	return 0;
}
