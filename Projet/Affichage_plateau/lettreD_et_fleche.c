#include "affichage_plateau.h"


void lettreD_et_fleche()
{
    /// Lettre D
    int j;

    ///Dessin barre principale

    int col = 100;
    int lig  = 46;
    for (j = 0; j< 4; j++)
        {
            Color(0,7);
            gotoligcol(lig,col);
            printf(" " );
            lig++;
        }

    col = 100;
    lig  = 46;

    /// dessin deux barres horizontales

    for (int i = 0; i< 3 ; i++){
        lig = 46 ;
        for (j = 0; j< 2; j++)
        {
            gotoligcol(lig,col);
            printf(" " );
            lig = lig +3;
        }
        col++;
    }

    /// dessin petite barre

    lig  = 47;
    for (j = 0; j< 2; j++)
    {
        gotoligcol(lig,col);
        printf(" " );
        lig++;
    }

    /// FLECHE
    lig = 48 + 5;
    col =  110 -11;
    for (j = 0; j< 6; j++)
    {
        Color(0,9);
        gotoligcol(lig,col);
        printf(" " );
        col++;
    }

}
