#include "mono.h"

int main()
{
    int nombre_de_joueurs = demander_nb_joueur();
    t_joueur joueur[nombre_de_joueurs];
    creation_joueurs(joueur);
    for (int i = 0; i < nombre_de_joueurs; i++)
    {
        if (getch())
        {
            tour_joueur(joueur[i], i);
            printf("%d", joueur[i].position);
            // le pion se déplacera, il ne faudra pas jouer pendant ce temps
        }

    }
    //deplacement_joueur();*
    return 0;
}
