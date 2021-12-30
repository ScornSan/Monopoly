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

void effacement_bleu()
{
    Color(0,3);
    printf(" ");
}

void effacement_noir()
{
    Color(0, 0);
    printf(" ");
}

void deplacement_joueur(t_joueur pion[], int max_joueurs, int id_joueur)
{
    int placement_depart = 93;
    int placement_colonne_gauche = 47;
    int placement_ligne_haut = 15;
    int placement_colonne_droite = 12;
    int i;
    int arret;
    arret = pion[id_joueur].position;;

    for (i = pion[id_joueur].ancienne_position; i <= pion[id_joueur].position; i++)
    {
            switch(i)
            {
                case 0:
                    gotoligcol(placement_colonne_droite + 5 * 6, 93 + id_joueur * 2);
                    effacement_blanc();
                    gotoligcol(47, placement_depart + id_joueur * 2);
                    Color(0,id_joueur);
                    printf(" ");
                    usleep(400000);break;

                case 1:
                    gotoligcol(47, placement_depart + id_joueur * 2);
                    effacement_blanc();
                    gotoligcol(47, placement_depart - 13 + id_joueur * 2);
                    Color(0,id_joueur);
                    printf(" ");
                    usleep(400000);break;

                case 2:
                    gotoligcol(47, placement_depart - 13 + id_joueur * 2);
                    effacement_blanc();
                    gotoligcol(47, placement_depart - 13 * 2 + id_joueur * 2);
                    Color(0,id_joueur);
                    printf(" ");
                    usleep(400000);break;

                case 3:
                    gotoligcol(47, placement_depart - 13 * 2 + id_joueur * 2);
                    effacement_blanc();
                    gotoligcol(47, placement_depart - 13 * 3 + id_joueur * 2);
                    Color(0,id_joueur);
                    printf(" ");
                    usleep(400000);break;

                case 4:
                    gotoligcol(47, placement_depart - 13 * 3 + id_joueur * 2);
                    effacement_blanc();
                    Color(0,id_joueur);
                    gotoligcol(47, placement_depart - 13 * 4 + id_joueur * 2);
                    printf(" ");
                    usleep(400000);break;

                case 5:
                    gotoligcol(47, placement_depart - 13 * 4 + id_joueur * 2);
                    effacement_blanc();
                    Color(0,id_joueur);
                    gotoligcol(47, placement_depart - 13 * 5 + id_joueur * 2);
                    printf(" ");
                    usleep(400000);break;

                case 6:
                    gotoligcol(47, placement_depart - 13 * 5 + id_joueur * 2);
                    effacement_gris();
                    Color(0,id_joueur);
                    gotoligcol(47, placement_depart - 13 * 6 + id_joueur * 2);
                    printf(" ");
                    usleep(400000);break;

                case 7:
                    gotoligcol(47, placement_depart - 13 * 6 + id_joueur * 2);
                    effacement_blanc();
                    Color(0,id_joueur);
                    if (id_joueur == 0 || id_joueur == 1)
                    {
                        gotoligcol(placement_colonne_gauche, 2 + id_joueur * 2);
                        printf(" ");
                        usleep(400000);break;
                    }
                    else
                    {
                        gotoligcol(placement_colonne_gauche + 2, 2 + id_joueur * 2);
                        printf(" ");
                        usleep(400000);break;
                    }

                case 8:
                    gotoligcol(placement_colonne_gauche, 2 + id_joueur * 2);
                    effacement_blanc();
                    gotoligcol(placement_colonne_gauche + 2, 2 + id_joueur * 2);
                    effacement_blanc();
                    Color(0,id_joueur);
                    gotoligcol(placement_colonne_gauche - 5, 2 + id_joueur * 2);
                    printf(" ");
                    usleep(400000);break;

                case 9:
                    gotoligcol(placement_colonne_gauche - 5, 2 + id_joueur * 2);
                    effacement_blanc();
                    Color(0,id_joueur);
                    gotoligcol(placement_colonne_gauche - 2 * 5, 2 + id_joueur * 2);
                    printf(" ");
                    usleep(400000);break;

                case 10:
                    gotoligcol(placement_colonne_gauche - 2 * 5, 2 + id_joueur * 2);
                    effacement_blanc();
                    Color(0,id_joueur);
                    gotoligcol(placement_colonne_gauche - 3 * 5, 2 + id_joueur * 2);
                    printf(" ");
                    usleep(400000);break;

                case 11:
                    gotoligcol(placement_colonne_gauche - 3 * 5, 2 + id_joueur * 2);
                    effacement_blanc();
                    Color(0,id_joueur);
                    gotoligcol(placement_colonne_gauche - 4 * 5, 2 + id_joueur * 2);
                    printf(" ");
                    usleep(400000);break;
                case 12:
                    gotoligcol(placement_colonne_gauche - 4 * 5, 2 + id_joueur * 2);
                    effacement_blanc();
                    Color(0,id_joueur);
                    gotoligcol(placement_colonne_gauche - 5 * 5, 2 + id_joueur * 2);
                    printf(" ");
                    usleep(400000);break;
                case 13:
                    gotoligcol(placement_colonne_gauche - 5 * 5, 2 + id_joueur * 2);
                    effacement_gris();
                    Color(0,id_joueur);
                    gotoligcol(placement_colonne_gauche - 6 * 5, 2 + id_joueur * 2);
                    printf(" ");
                    usleep(400000);break;
                case 14: // case parking gratuit
                    gotoligcol(placement_colonne_gauche - 6 * 5, 2 + id_joueur * 2);
                    effacement_blanc();
                    Color(0,id_joueur);
                    if (id_joueur == 0 || id_joueur == 2)
                    {
                        gotoligcol(12 + id_joueur, 10);
                        printf(" ");
                        usleep(400000);break;
                    }
                    else
                    {
                        gotoligcol(14 + id_joueur, 3);
                        printf(" ");
                        usleep(400000);break;
                    }

                case 15:
                    if (id_joueur == 0 || id_joueur == 2)
                    {
                        gotoligcol(12 + id_joueur, 10);
                        effacement_bleu();
                        Color(0,id_joueur);
                        gotoligcol(12, placement_ligne_haut + id_joueur * 2);
                        printf(" ");
                        usleep(400000);break;
                    }
                    else
                    {
                        gotoligcol(14 + id_joueur, 3);
                        effacement_bleu();
                        Color(0, id_joueur);
                        gotoligcol(12, placement_ligne_haut + id_joueur * 2);
                        printf(" ");
                        usleep(400000);break;
                    }

                case 16:
                    gotoligcol(12, placement_ligne_haut + id_joueur * 2);
                    effacement_blanc();
                    Color(0,id_joueur);
                    gotoligcol(12, placement_ligne_haut + 13 + id_joueur * 2);
                    printf(" ");
                    usleep(400000);break;
                case 17:
                    gotoligcol(12, placement_ligne_haut + 13 + id_joueur * 2);
                    effacement_blanc();
                    Color(0,id_joueur);
                    gotoligcol(12, placement_ligne_haut + 13 * 2 + id_joueur * 2);
                    printf(" ");
                    usleep(400000);break;
                case 18:
                    gotoligcol(12, placement_ligne_haut + 13 * 2 + id_joueur * 2);
                    effacement_blanc();
                    Color(0,id_joueur);
                    gotoligcol(12, placement_ligne_haut + 13 * 3 + id_joueur * 2);
                    printf(" ");
                    usleep(400000);break;
                case 19: // carte chance
                    gotoligcol(12, placement_ligne_haut + 13 * 3+ id_joueur * 2);
                    effacement_blanc();
                    Color(0,id_joueur);
                    gotoligcol(12, placement_ligne_haut + 13 * 4 + id_joueur * 2);
                    printf(" ");
                    usleep(400000);break;
                case 20:
                    gotoligcol(12, placement_ligne_haut + 13 * 4+ id_joueur * 2);
                    effacement_gris();
                    Color(0,id_joueur);
                    gotoligcol(12, placement_ligne_haut + 13 * 5 + id_joueur * 2);
                    printf(" ");
                    usleep(400000);break;
                case 21:
                    gotoligcol(12, placement_ligne_haut + 13 * 5+ id_joueur * 2);
                    effacement_blanc();
                    Color(0,id_joueur);
                    gotoligcol(placement_colonne_droite, 93 + id_joueur * 2);
                    printf(" ");
                    usleep(400000);break;
                case 22:
                    gotoligcol(placement_colonne_droite, 93 + id_joueur * 2);
                    effacement_blanc();
                    Color(0,id_joueur);
                    gotoligcol(placement_colonne_droite + 5, 93 + id_joueur * 2);
                    printf(" ");
                    usleep(400000);break;
                case 23:
                    gotoligcol(placement_colonne_droite + 5, 93 + id_joueur * 2);
                    effacement_blanc();
                    Color(0,id_joueur);
                    gotoligcol(placement_colonne_droite + 5 * 2, 93 + id_joueur * 2);
                    printf(" ");
                    usleep(400000);break;
                case 24:
                    gotoligcol(placement_colonne_droite + 5 * 2, 93 + id_joueur * 2);
                    effacement_blanc();
                    Color(0,id_joueur);
                    gotoligcol(placement_colonne_droite + 5 * 3, 93 + id_joueur * 2);
                    printf(" ");
                    usleep(400000);break;
                case 25:
                    gotoligcol(placement_colonne_droite + 5 * 3, 93 + id_joueur * 2);
                    effacement_blanc();
                    Color(0,id_joueur);
                    gotoligcol(placement_colonne_droite + 5 * 4, 93 + id_joueur * 2);
                    printf(" ");
                    usleep(400000);break;
                case 26: // commu
                    gotoligcol(placement_colonne_droite + 5 * 4, 93 + id_joueur * 2);
                    effacement_blanc();
                    Color(0,id_joueur);
                    gotoligcol(placement_colonne_droite + 5 * 5, 93 + id_joueur * 2);
                    printf(" ");
                    usleep(400000);break;
                case 27:
                    gotoligcol(placement_colonne_droite + 5 * 5, 93 + id_joueur * 2);
                    effacement_gris();
                    Color(0,id_joueur);
                    gotoligcol(placement_colonne_droite + 5 * 6, 93 + id_joueur * 2);
                    printf(" ");
                    usleep(400000);break;
        }
    }
}
