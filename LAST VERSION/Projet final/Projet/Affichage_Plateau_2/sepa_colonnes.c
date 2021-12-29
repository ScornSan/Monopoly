#include "affichage_plateau.h"

void sepa_colonnes()
{
    /// Separation extérieurs colonne de gauche

    int col = premiere_colonne;
    for (int z = 0; z < 2; z++)
    {
        for (int i = 0; i<nombre_lignes_a_faire; i++){
            int lig = premiere_ligne_gain;
            for (int j = 0; j<jusque_repetition_ligne; j++)
                {
                    Color(9,15);
                    gotoligcol(lig,col);
                    lig++;
                    printf("%c", 0xBA);
                }
            col = col + largeur_case;
        }
        col = col + 65;
    }

    /// Separation extérieurs colonne de droite

    col = 26;
    for (int i = 0; i<hauteur_case; i++){
        int lig = premiere_ligne_gain;
        for (int z = 0; z < 2; z++)
        {
            for (int j = 0; j<nombre_lignes_a_faire_gain; j++)
                {
                    Color(9,15);
                    gotoligcol(lig,col);
                    lig++;
                    printf("%c", 0xBA);
                }
            lig = lig +31;
        }
        col = col + largeur_case;
    }
}
