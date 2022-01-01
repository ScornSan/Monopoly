#include "affichage_plateau.h"

void lettreI()
{
    /// Dessin deux barres horizontales

    int col = 68;
    int lig  = 46;
    for (int i = 0; i<2;i++)
    {
        col = 68;
        for (int j = 0; j< 8; j++)
        {
            gotoligcol(lig,col);
            printf(" " );
            col++;
        }
        lig = lig + 3;
    }

    /// Dessin barre du centre verticale simplement doublée

    col = 71;
    lig = 46;
    for (int i = 0; i<2;i++)
    {
        lig = 46;
        for (int j = 0; j< 3; j++)
            {
                gotoligcol(lig,col);
                printf(" " );
                lig++;
            }
        col++;
    }
}
