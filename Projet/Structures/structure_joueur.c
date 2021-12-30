#include "structure_joueur.h"
<<<<<<< HEAD

/// ne pas faire la manip chaine de carac ici car debut donc pas centré
int demander_nb_joueur()
{
    couleur(12, 0);
    printf("Appuyez sur [ECHAP] pour revenir au menu");
    couleur(9, 0);
    position(8,70);
    printf("BIENVENUE DANS UNE NOUVELLE PARTIE ! \n");
    int nb_joueurs = 0;
    position(11,72);
    couleur(15, 0);
    printf("A combien souhaitez-vous jouer ?\n");
    position(13,72);
    couleur(15, 0);
    printf("Entrez votre selection : ");
    couleur(12, 0);
    fflush(stdin);
    scanf("%d", &nb_joueurs);
    // demande le nombre de joueurs
    while (nb_joueurs != 2 && nb_joueurs != 3 && nb_joueurs != 4)
    {
        position(11,72);
        couleur(15, 0);
        printf("A combien souhaitez-vous jouer ?\n");
        fflush(stdin);
        position(13,72);
        couleur(15, 0);
        printf("Entrez votre selection : ");
        couleur(12, 0);
=======
/// ne pas faire la manip chaine de carac ici car debut donc pas centré
int demander_nb_joueur()
{
    // demande le nombre de joueurs
    int nb_joueurs = 0;
    //int nb_joueurs = 2; /// TODO remettre à 0
    while (nb_joueurs != 2 && nb_joueurs != 3 && nb_joueurs != 4)
    {
        system("cls");
        printf("A combien souhaitez-vous jouer ?\n");
        fflush(stdin);
>>>>>>> 8f6cb42a2d5b9d237040b7ea1274803ca5449afb
        scanf("%d", &nb_joueurs);
    }
    return nb_joueurs; // on retourne avec -1 car la valeur qu'on retourne va nous servir pour les indices
}


void creation_joueurs(t_joueur joueur[], int nombre_joueurs, int identifiant_carte[])
{
<<<<<<< HEAD

    int n = 15;

=======
>>>>>>> 8f6cb42a2d5b9d237040b7ea1274803ca5449afb
    // tableau de structures, nombre de struct = nombre de joueurs
    // remplissage
    for (int x = 0; x < nombre_joueurs; x++)
    {
<<<<<<< HEAD
        couleur(15,0);
        position(n,72);
        printf("Joueur %d, entrez votre pseudo : ", x + 1);
        couleur(12,0);
=======
        printf("Joueur %d, entrez votre pseudo : ", x + 1);
>>>>>>> 8f6cb42a2d5b9d237040b7ea1274803ca5449afb
        fflush(stdin);
        gets(&joueur[x].pseudo);
        joueur[x].argent = 1500;
        joueur[x].position = 0;
<<<<<<< HEAD

        joueur[x].ancienne_position = 0;
        joueur[x].prison = false;
        identifiant_carte[x] = 1; // on initialise les identifiants des cartes de chaque joueur à 1
        joueur[x].prison = false;
        identifiant_carte[x] = 1; // on initialise les identifiants des cartes de chaque joueur à 1
        n = n+1;
    }
    system("cls");
=======
        joueur[x].prison = false;
        identifiant_carte[x] = 1; // on initialise les identifiants des cartes de chaque joueur à 1
    }
>>>>>>> 8f6cb42a2d5b9d237040b7ea1274803ca5449afb
}
