#include "../Structures/structure_joueur.h"



void chargerpartie1(int nb_joueurs, t_joueur joueur_x[], t_carte cartes) // Sauvegarde n°1
{
    FILE* sauvegarde1 = NULL;
    sauvegarde1 = fopen("sauvegarde1.txt", "r"); // "r" pour LECTURE donc on voit SI IL YA UN FICHIER
    if (sauvegarde1 == NULL)
    {
        printf("Fichier inexistant.");
    }

    if (sauvegarde1 != NULL)
    {
        for (int x = 0; x < nb_joueurs; x++) // Boucle pour lire les structures et les mettre en mémoire
        {
            fscanf(sauvegarde1, "%s", &joueur_x[x].pseudo);
            fscanf(sauvegarde1, "%d", &joueur_x[x].argent);
            fscanf(sauvegarde1, "%d", &joueur_x[x].position);
            fscanf(sauvegarde1, "%d", &joueur_x[x].ancienne_position);
            fscanf(sauvegarde1, "%d", &joueur_x[x].prison);
            fscanf(sauvegarde1, "%s", &cartes.nom);
            fscanf(sauvegarde1, "%d", &cartes.nb_maison);
            fscanf(sauvegarde1, "%d", &cartes.hypotheque);
            fscanf(sauvegarde1, "%d", &cartes.id_carte);
            fscanf(sauvegarde1, "%d", &cartes.possession_carte);
            fscanf(sauvegarde1, "%d", &cartes.possession_quartier);
            fscanf(sauvegarde1, "%d", &cartes.prix_achat);
            fscanf(sauvegarde1, "%d", &cartes.prix_loyer);
            fscanf(sauvegarde1, "%d", &cartes.prix_maison);
            fscanf(sauvegarde1, "%d", &cartes.prix_rachat);
            fscanf(sauvegarde1, "%d", &cartes.prix_rachat_hypotheque);
            fscanf(sauvegarde1, "%d", &cartes.prop_achete);
        }
        fclose(sauvegarde1);
        sauvegarde1 = NULL;
    }

}

