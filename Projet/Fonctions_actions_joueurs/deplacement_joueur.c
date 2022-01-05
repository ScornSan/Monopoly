#include "../Structures/structure_joueur.h"

void effacement(int id_joueur)
{
    Color(id_joueur + 1, 15);
    printf(" ");
    Color(id_joueur + 1, 0);
}

void remplacement_position(int tab[])
{
    if (tab[0] < 15 && tab[0] > 10 && tab[1] < 13 && tab[1] > 0)
    {
        // effacement bleu
        Color(0,3);
        printf(" ");
    }
    if ((tab[0] > 20 && tab[0] < 25 && tab[1] > 0 && tab[1] < 13) || (tab[0] > 10 && tab[0] < 15 && tab[1] > 65 && tab[1] < 78))
    {
        // effacement gris
        Color(0,7);
        printf(" ");
    }
    if ((tab[0] < 40 && tab[0] > 35 && tab[1] < 104 && tab[1] > 91) || (tab[0] < 50 && tab[0] > 45 && tab[1] < 39 && tab[1] > 26))
    {
        // effacement gris aussi
        Color(0,7);
        printf(" ");
    }
    else
    {
        // effacement blanc
        Color(0,15);
        printf(" ");
    }
}


void effacement_gris(int id_joueur)
{
    Color(id_joueur + 1, 7);
    printf(" ");
    Color(id_joueur + 1, 0);
}

void affichage_pion(int id_joueur)
{
    Color(id_joueur + 1, 9);
    printf(" ");
    Color(id_joueur + 1, 0);
}

void affichage_pion_prison(int id_joueur)
{
    Color(0 , id_joueur + 1);
    if (id_joueur == 0)
    {
        gotoligcol(47,3);
    }
    if (id_joueur == 1)
    {
        gotoligcol(47,5);
    }
    if (id_joueur == 2)
    {
        gotoligcol(49,3);
    }
    if (id_joueur == 3)
    {
        gotoligcol(49,5);
    }
    printf(" ");
    Color(0, id_joueur + 1);
}

