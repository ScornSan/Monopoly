#include "affichage_plateau.h"

void cases_speciales_colonnes()
{
    /// Dessin contour case sp�ciale rouge

    int col = avant_derniere_colonne;
    for (int i = 0; i<nombre_lignes_a_faire; i++){
        int lig = avant_derniere_ligne_gain;
        for (int j = 0; j<nombre_lignes_a_faire_gain; j++)
            {
                Color(11,15);
                gotoligcol(lig,col);
                lig++;
                printf("%c", 0xBA);
            }
        col = col + largeur_case;
    }

        /// Dessin contour case sp�ciale verte du d�part

    col = avant_derniere_colonne;
    for (int i = 0; i<nombre_lignes_a_faire; i++){
        int lig = premiere_ligne_gain;
        for (int j = 0; j<nombre_lignes_a_faire_gain; j++)
            {
                Color(12,15);
                gotoligcol(lig,col);
                lig++;
                printf("%c", 0xBA);
            }
        col = col + largeur_case;
    }

        /// Dessin contour case sp�ciale noir

    col = premiere_colonne;
    for (int i = 0; i<nombre_lignes_a_faire; i++){
        int lig = avant_derniere_ligne_gain;
        for (int j = 0; j<nombre_lignes_a_faire_gain; j++)
            {
                Color(0,15);
                gotoligcol(lig,col);
                lig++;
                printf("%c", 0xBA);
            }
        col = col + largeur_case;
    }
}
