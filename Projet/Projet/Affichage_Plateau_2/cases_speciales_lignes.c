#include "affichage_plateau.h"


void cases_speciales_lignes()
{
    ///Dessin contour case spéciale rouge

    int ligne = premiere_ligne;
    for (int i = 0; i<nombre_lignes_a_faire; i++){
        int col = avant_derniere_colonne_gain;
        for (int j = 0; j<nombre_colonnes_gain; j++)
            {
                Color(12,15);
                gotoligcol(ligne,col);
                col++;
                printf("%c", 0xCD);
            }
        ligne = ligne + hauteur_case;
    }

    /// Dessin contour case speciale noir

    ligne = avant_derniere_ligne;
    for (int i = 0; i<nombre_lignes_a_faire; i++){
        int col = 1;
        for (int j = 0; j<nombre_colonnes_gain; j++)
            {
                Color(0,15);
                gotoligcol(ligne,col);
                col++;
                printf("%c", 0xCD);
            }
        ligne = ligne + hauteur_case;
    }

    ///Dessin contour case spéciale du depart

    ligne = avant_derniere_ligne;
    for (int i = 0; i<nombre_lignes_a_faire; i++){
        int col = avant_derniere_colonne_gain;
        for (int j = 0; j<nombre_colonnes_gain; j++)
            {
                Color(11,15);
                gotoligcol(ligne,col);
                col++;
                printf("%c", 0xCD);
            }
        ligne = ligne + hauteur_case;
    }
}
