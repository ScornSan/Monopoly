#include "mono.h"
#include <string.h>

int main()
{
    t_carte tab[GROUPES_CARTES][3];
    int fin_de_partie;
    int nombre_de_joueurs = demander_nb_joueur();
    t_joueur joueur[nombre_de_joueurs]; // on cr�e un tableau de structures de joueurs, de taille du nombre demand�
    creation_joueurs(joueur, nombre_de_joueurs); // on cr�e les structures joueurs
    remplissages_cartes(tab); // on remplit les cartes terrains
    while (nombre_de_joueurs != 1)
    {
        for (int i = 0; i < nombre_de_joueurs; i++)
        {
            fin_de_partie = tour_joueur(joueur, i);
            // le pion se d�placera, il ne faudra pas jouer pendant ce temps
            printf("%d\n", joueur[i].position);
            if (fin_de_partie < 0)
            {
                break; // on sort de la boucle et on fait la fin du jeu
            }
        }
    }
    printf("fin de jeu");
    //deplacement_joueur();*/
    return 0;
}
