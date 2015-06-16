#include <stdlib.h>
#include <stdio.h>

typedef struct CircularList {
    int data;

    struct CircularList *next;
} CircularList;
typedef CircularList *pCircularList;


void createNewCircularList(pCircularList *l, int n) {
    pCircularList oldLink;
    int i;

    if(n > 0) {
        (*l) = malloc(sizeof(CircularList));
        (*l)->data = 1;
        (*l)->next = (*l);
        oldLink = (*l);

        for(i=2; i <= n; i++) {
            oldLink->next = malloc(sizeof(CircularList));
            oldLink = oldLink->next;
            oldLink->data = i;
            oldLink->next = (*l);
        }
    }
    else {
        printf("List not created\n");
    }
}

void displayCircularList(pCircularList l) {
    pCircularList firstLink = l;

    if(l != NULL) {
        printf("%d -> ", l->data);

        while(l->next != firstLink) {
            l = l->next;
            printf("%d -> ", l->data);
        }
        printf("loop\n");
    }
}

int isPerfect(int nb) {
	int i, sum = 0;

	for(i=1;i<nb;i++) {
		if(nb%i == 0) sum += i;
	}

	if(nb == sum) return 1;
	else return 0;
}

void deleteUnPerfect(pCircularList *l) {
	pCircularList firstLink = (*l), tempLink, newFirstLink, counterLink, oldLink;

    if(l != NULL) {
    	while(isPerfect((*l)->data) == 0) {
    		tempLink = (*l);
    		(*l) = (*l)->next;
    		free(tempLink);
    		newFirstLink = (*l);
    	}

    	oldLink = (*l);
    	counterLink = (*l)->next;

        while(counterLink != firstLink) {
        	if(isPerfect(counterLink->data) == 0) {
        		oldLink->next = counterLink->next;
        		free(counterLink);
        		counterLink = oldLink->next;
        	}
        	else {
        		oldLink = counterLink;
            	counterLink = counterLink->next;
            }
        }
        oldLink->next = newFirstLink;
    }
}


int main() {
	pCircularList listCircular = NULL, listTo650 = NULL;
	int n;

	printf("Que vaut n ? ");
	scanf("%d", &n);

	createNewCircularList(&listCircular, n);
	displayCircularList(listCircular);

	deleteUnPerfect(&listCircular);
	printf("\n");
	displayCircularList(listCircular);

	createNewCircularList(&listTo650, 650);
	deleteUnPerfect(&listTo650);
	displayCircularList(listTo650);

	return 0;
}