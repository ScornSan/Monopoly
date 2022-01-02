#include "../Structures/structure_joueur.h"

void sauvegardeenplus(int nb_joueurs, t_joueur joueur_x[], t_carte cartes) // Sauvegarde n°1
{
    FILE* sauvegarde2 = NULL;
    sauvegarde2 = fopen("sauvegarde2.txt", "w"); // "w" pour ECRASEMENT donc on crée un NOUVEAU FICHIER et on ECRASE l'autre si il y'en a un avec le même nom

    for (int x = 0; x < nb_joueurs; x++) // Boucle pour sauvegarder les structures
    {
        fflush(stdin);
        fprintf(sauvegarde2, "%s\n", joueur_x[x].pseudo);
        fprintf(sauvegarde2, "%d\n", joueur_x[x].argent);
        fprintf(sauvegarde2, "%d\n", joueur_x[x].position);
        fprintf(sauvegarde2, "%d\n", joueur_x[x].ancienne_position);
        fprintf(sauvegarde2, "%d\n", joueur_x[x].prison);
        fprintf(sauvegarde2, "%s\n", cartes.nom);
        fprintf(sauvegarde2, "%d\n", cartes.nb_maison);
        fprintf(sauvegarde2, "%d\n", cartes.hypotheque);
        fprintf(sauvegarde2, "%d\n", cartes.id_carte);
        fprintf(sauvegarde2, "%d\n", cartes.possession_carte);
        fprintf(sauvegarde2, "%d\n", cartes.possession_quartier);
        fprintf(sauvegarde2, "%d\n", cartes.prix_achat);
        fprintf(sauvegarde2, "%d\n", cartes.prix_loyer);
        fprintf(sauvegarde2, "%d\n", cartes.prix_maison);
        fprintf(sauvegarde2, "%d\n", cartes.prix_rachat);
        fprintf(sauvegarde2, "%d\n", cartes.prix_rachat_hypotheque);
        fprintf(sauvegarde2, "%d\n", cartes.prop_achete);
    }
    fclose(sauvegarde2);
    sauvegarde2 = NULL;
}
