#include "structurejoueur.h"

void banquechance(int x, t_joueur joueur_x[x], int cartechance, int banqueargent)
{
    if (cartechance == 0 || cartechance == 1) // Impot
    {
        joueur_x[x].argent = joueur_x[x].argent- 200;
        printf("Le joueur pert 200$ !");
    }
    if (cartechance == 2 || cartechance == 3) // Mega Impot
        {
        joueur_x[x].argent = joueur_x[x].argent- 500;
        printf("Le joueur pert 500$ !");
    }
    if (cartechance == 4 || cartechance == 5) // Don
    {
        joueur_x[x].argent = joueur_x[x].argent+ 200;
        printf("Le joueur gagne 200$ !");
    }
    if (cartechance == 6 || cartechance == 7) // Mega Don
        {
        joueur_x[x].argent = joueur_x[x].argent+ 500;
        printf("Le joueur gagne 500$ !");
    }
    if (cartechance == 8 || cartechance == 9) // Go prison
    {
        joueur_x[x].position = 7;
        printf("Le joueur va en prison!");
    }
    if (cartechance == 10 || cartechance == 11) // Go départ
    {
        joueur_x[x].position = 0;
        printf("Le joueur va a la case depart !");
    }
    if (cartechance == 12 || cartechance == 13) // Carte de prison libération
    {
        carteprison(x, joueur_x[x]);
        printf("Le joueur reçoit une clé de prison !");
        printf("\nSi il lui arrive de passer en prison, il pourra utiliser la clé...");
    }
    if (cartechance == 14 || cartechance == 15) // Carte de prise de maison
    {
        // A faire en gros c'est le joueur qui décide d'enlever une maison ou il veut
    }
}
