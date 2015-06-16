#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
 * Variables
 */

int cpt_1,cpt_2,cpt_3,n = 0,p,num_etat = 0,flag1 = 0,flag2 = 0;
char tableau_lecture[20][10],sybmole[20],regle[20][10],lettre_lue,temp_gauche[20],temp_droite[20][10],*ptr,temp[5],table_de_transition[20][20];

/*
 * structure utilisée pour stocker une
 * instruction d'un etat d'un automate
 */

struct etat
{
    char partie_gauche[20],partie_droite[20][10];
    int nb_regle;
}monEtat[20];

/*
 * fonction de comparaison de deux etats,
 * prend en parametre deux etats a comparer,
 * retourne 1 si les etats sont les mêmes
 */

int comparaison_etat(struct etat etat_1,struct etat etat_2)
{
    int cpt;

    if(etat_1.nb_regle != etat_2.nb_regle){
        return 0;
    }
    if(strcmp(etat_1.partie_gauche,etat_2.partie_gauche) != 0){
        return 0;
    }
    for(cpt = 0; cpt < etat_1.nb_regle; cpt++){
        if(strcmp(etat_1.partie_droite[cpt],etat_2.partie_droite[cpt]) != 0){
            return 0;
        }
    }
    return 1;
}

/*
 * fonction qui ajoute les etats manquants
 * a un etat apres avoir deplacé la tete de
 * lecture dans les regles
 */

void completion_etat()
{
    int cpt1,cpt2;
	int t,longueur = 0,flag = 0;
    char *point,tab_lecture[20][10];

    for(cpt1 = 0; cpt1 < monEtat[num_etat].nb_regle; cpt1++){
        point=strchr(monEtat[num_etat].partie_droite[longueur],'.');
        t=point-monEtat[num_etat].partie_droite[longueur];

        if(t+1 == strlen(monEtat[num_etat].partie_droite[longueur])){
            longueur++;
            continue;
        }

        lettre_lue=monEtat[num_etat].partie_droite[longueur][t+1];
        longueur++;

        for(cpt2 = 0; cpt2 < flag; cpt2++){
            if(lettre_lue == tab_lecture[cpt2][0]){
                break;
            }
        }

        if(cpt2 == flag){
            tab_lecture[flag][0 ]= lettre_lue;
            flag++;
        }

        else{
            continue;
        }

        for(cpt2 = 0; cpt2 < n; cpt2++)
        {
            if(sybmole[cpt2] == lettre_lue)
            {
                monEtat[num_etat].partie_droite[monEtat[num_etat].nb_regle][0] = '.';
                monEtat[num_etat].partie_droite[monEtat[num_etat].nb_regle][1] = NULL;
                strcat(monEtat[num_etat].partie_droite[monEtat[num_etat].nb_regle],regle[cpt2]);
                monEtat[num_etat].partie_gauche[monEtat[num_etat].nb_regle] = sybmole[cpt2];
                monEtat[num_etat].partie_gauche[monEtat[num_etat].nb_regle+1] = NULL;
                monEtat[num_etat].nb_regle++;
            }
        }
    }
}

/*
 * fonction qui créé les etats de l'automate,
 * on l'utilise apres avoir créé l'etat initial
 * elle prend en parametre un numero d'etat
 * à étudier pour créer les états qui en découlent
 */

void analyseur_slr(int etat_etudie)
{
    int t;
    char tab_lecture[20][10],flag=0,*ptr1;

    for(cpt_1 = 0; cpt_1 < monEtat[etat_etudie].nb_regle; cpt_1++){
        temp[0]='.';
        ptr1=strchr(monEtat[etat_etudie].partie_droite[cpt_1],'.');
        t=ptr1-monEtat[etat_etudie].partie_droite[cpt_1];

        if(t+1 == strlen(monEtat[etat_etudie].partie_droite[cpt_1])){
            continue;
        }

        temp[1] = monEtat[etat_etudie].partie_droite[cpt_1][t+1];
        temp[2] = NULL;

        for(cpt_2 = 0; cpt_2 < flag; cpt_2++){
            if(strcmp(temp,tab_lecture[cpt_2]) == 0){
                break;
            }
        }

        if(cpt_2 == flag){
            strcpy(tab_lecture[flag],temp);
            tab_lecture[flag][2] = NULL;
            flag++;
        }

        else{
            continue;
        }

        for(cpt_2 = 0;cpt_2 < monEtat[0].nb_regle; cpt_2++){
            ptr = strstr(monEtat[etat_etudie].partie_droite[cpt_2],temp);
            if(ptr){
                temp_gauche[flag1] = monEtat[etat_etudie].partie_gauche[cpt_2];
                temp_gauche[flag1+1] = NULL;
                strcpy(temp_droite[flag1],monEtat[etat_etudie].partie_droite[cpt_2]);
                flag1++;
            }
        }

        for(cpt_2 = 0; cpt_2 < flag1; cpt_2++){
            ptr = strchr(temp_droite[cpt_2],'.');
            p = ptr - temp_droite[cpt_2];
            temp_droite[cpt_2][p] = temp_droite[cpt_2][p+1];
            temp_droite[cpt_2][p+1] = '.';
            monEtat[num_etat].partie_gauche[monEtat[num_etat].nb_regle] = temp_gauche[cpt_2];
            monEtat[num_etat].partie_gauche[monEtat[num_etat].nb_regle+1] = NULL;
            strcpy(monEtat[num_etat].partie_droite[monEtat[num_etat].nb_regle],temp_droite[cpt_2]);
            monEtat[num_etat].nb_regle++;
        }

        completion_etat();

        for(cpt_2 = 0; cpt_2 < num_etat; cpt_2++){
            if(comparaison_etat(monEtat[num_etat],monEtat[cpt_2]) == 1){
                monEtat[num_etat].partie_gauche[0] = NULL;
                for(cpt_3 = 0;cpt_3 < monEtat[num_etat].nb_regle; cpt_3++){
                    monEtat[num_etat].partie_droite[cpt_3][0] = NULL;
                }
                monEtat[num_etat].nb_regle = 0;
                table_de_transition[etat_etudie][cpt_2] = temp[1];
                break;
            }
        }

        if(cpt_2 < num_etat){
            flag1 = 0;
            for(cpt_2 = 0;cpt_2 < 20; cpt_2++){
                temp_gauche[cpt_2] = NULL;
                temp_droite[cpt_2][0] = NULL;
            }
            continue;
        }

        table_de_transition[etat_etudie][cpt_2] = temp[1];
        printf("\n\nI%d :",num_etat);

        for(cpt_2 = 0;cpt_2 < monEtat[num_etat].nb_regle; cpt_2++){
            printf("\n\t%c -> %s",monEtat[num_etat].partie_gauche[cpt_2],monEtat[num_etat].partie_droite[cpt_2]);
        }

        getch();
        num_etat++;
        flag1 = 0;

        for(cpt_2 = 0;cpt_2 < 20; cpt_2++){
            temp_gauche[cpt_2] = NULL;
            temp_droite[cpt_2][0] = NULL;
        }
    }
}

