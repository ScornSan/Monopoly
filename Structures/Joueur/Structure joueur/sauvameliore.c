#include "structurejoueur.h"

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

void chargerpartie(int nb_joueurs, t_joueur joueur_x[], t_carte cartes) // Sauvegarde n°1 ou 2
{

    // Choix qui permet de choisir entre le fichier 1 et le fichier 2 (blindée si les fichiers n'existent pas
    int choix = 0;
    printf("Quelle sauvegarde voulez-vous charger ?");
    printf("\nTAPEZ 1) SAUVEGARDE 1");
    printf("\nTAPEZ 2) SAUVEGARDE 2");
    scanf("%d", &choix);

    while (choix != 1 && choix != 2)
    {
        printf("Erreur de choix !");
        printf("\nTAPEZ 1) SAUVEGARDE 1");
        printf("\nTAPEZ 2) SAUVEGARDE 2");
        scanf("%d", &choix);
    }

    if (choix == 1)
    {

        FILE* sauvegarde1 = NULL;
        sauvegarde1 = fopen("sauvegarde1.txt", "r"); // "r" pour LECTURE donc on voit SI IL YA UN FICHIER
        if (sauvegarde1 == NULL)
        {
            printf("Fichier inexistant.");
        }

        if (sauvegarde1 != NULL)
        {
            for (int x = 0; x < nb_joueurs; x++) // Boucle pour lire les structures
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
    if (choix == 2)
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
            printf("%s a %d$ !", joueur_x[0].pseudo, joueur_x[0].argent); // Petit test pour voir si on a bien les bonnes valeurs en sortie
            fclose(sauvegarde2);
            sauvegarde2 = NULL;
        }
    }


}
