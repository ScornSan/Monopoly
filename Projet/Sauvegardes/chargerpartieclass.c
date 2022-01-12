#include "../Structures/structure_joueur.h"

void chargerpartie1(int *nb_joueurs, t_joueur joueur_x[], t_carte carte[][3], int identifiant_carte[]) // Sauvegarde n°1
{
    FILE* sauvegarde1 = NULL;
    sauvegarde1 = fopen("sauvegarde1.txt", "r"); // "r" pour LECTURE donc on voit SI IL YA UN FICHIER
    if (sauvegarde1 == NULL)
    {
        printf("Il n'y a pas de fichier de sauvegarde.");
    }

    if (sauvegarde1 != NULL)
    {
        fscanf(sauvegarde1, "%d", &nb_joueurs);
        for (int x = 0; x < nb_joueurs; x++) // Boucle pour lire les structures
        {
            fscanf(sauvegarde1, "%s", joueur_x[x].pseudo);
            fscanf(sauvegarde1, "%d", &joueur_x[x].argent);
            fscanf(sauvegarde1, "%d", &joueur_x[x].position);
            fscanf(sauvegarde1, "%d", &joueur_x[x].ancienne_position);
            fscanf(sauvegarde1, "%d", &joueur_x[x].prison);
            fscanf(sauvegarde1, "%d", &identifiant_carte[x]);
        }

        //int nb_cartes;

        for (int i = 0; i < GROUPES_CARTES; i++)
        {
            /*if (i % 2 == 0 || i == 1)
            {
                nb_cartes = 2;
            }
            else
            {
                nb_cartes = 3;
            }*/
            for (int j = 0; j < 3; j++)
            {
                // le prix de départ est calculé par rapport au groupe de la carte, puis son niveau dans le groupe
                // on parcours selon le groupe de quartier puis selon la carte, 0, 1 voir 2 du quartier i
                /// on définit le prix d'achat du terrain et du loyer nu

                fscanf(sauvegarde1, "%d", &carte[i][j].hypotheque);
                fscanf(sauvegarde1, "%d", &carte[i][j].val_hypotheque);
                fscanf(sauvegarde1, "%d", &carte[i][j].prix_achat);
                fscanf(sauvegarde1, "%d", &carte[i][j].prix_rachat);
                fscanf(sauvegarde1, "%d", &carte[i][j].nb_maison);
                fscanf(sauvegarde1, "%d", &carte[i][j].possession_carte);
                fscanf(sauvegarde1, "%d", &carte[i][j].possession_quartier);
                fscanf(sauvegarde1, "%d", &carte[i][j].prix_rachat_hypotheque);
                fscanf(sauvegarde1, "%d", &carte[i][j].prix_loyer);
                fscanf(sauvegarde1, "%d", &carte[i][j].prop_achete);
                fscanf(sauvegarde1, "%d", &carte[i][j].prix_loyer);
                for (int id; id < 4; id++)
                {
                    fscanf(sauvegarde1, "%d", &carte[i][j].id_carte[id]);
                }

                fclose(sauvegarde1);
                sauvegarde1 = NULL;
            }
            system("cls");
            partiealternative(nb_joueurs, joueur_x, carte);
        }
    }
}

