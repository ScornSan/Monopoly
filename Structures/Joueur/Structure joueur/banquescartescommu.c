#include "structurejoueur.h"


void banquecommu(int x, int nb_joueurs, t_joueur joueur_x[x], int cartecommu, int banqueargent)
{
    if (cartecommu == 0 || cartecommu == 1) // Case départ pour tout les joueurs
    {
      for (int x = 0; x < nb_joueurs; x++)
        {
            joueur_x[x].position = 0;
            printf("Tout les joueurs vont a la case depart !");
        }
    }
    if (cartecommu == 2 || cartecommu == 3) // Case prison pour tout les joueurs
    {
       for (int x = 0; x < nb_joueurs; x++)
        {
            joueur_x[x].position = 7;
            printf("Tout les joueurs vont en prison !");
        }
    }
    if (cartecommu == 4 || cartecommu == 5) // Tout les joueurs donnent 100 EUROS à la banque
    {
       for (int x = 0; x < nb_joueurs; x++)
        {
            joueur_x[x].argent = joueur_x[x].argent-100;
            banqueargent = banqueargent+100;
            printf("Chaque joueur donne 100$ a la banque.");
        }
    }
    if (cartecommu == 6 || cartecommu == 7) // Le joueur en question récupère toute la banque
    {
        joueur_x[x].argent = joueur_x[x].argent+ banqueargent;
        banqueargent = 0;
        printf("Le joueur remporte %d$ de la banque !", banqueargent);
    }
    if (cartecommu == 8 || cartecommu == 9 || cartecommu == 10 || cartecommu == 11) // Le joueur reçoit 50 euros
    {
        joueur_x[x].argent = joueur_x[x].argent+ 50;

    }
    if (cartecommu == 12 || cartecommu == 13) // Le joueur reçoit 500 euros
    {
        joueur_x[x].argent = joueur_x[x].argent+ 500;
        printf("Le joueur recoit 500$ !");
    }
    if (cartecommu == 14 || cartecommu == 15) // Le joueur perd 200 euros
    {
        joueur_x[x].argent = joueur_x[x].argent- 200;
        printf("Le joueur pert 200$ !");
    }

// ça peut paraitre bizarre mais j'ai regardé sur internet et askip les carte commu c'est très individuel donc chelou

}
