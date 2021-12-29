#ifndef STRUCTURE_JOUEUR_H_INCLUDED
#define STRUCTURE_JOUEUR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#define CASES 28
#define GROUPES_CARTES 8
#define TOUCHE_ESPACE 32
#define TOUCHE_ENTER 13

int longueur;
int chaine[100];

typedef struct players
{
    char pseudo[20];
    int argent;
    int position;
    int ancienne_position;
    bool prison;
}t_joueur;

typedef struct cartes
{
    char *nom;
    int nb_maison;
    int prix_maison;
    int prix_achat;
    bool prop_achete;
    int prix_loyer;
    bool hypotheque;
    int val_hypotheque;
    int prix_rachat_hypotheque;
    int possession_carte;
    bool possession_quartier;
    int prix_rachat;
    int id_carte;
}t_carte;


#endif // STRUCTURE_JOUEUR_H_INCLUDED