#include <stdio.h>
#include <stdlib.h>
#include "echap.h"
#include <stdbool.h>
#include "../Structures/structure_joueur.h"

void echap(int pouvoirsauv, int nombre_de_joueurs, t_joueur joueur_x)
{
        system("cls");
        affichage_Menu(pouvoirsauv, nombre_de_joueurs, joueur_x);
}
