#include "../Structures/structure_joueur.h"

void banquechance(t_joueur joueur[], int x, int nb_joueurs, int cartechance[], int loto, int card)
{

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

    switch(cartechance[card])
    {
        case 0:
            effacement_gris();
            gotoligcol(47, 93 + x * 2);
            affichage_pion(x);
            placement_script(strlen(case_depart) + taille_pseudo, 1);
            printf("%s%s", joueur[x].pseudo, case_depart);
            joueur[x].position = 0;
            break;

        case 1:
            placement_script(strlen(impot_100) + taille_pseudo, 1);
            printf("%s%s", joueur[x].pseudo, impot_100);
            joueur[x].argent-= 100;
            loto+=100;
            break;

        case 2:
            placement_script(strlen(impot_100) + taille_pseudo, 1);
            printf("%s%s", joueur[x].pseudo, impot_50);
            joueur[x].argent-= 50;
            loto+=50;
            break;
        case 3:
            placement_script(strlen(impot_100) + taille_pseudo, 1);
            printf("%s%s", joueur[x].pseudo, impot_20);
            joueur[x].argent-= 20;
            loto+=20;
            break;
        case 4:
            placement_script(strlen(prison) + taille_pseudo, 1);
            printf("%s%s", joueur[x].pseudo, prison);sleep(1);
            gotoligcol(47, 10 + x);
            printf(" ");
            joueur[x].position = 7;
            joueur[x].prison = true;
            break;
        case 5:
            placement_script(strlen(anniversaire) + taille_pseudo, 1);
            printf("%s%s", joueur[x].pseudo, anniversaire);
            joueur[x].argent = 20 * nb_joueurs;
            break;
        case 6:
            placement_script(strlen(anniversaire) + taille_pseudo + strlen(loto), 1);
            printf("%s%s %d", joueur[x].pseudo, phrase_loto, loto);
            joueur[x].argent += loto;
            loto = 0;
            break;
        case 7:
            placement_script(strlen(revenue_100) + taille_pseudo, 1);
            printf("%s%s", joueur[x].pseudo, revenue_100);
            joueur[x].argent+= 100;
            break;

        case 8:
            placement_script(strlen(revenue_50) + taille_pseudo, 1);
            printf("%s%s", joueur[x].pseudo, revenue_50);
            joueur[x].argent+= 50;
            break;

        case 9:
            placement_script(strlen(revenue_20) + taille_pseudo, 1);
            printf("%s%s", joueur[x].pseudo, revenue_20);
            joueur[x].argent+= 20;
            break;
        case 10:
            placement_script(strlen(deplacement) + taille_pseudo, 1);
            printf("%s%s", joueur[x].pseudo, deplacement);
            joueur[x].position = 15;
            break;

            /// ici que des prisons pour tester si cela marche bien, et aussi trouver les idées
        case 11:
            placement_script(strlen(prison) + taille_pseudo, 1);
            printf("%s%s", joueur[x].pseudo, prison);sleep(1);
            gotoligcol(47, 10 + x);
            printf(" ");
            joueur[x].position = 7;
            joueur[x].prison = true;
            break;
        case 12:
            placement_script(strlen(prison) + taille_pseudo, 1);
            printf("%s%s", joueur[x].pseudo, prison);sleep(1);
            gotoligcol(47, 10 + x);
            printf(" ");
            joueur[x].position = 7;
            joueur[x].prison = true;
            break;
        case 13:
            placement_script(strlen(prison) + taille_pseudo, 1);
            printf("%s%s", joueur[x].pseudo, prison);sleep(1);
            gotoligcol(47, 10 + x);
            printf(" ");
            joueur[x].position = 7;
            joueur[x].prison = true;
            break;
        case 14:
            placement_script(strlen(prison) + taille_pseudo, 1);
            printf("%s%s", joueur[x].pseudo, prison);sleep(1);
            gotoligcol(47, 10 + x);
            printf(" ");
            joueur[x].position = 7;
            joueur[x].prison = true;
            break;
        case 15:
            placement_script(strlen(prison) + taille_pseudo, 1);
            printf("%s%s", joueur[x].pseudo, prison);sleep(1);
            gotoligcol(47, 10 + x);
            printf(" ");
            joueur[x].position = 7;
            joueur[x].prison = true;
            break;
    }
    card++;
    if (card == 15)
    {
        card = 0;
    }
}
