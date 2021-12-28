#include "../Structures/structure_joueur.h"

void case_prison(t_joueur joueur[], int nombre_joueurs, int id_joueur, int de1, int de2)
{
    if (de1 == de2)
    {
        printf("Vous avez fait %d et %d ! Vous sortez de prison en faisant un double !\n", de1, de2);
        joueur[id_joueur].position = joueur[id_joueur].position + de1 + de2;
        joueur[id_joueur].prison = false;
    }
    // else if (carte sortie de prison)
    else if (joueur[id_joueur].argent > 50)
    {
        printf("Voulez-vous payez 50$ pour sortir de prison ?\n");
        if (getch() == TOUCHE_ENTER)
        {
            printf("Vous avez fait %d et %d ! Vous sortez de prison en faisant un double !\n", de1, de2);
            joueur[id_joueur].position = joueur[id_joueur].position + de1 + de2;
            joueur[id_joueur].prison = false;
        }
    }
}
