#include <stdio.h>
#include <stdlib.h>

typedef struct cell *list;

struct cell
{
    int value;
    list next;
}cell;

list addFirst (list myList, int value)
{
    list newCell;

    newCell = malloc(sizeof(struct cell));
    newCell->value = value;
    newCell->next = myList;


return newCell;
}

void loop(list myList)
{
	list tmp;
	
	tmp = myList;
	
	if(tmp == NULL)
	{	
		return;
	}
	
	while(tmp->next)
	{
		tmp = tmp->next;
	}
	
	tmp->next = myList;
}

void showList (list myList)
{    //affiche la liste 
     list tmp=myList;

    if(tmp==NULL)
                 return;
    do
    {
                 printf("%d\n", tmp->value); //donne les valuers en col
                 tmp=tmp->next;
                 
    }while(tmp != myList);
    
}


int main()
{
    list myList = NULL;  //toujous initialiser toutes les valeurs
    int i,n;
    
    if (scanf("%d",&n)!= 1)
       return -1;
       
    for(i = 2; i <= n; i++)
    {    
         myList = addFirst(myList, i); //ajoute un élément en début de liste
    }
    
    showList(myList);
    loop(myList);
    showList(myList);

return 0;
}
