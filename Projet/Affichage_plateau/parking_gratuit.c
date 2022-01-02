#include "affichage_plateau.h"


void parking_gratuit()
{
    /// Dessin du carré bleu
    int j;
    int lig = premiere_ligne;
    for(int j = 0; j < hauteur_case +1; j++)
        {
            int col = premiere_colonne;
            for (int j = 0; j< largeur_case +1 ; j++)
                {
                    Color(0,3);
                    gotoligcol(lig,col);
                    printf(" " );
                    col++;
                }
            lig++;
        }
    /// Dessin de la lettre P
    /// Première barre verticale
    int col = 4;
    lig  = 10;
    for (int i = 0; i<2;i++)
    {
        lig = 10;
        for (j = 0; j< 6; j++)
        {
            Color(0,7);
            gotoligcol(lig,col);
            printf(" " );
            lig++;
        }
        col++;
    }
    /// dessin de la boucle du P
    lig = 10;
    for (int i = 0; i<2;i++)
    {
        col = 5;
        for (j = 0; j< 4; j++)
        {
            gotoligcol(lig,col);
            printf(" " );
            col++;
        }
        lig = lig +3;
    }
    lig = 10;
    for (int i = 0;i<1;i++)
    {
        lig = 10;
        for (j = 0; j< 4; j++)
        {
            gotoligcol(lig,col);
            printf(" " );
            lig++;
        }
        col++;
    }
}

