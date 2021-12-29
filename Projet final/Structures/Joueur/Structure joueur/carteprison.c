#include "structurejoueur.h"

void carteprison(int x, t_joueur joueur_x[x])
{
    // Le système permet juste de modifier la valeur de joueur_x[x].prison à 1.
    joueur_x[x].prison = true;
    // Par la suite, le programme proposera au joueur d'utiliser sa carte si il tombe en prison.
}
