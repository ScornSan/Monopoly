#include "affichage_plateau.h"


void logo_prison()
{
    /// Dessin des barreaux verticaux
    Color(0,7);
<<<<<<< HEAD
    int col = 6;
    for (int i = 0; i < 4; i++){
=======
    int col = 8;
    for (int i = 0; i < 3; i++){
>>>>>>> 8f6cb42a2d5b9d237040b7ea1274803ca5449afb
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
<<<<<<< HEAD
        int col = 6;
        for (int j = 0; j< 6; j++)
=======
        int col = 8;
        for (int j = 0; j< 5; j++)
>>>>>>> 8f6cb42a2d5b9d237040b7ea1274803ca5449afb
            {
                gotoligcol(lig,col);
                printf(" " );
                col++;
            }
        lig = lig +2;
    }
}
