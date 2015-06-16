#ifndef __FILE__H
#define __FILE__H

typedef struct cell
{
    int info;
    cell* next;
}cell;

typedef struct fifo
{
    cell* head;
    cell* queue;
    int lenght;
}fifo;

// Initialise la liste
void init_liste(fifo* liste);

// V�rifie si la liste est vide
int isEmpty_liste(fifo* liste);

// Ajoute un �l�ment en queue
int push_liste(int val, fifo* liste);

// Affiche la liste
void print_liste(fifo * liste);

// Supprime un �l�ment en t�te
int pop(fifo* liste);

// Test de nombre premier
int test_premier(int val);

// Filtrage
void filtrage_liste (fifo* liste);
#endif
