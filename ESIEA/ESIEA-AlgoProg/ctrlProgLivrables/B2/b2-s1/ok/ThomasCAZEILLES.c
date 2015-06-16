#include <stdio.h>
#include <stdlib.h>

typedef struct chaine{

int val;
struct chaine* next;

}chaine; //on définit la structure

chaine create(int i) 
{
       chaine mailtemp;
       mailtemp = (chaine)malloc(sizeof(chaine));
       
       mailtemp->val = i;       
       
       return mailtemp;
}     //fonction de création de maillon
       
chaine cercle(int n)
{
    chaine mail1;
    mail1 = (chaine)malloc(sizeof(chaine));
    
    mail1.val = 2;   
       
    if(n<=2)
    {    
         mail1->next = mail1;              
         return mail1;  
    }  //si n est inférieur ou égal à 2, la chaine ne comprendra qu'un seul élément
    else
    {
        chaine mail;
        mail = (chaine)malloc(sizeof(chaine));
        
        mailact = mail1;
        
        int i = 3;  // quel que soit n plus grand que 2, 3 sera le deuxième élement de la chaine
        for(i=3;i<=n;i++)
        {
            mailact->next = create(i);
            mailact = mailact.next;           
        }
        mailact.next = mail1;
        return mail1;
    }          
}

void afficher(chaine *chn)
{
    printf("2 "); //2 sera toujours le premier élement de toute chaine
    int i=0;
    
    chaine etape = chn->next;
    while(chn->val!=2)  //quand on recroisera 2, c'est que la boucle sera terminée
    {
       i = chn->val;
       printf("%d", i);               
    } 
    return;
}


int main()
{
    int n=0;
    printf("Entrer un N souhaité.\n");
    scanf("%d",&n);
    
    chaine circluaire;
    
    circulaire = cercle(n);
    
    afficher(circulaire);
    
    return 0;
}
