#include "structure_joueur.h"

int demander_nb_joueur()
{
    // demande le nombre de joueurs
    int nb_joueurs = 0;
    //int nb_joueurs = 2; /// TODO remettre à 0
    while (nb_joueurs != 2 && nb_joueurs != 3 && nb_joueurs != 4)
    {
        system("cls");
        printf("A combien souhaitez-vous jouer ?\n");
        fflush(stdin);
        scanf("%d", &nb_joueurs);
    }
    return nb_joueurs; // on retourne avec -1 car la valeur qu'on retourne va nous servir pour les indices
}


void creation_joueurs(t_joueur joueur[], int nombre_joueurs, int identifiant_carte[])
{
    // tableau de structures, nombre de struct = nombre de joueurs
    // remplissage
    for (int x = 0; x < nombre_joueurs; x++)
    {
        printf("Joueur %d, entrez votre pseudo : ", x + 1);
        fflush(stdin);
        gets(&joueur[x].pseudo);
        joueur[x].argent = 1500;
        joueur[x].position = 0;
        identifiant_carte[x] = 1; // on initialise les identifiants des cartes de chaque joueur à 1
    }
}