void deplacement_joueur(t_joueur pion[], int max_joueurs, int id_joueur, int nb_lancer)
{
    int placement_depart = 94;
    int placement_colonne_gauche = 46;
    int placement_ligne_haut = 16;
    int placement_colonne_droite = 12;
    int i;

    // on d�place graphiquement le pion en prison si il a fait 3 lancers

    for (i = pion[id_joueur].ancienne_position; i <= pion[id_joueur].position; i++)
    {
        switch(i)
        {
            case 0:
            case 28:
                gotoligcol(placement_colonne_droite + 5 * 6, 93 + id_joueur * 2);
                effacement(id_joueur);
                gotoligcol(47, placement_depart + id_joueur * 2);
                affichage_pion(id_joueur);
                break;

            case 1:
            case 29:
                gotoligcol(47, placement_depart + id_joueur * 2);
                effacement(id_joueur);
                gotoligcol(47, placement_depart - 13 + id_joueur * 2);
                affichage_pion(id_joueur);break;

            case 2:
            case 30:
                gotoligcol(47, placement_depart - 13 + id_joueur * 2);
                effacement(id_joueur);
                gotoligcol(47, placement_depart - 13 * 2 + id_joueur * 2);
                affichage_pion(id_joueur);break;

            case 3:
            case 31:
                if (id_joueur != 2)
                {
                    gotoligcol(47, placement_depart - 13 * 2 + id_joueur * 2);
                    effacement(id_joueur);
                    gotoligcol(47, placement_depart - 13 * 3 + id_joueur * 2);
                    affichage_pion(id_joueur);break;
                }
                else
                {
                    gotoligcol(47, placement_depart - 13 * 2 + id_joueur * 2);
                    effacement(id_joueur);
                    gotoligcol(47, placement_depart - 13 * 3 + id_joueur * 2);
                    affichage_pion(id_joueur);break;
                }

            case 4:
            case 32:
                gotoligcol(47, placement_depart - 13 * 3 + id_joueur * 2);
                effacement(id_joueur);
                gotoligcol(47, placement_depart - 13 * 4 + id_joueur * 2);
                affichage_pion(id_joueur);break;

            case 5:
            case 33:
                gotoligcol(47, placement_depart - 13 * 4 + id_joueur * 2);
                effacement(id_joueur);
                gotoligcol(47, placement_depart - 13 * 5 + id_joueur * 2);
                affichage_pion(id_joueur);break;

            case 6: // case apr�s communaut�
            case 34:
                gotoligcol(47, placement_depart - 13 * 5 + id_joueur * 2);
                effacement_gris(id_joueur);
                gotoligcol(47, placement_depart - 13 * 6 + id_joueur * 2);
                affichage_pion(id_joueur);break;

            case 7:
            case 35:
                gotoligcol(47, placement_depart - 13 * 6 + id_joueur * 2);
                effacement(id_joueur);
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
                    effacement(id_joueur);
                }
                else
                {
                    gotoligcol(placement_colonne_gauche + 2, id_joueur * 2 - 2);
                    effacement(id_joueur);
                }
                gotoligcol(placement_colonne_gauche - 5, 3 + id_joueur * 2);
                affichage_pion(id_joueur);break;

            case 9:
            case 37:
                gotoligcol(placement_colonne_gauche - 5, 3 + id_joueur * 2);
                effacement(id_joueur);
                gotoligcol(placement_colonne_gauche - 2 * 5, 3 + id_joueur * 2);
                affichage_pion(id_joueur);break;

            case 10:
            case 38:
                gotoligcol(placement_colonne_gauche - 2 * 5, 3 + id_joueur * 2);
                effacement(id_joueur);
                gotoligcol(placement_colonne_gauche - 3 * 5, 3 + id_joueur * 2);
                affichage_pion(id_joueur);break;

            case 11:
            case 39:
                gotoligcol(placement_colonne_gauche - 3 * 5, 3 + id_joueur * 2);
                effacement(id_joueur);
                gotoligcol(placement_colonne_gauche - 4 * 5, 3 + id_joueur * 2);
                affichage_pion(id_joueur);break;
            case 12:
                gotoligcol(placement_colonne_gauche - 4 * 5, 3 + id_joueur * 2);
                effacement(id_joueur);
                gotoligcol(placement_colonne_gauche - 5 * 5, 3 + id_joueur * 2);
                affichage_pion(id_joueur);break;
            case 13:
                gotoligcol(placement_colonne_gauche - 5 * 5, 3 + id_joueur * 2);
                effacement(id_joueur);
                gotoligcol(placement_colonne_gauche - 6 * 5, 3 + id_joueur * 2);
                affichage_pion(id_joueur);break;
            case 14: // case parking gratuit
                gotoligcol(placement_colonne_gauche - 6 * 5, 3 + id_joueur * 2);
                effacement(id_joueur);
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
                    gotoligcol(12, placement_ligne_haut + id_joueur * 2);
                    affichage_pion(id_joueur);break;
                }
                else
                {
                    gotoligcol(10 + id_joueur, 3);
                    effacement(id_joueur);
                    gotoligcol(12, placement_ligne_haut + id_joueur * 2);
                    affichage_pion(id_joueur);break;
                }

            case 16:
                gotoligcol(12, placement_ligne_haut + id_joueur * 2);
                effacement(id_joueur);
                gotoligcol(12, placement_ligne_haut + 13 + id_joueur * 2);
                affichage_pion(id_joueur);break;
            case 17:
                gotoligcol(12, placement_ligne_haut + 13 + id_joueur * 2);
                effacement(id_joueur);
                gotoligcol(12, placement_ligne_haut + 13 * 2 + id_joueur * 2);
                affichage_pion(id_joueur);break;
            case 18:
                gotoligcol(12, placement_ligne_haut + 13 * 2 + id_joueur * 2);
                effacement(id_joueur);
                gotoligcol(12, placement_ligne_haut + 13 * 3 + id_joueur * 2);
                affichage_pion(id_joueur);break;
            case 19: // carte chance
                gotoligcol(12, placement_ligne_haut + 13 * 3+ id_joueur * 2);
                effacement(id_joueur);
                gotoligcol(12, placement_ligne_haut + 13 * 4 + id_joueur * 2);
                affichage_pion(id_joueur);break;
            case 20:
                gotoligcol(12, placement_ligne_haut + 13 * 4+ id_joueur * 2);
                effacement_gris(id_joueur);
                gotoligcol(12, placement_ligne_haut + 13 * 5 + id_joueur * 2);
                affichage_pion(id_joueur);break;
            case 21:
                gotoligcol(12, placement_ligne_haut + 13 * 5+ id_joueur * 2);
                effacement(id_joueur);
                gotoligcol(placement_colonne_droite, 93 + id_joueur * 2);
                affichage_pion(id_joueur);break;
            case 22:
                gotoligcol(placement_colonne_droite, 93 + id_joueur * 2);
                effacement(id_joueur);
                gotoligcol(placement_colonne_droite + 5, 93 + id_joueur * 2);
                affichage_pion(id_joueur);break;
            case 23:
                gotoligcol(placement_colonne_droite + 5, 93 + id_joueur * 2);
                effacement(id_joueur);
                gotoligcol(placement_colonne_droite + 5 * 2, 93 + id_joueur * 2);
                affichage_pion(id_joueur);break;
            case 24:
                gotoligcol(placement_colonne_droite + 5 * 2, 93 + id_joueur * 2);
                effacement(id_joueur);
                gotoligcol(placement_colonne_droite + 5 * 3, 93 + id_joueur * 2);
                affichage_pion(id_joueur);break;
            case 25:
                gotoligcol(placement_colonne_droite + 5 * 3, 93 + id_joueur * 2);
                effacement(id_joueur);
                gotoligcol(placement_colonne_droite + 5 * 4, 93 + id_joueur * 2);
                affichage_pion(id_joueur);break;
            case 26: // commu
                gotoligcol(placement_colonne_droite + 5 * 4, 93 + id_joueur * 2);
                effacement(id_joueur);
                gotoligcol(placement_colonne_droite + 5 * 5, 93 + id_joueur * 2);
                affichage_pion(id_joueur);break;
            case 27:
                gotoligcol(placement_colonne_droite + 5 * 5, 93 + id_joueur * 2);
                effacement_gris(id_joueur);
                gotoligcol(placement_colonne_droite + 5 * 6, 93 + id_joueur * 2);
                affichage_pion(id_joueur);break;
        }
    }
}
