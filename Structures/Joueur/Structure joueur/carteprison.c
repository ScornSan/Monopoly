#include "structurejoueur.h"

void carteprison(int x, t_joueur joueur_x[x])
{
    // Le syst�me permet juste de modifier la valeur de joueur_x[x].prison � 1.
    joueur_x[x].prison = true;
    // Par la suite, le programme proposera au joueur d'utiliser sa carte si il tombe en prison.
}
