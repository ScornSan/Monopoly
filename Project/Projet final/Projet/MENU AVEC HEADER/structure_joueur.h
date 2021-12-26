#ifndef STRUCTURE_JOUEUR_H_INCLUDED
#define STRUCTURE_JOUEUR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#define CASES 28
#define GROUPES_CARTES 8

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


int demander_nb_joueur();
void creation_joueurs(t_joueur joueur[], int nombre_joueurs);


#endif // STRUCTURE_JOUEUR_H_INCLUDED
