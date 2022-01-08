#include "structure_joueur.h"
/// ne pas faire la manip chaine de carac ici car debut donc pas centré
int demander_nb_joueur()
{
    int nb_joueurs = 0;
    // demande le nombre de joueurs
    do
    {
        system("cls");
        Color(12, 0);
        printf("Appuyez sur [ECHAP] pour revenir au menu");
        Color(9, 0);
        gotoligcol(8,70);
        printf("BIENVENUE DANS UNE NOUVELLE PARTIE ! \n");
        gotoligcol(11,72);
        Color(15, 0);
        printf("A combien souhaitez-vous jouer ?\n");
        fflush(stdin);
        gotoligcol(13,72);
        Color(15, 0);
        printf("Entrez votre selection : ");
        Color(12, 0);
        scanf("%d", &nb_joueurs);
    }
    while (nb_joueurs != 2 && nb_joueurs != 3 && nb_joueurs != 4);

    return nb_joueurs; // on retourne avec -1 car la valeur qu'on retourne va nous servir pour les indices
}


void creation_joueurs(t_joueur joueur[], int nombre_joueurs, int identifiant_carte[])
{
    int n = 15;
    // tableau de structures, nombre de struct = nombre de joueurs
    // remplissage
    for (int x = 0; x < nombre_joueurs; x++)
    {
        do
        {
            effacement_noir(1, 100, n, 72);
            Color(15,0);
            gotoligcol(n,72);
            printf("Joueur %d, entrez votre pseudo : ", x + 1);
            Color(12,0);
            fflush(stdin);
            gets(&joueur[x].pseudo);
            while (joueur[x].pseudo[0] == TOUCHE_ESPACE)
            {
                effacement_noir(1, 100, n, 72);
                Color(15,0);
                gotoligcol(n,72);
                printf("Joueur %d, entrez votre pseudo : ", x + 1);
                Color(12,0);
                fflush(stdin);
                gets(&joueur[x].pseudo);
            }
        }
        while (strlen(&joueur[x].pseudo) > 12 || strlen(&joueur[x].pseudo) <= 0);

        joueur[x].argent = 1500;
        joueur[x].position = 0;
        joueur[x].prison = false;
        identifiant_carte[x] = 1; // on initialise les identifiants des cartes de chaque joueur à 1
        n = n+1;
    }

    system("cls");
}
