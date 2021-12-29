#include "affichage_plateau.h"

void lignes()
{
    /// Triple boucle de for pour faire les deux lignes en meme temps
    int lig = premiere_ligne;
    for (int z = 0; z < 2; z++)
    {
        for(int i = 0; i < hauteur_case; i++)
        {
            int col = 1;
            for (int j = 0; j< jusque_repetition_colonne; j++)
                {
                    Color(0,15);
                    gotoligcol(lig,col);
                    printf(" " );
                    col++;
                }
            lig++;
        }
        lig = lig +30;
    }
}
