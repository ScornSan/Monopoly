#include "../Structures/structure_joueur.h"

void deplacement_joueur(t_joueur pion[], int max_joueurs, int id_joueur)
{
    int placement_depart = 93;
    int placement_colonne_gauche = 42;
    int placement_ligne_haut = 2;
    int i;

    for (i = pion[id_joueur].ancienne_position; i < pion[id_joueur].position; i++)
    {printf("%d", i);
        if (i >= 0 && i < 6)
        {
            Color(0,id_joueur);
            gotoligcol(47, placement_depart + id_joueur * 2);
            printf(" ");
            placement_depart-=13;
            gotoligcol(47, placement_depart + id_joueur * 2); // 47 est la hauteur, donc le milieu des cases en bas
            printf("a");
            sleep(1);
        }
        if (i == 6 && (id_joueur == 0 || id_joueur == 1))
        {
            Color(0,id_joueur);
            gotoligcol(47, 2 + id_joueur * 2);
            printf("a");
            sleep(1);
        }
        if (i == 6 && (id_joueur == 2 || id_joueur == 3))
        {
            Color(0,id_joueur);
            gotoligcol(48, 2 + id_joueur);
            printf("a");
            sleep(1);
        }
        if (i >= 7 && i <= 14)
        {
            Color(0,id_joueur);
            gotoligcol(placement_colonne_gauche, 2 + id_joueur * 2);
            printf(" ");
            placement_colonne_gauche-=5;
            gotoligcol(placement_colonne_gauche, 2 + id_joueur * 2);
            printf("a");
            sleep(1);
        }
        if (i >= 15 && i <= 21)
        {
            Color(0,id_joueur);
            gotoligcol(12, placement_ligne_haut);
            printf(" ");
            placement_colonne_gauche+=13;
            gotoligcol(12, placement_ligne_haut);
            printf("a");
            sleep(1);
        }
    }
}




    /*switch(pion[id_joueur].position)
        {
            case 0:

                gotoligcol(47, placement_depart); // 47 est la hauteur, donc le milieu des cases en bas
                printf("a");


            case 1:

                gotoligcol(47, placement_depart);
                printf("a");


            case 2:

                gotoligcol(47, placement_depart);
                printf("a");


            case 3:

                gotoligcol(47, placement_depart);
                printf("a");


            case 4:

                gotoligcol(47, placement_depart);
                printf("a");


            case 5:

                gotoligcol(47, placement_depart);
                printf("a");


            case 6:

                gotoligcol(47, placement_depart);
                printf("a");


            case 7:

                gotoligcol(47, placement_depart);
                printf("a");


            case 8:

                gotoligcol(47, placement_depart);
                printf("a");


            case 9:

                gotoligcol(47, placement_depart);
                printf("a");


            case 10:

                gotoligcol(47, placement_depart);
                printf("a");


            case 11:

                gotoligcol(47, placement_depart);
                printf("a");


            case 12:

                gotoligcol(47, placement_depart);
                printf("a");


        }


    }*/
