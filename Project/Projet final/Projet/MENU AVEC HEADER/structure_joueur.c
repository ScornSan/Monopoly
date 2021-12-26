#include "structure_joueur.h"

int demander_nb_joueur()
{
    //demande le nombre de joueurs
    couleur(12, 0);
    printf("Appuyez sur [ECHAP] pour revenir au menu");
    couleur(9, 0);
    position(8,45);
    printf("BIENVENUE DANS UNE NOUVELLE PARTIE ! \n");
    position(9,50);
    printf("QUE LE MEILLEUR GAGNE ^^\n");
    int nb_joueurs = 0;
    position(11,50);
    couleur(15, 0);
    printf("A combien souhaitez-vous jouer ?\n");
    position(12,50);
    couleur(15, 0);
    printf(">>>>\t");
    couleur(12, 0);
    fflush(stdin);
    scanf("%d", &nb_joueurs);

          while (nb_joueurs < 2 || nb_joueurs > 4)
            {
            system("cls");
            couleur(15,0);
            position(10,20);
            printf("Oups nombre de joueurs invalide ! Vous ne pouvez jouer qu'a 2, 3 ou 4 personnes :( \n");
            position(11,20);
            printf("Saisissez un nombre de joueurs valide : \n");
            couleur(12,0);
            position(12,20);
            printf(">>>>  ");
            scanf("%d", &nb_joueurs);
            }

        return nb_joueurs; // on retourne avec -1 car la valeur qu'on retourne va nous servir pour les indices
}


void creation_joueurs(t_joueur joueur[], int nb_joueurs)
{
    int n = 15;
    // tableau de structures, nombre de struct = nombre de joueurs
    // remplissage
    for (int i = 0; i < nb_joueurs; i++)
    {

        couleur(15,0);
        position(n,50);
        printf("Entrez le pseudo de joueur %d : ", i + 1);
        couleur(12,0);
        fflush(stdin);
        gets(&joueur[i].pseudo);
        joueur[i].argent = 1500;
        joueur[i].position = 0;
        n++;
    }

    system("cls");
    position(n+nb_joueurs,50);
    printf("Vous commencez tous avec 1500 euros\n");

}
