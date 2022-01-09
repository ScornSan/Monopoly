#include "../Structures/structure_joueur.h"

void sauvegardeclassique(int nb_joueurs, t_joueur joueur_x[], t_carte cartes) // Sauvegarde n°1
{
    FILE* sauvegarde1 = NULL;
    sauvegarde1 = fopen("sauvegarde1.txt", "w"); // "w" pour ECRASEMENT donc on crée un NOUVEAU FICHIER et on ECRASE l'autre si il y'en a un

    fprintf(sauvegarde1, "%d\n", nb_joueurs);
    for (int x = 0; x < nb_joueurs; x++) // Boucle pour sauvegarder les structures
    {
        fprintf(sauvegarde1, "%s\n", joueur_x[x].pseudo);
        fprintf(sauvegarde1, "%d\n", joueur_x[x].argent);
        fprintf(sauvegarde1, "%d\n", joueur_x[x].position);
        fprintf(sauvegarde1, "%d\n", joueur_x[x].ancienne_position);
        fprintf(sauvegarde1, "%d\n", joueur_x[x].prison);
    }
    fclose(sauvegarde1);
    sauvegarde1 = NULL;
}