int main()
{
    FILE *f;
    int etat_etudie;

    for(cpt_1 = 0; cpt_1 < 20; cpt_1++){
        monEtat[cpt_1].nb_regle = 0;
        monEtat[cpt_1].partie_gauche[0] = NULL;
        monEtat[cpt_1].partie_droite[0][0] = NULL;
        table_de_transition[cpt_1][0] = NULL;
    }

    f = fopen("regle_01.txt","r");

    while(!feof(f)){
        fscanf(f,"%c",&sybmole[n]);
        fscanf(f,"%s\n",regle[n]);
        n++;
    }

    printf("\n\n\LA GRAMMAIRE DU FICHIER \n");

    for(cpt_1 = 0; cpt_1 < n; cpt_1++){
        printf("\t\t\t\t%c -> %s\n",sybmole[cpt_1],regle[cpt_1]);
    }

    getch();

    printf("\n\n\LES ETATS DE L'AUTOMATE ASSOCIE A CETTE GRAMMAIRE \n");

    monEtat[0].partie_gauche[0] = 'Z';
    strcpy(monEtat[0].partie_droite[0],".S");
    monEtat[0].nb_regle++;
    etat_etudie = 0;

    for(cpt_1 = 0; cpt_1 < n; cpt_1++){
        lettre_lue = monEtat[0].partie_droite[etat_etudie][1];
        etat_etudie++;
        for(cpt_2 = 0; cpt_2 < flag2; cpt_2++){
            if(lettre_lue == tableau_lecture[cpt_2][0]){
                break;
            }
        }
        if(cpt_2 == flag2){
            tableau_lecture[flag2][0] = lettre_lue;
            flag2++;
        }
        else{
            continue;
        }

        for(cpt_2 = 0; cpt_2 < n; cpt_2++){
            if(sybmole[cpt_2] == lettre_lue){
                monEtat[0].partie_droite[monEtat[0].nb_regle][0] = '.';
                strcat(monEtat[0].partie_droite[monEtat[0].nb_regle],regle[cpt_2]);
                monEtat[0].partie_gauche[monEtat[0].nb_regle] = sybmole[cpt_2];
                monEtat[0].nb_regle++;
            }
        }
    }
    num_etat++;

    printf("\nI%d :\n",num_etat-1);
    for(cpt_1 = 0; cpt_1 < monEtat[0].nb_regle; cpt_1++){
        printf("\t%c -> %s\n",monEtat[0].partie_gauche[cpt_1],monEtat[0].partie_droite[cpt_1]);
    }

    for(etat_etudie = 0;etat_etudie < num_etat; etat_etudie++){
        analyseur_slr(etat_etudie);
	}

    getch();

    printf("\n\n\nTABLE DE TRANSITION DE L'AUTOMATE\n\n\n");
    for(cpt_1 = 0; cpt_1 < num_etat; cpt_1++){
        printf("I%d : ",cpt_1);
        for(cpt_2 = 0; cpt_2 < num_etat; cpt_2++){
            if(table_de_transition[cpt_1][cpt_2] != '\0'){
                printf("'%c'->I%d | ",table_de_transition[cpt_1][cpt_2],cpt_2);
            }
        }
        printf("\n\n\n");
        getch();
    }
    printf("\n\nFIN DU PROGRAMME");
    getch();

	return 0;
}
