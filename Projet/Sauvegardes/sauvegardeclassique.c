#include "../Structures/structure_joueur.h"

void sauvegardeclassique(int nb_joueurs, t_joueur joueur_x[], t_carte cartes) // Sauvegarde n°1
{
    FILE* sauvegarde1 = NULL;
    sauvegarde1 = fopen("sauvegarde1.txt", "w"); // "w" pour ECRASEMENT donc on crée un NOUVEAU FICHIER et on ECRASE l'autre si il y'en a un
    for (int x = 0; x < nb_joueurs; x++) // Boucle pour sauvegarder les structures
    {
        fflush(stdin);
        fprintf(sauvegarde1, "%s\n", joueur_x[x].pseudo);
        fprintf(sauvegarde1, "%d\n", joueur_x[x].argent);
        fprintf(sauvegarde1, "%d\n", joueur_x[x].position);
        fprintf(sauvegarde1, "%d\n", joueur_x[x].ancienne_position);
        fprintf(sauvegarde1, "%d\n", joueur_x[x].prison);
        fprintf(sauvegarde1, "%s\n", cartes.nom);
        fprintf(sauvegarde1, "%d\n", cartes.nb_maison);
        fprintf(sauvegarde1, "%d\n", cartes.hypotheque);
        fprintf(sauvegarde1, "%d\n", cartes.id_carte);
        fprintf(sauvegarde1, "%d\n", cartes.possession_carte);
        fprintf(sauvegarde1, "%d\n", cartes.possession_quartier);
        fprintf(sauvegarde1, "%d\n", cartes.prix_achat);
        fprintf(sauvegarde1, "%d\n", cartes.prix_loyer);
        fprintf(sauvegarde1, "%d\n", cartes.prix_maison);
        fprintf(sauvegarde1, "%d\n", cartes.prix_rachat);
        fprintf(sauvegarde1, "%d\n", cartes.prix_rachat_hypotheque);
        fprintf(sauvegarde1, "%d\n", cartes.prop_achete);
    }
    fclose(sauvegarde1);
    sauvegarde1 = NULL;
}

