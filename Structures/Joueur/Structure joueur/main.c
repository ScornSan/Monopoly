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

void creation_structures_joueurs(int nb_joueurs, t_joueur joueur_x[])
{
    for (int x = 0; x < nb_joueurs; x++)
    {
        printf("Joueur %d, entrez votre pseudo : ", x+1);
        fflush(stdin);
        gets(&joueur_x[x].pseudo);
        joueur_x[x].argent = 1500;
        joueur_x[x].position = 0;
        joueur_x[x].prison = 0;
    }
}

void sauvegarde(int nb_joueurs, t_joueur joueur_x[])
{
    FILE* sauvegarde1 = NULL;
    sauvegarde1 = fopen("sauvegarde1.txt", "w"); // "w" pour ECRASEMENT donc on crée un NOUVEAU FICHIER et on ECRASE l'autre si il y'en a un

    for (int x = 0; x < nb_joueurs; x++) // Boucle pour sauvegarder les structures
    {
        fflush(stdin);
        fprintf(sauvegarde1, "%s\n", joueur_x[x].pseudo);
        fprintf(sauvegarde1, "%d\n", joueur_x[x].argent);
        fprintf(sauvegarde1, "%d\n", joueur_x[x].position);
        fprintf(sauvegarde1, "%c\n", joueur_x[x].prison);
    }
    fclose(sauvegarde1);
    sauvegarde1 = NULL;
}

void chargerpartie(int nb_joueurs, t_joueur joueur_x[])
{
    FILE* sauvegarde1 = NULL;
    sauvegarde1 = fopen("sauvegarde1.txt", "r"); // "r" pour LECTURE donc on voit SI IL YA UN FICHIER
    for (int x = 0; x < nb_joueurs; x++) // Boucle pour lire les structures
    {
        fscanf(sauvegarde1, "%s", &joueur_x[x].pseudo);
        fscanf(sauvegarde1, "%d", &joueur_x[x].argent);
        fscanf(sauvegarde1, "%d", &joueur_x[x].position);
        fscanf(sauvegarde1, "%c\n", joueur_x[x].prison);

    }
    printf("%s a %d$ !", joueur_x[0].pseudo, joueur_x[0].argent);
    fclose(sauvegarde1);
    sauvegarde1 = NULL;
}

int main()
{
    int banqueargent = 0;
    int cartecommu = 0;
    int cartechance = 0;
    char choixsauv = 0;
    int nb_joueurs = nb_player();
    t_joueur joueur_x[nb_joueurs];
    creation_structures_joueurs(nb_joueurs, joueur_x);
    printf("Sauvegarde ou charger?\nS/C : ");
    scanf("%c", &choixsauv);

    if (choixsauv == 's')
    {
        sauvegarde(nb_joueurs, joueur_x);
    }
    if (choixsauv == 'c')
    {
        chargerpartie(nb_joueurs, joueur_x);
    }
    return 0;
}
