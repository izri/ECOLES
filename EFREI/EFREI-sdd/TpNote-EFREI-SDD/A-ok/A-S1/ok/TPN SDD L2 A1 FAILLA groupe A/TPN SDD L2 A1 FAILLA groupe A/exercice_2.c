#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

typedef struct node_t {
    int value;
    struct node_t *left;
    struct node_t *right;
} node_t;

char isPrime(int n);
char isPerfect(int n);
int *buildPrimeTable(int limit, size_t *size);
node_t *initPerfectNode(int value, int limit);
node_t *initNode(int value, int limit);
void freeNode(node_t *node);
void displayTree(node_t *root);

int main(int argc, char **argv)
{
    node_t *tree = NULL;
    int limit = 0, choice = 0;
    char run = 0;

    srand(time(NULL));

    // On récupère la limite
    if (argc > 1)
        limit = (atoi(argv[1]) % 150) + 1;
    else
    {
        printf("Entrez une limite : ");
        do
        {
            run = scanf("%d", &limit);
        } while (!run || limit < 2 || limit > 150);
    }

    // On demande le type d'arbre à générer
    printf("Voulez-vous génerer un arbre...\n\t(1) d\'entiers parfaits ?\n\t(2) d'entiers ?\n\nVotre choix : ");
    run = scanf("%d", &choice);

    // Si le choix ne correspond pas, on en fait un au hasard
    if (!run || choice < 1 || choice > 2)
        choice = (rand() % 2) + 1;

    // On construit l'arbre selon la méthode choisie
    if (choice == 1)
        tree = initPerfectNode(2, limit);
    else
        tree = initNode(1, limit);

    if (tree == NULL)
        exit(EXIT_FAILURE);

    // On l'affiche
    printf("Affichage de l'arbre sous la forme infixe\n");
    displayTree(tree);
    printf("\n");

    system("pause");

    // On le libère
    freeNode(tree);

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

char isPerfect(int n)
{
    int *primes = NULL;
    int i = 0, div = n, sum = 1;
    size_t size = 0;

    // On récupère d'abord tous les premiers qui peuvent diviser n
    primes = buildPrimeTable(n, &size);

    for (i = 0 ; i < size ; i++)
    {
        if (div % primes[i] == 0)
            sum += primes[i];
    }

    free(primes);

    return (sum == n) ? 1 : 0;
}

int *buildPrimeTable(int limit, size_t *size)
{
    int *table = NULL, *tmp = NULL;
    int i = 0;
    *size = 1;

    table = (int*) malloc(sizeof(int));
    if (table == NULL)
        return NULL;

    *table = 2;
    for (i = 3 ; i < limit ; i++)
    {
        if (isPrime(i))
        {
            *size = *size + 1;
            tmp = (int*) realloc(table, *size * sizeof(int));

            if (tmp == NULL)
            {
                free(table);

                return NULL;
            }

            table = tmp;
            table[*size - 1] = i;
        }
    }

    return table;
}

node_t *initNode(int value, int limit)
{
    node_t *node = NULL;

    if (value > limit)
        return NULL;

    node = (node_t*) malloc(sizeof(node_t));
    if (node == NULL)
        return NULL;

    node->value = value;
    node->left = initNode(2 * value, limit);
    node->right = initNode(2 * value + 1, limit);

    return node;
}

node_t *initPerfectNode(int value, int limit)
{
    node_t *node = NULL;

    if (value > limit)
        return NULL;

    node = (node_t*) malloc(sizeof(node_t));
    if (node == NULL)
        return NULL;

    while (!isPerfect(value) && value <= limit)
        value++;

    if (value > limit)
    {
        free(node);

        return NULL;
    }

    node->value = value;
    node->left = initPerfectNode(value + 1, limit);
    node->right = initPerfectNode(value + 2, limit);

    return node;
}

void freeNode(node_t *node)
{
    if (node == NULL)
        return;

    freeNode(node->left);
    freeNode(node->right);
    free(node);
}

void displayTree(node_t *root)
{
    if (root == NULL)
        return;

    displayTree(root->left);
    printf("%d ", root->value);
    displayTree(root->right);
}
