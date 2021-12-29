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

#endif // STRUCTUREJOUEUR_H_INCLUDED
