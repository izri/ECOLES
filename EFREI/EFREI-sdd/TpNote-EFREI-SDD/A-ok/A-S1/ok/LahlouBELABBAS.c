#include <stdio.h>
#include <stdlib.h>




typedef struct maillon
{
    int val;
    struct maillon * next;

}maillon;

typedef struct list
{
    maillon *  tete ;
    maillon * queue ;
}list ;

void creationlist()
{
list p ;
p = (list)malloc(sizeof());

}
