#include "../Structures/structure_joueur.h"

void banquechance(t_joueur joueur[], int x, int nb_joueurs, int cartechance[], int loto, int card, int sauvegarde_position[])
{
    int key;
    int tailletabcartes = 11;
    int taille_pseudo = strlen(joueur[x].pseudo);
    int solution;
    melangeurCarte(cartechance, tailletabcartes);

    char* case_depart = ", placez vous sur la case d�part";
    char* impot_100 = ", vous devez payer 100$";
    char* impot_50 = ", vous devez payer 50$";
    char* impot_20 = ", vous devez payer 20$";
    char* revenue_100 = ", vous avez gagne 100$ !";
    char* revenue_50 = ", vous avez gagne 50$ !";
    char* revenue_20 = ", vous avez gagne 20$ !";
    char* prison = ", allez en prison !";
    char* anniversaire = ", c'est votre anniversaire, chaque joueur doit vous donner 20$ !";
    char* phrase_loto = ", vous avez gagne la loterie ! Vous remportez";
    char* deplacement = ", retournez a la Maison 5.1";

    if (getch()) // On entre 32 en constante, correspondant � ESPACE
    {
        switch(cartechance[card])
        {
        case 0:
            gotoligcol(47, 93 + x * 2);
            affichage_pion(x);
            remplacement_position(sauvegarde_position, joueur[x].position);
            placement_script(strlen(case_depart) + taille_pseudo, 1);
            Color( x +9, 0);
            printf("%s%s", joueur[x].pseudo, case_depart);
            joueur[x].position = 0;
            joueur[x].ancienne_position = 0;
            usleep(3000000);
            break;

        case 1:
            placement_script(strlen(impot_100) + taille_pseudo, 1);
            printf("%s%s", joueur[x].pseudo, impot_100);
            joueur[x].argent-= 100;
            affichage_argent_joueurs(joueur, x);
            usleep(3000000);
            break;

        case 2:
            placement_script(strlen(impot_100) + taille_pseudo, 1);
            printf("%s%s", joueur[x].pseudo, impot_50);
            joueur[x].argent-= 50;
            affichage_argent_joueurs(joueur, x);
            usleep(3000000);
            break;
        case 3:
            placement_script(strlen(impot_100) + taille_pseudo, 1);
            printf("%s%s", joueur[x].pseudo, impot_20);
            joueur[x].argent-= 20;
            affichage_argent_joueurs(joueur, x);
            usleep(3000000);
            break;
        case 4:
            placement_script(strlen(prison) + taille_pseudo, 1);
            printf("%s%s", joueur[x].pseudo, prison);
            sleep(1);
            gotoligcol(47, 10);
            printf(" ");
            joueur[x].position = 7;
            joueur[x].prison = true;
            usleep(3000000);
            break;
        case 5:
            placement_script(strlen(anniversaire) + taille_pseudo, 1);
            printf("%s%s", joueur[x].pseudo, anniversaire);
            joueur[x].argent = joueur[x].argent + 20 * (nb_joueurs - 1);
            affichage_argent_joueurs(joueur, x);
            usleep(3000000);
            break;

        /*case 6: /// CRASH
            placement_script(strlen(phrase_loto) + taille_pseudo + strlen(loto), 1);
            printf("%s%s %d", joueur[x].pseudo, phrase_loto, loto);
            joueur[x].argent = joueur[x].argent + loto;
            loto = 0;
            affichage_argent_joueurs(joueur, x);
            usleep(3000000);
            break;*/

        case 7:
            placement_script(strlen(revenue_100) + taille_pseudo, 1);
            printf("%s%s", joueur[x].pseudo, revenue_100);
            joueur[x].argent+= 100;
            affichage_argent_joueurs(joueur, x);
            usleep(3000000);
            break;

        case 8:
            placement_script(strlen(revenue_50) + taille_pseudo, 1);
            printf("%s%s", joueur[x].pseudo, revenue_50);
            joueur[x].argent+= 50;
            affichage_argent_joueurs(joueur, x);
            usleep(3000000);
            break;

        case 9:
            placement_script(strlen(revenue_20) + taille_pseudo, 1);
            printf("%s%s", joueur[x].pseudo, revenue_20);
            joueur[x].argent+= 20;
            affichage_argent_joueurs(joueur, x);
            usleep(3000000);
            break;
        /*case 10: /// Crash
            placement_script(strlen(phrase_loto) + taille_pseudo + strlen(loto), 1);
            printf("%s%s %d", joueur[x].pseudo, phrase_loto, loto);
            joueur[x].argent = joueur[x].argent - loto;
            affichage_argent_joueurs(joueur, x);
            usleep(3000000);
            break;*/
        case 10:
            placement_script(strlen(prison) + taille_pseudo, 1);
            printf("%s%s", joueur[x].pseudo, prison);
            joueur[x].prison = true;
            affichage_pion_prison(x,joueur[x].prison);
            remplacement_position(sauvegarde_position,joueur[x].position);
            Color(0, x + 9);
            printf(" ");
            joueur[x].position = 7;
            usleep(3000000);
            break;
        case 6:
            solution = equation();
            if (solution == 6)
            {
                joueur[x].argent += 50;
                affichage_argent_joueurs(joueur, x);
            }
            usleep(3000000);
            break;
        }
    }
}
