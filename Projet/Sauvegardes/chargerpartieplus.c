#include "../Structures/structure_joueur.h"

void chargerpartie2(int nb_joueurs, t_joueur joueur_x[], t_carte cartes) // Sauvegarde n°2
{
    FILE* sauvegarde2 = NULL;
    sauvegarde2 = fopen("sauvegarde2.txt", "r"); // "r" pour LECTURE donc on voit SI IL YA UN FICHIER
    if (sauvegarde2 == NULL)
    {
        printf("Fichier inexistant.");
    }

    if (sauvegarde2 != NULL)
    {
        for (int x = 0; x < nb_joueurs; x++) // Boucle pour lire les structures
        {
            fscanf(sauvegarde2, "%s", &joueur_x[x].pseudo);
            fscanf(sauvegarde2, "%d", &joueur_x[x].argent);
            fscanf(sauvegarde2, "%d", &joueur_x[x].position);
            fscanf(sauvegarde2, "%d", &joueur_x[x].ancienne_position);
            fscanf(sauvegarde2, "%d", &joueur_x[x].prison);
            fscanf(sauvegarde2, "%s", &cartes.nom);
            fscanf(sauvegarde2, "%d", &cartes.nb_maison);
            fscanf(sauvegarde2, "%d", &cartes.hypotheque);
            fscanf(sauvegarde2, "%d", &cartes.id_carte);
            fscanf(sauvegarde2, "%d", &cartes.possession_carte);
            fscanf(sauvegarde2, "%d", &cartes.possession_quartier);
            fscanf(sauvegarde2, "%d", &cartes.prix_achat);
            fscanf(sauvegarde2, "%d", &cartes.prix_loyer);
            fscanf(sauvegarde2, "%d", &cartes.prix_maison);
            fscanf(sauvegarde2, "%d", &cartes.prix_rachat);
            fscanf(sauvegarde2, "%d", &cartes.prix_rachat_hypotheque);
            fscanf(sauvegarde2, "%d", &cartes.prop_achete);
        }
        fclose(sauvegarde2);
        sauvegarde2 = NULL;
    }
}
