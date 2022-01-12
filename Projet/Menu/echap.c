#include <stdio.h>
#include <stdlib.h>
#include "echap.h"
#include <stdbool.h>
#include "../Structures/structure_joueur.h"

void echap(int keych, int pouvoirsauv, int nombre_de_joueurs, t_joueur joueur[], t_carte cartes[][3], int id_max[])
{
    pouvoirsauv = 1;
    do
    {
        system("cls");
        affichage_Menu(pouvoirsauv, nombre_de_joueurs, joueur, cartes, id_max);
    }
    while(keych != 'm' || keych != 'M');
}
