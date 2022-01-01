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

void affichage_pion(int id_joueur)
{
    Color(0,id_joueur + 1);
    printf(" ");
    Color(15, 0);
    usleep(400);
    Color(id_joueur + 1, 0);
}

void case_pion(int id_joueur, int i)
{
    int placement_depart = 93;
    int placement_colonne_gauche = 47;
    int placement_ligne_haut = 15;
    int placement_colonne_droite = 12;
    switch(i)
            {
                case 0:
                case 28:
                    gotoligcol(placement_colonne_droite + 5 * 6, 93 + id_joueur * 2);
                    effacement_blanc();
                    gotoligcol(47, placement_depart + id_joueur * 2);
                    affichage_pion(id_joueur);break;

                case 1:
                case 29:
                    gotoligcol(47, placement_depart + id_joueur * 2);
                    effacement_blanc();
                    gotoligcol(47, placement_depart - 13 + id_joueur * 2);
                    affichage_pion(id_joueur);break;

                case 2:
                case 30:
                    gotoligcol(47, placement_depart - 13 + id_joueur * 2);
                    effacement_blanc();
                    gotoligcol(47, placement_depart - 13 * 2 + id_joueur * 2);
                    affichage_pion(id_joueur);break;

                case 3:
                case 31:
                    if (id_joueur != 2)
                    {
                        gotoligcol(47, placement_depart - 13 * 2 + id_joueur * 2);
                        effacement_blanc(id_joueur);
                        gotoligcol(47, placement_depart - 13 * 3 + id_joueur * 2);
                        affichage_pion(id_joueur);break;
                    }
                    else
                    {
                        gotoligcol(47, placement_depart - 13 * 2 + id_joueur * 2);
                        effacement_gris(id_joueur);
                        gotoligcol(47, placement_depart - 13 * 3 + id_joueur * 2);
                        affichage_pion(id_joueur);break;
                    }

                case 4:
                case 32:
                    gotoligcol(47, placement_depart - 13 * 3 + id_joueur * 2);
                    effacement_blanc();
                    gotoligcol(47, placement_depart - 13 * 4 + id_joueur * 2);
                    affichage_pion(id_joueur);break;

                case 5:
                case 33:
                    gotoligcol(47, placement_depart - 13 * 4 + id_joueur * 2);
                    effacement_blanc();
                    gotoligcol(47, placement_depart - 13 * 5 + id_joueur * 2);
                    affichage_pion(id_joueur);break;

                case 6:
                case 34:
                    if (id_joueur != 3)
                    {
                        gotoligcol(47, placement_depart - 13 * 5 + id_joueur * 2);
                        effacement_gris();
                        gotoligcol(47, placement_depart - 13 * 6 + id_joueur * 2);
                        affichage_pion(id_joueur);break;
                    }
                    else
                    {
                        gotoligcol(47, placement_depart - 13 * 5 + id_joueur * 2);
                        effacement_noir();
                        gotoligcol(47, placement_depart - 13 * 6 + id_joueur * 2);
                        affichage_pion(id_joueur);break;
                    }

                case 7:
                case 35:
                    gotoligcol(47, placement_depart - 13 * 6 + id_joueur * 2);
                    effacement_blanc();
                    if (id_joueur == 0 || id_joueur == 1)
                    {
                        gotoligcol(placement_colonne_gauche, 2 + id_joueur * 2);
                        affichage_pion(id_joueur);break;
                    }
                    else
                    {
                        gotoligcol(placement_colonne_gauche + 2, id_joueur * 2 - 2);
                        affichage_pion(id_joueur);break;
                    }

                case 8:
                case 36:
                    if (id_joueur == 0 || id_joueur == 1)
                    {
                        gotoligcol(placement_colonne_gauche, 2 + id_joueur * 2);
                        effacement_blanc();
                    }
                    else
                    {
                        gotoligcol(placement_colonne_gauche + 2, id_joueur * 2 - 2);
                    effacement_blanc();
                    }
                    gotoligcol(placement_colonne_gauche - 5, 2 + id_joueur * 2);
                    affichage_pion(id_joueur);break;

                case 9:
                case 37:
                    gotoligcol(placement_colonne_gauche - 5, 2 + id_joueur * 2);
                    effacement_blanc();
                    gotoligcol(placement_colonne_gauche - 2 * 5, 2 + id_joueur * 2);
                    affichage_pion(id_joueur);break;

                case 10:
                case 38:
                    gotoligcol(placement_colonne_gauche - 2 * 5, 2 + id_joueur * 2);
                    effacement_blanc();
                    gotoligcol(placement_colonne_gauche - 3 * 5, 2 + id_joueur * 2);
                    affichage_pion(id_joueur);break;

                case 11:
                case 39:
                    gotoligcol(placement_colonne_gauche - 3 * 5, 2 + id_joueur * 2);
                    effacement_blanc();
                    gotoligcol(placement_colonne_gauche - 4 * 5, 2 + id_joueur * 2);
                    affichage_pion(id_joueur);break;
                case 12:
                    gotoligcol(placement_colonne_gauche - 4 * 5, 2 + id_joueur * 2);
                    effacement_blanc();
                    gotoligcol(placement_colonne_gauche - 5 * 5, 2 + id_joueur * 2);
                    affichage_pion(id_joueur);break;
                case 13:
                    gotoligcol(placement_colonne_gauche - 5 * 5, 2 + id_joueur * 2);
                    effacement_gris();
                    gotoligcol(placement_colonne_gauche - 6 * 5, 2 + id_joueur * 2);
                    affichage_pion(id_joueur);break;
                case 14: // case parking gratuit
                    gotoligcol(placement_colonne_gauche - 6 * 5, 2 + id_joueur * 2);
                    effacement_blanc();
                    if (id_joueur == 0 || id_joueur == 2)
                    {
                        gotoligcol(12 + id_joueur, 10);
                        affichage_pion(id_joueur);break;
                    }
                    else
                    {
                        gotoligcol(10 + id_joueur, 3);
                        affichage_pion(id_joueur);break;
                    }

                case 15:
                    if (id_joueur == 0 || id_joueur == 2)
                    {
                        gotoligcol(12 + id_joueur, 10);
                        effacement_bleu();
                        gotoligcol(10 + id_joueur, 3);
                        effacement_bleu();
                        gotoligcol(12, placement_ligne_haut + id_joueur * 2);
                        affichage_pion(id_joueur);break;
                    }
                    else
                    {
                        gotoligcol(14 + id_joueur, 3);
                        effacement_bleu();
                        gotoligcol(12, placement_ligne_haut + id_joueur * 2);
                        affichage_pion(id_joueur);break;
                    }

                case 16:
                    gotoligcol(12, placement_ligne_haut + id_joueur * 2);
                    effacement_blanc();
                    gotoligcol(12, placement_ligne_haut + 13 + id_joueur * 2);
                    affichage_pion(id_joueur);break;
                case 17:
                    gotoligcol(12, placement_ligne_haut + 13 + id_joueur * 2);
                    effacement_blanc();
                    gotoligcol(12, placement_ligne_haut + 13 * 2 + id_joueur * 2);
                    affichage_pion(id_joueur);break;
                case 18:
                    gotoligcol(12, placement_ligne_haut + 13 * 2 + id_joueur * 2);
                    effacement_blanc();
                    gotoligcol(12, placement_ligne_haut + 13 * 3 + id_joueur * 2);
                    affichage_pion(id_joueur);break;
                case 19: // carte chance
                    gotoligcol(12, placement_ligne_haut + 13 * 3+ id_joueur * 2);
                    effacement_blanc();
                    gotoligcol(12, placement_ligne_haut + 13 * 4 + id_joueur * 2);
                    affichage_pion(id_joueur);break;
                case 20:
                    gotoligcol(12, placement_ligne_haut + 13 * 4+ id_joueur * 2);
                    effacement_gris();
                    gotoligcol(12, placement_ligne_haut + 13 * 5 + id_joueur * 2);
                    affichage_pion(id_joueur);break;
                case 21:
                    gotoligcol(12, placement_ligne_haut + 13 * 5+ id_joueur * 2);
                    effacement_blanc();
                    gotoligcol(placement_colonne_droite, 93 + id_joueur * 2);
                    affichage_pion(id_joueur);break;
                case 22:
                    gotoligcol(placement_colonne_droite, 93 + id_joueur * 2);
                    effacement_blanc();
                    gotoligcol(placement_colonne_droite + 5, 93 + id_joueur * 2);
                    affichage_pion(id_joueur);break;
                case 23:
                    gotoligcol(placement_colonne_droite + 5, 93 + id_joueur * 2);
                    effacement_blanc();
                    gotoligcol(placement_colonne_droite + 5 * 2, 93 + id_joueur * 2);
                    affichage_pion(id_joueur);break;
                case 24:
                    gotoligcol(placement_colonne_droite + 5 * 2, 93 + id_joueur * 2);
                    effacement_blanc();
                    gotoligcol(placement_colonne_droite + 5 * 3, 93 + id_joueur * 2);
                    affichage_pion(id_joueur);break;
                case 25:
                    gotoligcol(placement_colonne_droite + 5 * 3, 93 + id_joueur * 2);
                    effacement_blanc();
                    gotoligcol(placement_colonne_droite + 5 * 4, 93 + id_joueur * 2);
                    affichage_pion(id_joueur);break;
                case 26: // commu
                    gotoligcol(placement_colonne_droite + 5 * 4, 93 + id_joueur * 2);
                    effacement_blanc();
                    gotoligcol(placement_colonne_droite + 5 * 5, 93 + id_joueur * 2);
                    affichage_pion(id_joueur);break;
                case 27:
                    gotoligcol(placement_colonne_droite + 5 * 5, 93 + id_joueur * 2);
                    effacement_gris();
                    gotoligcol(placement_colonne_droite + 5 * 6, 93 + id_joueur * 2);
                    affichage_pion(id_joueur);break;
        }
}

void deplacement_joueur(t_joueur pion[], int max_joueurs, int id_joueur)
{
    int i;


    for (i = pion[id_joueur].ancienne_position; i <= pion[id_joueur].position; i++)
    {
        case_pion(id_joueur, i);
    }
}