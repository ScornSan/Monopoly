#include "../Structures/structure_joueur.h"

int equation()
{
    int x = 0;
    int solution = 6;
    carre_noir();
    char equation[40] = "3 * x - 6 = 12";
    placement_script(strlen(equation), 0);
    printf("%s", equation);
    char devinette[60] = "Devinez la solution de l'equation : ";
    placement_script(strlen(devinette), 1);
    printf("%s", devinette);
    scanf("%d", &x);
    if (x == solution)
    {
        char bravo [50] = "Bravo ! Vous avez gagnez 50$";
        placement_script(strlen(bravo), 3);
        printf("%s", bravo);
    }
    else
    {
        char nul[50] = "Dommage, vous avez perdu!";
        placement_script(strlen(nul), 3);
        printf("%s", nul);
    }
    fflush(stdin);
    return x;
}


void banquecommu(t_joueur joueur[], int x, int nb_joueurs, int cartecommu[], int loto, int card, int sauvegarde_position[])
{
    int key;
    int solution;
    int tailletabcartes = 16;

    melangeurCarte(cartecommu, tailletabcartes);

    int taille_pseudo = strlen(joueur[x].pseudo);
    char* case_depart = ", placez vous sur la case départ";
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

    if (getch()) // On entre 32 en constante, correspondant à ESPACE
    {

        switch(cartecommu[card])
        {
        case 0:
            gotoligcol(47, 93 + x * 2);
            affichage_pion(x);
            placement_script(strlen(case_depart) + taille_pseudo, 1);
            printf("%s%s", joueur[x].pseudo, case_depart);
            joueur[x].position = 0;
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

        /*case 6:
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
            remplacement_position(sauvegarde_position,joueur[x].position);
            affichage_pion_prison_c(x,joueur[x].prison);
            Color(0, x + 9);
            printf(" ");
            joueur[x].position = 7;
            joueur[x].prison = true;
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
