#include "../Structures/structure_joueur.h"

void effacement_blanc()
{
    Color(0,15);
    printf(" ");
}

void effacement_gris()
{
    Color(0,7);
    printf(" ");
}

void deplacement_joueur(t_joueur pion[], int max_joueurs, int id_joueur)
{
    int placement_depart = 93;
    int placement_colonne_gauche = 42;
    int placement_ligne_haut = 2;
    int i;
    int arret;
    arret = pion[id_joueur].position;;

    for (i = pion[id_joueur].ancienne_position; i <= pion[id_joueur].position; i++)
    {
            switch(i)
            {
                case 0:
                    effacement_blanc();
                    gotoligcol(47, placement_depart + id_joueur * 2);
                    printf(" ");
                    sleep(1);break;

                case 1:
                    gotoligcol(47, placement_depart + id_joueur * 2);
                    effacement_blanc();
                    gotoligcol(47, placement_depart - 13 + id_joueur * 2);
                    Color(0,id_joueur);
                    printf(" ");
                    sleep(1);break;

                case 2:
                    gotoligcol(47, placement_depart - 13 + id_joueur * 2);
                    effacement_blanc();
                    gotoligcol(47, placement_depart - 13 * 2 + id_joueur * 2);
                    Color(0,id_joueur);
                    printf(" ");
                    sleep(1);break;

                case 3:
                    gotoligcol(47, placement_depart - 13 * 2 + id_joueur * 2);
                    effacement_blanc();
                    gotoligcol(47, placement_depart - 13 * 3 + id_joueur * 2);
                    Color(0,id_joueur);
                    printf(" ");
                    sleep(1);break;

                case 4:
                    gotoligcol(47, placement_depart - 13 * 3 + id_joueur * 2);
                    effacement_blanc();
                    Color(0,id_joueur);
                    gotoligcol(47, placement_depart - 13 * 4 + id_joueur * 2);
                    printf(" ");
                    sleep(1);break;

                case 5:
                    gotoligcol(47, placement_depart - 13 * 4 + id_joueur * 2);
                    effacement_blanc();
                    Color(0,id_joueur);
                    gotoligcol(47, placement_depart - 13 * 5 + id_joueur * 2);
                    printf(" ");
                    sleep(1);break;

                case 6:
                    gotoligcol(47, placement_depart - 13 * 5 + id_joueur * 2);
                    effacement_gris();
                    Color(0,id_joueur);
                    gotoligcol(47, placement_depart - 13 * 6 + id_joueur * 2);
                    printf(" ");
                    sleep(1);break;

                case 7:
                    gotoligcol(47, placement_depart - 13 * 6 + id_joueur * 2);
                    effacement_blanc();
                    Color(0,id_joueur);
                    gotoligcol(47, placement_depart - 13 * 7 + id_joueur * 2);
                    printf(" ");
                    sleep(1);break;

                case 8:
                    Color(0,id_joueur);

                    sleep(1);break;

                case 9:
                    Color(0,id_joueur);
                    gotoligcol(47, placement_depart + 13 - id_joueur * 2);
                    printf(" ");
                    sleep(1);break;

                case 10:
                    Color(0,id_joueur);
                    gotoligcol(47, placement_depart + 13 - id_joueur * 2);
                    printf(" ");
                    sleep(1);break;

                case 11:
                    Color(0,id_joueur);
                    gotoligcol(47, placement_depart + 13 - id_joueur * 2);
                    printf(" ");
                    sleep(1);break;

                case 12:
                    Color(0,id_joueur);
                    gotoligcol(47, placement_depart + 13 - id_joueur * 2);
                    printf(" ");
                    sleep(1);break;
        }
    }
}
