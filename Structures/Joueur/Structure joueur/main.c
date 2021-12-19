#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct joueur
{
    char pseudo;
    int argent;
    int position;
}t_joueur;


int nb_player()
{
    // demannde le nombre de joueurs
    int nb_joueurs = 1;
    while (nb_joueurs != 2 && nb_joueurs != 3 && nb_joueurs != 4)
    {
        printf("A combien souhaitez-vous jouer ?\n");
        scanf("%d", &nb_joueurs);
    }
    return nb_joueurs;
}

void creation_structures_joueurs()
{
    int nombre_joueurs = nb_player();
    t_joueur joueur_x[nombre_joueurs];
    for (int x = 0; x < nombre_joueurs; x++)
    {
        printf("Joueur %d, entrez votre pseudo : ", x+1);
        fflush(stdin);
        gets(&joueur_x[x].pseudo);
        joueur_x[x].argent = 1500;
        joueur_x[x].position = 0;
    }
}

int main()
{
    creation_structures_joueurs();
    return 0;
}
