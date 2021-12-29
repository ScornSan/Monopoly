#include "affichage_plateau.h"

void colonnes()
{
    /// Dessin des 2 colonnes en 3 boucles for pour le faire en 1 fois
    int col = premiere_colonne;
    for (int z = 0;z<2;z++)
    {
        for(int i = 0; i < largeur_case; i++)
        {
            int lig = deuxieme_ligne;
            for (int j = 0; j< nombre_lignes_gain; j++)
                {
                    Color(0,15);
                    gotoligcol(lig,col);
                    printf(" " );
                    lig++;
                }
            col++;
        }
        col = col + 78;
    }
}
