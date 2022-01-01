#include "affichage_plateau.h"


void logo_prison()
{
    /// Dessin des barreaux verticaux
    Color(0,7);
    int col = 6;
    for (int i = 0; i < 4; i++){
        int lig  = 46;
        for (int j = 0; j< 4; j++)
            {
                gotoligcol(lig,col);
                printf(" " );
                lig++;
            }
        col = col +2;
    }
    /// Dessin des barreaux horizontaux
    int lig = 46;
    for (int i = 0; i < 2; i++){
        int col = 6;
        for (int j = 0; j< 6; j++)
            {
                gotoligcol(lig,col);
                printf(" " );
                col++;
            }
        lig = lig +2;
    }
}
