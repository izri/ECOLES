#ifndef NOMBRE_H_INCLUDED
#define NOMBRE_H_INCLUDED

typedef struct nombre
{
    int nb;
    struct nombre *suivant;
} nombre;

typedef struct nombre* LSCnombre;


LSCnombre ajouter_nb(LSCnombre liste, int nomb);
void afficherliste(LSCnombre liste);

#endif // NOMBRE_H_INCLUDED
