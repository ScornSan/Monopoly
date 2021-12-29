#ifndef STRUCTUREJOUEUR_H_INCLUDED
#define STRUCTUREJOUEUR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct joueur
{
    char pseudo[40];
    int argent;
    int position;
    bool prison;

}t_joueur;

#endif // STRUCTUREJOUEUR_H_INCLUDED
