#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct list_t {
	int value;
	struct list_t *next;
} list_t;

char isPrime(int n);
list_t *initList(int lim);
void freeList(list_t *list);
void displayList(list_t *list);
void filterPrime(list_t *list);

int main(int argc, char **argv)
{
	list_t *list = NULL;
	int limit = 0;
	char run = 0;

	if (argc > 1)
		limit = (atoi(argv[1]) % 150) + 1;
	else
	{
		printf("Entrez une limite : ");
		do
		{
			run = scanf("%d", &limit);
			fflush(stdin);
		} while (!run || limit < 2 || limit > 150);
	}

	list = initList(limit);
	if (list == NULL)
		exit(EXIT_FAILURE);

	displayList(list);
	filterPrime(list);
	displayList(list);

	freeList(list);

	system("pause");

	return EXIT_SUCCESS;
}

char isPrime(int n)
{
	int i = 0;

	for (i = 2 ; i < n ; i++)
	{
		if (n % i == 0)
			return 0;
	}

	return 1;
}

list_t *initList(int lim)
{
	list_t *head = NULL, *node = NULL;
	int i = 0;

	head = (list_t*) malloc(sizeof(list_t));
	if (head == NULL)
		return NULL;

	head->value = 2;
	node = head;

	for (i = 3 ; i <= lim ; i++)
	{
		node->next = (list_t*) malloc(sizeof(list_t));
		node->next->value = i;
		node = node->next;
	}

	node->next = NULL;

	return head;
}

void freeList(list_t *list)
{
	list_t *tmp = NULL;

	while (list != NULL)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}

void displayList(list_t *list)
{
	printf("Affichage de la liste :\n");

	while (list != NULL)
	{
		printf("%d ", list->value);

		list = list->next;
	}

	printf("\n");
}

void filterPrime(list_t *list)
{
	list_t *iterator = NULL, *previous = NULL, *tmp = NULL;

	printf("Filtrage de la liste...\n");

	iterator = list;
	while (iterator != NULL)
	{
		if (!isPrime(iterator->value))
		{
			if (previous != NULL)
				previous->next = iterator->next;

			tmp = iterator->next;
			free(iterator);
			iterator = tmp;
		}
		else
        {
            previous = iterator;
			iterator = iterator->next;
        }
	}
}
