#include "structure_joueur.h"

int demander_nb_joueur()
{
    // demande le nombre de joueurs
    int nb_joueurs = 0;
    //int nb_joueurs = 2; /// TODO remettre � 0
    while (nb_joueurs != 2 && nb_joueurs != 3 && nb_joueurs != 4)
    {
<<<<<<< HEAD
<<<<<<< HEAD:Projet/Structure_joueur/structure_joueur.c
        printf("A combien souhaitez-vous jouer ? Ce Monopoly se joue avec 2, 3 ou 4 joueurs\n");
=======
        printf("A combien souhaitez-vous jouer ? J\n");
>>>>>>> 8f6cb42a2d5b9d237040b7ea1274803ca5449afb:Projet/Structure_joueur/structure_joueur.c.save
=======
        printf("A combien souhaitez-vous jouer ? Ce Monopoly se joue avec 2, 3 ou 4 joueurs\n");
>>>>>>> 8f6cb42a2d5b9d237040b7ea1274803ca5449afb
        fflush(stdin);
        scanf("%d", &nb_joueurs);
    }
    return nb_joueurs;
}


void creation_joueurs(t_joueur joueur[], int nombre_joueurs)
{
    // tableau de structures, nombre de struct = nombre de joueurs
    // remplissage
    for (int x = 0; x < nombre_joueurs; x++)
    {
        printf("Joueur %d, entrez votre pseudo : ", x+1);
        fflush(stdin);
        gets(&joueur[x].pseudo);
        joueur[x].argent = 1500;
        joueur[x].position = 0;
    }
}
