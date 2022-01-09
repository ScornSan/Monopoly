#include "../Structures/structure_joueur.h"

void chargerpartie1(int *nb_joueurs, t_joueur joueur_x[], t_carte cartes) // Sauvegarde n°1
{
    FILE* sauvegarde1 = NULL;
    sauvegarde1 = fopen("sauvegarde1.txt", "r"); // "r" pour LECTURE donc on voit SI IL YA UN FICHIER
    if (sauvegarde1 == NULL)
    {
        printf("Il n'y a pas de fichier de sauvegarde.");
    }

    if (sauvegarde1 != NULL)
    {
        fscanf(sauvegarde1, "%d ", &nb_joueurs);
        for (int x = 0; x < nb_joueurs; x++) // Boucle pour lire les structures
        {
            fgets(joueur_x[x].pseudo, 20, sauvegarde1);
            char *p;
            p=strchr(joueur_x[x].pseudo,'\n');
            if(p)
                *p=0;
            fscanf(sauvegarde1, "%d ", &joueur_x[x].argent);
            fscanf(sauvegarde1, "%d ", &joueur_x[x].position);
            fscanf(sauvegarde1, "%d ", &joueur_x[x].ancienne_position);
            fscanf(sauvegarde1, "%d ", &joueur_x[x].prison);
        }
        fclose(sauvegarde1);
        sauvegarde1 = NULL;
    }
    system("cls");
    partiealternative(nb_joueurs, joueur_x, cartes);
}


