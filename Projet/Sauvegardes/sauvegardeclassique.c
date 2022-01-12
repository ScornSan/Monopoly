#include "../Structures/structure_joueur.h"

void sauvegardeclassique(int nb_joueurs, t_joueur joueur_x[], t_carte carte[][3], int identifiant_carte[]) // Sauvegarde n°1
{
    FILE* sauvegarde1 = NULL;
    sauvegarde1 = fopen("sauvegarde1.txt", "w"); // "w" pour ECRASEMENT donc on crée un NOUVEAU FICHIER et on ECRASE l'autre si il y'en a un
    //int nb_cartes;
    printf("Apres ouverture\n");
    fprintf(sauvegarde1, "%d\n", nb_joueurs);
    printf("%d", nb_joueurs);
    printf("Apres phrase");
    for (int x = 0; x < nb_joueurs; x++) // Boucle pour sauvegarder les structures
    {
        fprintf(sauvegarde1, "%s\n", joueur_x[x].pseudo);
        fprintf(sauvegarde1, "%d\n", joueur_x[x].argent);
        fprintf(sauvegarde1, "%d\n", joueur_x[x].position);
        fprintf(sauvegarde1, "%d\n", joueur_x[x].ancienne_position);
        fprintf(sauvegarde1, "%d\n", joueur_x[x].prison);
    }
    printf("Apres premiere boucle");
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

            fprintf(sauvegarde1, "%d", carte[i][j].hypotheque);
            fprintf(sauvegarde1, "%d", carte[i][j].val_hypotheque);
            fprintf(sauvegarde1, "%d", carte[i][j].prix_achat);
            fprintf(sauvegarde1, "%d", carte[i][j].prix_rachat);
            fprintf(sauvegarde1, "%d", carte[i][j].nb_maison);
            fprintf(sauvegarde1, "%d", carte[i][j].possession_carte);
            fprintf(sauvegarde1, "%d", carte[i][j].possession_quartier);
            fprintf(sauvegarde1, "%d", carte[i][j].prix_rachat_hypotheque);
            fprintf(sauvegarde1, "%d", carte[i][j].prix_loyer);
            fprintf(sauvegarde1, "%d", carte[i][j].prop_achete);
            fprintf(sauvegarde1, "%d", carte[i][j].prix_loyer);
            for (int id; id < 4; id++)
            {
                fprintf(sauvegarde1, "%d", carte[i][j].id_carte[id]);
            }
            printf("Apres les boucles");
            fclose(sauvegarde1);
            sauvegarde1 = NULL;
        }
    }
}
