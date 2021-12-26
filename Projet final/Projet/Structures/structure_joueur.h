#ifndef STRUCTURE_JOUEUR_H_INCLUDED
#define STRUCTURE_JOUEUR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>
#define CASES 28
#define GROUPES_CARTES 8

HANDLE win;

CONSOLE_SCREEN_BUFFER_INFO coninfo;


typedef struct players
{
    char pseudo[20];
    int argent;
    int position;
}t_joueur;

typedef struct cartes
{
    char *nom;
    int nb_maison;
    int prix_achat;
    bool prop_achete;
    int prix_loyer;
    int prix_hypotheque;
    int prix_rachat_hypotheque;
    int possession_carte;
    bool possession_quartier;
    int prix_rachat;
}t_carte;

#define MAX 100



#endif // STRUCTURE_JOUEUR_H_INCLUDED
