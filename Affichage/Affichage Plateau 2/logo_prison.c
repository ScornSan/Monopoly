#include "affichage_plateau.h"


void logo_prison()
{
    /// Dessin des barreaux verticaux
    Color(0,7);
    int col = 8;
    for (int i = 0; i < 3; i++){
        int lig  = 46;
        for (int j = 0; j< 4; j++)
            {
                gotoligcol(lig,col);
                printf("%c", " " );
                lig++;
            }
        col = col +2;
    }
    /// Dessin des barreaux horizontaux
    int lig = 46;
    for (int i = 0; i < 2; i++){
        int col = 8;
        for (int j = 0; j< 5; j++)
            {
                gotoligcol(lig,col);
                printf("%c", " " );
                col++;
            }
        lig = lig +2;
    }
}
