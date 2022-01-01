#include "structure_joueur.h"

void paiement_loyer(t_joueur pion_du_joueur[], int nb_joueurs_v2, t_carte prop[][3])
{
    for (int i = 0; i < nb_joueurs_v2; i++)
    switch (pion_du_joueur[i].position)
    {
        // Chaque cas correspond à l'indice de la position du joueur, dans le tableau correspondant au plateau
        case 1:
            printf("Vous etes dans la %s\n", prop[0][0].nom[20]);
        /*case 3:
        case 4:
        case 6:
        case 8:
        case 9:
        case 10:
        case 11:
        case 13:
        case 15:
        case 16:
        case 17:
        case 18:
        case 20:
        case 22:
        case 23:
        case 24:
        case 25:
        case 27:*/

    }
}
